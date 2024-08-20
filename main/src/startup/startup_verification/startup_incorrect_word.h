/*********************
 *      INCLUDES
 *********************/
#ifndef __STARTUP_INCORRECT_WORD_H__
#define __STARTUP_INCORRECT_WORD_H__


#include <lvgl.h>

enum
{
	WORD_VERIFACATION_STATE_1 = 0x01,
	WORD_VERIFACATION_STATE_2 = 0x02,
	WORD_VERIFACATION_STATE_ALL = 0x03,
};
typedef uint8_t word_incorrect_word_state_t;


typedef struct
{
	lv_obj_t* bg_cont;
} startup_incorrect_word_t;


void startup_incorrect_word_start(void);
void startup_incorrect_word_stop(void);

#endif /* __STARTUP_INCORRECT_WORD_H__ */


