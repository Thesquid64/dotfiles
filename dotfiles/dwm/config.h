/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 64;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMonoNerdFontMono-Regular:size=15" };
static const char dmenufont[]       = "JetBrainsMonoNerdFontMono-Regular";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

static const char col_dark[]        = "#000000";
static const char col_blue[]        = "#65D9FF";
static const char col_darkGrey[]    = "#262626";
static const char col_steelBlue[]   = "#0099FF";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_dark, col_gray2 },
	[SchemeSel]  = { col_gray4, col_steelBlue,  col_steelBlue  },
};

/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.47; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 60;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]",      tile },    /* first entry is default */
	{ "|-|",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-show", "drun", "-theme-str", "window { background-color: #000000; border: 2px; border-color: #0099FF; } mainbox { background-color: #000000; } listview { background-color: #000000; } element { background-color: #000000; text-color: #65D9FF; } element selected { background-color: #262626; text-color: #0099FF; } element-text { background-color: inherit; text-color: inherit; } inputbar { background-color: #000000; text-color: #65D9FF; } prompt { background-color: #000000; text-color: #0099FF; } entry { background-color: #000000; text-color: #65D9FF; }", NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *browsercmd[]  = { "firefox", NULL };
static const char *textcmd[]  = { "kitty emacs", NULL };
static const char *filemanagercmd[]  = { "kitty lf", NULL };
static const char *keybcmd[] = { "/usr/bin/flatpak", "run", "org.cubocore.CoreKeyboard", NULL };
static const char *scrshotcmd[] = { "scrot -s", NULL };


static const Key keys[] = {
	/* modifier                     key        function        argument */
        { MODKEY|ShiftMask,             XK_q,      spawn,          {.v = scrshotcmd } }, 
	{ MODKEY,                       XK_k,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_m,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_comma,  spawn,          {.v = textcmd } },
	{ MODKEY,                       XK_period, spawn,          {.v = browsercmd } },
        { MODKEY,                       XK_slash,  spawn,          {.v = filemanagercmd } },
	//{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_u,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_l,      focusstack,     {.i = -1 } },
	//{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	//{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_y, zoom,           {0} },
	//{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_f,      killclient,     {0} },
	//{ MODKEY,                       XK_p,      setlayout,      {.v = &layouts[0]} },
	//{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_p,      setlayout,      {.v = &layouts[2]} },
	//{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	//{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	//{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	//{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	//{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	//{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	//{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_n,                      0)
	TAGKEYS(                        XK_e,                      1)
	TAGKEYS(                        XK_i,                      2)
	TAGKEYS(                        XK_o,                      3)
	TAGKEYS(                        XK_t,                      4)
	TAGKEYS(                        XK_s,                      5)
	TAGKEYS(                        XK_r,                      6)
	TAGKEYS(                        XK_a,                      7)
	{ MODKEY,                       XK_BackSpace, quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        spawn,          {.v = keybcmd } },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = dmenucmd } },
	{ ClkStatusText,        0,              Button3,        killclient,     {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

