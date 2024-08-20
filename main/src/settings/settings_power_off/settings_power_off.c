/*********************
 *      INCLUDES
 *********************/

#include "settings_power_off.h"
#include "gui_comm.h"

extern void settings_main_start(void);

static settings_power_off_t* p_settings_power_off = NULL;


static void power_off_cb(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);

    if (LV_EVENT_SHORT_CLICKED == event)
    {
		
    }
}
static void cancle_cb(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);

    if (LV_EVENT_SHORT_CLICKED == event)
    {
    	settings_power_off_stop();
		settings_main_start();
    }
}
static void settings_power_off_bg_cont(lv_obj_t* parent)
{
    gui_comm_draw_title(parent, "Power Off", NULL);
	
    lv_obj_t* img_btn_power_off = lv_imagebutton_create(parent);
	lv_imagebutton_set_src(img_btn_power_off, LV_IMAGEBUTTON_STATE_RELEASED, &img_left_released_ff2600_14x26, &img_mid_released_ff2600_4x26, &img_right_released_ff2600_14x26);
	lv_imagebutton_set_src(img_btn_power_off, LV_IMAGEBUTTON_STATE_PRESSED, &img_left_pressed_ff6247_14x26, &img_mid_pressed_ff6247_4x26, &img_right_pressed_ff6247_14x26);
    lv_obj_set_width(img_btn_power_off, 200);
    lv_obj_set_pos(img_btn_power_off, 20, 246);
    lv_obj_add_event_cb(img_btn_power_off, power_off_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_flag(img_btn_power_off, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t* label_power_off = lv_label_create(img_btn_power_off);
	lv_obj_set_style_text_font(label_power_off, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_color(label_power_off, lv_color_hex(0xffffff), 0);
    lv_label_set_text(label_power_off, "Power Off");
    lv_obj_align(label_power_off, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(label_power_off, LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t* img_btn_cancle = lv_imagebutton_create(parent);
    lv_imagebutton_set_src(img_btn_cancle, LV_IMAGEBUTTON_STATE_RELEASED, &img_left_released_888888_14x26, &img_mid_released_888888_4x26, &img_right_released_888888_14x26);
    lv_imagebutton_set_src(img_btn_cancle, LV_IMAGEBUTTON_STATE_PRESSED, &img_left_pressed_bbbbbb_14x26, &img_mid_pressed_bbbbbb_4x26, &img_right_pressed_bbbbbb_14x26);
    lv_obj_set_width(img_btn_cancle, 200);
    lv_obj_set_pos(img_btn_cancle, 20, 278);
    lv_obj_add_event_cb(img_btn_cancle, cancle_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_flag(img_btn_cancle, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t* label_cancle = lv_label_create(img_btn_cancle);
	lv_obj_set_style_text_font(label_cancle, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_color(label_cancle, lv_color_hex(0xffffff), 0);
    lv_label_set_text(label_cancle, "Cancle");
    lv_obj_align(label_cancle, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(label_cancle, LV_OBJ_FLAG_EVENT_BUBBLE);

}


void settings_power_off_start(void)
{
    p_settings_power_off = (settings_power_off_t*)lv_malloc(sizeof(settings_power_off_t));
    LV_ASSERT(p_settings_power_off);
    lv_memset(p_settings_power_off, 0, sizeof(settings_power_off_t));

    p_settings_power_off->bg_cont = gui_comm_draw_bg();
    settings_power_off_bg_cont(p_settings_power_off->bg_cont);
}

void settings_power_off_stop(void)
{
    lv_obj_del(p_settings_power_off->bg_cont);
    lv_free(p_settings_power_off);
    p_settings_power_off = NULL;
}

