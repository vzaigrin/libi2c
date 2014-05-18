libi2c
======

A small library to read and write data over I2C bus in FreeBSD


Call i2c_read to read data from device on I2C bus

Call i2c_write to write data to device on I2C bus


int fd - a file descriptor of the open i2c device

uint16_t slave - address of the device on i2c bus

uint8_t offset - address of data on the device

uint8_t *buf - pointer to the variable where data read from the device will be placed

uint8_t val - data to be written to the device
