/**
 * @file main/src/about_device.c
 *
 */

#include "lvgl/lvgl.h"

void back_btn_event_handler(lv_event_t * e);  // 声明 Back 按钮事件处理函数

/**
 * 加载 About Device 屏幕
 */
void load_about_device_screen() {
    /* 创建主屏幕 */
    lv_obj_t * scr = lv_scr_act();

    /* 清空当前屏幕 */
    lv_obj_clean(scr);

    /* 创建一个新的容器作为页面 */
    lv_obj_t * container = lv_obj_create(scr);
    lv_obj_set_size(container, 240, 320);
    lv_obj_center(container);

    /* 创建容器的样式并设置背景为黑色 */
    static lv_style_t style_container;
    lv_style_init(&style_container);
    lv_style_set_bg_color(&style_container, lv_color_black());
    lv_obj_add_style(container, &style_container, 0);

    /* 创建一个标签作为标题 */
    lv_obj_t * label = lv_label_create(container);
    lv_label_set_text(label, "About Device");
    lv_obj_set_style_text_color(label, lv_color_white(), 0);  // 设置标题文字颜色为白色
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 10);  // 将标题居中放置在顶部

    /* 添加设备信息标签 */
    lv_obj_t * info_label = lv_label_create(container);
    lv_label_set_text(info_label, "Device: MyDevice\nVersion: 1.0.0\nManufacturer: MyCompany");
    lv_obj_set_style_text_color(info_label, lv_color_white(), 0);  // 设置信息文字颜色为白色
    lv_obj_align(info_label, LV_ALIGN_CENTER, 0, 0);  // 将信息标签居中放置

    /* 创建Back按钮 */
    lv_obj_t * back_btn = lv_btn_create(container);
    lv_obj_set_size(back_btn, 100, 40);  // 设置按钮的宽度为100，高度为40
    lv_obj_align(back_btn, LV_ALIGN_BOTTOM_MID, 0, -10);  // 将按钮放置在容器底部
    lv_obj_t * back_label = lv_label_create(back_btn);
    lv_label_set_text(back_label, "Back");
    lv_obj_center(back_label);
    lv_obj_add_event_cb(back_btn, back_btn_event_handler, LV_EVENT_CLICKED, NULL);
}
