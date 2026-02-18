# ====== CONFIG ======
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wno-unused -Wno-maybe-uninitialized -Werror -Wno-unused-but-set-variable -Isrc -g -O0
BUILD := build
# do we realllyyyyy need to please windows users
# TARGET := build/text_rpg.exe
TARGET := build/text_rpg


# ====== FILES ======
# Explicitly list each .cpp file (guaranteed to work)
SRCS := \
    src/main.cpp \
    src/Terminal.cpp \
    src/game/Game.cpp \
    src/character/Character.cpp \
    src/combat/Combat.cpp \
    src/combat/Action.cpp \
    src/menu/Menu.cpp \
    src/menu/MenuManager.cpp \
    src/party/Party.cpp \
    src/skills/Skill.cpp \
    src/skills/SkillList.cpp \
    src/character_classes/Warrior.cpp \
    src/character_classes/Mage.cpp \
    src/character_classes/Healer.cpp \
    src/character_classes/Archer.cpp \
    src/character_classes/Boss.cpp \
	src/Random.cpp

OBJS := $(SRCS:%.cpp=$(BUILD)/%.o)

# ====== TARGETS ======
.PHONY: all run clean rebuild

all: $(TARGET)

$(BUILD)/%.o: %.cpp
	@echo [CXX ] $<
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@echo [LINK] $@
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

run: $(TARGET)
	$(TARGET)

clean:
	@echo [CLEAN]
	rm -rf $(BUILD)/src
	rm -f $(TARGET)

rebuild: clean all
