<?php

/**
 * @file
 * Admin page.
 */

/**
 * Implements hook_form().
 */
function node_publish_pay_admin_form() {
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General data'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['general']['node_publish_pay_ct'] = array(
    '#type' => 'textfield',
    '#title' => t('The Content Types to activate payment'),
    '#description' => t('*Comma separated string will end up in an array.'),
    '#default_value' => variable_get('node_publish_pay_ct'),
  );

  $form['general']['node_publish_pay_devel'] = array(
    '#type' => 'checkbox',
    '#title' => t('Development mode'),
    '#default_value' => variable_get('node_publish_pay_devel'),
  );

  $content = variable_get('node_publish_pay_subscribe_info', array());
  $form['general']['node_publish_pay_subscribe_info'] = [
    '#type' => 'text_format',
    '#format' => !empty($content['format']) ? $content['format'] : 'plain_text',
    '#title' => t('Payment instructions displayed for the users.'),
    '#default_value' => !empty($content['value']) ? $content['value'] : '',
    '#rows' => 5,
  ];

  $form['payment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Payment data'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['payment']['node_publish_pay_receiver_email'] = array(
    '#type' => 'textfield',
    '#title' => t('The payment receiver Email'),
    '#default_value' => variable_get('node_publish_pay_receiver_email'),
  );

  $form['payment']['node_publish_pay_currency'] = array(
    '#type' => 'textfield',
    '#title' => t('The payment currency code used for validation(e.g: CAD, GBP)'),
    '#default_value' => variable_get('node_publish_pay_currency'),
  );

  $form['api'] = array(
    '#type' => 'fieldset',
    '#title' => t('API data'),
    '#description' => t('Used for Subscription cancellation'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['api']['node_publish_pay_api_username'] = array(
    '#type' => 'textfield',
    '#title' => t('API username'),
    '#default_value' => variable_get('node_publish_pay_api_username'),
  );

  $form['api']['node_publish_pay_api_password'] = array(
    '#type' => 'textfield',
    '#title' => t('API password'),
    '#default_value' => variable_get('node_publish_pay_api_password'),
  );

  $form['api']['node_publish_pay_api_signature'] = array(
    '#type' => 'textfield',
    '#title' => t('API signature'),
    '#default_value' => variable_get('node_publish_pay_api_signature'),
  );

  return system_settings_form($form);
}
