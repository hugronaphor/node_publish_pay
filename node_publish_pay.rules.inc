<?php
/**
 * Implementation of hook_rules_event_info().
 * @ingroup rules
 */
function node_publish_pay_rules_event_info() {
  return array(
    'node_publish_pay_payment_is_completed' => array(
      'group' => t('Node Publish Pay'),
      'label' => t('A payment for the node is completed'),
      'module' => 'node_publish_pay',
      'arguments' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('The user who paid.')
        ),
        'node' => array(
          'type' => 'node',
          'label' => t('The published paid Node.')
        ),
      ),
    ),
  );
}
