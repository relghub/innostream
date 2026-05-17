# --- Konfiguracja Kompilatora ---
CXX = g++
# -MMD -MP to flagi generujące pliki .d (zależności od nagłówków)
CXXFLAGS = -Wall -Wextra -std=c++17 -g -MMD -MP
TARGET = program

# --- Automatyczne wyszukiwanie plików ---
# Znajdź wszystkie pliki .cpp oraz .cc w obecnym katalogu
SRCS = $(wildcard *.cpp *.cc)

# Zmień rozszerzenia w liście: cokolwiek to było (.cpp czy .cc), zrób z tego .o
OBJS = $(addsuffix .o,$(basename $(SRCS)))

# Lista plików zależności (końcówka .d zamiast .o)
DEPS = $(OBJS:.o=.d)

# --- Główne Reguły ---

# Domyślny cel kompilacji
all: $(TARGET)

# Sklejanie wszystkiego w plik wykonywalny
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "✨ Kompilacja zakończona: ./${TARGET}"

# Reguła dla plików .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reguła dla plików .cc (jeśli wolisz to rozszerzenie)
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Narzędzia ---

# Sprzątanie folderu ze śmieci po kompilacji
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

# Wczytaj wygenerowane pliki zależności (jeśli istnieją).
# Znak '-' na początku ignoruje błędy, jeśli plików jeszcze nie ma (np. przed pierwszą kompilacją).
-include $(DEPS)

# Deklaracja komend (nie są to pliki na dysku)
.PHONY: all clean
