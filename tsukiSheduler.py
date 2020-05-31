import schedule
import time
import datetime
from smbus import SMBus

addr = 0x8
bus = SMBus(1)

def sendOpenSignal():
    print("Telling arduino to open the door")
    bus.write_byte(addr, 0x1)

def sendCloseSignal():
    bus.write_byte(addr, 0x0)

def logTime():
    print(datetime.datetime.now())

schedule.every().day.at("12:00").do(sendOpenSignal)
schedule.every().day.at("18:00").do(sendOpenSignal)
schedule.every().day.at("00:00").do(sendOpenSignal)
schedule.every().day.at("06:00").do(sendOpenSignal)
schedule.every().minute.at(":00").do(logTime)


while True:
    schedule.run_pending()
    time.sleep(1)
