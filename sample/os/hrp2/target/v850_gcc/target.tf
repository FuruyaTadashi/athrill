$
$ TOPPERS/ASP Kernel
$     Toyohashi Open Platform for Embedded Real-Time Systems/
$     Advanced Standard Profile Kernel
$
$ Copyright (C) 2010 by Meika Sugimoto
$
$ �嵭����Ԥϡ��ʲ���(1)�Ꮅ(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
$ �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
$ �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
$ (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
$     ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
$     ����������˴ޤޤ�Ƥ��뤳�ȡ�
$ (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$     �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
$     �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
$     ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
$ (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$     �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
$     �ȡ�
$   (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
$       �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
$   (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
$       ��𤹤뤳�ȡ�
$ (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
$     ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
$     �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
$     ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
$     ���դ��뤳�ȡ�
$
$ �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
$ ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
$ ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
$ �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
$ ����Ǥ�����ʤ���
$ 
$  ɸ��Υ��������Υ��ꥪ�֥�������°�������
$ 
$MEMATR_TEXT = (TA_NOWRITE|TA_EXEC)$
$MEMATR_RODATA = TA_NOWRITE$
$MEMATR_DATA = TA_MEMINI$
$MEMATR_BSS = TA_NULL$
$MEMATR_PRSV = TA_MEMPRSV$

$TARGET_MEMATR_USTACK = TA_NULL$

$ 
$  ɸ��Υ��������˴ؤ������
$  DSEC.ORDER_LIST��ID�Υꥹ��
$  DESC.MEMREG���������������֤������꡼�����
$  DESC.SECTION�����������̾
$  DESC.MEMATR�����������Υ��ꥪ�֥�������°��
$ 
$FUNCTION DEFINE_DSEC$
    $DSEC.ORDER_LIST = RANGE(0,4)$

    $DSEC.MEMREG[0] = STANDARD_ROM$
    $DSEC.SECTION[0] = ".text"$
    $DSEC.MEMATR[0] = MEMATR_TEXT$

    $DSEC.MEMREG[1] = STANDARD_ROM$
    $DSEC.SECTION[1] = ".rodata"$
    $DSEC.MEMATR[1] = MEMATR_RODATA$

    $DSEC.MEMREG[2] = STANDARD_RAM$
    $DSEC.SECTION[2] = ".data"$
    $DSEC.MEMATR[2] = MEMATR_DATA$

    $DSEC.MEMREG[3] = STANDARD_RAM$
    $DSEC.SECTION[3] = ".bss"$
    $DSEC.MEMATR[3] = MEMATR_BSS$

    $DSEC.MEMREG[4] = STANDARD_ROM$
    $DSEC.SECTION[4] = ".idata"$
    $DSEC.MEMATR[4] = TA_NOWRITE$

$END$

$ 
$  �桼�������å��ΰ����ݤ��륳���ɤ���Ϥ���
$  ARGV[1]��������ID
$  ARGV[2]�������å�������
$ 
$FUNCTION ALLOC_USTACK$
    static STK_T _kernel_ustack_$ARGV[1]$[COUNT_STK_T($ARGV[2]$)]
    $SPC$__attribute__((section($FORMAT("\".user_stack.%s\"", ARGV[1])$)));$NL$

    $TSK.TINIB_USTKSZ[ARGV[1]] = FORMAT("ROUND_STK_T(%s)", ARGV[2])$
    $TSK.TINIB_USTK[ARGV[1]] = FORMAT("_kernel_ustack_%s", ARGV[1])$
$END$

$ 
$  �桼�������å��ΰ�Υ��������̾���֤�
$  ARGV[1]��������ID
$ 
$FUNCTION SECTION_USTACK$
    $RESULT = FORMAT(".user_stack.%s", ARGV[1])$
$END$
$  DOMINICTXB�ν�������������
$ 
$FUNCTION GENERATE_DOMINICTXB$
	$SPC${
$   RX�ΰ�����ѡ�
    $SPC$&__start_text_$DOM.LABEL[ARGV[1]]$,
    $SPC$(&__limit_text_$DOM.LABEL[ARGV[1]]$ - 4),
$   R�ΰ�����ѡ�
    $SPC$&__start_rodata_$DOM.LABEL[ARGV[1]]$,
    $SPC$(&__limit_rodata_$DOM.LABEL[ARGV[1]]$ - 4),
$   RWX�ΰ�����ѡ�
    $SPC$&__start_ram_$DOM.LABEL[ARGV[1]]$,
    $SPC$(&__limit_ram_$DOM.LABEL[ARGV[1]]$ - 4),
$   ��ͭ�꡼�����ѥ饤��
    $SPC$$FORMAT("&__start_ram_%s_%x_%x", DOM.LABEL[ARGV[1]], +DEFAULT_ACPTN[ARGV[1]], +TACP_SHARED)$,
    $SPC$$FORMAT("(&__limit_ram_%s_%x_%x - 4)", DOM.LABEL[ARGV[1]], +DEFAULT_ACPTN[ARGV[1]], +TACP_SHARED)$,
$   �ΰ��ͭ���ӥåȤΥޥå�
    $SPC$$FORMAT("&dom_valid_map_table[%d]", (+ARGV[1] - 1))$
	},
$END$

$ 
$  TSKINICTXB�ν�������������
$ 
$FUNCTION GENERATE_TSKINICTXB$
	$SPC${
    $SPC$$TSK.TINIB_SSTKSZ[ARGV[1]]$, 
	$SPC$((void *)((char *)($TSK.TINIB_SSTK[ARGV[1]]$)
    $SPC$+ ($TSK.TINIB_SSTKSZ[ARGV[1]]$))),
    $IF (TSK.DOMAIN[ARGV[1]] == TDOM_KERNEL)$
        $SPC$0, 0, 0, 0 },
    $ELSE$
        $SPC$$TSK.TINIB_USTKSZ[ARGV[1]]$, 
        $SPC$((void *)((char *)($TSK.TINIB_USTK[ARGV[1]]$)
        $SPC$+ ($TSK.TINIB_USTKSZ[ARGV[1]]$))),
        $SPC$$FORMAT("&__start_user_stack%s", ARGV[1])$,
        $SPC$$FORMAT("(&__limit_user_stack%s - 4)", ARGV[1])$,
        },
    $END$
$END$
$
$

$TOPPERS_SUPPORT_ATT_MOD = 1$

$INCLUDE "v850_gcc/v850es_fk3.tf"$
$IF LENGTH(TEXCNO_EMULATE_RET_TEX)$
    $TAB$.section .rodata_kernel$NL$
    $TAB$.align 4$NL$
    $TAB$.global __kernel_emulate_ret_tex_handler$NL$
    $TAB$.extern
    $IF LENGTH(EXC.EXCHDR[TEXCNO_EMULATE_RET_TEX])$
        $SPC$_$EXC.EXCHDR[TEXCNO_EMULATE_RET_TEX]$
    $ELSE$
        $SPC$__kernel_default_exc_handler
    $END$
    $NL$

    __kernel_emulate_ret_tex_handler:$NL$
    $IF LENGTH(EXC.EXCHDR[TEXCNO_EMULATE_RET_TEX])$
        $TAB$.long _$EXC.EXCHDR[TEXCNO_EMULATE_RET_TEX]$$NL$
    $ELSE$
        $TAB$.long __kernel_default_exc_handler$NL$
    $END$
$END$

$ 
$  MPUͭ���ΰ�Υӥåȥޥå׾��������
$ 
$FILE "kernel_mem2.c"$
$IF LENGTH(DOM.ID_LIST)$
	const uint32_t dom_valid_map_table[TNUM_DOMID] = {$NL$
	$JOINEACH domid DOM.ID_LIST ",\n"$
        $TAB$0x0
	$END$,$NL$
	};$NL$
	$NL$
$ELSE$
	const DOMINIB dom_valid_map_table[0];$NL$
$END$$NL$
$ $INCLUDE "arch/logtrace/tlv.tf"$
