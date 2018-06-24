$ ======================================================================
$
$   TOPPERS/HRP Kernel
$       Toyohashi Open Platform for Embedded Real-Time Systems/
$       High Reliable system Profile Kernel
$
$   Copyright (C) 2011-2012 by Embedded and Real-Time Systems Laboratory
$               Graduate School of Information Science, Nagoya Univ., JAPAN
$  
$   �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
$   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
$   �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
$   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
$       ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
$       ����������˴ޤޤ�Ƥ��뤳�ȡ�
$   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
$       �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
$       ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
$   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
$       �ȡ�
$     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
$         �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
$     (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
$         ��𤹤뤳�ȡ�
$   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
$       ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
$       �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
$       ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
$       ���դ��뤳�ȡ�
$  
$   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
$   ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
$   ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
$   �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
$   ����Ǥ�����ʤ���
$
$ =====================================================================

$ 
$     �ѥ�2�Υ������åȰ�¸�ƥ�ץ졼�ȡ�SH2A-MG-EVB�ѡ�
$ 


$INTNO_VALID = { 94,95,...,101;
                 102,103,...,114;
                 134,135,136;
                 142,143,144,145,148;
                 156;
                 312,313,...,351;
                 353,354,...,359;
                 403,404,407,408;
                 411,412,415,416;
                 427,428,...,464;
                 478,479,...,482;
                 487,488,...,493 }$

$INHNO_VALID = INTNO_VALID$

$EXCNO_VALID = { 4;6;9;10;11;12;14;15;16;17;18;19;
				 32,33,...,63 }$

$ 
$  Ʊ�������ͥ���٤����ꤷ�ʤ���Фʤ�ʤ�������ֹ�Υꥹ��
$  ����-1�򥻥ѥ졼���Ȥ��롣��
$ 
$same_intpri_list = { 108,109,-1,
					  112,113,-1,
					  116,117,-1,
					  120,121,-1,
					  124,125,-1,
					  128,129,-1,
					  132,133,-1,
					  136,137,-1,
					  156,157,158,159,-1,
					  160,161,162,-1,
					  164,165,-1,
					  168,169,-1,
					  172,173,-1,
					  176,177,-1,
					  180,181,182,183,-1,
					  188,189,190,191,-1,
					  196,197,198,-1,
					  200,201,-1,
					  204,205,206,207,-1,
					  212,213,214,215,-1,
					  220,221,222,-1,
					  228,229,230,231,232,-1,
					  240,241,242,243,-1,
					  244,245,246,247,-1,
					  248,249,250,251,-1,
					  252,253,254,255,-1,
					  256,257,258,-1
					}$


$ 
$ IRQ����ߤǻ��ѤǤ�������°��
$ 		���ݥ��ƥ��֥��å�
$ 		���ͥ��ƥ��֥��å�
$ 		��ξ�ƥ��֥��å�
$ 		������٥�
$ 
$valid_irq_intatr_list = {
	0,
	TA_POSEDGE,
	TA_NEGEDGE,
	TA_BOTHEDGE,
	TA_EDGE,
	TA_EDGE | TA_POSEDGE,
	TA_EDGE | TA_NEGEDGE,
	TA_EDGE | TA_BOTHEDGE,
	TA_LOWLEVEL
}$

$ 
$ NMI�ǻ��ѤǤ�������°��
$ 		���ݥ��ƥ��֥��å�
$ 		���ͥ��ƥ��֥��å�
$ 
$valid_nmi_intatr_list = {
	TA_POSEDGE,
	TA_NEGEDGE,
	TA_EDGE,
	TA_EDGE | TA_POSEDGE,
	TA_EDGE | TA_NEGEDGE
}$

$ 
$  kernel/kernel.tf�Τ�������
$ 

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

$ 
$  ����Ĺ����ס����ΰ����ݤ��륳���ɤ���Ϥ���
$  ARGV[1]������Ĺ����ס���ID
$  ARGV[2]���ɥᥤ��ID
$  ARGV[3]���֥�å���
$  ARGV[4]���֥�å�������
$ 
$FUNCTION ALLOC_UMPF$
    static MPF_T _kernel_mpf_$ARGV[1]$[($ARGV[3]$) * COUNT_MPF_T($ARGV[4]$)]
    $SPC$__attribute__((section($FORMAT("\".mpf.%s\"", ARGV[1])$)));$NL$
$END$

$ 
$  ����Ĺ����ס����ΰ�Υ��������̾���֤�
$  ARGV[1]��������ID
$ 
$FUNCTION SECTION_UMPF$
    $RESULT = FORMAT(".mpf.%s", ARGV[1])$
$END$

$TARGET_MEMATR_MPFAREA = TA_MEMPRSV$

$ 
$  arch/gcc/ldscript.tf�Υ������åȰ�¸��
$ 
$FUNCTION GENERATE_OUTPUT$
    OUTPUT_FORMAT("elf32-sh") $NL$
    OUTPUT_ARCH(sh)           $NL$
    STARTUP(start.o)          $NL$
    $NL$
$END$

$FUNCTION GENERATE_PROVIDE$
    PROVIDE(_hardware_init_hook = 0);$NL$
    PROVIDE(_software_init_hook = 0);$NL$
    PROVIDE(_software_term_hook = 0);$NL$
    PROVIDE(__kernel_bsssecinib_table = 0);$NL$
    PROVIDE(__kernel_tnum_bsssec = 0);$NL$
    PROVIDE(__kernel_datasecinib_table = 0);$NL$
    PROVIDE(__kernel_tnum_datasec = 0);$NL$
    $NL$

    $IF LENGTH(DOM.ID_LIST)$
        $FOREACH domid DOM.ID_LIST$
$   RX�ΰ�����ѡ�
            PROVIDE(___start_text_$DOM.LABEL[domid]$ = 0xffffffff);$NL$
            PROVIDE(___limit_text_$DOM.LABEL[domid]$ = 0xffffffff);$NL$
$   R�ΰ�����ѡ�
            PROVIDE(___start_rodata_$DOM.LABEL[domid]$ = 0xffffffff);$NL$
            PROVIDE(___limit_rodata_$DOM.LABEL[domid]$ = 0xffffffff);$NL$
$   RWX�ΰ�����ѡ�
            PROVIDE(___start_ram_$DOM.LABEL[domid]$ = 0xffffffff);$NL$
            PROVIDE(___limit_ram_$DOM.LABEL[domid]$ = 0xffffffff);$NL$
$   ��ͭ�꡼�����ѥ饤��
            PROVIDE($FORMAT("___start_ram_%s_%x_%x", DOM.LABEL[domid], +DEFAULT_ACPTN[domid], +TACP_SHARED)$ = 0xffffffff);$NL$
            PROVIDE($FORMAT("___limit_ram_%s_%x_%x", DOM.LABEL[domid], +DEFAULT_ACPTN[domid], +TACP_SHARED)$ = 0xffffffff);$NL$
$  ��ͭ�ΰ�
            PROVIDE(___start_text_$DOM.LABEL[TDOM_NONE]$ = 0xffffffff);$NL$
            PROVIDE(___limit_text_$DOM.LABEL[TDOM_NONE]$ = 0xffffffff);$NL$
            PROVIDE(___start_rodata_$DOM.LABEL[TDOM_NONE]$ = 0xffffffff);$NL$
            PROVIDE(___limit_rodata_$DOM.LABEL[TDOM_NONE]$ = 0xffffffff);$NL$
            PROVIDE(___start_ram_$DOM.LABEL[TDOM_NONE]$ = 0xffffffff);$NL$
            PROVIDE(___limit_ram_$DOM.LABEL[TDOM_NONE]$ = 0xffffffff);$NL$
        $END$
        $NL$
    $END$$NL$
$   ��ͭ�꡼�����ѥ饤���ΰ�����
    PROVIDE(___start_srpw_all = 0xffffffff);$NL$
    PROVIDE(___limit_srpw_all = 0xffffffff);$NL$
$END$

$FUNCTION GENERATE_SECTION_FIRST$
    $TAB$.vector_start : {$NL$
    $TAB$$TAB$__vector_start = .;$NL$
    $TAB$$TAB$*(.vector)$NL$
    $TAB$$TAB$__vector_end = .;$NL$
    $TAB$$TAB$start.o(.text_kernel)$NL$
    $TAB$$TAB$start.o(*.text*)$NL$
    $TAB$} > $REG.REGNAME[STANDARD_ROM]$$NL$
    $NL$
    $TAB$.vector_entry : {$NL$
    $TAB$$TAB$__vector_entry_start = .;$NL$
    $TAB$$TAB$*(.vector_entry)$NL$
    $TAB$$TAB$__vector_entry_end = .;$NL$
    $TAB$}  > $REG.REGNAME[STANDARD_ROM]$$NL$
    $NL$
    $TAB$.bss : {$NL$
    $TAB$} > $REG.REGNAME[STANDARD_RAM]$$NL$
    $NL$
$END$

$TARGET_PAGE_SIZE_STR = 4$
$TARGET_SEC_ALIGN_STR = 4$

$TOPPERS_SUPPORT_ATT_MOD = 1$

$ 
$ �ݸ�ɥᥤ����������ƥ����ȥ֥�å��Τ�������
$ 
$FUNCTION PREPARE_DOMINICTXB$
    $IF LENGTH(DOM.ID_LIST)$
        $FOREACH domid DOM.ID_LIST$
$   RX�ΰ�����ѡ�
            extern char __start_text_$DOM.LABEL[domid]$;$NL$
            extern char __limit_text_$DOM.LABEL[domid]$;$NL$
$   R�ΰ�����ѡ�
            extern char __start_rodata_$DOM.LABEL[domid]$;$NL$
            extern char __limit_rodata_$DOM.LABEL[domid]$;$NL$
$   RWX�ΰ�����ѡ�
            extern char __start_ram_$DOM.LABEL[domid]$;$NL$
            extern char __limit_ram_$DOM.LABEL[domid]$;$NL$
$   ��ͭ�꡼�����ѥ饤��
            extern char $FORMAT("__start_ram_%s_%x_%x", DOM.LABEL[domid], +DEFAULT_ACPTN[domid], +TACP_SHARED)$;$NL$
            extern char $FORMAT("__limit_ram_%s_%x_%x", DOM.LABEL[domid], +DEFAULT_ACPTN[domid], +TACP_SHARED)$;$NL$
        $END$
        extern uint32_t dom_valid_map_table[];
        $NL$
    $END$$NL$

$  ��ͭ�ΰ�
    extern char __start_text_$DOM.LABEL[TDOM_NONE]$;$NL$
    extern char __limit_text_$DOM.LABEL[TDOM_NONE]$;$NL$
    extern char __start_rodata_$DOM.LABEL[TDOM_NONE]$;$NL$
    extern char __limit_rodata_$DOM.LABEL[TDOM_NONE]$;$NL$
    extern char __start_ram_$DOM.LABEL[TDOM_NONE]$;$NL$
    extern char __limit_ram_$DOM.LABEL[TDOM_NONE]$;$NL$
    extern char __start_srpw_all;$NL$
    extern char __limit_srpw_all;$NL$

    $IF LENGTH(TSK.ID_LIST)$
        $FOREACH tskid TSK.ID_LIST$
            $IF TSK.DOMAIN[tskid] != TDOM_KERNEL$
                extern char $FORMAT("__start_user_stack%s", tskid)$;$NL$
                extern char $FORMAT("__limit_user_stack%s", tskid)$;$NL$
            $END$
        $END$
    $END$
$END$

$ 
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
$  ��󥫤Τ���Υ�������󵭽Ҥ�����
$
$FUNCTION SECTION_DESCRIPTION$
	$IF EQ(ARGV[1], ".rodata")$
		$RESULT = ".rodata .rodata.str1.4"$
	$ELIF EQ(ARGV[1], ".bss")$
		$RESULT = ".bss COMMON"$
	$ELSE$
		$RESULT = ARGV[1]$
	$END$
$END$

$ 
$  ATT_MEM�Υ������åȰ�¸��
$  ATTMEM_LIST: ATT_MEM����Ͽ���줿MEM�Υꥹ��
$  DOM.MEM_COUNT[domid]: �ݸ�ɥᥤ���°����MEM�ο�
$                       1�ݸ�ɥᥤ�󤢤����1�Ĥ�MEM�Τ�°���뤳�Ȥ��Ǥ���
$                       1�Ĥ�MEM����ͭ�Ǥ��ä����ˤϡ�¾��MEM����Ͽ�Ǥ��ʤ�
$  SHARED_MEM_COUNT: ��ͭ��MEM�ο�
$  ALL_MEM_COUNT: MEM�ο�
$  DOM.MEM_BASE[domid]: �ݸ�ɥᥤ���°����MEM����Ƭ����
$  DOM.MEM_SIZE[domid]: �ݸ�ɥᥤ���°����MEM�Υ�����
$ATTMEM_LIST = {}$
$ALL_MEM_COUNT = 0$
$SHARED_MEM_COUNT = 0$
$FOREACH domid DOM.ID_LIST$
    $DOM.MEM_COUNT[domid] = 0$
    $DOM.MEM_BASE[domid] = 0$
    $DOM.MEM_SIZE[domid] = 0$
$END$
$FUNCTION HOOK_ERRORCHECK_MEM$
    $WARNING$$FORMAT("ATT_MEM is not supported.")$$END$
$END$


$ 
$  �ץ��å���¸�Υƥ�ץ졼�ȥե�����Υ��󥯥롼��
$ 
$INCLUDE "sh12a_gcc/prc.tf"$ 
$INCLUDE "gcc/ldscript.tf"$ 

$ 
$  �桼�������å��Υ����������å�
$ 
$FOREACH tskid TSK.ID_LIST$
    $IF (TSK.DOMAIN[tskid] != TDOM_KERNEL) && (TSK.STKSZ[tskid] % 4)$
        $ERROR$$FORMAT("the user stack of TASK(%1%) does not meet MPU size constraints. size = %2%", tskid, +TSK.STKSZ[tskid])$$END$
    $END$
$END$

$ 
$  ��ͭ�ΰ�ν�����֥�å�������
$ 
$FILE "kernel_cfg.h"$
extern const uint_t tnum_shared_mem;$NL$
extern char * const shared_meminib_table[];$NL$
$NL$

$FILE "kernel_cfg.c"$
$TNUM_SHARED_REGION = 4$
const uint_t tnum_shared_mem = $TNUM_SHARED_REGION * 2$;$NL$
char * const shared_meminib_table[$TNUM_SHARED_REGION * 2$] = {$NL$
    $SPC$&__start_text_$DOM.LABEL[TDOM_NONE]$,
    $SPC$(&__limit_text_$DOM.LABEL[TDOM_NONE]$ - 4),
    $SPC$&__start_rodata_$DOM.LABEL[TDOM_NONE]$,
    $SPC$(&__limit_rodata_$DOM.LABEL[TDOM_NONE]$ - 4),
    $SPC$&__start_ram_$DOM.LABEL[TDOM_NONE]$,
    $SPC$(&__limit_ram_$DOM.LABEL[TDOM_NONE]$ - 4),
    $SPC$&__start_srpw_all,
    $SPC$(&__limit_srpw_all - 4),
};$NL$
$NL$

$ 
$  ���ߥ�졼�Ȥ��줿CPU�㳰�ϥ�ɥ�Υ��ɥ쥹
$ 
$FILE "kernel_cfg_asm.S"$
$IF LENGTH(TEXCNO_EMULATE_TEXRTN)$
    $TAB$.section .rodata_kernel$NL$
    $TAB$.align 4$NL$
    $TAB$.global __kernel_emulate_texrtn_handler$NL$
    $TAB$.extern
    $IF LENGTH(EXC.EXCHDR[TEXCNO_EMULATE_TEXRTN])$
        $SPC$_$EXC.EXCHDR[TEXCNO_EMULATE_TEXRTN]$
    $ELSE$
        $SPC$__kernel_default_exc_handler
    $END$
    $NL$

    __kernel_emulate_texrtn_handler:$NL$
    $IF LENGTH(EXC.EXCHDR[TEXCNO_EMULATE_TEXRTN])$
        $TAB$.long _$EXC.EXCHDR[TEXCNO_EMULATE_TEXRTN]$$NL$
    $ELSE$
        $TAB$.long __kernel_default_exc_handler$NL$
    $END$
$END$
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

$ 
$  data, idata���������κ����֤򤹤뤿��Υ����륹����ץȤ�����
$ 
$IF COPY_IDATA_SECTION == 1$
    $INCLUDE "section_rename.tf"$
$END$

