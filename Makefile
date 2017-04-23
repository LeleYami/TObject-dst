CFLAGS=$(shell root-config --cflags) -IRootEventData/
LDFLAGS=-L /home/luole/root/lib -fpermissive -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic -L /home/luole/root/luole/dst -lthis2

all:libSclass.so read_write

read_write:read_write.o
	g++ -L. -o $@ $^ $(LDFLAGS)
hclient:hclient.o
	g++ -L. -o $@ $^ $(LDFLAGS)

hserv:hserv.o
	g++ -fpermissive -L. -o $@ $^ $(LDFLAGS)

interface:interface.o
	g++ -L. -o $@ $^ $(LDFLAGS)

libSclass.so:Sclass.o SclassDict.o
	g++ -shared -o $@ $^ $(LDFLAGS)

Sclass.cpp:Sclass.h

SclassDict.cpp:Sclass.h LinkDef.h
	rootcint -f $@ -c $^

%.o:%.cpp
	g++ -fpermissive -c -fPIC -o $@ $^ $(CFLAGS)

####################################
#run the command
####################################
run_read_write:read_write
       @LD_LIBRARY_PATH=.:$(LD_LIBRARY_PATH) ./read_write 
