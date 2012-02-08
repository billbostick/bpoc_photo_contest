<?php

/**
 * Implementation of hook_strongarm().
 */
function bpoc_photo_contest_strongarm() {
  $export = array();

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

  return $export;
}
