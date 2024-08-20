/*********************
 *      INCLUDES
 *********************/
#ifndef __SETTINGS_POWER_OFF_H__
#define __SETTINGS_POWER_OFF_H__


#include <lvgl.h>

typedef struct
{
	lv_obj_t* bg_cont;
} settings_power_off_t;


extern void settings_power_off_start(void);
extern void settings_power_off_stop(void);

#endif /* __SETTINGS_POWER_OFF_H__ */


