from smbus import SMBus

addr = 0x8
bus = SMBus(1)

def sendOpenSignal():
    print("Telling arduino to open the door")
    bus.write_byte(addr, 0x1)

def sendCloseSignal():
    print("Telling arduino to close the door")
    bus.write_byte(addr, 0x0)

# sendOpenSignal()
