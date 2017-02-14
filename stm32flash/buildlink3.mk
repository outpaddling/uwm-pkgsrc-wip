# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.stm32flash?=	build

BUILDLINK_TREE+=	stm32flash

.if !defined(STM32FLASH_BUILDLINK3_MK)
STM32FLASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.stm32flash+=	stm32flash>=2011.05.30
BUILDLINK_PKGSRCDIR.stm32flash?=	../../uwm-pkgsrc-wip/stm32flash
.endif	# STM32FLASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-stm32flash
