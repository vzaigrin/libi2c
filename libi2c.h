#ifndef __LIBI2C_H__
#define __LIBI2C_H__

#include <unistd.h>

char i2c_read ( int fd, uint16_t slave, uint8_t offset, uint8_t *buf );
char i2c_write ( int fd, uint16_t slave, uint8_t offset, uint8_t val );

#endif  /* __LIBI2C_H__ */
