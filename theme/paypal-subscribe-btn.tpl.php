<div class="paypal-subscribe-wrapper">
  <div class="paypal-button">

    <form action="https://www.sandbox.paypal.com/cgi-bin/webscr" method="post" target="_top">
      <input type="hidden" name="cmd" value="_s-xclick">
      <input type="hidden" name="hosted_button_id" value="WAU7T5GE8KFBW">
      <table>
        <tr><td><input type="hidden" name="on0" value="Ad Type">Ad Type</td></tr><tr><td><select name="os0">
              <option value="No Ad(simple listing)">No Ad(simple listing) : $1.00 CAD - daily</option>
              <option value="Or">Or : $2.00 CAD - daily</option>
              <option value="Argent">Argent : $3.00 CAD - daily</option>
              <option value="Bronze">Bronze : $4.00 CAD - daily</option>
            </select> </td></tr>
      </table>
      <input type="hidden" name="custom" value="<?php print $nid; ?>"/>
      <input type="hidden" name="currency_code" value="CAD">
      <input type="image" src="https://www.sandbox.paypal.com/en_US/i/btn/btn_subscribeCC_LG.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
      <img alt="" border="0" src="https://www.sandbox.paypal.com/en_US/i/scr/pixel.gif" width="1" height="1">
    </form>

  <?php if (!empty($paypal_subscribe_info)) : ?>
    <div class="paypal-subscribe-info">
      <?php print $paypal_subscribe_info; ?>
    </div>
  <?php endif; ?>
</div>