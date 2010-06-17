<?php
// $Id: madmimi.admin.inc,v 1.1 2010/03/31 16:19:11 elliotttt Exp $

/**
 * @file
 * Administrative page callbacks for the madmimi module.
 */

/**
 * Define the settings form.
 */
function madmimi_admin_settings() {
  $form = array();
  $form['madmimi_username'] = array(
    '#title' => 'Mad Mimi Username',
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('madmimi_username', NULL),
    '#size' => 60,
    '#maxlength' => 128
  );
  
  $form['madmimi_apikey'] = array(
    '#title' => 'Mad Mimi API Key',
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('madmimi_apikey', NULL),
    '#size' => 60,
    '#maxlength' => 128,
    '#description' => t('Be sure your account has the Mailer API feature, available <a href="http://madmimi.com/addons">here</a>.'),
  );
  
  $form['madmimi_promotionname'] = array(
    '#title' => 'Promotion Name',
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('madmimi_promotionname', NULL),
    '#size' => 60,
    '#maxlength' => 128
  );

  // Add a drop down to select the promotion type
  $form['madmimi_promotiontype'] = array(
  	'#title' => 'Promotion Type',
    '#type' => 'select',
    '#options' => array('Composer', 'Plain Text'),
    '#required' => TRUE,
	'#default_value' => variable_get('madmimi_promotiontype', NULL)
  );
  
  return system_settings_form($form);  
}