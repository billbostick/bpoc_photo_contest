<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function bpoc_photo_contest_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function bpoc_photo_contest_imagecache_default_presets() {
  $items = array(
    'contest_medium_photo' => array(
      'presetname' => 'contest_medium_photo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '700',
            'height' => '700',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'contest_thumbnail' => array(
      'presetname' => 'contest_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagefield_focus',
          'action' => 'imagefield_focus_scale_and_crop',
          'data' => array(
            'width' => '160',
            'height' => '120',
            'strength' => 'high',
            'fallback' => 'smartcrop',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function bpoc_photo_contest_node_info() {
  $items = array(
    'photo_submission' => array(
      'name' => t('Photo Submission'),
      'module' => 'features',
      'description' => t('A submitted entry for a photo contest.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function bpoc_photo_contest_views_api() {
  return array(
    'api' => '2',
  );
}
