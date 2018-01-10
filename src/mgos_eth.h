/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_MOS_LIBS_ETHERNET_SRC_MGOS_ETH_H_
#define CS_MOS_LIBS_ETHERNET_SRC_MGOS_ETH_H_

#include <stdbool.h>
#include <stdint.h>

#include "lwip/ip_addr.h"

#ifdef __cplusplus
extern "C" {
#endif

enum mgos_eth_speed {
  MGOS_ETH_SPEED_AUTO = 0,
  MGOS_ETH_SPEED_10M,
  MGOS_ETH_SPEED_100M,
};

enum mgos_eth_duplex {
  MGOS_ETH_DUPLEX_AUTO = 0,
  MGOS_ETH_DUPLEX_HALF,
  MGOS_ETH_DUPLEX_FULL,
};

struct mgos_eth_phy_opts {
  enum mgos_eth_speed speed;
  enum mgos_eth_duplex duplex;
  bool autoneg_on;
};

struct mgos_eth_opts {
  int phy_addr;
  struct mgos_eth_phy_opts phy_opts;
  uint8_t mac[6];
  int mtu;
};

const char *mgos_eth_speed_str(enum mgos_eth_speed speed);
const char *mgos_eth_duplex_str(enum mgos_eth_duplex duplex);
bool mgos_eth_phy_opts_from_str(const char *str,
                                struct mgos_eth_phy_opts *opts);
bool mgos_eth_get_static_ip_config(ip4_addr_t *ip, ip4_addr_t *netmask,
                                   ip4_addr_t *gw);

#ifdef __cplusplus
}
#endif
#endif /* CS_MOS_LIBS_ETHERNET_SRC_MGOS_ETH_H_ */
