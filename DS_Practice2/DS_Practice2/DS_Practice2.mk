##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DS_Practice2
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\R\Documents\LabDS\Practice 2\dsAssignment2\DS_Practice2"
ProjectPath            := "C:\Users\R\Documents\LabDS\Practice 2\dsAssignment2\DS_Practice2\DS_Practice2"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=R
Date                   :=29/11/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="DS_Practice2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/DList.cpp$(ObjectSuffix) $(IntermediateDirectory)/celltype.cpp$(ObjectSuffix) $(IntermediateDirectory)/DCList.cpp$(ObjectSuffix) $(IntermediateDirectory)/IOHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainHandler.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 2/dsAssignment2/DS_Practice2/DS_Practice2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/DList.cpp$(ObjectSuffix): DList.cpp $(IntermediateDirectory)/DList.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 2/dsAssignment2/DS_Practice2/DS_Practice2/DList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DList.cpp$(DependSuffix): DList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DList.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DList.cpp$(DependSuffix) -MM "DList.cpp"

$(IntermediateDirectory)/DList.cpp$(PreprocessSuffix): DList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DList.cpp$(PreprocessSuffix) "DList.cpp"

$(IntermediateDirectory)/celltype.cpp$(ObjectSuffix): celltype.cpp $(IntermediateDirectory)/celltype.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 2/dsAssignment2/DS_Practice2/DS_Practice2/celltype.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/celltype.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/celltype.cpp$(DependSuffix): celltype.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/celltype.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/celltype.cpp$(DependSuffix) -MM "celltype.cpp"

$(IntermediateDirectory)/celltype.cpp$(PreprocessSuffix): celltype.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/celltype.cpp$(PreprocessSuffix) "celltype.cpp"

$(IntermediateDirectory)/DCList.cpp$(ObjectSuffix): DCList.cpp $(IntermediateDirectory)/DCList.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 2/dsAssignment2/DS_Practice2/DS_Practice2/DCList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DCList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DCList.cpp$(DependSuffix): DCList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DCList.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DCList.cpp$(DependSuffix) -MM "DCList.cpp"

$(IntermediateDirectory)/DCList.cpp$(PreprocessSuffix): DCList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DCList.cpp$(PreprocessSuffix) "DCList.cpp"

$(IntermediateDirectory)/IOHandler.cpp$(ObjectSuffix): IOHandler.cpp $(IntermediateDirectory)/IOHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 2/dsAssignment2/DS_Practice2/DS_Practice2/IOHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IOHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IOHandler.cpp$(DependSuffix): IOHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IOHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IOHandler.cpp$(DependSuffix) -MM "IOHandler.cpp"

$(IntermediateDirectory)/IOHandler.cpp$(PreprocessSuffix): IOHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IOHandler.cpp$(PreprocessSuffix) "IOHandler.cpp"

$(IntermediateDirectory)/MainHandler.cpp$(ObjectSuffix): MainHandler.cpp $(IntermediateDirectory)/MainHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 2/dsAssignment2/DS_Practice2/DS_Practice2/MainHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainHandler.cpp$(DependSuffix): MainHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainHandler.cpp$(DependSuffix) -MM "MainHandler.cpp"

$(IntermediateDirectory)/MainHandler.cpp$(PreprocessSuffix): MainHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainHandler.cpp$(PreprocessSuffix) "MainHandler.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


