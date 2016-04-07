<?php

/**
 * Publish the property - form callback.
 */
function node_publish_pay_publish_confirm_form($form, &$form_state, $nid) {
  $node = node_load($nid);

  // Make sure the node exist. There is no need to be very explicit
  // about the reason of error.
  if (empty($node)) {
    return array('info' => array('#markup' => t('Wrong URL.')));
  }

  $form['node'] = array(
    '#type' => 'value',
    '#value' => $node,
  );

  $question = t('Are you sure you want to publish the: @node_title item?', array('@node_title' => $node->title));
  return confirm_form($form, $question, "node/$nid", $question, t('Publish'), t('Cancel'));
}

/**
 * Submit handler for the node_publish_pay_publish_confirm_form
 */
function node_publish_pay_publish_confirm_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['node']->nid)) {
    $form_state['values']['node']->status = TRUE;

    try {
      node_save($form_state['values']['node']);
      drupal_set_message('The Property has been successfully published.');
    } catch (Exception $e) {
      drupal_set_message('An error occurred while publishing the Property.');
    }
    $form_state['redirect'] = 'node/' . $form_state['values']['node']->nid;
    return;
  }

  $form_state['redirect'] = '<front>';
}
