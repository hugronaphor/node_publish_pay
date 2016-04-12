<?php

/**
 * Subscription cancellation - form callback.
 */
function node_publish_pay_cancel_confirm_form($form, &$form_state, $nid) {
  global $user;

  if (!user_access('allow cancel subscription')) {
    return array('info' => array('#markup' => t('You are not allowed to visit this page.')));
  }

  // Make sure the node exist. There is no need to be very explicit
  // about the reason of error.
  $node = node_load($nid);
  if (empty($node)) {
    return array('info' => array('#markup' => t('Wrong URL.')));
  }

  if (($user->uid != $node->uid) || $user->uid != 1) {
    return array('info' => array('#markup' => t('You are truing to perform an action on a property not belonging to you.')));
  }

  $form['node'] = array(
    '#type' => 'value',
    '#value' => $node,
  );

  $question = t('Are you sure you want to cancel the subscription for: @node_title?', array('@node_title' => $node->title));
  return confirm_form($form, $question, "node/$nid", $question, t('Cancel the subscription'), t('Back'));
}

/**
 * Submit handler for the node_publish_pay_cancel_confirm_form
 */
function node_publish_pay_cancel_confirm_form_submit($form, &$form_state) {
  global $user;
  if (!empty($form_state['values']['node']->subscr_id)) {
    // Cancel the subscription.
    $response = _node_publish_pay_cancel_subscription($form_state['values']['node']->subscr_id);

    if (!empty($response['ACK']) && strtolower($response['ACK']) == 'success') {
      drupal_set_message('Subscription Cancellation have been successfully submitted. It make take few minutes to see the effect.');
    }
  }
  else {
    drupal_set_message(t('There are missing data for canceling the subscription. Please contact the site administrator if the error occurs again.'), 'error');
    watchdog('node_publish_pay', 'The subscr_id is missing for node ID: @nid', array(
      '@nid' => $form_state['values']['node']->nid,
    ), WATCHDOG_ERROR);
  }

  $form_state['redirect'] = 'user/' . $user->uid . '/properties';
}

/**
 * Performs an Express Checkout NVP API operation to cancel the subscription.
 *
 * Although the PayPal Standard API provides no facility for cancelling
 * a subscription, the PayPal Express Checkout  NVP API can be used.
 */
function _node_publish_pay_cancel_subscription($subscr_id) {
  $api_username = variable_get('node_publish_pay_api_username', '');
  $api_password = variable_get('node_publish_pay_api_password', '');
  $api_signature = variable_get('node_publish_pay_api_signature', '');

  if (empty($api_username) || empty($api_password) || empty($api_signature) || empty($subscr_id)) {
    drupal_set_message(t('API error. Please try one more time and contact the site administrator if error occurs again'), 'error');
    return;
  }

  $api_request = 'USER=' . urlencode($api_username) . '&PWD=' . urlencode($api_password) . '&SIGNATURE=' . urlencode($api_signature) . '&VERSION=76.0' . '&METHOD=ManageRecurringPaymentsProfileStatus' . '&PROFILEID=' . urlencode($subscr_id) . '&ACTION=' . urlencode('Cancel') . '&NOTE=' . urlencode('Profile cancelled at store');
  $ch = curl_init();

  // Detect either we are in Development mode or not.
  if (NODE_PUBLISH_PAY_DEVEL) {
    curl_setopt($ch, CURLOPT_URL, 'https://api-3t.sandbox.paypal.com/nvp');
  }
  else {
    curl_setopt($ch, CURLOPT_URL, 'https://api-3t.paypal.com/nvp');
  }

  curl_setopt($ch, CURLOPT_VERBOSE, 1);

  // Uncomment these to turn off server and peer verification
  // curl_setopt( $ch, CURLOPT_SSL_VERIFYPEER, FALSE );
  // curl_setopt( $ch, CURLOPT_SSL_VERIFYHOST, FALSE );
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_POST, 1);

  // Support request for older PHP version.
  if (version_compare(PHP_VERSION, '5.4.0') <= 0) {
    var_dump('test');
    curl_setopt($ch, CURLOPT_SSLVERSION, 6);
  }

  // Set the API parameters for this transaction
  curl_setopt($ch, CURLOPT_POSTFIELDS, $api_request);

  // Request response from PayPal
  $response = curl_exec($ch);

  // Notify user and admin, if no response was received from PayPal.
  if (!$response) {
    drupal_set_message(t('Canceling the subscription failed. Please try one more time and contact the site administrator if the error occurs again.'), 'error');
    watchdog('node_publish_pay', 'Calling PayPal to cancel the subscription failed: @error(@error_nr)', array(
      '@error' => curl_error($ch),
      '@error_nr' => curl_errno($ch)
    ), WATCHDOG_ERROR);
    return;
  }

  curl_close($ch);
  parse_str($response, $parsed_response);

  return $parsed_response;
}
