/* Copied from config.def.h */
/* See LICENSE file for copyright and license details. */

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int rmaster            = 0;        /* 1 means master-area is initially on the right */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=13:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=13:antialias=true:autohint=true";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#dddddd";
static const char col_gray4[]       = "#e0e0e0";
static const char col_cyan[]        = "#224455";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "󰆍", "", "󰎄", "", "󰖵" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ NULL,     NULL,       "FL Studio 21",     0,      True,           -1 },
	{ NULL,     NULL,       "Godot",        1 << 0,     False,           0 },
	{ NULL,     NULL,       "Slack",        1 << 5,     False,           1 },
//	{ NULL,       NULL,       NULL,       0,            False,       -1 },
};

/* layout(s) */
static const float mfact     = 0.52; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|||",      col },
//{ "###",      gaplessgrid },
};

/* key definitions */
#define MODKEY Mod4Mask // Windows key
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] =     { "dmenu_run", "-i", "-m", dmenumon, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  =     { "kitty", NULL };
static const char *pcmanfmcmd[] =   { "dbus-launch", "pcmanfm", NULL };
static const char *cmuscmd[] =      { "kitty", "cmus", NULL };
static const char *firefoxcmd[] =   { "firefox", NULL };
static const char *godotcmd[] =     { "steam-run", "godot4", NULL };
static const char *flameshotcmd[] = { "flameshot", "gui", NULL };
static const char *keepmenucmd[] =  { "kp", NULL };
static const char *slackcmd[] =     { "slack", NULL };
static const char *mailcmd[] =      { "kitty", "nvim", "+Himalaya", NULL };
static const char *suspendcmd[] =   { "systemctl", "suspend", NULL };
static const char *shutdowncmd[] =  { "shutdown", "now", NULL };

static const char *togglemutecmd[] =  { "mute", NULL };
static const char *volumeup[] =       { "volup", NULL };
static const char *volumedown[] =     { "voldn", NULL };
static const char *brightnessup[] =   { "adjustlight", "up", NULL };
static const char *brightnessdown[] = { "adjustlight", "down", NULL };

static const char *cmus_pause[] =   { "cmus-remote", "--pause", NULL };
static const char *cmus_play[] =    { "cmus-remote", "--play", NULL };
static const char *cmus_next[] =    { "cmus-remote", "--next", NULL };
static const char *cmus_prev[] =    { "cmus-remote", "--prev", NULL };
static const char *cmus_ff[] =      { "cmus-remote", "--seek", "+5", NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier             key        function        argument */
	{ MODKEY,               XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,               XK_c,      spawn,          {.v = termcmd } },
	{ MODKEY,               XK_f,      spawn,          {.v = pcmanfmcmd } },   // File Browser
	{ MODKEY,               XK_w,      spawn,          {.v = firefoxcmd } },   // Web browser
	{ MODKEY,               XK_g,      spawn,          {.v = godotcmd } },     // 3D Engine
	{ MODKEY|ShiftMask,     XK_s,      spawn,          {.v = flameshotcmd } }, // Screenshot
	{ MODKEY,               XK_backslash,spawn,        {.v = keepmenucmd } },  // Passwords
	{ MODKEY,               XK_m,      spawn,          {.v = cmuscmd } },      // Music Player
	{ MODKEY,               XK_e,      spawn,          {.v = mailcmd } },      // Email (In Neovim)
	{ MODKEY,               XK_s,      spawn,          {.v = slackcmd } },     // Slack

	{ MODKEY,               XK_b,      togglebar,      {0} },
	{ MODKEY,               XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,               XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,               XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,               XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,               XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,               XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,               XK_Return, zoom,           {0} },
	{ MODKEY,               XK_Tab,    view,           {0} },
	{ MODKEY,               XK_q,      killclient,     {0} },

	{ MODKEY|ShiftMask,     XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,     XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,     XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,     XK_c,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,     XK_g,      setlayout,      {.v = &layouts[4]} },

  /* cmus control */
	{ MODKEY|ControlMask,   XK_space,  spawn,          {.v = cmus_pause } },
	{ MODKEY|ControlMask,   XK_p,      spawn,          {.v = cmus_play } },
	{ MODKEY|ControlMask,   XK_k,      spawn,          {.v = cmus_next } },
	{ MODKEY|ControlMask,   XK_h,      spawn,          {.v = cmus_prev } },
	{ MODKEY|ControlMask,   XK_l,      spawn,          {.v = cmus_ff } },

	{ MODKEY,               XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,     XK_space,  togglefloating, {0} },
  { MODKEY,               XK_r,      togglermaster,  {0} },
	{ MODKEY,               XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,     XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,               XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,               XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,     XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                XK_1,                      0)
	TAGKEYS(                XK_2,                      1)
	TAGKEYS(                XK_3,                      2)
	TAGKEYS(                XK_4,                      3)
	TAGKEYS(                XK_5,                      4)
	TAGKEYS(                XK_6,                      5)
	{ MODKEY|ShiftMask,     XK_q,         quit,        {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q, quit,        {1} }, 
	{ MODKEY|ShiftMask,     XK_BackSpace, spawn,       {.v = suspendcmd } },
	{ MODKEY|ControlMask,   XK_BackSpace, spawn,       {.v = shutdowncmd } },

  { 0,                    XF86XK_AudioMute, spawn,      {.v = togglemutecmd } },
  { 0,                    XF86XK_AudioRaiseVolume, spawn, {.v = volumeup } },
  { 0,                    XF86XK_AudioLowerVolume, spawn, {.v = volumedown } },
  { 0,                    XF86XK_MonBrightnessUp, spawn, {.v = brightnessup} },
  { 0,                    XF86XK_MonBrightnessDown, spawn, {.v = brightnessdown} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

