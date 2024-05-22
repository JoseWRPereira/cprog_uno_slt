PROJECT=cprog_uno_slt
DEVICE=ATmega328PB
CC_PATH="C:\Program Files\Microchip\xc8\v2.45\bin"
CC="$(CC_PATH)\xc8-cc.exe"
OBJCP="$(CC_PATH)\avr-objcopy"
BUILD=build/default/production
DIST=dist/default/production



SRCS=$(wildcard *.c)
BUILDS=$(SRCS:%.c=$(BUILD)/%.o)



all: build $(BUILDS)
	$(CC)  	-mcpu=$(DEVICE) \
			-Wl,-Map=$(DIST)/$(PROJECT).X.production.map  \
			-DXPRJ_default=default  \
			-Wl,--defsym=__MPLAB_BUILD=1 \
			-Wl,--gc-sections -O1 \
			-ffunction-sections \
			-fdata-sections \
			-fshort-enums \
			-fno-common \
			-funsigned-char \
			-funsigned-bitfields \
			-Wall \
			-gdwarf-3 \
			-mno-const-data-in-progmem      \
			-Wl,--memorysummary,$(DIST)/memoryfile.xml \
			-o $(DIST)/$(PROJECT).X.production.elf  \
			-o $(DIST)/$(PROJECT).X.production.elf  \
			$(BUILDS) \
			-Wl,--start-group  \
			-Wl,-lm -Wl,--end-group
	$(OBJCP) -O ihex "$(DIST)/$(PROJECT).X.production.elf" \
			"$(DIST)/$(PROJECT).X.production.hex"



$(BUILD)/%.o: %.c
	$(CC)  	-mcpu=$(DEVICE) \
            -c  -x c -D__$(DEVICE)__ \
            -Wl,--gc-sections -O1 \
            -ffunction-sections \
            -fdata-sections \
            -fshort-enums \
            -fno-common \
            -funsigned-char \
            -funsigned-bitfields \
            -Wall -DXPRJ_default=default \
            -gdwarf-3 \
            -mno-const-data-in-progmem \
            -MD -MP -MF "$@.d" \
            -MT "$@.d" \
            -MT $@ \
            -o $@ \
            $<



build:
	mkdir "$(BUILD)"
	mkdir "$(DIST)"
