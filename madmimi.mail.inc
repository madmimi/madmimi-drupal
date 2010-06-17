<?php
// $Id: madmimi.mail.inc,v 1.1 2010/05/31 21:13:08 elliotttt Exp $
/**
 * @file madmimi.mail.inc
 * overrides drupals mail
 * point of integration with MadMimi class
 */
 
function drupal_mail_wrapper($message) {
  $id       = $message['id'];
  $to       = $message['to'];
  $from     = $message['from'];
  $subject  = $message['subject'];
  $body     = $message['body'];

  // Include the MadMimi class
  require_once(drupal_get_path('module', 'madmimi') .'/classes/MadMimi.class.php'); 
  
  // Can include 'Name' => 'Some Name'
  $recipient = array(
    'Email' => $to
  );

  // Set up recipient.
  $info = array(
    'Subject' => $subject,
    'PromoName' => variable_get('madmimi_promotionname', NULL),
    'FromAddr' => $from
  );

  // Configure the message settings.
  // IMPORTANT: You MUST add {message} in the Madmimi interface in one of your promotions where you want the custom
  // message to appear
  // TODO: Allow for multiple configurable variables
  $mimibody = array(
    'message' => $body,
  );
  
  $opt = array(
    'promotion_name' => variable_get('madmimi_promotionname', NULL),
    'recipients' => $to,
    'subject' => $subject,
    'from' => $from
  );
  
  $mailer = new MadMimi(variable_get('madmimi_username', NULL), variable_get('madmimi_apikey', NULL), FALSE);
  
  // note, the last param is set to false which captures the mimi message ID as a string instead of printing
  // to the browser
  if (variable_get('madmimi_promotiontype', NULL) == 1) {
	 $send = $mailer->SendPlainText($opt, $body, false);
  } else {
     $send = $mailer->SendMessage($opt, $mimibody, false);
  }

  // useful for debugging
  watchdog('mimi', 'id: '. $id .', to: '. $to .', from: '. $from .', subject: '. $subject .', body:'. $body .', mimi: '. $send);
  
  // TODO: add better error handling :P
  return TRUE;
}