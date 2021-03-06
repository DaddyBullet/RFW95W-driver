#ifndef RFM95W_DRIVER_H
#define RFM95W_DRIVER_H

#include "RFM95W_LORA_defines.h"
#include "RFM95W_driver_SPI_handler.h"

uint8_t RFM95WLORAReadVersion();

uint8_t RFM95WLORASetIrqFlagsMask(uint8_t mask);
uint8_t RFM95WLORAReadIrqFlagsMask();

uint8_t RFM95WLORAReadIrqFlags();
uint8_t RFM95WLORAClearIrqFlags(uint8_t mask);

uint8_t RFM95WLORAReadIrqFlag(RFM95W_LORA_IRQ_FLAG flag);
uint8_t RFM95WLORAClearIrqFlag(RFM95W_LORA_IRQ_FLAG flag);

uint8_t RFM95WLORASetDIO(RFM95W_LORA_DIO_TYPE dio, uint8_t func);

RFM95W_LORA_MODE RFM95WLORAReadMode();

uint8_t RFM95WLORASetMode(RFM95W_LORA_MODE mode);
uint8_t RFM95WLORASetLoraFsk(uint8_t global_mode);
uint8_t RFM95WLORASetFreqMode(uint8_t freq_mode);

uint8_t RFM95WLORASetFreq(uint32_t freq, uint32_t xosc_freq);
uint8_t RFM95WLORASetFreq868();
// This will put modem in LORA mode
uint8_t RFM95WLORAInitRegOpMode(uint8_t access_share_reg, uint8_t low_freq_mode_on, RFM95W_LORA_MODE mode);

uint8_t RFM95WLORASetPaConfig(uint8_t pa_select, uint8_t max_power, uint8_t output_power);
uint8_t RFM95WLORASetPaSelect(uint8_t pa_select);
// Pmax = 10.8 + (0.6 * max_power) [dBm]
uint8_t RFM95WLORASetPaMaxPower(uint8_t max_power);
// Pout = Pmax - (15 - output_power) if pa_select == 0
// Pout = 17  -  (15 - output_power) if pa_select == 1
uint8_t RFM95WLORASetPaOutputPower(uint8_t output_power);

uint8_t RFM95WLORASetOcpConfig(uint8_t osp_on, uint8_t ocp_trim);
uint8_t RFM95WLORASetOcpOn(uint8_t osp_on);
// Imax = 45 + (5 * osp_trim) [mA] if osp_trim <= 15
// Imax = -30 + (10 * osp_trim) [mA] if 15 < osp_trim <= 27
// Imax = 100[mA] if osp_trim > 27
uint8_t RFM95WLORASetOcpTrim(uint8_t osp_trim);

uint8_t RFM95WLORASetLnaConfig(uint8_t lna_gain, uint8_t lna_boost_lf, uint8_t lna_boost_hf);
uint8_t RFM95WLORASetLnaGain(uint8_t lna_gain);
uint8_t RFM95WLORASetLnaBoostLf(uint8_t lna_boost_lf);
// lna_boost_hf 00 -> Default LNA current
// lna_boost_hf 11 -> Boost on, 150% LNA current
uint8_t RFM95WLORASetLnaBoostHf(uint8_t lna_boost_hf);

uint8_t RFM95WLORASetModemConfig(RFM95W_LORA_BANDWIDTH bw, RFM95W_LORA_CR cr, RFM95W_LORA_SF sf, \
                              RFM95W_LORA_HEADER_MODE hm, \
                              RFM95W_LORA_TX_MODE tx_mode, \
                              RFM95W_LORA_RX_PAYLOAD_CRC rx_crc);

uint8_t RFM95WLORASetModemConfigFull(RFM95W_LORA_BANDWIDTH bw, RFM95W_LORA_CR cr, RFM95W_LORA_SF sf, \
                              RFM95W_LORA_HEADER_MODE hm, \
                              RFM95W_LORA_TX_MODE tx_mode, \
                              RFM95W_LORA_RX_PAYLOAD_CRC rx_crc, \
                              RFM95W_LORA_NODE node, \
                              RFM95W_LORA_AGC_AUTO agc);

uint8_t RFM95WLORASetBandwidth(RFM95W_LORA_BANDWIDTH bw);
uint8_t RFM95WLORASetCodingRate(RFM95W_LORA_CR cr);
uint8_t RFM95WLORASetSpreadingFactor(RFM95W_LORA_SF sf);

uint8_t RFM95WLORASetHopPeriod(uint8_t hop_period);
uint8_t RFM95WLORAReadPresentChannel();

int16_t RFM95WLORAReadRssi();
int16_t RFM95WLORAReadPacketRssi();
int8_t RFM95WLORAReadPacketSnr();

// Timeout = symb_timeout * Ts
uint8_t RFM95WLORASetSymbTimeout(uint16_t symb_timeout);
uint8_t RFM95WLORASetPreambleLength(uint16_t pre_length);
uint8_t RFM95WLORASetPayloadLength(uint8_t payload_length);
uint8_t RFM95WLORAReadPayloadLength();
uint8_t RFM95WLORASetPayloadMaxLength(uint8_t payload_max_length);

uint8_t RFM95WLORASetFifoAddrPtr(uint8_t addr);
uint8_t RFM95WLORAReadFifoTxBase();
uint8_t RFM95WLORASetFifoTxBase(uint8_t tx_base_addr);
uint8_t RFM95WLORAReadFifoRxBase();
uint8_t RFM95WLORASetFifoRxBase(uint8_t rx_base_addr);
uint8_t RFM95WLORAReadFifoRxNb();
uint8_t RFM95WLORAReadFifoRxDataAddr();

uint8_t RFM95WLORAWritePacket(uint8_t *data, uint8_t length);
uint8_t RFM95WLORATransmitPacket(uint8_t *data, uint8_t length);

// ret val 0xFE = not enough space in buff
uint8_t RFM95WLORAReadPacket(uint8_t *data, uint8_t length);



#endif /* RFM95W_DRIVER_H */
