<?php

/**
 * @file
 * Provides settings pages for the CAS Varnostna Shema module.
 */

/**
 * Lists available CAS Attributes.
 */
function cas_varnostna_shema_list() {

  $header = array('Token', 'Value');
  $rows = array();

  $attributes = cas_varnostna_shema_attributes('15277011');
  foreach ($attributes as $attribute => $value) {
    if (is_numeric($attribute)) {
      continue;
    }
    if (is_array($value)) {
      $value = implode(', ', $value);
    }
    $rows[] = array(
      t('[cas:varnostna_shema:@attribute]', array('@attribute' => drupal_strtolower($attribute))),
      check_plain($value),
    );
  }

  if (empty($rows)) {
    $rows[] = array(
      'data' => array(
        array(
          'data' => t('No Varnostna Shema attributes were returned by the Varnostna Shema server.'),
          'colspan' => 2,
        ),
      ),
    );
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}
