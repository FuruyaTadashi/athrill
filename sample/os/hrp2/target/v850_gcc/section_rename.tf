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

$FILE "section_rename_cfg.sh"$
$PRE_OBJ = "hrp2.tmp.elf"$
$FINAL_OBJ = "hrp2.elf"$
$FINAL_LDSCRIPT = "ldscript3.ld"$
$CRE_FILE_LIST = {}$

mv $FINAL_OBJ$ $PRE_OBJ$$NL$

$IF !OMIT_IDATA$
    $IF LENGTH(DATASEC_LIST)$
        $FOREACH moid DATASEC_LIST$
$           # hrp2.elf����.data���������Τߤ򥳥ԡ�
            sh-elf-objcopy --only-section=.$MO.SLABEL[moid]$ $PRE_OBJ$ $MO.SLABEL[moid]$.$PRE_OBJ$$NL$
$           # hrp2.elf��.data����������.idata���������˥�͡���
            sh-elf-objcopy --rename-section .$MO.SLABEL[moid]$=.$MO.ILABEL[moid]$ $PRE_OBJ$$NL$
$           # hrp2.data�Υ���ܥ��ե��������¸
            sh-elf-nm $MO.SLABEL[moid]$.$PRE_OBJ$ | sed "s/^[^ ]* [^ ]* //g" > $MO.SLABEL[moid]$.$PRE_OBJ$.syms$NL$
$           # hrp2.elf���顢hrp2.elf��hrp2.data�Ǿ��ͤ��륷��ܥ����
            sh-elf-objcopy --strip-symbols=$MO.SLABEL[moid]$.$PRE_OBJ$.syms $PRE_OBJ$$NL$

            $CRE_FILE_LIST = APPEND(FORMAT("%s.%s", MO.SLABEL[moid], PRE_OBJ), CRE_FILE_LIST)$
            $CRE_FILE_LIST = APPEND(FORMAT("%s.%s.syms", MO.SLABEL[moid], PRE_OBJ), CRE_FILE_LIST)$
        $END$$NL$
    $END$
$END$

$  hrp2.elf��hrp2.data���� 
sh-elf-gcc -nostdlib -mb -T $FINAL_LDSCRIPT$ -o $FINAL_OBJ$ $PRE_OBJ$
$IF !OMIT_IDATA$
    $IF LENGTH(DATASEC_LIST)$
        $FOREACH moid DATASEC_LIST$
            $SPC$$MO.SLABEL[moid]$.$PRE_OBJ$
        $END$
    $END$
$END$
$SPC$-lgcc$NL$

$IF !OMIT_IDATA$
    $IF LENGTH(DATASEC_LIST)$
        $FOREACH moid DATASEC_LIST$
$           # .data����������LOAD°������
            sh-elf-objcopy --set-section-flags .$MO.SLABEL[moid]$="alloc,noload" $FINAL_OBJ$$NL$
        $END$$NL$
    $END$
$END$

$  �����륷��ܥ����
sh-elf-nm $FINAL_OBJ$ > $FINAL_OBJ$.syms$NL$
ruby rename.rb $FINAL_OBJ$.syms > $FINAL_OBJ$.localsyms$NL$
sh-elf-objcopy --strip-symbols=$FINAL_OBJ$.localsyms $FINAL_OBJ$$NL$
$NL$

$  ��֥ե��������
$FOREACH file CRE_FILE_LIST$
    rm -f $file$$NL$
$END$

$INCLUDE "ldscript3.tf"$

