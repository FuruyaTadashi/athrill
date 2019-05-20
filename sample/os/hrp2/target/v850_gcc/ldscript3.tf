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

$ =====================================================================
$ ��󥫥�����ץȤ�����
$ =====================================================================
$FILE "ldscript3.ld"$

$
$  �������åȰ�¸��OUTPUT���Ҥ�����
$
OUTPUT_FORMAT("elf32-sh") $NL$
OUTPUT_ARCH(sh)           $NL$
$NL$

$
$  MEMORY���Ҥ�����
$
MEMORY {$NL$
$FOREACH reg REG.ORDER_LIST$
	$TAB$$REG.REGNAME[reg]$$SPC$:$SPC$
	ORIGIN = $REG.BASE[reg]$, LENGTH = $REG.SIZE[reg]$$NL$
$END$
}$NL$
$NL$

$
$  �������åȰ�¸��PROVIDE���Ҥ�����
$
$IF ISFUNCTION("GENERATE_PROVIDE")$
	$GENERATE_PROVIDE()$
$END$

$
$  ��󥯻��������
$
SECTIONS {$NL$
$ �������åȰ�¸�Υ�������󵭽Ҥ�����
$TAB$.vector_start : {$NL$
$TAB$$TAB$$PRE_OBJ$(.vector_start)$NL$
$TAB$} > $REG.REGNAME[STANDARD_ROM]$$NL$
$NL$
$TAB$.vector_entry : {$NL$
$TAB$$TAB$$PRE_OBJ$(.vector_entry)$NL$
$TAB$}  > $REG.REGNAME[STANDARD_ROM]$$NL$
$NL$
$TAB$.bss : {$NL$
$TAB$} > $REG.REGNAME[STANDARD_RAM]$$NL$
$NL$


$IF TOPPERS_LABEL_ASM$
	$PREFIX_START = "___start_"$
	$PREFIX_END   = "___end_"$
	$PREFIX_LIMIT = "___limit_"$
$ELSE$
	$PREFIX_START = "__start_"$
	$PREFIX_END   = "__end_"$
	$PREFIX_LIMIT = "__limit_"$
$END$

$FOREACH moid MO_ORDER$
	$IF MO.LINKER[moid]$
$		// ���������ȥ��ꥪ�֥������Ȥγ��ϵ��Ҥ�����
		$IF (MO.SEFLAG[moid] & 0x01) != 0$
            $TAB$.$MO.SLABEL[moid]$
            $IF LENGTH(POSITION[MO.MEMREG[moid]])$
                $SPC$($POSITION[MO.MEMREG[moid]]$)$SPC$
            $ELSE$
                $SPC$
            $END$
            : {$NL$
		$END$
		$IF (MO.SEFLAG[moid] & 0x02) != 0$

			$IF !OMIT_IDATA && !EQ(MO.ILABEL[moid], "")$
                $TAB$$TAB$$MO.SLABEL[moid]$.$PRE_OBJ$(*)$NL$
			    $TAB$} > $REG.REGNAME[MO.MEMREG[moid]]$$NL$
                $TAB$. = ALIGN($TARGET_PAGE_SIZE_STR$);$NL$
                $POSITION[MO.MEMREG[moid]] = CONCAT(PREFIX_LIMIT,MO.SLABEL[moid])$
                $TAB$$POSITION[MO.MEMREG[moid]]$ = .;$NL$
                $TAB$.$MO.ILABEL[moid]$ ($POSITION[STANDARD_ROM]$) : {$NL$
                $TAB$$TAB$$PRE_OBJ$(.$MO.ILABEL[moid]$)$NL$
                $TAB$} > $REG.REGNAME[STANDARD_ROM]$$NL$
                $TAB$. = ALIGN($TARGET_PAGE_SIZE_STR$);$NL$
                $POSITION[STANDARD_ROM] = CONCAT(PREFIX_LIMIT,MO.ILABEL[moid])$
                $TAB$$POSITION[STANDARD_ROM]$ = .;$NL$
            $ELSE$
                $TAB$$TAB$$PRE_OBJ$(.$MO.SLABEL[moid]$)$NL$
			    $TAB$} > $REG.REGNAME[MO.MEMREG[moid]]$$NL$
                $TAB$. = ALIGN($TARGET_PAGE_SIZE_STR$);$NL$
                $POSITION[MO.MEMREG[moid]] = CONCAT(PREFIX_LIMIT,MO.SLABEL[moid])$
                $TAB$$POSITION[MO.MEMREG[moid]]$ = .;$NL$
			$END$
		$END$

		$IF (MO.SEFLAG[moid] & 0x02) != 0$
			$NL$
		$END$
	$END$
$END$

$FOREACH lsid RANGE(1, numls)$
	$TAB$$LNKSEC.SECTION[lsid]$ : {$NL$
	$TAB$$TAB$*($LNKSEC.SECTION[lsid]$)$NL$
	$TAB$} > $REG.REGNAME[LNKSEC.MEMREG[lsid]]$$NL$
	$NL$
$END$

$TAB$/DISCARD/ : {$NL$
$TAB$$TAB$*(.rel.dyn)$NL$
$TAB$}$NL$
$NL$

$TAB$/* DWARF debug sections.$NL$
$TAB$Symbols in the DWARF debugging sections are relative to $NL$
$TAB$the beginning of the section so we begin them at 0.  */$NL$
$NL$
$TAB$/* DWARF 1 */$NL$
$TAB$.debug          0 : { *(.debug) }$NL$
$TAB$.line           0 : { *(.line) }$NL$
$NL$
$TAB$/* GNU DWARF 1 extensions */$NL$
$TAB$.debug_srcinfo  0 : { *(.debug_srcinfo) }$NL$
$TAB$.debug_sfnames  0 : { *(.debug_sfnames) }$NL$
$NL$
$TAB$/* DWARF 1.1 and DWARF 2 */$NL$
$TAB$.debug_aranges  0 : { *(.debug_aranges) }$NL$
$TAB$.debug_pubnames 0 : { *(.debug_pubnames) }$NL$
$NL$
$TAB$/* DWARF 2 */$NL$
$TAB$.debug_info     0 : { *(.debug_info) }$NL$
$TAB$.debug_abbrev   0 : { *(.debug_abbrev) }$NL$
$TAB$.debug_line     0 : { *(.debug_line) }$NL$
$TAB$.debug_frame    0 : { *(.debug_frame) }$NL$
$TAB$.debug_str      0 : { *(.debug_str) }$NL$
$TAB$.debug_loc      0 : { *(.debug_loc) }$NL$
$TAB$.debug_macinfo  0 : { *(.debug_macinfo) }$NL$
$TAB$.debug_ranges   0 : { *(.debug_ranges) }$NL$
$NL$
$TAB$/* SGI/MIPS DWARF 2 extensions */$NL$
$TAB$.debug_weaknames 0 : { *(.debug_weaknames) }$NL$
$TAB$.debug_funcnames 0 : { *(.debug_funcnames) }$NL$
$TAB$.debug_typenames 0 : { *(.debug_typenames) }$NL$
$TAB$.debug_varnames  0 : { *(.debug_varnames) }$NL$
$NL$
}$NL$
