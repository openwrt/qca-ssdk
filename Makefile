obj ?= $(shell pwd)

obj-m += qca-ssdk.o

qca-ssdk-objs += src/adpt/adpt.o \
                            src/adpt/hppe/adpt_hppe_acl.o \
                            src/adpt/hppe/adpt_hppe_bm.o \
                            src/adpt/hppe/adpt_hppe_ctrlpkt.o \
                            src/adpt/hppe/adpt_hppe_fdb.o \
                            src/adpt/hppe/adpt_hppe_flow.o \
                            src/adpt/hppe/adpt_hppe_ip.o \
                            src/adpt/hppe/adpt_hppe_mib.o \
                            src/adpt/hppe/adpt_hppe_mirror.o \
                            src/adpt/hppe/adpt_hppe_misc.o \
                            src/adpt/hppe/adpt_hppe_policer.o \
                            src/adpt/hppe/adpt_hppe_portvlan.o \
                            src/adpt/hppe/adpt_hppe_pppoe.o \
                            src/adpt/hppe/adpt_hppe_qm.o \
                            src/adpt/hppe/adpt_hppe_qos.o \
                            src/adpt/hppe/adpt_hppe_rss_hash.o \
                            src/adpt/hppe/adpt_hppe_sec.o \
                            src/adpt/hppe/adpt_hppe_servcode.o \
                            src/adpt/hppe/adpt_hppe_shaper.o \
                            src/adpt/hppe/adpt_hppe_stp.o \
                            src/adpt/hppe/adpt_hppe_trunk.o \
                            src/adpt/hppe/adpt_hppe_vsi.o \
                            src/api/api_access.o \
                            src/fal/fal_acl.o \
                            src/fal/fal_bm.o \
                            src/fal/fal_ctrlpkt.o \
                            src/fal/fal_cosmap.o \
                            src/fal/fal_fdb.o \
                            src/fal/fal_flow.o \
                            src/fal/fal_igmp.o \
                            src/fal/fal_init.o \
                            src/fal/fal_ip.o \
                            src/fal/fal_leaky.o \
                            src/fal/fal_led.o \
                            src/fal/fal_mib.o \
                            src/fal/fal_mirror.o \
                            src/fal/fal_misc.o \
                            src/fal/fal_nat.o \
                            src/fal/fal_policer.o \
                            src/fal/fal_portvlan.o \
                            src/fal/fal_pppoe.o \
                            src/fal/fal_qm.o \
                            src/fal/fal_qos.o \
                            src/fal/fal_rate.o \
                            src/fal/fal_reg_access.o \
                            src/fal/fal_rss_hash.o \
			    src/fal/fal_sec.o \
                            src/fal/fal_servcode.o \
                            src/fal/fal_shaper.o \
                            src/fal/fal_stp.o \
                            src/fal/fal_trunk.o \
                            src/fal/fal_vlan.o \
                            src/fal/fal_vsi.o \
                            src/hsl/phy/f1_phy.o \
                            src/hsl/phy/f2_phy.o \
                            src/hsl/phy/hsl_phy.o \
                            src/hsl/phy/malibu_phy.o \
                            src/hsl/phy/aquantia_phy.o \
                            src/hsl/hsl_acl.o \
                            src/hsl/hsl_api.o \
                            src/hsl/hsl_dev.o \
                            src/hsl/hsl_lock.o \
                            src/hsl/hsl_port_prop.o \
                            src/hsl/hppe/hppe_acl.o \
                            src/hsl/hppe/hppe_bm.o \
                            src/hsl/hppe/hppe_ctrlpkt.o \
                            src/hsl/hppe/hppe_fdb.o \
                            src/hsl/hppe/hppe_flow.o \
                            src/hsl/hppe/hppe_global.o \
                            src/hsl/hppe/hppe_init.o \
                            src/hsl/hppe/hppe_ip.o \
                            src/hsl/hppe/hppe_mib.o \
                            src/hsl/hppe/hppe_mirror.o \
                            src/hsl/hppe/hppe_policer.o \
                            src/hsl/hppe/hppe_portctrl.o \
                            src/hsl/hppe/hppe_portvlan.o \
                            src/hsl/hppe/hppe_pppoe.o \
                            src/hsl/hppe/hppe_qm.o \
                            src/hsl/hppe/hppe_qos.o \
                            src/hsl/hppe/hppe_reg_access.o \
			    src/hsl/hppe/hppe_rss.o \
                            src/hsl/hppe/hppe_sec.o \
                            src/hsl/hppe/hppe_servcode.o \
                            src/hsl/hppe/hppe_shaper.o \
                            src/hsl/hppe/hppe_stp.o \
                            src/hsl/hppe/hppe_trunk.o \
                            src/hsl/hppe/hppe_uniphy.o \
                            src/hsl/hppe/hppe_vsi.o \
                            src/hsl/hppe/hppe_xgmacmib.o \
                            src/hsl/hppe/hppe_xgportctrl.o \
                            src/init/ssdk_init.o \
                            src/init/ssdk_plat.o \
                            src/ref/ref_vsi.o \
                            src/sal/sd/sd.o \
                            src/sal/sd/linux/uk_interface/sw_api_ks_ioctl.o \
                            src/shell_lib/shell.o \
                            src/shell_lib/shell_config.o \
                            src/shell_lib/shell_io.o \
                            src/shell_lib/shell_sw.o \
                            src/util/util.o

ccflags-y += -I$(obj)/include -I$(obj)/include/common -I$(obj)/include/api -I$(obj)/include/fal -I$(obj)/include/ref -I$(obj)/include/adpt -I$(obj)/include/hsl -I$(obj)/include/hsl/phy -I$(obj)/include/sal/os -I$(obj)/include/sal/os/linux  -I$(obj)/include/sal/sd -I$(obj)/include/sal/sd/linux/hydra_howl -I$(obj)/include/sal/sd/linux/uk_interface -I$(obj)/include/init -I$(obj)/include/hsl/appe -I$(obj)/include/hsl/hppe -I$(obj)/include/adpt/hppe -I$(obj)/include/hsl/athena -I$(obj)/include/adpt -I$(obj)/include/api -I$(obj)/include/common -I$(obj)/include/fal -I$(obj)/include/hsl/dess -I$(obj)/include/hsl/garuda -I$(obj)/include/hsl/horus -I$(obj)/include/hsl/isis -I$(obj)/include/hsl/isisc -I$(obj)/include/hsl/isisc -I$(obj)/include/hsl/phy -I$(obj)/include/hsl/shiva  -I$(obj)/include/init -I$(obj)/include/ref -I$(obj)/include/common -I$(obj)/include/shell_lib

ccflags-y += -DKVER26 -DIN_ACL -DIN_FDB -DIN_TUNNEL_PARSER -DIN_TUNNEL -DIN_PRE_IPO -DIN_IGMP -DIN_LEAKY -DIN_LED -DIN_MIB -DIN_MIRROR -DIN_MISC   -DIN_PORTVLAN -DIN_QOS -DIN_RATE -DIN_STP  -DIN_COSMAP -DIN_IP -DIN_NAT -DIN_FLOW -DIN_TRUNK -DIN_SEC -DIN_QM  -DIN_CTRLPKT -DIN_SERVCODE -DIN_RSS_HASH -DIN_MALIBU_PHY -DIN_AQUANTIA_PHY -DIN_VSI -DIN_PPPOE -DIN_BM -DIN_SHAPER -DIN_POLICER -DHAWKEYE_CHIP -DUK_IF -DUK_NL_PROT= -DUK_MINOR_DEV=254

ccflags-y +=  -DHPPE -DKERNEL_MODULE -DKVER32 -DRUMI_EMULATION
