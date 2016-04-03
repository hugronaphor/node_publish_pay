<div class="paypal-subscribe-wrapper">
  <div class="paypal-button">
    <form action="https://www.sandbox.paypal.com/cgi-bin/webscr" method="post" target="_top">
      <input type="hidden" name="cmd" value="_s-xclick">
      <input type="hidden" name="hosted_button_id" value="<?php print $hosted_button_id; ?>">
      <input type="hidden" name="custom" value="<?php print $nid; ?>"/>
      <input type="image" src="https://www.sandbox.paypal.com/en_US/i/btn/btn_subscribeCC_LG.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
      <img alt="" border="0" src="https://www.sandbox.paypal.com/en_US/i/scr/pixel.gif" width="1" height="1">
    </form>
  </div>

  <?php if (!empty($paypal_subscribe_info)) : ?>
    <div class="paypal-subscribe-info">
      <?php print $paypal_subscribe_info; ?>
    </div>
  <?php endif; ?>
</div>