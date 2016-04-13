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

  $form['general']['node_publish_pay_devel'] = array(
    '#type' => 'checkbox',
    '#title' => t('Development mode'),
    '#default_value' => variable_get('node_publish_pay_devel'),
  );

  $options_subscribe_info = variable_get('node_publish_pay_options_subscribe_info', array());
  $form['general']['node_publish_pay_options_subscribe_info'] = array(
    '#type' => 'text_format',
    '#format' => !empty($options_subscribe_info['format']) ? $options_subscribe_info['format'] : 'plain_text',
    '#title' => t('Payment instructions for Partner.'),
    '#default_value' => !empty($options_subscribe_info['value']) ? $options_subscribe_info['value'] : '',
    '#rows' => 5,
  );

  $simple_subscribe_info = variable_get('node_publish_pay_simple_subscribe_info', array());
  $form['general']['node_publish_pay_simple_subscribe_info'] = array(
    '#type' => 'text_format',
    '#format' => !empty($simple_subscribe_info['format']) ? $simple_subscribe_info['format'] : 'plain_text',
    '#title' => t('Payment instructions for Property.'),
    '#default_value' => !empty($simple_subscribe_info['value']) ? $simple_subscribe_info['value'] : '',
    '#rows' => 5,
  );

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
