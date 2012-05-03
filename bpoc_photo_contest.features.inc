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
    'contest_admin_thumbnail' => array(
      'presetname' => 'contest_admin_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagefield_focus',
          'action' => 'imagefield_focus_scale_and_crop',
          'data' => array(
            'width' => '80',
            'height' => '60',
            'strength' => 'high',
            'fallback' => 'smartcrop',
          ),
        ),
      ),
    ),
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
 * Implementation of hook_rules_defaults().
 */
function bpoc_photo_contest_rules_defaults() {
  return array(
    'rules' => array(
      'rules_a_vote_was_cast' => array(
        '#type' => 'rule',
        '#set' => 'event_bpoc_contest_vote_cast',
        '#label' => 'A vote was cast',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'BPOC Contest',
          'bpoc_photo_contest' => 'bpoc_photo_contest',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#settings' => array(
              'message' => 'Thank You. Your vote was received.',
              'error' => 0,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_photo_submission_received' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Photo Submission Received',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'BPOC Contest',
          'bpoc_photo_contest' => 'bpoc_photo_contest',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is Photo Submission',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'photo_submission' => 'photo_submission',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'path' => '[node:field_contest_ref-url]',
              'query' => '',
              'fragment' => '',
              'force' => 0,
              'immediate' => 0,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'path' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                  'query' => array(
                    '0' => ':global',
                  ),
                  'fragment' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_drupal_goto',
            '#info' => array(
              'label' => 'Page redirect',
              'module' => 'System',
              'eval input' => array(
                '0' => 'path',
                '1' => 'query',
                '2' => 'fragment',
              ),
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#settings' => array(
              'message' => 'Thank You. Your submission has been received.',
              'error' => 0,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function bpoc_photo_contest_views_api() {
  return array(
    'api' => '2',
  );
}
