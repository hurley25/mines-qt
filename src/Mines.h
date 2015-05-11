/**
 * 一些有关界面魔数的宏定义
 *  @hurley
 *  2013/12/04
 */

#ifndef MINES_H
#define MINES_H

// 定义数字区域图片宽度
#define PIC_NUM_WIDTH		(20)

// 定义数字区域图片高度
#define PIC_NUM_HIGHT		(40)

// 定义笑脸区域图片长度
#define PIC_FACE_SIZE		(30)

// 定义笑脸按钮旁白
#define PIC_FACE_BRINK       (6)

// 定义雷区显示和窗口顶距
#define VIEW_HEIGHT_BRINK   (80)

// 定义雷区显示和窗口旁距
#define VIEW_WIDTH_BRINK    (18)

// 定义地雷区域图片长度
#define PIC_MINE_SIZE	   (25)

// 定义笑脸状态参数
#define PIC_FACEORIG		    (0)
#define PIC_FACEFAIL		    (1)
#define PIC_FACEWIN		    (2)

// 雷区资源的宏定义，同时应用于贴图顺序
#define  PIC_ORIG			(0)
#define  PIC_NUM1		    (1)
#define  PIC_NUM2			(2)
#define  PIC_NUM3			(3)
#define  PIC_NUM4			(4)
#define  PIC_NUM5			(5)
#define  PIC_NUM6			(6)
#define  PIC_NUM7		    (7)
#define  PIC_NUM8			(8)
#define  PIC_MINE			(9)
#define  PIC_MINE_RED	   (10)
#define  PIC_MINE_ERR	   (11)
#define  PIC_FLAG		   (12)
#define  PIC_QUES		   (13)
#define  PIC_BLANK		   (14)
#define  PIC_ORIGLIGHT	   (15)

#endif // MINES_H
