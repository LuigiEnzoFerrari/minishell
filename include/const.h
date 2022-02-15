#ifndef CONST_H
# define CONST_H

// Reset
#define COLOR_OFF "\001\033[0m\002"       // Text Reset

// Regular Colors
#define BLACK "\001\003[0;30m\002"        // Black
#define RED "\001\003[0;31m\002"          // Red
#define GREEN "\001\033[1;32m\002"        // Green
#define YELLOW "\001\033[0;33m\002"       // Yellow
#define BLUE "\001\003[0;34m\002"         // Blue
#define PURPLE "\001\003[0;35m\002"       // Purple
#define CYAN "\001\003[0;36m\002"         // Cyan
#define WHITE "\001\003[0;37m\002"        // White

// Bold
#define BBLACK "\001\003[1;30m\002"       // Black
#define BRED "\001\003[1;31m\002"         // Red
#define BGREEN "\001\003[1;32m\002"       // Green
#define BYELLOW "\001\003[1;33m\002"      // Yellow
#define BBLUE "\001\003[1;34m\002"        // Blue
#define BPURPLE "\001\003[1;35m\002"      // Purple
#define BCYAN "\001\003[1;36m\002"        // Cyan
#define BWHITE "\001\003[1;37m\002"       // White

// Underline
#define UBLACK "\001\003[4;30m\002"       // Black
#define URED "\001\003[4;31m\002"         // Red
#define UGREEN "\001\003[4;32m\002"       // Green
#define UYELLOW "\001\003[4;33m\002"      // Yellow
#define UBLUE "\001\003[4;34m\002"        // Blue
#define UPURPLE "\001\003[4;35m\002"      // Purple
#define UCYAN "\001\003[4;36m\002"        // Cyan
#define UWHITE "\001\003[4;37m\002"       // White

// Background
#define ON_BLACK "\001\003[40m\002"       // Black
#define ON_RED "\001\003[41m\002"         // Red
#define ON_GREEN "\001\003[42m\002"       // Green
#define ON_YELLOW "\001\003[43m\002"      // Yellow
#define ON_BLUE "\001\003[44m\002"        // Blue
#define ON_PURPLE "\001\003[45m\002"      // Purple
#define ON_CYAN "\001\003[46m\002"        // Cyan
#define ON_WHITE "\001\003[47m\002"       // White

// High Intensty
#define IBLACK "\001\003[0;90m\002"       // Black
#define IRED "\001\003[0;91m\002"         // Red
#define IGREEN "\001\033[0;92m\002"       // Green
#define IYELLOW "\001\003[0;93m\002"      // Yellow
#define IBLUE "\001\003[0;94m\002"        // Blue
#define IPURPLE "\001\003[0;95m\002"      // Purple
#define ICYAN "\001\003[0;96m\002"        // Cyan
#define IWHITE "\001\003[0;97m\002"       // White

// Bold High Intensty
#define BIBLACK "\001\003[1;90m\002"      // Black
#define BIRED "\001\003[1;91m\002"        // Red
#define BIGREEN "\001\003[1;92m\002"      // Green
#define BIYELLOW "\001\003[1;93m\002"     // Yellow
#define BIBLUE "\001\003[1;94m\002"       // Blue
#define BIPURPLE "\001\003[1;95m\002"     // Purple
#define BICYAN "\001\003[1;96m\002"       // Cyan
#define BIWHITE "\001\003[1;97m\002"      // White

// High Intensty backgrounds
#define On_IBlack "\001\003[0;100m\002"   // Black
#define On_IRed "\001\003[0;101m\002"     // Red
#define On_IGreen "\001\003[0;102m\002"   // Green
#define On_IYellow "\001\003[0;103m\002"  // Yellow
#define On_IBlue "\001\003[0;104m\002"    // Blue
#define On_IPurple "\001\003[10;95m\002"  // Purple
#define On_ICyan "\001\003[0;106m\002"    // Cyan
#define On_IWhite "\001\003[0;107m\002"   // White

#endif