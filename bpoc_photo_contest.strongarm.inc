<?php

/**
 * Implementation of hook_strongarm().
 */
function bpoc_photo_contest_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_photo_submission';
  $strongarm->value = 0;
  $export['comment_anonymous_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_photo_submission';
  $strongarm->value = '3';
  $export['comment_controls_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_photo_submission';
  $strongarm->value = '4';
  $export['comment_default_mode_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_photo_submission';
  $strongarm->value = '1';
  $export['comment_default_order_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_photo_submission';
  $strongarm->value = '50';
  $export['comment_default_per_page_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_photo_submission';
  $strongarm->value = '0';
  $export['comment_form_location_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_photo_submission';
  $strongarm->value = '0';
  $export['comment_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_photo_submission';
  $strongarm->value = '1';
  $export['comment_preview_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_photo_submission';
  $strongarm->value = '1';
  $export['comment_subject_field_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_photo_submission';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '10',
    'author' => '8',
    'options' => '11',
    'comment_settings' => '16',
    'menu' => '9',
    'path' => '15',
    'attachments' => '12',
    'custom_breadcrumbs' => '13',
    'path_redirect' => '14',
  );
  $export['content_extra_weights_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_photo_submission';
  $strongarm->value = array();
  $export['node_options_photo_submission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_photo_submission';
  $strongarm->value = '0';
  $export['upload_photo_submission'] = $strongarm;

  return $export;
}
