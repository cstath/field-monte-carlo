# #####################   Makefile   ####################### 

# Declaration of variables
SRCDIR = ./source
INCLDIR = ./include
OUTDIR = ./bin
$(shell mkdir -p $(OUTDIR) >/dev/null)
DEPDIR = $(OUTDIR)/deps
$(shell mkdir -p $(DEPDIR) >/dev/null)
DOCDIR = ./documentation

CC = gcc
CC_FLAGS = -std=c99 -ggdb3 -Wall -Wextra -pedantic
LIBS   = -lm 

# File names
PROGRAM = metropolis
SRCFILES := $(shell ls $(SRCDIR))
TMPFILES = $(SRCFILES:.c=.o)
OBJFILES = $(addprefix $(OUTDIR)/, $(TMPFILES))
TMPDEPFILES = $(SRCFILES:.c=.d)
DEPFILES = $(addprefix $(DEPDIR)/, $(TMPDEPFILES))

# Main target
$(OUTDIR)/$(PROGRAM): $(OBJFILES)
	$(CC) $(OBJFILES) -o $@ $(LIBS)

# pull in dependency info for *existing* .o files
-include $(DEPFILES)

# To obtain object files
$(OUTDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CC_FLAGS) -I$(INCLDIR) $< -o $@ $(LIBS)
	$(CC) -MM $(CC_FLAGS) -I$(INCLDIR) $< $(LIBS) > $(DEPDIR)/$*.d
	@mv -f $(DEPDIR)/$*.d $(DEPDIR)/$*.d.tmp
	@sed -e 's|.*:|$(OUTDIR)/$*.o:|' < $(DEPDIR)/$*.d.tmp > $(DEPDIR)/$*.d
	@sed -e 's/.*://' -e 's/\\//' < $(DEPDIR)/$*.d.tmp | tr --delete '\n' |\
	  fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(DEPDIR)/$*.d
	@rm -f $(DEPDIR)/$*.d.tmp

# To create the doxygen documentation
doc:
	doxygen Doxyfile

# To remove generated files
clean:
	rm -f $(OUTDIR)/$(PROGRAM) $(OBJFILES) $(DEPFILES) 
	rm -rf $(DOCDIR)