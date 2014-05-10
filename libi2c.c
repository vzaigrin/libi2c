#include <stdio.h>
#include <unistd.h>
#include <dev/iicbus/iic.h>

char i2c_read ( int fd, uint16_t slave, uint8_t offset, uint8_t *buf )  {

  struct iic_msg msg[2];
  struct iic_rdwr_data rdwr;

  msg[0].slave = slave;
  msg[0].flags = !IIC_M_RD;
  msg[0].len = sizeof( offset );
  msg[0].buf = &offset;

  msg[1].slave = slave;
  msg[1].flags = IIC_M_RD;
  msg[1].len = sizeof( buf );
  msg[1].buf = buf;

  rdwr.msgs = msg;
  rdwr.nmsgs = 2;

  if ( ioctl(fd, I2CRDWR, &rdwr) < 0 )  {
    perror("I2CRDWR");
    return(-1);
  }
  
  return(0);
}


char i2c_write ( int fd, uint16_t slave, uint8_t offset, uint8_t val )  {

  uint8_t buf[2];
  struct iic_msg msg;
  struct iic_rdwr_data rdwr;

  buf[0] = offset;
  buf[1] = val;
  msg.slave = slave;
  msg.flags = 0;
  msg.len = sizeof( buf );
  msg.buf = buf;

  rdwr.msgs = &msg;
  rdwr.nmsgs = 1;

  if ( ioctl(fd, I2CRDWR, &rdwr) < 0 )  {
    perror("I2CRDWR");
    return(-1);
  }
  
  return(0);
}
