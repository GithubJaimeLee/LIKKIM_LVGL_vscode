/*********************
 *      INCLUDES
 *********************/

#include "startup_incorrect_word.h"
#include "gui_comm.h"
#include "gui_data_comm.h"

extern void startup_verification_start(void);

static startup_incorrect_word_t* p_startup_incorrect_word = NULL;


static void continue_cb(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);

    if (LV_EVENT_SHORT_CLICKED == event)
    {
    	startup_incorrect_word_stop();
		startup_verification_start();
    }
}
static void startup_incorrect_word_bg_cont(lv_obj_t* parent)
{
    gui_comm_draw_title(parent, "Incorrect Word", NULL);

    lv_obj_t* label_describe1 = lv_label_create(parent);
	lv_obj_set_style_text_font(label_describe1, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_color(label_describe1, lv_color_hex(0xffffff), 0);
    lv_label_set_text_fmt(label_describe1, "This is a wrong word, check your backup and try again.");
    lv_label_set_long_mode(label_describe1, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label_describe1, 200);
    lv_obj_set_pos(label_describe1, 20, 60);

    lv_obj_t* img_btn_continue = lv_imagebutton_create(parent);
    lv_imagebutton_set_src(img_btn_continue, LV_IMAGEBUTTON_STATE_RELEASED, &img_left_released_6c6cf4_14x26, &img_mid_released_6c6cf4_4x26, &img_right_released_6c6cf4_14x26);
    lv_imagebutton_set_src(img_btn_continue, LV_IMAGEBUTTON_STATE_PRESSED, &img_left_pressed_9797ff_14x26, &img_mid_pressed_9797ff_4x26, &img_right_pressed_9797ff_14x26);
    lv_obj_set_width(img_btn_continue, 200);
    lv_obj_set_pos(img_btn_continue, 20, 278);
    lv_obj_add_event_cb(img_btn_continue, continue_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_flag(img_btn_continue, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t* label_continue = lv_label_create(img_btn_continue);
	lv_obj_set_style_text_font(label_continue, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_color(label_continue, lv_color_hex(0xffffff), 0);
    lv_label_set_text(label_continue, "Try Again");
    lv_obj_align(label_continue, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(label_continue, LV_OBJ_FLAG_EVENT_BUBBLE);
}


void startup_incorrect_word_start(void)
{
    p_startup_incorrect_word = (startup_incorrect_word_t*)lv_malloc(sizeof(startup_incorrect_word_t));
    LV_ASSERT(p_startup_incorrect_word);
    lv_memset(p_startup_incorrect_word, 0, sizeof(startup_incorrect_word_t));

    p_startup_incorrect_word->bg_cont = gui_comm_draw_bg();
    startup_incorrect_word_bg_cont(p_startup_incorrect_word->bg_cont);
}

void startup_incorrect_word_stop(void)
{
    lv_obj_del(p_startup_incorrect_word->bg_cont);
    lv_free(p_startup_incorrect_word);
    p_startup_incorrect_word = NULL;
}


