/*
 *  TOPPERS/HRP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 *	
 *	Copyright (C) 2011-2012 by Embedded and Real-Time Systems Laboratory
 *				Graduate School of Information Science, Nagoya Univ., JAPAN
 *	
 *	�嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *	�����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *	�ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *	(1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *		��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *		����������˴ޤޤ�Ƥ��뤳�ȡ�
 *	(2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *		�ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *		�ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *		��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *	(3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *		�ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *		�ȡ�
 *	  (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *		  �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *	  (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *		  ��𤹤뤳�ȡ�
 *	(4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *		������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *		�ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *		ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *		���դ��뤳�ȡ�
 *	
 *	�ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *	���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *	���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *	�������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *	����Ǥ�����ʤ���
 *	
 */

/*
 *	MPU�ɥ饤�С�SH72AW�ѡ�
 */

#include "kernel_impl.h"
#include <sil.h>
#include "kernel_cfg.h"
#include "target_mpu.h"

extern char _vector_start;
extern char _vector_end;
extern char _vector_entry_start;
extern char _vector_entry_end;

void
target_mpu_initialize(void)
{
    char *shared_mem_start;
    char *shared_mem_end;

    /*
     *  �ΰ�5: ��ͭtext
     */
    shared_mem_start = shared_meminib_table[0];
    shared_mem_end   = shared_meminib_table[1];
    sil_wrw_mem((void *)(MPCSADR5), (uint32_t)shared_mem_start);
    sil_wrw_mem((void *)(MPCEADR5), (uint32_t)shared_mem_end);

    /*
     *  �ΰ�6: ��ͭrodata
     */
    shared_mem_start = shared_meminib_table[2];
    shared_mem_end   = shared_meminib_table[3];
    sil_wrw_mem((void *)(MPCSADR6), (uint32_t)shared_mem_start);
    sil_wrw_mem((void *)(MPCEADR6), (uint32_t)shared_mem_end);

    /*
     *  �ΰ�7: ��ͭdata
     */
    shared_mem_start = shared_meminib_table[4];
    shared_mem_end   = shared_meminib_table[5];
    sil_wrw_mem((void *)(MPCSADR7), (uint32_t)shared_mem_start);
    sil_wrw_mem((void *)(MPCEADR7), (uint32_t)shared_mem_end);

    /*
     *  �ΰ�8: ��ͭ�꡼�����ѥ饤���ΰ�����
     */
    shared_mem_start = shared_meminib_table[6];
    shared_mem_end   = shared_meminib_table[7];
    sil_wrw_mem((void *)(MPCSADR8), (uint32_t)shared_mem_start);
    sil_wrw_mem((void *)(MPCEADR8), (uint32_t)shared_mem_end);

    /*
     *  �ΰ�9���٥����ơ��֥�
     */
    sil_wrw_mem((void *)(MPCSADR9), (uint32_t)&_vector_start);
    sil_wrw_mem((void *)(MPCEADR9), (((uint32_t)(&_vector_end) + 3) & 0xfffffffc) - 4);

    /*
     *  �ΰ�10���٥�������ȥ�
     */
    sil_wrw_mem((void *)(MPCSADR10), (uint32_t)&_vector_entry_start);
    sil_wrw_mem((void *)(MPCEADR10), (((uint32_t)(&_vector_entry_end) + 3) & 0xfffffffc) - 4);

    /*
     *  �ΰ�11��MPUͭ���쥸����
     */
    sil_wrw_mem((void *)(MPCSADR11), (uint32_t)MPCMPEN);
    sil_wrw_mem((void *)(MPCEADR11), (uint32_t)MPCMPEN);

    /*
     *  R������������
     */
    sil_wrw_mem((void *)(MPCRACR), (uint32_t)(0xaaaa07f7));

    /*
     *  W������������
     */
    sil_wrw_mem((void *)(MPCWACR), (uint32_t)(0xaaaa089c));

    /*
     *  I(X)������������
     */
    sil_wrw_mem((void *)(MPCIACR), (uint32_t)(0xaaaa0421));

}

void
target_mpu_exc_handler(void *p_excinf)
{
    syslog(LOG_EMERG, "MPU EXCEPTION OCCURED!!");
    while(1);
}

// �������㳰�¹Գ��ϻ������å������ϥ�ɥ�
void
target_emulate_texrtn_handler(void *p_excinf)
{
    syslog(LOG_EMERG, "User stack is no space at prepare texrtn.");
    while(1);
}

// �������㳰�꥿����������å������ϥ�ɥ�
void
target_emulate_ret_tex_handler(void *p_excinf)
{
    syslog(LOG_EMERG, "User stack is no space at return texrtn.");
    while(1);
}


/*
 *  ���ꤵ�줿���ɥ쥹���桼���⡼�ɻ��˽���߲�ǽ��������å�����
 */
#ifdef OMIT_PROBE_MEM_WRITE
bool_t
probe_mem_write(void *base, SIZE size)
{
	uint32_t top;

    /*
     *  ��Ƭ���ɥ쥹�򥵡���
     */
    sil_wrw_mem((void *)MPCRSADR, (uint32_t)base); /* ���������륢�ɥ쥹�򥻥å�*/
    sil_wrb_mem((void *)MPCRSOP,  (uint8_t)MPCRSOP_S_BIT);  /* �ΰ襵�����򳫻� */

	/* 
     *  ��Ƭ���ɥ쥹�Υ�������̤���¸
     */
	top = sil_rew_mem((void *)MPCHITO);

	/* 
     *  ����߲�ǽ�������å�
     */
	if((top & MPCHITO_W_MASK) == 0){
		return false;
	}

    /*
     *  ��λ���ɥ쥹�򥵡���
     */
    sil_wrw_mem((void *)MPCRSADR, (uint32_t)(base + size)); /* ���������륢�ɥ쥹�򥻥å�*/
    sil_wrb_mem((void *)MPCRSOP,  (uint8_t)MPCRSOP_S_BIT);  /* �ΰ襵�����򳫻� */

	/* 
     *  ��Ƭ���ɥ쥹�Υ�������̤Ȱ��פ��뤫�ɤ���������å�
     */
	if(sil_rew_mem((void *)MPCHITO) != top){
        return false;
    }

	return true;
}
#endif /* OMIT_PROBE_MEM_WRITE */

/*
 *  ���ꤵ�줿���ɥ쥹���桼���⡼�ɻ����ɹ��߲�ǽ��������å�����
 */
#ifdef OMIT_PROBE_MEM_READ
bool_t
probe_mem_read(void *base, SIZE size)
{
	uint32_t top;

    /*
     *  ��Ƭ���ɥ쥹�򥵡���
     */
    sil_wrw_mem((void *)MPCRSADR, (uint32_t)base); /* ���������륢�ɥ쥹�򥻥å�*/
    sil_wrb_mem((void *)MPCRSOP,  (uint8_t)MPCRSOP_S_BIT);  /* �ΰ襵�����򳫻� */

	/* 
     *  ��Ƭ���ɥ쥹�Υ�������̤���¸
     */
	top = sil_rew_mem((void *)MPCHITO);

	/* 
     *  �ɤ߽Ф���ǽ�������å�
     */
	if((top & MPCHITO_R_MASK) == 0){
		return false;
	}

    /*
     *  ��λ���ɥ쥹�򥵡���
     */
    sil_wrw_mem((void *)MPCRSADR, (uint32_t)(base + size)); /* ���������륢�ɥ쥹�򥻥å�*/
    sil_wrb_mem((void *)MPCRSOP,  (uint8_t)MPCRSOP_S_BIT);  /* �ΰ襵�����򳫻� */

	/* 
     *  ��Ƭ���ɥ쥹�Υ�������̤Ȱ��פ��뤫�ɤ���������å�
     */
	if(sil_rew_mem((void *)MPCHITO) != top){
        return false;
    }

	return true;
}
#endif /* OMIT_PROBE_MEM_READ */

/*
 *  ���ꤵ�줿�ΰ褬�桼�������å��ΰ�˼��ޤäƤ��뤫������å�����
 */
#ifdef OMIT_PROBE_STACK

bool_t
probe_stack(void *base, SIZE size)
{
	if((sil_rew_mem((void *)MPCSADR4) <= (uint32_t)base) &&
	   (sil_rew_mem((void *)MPCEADR4) >= (uint32_t)((SIZE)base + size))){
		return true;
	}

	return false;
}
#endif /* OMIT_PROBE_STACK */


