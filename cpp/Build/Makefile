# [COMMANDS]: 
CC = g++
LD = ld
PRINT = @echo

# [FLAGS]:
CFLAGS = -Wall `Magick++-config --cxxflags --cppflags`
LFLAGS = -r 
MAGKPP = `Magick++-config --ldflags --libs`

# [STYLE]:
NC = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
GREY = \033[0;37m

# [OUTPUT:]
** = $(GREY)[**]$(NC)
VV = $(YELLOW)[VV]$(NC)
<< = $(GREEN)[<<]$(NC)
>> = $(BLUE)[>>]$(NC)
!! = $(RED)[!!]$(NC)


#
# [BUILD:]
#

TARGET = Main

#
# Driver [START]
all: $(TARGET)
	$(PRINT) "$(VV)  $(YELLOW)Binary file built correctly$(NC)"
	$(PRINT) "$(>>)  $(BLUE)Creating executable...$(NC)"
	@chmod +x $(TARGET)
	$(PRINT) "$(VV)  $(YELLOW)Installation completed correctly!$(NC)"
	$(PRINT) "$(GREY)Bye...$(NC)"

$(TARGET): driver.o
	$(PRINT) "$(<<)  Unioning objects file..."
	$(PRINT) "$(>>)  $(BLUE)Creating driver executable...$(NC)"
	@$(CC) $(CFLAGS) -o $(TARGET) driver.o $(MAGKPP) 
	$(PRINT) "$(!!)  $(RED)Deleting objects file...$(RED)"
	@rm -f *.o

driver.o: ../Main.cpp image_to_ascii.o
	$(PRINT) "$(**)  $(GREY)Compiling driver_partial.o...$(NC)"
	@$(CC) $(CFLAGS) -c -o driver_partial.o ../Main.cpp $(MAGKPP) 
	$(PRINT) "$(<<)  Unifing driver.o..."
	@$(LD) $(LFLAGS) -o driver.o image_to_ascii.o driver_partial.o

#
# Image_to_ascii [START]
image_to_ascii.o: ../src/Image_to_ascii.h ../src/Image_to_ascii.cpp converter.o except.o 
	$(PRINT) "$(**)  $(GREY)Compiling image_to_ascii_partial.o...$(NC)"
	@$(CC) $(CFLAGS) -c -o image_to_ascii_partial.o ../src/Image_to_ascii.cpp $(MAGKPP)
	$(PRINT) "$(<<)  Unifing image_to_ascii.o..."
	@$(LD) $(LFLAGS) -o image_to_ascii.o except.o converter.o image_to_ascii_partial.o

#
# Converter [START]
converter.o: ../src/Converter/Converter.h ../src/Converter/Converter.cpp utils.o
	$(PRINT) "$(**)  $(GREY)Compiling converter_partial.o...$(NC)"
	@$(CC) $(CFLAGS) -c -o converter_partial.o ../src/Converter/Converter.cpp $(MAGKPP)
	$(PRINT) "$(<<)  Unifing converter.o..."
	@$(LD) $(LFLAGS) -o converter.o utils.o converter_partial.o

#
# Utils [START]
utils.o: ../src/Converter/Utils/Utils.h ../src/Converter/Utils/Utils.cpp
	$(PRINT) "$(**)  $(GREY)Compiling utils.o...$(NC)"
	@$(CC) $(CFLAGS) -c -o utils.o ../src/Converter/Utils/Utils.cpp $(MAGKPP)
# Utils [END]
#

# Converter [END]
#

#
# Except [START]
except.o: ../src/Exceptions/Except.h ../src/Exceptions/Except.cpp
	$(PRINT) "$(**)  $(GREY)Compiling except.o...$(NC)"
	@$(CC) $(CFLAGS) -c -o except.o ../src/Exceptions/Except.cpp $(MAGKPP)
# Except [END]
#

# Image_to_ascii [END]
#

# Driver [END]
#