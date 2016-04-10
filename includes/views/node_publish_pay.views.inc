<?php

/**
 * @file
 * Provide views data and handlers for node_publish_pay.module.
 *
 * @ingroup views_module_handlers
 */

/**
 * Implements hook_views_data().
 */
function node_publish_pay_views_data() {
  $data['node']['txn_id'] = array(
    'title' => t('Transaction identification(txn_id)'),
    'help' => t('The content of transaction identification(txn_id).'),
    'field' => array(
      'field' => 'txn_id',
      'group' => t('Content'),
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
      'link_to_node default' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['node']['subscr_id'] = array(
    'title' => t('Subscription ID(subscr_id)'),
    'help' => t('The content of Subscription ID(subscr_id).'),
    'field' => array(
      'field' => 'subscr_id',
      'group' => t('Content'),
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
      'link_to_node default' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['node']['payment_status'] = array(
    'title' => t('Node Payment Status'),
    'help' => t('The Node Payment Status.'),
    'field' => array(
      'field' => 'payment_status',
      'group' => t('Content'),
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
      'link_to_node default' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
