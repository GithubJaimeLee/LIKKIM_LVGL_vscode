/*********************
 *      INCLUDES
 *********************/
#ifndef __GUI_DATA_COMM_H__
#define __GUI_DATA_COMM_H__


#include <lvgl.h>
#include <string.h>
#include <stdio.h>

#define WALLET_LIB_USED		0

typedef struct
{
	uint8_t bg_src_id;		//保存的背景图序号
	void *bg_src;			//背景图资源
	
	char pin[8];			//保存的密码
	char language[32];		//保存的多语言类型

	bool word_set_complete;	//助记词设置完成
	uint8_t word_num;		//设置的助记词数量
	char word[24][16];		//保存的助记词内容

	int lock_time;			//锁屏时间，单位min，-1是never
	int shutdown_time;		//关机时间，单位min，-1是never
} gui_data_t;

/*获取modle名称*/
void *gui_data_get_modle_name(void);
/*获取bluetooth名称*/
void *gui_data_get_bluetooth_name(void);
/*获取system*/
void *gui_data_get_system(void);
/*获取system*/
void *gui_data_get_bluetooth(void);
/*获取bootloader*/
void *gui_data_get_bootloader(void);


/*获取Address的标题*/
void *gui_data_get_address_title(void);
/*获取Address的内容*/
void *gui_data_get_address_info(void);
/*获取Address的path*/
void *gui_data_get_address_path(void);

/*获取fee_payer的内容*/
void *gui_data_get_transaction_fee_payer(void);
/*获取fomat的内容*/
void *gui_data_get_transaction_format(void);
/*获取hash的内容*/
void *gui_data_get_transaction_hash(void);


uint8_t gui_data_get_bg_src_id(void);
void *gui_data_get_bg_src(void);
void gui_data_set_bg_src_id(uint8_t id);
char *gui_data_get_language(void);
void gui_data_set_language(char *language);
char *gui_data_get_pin(void);
void gui_data_set_pin(char *pin);
uint8_t gui_data_get_word_num(void);;
void gui_data_set_word_num(uint8_t word_num);
char *gui_data_get_word(uint8_t word_index);
void gui_data_set_word(uint8_t word_index, char *word);
int gui_data_get_shutdown_time(void);
void gui_data_set_shutdown_time(int shutdown_time);
int gui_data_get_lock_time(void);
void gui_data_set_lock_time(int lock_time);



void gui_data_init(void);
void gui_data_deinit(void);

#endif /* __GUI_DATA_COMM_H__ */


