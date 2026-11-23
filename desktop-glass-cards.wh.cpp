// ==WindhawkMod==
// @id              desktop-glass-cards
// @name            Desktop Glass Cards
// @description     Six translucent desktop cards for weather, clock and Pomodoro, system monitoring, media and MP3 metadata, calendar, and notes.
// @version         9.17.0
// @author          David Nadal Pérez
// @donateUrl       https://ko-fi.com/davidnadalperez
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -DWIN32_LEAN_AND_MEAN -lwinhttp -luser32 -lgdi32 -liphlpapi -lpdh -lshell32 -ladvapi32 -lpsapi -lole32 -loleaut32 -lruntimeobject -lversion -lmfplat -lmfreadwrite -lmfuuid -utf-8
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Desktop Glass Cards

Six translucent desktop cards for Windhawk on 64-bit Windows. Drag any card to move the stack. Click a heading to collapse or expand that card. Use the context menu to collapse or expand all cards, change their order, or lock their position. The default global shortcut is **Ctrl+Alt+F9**.

- **Weather** shows current conditions, an interactive 24-hour temperature and rain chart, and a six-day forecast. Optional panels include apparent temperature, humidity, wind, sunrise, sunset, air quality, and pollen. The card retains the last forecast during a failed refresh.
- **Clock** shows local time and up to three additional time zones. Choose a digital or analog display and set work and break intervals for the Pomodoro timer. A collapsed card shows local time or the running countdown.
- **System** shows CPU, RAM, optional GPU and disk activity, a 60-second CPU chart, network download and upload rates, and the busiest processes. Storage, battery, and Wi-Fi are configurable. Process memory is private committed memory. Point to the CPU chart or a process for a detailed reading.
- **Calendar** combines local events with optional local or remote iCalendar feeds. Click a countdown to mark or unmark an event and click its location to open it in Maps. The collapsed card can hide the next event's name.
- **Notes** is an automatically saved sticky note. Click the note to edit it. Press Esc or click outside to finish. The corner button clears the note and allows you to undo the last clear.
- **Media** shows cover art, track details, transport controls, progress, and a spectrum visualizer. Click the track title to copy the title and artist. Hover over a long title to scroll it. Click or drag the progress bar when the player supports seeking.

## Media controls and lyrics

The card normally follows a playing session. Use **Switch player** in its context menu or **Shift + mouse wheel** to cycle through sessions. The regular mouse wheel adjusts the selected application's volume when Windows can identify its audio session. Shuffle, repeat, and seeking depend on the player. Global media shortcuts are optional.

The visualizer attempts to capture the selected application and its child processes. It uses the default Windows output when that capture is unavailable. Capture pauses when playback pauses or the card is collapsed or hidden. Enable **Keep the card visible while stopped** if your player keeps a stopped session open.

Synchronized lyrics from LRCLIB have a separate, accent-colored row. The card expands for lyrics while keeping the album and year visible. The lookup uses title, artist, duration, and album when available, and skips browser sessions.

## Audio metadata

Open the metadata panel using the button in the Media card header.

- **A** shows supported local tags first, then catalog matches and available details from the card.
- **B** prefers an acoustic match for local MP3 files and falls back to a title and artist search through online catalogs. The panel identifies the source when available.
- When the player reports a file path, the mod can read embedded title, artist, album, year, and cover art from **MP3, FLAC, M4A, and M4B** files with supported tags. FLAC, M4A, and M4B are read-only. Other recognized formats can still show information supplied by the player or catalog.
- The card keeps the album supplied by the file or player. If that album is known, a catalog year is accepted only for a matching album.

Only **MP3** supports writing. If the player does not provide a verifiable path, confirm the suggested MP3 or select it yourself. Choose the tags and artwork, then select **Embed** to authorize the write. The editor closes once the operation is queued.

The persistent queue waits for the media sessions to stop or close and for the MP3 to become available. A changed file or interrupted write requires review. Pending changes can be inspected or canceled from any card's context menu. **Undo last change** restores the previous header when a valid backup exists. Up to five undo levels are kept per file. MP3 notices can remain visible separately when the Media card hides.

## Online services and local data

Weather needs network access. Remote calendars are requested only when configured. Catalog lookups use track title and artist. LRCLIB also receives duration and, when available, album. Acoustic matching is optional and requires your own AcoustID API key. It sends a fingerprint and the track duration. Leave the key empty to disable fingerprinting.

Napster is an optional source for missing artwork. If you have an application key for the legacy Napster music catalog (v2.2), enter it in **[Media] Napster catalog API key** and enable **Look up missing cover art online**. The mod sends title and artist to the catalog over HTTPS when a lookup reaches that source. Enter your key in Windhawk Settings and keep it out of the published source.

The mod stores caches, backups, and queued MP3 operations under LocalAppData. Catalog proposals can be reused for 30 days. The bundled fingerprinting code does not require an external executable.

## Calendar editor and card order

Right-click Calendar and choose **Edit calendar…**. Enter one local event per line. Blank lines and lines beginning with # are ignored. Use **Save** or **Ctrl+Enter** to apply, and **Cancel** or **Esc** to discard edits. Edit imported events in their original calendar.

    DD/MM/YYYY [HH:MM] Text [@daily|@weekly|@monthly|@yearly] [# Location]
    16/03/2027 07:00 Renew passport @yearly # City hall

Clock entries use **Label | Windows time zone | Country code**. The country code is optional. Run **tzutil /l** to list Windows time zone names.

Right-click any card and choose **Card order…** to set the order from top to bottom. Select a card and use **Move up** or **Move down**. **Default order** restores the original arrangement in the editor. Save to apply and persist the order. Hidden cards retain their place.

English is the default card language. Spanish and Catalan remain available in Settings.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- language: "en"
  $name: "[General] Language"
  $description: "Language used for all cards and menus"
  $options:
    - es: "Spanish"
    - en: "English"
    - ca: "Catalan"
- theme: auto
  $name: "[General] Theme"
  $description: "Automatic follows the Windows light or dark theme"
  $options:
    - auto: "Automatic"
    - dark: "Dark"
    - light: "Light"
- useWindowsAccent: false
  $name: "[General] Use the Windows accent color"
  $description: "Uses the system accent for the card glow, icons, bars, and accent-based visualizer palette"
- accent: 255
  $name: "[General] Card accent intensity (0–255)"
  $description: "Controls the upper-left glow. 0 is off and 255 is maximum"
- scale: 100
  $name: "[General] Scale (%)"
  $description: "Scales all cards. 100 is the original size"
- glassOpacity: 72
  $name: "[General] Glass opacity (%)"
  $description: "Higher values make the card backgrounds less transparent"
- cornerRadius: 24
  $name: "[General] Corner radius (px)"
  $description: "Higher values make the card corners rounder"
- pauseFullscreen: true
  $name: "[General] Pause while an app is full-screen"
  $description: "Pauses updates while a game or video fills the screen"
- modernFont: true
  $name: "[General] Modern typeface (Segoe UI Variable)"
  $description: "Uses Segoe UI Variable when installed. Otherwise uses Segoe UI"
- autoFold: true
  $name: "[General] Auto-collapse cards to fit the screen"
  $description: "Collapses cards in priority order if the stack is too tall. Opening an auto-collapsed card can collapse another"
- autoFoldOrder: "clock, notes, deadlines, media, system"
  $name: "[General] Auto-collapse order"
  $description: "Comma-separated card IDs: weather, clock, system, deadlines, notes, media. Omitted cards never collapse automatically. Leave blank to exclude all cards"
- foldHotkey: "Ctrl+Alt+F9"
  $name: "[General] Shortcut to collapse or expand all cards"
  $description: "For example Ctrl+Alt+F9 or Win+Shift+T. Requires Ctrl, Alt, Shift, or Win. Avoid Ctrl+Alt with letters if you use AltGr. Leave blank to disable"
- lockPosition: false
  $name: "[Position] Lock position"
  $description: "Prevents dragging the cards. You can also change this in the context menu"
- monitor: 0
  $name: "[Position] Monitor"
  $description: "0 is the primary display. Use 1, 2, and so on to select a display by number"
- snapToEdges: true
  $name: "[Position] Snap to screen edges"
  $description: "Snaps the stack to the screen edges when you finish dragging"
- marginRight: 45
  $name: "[Position] Right margin (px)"
  $description: "Distance from the cards to the right edge of the screen"
- marginTop: 32
  $name: "[Position] Top margin (px)"
  $description: "Distance from the first card to the top edge of the screen"
- stackGap: 14
  $name: "[Position] Gap between cards (px)"
  $description: "Vertical space between adjacent cards"
- resetPosition: 0
  $name: "[Position] Reset position"
  $description: "Set to 1 to reset the position, then return it to 0"
- showWeather: true
  $name: "[Weather] Show card"
  $description: "Shows or hides the Weather card"
- city: "London"
  $name: "[Weather] City"
  $description: "Name shown on the card. Weather is fetched for the coordinates below"
- latitude: "51.50"
  $name: "[Weather] Latitude"
  $description: "Use a decimal point, for example 51.50"
- longitude: "-0.12"
  $name: "[Weather] Longitude"
  $description: "Use a decimal point, for example -0.12"
- units: celsius
  $name: "[Weather] Units"
  $description: "Temperature unit"
  $options:
    - celsius: "Celsius"
    - fahrenheit: "Fahrenheit"
- alertDot: true
  $name: "[Weather] Show an unread alert dot"
  $description: "Shows a severity-colored dot for an unseen yellow, orange, or red alert. Hover over the card to mark it as seen"
- showDetails: true
  $name: "[Weather] Show apparent temperature, humidity, and wind"
  $description: "Displays the panel for apparent temperature, humidity, and wind"
- showSunAir: true
  $name: "[Weather] Show sun times, air quality, and pollen"
  $description: "Displays sunrise, sunset, air quality, and pollen levels"
- showHourly: true
  $name: "[Weather] Show the 24-hour chart"
  $description: "Displays the expected temperature trend over the next 24 hours"
- showForecast: true
  $name: "[Weather] Show the forecast"
  $description: "Displays the forecast for the coming days"
- refreshMinutes: 15
  $name: "[Weather] Refresh interval (minutes)"
  $description: "How often to fetch the weather"
- showClock: true
  $name: "[Clock] Show card"
  $description: "Shows or hides the Clock card"
- clocks:
  - "London | GMT Standard Time | GB"
  - "New York | Eastern Standard Time | US"
  $name: "[Clock] Time zones (up to 3)"
  $description: "Separate the label, Windows time zone, and optional country code with vertical bars. Use tzutil /l to list time zones"
- clockStyle: digital
  $name: "[Clock] Style"
  $description: "Digital shows HH:MM:SS. Analog shows a clock face with the local time"
  $options:
    - digital: "Digital (HH:MM:SS)"
    - analogico: "Analog (clock face)"
- localFlag: ""
  $name: "[Clock] Local time flag"
  $description: "Country code, such as US, GB, or CAT. Leave blank to hide the flag"
- pomoFocus: 25
  $name: "[Clock] Pomodoro work time (minutes)"
  $description: "Length of each work session. 0 disables the timer"
- pomoBreak: 5
  $name: "[Clock] Pomodoro break time (minutes)"
  $description: "Length of each break"
- showSystem: true
  $name: "[System] Show card"
  $description: "Shows or hides the System card"
- systemFoldSummary: cpuRam
  $name: "[System] Collapsed summary"
  $options:
    - cpuRam: "CPU and RAM"
    - cpu: "CPU"
    - ram: "RAM"
    - none: "No summary"
- systemRefreshSec: 1
  $name: "[System] Refresh interval (seconds)"
  $description: "General update interval. The CPU is sampled separately while System is visible"
- showGpu: true
  $name: "[System] Show GPU"
  $description: "Shows the busiest graphics engine using Windows performance counters"
- showDisk: true
  $name: "[System] Show disk activity"
  $description: "Shows the percentage of time disks are busy. Enabling GPU and disk activity displays four gauges"
- showBattery: true
  $name: "[System] Show battery when available"
  $description: "Shows the charge level on supported laptops and tablets"
- showWifi: true
  $name: "[System] Show Wi-Fi"
  $description: "Shows the network name and signal strength"
- maxDisks: 2
  $name: "[System] Number of drives"
  $description: "Shows between zero and four drives"
- processCount: 5
  $name: "[System] Number of busiest processes"
  $description: "Shows up to five processes. Set to 0 to hide them"
- topProcsSort: cpu
  $name: "[System] Sort processes by"
  $description: "Controls which processes are shown"
  $options:
    - cpu: "CPU"
    - ram: "Private committed memory"
- showMedia: true
  $name: "[Media] Show card"
  $description: "Shows or hides the Media card"
- mediaAutoHide: true
  $name: "[Media] Hide when there is no active session"
  $description: "Keeps the card visible during pause or loading. MP3 notices can appear while the card is hidden"
- mediaKeepStopped: false
  $name: "[Media] Keep the card visible while stopped"
  $description: "Keeps controls visible when a player reports a stopped session"
- mediaLyrics: true
  $name: "[Media] Synchronized lyrics (LRCLIB)"
  $description: "Shows lyrics in an accent-colored row. LRCLIB receives the title, artist, duration, and album if known. Browser sessions are skipped"
- mediaHotkeyPrev: ""
  $name: "[Media] Global shortcut for previous track"
  $description: "For example Ctrl+Alt+Left. Requires a modifier and the Media card to be enabled. Leave blank to disable"
- mediaHotkeyPlay: ""
  $name: "[Media] Global shortcut for play or pause"
  $description: "For example Ctrl+Alt+Space. Leave blank to disable"
- mediaHotkeyNext: ""
  $name: "[Media] Global shortcut for next track"
  $description: "For example Ctrl+Alt+Right. Leave blank to disable"
- mediaTime: true
  $name: "[Media] Show elapsed and total time"
  $description: "Shows elapsed time on the left and total time on the right when available. Seeking requires player support"
- coverAccent: true
  $name: "[Media] Use cover art as the accent color"
  $description: "Uses the cover art's dominant color for the progress bar, glow, and icon. Otherwise uses pink or the Windows accent"
- eqPalette: rainbow
  $name: "[Media] Visualizer color palette"
  $description: "Uses application audio when Windows can identify it. Otherwise uses the default output. Custom uses the three colors below"
  $options:
    - rainbow: "Rainbow (cyan, green, yellow, orange, pink)"
    - bluepurple: "Blue and violet"
    - sunset: "Sunset (violet, pink, orange)"
    - fire: "Fire (yellow, orange, red)"
    - green: "Green"
    - ice: "Ice (light blue to white)"
    - accent: "Card accent color"
    - custom: "Custom (three colors)"
- eqColorLow: '#3C78FF'
  $name: "[Media] Visualizer base color"
  $description: "For the Custom palette. Use #RRGGBB"
- eqColorMid: '#A064FF'
  $name: "[Media] Visualizer middle color"
  $description: "For the Custom palette. Use #RRGGBB"
- eqColorHigh: '#FF64C8'
  $name: "[Media] Visualizer peak color"
  $description: "For the Custom palette. Use #RRGGBB"
- onlineCovers: true
  $name: "[Media] Look up missing cover art online"
  $description: "Looks up title and artist in online music catalogs and caches artwork locally"
- napsterApiKey: ''
  $name: "[Media] Napster catalog API key"
  $description: "Optional application key for the legacy Napster music catalog (v2.2). Requires online cover art lookups. Leave blank to skip Napster"
- musicFolders:
  - '%USERPROFILE%\Music'
  $name: "[Media] MP3 search folders (up to 5)"
  $description: "Searches these folders and their subfolders for candidate files when preparing MP3 metadata"
- fingerprint: true
  $name: "[Media] Identify tracks with an audio fingerprint"
  $description: "Uses the bundled Chromaprint library for local MP3s. Sends the fingerprint and duration to AcoustID using your API key"
- acoustidKey: ""
  $name: "[Media] AcoustID API key"
  $description: "Get a free key at acoustid.org/new-application. Leave blank to disable fingerprint lookups"
- showDeadlines: true
  $name: "[Calendar] Show card"
  $description: "Shows or hides the Calendar card"
- agendaFoldPrivate: false
  $name: "[Calendar] Hide event names when collapsed"
  $description: "Shows only the date and countdown of the next event"
- maxDeadlines: 4
  $name: "[Calendar] Number of visible events"
  $description: "Controls how many events appear on the card at once"
- deadlines:
  - ""
  $name: "[Calendar] Events"
  $description: "DD/MM/YYYY [HH:MM] Text [@daily, @weekly, @monthly, or @yearly] [# Location]"
- notifyMinutes: 30
  $name: "[Calendar] Notify before an event (minutes)"
  $description: "Set to 0 to disable timed event notifications"
- icsUrl: ''
  $name: "[Calendar] iCalendar feeds (optional)"
  $description: "Adds events from local .ics files or remote HTTPS or webcal URLs. Separate sources with spaces or vertical bars"
- icsLabel: ''
  $name: "[Calendar] Short feed label (optional)"
  $description: "A label to show alongside events from the feed"
- calendarUrl: ''
  $name: "[Calendar] Double-click URL (optional)"
  $description: "Opens this URL when you double-click the Calendar card"
- showNotes: true
  $name: "[Notes] Show card"
  $description: "Shows or hides the Notes card"
- stickyCompact: true
  $name: "[Notes] Fit height to text"
  $description: "Fits the note to its content up to the maximum number of lines"
- stickyLines: 7
  $name: "[Notes] Maximum visible lines"
  $description: "Controls the maximum height of the note"
- notes:
  - "Click to write a note"
  $name: "[Notes] Initial note text"
  $description: "Used on first run. Later edits are saved automatically"
*/
// ==/WindhawkModSettings==

#define GC_MOD_VERSION_W L"9.17.0"
#define GC_HTTP_AGENT_W L"WindhawkGlassCards/" GC_MOD_VERSION_W

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define NOMINMAX
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <windows.h>
#include <windowsx.h>   // GET_X_LPARAM / GET_Y_LPARAM
#include <winhttp.h>
#include <shellapi.h>
#include <winver.h>   // GetFileVersionInfoW supplies process display names.
#include <commdlg.h>   // GetOpenFileNameW opens the file picker.
#include <tlhelp32.h>
#include <psapi.h>
#include <pdh.h>
#include <pdhmsg.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif
#include <ctype.h>
#include <wctype.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <chrono>

#include <vector>
#include <utility>
#include <atomic>
#include <algorithm>
#include <unordered_map>
#include <mmsystem.h>
#include <mmreg.h>
#include <mmdeviceapi.h>
#include <audioclient.h>
#include <audiopolicy.h>
#if defined(__has_include)
#if __has_include(<audioclientactivationparams.h>)
#include <audioclientactivationparams.h>
#define GH_HAVE_PROCESS_LOOPBACK 1
#endif
#endif
#ifndef GH_HAVE_PROCESS_LOOPBACK
#define GH_HAVE_PROCESS_LOOPBACK 0
#endif
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <mferror.h>
#include <propidl.h>

// Media integration is available when the C++/WinRT headers are present.
#define GH_HAVE_WINRT 0
#define GH_HAVE_THUMB 0
#if defined(__has_include)
#if __has_include(<winrt/Windows.Media.Control.h>)
#undef GetCurrentTime
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Media.h>
#include <winrt/Windows.Media.Control.h>
#undef GH_HAVE_WINRT
#define GH_HAVE_WINRT 1
#if __has_include(<winrt/Windows.Graphics.Imaging.h>) && __has_include(<winrt/Windows.Storage.Streams.h>)
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Graphics.Imaging.h>
#undef GH_HAVE_THUMB
#define GH_HAVE_THUMB 1
#endif
#endif
#endif

#ifndef WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY
#define WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY 4
#endif

// ---------------------------------------------------------------------------
// Load GetIfTable2 and FreeMibTable at runtime.
// ---------------------------------------------------------------------------

typedef struct _UA_MIB_IF_ROW2 {
    NET_LUID InterfaceLuid;
    NET_IFINDEX InterfaceIndex;
    GUID InterfaceGuid;
    WCHAR Alias[IF_MAX_STRING_SIZE + 1];
    WCHAR Description[IF_MAX_STRING_SIZE + 1];
    ULONG PhysicalAddressLength;
    UCHAR PhysicalAddress[IF_MAX_PHYS_ADDRESS_LENGTH];
    UCHAR PermanentPhysicalAddress[IF_MAX_PHYS_ADDRESS_LENGTH];
    ULONG Mtu;
    IFTYPE Type;
    TUNNEL_TYPE TunnelType;
    NDIS_MEDIUM MediaType;
    NDIS_PHYSICAL_MEDIUM PhysicalMediumType;
    NET_IF_ACCESS_TYPE AccessType;
    NET_IF_DIRECTION_TYPE DirectionType;
    struct {
        BOOLEAN HardwareInterface : 1;
        BOOLEAN FilterInterface : 1;
        BOOLEAN ConnectorPresent : 1;
        BOOLEAN NotAuthenticated : 1;
        BOOLEAN NotMediaConnected : 1;
        BOOLEAN Paused : 1;
        BOOLEAN LowPower : 1;
        BOOLEAN EndPointInterface : 1;
    } InterfaceAndOperStatusFlags;
    IF_OPER_STATUS OperStatus;
    NET_IF_ADMIN_STATUS AdminStatus;
    NET_IF_MEDIA_CONNECT_STATE MediaConnectState;
    NET_IF_NETWORK_GUID NetworkGuid;
    NET_IF_CONNECTION_TYPE ConnectionType;
    ULONG64 TransmitLinkSpeed;
    ULONG64 ReceiveLinkSpeed;
    // MIB_IF_ROW2 stores all inbound counters before the outbound counters.
    ULONG64 InOctets;
    ULONG64 InUcastPkts;
    ULONG64 InNUcastPkts;
    ULONG64 InDiscards;
    ULONG64 InErrors;
    ULONG64 InUnknownProtos;
    ULONG64 InUcastOctets;
    ULONG64 InMulticastOctets;
    ULONG64 InBroadcastOctets;
    ULONG64 OutOctets;
    ULONG64 OutUcastPkts;
    ULONG64 OutNUcastPkts;
    ULONG64 OutDiscards;
    ULONG64 OutErrors;
    ULONG64 OutUcastOctets;
    ULONG64 OutMulticastOctets;
    ULONG64 OutBroadcastOctets;
    ULONG64 OutQLen;
} UA_MIB_IF_ROW2;

typedef struct _UA_MIB_IF_TABLE2 {
    ULONG NumEntries;
    UA_MIB_IF_ROW2 Table[1];
} UA_MIB_IF_TABLE2;

typedef NETIO_STATUS(WINAPI* GetIfTable2Fn)(UA_MIB_IF_TABLE2**);
typedef VOID(WINAPI* FreeMibTableFn)(PVOID);

static GetIfTable2Fn  pGetIfTable2  = nullptr;
static FreeMibTableFn pFreeMibTable = nullptr;
static bool           g_netApiTried = false;

static void LoadNetApi() {
    if (g_netApiTried) return;
    g_netApiTried = true;
    HMODULE m = LoadLibraryW(L"iphlpapi.dll");
    if (!m) m = GetModuleHandleW(L"iphlpapi.dll");
    if (!m) return;
    pGetIfTable2 = (GetIfTable2Fn)GetProcAddress(m, "GetIfTable2");
    pFreeMibTable = (FreeMibTableFn)GetProcAddress(m, "FreeMibTable");
}

// ---------------------------------------------------------------------------
// Windows peak meter fallback

// Peak-only input cannot separate frequencies. Shape the bars using overall and per-channel levels.

// ---------------------------------------------------------------------------

typedef HRESULT(WINAPI* CoCreateInstanceFn)(REFCLSID, LPUNKNOWN, DWORD, REFIID, LPVOID*);

static void*  g_audioMeter = nullptr;
static bool   g_audioTried = false;
#define kEqBars 24
static float  g_eqBars[kEqBars] = {0};
static float  g_eqPeak[kEqBars] = {0};

static const GUID kClsidMMDeviceEnumerator =
    {0xBCDE0395, 0xE52F, 0x467C, {0x8E, 0x3D, 0xC4, 0x57, 0x92, 0x91, 0x69, 0x2E}};
static const GUID kIidIAudioMeter =
    {0xC02216F6, 0x8C67, 0x4B5B, {0x9D, 0x00, 0xD0, 0x08, 0xE7, 0x3E, 0x00, 0x64}};
static const GUID kIidIMMDeviceEnumerator =
    {0xA95664D2, 0x9614, 0x4F35, {0xA7, 0x46, 0xDE, 0x8D, 0xB6, 0x36, 0x17, 0xE6}};

// Keep unused COM vtable slots so the methods we call remain at their ABI offsets.

typedef HRESULT(WINAPI* PFN_GetDefaultAudioEndpoint)(void*, int, int, void**);
typedef HRESULT(WINAPI* PFN_Activate)(void*, REFIID, DWORD, void*, void**);
typedef HRESULT(WINAPI* PFN_GetPeakValue)(void*, float*);

static void CloseAudioMeter() {
    if (!g_audioMeter) return;
    void** obj = reinterpret_cast<void**>(g_audioMeter);
    if (obj && obj[0]) {
        typedef ULONG(WINAPI* PFN_Release)(void*);
        PFN_Release rel = reinterpret_cast<PFN_Release>(
            reinterpret_cast<void**>(obj[0])[2]);
        if (rel) rel(g_audioMeter);
    }
    g_audioMeter = nullptr;
}

static void LoadAudioMeter() {
    if (g_audioTried) return;
    g_audioTried = true;

    HMODULE m = LoadLibraryW(L"mmdevapi.dll");
    if (!m) m = GetModuleHandleW(L"mmdevapi.dll");
    if (!m) {
        Wh_Log(L"Audio meter: mmdevapi.dll is unavailable");
        return;
    }

    void* enumerator = nullptr;
    HRESULT hr = CoCreateInstance(kClsidMMDeviceEnumerator, nullptr, 1 /*INPROC_SERVER*/,
                                  kIidIMMDeviceEnumerator, &enumerator);
    if (FAILED(hr) || !enumerator) {
        Wh_Log(L"Audio meter: no device enumerator, hr=0x%08lX", (unsigned long)hr);
        return;
    }

    // Get the default multimedia render endpoint.

    void** evt = reinterpret_cast<void**>(enumerator);
    PFN_GetDefaultAudioEndpoint getEndpoint = reinterpret_cast<PFN_GetDefaultAudioEndpoint>(
        reinterpret_cast<void**>(evt[0])[4]);
    void* device = nullptr;
    hr = getEndpoint ? getEndpoint(enumerator, 0, 1, &device) : E_FAIL;
    if (FAILED(hr) || !device) {
        Wh_Log(L"Audio meter: no default device, hr=0x%08lX", (unsigned long)hr);
        typedef ULONG(WINAPI* PFN_Release)(void*);
        reinterpret_cast<PFN_Release>(evt[0] ? reinterpret_cast<void**>(evt[0])[2] : nullptr)(enumerator);
        return;
    }

    void** dvt = reinterpret_cast<void**>(device);
    PFN_Activate activate = reinterpret_cast<PFN_Activate>(
        reinterpret_cast<void**>(dvt[0])[3]);
    void* meter = nullptr;
    hr = activate ? activate(device, kIidIAudioMeter, 0 /*CLSCTX_INPROC_SERVER*/, nullptr, &meter)
                  : E_FAIL;
    if (FAILED(hr) || !meter) {
        Wh_Log(L"Audio meter: endpoint meter is unavailable, hr=0x%08lX", (unsigned long)hr);
        meter = nullptr;
    }

    typedef ULONG(WINAPI* PFN_Release)(void*);
    PFN_Release rel = reinterpret_cast<PFN_Release>(dvt[0] ? reinterpret_cast<void**>(dvt[0])[2] : nullptr);
    if (rel) rel(device);
    rel = reinterpret_cast<PFN_Release>(evt[0] ? reinterpret_cast<void**>(evt[0])[2] : nullptr);
    if (rel) rel(enumerator);

    g_audioMeter = meter;
    Wh_Log(L"Audio meter: %s", meter ? L"ready" : L"unavailable");
}

// Read the peak level on a 0–1 scale. Return -1 if the meter is unavailable.

struct AudioMeterVtbl {
    void* QueryInterface;
    void* AddRef;
    void* Release;
    HRESULT(WINAPI* GetPeakValue)(void*, float*);
    HRESULT(WINAPI* GetMeteringChannelCount)(void*, UINT*);
    HRESULT(WINAPI* GetChannelsPeakValues)(void*, UINT, float*);
};

static AudioMeterVtbl* AudioMeter() {
    if (!g_audioMeter) return nullptr;
    void** obj = reinterpret_cast<void**>(g_audioMeter);
    if (!obj || !obj[0]) return nullptr;
    return reinterpret_cast<AudioMeterVtbl*>(obj[0]);
}

static float ReadAudioPeak() {
    AudioMeterVtbl* vt = AudioMeter();
    if (!vt || !vt->GetPeakValue) return -1.0f;
    float peak = 0.0f;
    if (FAILED(vt->GetPeakValue(g_audioMeter, &peak))) return -1.0f;
    if (peak < 0.0f) peak = 0.0f;
    if (peak > 1.0f) peak = 1.0f;
    return peak;
}

// Read up to eight channel peaks. Return zero if unavailable.
static UINT ReadAudioChannels(float* out, UINT maxCh) {
    AudioMeterVtbl* vt = AudioMeter();
    if (!vt || !vt->GetMeteringChannelCount || !vt->GetChannelsPeakValues) return 0;
    UINT n = 0;
    if (FAILED(vt->GetMeteringChannelCount(g_audioMeter, &n)) || n == 0) return 0;
    if (n > maxCh) n = maxCh;
    if (FAILED(vt->GetChannelsPeakValues(g_audioMeter, n, out))) return 0;
    for (UINT i = 0; i < n; i++) {
        if (out[i] < 0.0f) out[i] = 0.0f;
        if (out[i] > 1.0f) out[i] = 1.0f;
    }
    return n;
}

static void SampleEqualizer() {
    // Refresh the default endpoint periodically and retry sooner after failure.

    static ULONGLONG s_reload = 0;
    ULONGLONG nowT = GetTickCount64();
    if (g_audioMeter && nowT >= s_reload) {
        CloseAudioMeter();
        g_audioTried = false;
    }
    LoadAudioMeter();
    if (g_audioMeter && s_reload <= nowT) s_reload = nowT + 30000;
    if (!g_audioMeter) {
        for (int i = 0; i < kEqBars; i++) g_eqBars[i] = 0.0f;
        if (nowT >= s_reload) s_reload = nowT + 5000;
        g_audioTried = (nowT < s_reload);
        return;
    }
    // Combine the instantaneous level with its smoothed envelope.

    static float s_slow = 0.0f;
    static float s_phase = 0.0f;
    float inst = ReadAudioPeak();
    if (inst < 0.0f) {
        CloseAudioMeter();
        g_audioTried = false;
        s_reload = nowT + 5000;
        for (int i = 0; i < kEqBars; i++) g_eqBars[i] = 0.0f;
        return;
    }
    s_slow += (inst - s_slow) * 0.25f;
    s_phase += 1.9f;

    float ch[8] = {0};
    UINT nch = ReadAudioChannels(ch, 8);

    for (int i = 0; i < kEqBars; i++) {
        float t = (float)i / (float)(kEqBars - 1);       // 0..1

        float shape = 0.55f + 0.45f * sinf(t * 3.14159265f);

        float base = inst * 0.65f + s_slow * 0.35f;

        if (nch >= 2) {
            float c = (t < 0.5f) ? ch[0] : ch[1];
            base = base * 0.55f + c * 0.45f;
        }

        float wob = 0.42f + 0.58f * sinf(s_phase + (float)i * 0.70f);
        wob += 0.18f * sinf(s_phase * 2.3f + (float)i * 1.7f);
        float target = base * shape * wob;
        if (target > 1.0f) target = 1.0f;

        if (target > g_eqBars[i]) g_eqBars[i] = target;
        else g_eqBars[i] += (target - g_eqBars[i]) * 0.82f;
    }
}

// ---------------------------------------------------------------------------
// WASAPI loopback and spectrum analysis

// The capture thread derives 24 bars from a 2048-point FFT spanning 50 Hz–14 kHz. It also processes volume commands.

// ---------------------------------------------------------------------------

#define kFftN 2048
static volatile LONG  g_eqWanted = 0;
static volatile LONG  g_eqQuit = 0;
static volatile LONG  g_eqCapOk = 0;
static std::atomic<float> g_eqLive[kEqBars] = {};
static HANDLE         g_eqThread = nullptr;
static SRWLOCK g_audioLock = SRWLOCK_INIT;
static std::wstring g_audioApp;
static LONG g_audioGeneration = 0;
static int g_audioWheelSteps = 0;
static bool g_audioVolumeBusy = false;
static int g_audioVolumeResult = -2;   // -2 indicates no response. -1 indicates volume is unavailable.

static void AudioSetTarget(const std::wstring& app) {
    AcquireSRWLockExclusive(&g_audioLock);
    if (g_audioApp != app) {
        g_audioApp = app;
        ++g_audioGeneration;
        g_audioWheelSteps = 0;
        g_audioVolumeBusy = false;
        g_audioVolumeResult = -2;
        InterlockedExchange(&g_eqCapOk, 0);
    }
    ReleaseSRWLockExclusive(&g_audioLock);
}

static bool AudioProcessMatches(DWORD pid, const std::wstring& app) {
    if (!pid || app.empty()) return false;
    HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!process) return false;
    wchar_t text[1024];
    constexpr auto capacity = sizeof(text) / sizeof(text[0]);
    bool match = false;
    if (app.find(L'!') != std::wstring::npos) {
        UINT32 size = static_cast<UINT32>(capacity);
        using GetAppId = LONG (WINAPI*)(HANDLE, UINT32*, PWSTR);
        static const auto getAppId = reinterpret_cast<GetAppId>(
            GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "GetApplicationUserModelId"));
        match = getAppId && getAppId(process, &size, text) == ERROR_SUCCESS &&
                _wcsicmp(text, app.c_str()) == 0;
    } else if (app.size() > 4 && _wcsicmp(app.c_str() + app.size() - 4, L".exe") == 0) {
        DWORD size = static_cast<DWORD>(capacity);
        if (QueryFullProcessImageNameW(process, 0, text, &size)) {
            const wchar_t* slash = wcsrchr(text, L'\\');
            const wchar_t* supplied = wcsrchr(app.c_str(), L'\\');
            match = _wcsicmp(app.c_str(), supplied ? text : slash ? slash + 1 : text) == 0;
        }
    }
    CloseHandle(process);
    return match;
}

struct AudioPlayerSessions {
    IAudioSessionControl* volume = nullptr;
    DWORD pid = 0;
    int matches = 0;
    int active = 0;
    bool multiplePids = false;

    ~AudioPlayerSessions() { if (volume) volume->Release(); }
    AudioPlayerSessions() = default;
    AudioPlayerSessions(const AudioPlayerSessions&) = delete;
    AudioPlayerSessions& operator=(const AudioPlayerSessions&) = delete;

    void Add(IAudioSessionControl* control, DWORD owner, bool playing) {
        if (!matches++) pid = owner;
        else multiplePids |= pid != owner;
        if (playing) ++active;
        if (matches == 1 || (playing && active == 1)) {
            if (volume) volume->Release();
            control->AddRef();
            volume = control;
        }
    }
};

static void AudioFindSessions(IMMDeviceEnumerator* en, const std::wstring& app, AudioPlayerSessions& found) {
    IMMDeviceCollection* endpoints = nullptr;
    if (app.empty() || FAILED(en->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE, &endpoints)) || !endpoints) return;
    UINT count = 0;
    endpoints->GetCount(&count);
    for (UINT i = 0; i < count; ++i) {
        IMMDevice* endpoint = nullptr;
        if (FAILED(endpoints->Item(i, &endpoint)) || !endpoint) continue;
        IAudioSessionManager2* manager = nullptr;
        endpoint->Activate(__uuidof(IAudioSessionManager2), CLSCTX_INPROC_SERVER, nullptr, (void**)&manager);
        endpoint->Release();
        if (!manager) continue;
        IAudioSessionEnumerator* list = nullptr;
        manager->GetSessionEnumerator(&list);
        manager->Release();
        if (!list) continue;
        int sessions = 0;
        list->GetCount(&sessions);
        for (int j = 0; j < sessions; ++j) {
            IAudioSessionControl* control = nullptr;
            if (FAILED(list->GetSession(j, &control)) || !control) continue;
            IAudioSessionControl2* identity = nullptr;
            AudioSessionState state = AudioSessionStateExpired;
            control->GetState(&state);
            if (state != AudioSessionStateExpired &&
                SUCCEEDED(control->QueryInterface(__uuidof(IAudioSessionControl2), (void**)&identity))) {
                DWORD pid = 0;
                // S_OK identifies a single process. AUDCLNT_S_NO_SINGLE_PROCESS does not.
                if (identity->GetProcessId(&pid) == S_OK && AudioProcessMatches(pid, app))
                    found.Add(control, pid, state == AudioSessionStateActive);
                identity->Release();
            }
            control->Release();
        }
        list->Release();
    }
    endpoints->Release();
}

static int AudioAdjustVolume(const AudioPlayerSessions& found, int steps, LONG generation) {
    if (!found.volume || (found.active ? found.active != 1 : found.matches != 1)) return -1;
    ISimpleAudioVolume* volume = nullptr;
    if (FAILED(found.volume->QueryInterface(__uuidof(ISimpleAudioVolume), (void**)&volume))) return -1;
    float level = 0;
    HRESULT hr = volume->GetMasterVolume(&level);
    if (SUCCEEDED(hr)) {
        level = std::clamp(level + 0.05f * steps, 0.0f, 1.0f);
        AcquireSRWLockShared(&g_audioLock);
        const bool sameTarget = generation == g_audioGeneration;
        ReleaseSRWLockShared(&g_audioLock);
        hr = sameTarget ? volume->SetMasterVolume(level, nullptr) : E_ABORT;
    }
    volume->Release();
    return SUCCEEDED(hr) ? (int)lroundf(level * 100.0f) : -1;
}

static const GUID kIidIAudioClient =
    {0x1CB9AD4C, 0xDBFA, 0x4C32, {0xB1, 0x78, 0xC2, 0xF5, 0x68, 0xA7, 0x03, 0xB2}};
static const GUID kIidIAudioCaptureClient =
    {0xC8ADBD64, 0xE71E, 0x48A0, {0xA4, 0xDE, 0x18, 0x5C, 0x39, 0x5C, 0xD3, 0x17}};

#if GH_HAVE_PROCESS_LOOPBACK
class AudioActivation final : public IActivateAudioInterfaceCompletionHandler {
    LONG refs = 1;
public:
    HANDLE event = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    IAudioClient* client = nullptr;

    ~AudioActivation() {
        if (client) client->Release();
        if (event) CloseHandle(event);
    }

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID id, void** out) override {
        if (!out) return E_POINTER;
        *out = nullptr;
        if (id != __uuidof(IUnknown) && id != __uuidof(IAgileObject) &&
            id != __uuidof(IActivateAudioInterfaceCompletionHandler)) return E_NOINTERFACE;
        *out = static_cast<IActivateAudioInterfaceCompletionHandler*>(this);
        AddRef();
        return S_OK;
    }
    ULONG STDMETHODCALLTYPE AddRef() override { return (ULONG)InterlockedIncrement(&refs); }
    ULONG STDMETHODCALLTYPE Release() override {
        ULONG count = (ULONG)InterlockedDecrement(&refs);
        if (!count) delete this;
        return count;
    }
    HRESULT STDMETHODCALLTYPE ActivateCompleted(IActivateAudioInterfaceAsyncOperation* operation) override {
        HRESULT status = E_FAIL;
        IUnknown* activated = nullptr;
        if (SUCCEEDED(operation->GetActivateResult(&status, &activated)) && SUCCEEDED(status) && activated)
            activated->QueryInterface(kIidIAudioClient, (void**)&client);
        if (activated) activated->Release();
        SetEvent(event);
        return S_OK;
    }
};

static IAudioClient* EqActivateProcess(DWORD pid) {
    if (!pid) return nullptr;
    using Activate = HRESULT (WINAPI*)(LPCWSTR, REFIID, PROPVARIANT*,
        IActivateAudioInterfaceCompletionHandler*, IActivateAudioInterfaceAsyncOperation**);
    static const auto activate = reinterpret_cast<Activate>(
        GetProcAddress(GetModuleHandleW(L"mmdevapi.dll"), "ActivateAudioInterfaceAsync"));
    if (!activate) return nullptr;
    auto* completion = new (std::nothrow) AudioActivation();
    if (!completion) return nullptr;
    AUDIOCLIENT_ACTIVATION_PARAMS options = {};
    options.ActivationType = AUDIOCLIENT_ACTIVATION_TYPE_PROCESS_LOOPBACK;
    options.ProcessLoopbackParams.TargetProcessId = pid;
    options.ProcessLoopbackParams.ProcessLoopbackMode = PROCESS_LOOPBACK_MODE_INCLUDE_TARGET_PROCESS_TREE;
    PROPVARIANT params = {};
    params.vt = VT_BLOB;
    params.blob.cbSize = sizeof(options);
    params.blob.pBlobData = reinterpret_cast<BYTE*>(&options);
    IActivateAudioInterfaceAsyncOperation* operation = nullptr;
    IAudioClient* client = nullptr;
    if (completion->event &&
        SUCCEEDED(activate(L"VAD\\Process_Loopback", kIidIAudioClient, &params, completion, &operation))) {
        // The capture thread waits for activation to complete. The callback never touches UI or player state.

        if (WaitForSingleObject(completion->event, INFINITE) == WAIT_OBJECT_0 && completion->client) {
            client = completion->client;
            client->AddRef();
        }
    }
    if (operation) operation->Release();
    completion->Release();
    return client;
}
#endif

static void FftInPlace(float* re, float* im, int n) {
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) {
            std::swap(re[i], re[j]);
            std::swap(im[i], im[j]);
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        float ang = -6.28318530718f / (float)len;
        float wlr = cosf(ang), wli = sinf(ang);
        int half = len >> 1;
        for (int i = 0; i < n; i += len) {
            float wr = 1.0f, wi = 0.0f;
            for (int j = 0; j < half; j++) {
                int a = i + j, b = i + j + half;
                float vr = re[b] * wr - im[b] * wi;
                float vi = re[b] * wi + im[b] * wr;
                re[b] = re[a] - vr;
                im[b] = im[a] - vi;
                re[a] += vr;
                im[a] += vi;
                float nwr = wr * wlr - wi * wli;
                wi = wr * wli + wi * wlr;
                wr = nwr;
            }
        }
    }
}

struct EqSession {
    IMMDevice* dev = nullptr;
    HANDLE event = nullptr;
    IAudioClient* ac = nullptr;
    IAudioCaptureClient* cap = nullptr;
    WAVEFORMATEX* fmt = nullptr;
    std::wstring id;
    int ch = 2;
    int bits = 32;
    int frameBytes = 8;
    int sr = 48000;
    bool isFloat = true;
};

static void EqClose(EqSession& s) {
    if (s.ac) s.ac->Stop();
    if (s.cap) s.cap->Release();
    if (s.ac) s.ac->Release();
    if (s.event) CloseHandle(s.event);
    if (s.dev) s.dev->Release();
    if (s.fmt) CoTaskMemFree(s.fmt);
    s = EqSession();
}

static bool EqOpen(IMMDeviceEnumerator* en, EqSession& s, DWORD pid) {
#if GH_HAVE_PROCESS_LOOPBACK
    if ((s.ac = EqActivateProcess(pid))) {
        WAVEFORMATEX pcm = {};
        pcm.wFormatTag = WAVE_FORMAT_PCM;
        pcm.nChannels = 2;
        pcm.nSamplesPerSec = 44100;
        pcm.wBitsPerSample = 16;
        pcm.nBlockAlign = 4;
        pcm.nAvgBytesPerSec = 176400;
        s.event = CreateEventW(nullptr, FALSE, FALSE, nullptr);
        if (s.event && SUCCEEDED(s.ac->Initialize(AUDCLNT_SHAREMODE_SHARED,
                AUDCLNT_STREAMFLAGS_LOOPBACK | AUDCLNT_STREAMFLAGS_EVENTCALLBACK | AUDCLNT_STREAMFLAGS_AUTOCONVERTPCM,
                0, 0, &pcm, nullptr)) && SUCCEEDED(s.ac->SetEventHandle(s.event)) &&
            SUCCEEDED(s.ac->GetService(kIidIAudioCaptureClient, (void**)&s.cap)) && s.cap &&
            SUCCEEDED(s.ac->Start())) {
            s.isFloat = false;
            s.bits = 16;
            s.frameBytes = 4;
            s.sr = 44100;
            return true;
        }
        EqClose(s);
    }
#else
    (void)pid;
#endif
    if (FAILED(en->GetDefaultAudioEndpoint(eRender, eMultimedia, &s.dev)) || !s.dev) {
        EqClose(s);
        return false;
    }
    LPWSTR id = nullptr;
    if (SUCCEEDED(s.dev->GetId(&id)) && id) {
        s.id = id;
        CoTaskMemFree(id);
    }
    if (FAILED(s.dev->Activate(kIidIAudioClient, CLSCTX_INPROC_SERVER, nullptr, (void**)&s.ac)) || !s.ac ||
        FAILED(s.ac->GetMixFormat(&s.fmt)) || !s.fmt) {
        EqClose(s);
        return false;
    }
    WAVEFORMATEX* f = s.fmt;
    s.ch = f->nChannels;
    s.bits = f->wBitsPerSample;
    s.sr = (int)f->nSamplesPerSec;
    s.frameBytes = f->nBlockAlign;
    s.isFloat = f->wFormatTag == 3 ||
                (f->wFormatTag == 0xFFFE && f->cbSize >= 22 &&
                 reinterpret_cast<WAVEFORMATEXTENSIBLE*>(f)->SubFormat.Data1 == 3);
    bool okFmt = s.ch >= 1 && s.frameBytes >= 1 && s.sr >= 8000 &&
                 (s.isFloat ? s.bits == 32 : (s.bits == 16 || s.bits == 24 || s.bits == 32));
    if (!okFmt || FAILED(s.ac->Initialize(AUDCLNT_SHAREMODE_SHARED, AUDCLNT_STREAMFLAGS_LOOPBACK, 2000000, 0,
                                          s.fmt, nullptr)) ||
        FAILED(s.ac->GetService(kIidIAudioCaptureClient, (void**)&s.cap)) || !s.cap || FAILED(s.ac->Start())) {
        Wh_Log(L"Visualizer: capture could not be opened (%d-bit format, float=%d)", s.bits, s.isFloat ? 1 : 0);
        EqClose(s);
        return false;
    }
    return true;
}

static inline float EqReadSample(const BYTE* p, bool isFloat, int bits) {
    if (isFloat) {
        float v;
        memcpy(&v, p, 4);
        if (!(v == v)) return 0.0f; // NaN
        if (v > 1.0f) v = 1.0f;
        if (v < -1.0f) v = -1.0f;
        return v;
    }
    if (bits == 16) {
        short v;
        memcpy(&v, p, 2);
        return (float)v / 32768.0f;
    }
    if (bits == 24) {
        int v = (int)(((unsigned)p[0] << 8) | ((unsigned)p[1] << 16) | ((unsigned)p[2] << 24));
        return (float)v / 2147483648.0f;
    }
    int v;
    memcpy(&v, p, 4);
    return (float)v / 2147483648.0f;
}

// Own the loopback endpoint and FFT state on the audio thread.
static DWORD WINAPI EqCaptureThread(LPVOID) {
    HRESULT hrCo = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    IMMDeviceEnumerator* en = nullptr;
    if (FAILED(CoCreateInstance(kClsidMMDeviceEnumerator, nullptr, CLSCTX_INPROC_SERVER, kIidIMMDeviceEnumerator,
                                (void**)&en)) ||
        !en) {
        Wh_Log(L"Visualizer: using the peak meter because the audio enumerator is unavailable");
        AcquireSRWLockExclusive(&g_audioLock);
        if (std::exchange(g_audioWheelSteps, 0)) g_audioVolumeResult = -1;
        ReleaseSRWLockExclusive(&g_audioLock);
        if (SUCCEEDED(hrCo)) CoUninitialize();
        return 0;
    }

    static float ring[kFftN];
    static float hann[kFftN];
    static float re[kFftN], im[kFftN];
    for (int i = 0; i < kFftN; i++) hann[i] = 0.5f - 0.5f * cosf(6.28318530718f * (float)i / (float)(kFftN - 1));
    memset(ring, 0, sizeof(ring));

    EqSession sess;
    int ringW = 0, sinceLast = 0;
    float agc = 0.5f;
    float live[kEqBars] = {0};
    struct EqBand { int lo, hi; float compensation; };
    EqBand bands[kEqBars] = {};
    ULONGLONG lastIdCheck = 0, lastData = 0, lastAppCheck = 0;
    LONG previousTarget = -1;
    DWORD playerPid = 0;
    // Publish mono PCM at the endpoint sample rate. Shared FIR resampling runs outside the capture thread.

    while (!g_eqQuit) {
        std::wstring app;
        AcquireSRWLockExclusive(&g_audioLock);
        const LONG generation = g_audioGeneration;
        const int wheel = std::exchange(g_audioWheelSteps, 0);
        if (wheel) g_audioVolumeBusy = true;
        const ULONGLONG now = GetTickCount64();
        const bool resolve = generation != previousTarget || wheel ||
            (g_eqWanted && now - lastAppCheck >= 1500);
        if (resolve) app = g_audioApp;
        ReleaseSRWLockExclusive(&g_audioLock);
        if (resolve) {
            AudioPlayerSessions found;
            AudioFindSessions(en, app, found);
            const DWORD pid = found.multiplePids ? 0 : found.pid;
            if (generation != previousTarget || pid != playerPid) {
                EqClose(sess);
                InterlockedExchange(&g_eqCapOk, 0);
                for (int i = 0; i < kEqBars; ++i) {
                    live[i] = 0.0f;
                    g_eqLive[i].store(0.0f, std::memory_order_relaxed);
                }
            }
            previousTarget = generation;
            playerPid = pid;
            lastAppCheck = now;
            if (wheel) {
                const int result = AudioAdjustVolume(found, wheel, generation);
                AcquireSRWLockExclusive(&g_audioLock);
                if (generation == g_audioGeneration) {
                    g_audioVolumeResult = result;
                    g_audioVolumeBusy = false;
                }
                ReleaseSRWLockExclusive(&g_audioLock);
            }
        }
        if (!g_eqWanted) {

            if (sess.ac || g_eqCapOk) {
                if (sess.ac) EqClose(sess);
                InterlockedExchange(&g_eqCapOk, 0);
            }
            for (int i = 0; i < kEqBars; i++) {
                live[i] = 0.0f;
                g_eqLive[i].store(0.0f, std::memory_order_relaxed);
            }
            Sleep(150);
            continue;
        }
        if (!sess.ac) {
            if (!EqOpen(en, sess, playerPid)) {
                InterlockedExchange(&g_eqCapOk, 0);
                Sleep(1500);
                continue;
            }
            lastIdCheck = lastData = now;
            ringW = sinceLast = 0;
            memset(ring, 0, sizeof(ring));
            // Precompute frequency bands when the mix format changes.

            const float fmin = 50.0f;
            const float fmax = std::min(14000.0f, (float)sess.sr * 0.45f);
            const float ratio = fmax / fmin;
            for (int b = 0; b < kEqBars; ++b) {
                const float lo = fmin * powf(ratio, (float)b / (float)kEqBars);
                const float hi = fmin * powf(ratio, (float)(b + 1) / (float)kEqBars);
                const int kLo = std::max(1, (int)(lo * (float)kFftN / (float)sess.sr));
                const int kHi = std::min(kFftN / 2,
                    std::max(kLo + 1, (int)(hi * (float)kFftN / (float)sess.sr)));
                bands[b] = {kLo, kHi, 2.5f * log2f(sqrtf(lo * hi) / 150.0f)};
            }
            InterlockedExchange(&g_eqCapOk, 1);
        }

        // Reopen loopback capture if the default output changes.
        if (sess.dev && now - lastIdCheck > 1500) {
            lastIdCheck = now;
            IMMDevice* d = nullptr;
            if (SUCCEEDED(en->GetDefaultAudioEndpoint(eRender, eMultimedia, &d)) && d) {
                LPWSTR id = nullptr;
                bool changed = false;
                if (SUCCEEDED(d->GetId(&id)) && id) {
                    changed = (sess.id != id);
                    CoTaskMemFree(id);
                }
                d->Release();
                if (changed) {
                    InterlockedExchange(&g_eqCapOk, 0);
                    EqClose(sess);
                    continue;
                }
            }
        }

        Sleep(10);

        bool got = false, broken = false;
        UINT32 pkt = 0;
        while (true) {
            HRESULT hr = sess.cap->GetNextPacketSize(&pkt);
            if (FAILED(hr)) {
                broken = true;
                break;
            }
            if (pkt == 0) break;
            BYTE* data = nullptr;
            UINT32 frames = 0;
            DWORD flags = 0;
            if (FAILED(sess.cap->GetBuffer(&data, &frames, &flags, nullptr, nullptr))) {
                broken = true;
                break;
            }
            const int sb = sess.bits / 8;
            for (UINT32 f = 0; f < frames; f++) {
                float v = 0.0f;
                if (!(flags & AUDCLNT_BUFFERFLAGS_SILENT) && data) {
                    const BYTE* p = data + (size_t)f * (size_t)sess.frameBytes;
                    v = EqReadSample(p, sess.isFloat, sess.bits);
                    if (sess.ch >= 2) v = 0.5f * (v + EqReadSample(p + sb, sess.isFloat, sess.bits));
                }
                ring[ringW] = v;
                ringW = (ringW + 1) % kFftN;
                sinceLast++;
            }
            sess.cap->ReleaseBuffer(frames);
            got = true;
        }
        if (broken) {
            InterlockedExchange(&g_eqCapOk, 0);
            EqClose(sess);
            continue;
        }

        if (got) lastData = now;

        if (sinceLast >= kFftN / 2) {
            sinceLast = 0;
            for (int i = 0; i < kFftN; i++) {
                re[i] = ring[(ringW + i) % kFftN] * hann[i];
                im[i] = 0.0f;
            }
            FftInPlace(re, im, kFftN);

            float frameMax = 0.0f;
            float val[kEqBars];
            for (int b = 0; b < kEqBars; b++) {
                const EqBand& band = bands[b];
                float sum = 0.0f;
                for (int k = band.lo; k < band.hi; k++) sum += sqrtf(re[k] * re[k] + im[k] * im[k]);
                float mag = sum / (float)std::max(1, band.hi - band.lo);
                float amp = mag / ((float)kFftN * 0.25f);
                float db = 20.0f * log10f(amp + 1e-7f);

                db += band.compensation;
                float v = (db + 75.0f) / 60.0f;
                v = v < 0.0f ? 0.0f : (v > 1.5f ? 1.5f : v);
                val[b] = v;
                if (v > frameMax) frameMax = v;
            }
            // Adapt the reference level gradually so quieter tracks still register.
            agc = std::max(frameMax, agc * 0.995f);
            float gain = 0.95f / std::max(agc, 0.35f);
            for (int b = 0; b < kEqBars; b++) {
                float v = std::min(1.0f, std::max(0.0f, val[b] * gain));
                v = v * v * (3.0f - 2.0f * v);
                live[b] = std::max(v, live[b] * 0.86f);
                g_eqLive[b].store(live[b], std::memory_order_relaxed);
            }
        } else if (!got && now - lastData > 120) {
            // WASAPI can stop delivering packets in silence. Let the bars decay on their own.
            for (int b = 0; b < kEqBars; b++) {
                live[b] *= 0.85f;
                if (live[b] < 0.004f) live[b] = 0.0f;
                g_eqLive[b].store(live[b], std::memory_order_relaxed);
            }
        }
    }

    EqClose(sess);
    en->Release();
    InterlockedExchange(&g_eqCapOk, 0);
    if (SUCCEEDED(hrCo)) CoUninitialize();
    return 0;
}

// ---------------------------------------------------------------------------
// Minimal WLAN ABI declarations for runtime-loaded functions
// ---------------------------------------------------------------------------

struct UA_WLAN_IFINFO {
    GUID guid;
    WCHAR desc[256];
    ULONG state;
};
struct UA_WLAN_IFLIST {
    DWORD n;
    DWORD reserved;
    UA_WLAN_IFINFO info[1];
};
// Keep Windows structure fields in ABI order, including the unused ones.

struct UA_WLAN_CONN {
    ULONG state;
    ULONG mode;
    WCHAR profile[256];
    ULONG ssidLen;
    UCHAR ssid[32];
    ULONG bssType;
    UCHAR mac[6];
    ULONG phyType;
    ULONG phyIdx;
    ULONG quality;
    ULONG rx;
    ULONG tx;
};

typedef DWORD(WINAPI* WlanOpenHandleFn)(DWORD, PVOID, PDWORD, PHANDLE);
typedef DWORD(WINAPI* WlanEnumInterfacesFn)(HANDLE, PVOID, void**);
typedef DWORD(WINAPI* WlanQueryInterfaceFn)(HANDLE, const GUID*, ULONG, PVOID, PDWORD, PVOID*, PULONG);
typedef VOID(WINAPI* WlanFreeMemoryFn)(PVOID);
typedef DWORD(WINAPI* WlanCloseHandleFn)(HANDLE, PVOID);

static WlanOpenHandleFn     pWlanOpen = nullptr;
static WlanEnumInterfacesFn pWlanEnum = nullptr;
static WlanQueryInterfaceFn pWlanQuery = nullptr;
static WlanFreeMemoryFn     pWlanFree = nullptr;
static WlanCloseHandleFn    pWlanClose = nullptr;
static HANDLE               g_wlan = nullptr;
static bool                 g_wlanTried = false;

// ---------------------------------------------------------------------------
// Card types, shared state, and worker messages
// ---------------------------------------------------------------------------

static const wchar_t kWndClass[] = L"WindhawkDesktopGlassCards6";
static const wchar_t kEditClass[] = L"WindhawkDesktopGlassCardsEdit6";
static constexpr wchar_t kCardOrderClass[] = L"WindhawkDesktopGlassCardsOrder";
static const wchar_t kStickyClass[] = L"WindhawkDesktopGlassCardsSticky6";
static const UINT WM_APP_RELOAD  = WM_APP + 1;
static const UINT WM_APP_WEATHER = WM_APP + 2;
static const UINT WM_APP_ICS     = WM_APP + 3;
static const UINT WM_APP_THUMB   = WM_APP + 4;
static const UINT WM_APP_META    = WM_APP + 6;   // Metadata panel data is ready.
static const UINT WM_APP_MXMETA  = WM_APP + 7;   // Album and year returned by the metadata worker.
static const UINT WM_APP_PANEL   = WM_APP + 8;
static const UINT WM_APP_EMBED   = WM_APP + 9;   // The tag write or undo has finished.
static const UINT WM_APP_METAPICK = WM_APP + 12; // The user-selected file is ready for review.
static const UINT WM_APP_DEFERRED = WM_APP + 13; // Result of a deferred MP3 operation.
static constexpr UINT WM_APP_MEDIA_CLOSED = WM_APP + 14;
static constexpr UINT WM_APP_LYRICS = WM_APP + 15;

static const int CARD_WEATHER = 0;
static const int CARD_SYSTEM = 1;
static const int CARD_DEADLINES = 2;
static const int CARD_NOTES = 3;
static const int CARD_MEDIA = 4;
static const float kClockCardWu = 372.0f;  // Card width in design units.
static const int CARD_CLOCK = 5;
static const int CARD_COUNT = 6;
static constexpr int kDefaultCardOrder[CARD_COUNT] = {CARD_WEATHER, CARD_CLOCK, CARD_SYSTEM,
                                                       CARD_MEDIA, CARD_DEADLINES, CARD_NOTES};
static int g_cardOrder[CARD_COUNT];

// Reject malformed stored orders so every card keeps a unique slot.
static bool DecodeCardOrder(const std::wstring& stored, int (&order)[CARD_COUNT]) {
    if (stored.size() != CARD_COUNT) return false;
    unsigned seen = 0;
    for (wchar_t value : stored) {
        const int id = value - L'0';
        if (id < 0 || id >= CARD_COUNT || (seen & (1u << id))) return false;
        seen |= 1u << id;
    }
    for (int i = 0; i < CARD_COUNT; ++i) order[i] = stored[i] - L'0';
    return true;
}

static std::wstring EncodeCardOrder(const int (&order)[CARD_COUNT]) {
    std::wstring stored;
    for (int id : order) stored += (wchar_t)(L'0' + id);
    return stored;
}

static int MoveCardInOrder(int (&order)[CARD_COUNT], int from, int step) {
    if (from < 0 || from >= CARD_COUNT || (step != -1 && step != 1)) return from;
    const int to = from + step;
    if (to < 0 || to >= CARD_COUNT) return from;
    std::swap(order[from], order[to]);
    return to;
}

static HANDLE g_thread = nullptr;
static HANDLE g_ready = nullptr;
static DWORD  g_threadId = 0;
static volatile LONG g_stop = 0;

// RAII guard for an exclusive SRW lock.
struct SrwGuard {
    SRWLOCK* l;
    explicit SrwGuard(SRWLOCK* x) : l(x) { AcquireSRWLockExclusive(l); }
    ~SrwGuard() { ReleaseSRWLockExclusive(l); }
};

// Workers post owned results to the UI thread, which owns g and g_meta.

struct MxMetaResult {
    std::wstring title, artist, album, year;
    unsigned long long track = 0;
};

// Validated ID3 data read from the file itself. ok confirms that the file was identified and read.

struct FileMeta {
    bool ok = false;
    std::wstring path, title, artist, album, year;
    bool coverOk = false, titleOk = false, artistOk = false, albumOk = false, yearOk = false;
    bool mine = false;
    std::vector<BYTE> cover;
};
enum class MetaCatalog { None, Apple, Deezer, MusicBrainz };
struct MetaOnlineProposal {
    std::wstring title, artist, year, album;
    MetaCatalog catalog = MetaCatalog::None;
    std::vector<BYTE> cover;
};

// Track background handles so workers finish before the module unloads.

static SRWLOCK g_bgLock = SRWLOCK_INIT;
static std::vector<HANDLE> g_bgThreads;
static HANDLE StartBgThread(LPTHREAD_START_ROUTINE fn, LPVOID p) {
    HANDLE h = CreateThread(nullptr, 0, fn, p, 0, nullptr);
    if (!h) return nullptr;
    SrwGuard lk(&g_bgLock);
    for (size_t i = 0; i < g_bgThreads.size();) {
        if (WaitForSingleObject(g_bgThreads[i], 0) == WAIT_OBJECT_0) {
            CloseHandle(g_bgThreads[i]);
            g_bgThreads.erase(g_bgThreads.begin() + (long)i);
        } else {
            i++;
        }
    }
    g_bgThreads.push_back(h);
    return h;
}
static void JoinBgThreads() {
    std::vector<HANDLE> v;
    {
        SrwGuard lk(&g_bgLock);
        v.swap(g_bgThreads);
    }
    for (size_t i = 0; i < v.size(); i++) {
        WaitForSingleObject(v[i], INFINITE);
        CloseHandle(v[i]);
    }
}

struct Disk {
    wchar_t letter;
    double totalGB;
    double freeGB;
};

static unsigned int TextHash(const std::wstring& s) {
    unsigned int h = 2166136261u;
    for (size_t i = 0; i < s.size(); i++) {
        h ^= (unsigned int)s[i];
        h *= 16777619u;
    }
    return h;
}

struct Deadline {
    int y = 0, m = 0, d = 0;
    long long dayNum = 0;
    int days = 0;
    int hh = -1, mm = -1;
    std::wstring name;
    std::wstring place;
    int repeat = 0;          // 0 none, 1 daily, 2 weekly, 3 monthly, 4 yearly
    int interval = 1;
    long long until = 0;     // last day of the repetition (0 = no end)
    std::wstring origin;     // Calendar name from X-WR-CALNAME.
    std::wstring badge;
    bool fromIcs = false;    // Imported iCalendar event.
    std::wstring tag;
};

struct Note {
    int kind = 0;  // 0 plain, 1 open task, 2 done task, 3 important
    std::wstring text;
    unsigned int hash = 0;
};

struct NetPrev {
    ULONG64 luid;
    ULONG64 in;
    ULONG64 out;
};

struct Weather {
    bool valid = false;
    double temp = 0;
    double feels = 0;
    double wind = 0;
    int humidity = 0;
    int code = 0;
    bool isDay = true;
    int days = 0;
    double dmax[7] = {0, 0, 0, 0, 0, 0, 0};
    double dmin[7] = {0, 0, 0, 0, 0, 0, 0};
    int dcode[7] = {0, 0, 0, 0, 0, 0, 0};
    int ddow[7] = {0, 0, 0, 0, 0, 0, 0};
    int dpop[7] = {0, 0, 0, 0, 0, 0, 0};
    std::wstring place;
    int version = 0;
    int rainMin = -1;
    double rainMm = 0.0;
    int uv = -1;
    int hourlyN = 0;
    double htemp[24] = {};
    int hpop[24] = {};
    int hhour[24] = {};
    int sunrise = -1;   // minutes since midnight
    int sunset = -1;
    int aqi = -1;
    int pollen = -1;
    // Official alert severity: 0 none, 1 green, 2 yellow, 3 orange, 4 red.

    int alertColor = 0;
    std::wstring alertText;
};

struct FetchJob {
    std::wstring city;
    std::string lat;
    std::string lon;
    bool fahrenheit = false;
    int lang = 0;
    int version = 0;
    bool hourly = true;
    bool air = true;
};

struct IcsSourceResult {
    std::wstring key;
    std::vector<Deadline> events;
    bool ok = false;
};

struct IcsResult {
    std::vector<IcsSourceResult> sources;
    int version = 0;
};

struct IcsJob {
    std::wstring url;
    std::wstring label;
    std::wstring noName;
    int version = 0;
};

struct Card {
    int id = 0;
    HWND win = nullptr;
    bool placed = false;
    bool dirty = true;
    int winW = 0;
    int winH = 0;
    int cardHpx = 0;
    int mPx = 0;
    float fullHu = 0.0f;       // Expanded height in design units.
    bool autoFold = false;     // Automatically collapsed to fit the work area.
    bool animating = false;    // Collapse or expand animation is active.
    bool animOpening = false;
    ULONGLONG animStart = 0;
    std::vector<DWORD> bg;
    std::vector<DWORD> bgHover;  // Lazily rendered hover surface.
    int bgW = 0;
    int bgH = 0;
    unsigned long long bgKey = 0;
};

struct Fonts {
    HFONT title, small, big, name, pill, temp, unit, desc, time, city, day, note, head;
};

struct RGBA {
    float r, g, b, a;  // non-premultiplied, 0..1
};

static inline RGBA C(float r, float g, float b, float a = 1.0f) {
    RGBA c = {r / 255.0f, g / 255.0f, b / 255.0f, a};
    return c;
}

struct Palette {
    RGBA white, soft, dimc, hl, topC, botC;
    float shadow = 0.45f;
    bool light = false;
};

struct ZoneInfo {
    std::wstring label;
    TIME_ZONE_INFORMATION tzi;
    bool ok = false;
    int flag = 0;
};

struct ProcInfo {
    std::wstring name;
    DWORD pid = 0;
    double cpu = 0;
    double ramMB = 0;
};

struct ProcPrev {
    DWORD pid;
    ULONGLONG t;
    ULONGLONG created = 0;  // Keep the creation time to detect PID reuse.
};

struct SysRow {
    int kind = 0;  // 0 bar, 1 text next to the label, 2 wide (name left, value right)
    std::wstring label;
    std::wstring value;
    float pct = 0;
    float colorPct = 0;
};

struct ThumbResult {
    int gen = 0;
    int size = 0;
    bool ok = false;
    bool fallback = false;  // Artwork obtained from the catalog or cache.
    std::wstring key, artist, title, path;
    uint64_t sourceHash = 0;  // Hash of the original thumbnail supplied by the player.
    uint64_t keyHash = 0;     // Track key hash used by the thumbnail request.
    std::vector<DWORD> px;  // Premultiplied BGRA pixels.
    std::vector<BYTE> img;  // Original JPEG or PNG used to generate the preview.
};

// Windows file identity combines the volume serial and file index. It survives a rename.

struct CvFileId {
    unsigned long long vol = 0;
    unsigned char id[16] = {0};
    bool ok = false;
    bool Same(const CvFileId& o) const {
        if (!ok || !o.ok || vol != o.vol) return false;
        for (int i = 0; i < 16; i++)
            if (id[i] != o.id[i]) return false;
        return true;
    }
};

struct MetaPanelResult {
    MetaOnlineProposal online;
    unsigned long long size = 0, time = 0;
    CvFileId fileId;
    int gen = 0;
    int dur = 0;
    std::wstring path, newTitle, newArtist, newYear, newAlbum;
    // Keep original ID3 values separate from fields proposed for column A.
    std::wstring fileTitle, fileArtist, fileYear, fileAlbum;
    std::vector<BYTE> fileImg, newImg;
    bool pathConfirmed = false; // The path, file identity, or tags tie this file to the selected track.
    bool ambiguous = false;
    int fpPct = 0;            // Acoustic fingerprint confidence. Zero means fingerprinting was not used.
};

struct MediaInfo {
    bool valid = false;
    bool paused = false, loading = false;
    bool canPrevious = false, canToggle = false, canNext = false, canSeek = false;
    bool canPlay = false, canPause = false;
    bool shuffle = false, canShuffle = false, canRepeat = false;
    int repeat = 0;
    std::wstring title;
    std::wstring artist;
    bool playing = false;
    double pos = 0;
    double dur = 0;
    std::wstring player;

    std::wstring file;
    std::wstring path;
    CvFileId id;              // Identity of the currently playing file.
    std::wstring album;
    std::wstring year;
    bool nameParsed = false;
    bool tagsOk = false;
};

// Palette colors run from the bottom of each spectrum bar to the peak.
struct EqPal {
    int n = 5;
    float stop[5] = {0.0f, 0.30f, 0.55f, 0.78f, 1.0f};
    RGBA col[5];
};

struct State {
    Card cards[CARD_COUNT];
    bool decided = false;
    bool disabled = false;
    bool paused = false;

    Card* dragCard = nullptr;
    bool dragMoved = false;
    POINT dragCursor = {0, 0};
    POINT dragAnchor = {0, 0};
    bool anchorValid = false;
    int anchorX = 0;
    int anchorY = 0;
    int stackH = 0;
    bool needStack = false;
    Card* hoverCard = nullptr;
    bool collapsed[CARD_COUNT] = {};
    bool stickyCompact = true;
    bool agendaFoldPrivate = false;
    std::wstring systemFoldSummary = L"cpuRam";
    int hourlyHover = -1;
    int processHover = -1;
    int cpuGraphHover = -1;
    float dpi = 1.0f;
    float kLast = 1.0f;

    int lastMinute = -1;
    int lastReset = 0;
    int tick = 0;
    ULONGLONG dueDisks = 0, dueCpu = 0, dueGpu = 0, dueBat = 0, dueWifi = 0, dueProcs = 0;

    // general settings
    int lang = 1;  // 0 Spanish, 1 English, 2 Catalan.
    int theme = 0; // 0 auto, 1 dark, 2 light
    bool useWinAccent = false;
    bool haveAccent = false;
    DWORD accentRaw = 0;
    RGBA accentCol = {0.35f, 0.68f, 1.0f, 1.0f};
    Palette pal;
    int scale = 100;
    int glassOpacity = 72;
    int cornerRadius = 24;
    int accent = 255;
    bool lockPosition = false;
    int monitor = 0;
    bool snap = true;
    bool pauseFs = true;
    int marginRight = 45;
    int marginTop = 32;
    int stackGap = 14;
    std::wstring calendarUrl;
    std::wstring icsUrl;
    std::wstring icsLabel;
    bool showWeather = true;
    bool showSystem = true;
    bool showMedia = true;
    bool mediaAutoHide = true;
    bool onlineCovers = true;
    EqPal eqPal;
    bool eqAccent = false; // The accent palette is resolved when drawn.
    std::vector<std::wstring> musicDirs;
    bool showClock = true;
    bool showDeadlines = true;
    bool showNotes = true;

    // weather
    std::wstring city;
    std::string lat, lon;
    bool fahrenheit = false;
    bool showDetails = true;
    bool showSunAir = true;
    bool showHourly = true;
    bool showForecast = true;
    int refreshMinutes = 15;
    int settingsVersion = 0;
    Weather weather;
    bool fetching = false;
    HANDLE fetchThread = nullptr;
    ULONGLONG nextFetch = 0;
    ULONGLONG lastOk = 0;
    SYSTEMTIME lastOkTime = {};
    bool fetchFailed = false;

    // system
    int maxDisks = 2;
    bool showGpu = true;
    bool showDisk = true;
    bool showBattery = true;
    bool showWifi = true;
    int topProcs = 5;
    bool procByRam = false;
    int sysRefresh = 1;
    double cpu = 0;
    double cpuMeter = 0;
    std::vector<std::pair<ULONGLONG, double>> hist;
    int ramPct = 0;
    double ramUsedGB = 0;
    double ramTotalGB = 0;
    std::vector<Disk> disks;
    double dlSpeed = 0;
    double ulSpeed = 0;
    std::vector<NetPrev> netPrev;
    ULONGLONG netLastTick = 0;
    int batPct = -1;
    bool batAC = false;
    std::wstring wifiSsid;
    int wifiQ = -1;
    std::vector<ProcInfo> procs;
    std::vector<ProcPrev> procPrev;
    ULONGLONG procWall = 0;

    // media
    MediaInfo media;
    unsigned int mediaSig = 0;
    std::vector<DWORD> thumbPx;
    int thumbS = 0;
    bool thumbOk = false;

    std::vector<ZoneInfo> zones;
    int pomoFocus = 25;
    int pomoBreak = 5;
    bool pomoRun = false;
    bool pomoStarted = false;
    int pomoMode = 0;  // 0 focus, 1 break
    int pomoLeft = 25 * 60;
    ULONGLONG pomoEnd = 0;
    int pomoDone = 0;

    // deadlines
    int maxDeadlines = 4;
    int notifyMin = 30;
    std::vector<Deadline> deadlines;
    std::vector<Deadline> ics;
    std::vector<std::wstring> dlRaw;
    bool icsFetching = false;
    HANDLE icsThread = nullptr;
    // Background cover lookup started by the Media card.
    ULONGLONG icsNext = 0;
    std::unordered_map<std::wstring, std::vector<Deadline>> icsBySource;
    int icsMissingSources = 0;
    bool icsFailed = false;      // Track consecutive calendar failures, last successful fetch, and event count.
    int icsFailCount = 0;
    int icsLastCount = -1;
    ULONGLONG icsLastOk = 0;
    std::vector<unsigned int> notified;

    bool stickyEditing = false;

    // notes

    // sticky note
    std::wstring stickyText;
    std::wstring stickyUndo;
    bool stickyCanUndo = false;
    int stickyLines = 7;
    int notePitch = 24;
    int localFlag = 0;
    int clockStyle = 0;

    // helper windows
    HWND msgWin = nullptr;
    bool noticeActive = false;

    // fonts
    Fonts fonts = {};
    int fontsKey = 0;
    bool fontsOk = false;
    bool modernFont = true;           // Use Segoe UI Variable when available.
    bool autoFoldOn = true;
    bool autoPin[CARD_COUNT] = {};
    int thumbSerial = 0;
    bool mediaTime = true;            // Elapsed and total time underneath the progress bar.
    bool coverAccent = true;
    bool alertDot = true;
    unsigned int alertSeen = 0;
    std::vector<BYTE> thumbImg;
    FileMeta fileMeta;
    bool fpOn = true;
    std::wstring foldHotkey;
    bool mediaLyrics = true;
    std::wstring mediaKeys[3];
    std::vector<int> autoFoldOrder;
    ULONGLONG copiedUntil = 0;
};

static State g;

static bool PostUi(UINT msg, WPARAM w, LPARAM l) {
    HWND h = g.msgWin;
    if (h && PostMessageW(h, msg, w, l)) return true;
    return g_threadId != 0 && PostThreadMessageW(g_threadId, msg, w, l) != 0;
}

static const wchar_t* TR(const wchar_t* es, const wchar_t* en, const wchar_t* ca) {
    return g.lang == 1 ? en : (g.lang == 2 ? ca : es);
}

static inline RGBA HL(float a) {
    RGBA c = g.pal.hl;
    c.a = a;
    return c;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
static std::wstring TrimWs(const std::wstring& s) {
    size_t a = 0, b = s.size();
    while (a < b && (s[a] == L' ' || s[a] == L'\t' || s[a] == L'\r' || s[a] == L'\n')) a++;
    while (b > a && (s[b - 1] == L' ' || s[b - 1] == L'\t' || s[b - 1] == L'\r' || s[b - 1] == L'\n')) b--;
    return s.substr(a, b - a);
}

static std::wstring LowerWs(const std::wstring& s) {
    std::wstring o = s;
    for (size_t i = 0; i < o.size(); i++) o[i] = (wchar_t)towlower(o[i]);
    return o;
}

static bool ContainsNoCase(const std::wstring& hay, const std::wstring& needle) {
    if (needle.empty()) return false;
    return LowerWs(hay).find(LowerWs(needle)) != std::wstring::npos;
}

static std::wstring Trim(std::wstring s) {
    while (!s.empty() && (s.front() == L' ' || s.front() == L'\t' || s.front() == L'"')) s.erase(s.begin());
    while (!s.empty() && (s.back() == L' ' || s.back() == L'\t' || s.back() == L'"')) s.pop_back();
    return s;
}

// Card geometry in design units

static_assert(true, "constantes 7.0");
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
static const float kStickyTextTop = 46.0f;
static const float kStickyClearX = 342.0f;
static const float kStickyHeaderH = 40.0f;
static const float kStickyPad = 28.0f;
static constexpr float kCardW = 372.0f;
static constexpr float kMediaInset = 18.0f;
static constexpr float kMediaRight = kCardW - kMediaInset;
static constexpr float kThumbU = 80.0f, kMediaCoverTop = 39.0f;
static constexpr float kMediaTitleX = kMediaInset + kThumbU + 12.0f;
static constexpr float kMediaTitleTop = 38.0f, kMediaTitleBottom = 58.0f;
static constexpr float kMediaEqTop = 96.0f, kMediaEqBase = 145.0f;
static constexpr float kMediaProgressY = 155.0f, kMediaProgressHit = 7.0f;
static constexpr float kMediaLyricExtraH = 26.0f, kMediaLyricCenterY = 162.0f;
static constexpr float kMediaLyricHalfH = 11.0f;
static constexpr float kMediaInfoX = kMediaRight, kMediaHeaderY = 20.0f;
static constexpr float kMediaInfoRadius = 11.0f;
static constexpr float kMediaFoldedPlayX = kMediaRight - 26.0f;
static constexpr float kMediaFoldedPlayRadius = 11.0f;
static constexpr float kMediaTransportY = 133.0f;
static constexpr float kMediaTransportX[] = {30.0f, 58.0f, 86.0f};
static constexpr float kMediaTransportRadius[] = {10.0f, 14.0f, 10.0f};
static constexpr int kMediaMetadataHover = 3, kMediaShuffleHover = 4, kMediaRepeatHover = 5;
static constexpr float kMediaShuffleX = kMediaInfoX - 48.0f, kMediaRepeatX = kMediaInfoX - 25.0f;
static constexpr float kMediaModeRadius = 10.0f;
static int g_mediaHover = -1;
static float g_mediaHoverSeek = -1.0f;
static HWND g_mediaScrubWindow = nullptr;
static int g_mediaScrubGeneration = 0;
static bool g_mediaHoverTitle = false;
static ULONGLONG g_mediaTitleHoverSince = 0;
static bool g_mediaMarqueeActive = false;
static int g_mediaVolumeText = -2;
struct LyricLine { double t; std::wstring s; };
static std::vector<LyricLine> g_lyrics;
static std::wstring g_lyrKey;
static std::wstring g_lyrAsked;
static std::atomic<bool> g_mediaKeepStopped{false};
static ULONGLONG g_mediaVolumeUntil = 0;
static int g_mediaWheelRemainder = 0;
static ULONGLONG g_mediaPressedUntil = 0;
static int g_mediaPressed = -1;
static int g_mediaFileDuration = 0;
static int g_metaGen = 0;
static ULONGLONG g_mediaCoverFadeUntil = 0;
static const float kPomoPlayX = 292.0f, kPomoResetX = 332.0f;

static const COLORREF kPaperRef = RGB(255, 236, 121);
static const COLORREF kInkRef = RGB(58, 44, 18);

static int ClampInt(int v, int lo, int hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}

static std::string ToUtf8(const std::wstring& w) {
    if (w.empty()) return std::string();
    int n = WideCharToMultiByte(CP_UTF8, 0, w.c_str(), -1, nullptr, 0, nullptr, nullptr);
    if (n <= 1) return std::string();
    std::string s((size_t)n, '\0');
    WideCharToMultiByte(CP_UTF8, 0, w.c_str(), -1, &s[0], n, nullptr, nullptr);
    s.resize((size_t)n - 1);
    return s;
}

static std::wstring FromUtf8(const std::string& s) {
    if (s.empty()) return std::wstring();
    int n = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, nullptr, 0);
    if (n <= 1) return std::wstring();
    std::wstring w((size_t)n, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, &w[0], n);
    w.resize((size_t)n - 1);
    return w;
}

static std::wstring UrlEncode(const std::wstring& in) {
    std::string u8 = ToUtf8(in);
    std::wstring out;
    wchar_t buf[8];
    for (size_t i = 0; i < u8.size(); i++) {
        unsigned char c = (unsigned char)u8[i];
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            out += (wchar_t)c;
        } else {
            wsprintfW(buf, L"%%%02X", (unsigned)c);
            out += buf;
        }
    }
    return out;
}

static std::string CleanCoordinate(const std::wstring& in) {
    std::string out;
    for (size_t i = 0; i < in.size(); i++) {
        wchar_t c = in[i];
        if ((c >= L'0' && c <= L'9') || c == L'-' || c == L'.') out += (char)c;
        else if (c == L',') out += '.';
    }
    return out;
}

static std::wstring FormatNum(double v, int dec) {
    wchar_t buf[48];
    _snwprintf(buf, 47, L"%.*f", dec, v);
    buf[47] = 0;
    std::wstring s = buf;
    if (g.lang != 1) {
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == L'.') s[i] = L',';
        }
    }
    return s;
}

static std::wstring FormatRate(double bps) {
    if (bps >= 1048576.0) return FormatNum(bps / 1048576.0, 1) + L" MB/s";
    if (bps >= 1024.0) return FormatNum(bps / 1024.0, 0) + L" KB/s";
    return FormatNum(bps, 0) + L" B/s";
}

static std::wstring FormatSize(double gb) {
    if (gb >= 1024.0) return FormatNum(gb / 1024.0, 1) + L" TB";
    return FormatNum(gb, 0) + L" GB";
}

static std::wstring HM(int minutes) {
    wchar_t b[16];
    wsprintfW(b, L"%02d:%02d", minutes / 60, minutes % 60);
    return b;
}

static const wchar_t* MonthShort(int m) {
    static const wchar_t* e[] = {L"ene", L"feb", L"mar", L"abr", L"may", L"jun",
                                 L"jul", L"ago", L"sep", L"oct", L"nov", L"dic"};
    static const wchar_t* n[] = {L"Jan", L"Feb", L"Mar", L"Apr", L"May", L"Jun",
                                 L"Jul", L"Aug", L"Sep", L"Oct", L"Nov", L"Dec"};
    static const wchar_t* c[] = {L"gen", L"feb", L"mar", L"abr", L"mai", L"jun",
                                 L"jul", L"ago", L"set", L"oct", L"nov", L"des"};
    if (m < 1 || m > 12) m = 1;
    return g.lang == 1 ? n[m - 1] : (g.lang == 2 ? c[m - 1] : e[m - 1]);
}

static const wchar_t* DowName(int d) {
    static const wchar_t* e[] = {L"dom", L"lun", L"mar", L"mi\u00E9", L"jue", L"vie", L"s\u00E1b"};
    static const wchar_t* n[] = {L"Sun", L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", L"Sat"};
    static const wchar_t* c[] = {L"dg", L"dl", L"dt", L"dc", L"dj", L"dv", L"ds"};
    if (d < 0 || d > 6) d = 0;
    return g.lang == 1 ? n[d] : (g.lang == 2 ? c[d] : e[d]);
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static long long DayNumber(int y, int m, int d) {
    SYSTEMTIME st;

    memset(&st, 0, sizeof(st));
    st.wYear = (WORD)y;
    st.wMonth = (WORD)m;
    st.wDay = (WORD)d;
    FILETIME ft;
    if (!SystemTimeToFileTime(&st, &ft)) return -1;
    ULARGE_INTEGER u;
    u.LowPart = ft.dwLowDateTime;
    u.HighPart = ft.dwHighDateTime;
    return (long long)(u.QuadPart / 864000000000ULL);
}

static void YMDFromDay(long long dn, int& y, int& m, int& d) {
    ULARGE_INTEGER u;
    u.QuadPart = (ULONGLONG)dn * 864000000000ULL;
    FILETIME ft;
    ft.dwLowDateTime = u.LowPart;
    ft.dwHighDateTime = u.HighPart;
    SYSTEMTIME st;
    if (!FileTimeToSystemTime(&ft, &st)) {
        y = 2000;
        m = 1;
        d = 1;
        return;
    }
    y = st.wYear;
    m = st.wMonth;
    d = st.wDay;
}

static int DaysInMonth(int y, int m) {
    static const int dm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) return 29;
    return dm[m - 1];
}

static long long TodayNumber() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    return DayNumber((int)st.wYear, (int)st.wMonth, (int)st.wDay);
}

static bool ApplyRepeat(Deadline& d, long long today) {
    if (d.repeat == 0) return true;
    if (d.dayNum < today) {
        int iv = std::max(1, d.interval);
        if (d.repeat == 1 || d.repeat == 2) {
            long long step = (d.repeat == 2 ? 7LL : 1LL) * (long long)iv;
            long long n = (today - d.dayNum + step - 1) / step;
            d.dayNum += n * step;
            YMDFromDay(d.dayNum, d.y, d.m, d.d);
        } else {
            int by = d.y, bm = d.m, bd = d.d;
            int stepM = (d.repeat == 3 ? 1 : 12) * iv;
            for (int k = 1; k < 3000; k++) {
                int tot = (bm - 1) + k * stepM;
                int ny = by + tot / 12;
                int nm = tot % 12 + 1;
                int nd = std::min(bd, DaysInMonth(ny, nm));
                long long dn = DayNumber(ny, nm, nd);
                if (dn >= today) {
                    d.y = ny;
                    d.m = nm;
                    d.d = nd;
                    d.dayNum = dn;
                    break;
                }
                if (ny > 2200) return false;
            }
        }
    }
    if (d.until > 0 && d.dayNum > d.until) return false;
    return true;
}

static int TakeRepeat(std::wstring& s) {
    size_t p = s.rfind(L'@');
    if (p == std::wstring::npos) return 0;
    std::wstring w = Trim(s.substr(p + 1));
    for (size_t i = 0; i < w.size(); i++) w[i] = (wchar_t)towlower(w[i]);
    int r = 0;
    if (w == L"diario" || w == L"diari" || w == L"daily") r = 1;
    else if (w == L"semanal" || w == L"setmanal" || w == L"weekly") r = 2;
    else if (w == L"mensual" || w == L"monthly") r = 3;
    else if (w == L"anual" || w == L"yearly" || w == L"annual") r = 4;
    if (!r) return 0;
    s = Trim(s.substr(0, p));
    return r;
}

static bool ParseTimePrefix(std::wstring& rest, int& hh, int& mm) {
    size_t i = 0;
    int h = 0, m = 0;
    size_t d1 = 0, d2 = 0;
    while (i < rest.size() && iswdigit(rest[i]) && d1 < 2) {
        h = h * 10 + (rest[i] - L'0');
        i++;
        d1++;
    }
    if (d1 == 0 || i >= rest.size() || rest[i] != L':') return false;
    i++;
    while (i < rest.size() && iswdigit(rest[i]) && d2 < 2) {
        m = m * 10 + (rest[i] - L'0');
        i++;
        d2++;
    }
    if (d2 != 2 || h > 23 || m > 59) return false;
    if (i < rest.size() && !iswspace(rest[i]) && rest[i] != L'h' && rest[i] != L'H') return false;

    size_t j = i;
    while (j < rest.size() && rest[j] == L' ') j++;
    if (j < rest.size() && (rest[j] == L'h' || rest[j] == L'H') &&
        (j + 1 == rest.size() || !iswalpha(rest[j + 1]))) {
        j++;
        if (j < rest.size() && rest[j] == L'.') j++;
        i = j;
    }
    hh = h;
    mm = m;
    rest = Trim(rest.substr(i));
    return true;
}

static bool ParseDeadline(const std::wstring& line, Deadline& out) {
    std::wstring s = Trim(line);
    if (s.empty()) return false;

    size_t sp = s.find_first_of(L" \t");
    std::wstring tok = (sp == std::wstring::npos) ? s : s.substr(0, sp);
    std::wstring rest = (sp == std::wstring::npos) ? L"" : Trim(s.substr(sp));

    int parts[3] = {0, 0, 0};
    int lens[3] = {0, 0, 0};
    int n = 0;
    size_t i = 0;
    while (i < tok.size() && n < 3) {
        if (!iswdigit(tok[i])) return false;
        int v = 0, len = 0;
        while (i < tok.size() && iswdigit(tok[i])) {
            v = v * 10 + (tok[i] - L'0');
            len++;
            i++;
        }
        parts[n] = v;
        lens[n] = len;
        n++;
        if (i < tok.size()) {
            wchar_t c = tok[i];
            if (c != L'/' && c != L'-' && c != L'.') return false;
            i++;
        }
    }
    if (n != 3) return false;

    int y, m, d;
    if (lens[0] == 4) {
        y = parts[0];
        m = parts[1];
        d = parts[2];
    } else {
        d = parts[0];
        m = parts[1];
        y = parts[2];
        if (y < 100) y += 2000;
    }
    if (y < 2000 || y > 2100 || m < 1 || m > 12 || d < 1 || d > 31) return false;

    long long dn = DayNumber(y, m, d);
    if (dn < 0) return false;

    out = Deadline();
    out.y = y;
    out.m = m;
    out.d = d;
    out.dayNum = dn;

    size_t hashPos = rest.find(L'#');
    if (hashPos != std::wstring::npos) {
        out.place = Trim(rest.substr(hashPos + 1));
        rest = Trim(rest.substr(0, hashPos));
    }
    out.repeat = TakeRepeat(rest);
    if (!out.repeat) out.repeat = TakeRepeat(out.place);
    while (!rest.empty() && rest.back() == L'.') rest.pop_back();

    int th = 0, tm = 0;
    const size_t first = rest.find_first_not_of(L"0123456789");
    const bool looksLikeTime = first > 0 && first <= 3 && first < rest.size() && rest[first] == L':';
    const bool hasTime = ParseTimePrefix(rest, th, tm);
    if (looksLikeTime && !hasTime) return false;
    if (hasTime) {
        out.hh = th;
        out.mm = tm;
    }
    out.name = rest.empty() ? std::wstring(TR(L"(sin nombre)", L"(no name)", L"(sense nom)")) : rest;
    return true;
}

static bool ParseNote(const std::wstring& line, Note& out) {
    std::wstring s = Trim(line);
    if (s.empty() || s[0] == L'#') return false;
    out.kind = 0;
    if (s.size() >= 3 && s[0] == L'[' && s[2] == L']') {
        wchar_t mk = s[1];
        if (mk == L'x' || mk == L'X') out.kind = 2;
        else out.kind = 1;
        s = Trim(s.substr(3));
    } else if (s[0] == L'!') {
        out.kind = 3;
        s = Trim(s.substr(1));
    }
    if (s.empty()) return false;
    out.text = s;
    return true;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static std::wstring IcsUnescape(const std::string& v) {
    std::string o;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == '\\' && i + 1 < v.size()) {
            char c = v[i + 1];
            o += (c == 'n' || c == 'N') ? ' ' : c;
            i++;
        } else {
            o += v[i];
        }
    }
    return FromUtf8(o);
}

static std::wstring CalShortName(const std::wstring& origin) {
    std::wstring s = Trim(origin);
    if (s.empty()) return s;
    size_t at = s.find(L'@');
    if (at != std::wstring::npos) s = Trim(s.substr(0, at));
    if (s.empty()) s = Trim(origin);
    return s;
}

static std::wstring OriginBadge(const std::wstring& calName, const std::wstring& label) {
    std::wstring src = label.empty() ? calName : label;
    for (size_t i = 0; i < src.size(); i++) {
        wchar_t c = src[i];
        if (c == L' ' || c == L'.' || c == L'-' || c == L'_') continue;
        if (c >= L'a' && c <= L'z') c = (wchar_t)(c - L'a' + L'A');
        return std::wstring(1, c);
    }
    return std::wstring();
}

static std::wstring IcsCalendarName(const std::string& txt) {
    size_t pos = 0;
    while (pos < txt.size()) {
        size_t e = txt.find('\n', pos);
        if (e == std::string::npos) e = txt.size();
        std::string ln = txt.substr(pos, e - pos);
        if (!ln.empty() && ln.back() == '\r') ln.pop_back();
        pos = e + 1;
        if (ln.compare(0, 13, "X-WR-CALNAME:") == 0) return Trim(IcsUnescape(ln.substr(13)));
    }
    return std::wstring();
}

// Parse iCalendar events and recurrence rules from the configured feeds.
static void ParseIcs(const std::string& txt, std::vector<Deadline>& out, const std::wstring& label,
                     const std::wstring& noName) {
    std::wstring calName = IcsCalendarName(txt);
    std::vector<std::string> lines;
    size_t pos = 0;
    while (pos < txt.size()) {
        size_t e = txt.find('\n', pos);
        if (e == std::string::npos) e = txt.size();
        std::string ln = txt.substr(pos, e - pos);
        if (!ln.empty() && ln.back() == '\r') ln.pop_back();
        pos = e + 1;
        if (!ln.empty() && (ln[0] == ' ' || ln[0] == '\t') && !lines.empty()) lines.back() += ln.substr(1);
        else lines.push_back(ln);
    }

    long long today = TodayNumber();
    bool inEv = false, haveStart = false, cancelled = false, isOverride = false;
    Deadline cur;

    for (size_t li = 0; li < lines.size(); li++) {
        const std::string& ln = lines[li];
        if (ln == "BEGIN:VEVENT") {
            inEv = true;
            cur = Deadline();
            haveStart = cancelled = isOverride = false;
            continue;
        }
        if (ln == "END:VEVENT") {
            inEv = false;
            if (haveStart && !cancelled && !isOverride) {
                if (cur.name.empty()) cur.name = noName;
                bool keep = cur.repeat ? (cur.until == 0 || cur.until >= today) : (cur.dayNum >= today - 7);
                cur.origin = calName;
                cur.badge = OriginBadge(calName, label);
                cur.fromIcs = true;
                cur.tag = CalShortName(!calName.empty() ? calName : label);
                if (keep && out.size() < 1500) out.push_back(cur);
            }
            continue;
        }
        if (!inEv) continue;

        size_t c = ln.find(':');
        if (c == std::string::npos) continue;
        std::string key = ln.substr(0, c), val = ln.substr(c + 1);
        size_t sc = key.find(';');
        std::string pname = (sc == std::string::npos) ? key : key.substr(0, sc);

        std::string tzid;
        bool allDay = false;
        if (sc != std::string::npos) {
            std::string params = key.substr(sc + 1);
            size_t t = params.find("TZID=");
            if (t != std::string::npos) {
                size_t e2 = params.find(';', t);
                tzid = params.substr(t + 5, e2 == std::string::npos ? std::string::npos : e2 - t - 5);
            }
            if (params.find("VALUE=DATE") != std::string::npos) allDay = true;
        }
        for (size_t i = 0; i < pname.size(); i++) pname[i] = (char)toupper((unsigned char)pname[i]);

        if (pname == "DTSTART") {
            if (val.size() < 8) continue;
            int y = atoi(val.substr(0, 4).c_str());
            int m = atoi(val.substr(4, 2).c_str());
            int d = atoi(val.substr(6, 2).c_str());
            int hh = -1, mi = -1;

            if (allDay) {
                cur.hh = cur.mm = -1;
            } else if (val.size() >= 13 && val[8] == 'T') {
                hh = atoi(val.substr(9, 2).c_str());
                mi = atoi(val.substr(11, 2).c_str());
                if (val[val.size() - 1] == 'Z') {
                    SYSTEMTIME u, l;
                    memset(&u, 0, sizeof(u));
                    u.wYear = (WORD)y;
                    u.wMonth = (WORD)m;
                    u.wDay = (WORD)d;
                    u.wHour = (WORD)hh;
                    u.wMinute = (WORD)mi;
                    if (SystemTimeToTzSpecificLocalTime(nullptr, &u, &l)) {
                        y = l.wYear;
                        m = l.wMonth;
                        d = l.wDay;
                        hh = l.wHour;
                        mi = l.wMinute;
                    }
                }
            }
            if (m < 1 || m > 12 || d < 1 || d > 31) continue;
            long long dn = DayNumber(y, m, d);
            if (dn < 0) continue;
            cur.y = y;
            cur.m = m;
            cur.d = d;
            cur.dayNum = dn;
            cur.hh = hh;

            cur.mm = (mi < 0) ? -1 : ((mi + 2) / 5) * 5;
            if (cur.mm >= 60) { cur.mm = 55; }
            haveStart = true;
        } else if (pname == "SUMMARY") {
            cur.name = Trim(IcsUnescape(val));
        } else if (pname == "LOCATION") {
            cur.place = Trim(IcsUnescape(val));
        } else if (pname == "STATUS") {
            if (val.find("CANCELLED") != std::string::npos) cancelled = true;
        } else if (pname == "RECURRENCE-ID") {
            isOverride = true;
        } else if (pname == "RRULE") {
            size_t p = 0;
            while (p < val.size()) {
                size_t e = val.find(';', p);
                if (e == std::string::npos) e = val.size();
                std::string part = val.substr(p, e - p);
                p = e + 1;
                if (part.compare(0, 5, "FREQ=") == 0) {
                    std::string f = part.substr(5);
                    if (f == "DAILY") cur.repeat = 1;
                    else if (f == "WEEKLY") cur.repeat = 2;
                    else if (f == "MONTHLY") cur.repeat = 3;
                    else if (f == "YEARLY") cur.repeat = 4;
                } else if (part.compare(0, 9, "INTERVAL=") == 0) {
                    cur.interval = std::max(1, atoi(part.substr(9).c_str()));
                } else if (part.compare(0, 6, "UNTIL=") == 0 && part.size() >= 14) {
                    long long un = DayNumber(atoi(part.substr(6, 4).c_str()), atoi(part.substr(10, 2).c_str()),
                                             atoi(part.substr(12, 2).c_str()));
                    if (un > 0) cur.until = un;
                }
            }
        }
    }
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static bool JsonValueStart(const std::string& js, size_t from, const char* key, size_t& pos) {
    std::string k = std::string("\"") + key + "\":";
    size_t p = js.find(k, from);
    if (p == std::string::npos) return false;
    p += k.size();
    while (p < js.size() && (js[p] == ' ' || js[p] == '\n' || js[p] == '\r' || js[p] == '\t')) p++;
    if (p >= js.size()) return false;
    pos = p;
    return true;
}

static bool JsonNumber(const std::string& js, size_t from, const char* key, std::string& out) {
    size_t p;
    if (!JsonValueStart(js, from, key, p)) return false;
    size_t e = p;
    while (e < js.size() && (isdigit((unsigned char)js[e]) || js[e] == '-' || js[e] == '+' ||
                             js[e] == '.' || js[e] == 'e' || js[e] == 'E')) {
        e++;
    }
    if (e == p) return false;
    out = js.substr(p, e - p);
    return true;
}

static bool JsonString(const std::string& js, size_t from, const char* key, std::string& out) {
    size_t p;
    if (!JsonValueStart(js, from, key, p)) return false;
    if (js[p] != '"') return false;
    p++;
    out.clear();
    while (p < js.size()) {
        char c = js[p];
        if (c == '"') return true;
        if (c == '\\' && p + 1 < js.size()) {
            char e = js[p + 1];
            p += 2;
            switch (e) {
                case 'n':  out += '\n'; break;
                case 't':  out += '\t'; break;
                case 'r':  out += '\r'; break;
                case 'b':  out += '\b'; break;
                case 'f':  out += '\f'; break;
                case 'u': {
                    if (p + 4 <= js.size()) {
                        out += '\\'; out += 'u';
                        out += js.substr(p, 4);
                        p += 4;
                    }
                    break;
                }
                default: out += e; break;
            }
            continue;
        }
        out += c;
        p++;
    }
    return true;
}
static bool JsonArray(const std::string& js, size_t from, const char* key, std::vector<std::string>& out) {
    out.clear();
    std::string k = std::string("\"") + key + "\":[";
    size_t p = js.find(k, from);
    if (p == std::string::npos) return false;
    p += k.size();
    size_t e = js.find(']', p);
    if (e == std::string::npos) return false;
    std::string cur;
    for (size_t i = p; i < e; i++) {
        char c = js[i];
        if (c == ',') {
            out.push_back(cur);
            cur.clear();
        } else if (c != '"' && c != ' ') {
            cur += c;
        }
    }
    out.push_back(cur);
    return true;
}

// ==CV-PURE-BEGIN==
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static std::wstring CvNorm(const std::wstring& s) {
    std::wstring o;
    for (size_t i = 0; i < s.size(); i++) {
        if (iswalnum((wint_t)s[i])) o += (wchar_t)towlower((wint_t)s[i]);
    }
    return o;
}

static bool CvLoose(const std::wstring& a, const std::wstring& b) {
    if (a.size() < 2 || b.size() < 2) return false;
    if (a.find(b) != std::wstring::npos || b.find(a) != std::wstring::npos) return true;

    size_t hits = 0, words = 0;
    size_t p = 0;
    while (p < b.size()) {
        if (!iswalnum((wint_t)b[p])) { p++; continue; }
        size_t st2 = p;
        while (p < b.size() && iswalnum((wint_t)b[p])) p++;
        std::wstring w = b.substr(st2, p - st2);
        if (w.size() < 3) continue;
        words++;
        if (a.find(w) != std::wstring::npos) hits++;
    }
    if (words == 0) return false;
    return hits * 3 >= words * 2;
}

static bool HasAudioExt(const std::wstring& low) {
    static const wchar_t* e[] = {L".mp3", L".m4a", L".flac", L".wav", L".ogg", L".opus",
                                 L".wma", L".aac", L".m4b", L".ape"};
    for (const wchar_t* x : e) {
        const size_t n = wcslen(x);
        if (low.size() >= n && low.compare(low.size() - n, n, x) == 0) return true;
    }
    return false;
}

static std::wstring CvStripExt(const std::wstring& text) {
    const auto dot = text.rfind(L'.');
    if (dot == std::wstring::npos || dot == 0 || !HasAudioExt(LowerWs(text))) return text;
    return text.substr(0, dot);
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static void CvFoldAppend(std::wstring& o, wchar_t ch) {
    unsigned c = (unsigned)ch;
    if (c >= 'A' && c <= 'Z') c += 32;
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) { o += (wchar_t)c; return; }
    if (c == 0xE6 || c == 0xC6) { o += L"ae"; return; }
    if (c == 0x153 || c == 0x152) { o += L"oe"; return; }
    if (c == 0xDF) { o += L"ss"; return; }
    if (c == 0xF0 || c == 0xD0) { o += L'd'; return; }
    if (c == 0xFE || c == 0xDE) { o += L"th"; return; }
    struct R { unsigned a, b; wchar_t base; };
    static const R r[] = {
        {0xC0,0xC5,L'a'}, {0xE0,0xE5,L'a'}, {0x100,0x105,L'a'},
        {0xC7,0xC7,L'c'}, {0xE7,0xE7,L'c'}, {0x106,0x10D,L'c'}, {0x10E,0x111,L'd'},
        {0xC8,0xCB,L'e'}, {0xE8,0xEB,L'e'}, {0x112,0x11B,L'e'},
        {0x11C,0x123,L'g'}, {0x124,0x127,L'h'},
        {0xCC,0xCF,L'i'}, {0xEC,0xEF,L'i'}, {0x128,0x131,L'i'},
        {0x134,0x135,L'j'}, {0x139,0x142,L'l'},
        {0xD1,0xD1,L'n'}, {0xF1,0xF1,L'n'}, {0x143,0x14B,L'n'},
        {0xD2,0xD6,L'o'}, {0xF2,0xF6,L'o'}, {0xD8,0xD8,L'o'}, {0xF8,0xF8,L'o'}, {0x14C,0x151,L'o'},
        {0x154,0x159,L'r'}, {0x15A,0x161,L's'}, {0x162,0x167,L't'},
        {0xD9,0xDC,L'u'}, {0xF9,0xFC,L'u'}, {0x168,0x173,L'u'},
        {0x174,0x175,L'w'}, {0xDD,0xDD,L'y'}, {0xFD,0xFF,L'y'}, {0x176,0x178,L'y'},
        {0x179,0x17E,L'z'}
    };
    for (size_t i = 0; i < sizeof(r) / sizeof(r[0]); i++)
        if (c >= r[i].a && c <= r[i].b) { o += r[i].base; return; }
}

static std::wstring CvNormSp(const std::wstring& s) {
    std::wstring o;
    bool sp = true;
    for (size_t i = 0; i < s.size(); i++) {
        size_t before = o.size();
        CvFoldAppend(o, s[i]);
        if (o.size() == before) { if (!sp) { o += L' '; sp = true; } }
        else sp = false;
    }
    while (!o.empty() && o.back() == L' ') o.pop_back();
    return o;
}

static std::vector<std::wstring> CvTokens(const std::wstring& s) {
    std::vector<std::wstring> v;
    std::wstring n = CvNormSp(s), cur;
    for (size_t i = 0; i <= n.size(); i++) {
        if (i == n.size() || n[i] == L' ') { if (cur.size() >= 2) v.push_back(cur); cur.clear(); }
        else cur += n[i];
    }
    return v;
}

static float CvSim(const std::wstring& a, const std::wstring& b) {
    std::wstring x = CvNorm(a), y = CvNorm(b);
    if (x.empty() || y.empty()) return 0.0f;
    if (x == y) return 1.0f;
    if (x.find(y) != std::wstring::npos || y.find(x) != std::wstring::npos) {
        float r = (float)std::min(x.size(), y.size()) / (float)std::max(x.size(), y.size());
        return 0.72f + 0.24f * r;
    }
    std::vector<std::wstring> tx = CvTokens(a), ty = CvTokens(b);
    if (tx.empty() || ty.empty()) return 0.0f;
    struct Helper {
        static float Side(const std::vector<std::wstring>& p, const std::vector<std::wstring>& q) {
            float hit = 0.0f, tot = 0.0f;
            for (size_t i = 0; i < p.size(); i++) {
                float w = (float)std::min<size_t>(p[i].size(), 6);
                tot += w;
                bool ok = false;
                for (size_t j = 0; j < q.size() && !ok; j++)
                    ok = (p[i] == q[j]) || (p[i].size() >= 4 && q[j].find(p[i]) != std::wstring::npos);
                if (ok) hit += w;
            }
            return tot > 0.0f ? hit / tot : 0.0f;
        }
    };
    return 0.95f * 0.5f * (Helper::Side(tx, ty) + Helper::Side(ty, tx));
}

static std::wstring CvSpaces(std::wstring s) {
    for (size_t i = 0; i < s.size(); i++) {
        wchar_t c = s[i];
        if (c == L'_' || c == L'\t' || c == 0x00A0) s[i] = L' ';
        else if (c == 0x2010 || c == 0x2011 || c == 0x2012 || c == 0x2013 ||
                 c == 0x2014 || c == 0x2212) s[i] = L'-';
    }
    std::wstring o;
    o.reserve(s.size());
    bool sp = false;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == L' ') { sp = true; continue; }
        if (sp && !o.empty()) o += L' ';
        sp = false;
        o += s[i];
    }
    return o;
}

static std::wstring CvSep(std::wstring s) {
    s = CvSpaces(s);
    std::wstring o;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == L'-' && i > 0 && i + 1 < s.size() && (s[i - 1] == L' ' || s[i + 1] == L' ')) {
            while (!o.empty() && o.back() == L' ') o.pop_back();
            o += L" - ";
            while (i + 1 < s.size() && s[i + 1] == L' ') i++;
        } else {
            o += s[i];
        }
    }
    if (o.find(L" - ") == std::wstring::npos) {
        size_t p = o.find(L'-');
        if (p != std::wstring::npos && p >= 2 && p + 2 < o.size() &&
            o.find(L'-', p + 1) == std::wstring::npos)
            o = o.substr(0, p) + L" - " + o.substr(p + 1);
    }
    return Trim(o);
}

static bool CvTakeTrack(std::wstring& s, int& track) {
    size_t i = 0;
    while (i < s.size() && s[i] >= L'0' && s[i] <= L'9') i++;
    if (i == 0 || i > 3) return false;
    int n = _wtoi(s.substr(0, i).c_str());
    size_t j = i;
    if (j < s.size() && s[j] == L'-' && j + 1 < s.size() && iswdigit((wint_t)s[j + 1])) {
        size_t k = j + 1;
        while (k < s.size() && iswdigit((wint_t)s[k])) k++;
        if (k - (j + 1) <= 2) { n = _wtoi(s.substr(j + 1, k - (j + 1)).c_str()); j = k; }
    }
    size_t k = j;
    while (k < s.size() && s[k] == L' ') k++;
    bool sep = false;
    if (k < s.size() && (s[k] == L'-' || s[k] == L'.')) {
        sep = true;
        k++;
        while (k < s.size() && s[k] == L' ') k++;
    }

    bool more = k < s.size() && s.find(L" - ", k) != std::wstring::npos;
    if (!sep) {

        if (k == j) return false;
        if (s[0] != L'0' && !(i == 2 && more)) return false;
    } else if (i == 3 && s[0] != L'0' && !more) {

        return false;
    }
    if (k >= s.size() || n <= 0 || n > 999) return false;
    track = n;
    s = Trim(s.substr(k));
    return true;
}

// Filename order: -1 unknown, 0 artist first, 1 title first, 2 unresolved.
static std::wstring CvCacheDir();
static bool CvReadFile(const std::wstring& p, std::vector<BYTE>& out, size_t cap);
static bool CvWriteFile(const std::wstring& p, const void* data, size_t n);

static bool CvNoArtist(const std::wstring& a);
static bool CvCoverTitleExact(const std::wstring& cand, const std::wstring& want);
static std::wstring CvJsonUnescape(const std::string& in);
static std::string CvJsonUnescapeUtf8(const std::string& in);
static bool HttpGet(const wchar_t* host, const std::wstring& path, std::string& out);
static bool CvDownload(const std::string& url8, std::vector<BYTE>& out);
static SRWLOCK g_ordLock = SRWLOCK_INIT;
static std::vector<std::pair<std::wstring, int> > g_ordMap;
static bool g_ordLoaded = false;
static HANDLE g_orderThread = nullptr;
static ULONGLONG g_orderLastTry = 0;

static std::wstring CvOrderKey(const std::wstring& a, const std::wstring& b) { return CvNorm(a) + L"|" + CvNorm(b); }

static void CvOrderLoadLocked() {
    if (g_ordLoaded) return;
    g_ordLoaded = true;
    std::wstring dir = CvCacheDir();
    if (dir.empty()) return;
    std::vector<BYTE> b;
    if (!CvReadFile(dir + L"\\order.map", b, 1u << 20) || b.empty()) return;
    std::wstring all = FromUtf8(std::string((const char*)b.data(), b.size()));
    size_t pos = 0;
    while (pos < all.size()) {
        size_t e = all.find(L'\n', pos);
        if (e == std::wstring::npos) e = all.size();
        std::wstring ln = all.substr(pos, e - pos);
        pos = e + 1;
        size_t t = ln.rfind(L'\t');
        if (t == std::wstring::npos || t + 2 != ln.size()) continue;
        int v = ln[t + 1] - L'0';
        if (v == 0 || v == 1) g_ordMap.push_back(std::make_pair(ln.substr(0, t), v));
    }
}

static int CvOrderGet(const std::wstring& a, const std::wstring& b) {
    std::wstring k = CvOrderKey(a, b);
    AcquireSRWLockExclusive(&g_ordLock);
    CvOrderLoadLocked();
    int r = -1;
    for (size_t i = 0; i < g_ordMap.size(); i++)
        if (g_ordMap[i].first == k) { r = g_ordMap[i].second; break; }
    ReleaseSRWLockExclusive(&g_ordLock);
    return r;
}

static void CvOrderSet(const std::wstring& a, const std::wstring& b, int v) {
    std::wstring k = CvOrderKey(a, b);
    AcquireSRWLockExclusive(&g_ordLock);
    CvOrderLoadLocked();
    bool found = false;
    for (size_t i = 0; i < g_ordMap.size(); i++)
        if (g_ordMap[i].first == k) { g_ordMap[i].second = v; found = true; break; }
    if (!found) g_ordMap.push_back(std::make_pair(k, v));
    if (v == 0 || v == 1) {
        std::wstring dir = CvCacheDir();
        if (!dir.empty()) {
            std::string out;
            for (size_t i = 0; i < g_ordMap.size(); i++) {
                int x = g_ordMap[i].second;
                if (x != 0 && x != 1) continue;
                out += ToUtf8(g_ordMap[i].first) + "\t" + (char)('0' + x) + "\n";
            }
            CvWriteFile(dir + L"\\order.map", out.data(), out.size());
        }
    }
    ReleaseSRWLockExclusive(&g_ordLock);
}

struct CvParsed {
    std::wstring title, artist;
    int track = 0;
    bool two = false;
    std::wstring first, second;
};

static CvParsed CvParseName(const std::wstring& name) {
    CvParsed r;
    std::wstring s = CvSep(CvStripExt(name));
    CvTakeTrack(s, r.track);
    size_t p = s.find(L" - ");
    if (p == std::wstring::npos) { r.title = Trim(s); return r; }
    std::wstring first = Trim(s.substr(0, p));
    std::wstring rest = Trim(s.substr(p + 3));
    size_t q = rest.find(L" - ");
    if (q != std::wstring::npos) {
        std::wstring mid = Trim(rest.substr(0, q));
        std::wstring last = Trim(rest.substr(q + 3));
        if (last.find(L"remix") != std::wstring::npos || last.find(L"mix") != std::wstring::npos ||
            last.find(L"version") != std::wstring::npos || last.find(L"edit") != std::wstring::npos) {
            r.artist = first;
            r.title = mid + L" (" + last + L")";
        } else {
            r.artist = mid;
            r.title = last.empty() ? first : last;
        }
        return r;
    }
    r.artist = first;
    r.title = rest.empty() ? first : rest;
    if (!rest.empty() && !first.empty()) {
        r.two = true;
        r.first = first;
        r.second = rest;
        if (CvOrderGet(first, rest) == 1) {
            r.artist = rest;
            r.title = first;
        }
    }
    return r;
}

static std::wstring CvCleanTitle(std::wstring t) {
    t = CvStripExt(t);
    for (size_t i = 0; i < t.size(); i++) {
        if (t[i] == L'_') t[i] = L' ';
    }
    std::wstring o;
    int depth = 0;
    for (size_t i = 0; i < t.size(); i++) {
        wchar_t c = t[i];
        if (c == L'(' || c == L'[') depth++;
        else if ((c == L')' || c == L']') && depth > 0) depth--;
        else if (depth == 0) o += c;
    }
    size_t i = 0;
    while (i < o.size() && iswdigit((wint_t)o[i])) i++;
    if (i > 0 && i < o.size()) {
        size_t k = i;
        bool punct = false;
        while (k < o.size() && (o[k] == L' ' || o[k] == L'.' || o[k] == L'-' || o[k] == L'_')) {
            if (o[k] != L' ') punct = true;
            k++;
        }
        if (punct && k < o.size()) o = o.substr(k);
    }
    while (!o.empty() && (o.back() == L' ' || o.back() == L'\t')) o.pop_back();
    size_t s0 = 0;
    while (s0 < o.size() && (o[s0] == L' ' || o[s0] == L'\t')) s0++;
    return o.substr(s0);
}

static std::wstring CvStripNoise(const std::wstring& in) {
    static const wchar_t* kw[] = {L"official", L"oficial", L"video", L"vídeo", L"videoclip", L"lyric",
                                  L"letra", L"audio", L"visualizer", L"hd", L"hq", L"4k", L"1080p",
                                  L"720p", L"remaster", L"clip"};
    std::wstring o;
    size_t i = 0;
    while (i < in.size()) {
        wchar_t c = in[i];
        if (c == L'(' || c == L'[') {
            wchar_t cl = (c == L'(') ? L')' : L']';
            size_t j = in.find(cl, i + 1);
            if (j != std::wstring::npos) {
                std::wstring grp = in.substr(i + 1, j - i - 1);
                for (size_t q = 0; q < grp.size(); q++) grp[q] = (wchar_t)towlower((wint_t)grp[q]);
                bool noisy = false;
                for (size_t q = 0; q < sizeof(kw) / sizeof(kw[0]) && !noisy; q++)
                    if (grp.find(kw[q]) != std::wstring::npos) noisy = true;
                if (noisy) { i = j + 1; continue; }
            }
        }
        o += c;
        i++;
    }
    std::wstring r;
    for (size_t q = 0; q < o.size(); q++) {
        if (o[q] == L' ' && !r.empty() && r.back() == L' ') continue;
        r += o[q];
    }
    while (!r.empty() && (r.back() == L' ' || r.back() == L'-')) r.pop_back();
    size_t s0 = 0;
    while (s0 < r.size() && r[s0] == L' ') s0++;
    return r.substr(s0);
}

static std::wstring CvCleanTitleExact(std::wstring t) {
    t = CvStripExt(t);
    t = CvStripNoise(t);
    for (size_t i = 0; i < t.size(); ++i) if (t[i] == L'_') t[i] = L' ';
    t = Trim(t);
    size_t i = 0;
    while (i < t.size() && iswdigit((wint_t)t[i])) ++i;
    if (i > 0 && i < t.size()) {
        size_t k = i;
        bool punct = false;
        while (k < t.size() && (t[k] == L' ' || t[k] == L'.' || t[k] == L'-' || t[k] == L'_')) {
            if (t[k] != L' ') punct = true;
            ++k;
        }
        if (punct && k < t.size()) t = t.substr(k);
    }
    return Trim(t);
}

static std::wstring CvCoreTitle(std::wstring t) {
    t = CvCleanTitle(t);
    static const wchar_t* suffixes[] = {
        L" extended version", L" extended mix", L" radio version", L" radio edit",
        L" single version", L" album version", L" acoustic version", L" live version",
        L" club mix", L" dance mix", L" instrumental version", L" instrumental",
        L" remastered", L" remixed", L" remix", L" edit", L" version", L" mix", L" live"
    };
    bool changed = true;
    while (changed) {
        changed = false;
        std::wstring low = t;
        for (size_t i = 0; i < low.size(); i++) low[i] = (wchar_t)towlower((wint_t)low[i]);
        for (size_t k = 0; k < sizeof(suffixes) / sizeof(suffixes[0]); k++) {
            size_t n = std::wstring(suffixes[k]).size();
            if (low.size() > n && low.compare(low.size() - n, n, suffixes[k]) == 0) {
                t.resize(t.size() - n);
                while (!t.empty() && (t.back() == L' ' || t.back() == L'-' || t.back() == L'_')) t.pop_back();
                changed = true;
                break;
            }
        }
    }
    return t;
}

static std::wstring CvPrimaryArtist(const std::wstring& a) {
    std::wstring low = a;
    for (size_t i = 0; i < low.size(); i++) low[i] = (wchar_t)towlower((wint_t)low[i]);
    static const wchar_t* seps[] = {L",", L";", L"/", L" feat", L" ft.", L" ft ", L" & ", L" featuring ", L" with ", L" x "};
    size_t cut = a.size();
    for (size_t k = 0; k < sizeof(seps) / sizeof(seps[0]); k++) {
        size_t p = low.find(seps[k]);
        if (p != std::wstring::npos && p > 0 && p < cut) cut = p;
    }
    std::wstring r = a.substr(0, cut);
    while (!r.empty() && (r.back() == L' ' || r.back() == L'\t')) r.pop_back();
    size_t s0 = 0;
    while (s0 < r.size() && (r[s0] == L' ' || r[s0] == L'\t')) s0++;
    return r.substr(s0);
}

static volatile LONG g_soloArtista = 0;
static std::wstring g_soloNombre;

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
struct CvSoloTitulo {
    std::wstring artista;
    std::string url;
    int fuentes = 0;
    bool discordan = false;
};

static void CvSoloApuntar(CvSoloTitulo& r, const std::wstring& a, const std::string& u) {
    if (CvNoArtist(a)) return;
    std::wstring pa = CvNormSp(CvPrimaryArtist(a));
    if (pa.empty()) return;
    if (r.artista.empty()) {
        r.artista = CvPrimaryArtist(a);
        r.url = u;
        r.fuentes = 1;
        return;
    }
    if (CvNormSp(CvPrimaryArtist(r.artista)) == pa) {
        if (r.url.empty() && !u.empty()) r.url = u;
        r.fuentes++;
    } else {
        r.discordan = true;
    }
}

static void CvSoloItunes(const std::string& js, const std::wstring& title, CvSoloTitulo& r) {
    const std::string tag = "{\"wrapperType\"";
    size_t pos = js.find(tag);
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        std::string tn, an, au;
        if (JsonString(ch, 0, "trackName", tn) && JsonString(ch, 0, "artistName", an) &&
            JsonString(ch, 0, "artworkUrl100", au) && CvCoverTitleExact(CvJsonUnescape(tn), title)) {
            std::string u = CvJsonUnescapeUtf8(au);
            size_t p = u.find("100x100bb");
            if (p != std::string::npos) u.replace(p, 9, "600x600bb");
            CvSoloApuntar(r, CvJsonUnescape(an), u);
        }
        pos = nx;
    }
}

static void CvSoloDeezer(const std::string& js, const std::wstring& title, CvSoloTitulo& r) {
    const std::string tag = "\"readable\":";
    size_t pos = js.find(tag);
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        std::string tn, an, cu;
        if (JsonString(ch, 0, "title", tn) && JsonString(ch, 0, "name", an) &&
            JsonString(ch, 0, "cover_big", cu) && CvCoverTitleExact(CvJsonUnescape(tn), title)) {
            CvSoloApuntar(r, CvJsonUnescape(an), CvJsonUnescapeUtf8(cu));
        }
        pos = nx;
    }
}

static void CvSoloTheAudioDb(const std::string& js, const std::wstring& title, CvSoloTitulo& r) {
    const std::string tag = "\"strTrack\":";
    size_t pos = js.find(tag);
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        std::string tn, an, url;
        if (JsonString(ch, 0, "strTrack", tn)) {
            JsonString(ch, 0, "strArtist", an);
            JsonString(ch, 0, "strTrackThumb", url);
            if (url.empty()) JsonString(ch, 0, "strAlbumThumb", url);
            if (CvCoverTitleExact(CvJsonUnescape(tn), title))
                CvSoloApuntar(r, CvJsonUnescape(an), CvJsonUnescapeUtf8(url));
        }
        pos = nx;
    }
}

static int CvSoloTituloCover(const std::wstring& title, std::vector<BYTE>& out) {
    if (g_stop || title.empty()) return -1;
    CvSoloTitulo r;
    bool reach = false;
    std::string js;

    std::wstring t8 = UrlEncode(title);
    if (HttpGet(L"itunes.apple.com", L"/search?term=" + t8 + L"&media=music&entity=song&limit=25", js)) {
        reach = true;
        CvSoloItunes(js, title, r);
    }
    if (g_stop) return -1;
    js.clear();
    if (HttpGet(L"api.deezer.com", L"/search?q=" + UrlEncode(L"track:\"" + title + L"\"") + L"&limit=25", js)) {
        reach = true;
        CvSoloDeezer(js, title, r);
    }
    if (g_stop) return -1;
    js.clear();
    if (HttpGet(L"theaudiodb.com", L"/api/v1/json/2/searchtrack.php?s=&t=" + t8, js)) {
        reach = true;
        CvSoloTheAudioDb(js, title, r);
    }
    if (!reach) return -1;
    if (r.discordan || r.artista.empty()) {
        Wh_Log(L"Empotrar: '%s' sin interprete; las fuentes no coinciden, no se usa portada", title.c_str());
        return 0;
    }
    Wh_Log(L"Empotrar: '%s' resuelto como '%s' por %d fuente(s)", title.c_str(), r.artista.c_str(), r.fuentes);
    if (!r.url.empty() && CvDownload(r.url, out)) return 1;

    InterlockedExchange(&g_soloArtista, 1);
    { std::wstring tmp = r.artista; g_soloNombre = tmp; }
    return 0;
}

static bool CvNoArtist(const std::wstring& a) {
    if (a.empty()) return true;
    std::wstring n = CvNorm(a);
    return n.empty() || n == L"unknown" || n == L"desconocido" || n == L"desconegut" ||
           n == L"varios" || n == L"various" || n == L"variousartists";
}

static void CvSplitQuery(const std::wstring& artist, const std::wstring& title, std::wstring& outA,
                         std::wstring& outT) {
    bool hayArtista = !CvNoArtist(artist);
    bool hayTitulo = !title.empty();
    if (hayArtista && hayTitulo) {
        outA = CvPrimaryArtist(artist);
        outT = CvCleanTitleExact(title);
        return;
    }

    CvParsed pn = CvParseName(title.empty() ? artist : title);
    if (hayTitulo) {
        outT = CvCleanTitleExact(title);
        outA = pn.artist;
        return;
    }
    if (hayArtista) {
        outA = CvPrimaryArtist(artist);
        outT = pn.title.empty() ? CvCoreTitle(title.empty() ? artist : title) : pn.title;
        return;
    }
    outA = pn.artist;
    outT = pn.title.empty() ? CvCoreTitle(title.empty() ? artist : title) : pn.title;
}
static bool CvTitleOk(const std::wstring& cand, const std::wstring& want) {
    return CvLoose(CvNorm(CvCoreTitle(cand)), CvNorm(CvCoreTitle(want)));
}

static bool CvCoverTitleExact(const std::wstring& cand, const std::wstring& want) {
    if (cand.empty() || want.empty()) return false;
    return CvNormSp(CvCleanTitleExact(cand)) == CvNormSp(CvCleanTitleExact(want));
}

static bool CvCoverArtistExact(const std::wstring& cand, const std::wstring& want) {
    if (CvNoArtist(cand) || CvNoArtist(want)) return false;
    return CvNormSp(CvPrimaryArtist(cand)) == CvNormSp(CvPrimaryArtist(want));
}

static bool CvArtistOk(const std::wstring& cand, const std::wstring& want) {
    if (want.empty()) return true;
    return CvLoose(CvNorm(CvPrimaryArtist(cand)), CvNorm(want));
}

static void CvAppendUtf8(std::string& o, unsigned cp) {
    if (cp < 0x80) {
        o += (char)cp;
    } else if (cp < 0x800) {
        o += (char)(0xC0 | (cp >> 6));
        o += (char)(0x80 | (cp & 0x3F));
    } else if (cp < 0x10000) {
        o += (char)(0xE0 | (cp >> 12));
        o += (char)(0x80 | ((cp >> 6) & 0x3F));
        o += (char)(0x80 | (cp & 0x3F));
    } else {
        o += (char)(0xF0 | (cp >> 18));
        o += (char)(0x80 | ((cp >> 12) & 0x3F));
        o += (char)(0x80 | ((cp >> 6) & 0x3F));
        o += (char)(0x80 | (cp & 0x3F));
    }
}

static std::string CvJsonUnescapeUtf8(const std::string& in) {
    std::string o;
    for (size_t i = 0; i < in.size(); i++) {
        char c = in[i];
        if (c != '\\' || i + 1 >= in.size()) {
            o += c;
            continue;
        }
        char n = in[++i];
        switch (n) {
            case 'n': o += ' '; break;
            case 't': o += ' '; break;
            case 'r': break;
            case 'b': case 'f': break;
            case 'u': {
                if (i + 4 >= in.size()) break;
                unsigned cp = (unsigned)strtoul(in.substr(i + 1, 4).c_str(), nullptr, 16);
                i += 4;
                if (cp >= 0xD800 && cp < 0xDC00 && i + 6 < in.size() && in[i + 1] == '\\' && in[i + 2] == 'u') {
                    unsigned lo = (unsigned)strtoul(in.substr(i + 3, 4).c_str(), nullptr, 16);
                    if (lo >= 0xDC00 && lo < 0xE000) {
                        cp = 0x10000 + ((cp - 0xD800) << 10) + (lo - 0xDC00);
                        i += 6;
                    }
                }
                CvAppendUtf8(o, cp);
                break;
            }
            default: o += n; break;
        }
    }
    return o;
}

static std::wstring CvJsonUnescape(const std::string& in) { return FromUtf8(CvJsonUnescapeUtf8(in)); }

static bool CvPickItunes(const std::string& js, const std::wstring& artist, const std::wstring& title,
                         std::string& url) {

    const std::string tag = "{\"wrapperType\"";
    size_t pos = js.find(tag);
    std::string best;
    int bestTracks = 9999;
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        std::string tn, an, au;
        if (JsonString(ch, 0, "trackName", tn) && JsonString(ch, 0, "artworkUrl100", au)) {
            JsonString(ch, 0, "artistName", an);
            if (CvCoverTitleExact(CvJsonUnescape(tn), title) && CvCoverArtistExact(CvJsonUnescape(an), artist)) {
                int tracks = 9999;
                size_t tc = ch.find("\"trackCount\":");
                if (tc != std::string::npos) tracks = atoi(ch.c_str() + tc + 13);
                if (tracks < bestTracks) {
                    bestTracks = tracks;
                    best = au;
                }
            }
        }
        pos = nx;
    }
    if (best.empty()) return false;
    url = CvJsonUnescapeUtf8(best);
    size_t p = url.find("100x100bb");
    if (p != std::string::npos) url.replace(p, 9, "600x600bb");
    Wh_Log(L"Empotrar: iTunes, disco de %d pista(s)", bestTracks);
    return true;
}

static bool CvPickDeezer(const std::string& js, const std::wstring& artist, const std::wstring& title,
                         std::string& url) {

    const std::string tag = "\"readable\":";
    size_t pos = js.find(tag);
    std::string best;
    int bestTracks = 9999;
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        std::string tn, an, cu;
        if (JsonString(ch, 0, "title", tn) && JsonString(ch, 0, "cover_big", cu)) {
            JsonString(ch, 0, "name", an);
            if (CvCoverTitleExact(CvJsonUnescape(tn), title) && CvCoverArtistExact(CvJsonUnescape(an), artist)) {
                int tracks = 9999;
                size_t tc = ch.find("\"nb_tracks\":");
                if (tc != std::string::npos) tracks = atoi(ch.c_str() + tc + 12);
                if (tracks < bestTracks) {
                    bestTracks = tracks;
                    best = cu;
                }
            }
        }
        pos = nx;
    }
    if (best.empty()) return false;
    url = CvJsonUnescapeUtf8(best);
    Wh_Log(L"Empotrar: Deezer, disco de %d pista(s)", bestTracks);
    return true;
}

// ID3v2 tag parsing and APIC cover frames

struct Id3Info {
    bool hasTag = false;
    bool unsupported = false;
    int ver = 3;
    size_t tagSize = 0;
    size_t framesEnd = 0;
    bool hasApic = false;
    bool hasApicBroken = false;
    int  apicType = 0;
    size_t apicBytes = 0;
    uint64_t apicHash = 0;
    unsigned apicCount = 0;
    std::wstring title, artist, album;
    std::wstring comment;
    std::wstring gcid;
    std::wstring year;
    std::wstring yearNew;
    std::wstring albumNew;
};

static inline unsigned CvSynchsafe(const BYTE* p) {
    return ((unsigned)(p[0] & 0x7F) << 21) | ((unsigned)(p[1] & 0x7F) << 14) | ((unsigned)(p[2] & 0x7F) << 7) |
           (unsigned)(p[3] & 0x7F);
}
static inline void CvPutSynchsafe(BYTE* p, unsigned v) {
    p[0] = (BYTE)((v >> 21) & 0x7F);
    p[1] = (BYTE)((v >> 14) & 0x7F);
    p[2] = (BYTE)((v >> 7) & 0x7F);
    p[3] = (BYTE)(v & 0x7F);
}
static inline unsigned CvBE32(const BYTE* p) {
    return ((unsigned)p[0] << 24) | ((unsigned)p[1] << 16) | ((unsigned)p[2] << 8) | (unsigned)p[3];
}

static std::wstring Id3Text(const BYTE* d, size_t n) {
    std::wstring o;
    if (n < 2) return o;
    int enc = d[0];
    const BYTE* p = d + 1;
    size_t m = n - 1;
    if (enc == 0) {
        for (size_t i = 0; i < m && p[i]; i++) o += (wchar_t)p[i];
    } else if (enc == 1 || enc == 2) {
        bool be = (enc == 2);
        size_t i = 0;
        if (enc == 1 && m >= 2) {
            if (p[0] == 0xFE && p[1] == 0xFF) { be = true; i = 2; }
            else if (p[0] == 0xFF && p[1] == 0xFE) { be = false; i = 2; }
        }
        for (; i + 1 < m; i += 2) {
            unsigned u = be ? (((unsigned)p[i] << 8) | p[i + 1]) : (((unsigned)p[i + 1] << 8) | p[i]);
            if (u == 0) break;
            o += (wchar_t)u;
        }
    } else if (enc == 3) {
        size_t len = 0;
        while (len < m && p[len]) len++;
        o = FromUtf8(std::string(reinterpret_cast<const char*>(p), len));
    }
    return o;
}

static std::wstring Id3CommentText(const BYTE* c, size_t cn) {
    if (!c || cn <= 4) return std::wstring();
    const int enc = c[0];
    size_t p = 4;
    if (enc == 1 || enc == 2) {
        while (p + 1 < cn && !(c[p] == 0 && c[p + 1] == 0)) p += 2;
        p += 2;
    } else {
        while (p < cn && c[p] != 0) ++p;
        ++p;
    }
    if (p >= cn) return std::wstring();
    std::vector<BYTE> tmp;
    tmp.push_back((BYTE)enc);
    tmp.insert(tmp.end(), c + p, c + cn);
    return Id3Text(tmp.data(), tmp.size());
}

static void Id3ReadHeader(const BYTE* h, size_t n, Id3Info& info) {
    info = Id3Info();
    if (n < 10 || memcmp(h, "ID3", 3) != 0) return;
    info.hasTag = true;
    info.ver = h[3];
    unsigned flags = h[5];
    for (int i = 6; i < 10; i++) {
        if (h[i] & 0x80) info.unsupported = true;
    }
    info.tagSize = CvSynchsafe(h + 6);
    if (info.ver != 3 && info.ver != 4) info.unsupported = true;
    if (flags & 0x80) info.unsupported = true;
    if (flags & 0x40) info.unsupported = true;
    if (info.ver == 4 && (flags & 0x10)) info.unsupported = true;
    if (info.tagSize > 64u * 1024u * 1024u) info.unsupported = true;
}

static bool CvApicHasImage(const BYTE* body, size_t n, int& imgType, size_t& imgOff) {
    imgType = 0;
    imgOff = 0;
    if (!body || n < 5) return false;
    const BYTE enc = body[0];
    if (enc > 3) return false;

    size_t p = 1;

    while (p < n && body[p] != 0) ++p;
    if (p >= n) return false;
    ++p;
    if (p >= n) return false;
    ++p;

    if (enc == 1 || enc == 2) {
        bool found = false;
        while (p + 1 < n) {
            if (body[p] == 0 && body[p + 1] == 0) {
                p += 2;
                found = true;
                break;
            }
            p += 2;
        }
        if (!found) return false;
    } else {
        while (p < n && body[p] != 0) ++p;
        if (p >= n) return false;
        ++p;
    }

    if (p + 4 > n) return false;
    if (body[p] == 0xFF && body[p + 1] == 0xD8 && body[p + 2] == 0xFF) imgType = 1;
    else if (body[p] == 0x89 && body[p + 1] == 0x50 &&
             body[p + 2] == 0x4E && body[p + 3] == 0x47) imgType = 2;
    else return false;
    imgOff = p;
    return true;
}

static uint64_t CvHashBytes(const BYTE* data, size_t size) {
    uint64_t h = 14695981039346656037ULL;
    for (size_t i = 0; i < size; ++i) {
        h ^= data[i];
        h *= 1099511628211ULL;
    }
    return h;
}

static void Id3ParseFrames(const BYTE* tag, size_t n, Id3Info& info) {
    size_t pos = 0;
    while (pos + 10 <= n) {
        if (tag[pos] == 0) break;
        unsigned sz = (info.ver == 4) ? CvSynchsafe(tag + pos + 4) : CvBE32(tag + pos + 4);
        if (sz == 0 || (size_t)sz > n - pos - 10) {
            info.unsupported = true;
            return;
        }
        const BYTE* fr = tag + pos;

        bool special = (fr[9] & (info.ver == 4 ? 0x4F : 0xE0)) != 0;
        if (memcmp(fr, "APIC", 4) == 0) {

            int t2 = 0;
            size_t off2 = 0;
            if (!special && CvApicHasImage(fr + 10, sz, t2, off2)) {
                const size_t imageBytes = (size_t)sz - off2;
                const uint64_t imageHash = CvHashBytes(fr + 10 + off2, imageBytes);
                if (info.apicCount == 0) {
                    info.apicType = t2;
                    info.apicBytes = imageBytes;
                    info.apicHash = imageHash;
                }
                ++info.apicCount;
                info.hasApic = true;
            } else {
                info.hasApicBroken = true;
            }
        } else if (!special && memcmp(fr, "TIT2", 4) == 0) {
            info.title = Id3Text(fr + 10, sz);
        } else if (!special && memcmp(fr, "TPE1", 4) == 0) {
            info.artist = Id3Text(fr + 10, sz);
        } else if (!special && memcmp(fr, "TALB", 4) == 0) {
            info.album = Id3Text(fr + 10, sz);
        } else if (!special && (memcmp(fr, "TYER", 4) == 0 || memcmp(fr, "TDRC", 4) == 0)) {
            info.year = Id3Text(fr + 10, sz);
        } else if (!special && memcmp(fr, "COMM", 4) == 0) {

            std::wstring commentText = Id3CommentText(fr + 10, sz);
            if (!commentText.empty()) {
                info.comment = commentText;
                if (commentText.compare(0, 5, L"GCID:") == 0) info.gcid = commentText;
            }
        }
        pos += 10 + (size_t)sz;
    }
    info.framesEnd = pos;
    for (size_t i = pos; i < n; i++) {
        if (tag[i] != 0) {
            info.unsupported = true;
            return;
        }
    }
}

static void Id3AddTextFrame(std::vector<BYTE>& out, int ver, const char* id,
                            const std::wstring& value) {
    if (value.empty()) return;
    std::vector<BYTE> body;
    if (ver == 4) {

        std::string u8 = ToUtf8(value);
        body.push_back(3);
        body.insert(body.end(), u8.begin(), u8.end());
        body.push_back(0);
    } else {

        body.push_back(1);
        body.push_back(0xFF);
        body.push_back(0xFE);
        for (size_t i = 0; i < value.size(); ++i) {
            unsigned short ch = (unsigned short)value[i];
            body.push_back((BYTE)(ch & 0xFF));
            body.push_back((BYTE)(ch >> 8));
        }
        body.push_back(0);
        body.push_back(0);
    }
    size_t fh = out.size();
    out.resize(fh + 10, 0);
    memcpy(&out[fh], id, 4);
    if (ver == 4) {
        CvPutSynchsafe(&out[fh + 4], (unsigned)body.size());
    } else {
        out[fh + 4] = (BYTE)(body.size() >> 24);
        out[fh + 5] = (BYTE)(body.size() >> 16);
        out[fh + 6] = (BYTE)(body.size() >> 8);
        out[fh + 7] = (BYTE)body.size();
    }
    out.insert(out.end(), body.begin(), body.end());
}

static std::vector<BYTE> Id3BuildWithCover(const Id3Info& info, const BYTE* tag, const BYTE* img,
                                           size_t imgN, int imgType, bool addCover = true,
                                           const std::wstring& comment = std::wstring()) {
    const char* mime = (imgType == 2) ? "image/png" : "image/jpeg";
    int ver = info.hasTag ? info.ver : 3;
    size_t keep = info.hasTag ? info.framesEnd : 0;

    std::vector<BYTE> body;
    if (addCover) {
        body.push_back(0);
        for (const char* m = mime; *m; m++) body.push_back((BYTE)*m);
        body.push_back(0);
        body.push_back(3);
        body.push_back(0);
        body.insert(body.end(), img, img + imgN);
    }

    std::vector<BYTE> out;
    out.push_back('I'); out.push_back('D'); out.push_back('3');
    out.push_back((BYTE)ver); out.push_back(0); out.push_back(0);
    out.resize(10, 0);

    if (keep) {
        size_t p = 0;
        while (p + 10 <= keep) {
            if (tag[p] == 0) break;
            unsigned fsz = (ver == 4) ? CvSynchsafe(tag + p + 4) : CvBE32(tag + p + 4);
            size_t full = 10 + (size_t)fsz;
            if (fsz == 0 || p + full > keep) break;
            bool dropTitle = memcmp(tag + p, "TIT2", 4) == 0 && !info.title.empty();
            bool dropArtist = memcmp(tag + p, "TPE1", 4) == 0 && !info.artist.empty();
            bool dropAlbum = !info.albumNew.empty() && memcmp(tag + p, "TALB", 4) == 0;
            bool dropCover = addCover && memcmp(tag + p, "APIC", 4) == 0;
            bool dropYear = !info.yearNew.empty() &&
                            (memcmp(tag + p, "TYER", 4) == 0 || memcmp(tag + p, "TDRC", 4) == 0);

            bool dropComment = !comment.empty() && memcmp(tag + p, "COMM", 4) == 0 &&
                               Id3CommentText(tag + p + 10, fsz).compare(0, 5, L"GCID:") == 0;
            bool drop = dropTitle || dropArtist || dropAlbum || dropCover || dropYear || dropComment;
            if (!drop) out.insert(out.end(), tag + p, tag + p + full);
            p += full;
        }
    }

    if (!info.title.empty()) Id3AddTextFrame(out, ver, "TIT2", info.title);
    if (!info.artist.empty()) Id3AddTextFrame(out, ver, "TPE1", info.artist);
    if (!info.albumNew.empty()) Id3AddTextFrame(out, ver, "TALB", info.albumNew);
    if (!info.yearNew.empty()) Id3AddTextFrame(out, ver, ver == 4 ? "TDRC" : "TYER", info.yearNew);
    if (!comment.empty()) {

        std::vector<BYTE> apicBody;
        if (ver == 4) {
            std::string u8 = ToUtf8(comment);
            apicBody.push_back(3);
            apicBody.push_back('X'); apicBody.push_back('X'); apicBody.push_back('X');
            apicBody.push_back(0);
            apicBody.insert(apicBody.end(), u8.begin(), u8.end());
            apicBody.push_back(0);
        } else {
            apicBody.push_back(1);
            apicBody.push_back('X'); apicBody.push_back('X'); apicBody.push_back('X');
            apicBody.push_back(0); apicBody.push_back(0);
            apicBody.push_back(0xFF); apicBody.push_back(0xFE);
            for (size_t i = 0; i < comment.size(); ++i) {
                unsigned short ch = (unsigned short)comment[i];
                apicBody.push_back((BYTE)(ch & 0xFF));
                apicBody.push_back((BYTE)(ch >> 8));
            }
            apicBody.push_back(0); apicBody.push_back(0);
        }
        size_t fh2 = out.size();
        out.resize(fh2 + 10, 0);
        memcpy(&out[fh2], "COMM", 4);
        if (ver == 4) {
            CvPutSynchsafe(&out[fh2 + 4], (unsigned)apicBody.size());
        } else {
            out[fh2 + 4] = (BYTE)(apicBody.size() >> 24);
            out[fh2 + 5] = (BYTE)(apicBody.size() >> 16);
            out[fh2 + 6] = (BYTE)(apicBody.size() >> 8);
            out[fh2 + 7] = (BYTE)apicBody.size();
        }
        out.insert(out.end(), apicBody.begin(), apicBody.end());
    }

    if (addCover) {
        size_t fh = out.size();
        out.resize(fh + 10, 0);
        memcpy(&out[fh], "APIC", 4);
        if (ver == 4) {
            CvPutSynchsafe(&out[fh + 4], (unsigned)body.size());
        } else {
            out[fh + 4] = (BYTE)(body.size() >> 24);
            out[fh + 5] = (BYTE)(body.size() >> 16);
            out[fh + 6] = (BYTE)(body.size() >> 8);
            out[fh + 7] = (BYTE)body.size();
        }
        out.insert(out.end(), body.begin(), body.end());
    }

    size_t total = out.size() - 10;
    if (total >= (1u << 28)) return std::vector<BYTE>();
    CvPutSynchsafe(&out[6], (unsigned)total);
    return out;
}

static long long AbsMinutes(const std::string& ts) {
    if (ts.size() < 16) return -1;
    long long dn = DayNumber(atoi(ts.substr(0, 4).c_str()), atoi(ts.substr(5, 2).c_str()),
                             atoi(ts.substr(8, 2).c_str()));
    if (dn < 0) return -1;
    return dn * 1440 + atoi(ts.substr(11, 2).c_str()) * 60 + atoi(ts.substr(14, 2).c_str());
}

static int MinuteOfDay(const std::string& ts) {
    if (ts.size() < 16) return -1;
    return atoi(ts.substr(11, 2).c_str()) * 60 + atoi(ts.substr(14, 2).c_str());
}

static int DayOfWeekFromDate(const std::string& s) {
    if (s.size() < 10) return 0;
    int y = atoi(s.substr(0, 4).c_str());
    int m = atoi(s.substr(5, 2).c_str());
    int d = atoi(s.substr(8, 2).c_str());
    if (m < 1 || m > 12) return 0;
    static const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3) y -= 1;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static bool HttpGetEx(const std::wstring& host, INTERNET_PORT port, bool secure, const std::wstring& path,
                      std::string& out, size_t cap, bool allowRedirects = true) {
    out.clear();
    if (g_stop) return false;

    HINTERNET ses = WinHttpOpen(GC_HTTP_AGENT_W, WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
                                WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!ses) {
        ses = WinHttpOpen(GC_HTTP_AGENT_W, WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                          WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    }
    if (!ses) return false;

    WinHttpSetTimeouts(ses, 4000, 4000, 4000, 6000);

    bool ok = false;
    HINTERNET con = WinHttpConnect(ses, host.c_str(), port, 0);
    if (con && !g_stop) {
        HINTERNET req = WinHttpOpenRequest(con, L"GET", path.c_str(), nullptr, WINHTTP_NO_REFERER,
                                           WINHTTP_DEFAULT_ACCEPT_TYPES, secure ? WINHTTP_FLAG_SECURE : 0);
        if (req) {
            // Prevent credentialed requests from following a redirect.
            DWORD disabledFeatures = WINHTTP_DISABLE_REDIRECTS;
            if ((allowRedirects || WinHttpSetOption(req, WINHTTP_OPTION_DISABLE_FEATURE,
                                                   &disabledFeatures, sizeof(disabledFeatures))) &&
                WinHttpSendRequest(req, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0) &&
                WinHttpReceiveResponse(req, nullptr)) {
                DWORD status = 0;
                DWORD sz = sizeof(status);
                WinHttpQueryHeaders(req, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                                    WINHTTP_HEADER_NAME_BY_INDEX, &status, &sz, WINHTTP_NO_HEADER_INDEX);
                if (status == 200) {
                    DWORD avail = 0;
                    bool tooBig = false;
                    while (!g_stop && WinHttpQueryDataAvailable(req, &avail) && avail > 0) {
                        std::string buf((size_t)avail, '\0');
                        DWORD rd = 0;
                        if (!WinHttpReadData(req, &buf[0], avail, &rd)) break;
                        out.append(buf.data(), rd);
                        if (out.size() > cap) {
                            tooBig = true;
                            break;
                        }
                    }
                    ok = !out.empty() && !g_stop && !tooBig;
                } else {
                    Wh_Log(L"HTTP status %lu", status);
                }
            } else {
                Wh_Log(L"HTTP request failed (error %lu)", GetLastError());
            }
            WinHttpCloseHandle(req);
        }
    }
    if (con) WinHttpCloseHandle(con);
    WinHttpCloseHandle(ses);
    return ok;
}

static bool HttpGet(const wchar_t* host, const std::wstring& path, std::string& out) {
    return HttpGetEx(host, INTERNET_DEFAULT_HTTPS_PORT, true, path, out, 4u << 20);
}

static bool HttpGetUrl(std::wstring url, std::string& out) {
    if (url.compare(0, 9, L"webcal://") == 0) url = L"https://" + url.substr(9);
    URL_COMPONENTS uc;
    memset(&uc, 0, sizeof(uc));
    uc.dwStructSize = sizeof(uc);
    uc.dwSchemeLength = (DWORD)-1;
    uc.dwHostNameLength = (DWORD)-1;
    uc.dwUrlPathLength = (DWORD)-1;
    uc.dwExtraInfoLength = (DWORD)-1;
    if (!WinHttpCrackUrl(url.c_str(), (DWORD)url.size(), 0, &uc)) return false;
    if (!uc.lpszHostName || uc.dwHostNameLength == 0) return false;
    std::wstring host(uc.lpszHostName, uc.dwHostNameLength);
    std::wstring path;
    if (uc.lpszUrlPath) path.assign(uc.lpszUrlPath, uc.dwUrlPathLength);
    if (uc.lpszExtraInfo) path.append(uc.lpszExtraInfo, uc.dwExtraInfoLength);
    if (path.empty()) path = L"/";
    bool secure = (uc.nScheme == INTERNET_SCHEME_HTTPS);
    return HttpGetEx(host, uc.nPort, secure, path, out, 6u << 20);
}

static bool DoFetch(const FetchJob& job, Weather& out) {
    std::string lat = job.lat;
    std::string lon = job.lon;
    std::wstring place = job.city;
    std::wstring lang = job.lang == 1 ? L"en" : (job.lang == 2 ? L"ca" : L"es");

    if (lat.empty() || lon.empty()) {
        if (job.city.empty()) {
            Wh_Log(L"No city or coordinates configured");
            return false;
        }

        static std::wstring cCity, cLang, cName;
        static std::string cLat, cLon;

        if (cCity == job.city && cLang == lang && !cLat.empty() && !cLon.empty()) {
            lat = cLat;
            lon = cLon;
            place = cName;
        } else {
            std::wstring path = L"/v1/search?name=" + UrlEncode(job.city) +
                                L"&count=1&format=json&language=" + lang;
            std::string js;
            if (!HttpGet(L"geocoding-api.open-meteo.com", path, js)) return false;

            size_t r = js.find("\"results\"");
            if (r == std::string::npos) {
                Wh_Log(L"City not found: %s (try latitude/longitude instead)", job.city.c_str());
                return false;
            }
            std::string nm;
            if (!JsonNumber(js, r, "latitude", lat) || !JsonNumber(js, r, "longitude", lon)) {
                Wh_Log(L"Could not read coordinates from the geocoding response");
                return false;
            }
            if (JsonString(js, r, "name", nm)) place = FromUtf8(nm);

            cCity = job.city;
            cLang = lang;
            cName = place;
            cLat = lat;
            cLon = lon;
        }
    }

    std::wstring path =
        L"/v1/forecast?latitude=" + FromUtf8(lat) + L"&longitude=" + FromUtf8(lon) +
        L"&current=temperature_2m,apparent_temperature,relative_humidity_2m,wind_speed_10m,"
        L"weather_code,is_day"
        L"&daily=weather_code,temperature_2m_max,temperature_2m_min,precipitation_probability_max,"
        L"uv_index_max,sunrise,sunset"
        L"&minutely_15=precipitation" +
        std::wstring(job.hourly ? L"&hourly=temperature_2m,precipitation_probability" : L"") +
        L"&forecast_days=7&alerts=yes"
        L"&timezone=auto&temperature_unit=" +
        std::wstring(job.fahrenheit ? L"fahrenheit" : L"celsius") + L"&wind_speed_unit=" +
        std::wstring(job.fahrenheit ? L"mph" : L"kmh");

    std::string js;
    if (!HttpGet(L"api.open-meteo.com", path, js)) return false;

    size_t cur = js.find("\"current\":{");
    if (cur == std::string::npos) {
        Wh_Log(L"Unexpected forecast response");
        return false;
    }

    std::string t, f, c, d, h, w;
    if (!JsonNumber(js, cur, "temperature_2m", t) || !JsonNumber(js, cur, "weather_code", c)) {
        Wh_Log(L"Could not read the current weather");
        return false;
    }
    if (!JsonNumber(js, cur, "apparent_temperature", f)) f = t;
    if (!JsonNumber(js, cur, "is_day", d)) d = "1";
    if (!JsonNumber(js, cur, "relative_humidity_2m", h)) h = "0";
    if (!JsonNumber(js, cur, "wind_speed_10m", w)) w = "0";

    out = Weather();
    out.valid = true;

    out.temp = strtod(t.c_str(), nullptr);
    out.feels = strtod(f.c_str(), nullptr);
    out.humidity = atoi(h.c_str());
    out.wind = strtod(w.c_str(), nullptr);
    out.code = atoi(c.c_str());
    out.isDay = atoi(d.c_str()) != 0;
    out.place = place;
    out.version = job.version;

    std::string curTime;
    long long nowAbs = JsonString(js, cur, "time", curTime) ? AbsMinutes(curTime) : -1;

    size_t m15 = js.find("\"minutely_15\":{");
    if (m15 != std::string::npos && nowAbs >= 0) {
        std::vector<std::string> mins, precs;
        if (JsonArray(js, m15, "time", mins) && JsonArray(js, m15, "precipitation", precs)) {
            double mm = 0.0;
            for (size_t i = 0; i < mins.size() && i < precs.size(); i++) {
                long long a = AbsMinutes(mins[i]);
                if (a < 0) continue;
                long long diff = a - nowAbs;
                if (diff < 0 || diff > 90) continue;
                double val = strtod(precs[i].c_str(), nullptr);
                if (val > 0.0 && out.rainMin < 0) out.rainMin = (int)diff;
                if (diff < 60) mm += val;
            }
            out.rainMm = mm;
        }
    }

    if (job.hourly) {
        size_t hp = js.find("\"hourly\":{");
        if (hp != std::string::npos) {
            std::vector<std::string> ht, tt, pp;
            if (JsonArray(js, hp, "time", ht) && JsonArray(js, hp, "temperature_2m", tt)) {
                bool hasP = JsonArray(js, hp, "precipitation_probability", pp);
                size_t start = 0;
                if (nowAbs >= 0) {
                    for (start = 0; start < ht.size(); start++) {
                        long long a = AbsMinutes(ht[start]);
                        if (a > nowAbs - 60) break;
                    }
                }
                int n = 0;
                for (size_t i = start; i < ht.size() && i < tt.size() && n < 24; i++, n++) {
                    out.htemp[n] = strtod(tt[i].c_str(), nullptr);
                    out.hpop[n] = (hasP && i < pp.size()) ? atoi(pp[i].c_str()) : 0;
                    out.hhour[n] = ht[i].size() >= 13 ? atoi(ht[i].substr(11, 2).c_str()) : 0;
                }
                out.hourlyN = n;
            }
        }
    }

    size_t dly = js.find("\"daily\":{");
    if (dly != std::string::npos) {
        std::vector<std::string> uvs, sr, ss;
        if (JsonArray(js, dly, "uv_index_max", uvs) && !uvs.empty())
            out.uv = (int)floor(strtod(uvs[0].c_str(), nullptr) + 0.5);
        if (JsonArray(js, dly, "sunrise", sr) && !sr.empty()) out.sunrise = MinuteOfDay(sr[0]);
        if (JsonArray(js, dly, "sunset", ss) && !ss.empty()) out.sunset = MinuteOfDay(ss[0]);

        std::vector<std::string> times, codes, tmax, tmin, pop;
        if (JsonArray(js, dly, "time", times) && JsonArray(js, dly, "weather_code", codes) &&
            JsonArray(js, dly, "temperature_2m_max", tmax) &&
            JsonArray(js, dly, "temperature_2m_min", tmin)) {
            bool hasPop = JsonArray(js, dly, "precipitation_probability_max", pop);
            size_t n = times.size();
            if (codes.size() < n) n = codes.size();
            if (tmax.size() < n) n = tmax.size();
            if (tmin.size() < n) n = tmin.size();
            if (n > 7) n = 7;
            for (size_t i = 0; i < n; i++) {
                out.dcode[i] = atoi(codes[i].c_str());
                out.dmax[i] = strtod(tmax[i].c_str(), nullptr);
                out.dmin[i] = strtod(tmin[i].c_str(), nullptr);
                out.ddow[i] = DayOfWeekFromDate(times[i]);
                out.dpop[i] = (hasPop && i < pop.size()) ? atoi(pop[i].c_str()) : 0;
            }
            out.days = (int)n;
        }
    }

    {
        size_t al = js.find("\"alerts\":[");
        if (al != std::string::npos) {
            std::string ev, sev;
            if (JsonString(js, al, "event", ev)) {
                JsonString(js, al, "severity", sev);
                std::wstring wev = FromUtf8(ev);
                std::wstring wsev = FromUtf8(sev);

                std::wstring juntas = wsev + L" " + wev;
                for (size_t i = 0; i < juntas.size(); i++) juntas[i] = (wchar_t)towlower((wint_t)juntas[i]);
                int col = 2;
                if (juntas.find(L"verde") != std::wstring::npos || juntas.find(L"green") != std::wstring::npos ||
                    juntas.find(L"minor") != std::wstring::npos || juntas.find(L"leve") != std::wstring::npos)
                    col = 1;
                else if (juntas.find(L"naranja") != std::wstring::npos || juntas.find(L"orange") != std::wstring::npos ||
                         juntas.find(L"severe") != std::wstring::npos || juntas.find(L"grave") != std::wstring::npos)
                    col = 3;
                else if (juntas.find(L"roja") != std::wstring::npos || juntas.find(L"rojo") != std::wstring::npos ||
                         juntas.find(L"red") != std::wstring::npos || juntas.find(L"extreme") != std::wstring::npos ||
                         juntas.find(L"extrema") != std::wstring::npos ||
                         (juntas.find(L"warning") != std::wstring::npos &&
                          juntas.find(L"moderate") == std::wstring::npos))
                    col = 4;
                out.alertColor = col;
                out.alertText = wev.empty() ? TR(L"Aviso meteorol\u00F3gico", L"Weather warning",
                                                 L"Av\u00EDs meteorol\u00F2gic")
                                            : wev;
                Wh_Log(L"Alertas: '%s' gravedad '%s' -> color %d", out.alertText.c_str(), wsev.c_str(), col);
            }
        }
    }

    if (job.air && !g_stop) {
        std::wstring p2 =
            L"/v1/air-quality?latitude=" + FromUtf8(lat) + L"&longitude=" + FromUtf8(lon) +
            L"&current=european_aqi,alder_pollen,birch_pollen,grass_pollen,mugwort_pollen,"
            L"olive_pollen,ragweed_pollen&timezone=auto";
        std::string js2;
        if (HttpGet(L"air-quality-api.open-meteo.com", p2, js2)) {
            size_t c2 = js2.find("\"current\":{");
            if (c2 != std::string::npos) {
                std::string v;
                if (JsonNumber(js2, c2, "european_aqi", v)) out.aqi = (int)floor(strtod(v.c_str(), nullptr) + 0.5);
                static const char* keys[] = {"alder_pollen", "birch_pollen", "grass_pollen",
                                             "mugwort_pollen", "olive_pollen", "ragweed_pollen"};
                double best = -1.0;
                for (int i = 0; i < 6; i++) {
                    if (JsonNumber(js2, c2, keys[i], v)) best = std::max(best, strtod(v.c_str(), nullptr));
                }
                if (best >= 0.0) out.pollen = (int)floor(best + 0.5);
            }
        }
    }
    return true;
}

// Fetch weather in the background and report the result to the UI.
static DWORD WINAPI FetchThread(LPVOID param) {
    FetchJob* job = static_cast<FetchJob*>(param);
    Weather* w = new Weather();
    bool ok = DoFetch(*job, *w);
    delete job;
    if (!PostUi(WM_APP_WEATHER, ok ? 1 : 0, (LPARAM)w)) {
        delete w;
    }
    return 0;
}

static void StartFetch() {
    FetchJob* job = new FetchJob();
    job->city = g.city;
    job->lat = g.lat;
    job->lon = g.lon;
    job->fahrenheit = g.fahrenheit;
    job->lang = g.lang;
    job->version = g.settingsVersion;
    job->hourly = g.showHourly;
    job->air = g.showSunAir;

    g.fetchThread = CreateThread(nullptr, 0, FetchThread, job, 0, nullptr);
    if (!g.fetchThread) {
        delete job;
        g.nextFetch = GetTickCount64() + 60000;
        return;
    }
    g.fetching = true;
}

// Combine imported calendars off the UI thread.
static DWORD WINAPI IcsThread(LPVOID param) {
    IcsJob* job = static_cast<IcsJob*>(param);
    IcsResult* res = new IcsResult();
    res->version = job->version;

    bool ok = false;
    {
        std::vector<std::wstring> srcs;
        std::wstring cur;
        for (size_t i = 0; i <= job->url.size(); i++) {
            wchar_t c = i < job->url.size() ? job->url[i] : L' ';
            if (c == L' ' || c == L'\t' || c == L'\r' || c == L'\n' || c == L'|') {
                if (!cur.empty()) srcs.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }
        for (size_t i = 0; i < srcs.size() && !g_stop; i++) {
            std::wstring u = srcs[i];
            std::string body;
            bool got = false;
            bool remote = u.compare(0, 7, L"http://") == 0 || u.compare(0, 8, L"https://") == 0 ||
                          u.compare(0, 9, L"webcal://") == 0 || u.compare(0, 10, L"webcals://") == 0;
            if (remote) {
                if (u.compare(0, 10, L"webcals://") == 0) u = L"https://" + u.substr(10);
                got = HttpGetUrl(u, body);
            } else {
                if (u.compare(0, 8, L"file:///") == 0) u = u.substr(8);
                for (size_t q = 0; q < u.size(); q++) if (u[q] == L'/') u[q] = L'\\';
                std::vector<BYTE> raw;
                if (CvReadFile(u, raw, 8u << 20) && !raw.empty()) {
                    body.assign((const char*)raw.data(), raw.size());
                    got = true;
                }
            }
            IcsSourceResult source;
            source.key = srcs[i];
            source.ok = got && body.find("BEGIN:VCALENDAR") != std::string::npos &&
                               body.find("END:VCALENDAR") != std::string::npos;
            if (source.ok) {
                ParseIcs(body, source.events, job->label, job->noName);
                ok = true;
            }
            res->sources.push_back(std::move(source));
        }
    }
    delete job;
    if (!PostUi(WM_APP_ICS, ok ? 1 : 0, (LPARAM)res)) {
        delete res;
    }
    return 0;
}

static void StartIcsFetch() {
    IcsJob* job = new IcsJob();
    job->url = g.icsUrl;
    job->label = g.icsLabel;
    job->noName = TR(L"(sin nombre)", L"(no name)", L"(sense nom)");
    job->version = g.settingsVersion;
    g.icsThread = CreateThread(nullptr, 0, IcsThread, job, 0, nullptr);
    if (!g.icsThread) {
        delete job;
        g.icsNext = GetTickCount64() + 300000;
        return;
    }
    g.icsFetching = true;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static const wchar_t* DescribeText(int code) {
    switch (code) {
        case 0: return TR(L"Despejado", L"Clear", L"Despejat");
        case 1: return TR(L"Mayormente despejado", L"Mostly clear", L"Majorit\u00E0riament seren");
        case 2: return TR(L"Parcialmente nublado", L"Partly cloudy", L"Parcialment ennuvolat");
        case 3: return TR(L"Nublado", L"Overcast", L"Ennuvolat");
        case 45:
        case 48: return TR(L"Niebla", L"Fog", L"Boira");
        case 51:
        case 53:
        case 55: return TR(L"Llovizna", L"Drizzle", L"Plugim");
        case 56:
        case 57: return TR(L"Llovizna helada", L"Freezing drizzle", L"Plugim gelat");
        case 61: return TR(L"Lluvia d\u00E9bil", L"Light rain", L"Pluja feble");
        case 63: return TR(L"Lluvia", L"Rain", L"Pluja");
        case 65: return TR(L"Lluvia fuerte", L"Heavy rain", L"Pluja forta");
        case 66:
        case 67: return TR(L"Lluvia helada", L"Freezing rain", L"Pluja gelada");
        case 71: return TR(L"Nieve d\u00E9bil", L"Light snow", L"Neu feble");
        case 73: return TR(L"Nieve", L"Snow", L"Neu");
        case 75: return TR(L"Nieve fuerte", L"Heavy snow", L"Neu forta");
        case 77: return TR(L"Nieve en grano", L"Snow grains", L"Neu en gra");
        case 80:
        case 81:
        case 82: return TR(L"Chubascos", L"Rain showers", L"Ruixats");
        case 85:
        case 86: return TR(L"Chubascos de nieve", L"Snow showers", L"Ruixats de neu");
        case 95: return TR(L"Tormenta", L"Thunderstorm", L"Tempesta");
        case 96:
        case 99: return TR(L"Tormenta con granizo", L"Thunderstorm with hail", L"Tempesta amb calamarsa");
        default: return TR(L"Desconocido", L"Unknown", L"Desconegut");
    }
}

static const wchar_t* AqiText(int a) {
    if (a < 20) return TR(L"buena", L"good", L"bona");
    if (a < 40) return TR(L"aceptable", L"fair", L"acceptable");
    if (a < 60) return TR(L"moderada", L"moderate", L"moderada");
    if (a < 80) return TR(L"mala", L"poor", L"dolenta");
    return TR(L"muy mala", L"very poor", L"molt dolenta");
}

static const wchar_t* PollenText(int p) {
    if (p < 1) return TR(L"nulo", L"none", L"nul");
    if (p < 20) return TR(L"bajo", L"low", L"baix");
    if (p < 100) return TR(L"moderado", L"moderate", L"moderat");
    return TR(L"alto", L"high", L"alt");
}

enum Kind { K_CLEAR, K_PARTLY, K_CLOUD, K_FOG, K_DRIZZLE, K_RAIN, K_SNOW, K_THUNDER };

static Kind KindFromCode(int c) {
    if (c == 0 || c == 1) return K_CLEAR;
    if (c == 2) return K_PARTLY;
    if (c == 3) return K_CLOUD;
    if (c == 45 || c == 48) return K_FOG;
    if (c >= 51 && c <= 57) return K_DRIZZLE;
    if ((c >= 61 && c <= 67) || (c >= 80 && c <= 82)) return K_RAIN;
    if ((c >= 71 && c <= 77) || c == 85 || c == 86) return K_SNOW;
    if (c >= 95) return K_THUNDER;
    return K_CLOUD;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static ULONGLONG FileTimeToU64(const FILETIME& f) {
    ULARGE_INTEGER u;
    u.LowPart = f.dwLowDateTime;
    u.HighPart = f.dwHighDateTime;
    return (ULONGLONG)u.QuadPart;
}

static double EaseCpuMeter(double displayed, double measured) {
    const double delta = measured - displayed;
    return std::abs(delta) <= 0.22 ? measured : displayed + delta * 0.32;
}

static void SampleCpu(ULONGLONG now) {
    static ULONGLONG pIdle = 0, pKernel = 0, pUser = 0;
    static bool have = false;
    static ULONGLONG lastSample = 0;

    FILETIME fi, fk, fu;
    if (!GetSystemTimes(&fi, &fk, &fu)) return;
    ULONGLONG i = FileTimeToU64(fi);
    ULONGLONG k = FileTimeToU64(fk);
    ULONGLONG u = FileTimeToU64(fu);

    if (have && now - lastSample <= 2500 && i >= pIdle && k >= pKernel && u >= pUser) {
        ULONGLONG di = i - pIdle;
        ULONGLONG dk = k - pKernel;
        ULONGLONG du = u - pUser;
        ULONGLONG total = dk + du;
        if (total > 0) {
            const double busy = (double)(total - std::min(total, di)) * 100.0 / (double)total;
            if (g.hist.empty() || now - g.hist.back().first > 2500) g.cpuMeter = busy;
            g.cpu = busy;
            g.hist.emplace_back(now, busy);
            while (now - g.hist.front().first > 60000ULL) g.hist.erase(g.hist.begin());
        }
    }
    pIdle = i;
    pKernel = k;
    pUser = u;
    lastSample = now;
    have = true;
}

static void SampleMemory() {
    MEMORYSTATUSEX ms;
    memset(&ms, 0, sizeof(ms));
    ms.dwLength = sizeof(ms);
    if (!GlobalMemoryStatusEx(&ms)) return;
    const double gb = 1024.0 * 1024.0 * 1024.0;
    g.ramPct = (int)ms.dwMemoryLoad;
    g.ramTotalGB = (double)ms.ullTotalPhys / gb;
    g.ramUsedGB = (double)(ms.ullTotalPhys - ms.ullAvailPhys) / gb;
}

static void SampleDisks() {
    g.disks.clear();
    DWORD mask = GetLogicalDrives();
    const double gb = 1024.0 * 1024.0 * 1024.0;
    for (int i = 0; i < 26; i++) {
        if ((int)g.disks.size() >= g.maxDisks) break;
        if (!(mask & (1u << i))) continue;
        wchar_t root[4] = {(wchar_t)(L'A' + i), L':', L'\\', 0};
        if (GetDriveTypeW(root) != DRIVE_FIXED) continue;
        ULARGE_INTEGER freeB, totalB, totalFree;
        if (GetDiskFreeSpaceExW(root, &freeB, &totalB, &totalFree) && totalB.QuadPart > 0) {
            Disk d;
            d.letter = root[0];
            d.totalGB = (double)totalB.QuadPart / gb;
            d.freeGB = (double)totalFree.QuadPart / gb;
            g.disks.push_back(d);
        }
    }
}

static void SampleNetwork() {
    LoadNetApi();
    if (!pGetIfTable2 || !pFreeMibTable) {
        g.dlSpeed = 0.0;
        g.ulSpeed = 0.0;
        return;
    }

    UA_MIB_IF_TABLE2* tbl = nullptr;
    if (pGetIfTable2(&tbl) != NO_ERROR || !tbl) return;

    ULONGLONG now = GetTickCount64();
    double dt = g.netLastTick ? (double)(now - g.netLastTick) / 1000.0 : 0.0;

    std::vector<NetPrev> cur;
    double inBytes = 0.0, outBytes = 0.0;

    for (ULONG i = 0; i < tbl->NumEntries; i++) {
        const UA_MIB_IF_ROW2& r = tbl->Table[i];
        if (!r.InterfaceAndOperStatusFlags.HardwareInterface) continue;
        if (r.OperStatus != IfOperStatusUp) continue;

        NetPrev np;
        np.luid = r.InterfaceLuid.Value;
        np.in = r.InOctets;
        np.out = r.OutOctets;
        cur.push_back(np);

        for (size_t j = 0; j < g.netPrev.size(); j++) {
            if (g.netPrev[j].luid == np.luid) {
                if (np.in >= g.netPrev[j].in) inBytes += (double)(np.in - g.netPrev[j].in);
                if (np.out >= g.netPrev[j].out) outBytes += (double)(np.out - g.netPrev[j].out);
                break;
            }
        }
    }

    pFreeMibTable(tbl);

    if (dt > 0.2) {
        g.dlSpeed = inBytes / dt;
        g.ulSpeed = outBytes / dt;
    }
    g.netPrev = cur;
    g.netLastTick = now;
}

static PDH_HQUERY   g_gpuQ = nullptr;
static PDH_HCOUNTER g_gpuC = nullptr;
static double       g_gpu = -1.0;
static bool         g_gpuTried = false;

static void InitGpu() {
    if (PdhOpenQueryW(nullptr, 0, &g_gpuQ) != ERROR_SUCCESS) {
        g_gpuQ = nullptr;
        return;
    }
    if (PdhAddEnglishCounterW(g_gpuQ, L"\\GPU Engine(*)\\Utilization Percentage", 0, &g_gpuC) !=
        ERROR_SUCCESS) {
        PdhCloseQuery(g_gpuQ);
        g_gpuQ = nullptr;
        g_gpuC = nullptr;
        return;
    }
    PdhCollectQueryData(g_gpuQ);
}

static double BusiestGpuEngine(const PDH_FMT_COUNTERVALUE_ITEM_W* items, DWORD count) {
    std::vector<std::pair<std::wstring, double>> engines;
    for (DWORD i = 0; i < count; ++i) {
        const auto& sample = items[i].FmtValue;
        if (sample.CStatus != PDH_CSTATUS_VALID_DATA && sample.CStatus != PDH_CSTATUS_NEW_DATA) continue;
        if (!items[i].szName || !std::isfinite(sample.doubleValue) || sample.doubleValue < 0.0) continue;
        const std::wstring name = items[i].szName;
        const size_t adapter = name.find(L"luid_");
        if (adapter == std::wstring::npos) continue;
        const size_t kind = name.find(L"_engtype_", adapter);
        if (kind == std::wstring::npos) continue;
        const auto engine = name.substr(adapter, kind - adapter);
        const auto entry = std::find_if(engines.begin(), engines.end(),
            [&](const auto& item) { return item.first == engine; });
        if (entry == engines.end()) engines.emplace_back(engine, sample.doubleValue);
        else entry->second += sample.doubleValue;
    }
    if (engines.empty()) return -1.0;
    double busiest = 0.0;
    for (const auto& engine : engines) busiest = std::max(busiest, engine.second);
    return std::clamp(busiest, 0.0, 100.0);
}

static void SampleGpu() {
    g_gpu = -1.0;
    if (!g_gpuQ) return;
    if (PdhCollectQueryData(g_gpuQ) != ERROR_SUCCESS) return;

    DWORD bytes = 0, count = 0;
    PDH_STATUS s = PdhGetFormattedCounterArrayW(g_gpuC, PDH_FMT_DOUBLE, &bytes, &count, nullptr);
    if (s != (PDH_STATUS)PDH_MORE_DATA || bytes == 0) return;

    std::vector<BYTE> buf(bytes);
    PDH_FMT_COUNTERVALUE_ITEM_W* items = reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(buf.data());
    if (PdhGetFormattedCounterArrayW(g_gpuC, PDH_FMT_DOUBLE, &bytes, &count, items) != ERROR_SUCCESS)
        return;

    g_gpu = BusiestGpuEngine(items, count);
}

static void CloseGpu() {
    if (g_gpuQ) {
        PdhCloseQuery(g_gpuQ);
        g_gpuQ = nullptr;
        g_gpuC = nullptr;
    }
}

static PDH_HQUERY   g_dskQ = nullptr;
static PDH_HCOUNTER g_dskC = nullptr;
static double       g_dsk = -1.0;
static bool         g_dskTried = false;
static ULONGLONG    g_dueDsk = 0;

static void InitDiskActivity() {
    if (PdhOpenQueryW(nullptr, 0, &g_dskQ) != ERROR_SUCCESS) {
        g_dskQ = nullptr;
        return;
    }
    if (PdhAddEnglishCounterW(g_dskQ, L"\\PhysicalDisk(_Total)\\% Idle Time", 0, &g_dskC) != ERROR_SUCCESS) {
        PdhCloseQuery(g_dskQ);
        g_dskQ = nullptr;
        g_dskC = nullptr;
        return;
    }
    PdhCollectQueryData(g_dskQ);
}

static void SampleDiskActivity() {
    g_dsk = -1.0;
    if (!g_dskQ) return;
    if (PdhCollectQueryData(g_dskQ) != ERROR_SUCCESS) return;
    PDH_FMT_COUNTERVALUE v;
    memset(&v, 0, sizeof(v));
    if (PdhGetFormattedCounterValue(g_dskC, PDH_FMT_DOUBLE, nullptr, &v) != ERROR_SUCCESS) return;
    if (v.CStatus != PDH_CSTATUS_VALID_DATA && v.CStatus != PDH_CSTATUS_NEW_DATA) return;
    if (!std::isfinite(v.doubleValue)) return;
    g_dsk = std::clamp(100.0 - v.doubleValue, 0.0, 100.0);
}

static void CloseDiskActivity() {
    if (g_dskQ) {
        PdhCloseQuery(g_dskQ);
        g_dskQ = nullptr;
        g_dskC = nullptr;
    }
}

static void SampleBattery() {
    SYSTEM_POWER_STATUS sps;
    if (GetSystemPowerStatus(&sps) && sps.BatteryFlag != 128 && sps.BatteryLifePercent <= 100) {
        g.batPct = (int)sps.BatteryLifePercent;
        g.batAC = (sps.ACLineStatus == 1);
    } else {
        g.batPct = -1;
    }
}

static void SampleWifi() {
    g.wifiSsid.clear();
    g.wifiQ = -1;
    if (!g_wlanTried) {
        g_wlanTried = true;
        HMODULE m = LoadLibraryW(L"wlanapi.dll");
        if (m) {
            pWlanOpen = (WlanOpenHandleFn)GetProcAddress(m, "WlanOpenHandle");
            pWlanEnum = (WlanEnumInterfacesFn)GetProcAddress(m, "WlanEnumInterfaces");
            pWlanQuery = (WlanQueryInterfaceFn)GetProcAddress(m, "WlanQueryInterface");
            pWlanFree = (WlanFreeMemoryFn)GetProcAddress(m, "WlanFreeMemory");
            pWlanClose = (WlanCloseHandleFn)GetProcAddress(m, "WlanCloseHandle");
            DWORD ver = 0;
            if (pWlanOpen && pWlanOpen(2, nullptr, &ver, &g_wlan) != 0) g_wlan = nullptr;
        }
    }
    if (!g_wlan || !pWlanEnum || !pWlanQuery || !pWlanFree) return;

    void* lp = nullptr;
    if (pWlanEnum(g_wlan, nullptr, &lp) != 0 || !lp) return;
    UA_WLAN_IFLIST* l = reinterpret_cast<UA_WLAN_IFLIST*>(lp);
    for (DWORD i = 0; i < l->n && g.wifiSsid.empty(); i++) {
        PVOID data = nullptr;
        DWORD sz = 0;
        if (pWlanQuery(g_wlan, &l->info[i].guid, 7, nullptr, &sz, &data, nullptr) == 0 && data) {
            UA_WLAN_CONN* cn = reinterpret_cast<UA_WLAN_CONN*>(data);
            if (cn->state == 1 && cn->ssidLen > 0 && cn->ssidLen <= 32) {
                g.wifiSsid = FromUtf8(std::string(reinterpret_cast<char*>(cn->ssid), cn->ssidLen));
                g.wifiQ = (int)cn->quality;
            }
            pWlanFree(data);
        }
    }
    pWlanFree(lp);
}

static void CloseWifi() {
    if (g_wlan && pWlanClose) pWlanClose(g_wlan, nullptr);
    g_wlan = nullptr;
}

static std::wstring ProcDescription(const std::wstring& path) {
    static std::vector<std::pair<std::wstring, std::wstring> > cache;
    for (size_t i = 0; i < cache.size(); i++)
        if (cache[i].first == path) return cache[i].second;
    std::wstring out;
    DWORD dummy = 0;
    DWORD sz = path.empty() ? 0 : GetFileVersionInfoSizeW(path.c_str(), &dummy);
    if (sz > 0 && sz < (1u << 20)) {
        std::vector<BYTE> buf(sz);
        if (GetFileVersionInfoW(path.c_str(), 0, sz, buf.data())) {
            struct LangCp { WORD lang; WORD cp; };
            LangCp* tr = nullptr;
            UINT n = 0;
            if (VerQueryValueW(buf.data(), L"\\VarFileInfo\\Translation", reinterpret_cast<LPVOID*>(&tr), &n) &&
                tr && n >= sizeof(LangCp)) {
                wchar_t sub[80];
                wsprintfW(sub, L"\\StringFileInfo\\%04x%04x\\FileDescription", (unsigned)tr[0].lang,
                          (unsigned)tr[0].cp);
                wchar_t* v = nullptr;
                UINT vn = 0;
                if (VerQueryValueW(buf.data(), sub, reinterpret_cast<LPVOID*>(&v), &vn) && v && vn > 1) out = v;
            }
        }
    }

    static const wchar_t* pre[] = {L"Microsoft ", L"Google ", L"Windows ", L"Host Process for ", L"Host de "};
    for (size_t i = 0; i < sizeof(pre) / sizeof(pre[0]); i++) {
        size_t pl = wcslen(pre[i]);
        if (out.size() > pl + 2 && _wcsnicmp(out.c_str(), pre[i], pl) == 0) out = out.substr(pl);
    }
    if (cache.size() > 64) cache.erase(cache.begin());
    cache.push_back(std::make_pair(path, out));
    return out;
}

static std::wstring FriendlyProc(const std::wstring& raw, const std::wstring& path) {
    struct M { const wchar_t* k; const wchar_t* v; };
    static const M map[] = {
        {L"msedgewebview2", L"WebView2"}, {L"msedge", L"Edge"}, {L"chrome", L"Chrome"},
        {L"firefox", L"Firefox"}, {L"brave", L"Brave"}, {L"opera", L"Opera"},
        {L"explorer", L"Explorer"}, {L"dwm", L"DWM"}, {L"audiodg", L"Audio"},
        {L"MsMpEng", L"Defender"}, {L"SearchIndexer", L"Indexador"}, {L"SearchHost", L"Busqueda"},
        {L"OneDrive", L"OneDrive"}, {L"Code", L"VS Code"}, {L"WindowsTerminal", L"Terminal"},
        {L"WINWORD", L"Word"}, {L"EXCEL", L"Excel"}, {L"POWERPNT", L"PowerPoint"},
        {L"OUTLOOK", L"Outlook"}, {L"ms-teams", L"Teams"}, {L"Teams", L"Teams"},
        {L"vlc", L"VLC"}, {L"steam", L"Steam"}, {L"steamwebhelper", L"Steam"},
        {L"discord", L"Discord"}, {L"Spotify", L"Spotify"}, {L"svchost", L"Servicios"},
        {L"ctfmon", L"Teclado"}, {L"StartMenuExperienceHost", L"Inicio"},
        {L"ShellExperienceHost", L"Shell"}, {L"RuntimeBroker", L"Broker"},
    };
    for (size_t i = 0; i < sizeof(map) / sizeof(map[0]); i++)
        if (_wcsicmp(raw.c_str(), map[i].k) == 0) return map[i].v;

    std::wstring desc = ProcDescription(path);
    if (!desc.empty() && desc.size() <= 16) return desc;

    std::wstring r = raw;
    bool allLower = !r.empty();
    for (size_t i = 0; i < r.size(); i++)
        if (iswupper(r[i])) { allLower = false; break; }
    if (allLower) r[0] = (wchar_t)towupper(r[0]);
    return r;
}

struct GcProcMemEx {
    DWORD cb;
    DWORD PageFaultCount;
    SIZE_T PeakWorkingSetSize, WorkingSetSize, QuotaPeakPagedPoolUsage, QuotaPagedPoolUsage,
           QuotaPeakNonPagedPoolUsage, QuotaNonPagedPoolUsage, PagefileUsage, PeakPagefileUsage,
           PrivateUsage;
};

static void SampleProcs() {
    if (g.topProcs <= 0) {
        g.procs.clear();
        return;
    }
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) return;

    FILETIME ftNow;
    GetSystemTimeAsFileTime(&ftNow);
    ULONGLONG wall = FileTimeToU64(ftNow);
    double dtWall = g.procWall ? (double)(wall - g.procWall) : 0.0;
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    double ncpu = si.dwNumberOfProcessors ? (double)si.dwNumberOfProcessors : 1.0;

    std::vector<ProcPrev> cur;
    std::vector<ProcInfo> all;
    std::unordered_map<DWORD, ProcPrev> prevMap;
    prevMap.reserve(g.procPrev.size() * 2 + 8);
    for (const auto& pv : g.procPrev) prevMap[pv.pid] = pv;
    PROCESSENTRY32W pe;
    memset(&pe, 0, sizeof(pe));
    pe.dwSize = sizeof(pe);
    if (Process32FirstW(snap, &pe)) {
        do {
            if (pe.th32ProcessID == 0) continue;
            HANDLE h = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pe.th32ProcessID);
            if (!h) continue;
            FILETIME c, e, kt, ut;
            bool okT = GetProcessTimes(h, &c, &e, &kt, &ut) != 0;
            ULONGLONG tot = okT ? (FileTimeToU64(kt) + FileTimeToU64(ut)) : 0;

            GcProcMemEx pmc;
            memset(&pmc, 0, sizeof(pmc));
            pmc.cb = sizeof(pmc);
            double ram = 0.0;
            if (GetProcessMemoryInfo(h, reinterpret_cast<PROCESS_MEMORY_COUNTERS*>(&pmc), sizeof(pmc)))
                ram = (double)pmc.PrivateUsage / 1048576.0;
            CloseHandle(h);
            if (!okT) continue;

            ProcPrev pp;
            pp.pid = pe.th32ProcessID;
            pp.t = tot;
            pp.created = FileTimeToU64(c);
            cur.push_back(pp);

            double cpu = 0.0;
            if (dtWall > 0.0) {
                const auto prev = prevMap.find(pp.pid);
                if (prev != prevMap.end() && prev->second.created == pp.created && tot >= prev->second.t)
                    cpu = (double)(tot - prev->second.t) * 100.0 / (dtWall * ncpu);
            }
            if (cpu > 100.0) cpu = 100.0;

            std::wstring nm = pe.szExeFile;
            if (nm.size() > 4 && _wcsicmp(nm.c_str() + nm.size() - 4, L".exe") == 0) nm.resize(nm.size() - 4);

            bool merged = false;
            for (size_t j = 0; j < all.size(); j++) {
                if (_wcsicmp(all[j].name.c_str(), nm.c_str()) == 0) {
                    all[j].cpu += cpu;
                    all[j].ramMB += ram;
                    merged = true;
                    break;
                }
            }
            if (!merged) {
                ProcInfo pi;
                pi.name = nm;
                pi.pid = pe.th32ProcessID;
                pi.cpu = cpu;
                pi.ramMB = ram;
                all.push_back(pi);
            }
        } while (Process32NextW(snap, &pe));
    }
    CloseHandle(snap);

    g.procPrev = cur;
    g.procWall = wall;

    bool byRam = g.procByRam;
    std::sort(all.begin(), all.end(), [byRam](const ProcInfo& a, const ProcInfo& b) {
        return byRam ? (a.ramMB > b.ramMB) : (a.cpu > b.cpu);
    });
    if ((int)all.size() > g.topProcs) all.resize((size_t)g.topProcs);
    for (size_t i = 0; i < all.size(); i++) {
        std::wstring path;
        HANDLE hp = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, all[i].pid);
        if (hp) {
            wchar_t pb[2 * MAX_PATH];
            DWORD pn = 2 * MAX_PATH;
            if (QueryFullProcessImageNameW(hp, 0, pb, &pn)) path.assign(pb, pn);
            CloseHandle(hp);
        }
        all[i].name = FriendlyProc(all[i].name, path);
    }
    g.procs = all;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static int    g_thumbGen = 0;
static unsigned long long g_thumbTrack = 0;
static std::wstring g_thumbAcceptedPath;
static bool   g_thumbBusy = false;
static bool   g_thumbRedo = false;
static int    g_thumbRetry = 0;
static HANDLE g_thumbThread = nullptr;

static volatile LONG64 g_lastPlayerThumbHash = 0;

static volatile LONG g_mediaDurSec = 0;

static volatile LONG64 g_lastPlayerThumbKeyHash = 0;

static volatile LONG   g_thumbMismatch = 0;
static volatile LONG g_propsFromTimer = 0;
static std::wstring g_curCoverKey;

static std::wstring g_mxLastQuery;

static void RefreshFileMeta(const std::wstring& forcePath = std::wstring());
static void OnEmbedDone(int what);
static void UndoLastChange();
static volatile LONG g_embedLocked = 0;
static std::wstring g_thumbFileUsed;
static wchar_t g_acoustKeyCfg[96] = L"";

static void ClearThumb() {
    ++g_thumbGen;
    ++g_thumbTrack;
    g_mediaCoverFadeUntil = 0;
    g_thumbAcceptedPath.clear();
    if (g.thumbOk || !g.thumbPx.empty()) {
        g.thumbOk = false;
        g.thumbPx.clear();
        g.thumbImg.clear();
        g.thumbSerial++;
        g.cards[CARD_MEDIA].dirty = true;
    }
}

#if GH_HAVE_WINRT
using namespace winrt::Windows::Media::Control;
static bool g_winrtInit = false, g_winrtOwnApartment = false;
static ULONGLONG g_mediaLast = 0;
static double g_mediaSeekTarget = 0.0, g_mediaLastRate = 1.0;
static ULONGLONG g_mediaSeekUntil = 0;
static int g_expectedPlaying = -1;
static volatile LONG64 g_propsEventAt = 0;
static std::wstring g_reportedMediaPath;

static GlobalSystemMediaTransportControlsSession g_sess{nullptr};
static winrt::Windows::Foundation::IAsyncOperation<GlobalSystemMediaTransportControlsSessionMediaProperties> g_mediaProperties{nullptr};
static winrt::Windows::Foundation::IAsyncOperation<bool> g_mediaAction{nullptr};
static ULONGLONG g_mediaPropsStarted = 0, g_mediaActionStarted = 0;
static int64_t g_mediaSeekStart = 0, g_mediaSeekEnd = 0, g_mediaSeekMin = 0, g_mediaSeekMax = 0;
static bool g_mediaPropsFromTimer = false;

template<class Operation> static void CancelMediaOperation(Operation& op) {
    if (!op) return;
    try { op.Cancel(); } catch (...) {}
    op = nullptr;
}
static winrt::event_token g_propTok{};
static volatile LONG g_propsDirty = 1;
static std::wstring g_sessId;
static ULONGLONG g_propsAtGlobal = 0;
static int g_mediaActionCmd = -1;
static std::wstring g_lastPropAlbum;
static uint32_t g_lastPropTrack = 0;
static ULONGLONG g_mediaLostSince = 0;

static void ReleaseMediaSession() {
    g_propsAtGlobal = 0;
    g_mediaActionCmd = -1;
    g_lastPropAlbum.clear();
    g_lastPropTrack = 0;
    CancelMediaOperation(g_mediaProperties);
    CancelMediaOperation(g_mediaAction);
    g_mediaPressed = -1;
    g_mediaLast = 0;
    g_mediaLastRate = 1.0;
    g_mediaSeekUntil = 0;
    g_expectedPlaying = -1;
    InterlockedExchange64(&g_propsEventAt, 0);
    g_reportedMediaPath.clear();
    g_lyrKey.clear();
    g_lyrAsked.clear();
    g_lyrics.clear();
    g_mediaSeekStart = g_mediaSeekEnd = g_mediaSeekMin = g_mediaSeekMax = 0;
    g_mediaFileDuration = 0;
    try {
        if (g_sess) g_sess.MediaPropertiesChanged(g_propTok);
    } catch (...) {
    }
    g_sess = nullptr;
    g_sessId.clear();
    g_mediaVolumeUntil = 0;
    g_mediaWheelRemainder = 0;
    AudioSetTarget(L"");
}

#if GH_HAVE_THUMB
static winrt::Windows::Storage::Streams::IRandomAccessStreamReference g_thumbRef{nullptr};

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static std::wstring CvCacheDir() {
    static const std::wstring dir = []() -> std::wstring {
        wchar_t buf[MAX_PATH];
        const DWORD n = GetEnvironmentVariableW(L"LOCALAPPDATA", buf, MAX_PATH);
        if (!n || n >= MAX_PATH) return {};
        std::wstring path = std::wstring(buf) + L"\\WindhawkGlassCards";
        CreateDirectoryW(path.c_str(), nullptr);
        path += L"\\covers";
        CreateDirectoryW(path.c_str(), nullptr);
        const DWORD attributes = GetFileAttributesW(path.c_str());
        if (attributes == INVALID_FILE_ATTRIBUTES || !(attributes & FILE_ATTRIBUTE_DIRECTORY)) return {};
        return path;
    }();
    return dir;
}

static std::wstring CvFileIdStr(const std::wstring& path);

static std::wstring CvKeyName(const std::wstring& artist, const std::wstring& title) {
    std::wstring k = CvNorm(artist) + L"|" + CvNorm(title);
    unsigned long long h = 14695981039346656037ULL;
    for (size_t i = 0; i < k.size(); i++) {
        h ^= (unsigned long long)(unsigned short)k[i];
        h *= 1099511628211ULL;
    }
    static const wchar_t* hex = L"0123456789abcdef";
    std::wstring o;
    for (int sh = 60; sh >= 0; sh -= 4) o += hex[(h >> sh) & 0xF];
    return o;
}

static std::wstring CvKeyFor(const std::wstring& path, const std::wstring& artist,
                             const std::wstring& title) {
    if (!path.empty()) {
        std::wstring id = CvFileIdStr(path);
        if (id.size() >= 8) return L"id" + id;
    }
    return CvKeyName(artist, title);
}

static uint64_t CvStrHash(const std::wstring& s) {
    uint64_t h = 14695981039346656037ULL;
    for (size_t i = 0; i < s.size(); i++) { h ^= (uint64_t)(unsigned short)s[i]; h *= 1099511628211ULL; }
    return h;
}

static bool CvIsBrowserSession() {
    std::wstring id = g_sessId;
    for (size_t i = 0; i < id.size(); i++) id[i] = (wchar_t)towlower((wint_t)id[i]);
    static const wchar_t* names[] = {L"chrome", L"msedge", L"firefox", L"opera", L"brave", L"vivaldi", L"iexplore", L"zen", L"arc", L"chromium", L"thorium", L"waterfox", L"librewolf"};
    for (size_t k = 0; k < sizeof(names) / sizeof(names[0]); k++) {
        if (id.find(names[k]) != std::wstring::npos) return true;
    }
    return false;
}

static bool CvFileExists(const std::wstring& p) {
    DWORD a = GetFileAttributesW(p.c_str());
    return a != INVALID_FILE_ATTRIBUTES && !(a & FILE_ATTRIBUTE_DIRECTORY);
}

static int CvFileAgeHours(const std::wstring& p) {
    WIN32_FILE_ATTRIBUTE_DATA d;
    if (!GetFileAttributesExW(p.c_str(), GetFileExInfoStandard, &d)) return -1;
    FILETIME now;
    GetSystemTimeAsFileTime(&now);
    ULARGE_INTEGER a, b;
    a.LowPart = d.ftLastWriteTime.dwLowDateTime;
    a.HighPart = d.ftLastWriteTime.dwHighDateTime;
    b.LowPart = now.dwLowDateTime;
    b.HighPart = now.dwHighDateTime;
    if (b.QuadPart < a.QuadPart) return 0;
    return (int)((b.QuadPart - a.QuadPart) / 36000000000ULL);
}

static void CvTouch(const std::wstring& p) {
    HANDLE h = CreateFileW(p.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h != INVALID_HANDLE_VALUE) CloseHandle(h);
}

static bool CvReadFile(const std::wstring& p, std::vector<BYTE>& out, size_t cap) {
    HANDLE h = CreateFileW(p.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    LARGE_INTEGER sz;
    if (!GetFileSizeEx(h, &sz) || sz.QuadPart <= 0 || (unsigned long long)sz.QuadPart > cap) {
        CloseHandle(h);
        return false;
    }
    out.resize((size_t)sz.QuadPart);
    DWORD rd = 0;
    bool ok = ReadFile(h, out.data(), (DWORD)out.size(), &rd, nullptr) && rd == out.size();
    CloseHandle(h);
    return ok;
}

static bool CvWriteFile(const std::wstring& p, const void* data, size_t n) {
    if (p.empty() || (n && !data)) return false;
    static volatile LONG tempSeq = 0;
    std::wstring tmp;
    HANDLE h = INVALID_HANDLE_VALUE;
    for (int attempt = 0; attempt < 16; ++attempt) {
        LONG seq = InterlockedIncrement(&tempSeq);
        tmp = p + L".tmp." + std::to_wstring(GetCurrentProcessId()) + L"." +
              std::to_wstring(GetTickCount64()) + L"." + std::to_wstring(seq);
        h = CreateFileW(tmp.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_NEW,
                        FILE_ATTRIBUTE_NORMAL, nullptr);
        if (h != INVALID_HANDLE_VALUE) break;
        if (GetLastError() != ERROR_FILE_EXISTS && GetLastError() != ERROR_ALREADY_EXISTS)
            return false;
    }
    if (h == INVALID_HANDLE_VALUE) return false;
    const BYTE* ptr = static_cast<const BYTE*>(data);
    size_t left = n;
    bool ok = true;
    while (left && ok) {
        DWORD chunk = left > 0x7ffff000u ? 0x7ffff000u : (DWORD)left;
        DWORD wr = 0;
        ok = WriteFile(h, ptr, chunk, &wr, nullptr) != 0 && wr == chunk;
        if (ok) { ptr += wr; left -= wr; }
    }
    if (ok) ok = FlushFileBuffers(h) != 0;
    if (!CloseHandle(h)) ok = false;
    if (ok) ok = MoveFileExW(tmp.c_str(), p.c_str(),
                             MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != 0;
    if (!ok) DeleteFileW(tmp.c_str());
    return ok;
}

static HANDLE CvCreateUniqueTempFile(const std::wstring& target, const wchar_t* purpose,
                                     std::wstring& tempPath) {
    static volatile LONG tempSeq = 0;
    tempPath.clear();
    if (target.empty() || !purpose || !*purpose) return INVALID_HANDLE_VALUE;
    for (int attempt = 0; attempt < 32; ++attempt) {
        LONG seq = InterlockedIncrement(&tempSeq);
        tempPath = target + L"." + purpose + L"." + std::to_wstring(GetCurrentProcessId()) +
                   L"." + std::to_wstring(GetTickCount64()) + L"." + std::to_wstring(seq) + L".tmp";
        HANDLE h = CreateFileW(tempPath.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_NEW,
                               FILE_ATTRIBUTE_NORMAL, nullptr);
        if (h != INVALID_HANDLE_VALUE) return h;
        DWORD error = GetLastError();
        tempPath.clear();
        if (error != ERROR_FILE_EXISTS && error != ERROR_ALREADY_EXISTS) return INVALID_HANDLE_VALUE;
    }
    return INVALID_HANDLE_VALUE;
}

static int CvImageType(const std::vector<BYTE>& b) {
    if (b.size() >= 4 && b[0] == 0xFF && b[1] == 0xD8 && b[2] == 0xFF) return 1;  // JPEG
    if (b.size() >= 8 && b[0] == 0x89 && b[1] == 0x50 && b[2] == 0x4E && b[3] == 0x47) return 2;  // PNG
    return 0;
}

// Extract embedded artwork from a bounded ID3 picture frame.
static bool CvReadApic(HANDLE h, const Id3Info& info, std::vector<BYTE>& out) {
    out.clear();
    if (!info.hasApic || info.tagSize < 10) return false;
    std::vector<BYTE> tag(info.tagSize + 10);
    LARGE_INTEGER z;
    z.QuadPart = 0;
    if (!SetFilePointerEx(h, z, nullptr, FILE_BEGIN)) return false;
    DWORD rd = 0;
    if (!ReadFile(h, tag.data(), (DWORD)tag.size(), &rd, nullptr) || rd < 10) return false;
    tag.resize(rd);
    size_t pos = 10;
    while (pos + 10 <= tag.size()) {
        const BYTE* fr = tag.data() + pos;
        if (fr[0] == 0) break;
        size_t sz = info.ver == 4 ? (((size_t)(fr[4] & 0x7F) << 21) | ((size_t)(fr[5] & 0x7F) << 14) |
                                     ((size_t)(fr[6] & 0x7F) << 7) | (size_t)(fr[7] & 0x7F))
                                  : (((size_t)fr[4] << 24) | ((size_t)fr[5] << 16) | ((size_t)fr[6] << 8) |
                                     (size_t)fr[7]);
        if (sz == 0 || pos + 10 + sz > tag.size()) break;
        if (memcmp(fr, "APIC", 4) == 0) {
            bool special = (fr[9] & (info.ver == 4 ? 0x4F : 0xE0)) != 0;
            int t2 = 0;
            size_t off2 = 0;
            if (!special && CvApicHasImage(fr + 10, sz, t2, off2)) {
                const BYTE* img = fr + 10 + off2;
                size_t n = sz - off2;
                if (n > 64) {
                    out.assign(img, img + n);
                    return CvImageType(out) != 0;
                }
            }
        }
        pos += 10 + sz;
    }
    return false;
}

static bool CvDownload(const std::string& url8, std::vector<BYTE>& out) {
    std::string body;
    if (url8.compare(0, 8, "https://") != 0) return false;
    if (!HttpGetUrl(FromUtf8(url8), body)) return false;
    out.assign(body.begin(), body.end());
    return out.size() >= 2048 && out.size() <= 4u * 1024u * 1024u && CvImageType(out) != 0;
}

static int CvMbKindWeight(const std::string& kind) {
    std::string k = kind;
    for (size_t i = 0; i < k.size(); i++) k[i] = (char)tolower((unsigned char)k[i]);
    if (k == "single") return 0;
    if (k == "ep") return 1;
    if (k == "album") return 2;
    if (k.find("compilation") != std::string::npos) return 4;
    if (k.find("soundtrack") != std::string::npos) return 3;
    if (k.find("live") != std::string::npos) return 5;
    return 3;
}

static bool CvPickMbRelease(const std::string& js, std::string& mbid) {

    const std::string tag = "\"id\":\"";
    size_t p = js.find("\"release-list\"");
    if (p == std::string::npos) return false;
    std::string best;
    int bestW = 99, bestTracks = 9999;
    size_t pos = js.find(tag, p);
    while (pos != std::string::npos && pos < 200000) {
        size_t b = pos + tag.size();
        size_t e = js.find('"', b);
        if (e == std::string::npos) break;
        std::string id = js.substr(b, e - b);
        bool uuid = id.size() == 36;
        for (size_t i = 0; uuid && i < id.size(); i++) {
            if (id[i] == '-') continue;
            if (!((id[i] >= '0' && id[i] <= '9') || (id[i] >= 'a' && id[i] <= 'f'))) uuid = false;
        }
        if (uuid) {

            size_t nx = js.find(tag, e);
            std::string ch = js.substr(pos, nx == std::string::npos ? 4000 : std::min<size_t>(nx - pos, 4000));
            std::string kind;
            JsonString(ch, 0, "primary-type", kind);
            int w = CvMbKindWeight(kind);
            int tracks = 9999;
            size_t tc = ch.find("\"track-count\":");
            if (tc != std::string::npos) tracks = atoi(ch.c_str() + tc + 14);
            if (w < bestW || (w == bestW && tracks < bestTracks)) {
                bestW = w;
                bestTracks = tracks;
                best = id;
            }
        }
        pos = js.find(tag, e);
    }
    if (best.empty()) return false;
    mbid = best;
    Wh_Log(L"Empotrar: lanzamiento elegido en MusicBrainz (tipo %d, %d pista(s))", bestW, bestTracks);
    return true;
}

static bool CvMbFrontOk(const std::string& js, std::string& url) {

    const std::string tag = "\"front\":";
    size_t p = js.find(tag);
    while (p != std::string::npos) {
        std::string v, img;
        if (JsonString(js, p, "front", v) || true) {
            size_t q = js.find("\"image\":", p);
            if (q != std::string::npos && q - p < 400 && JsonString(js, q, "image", img)) {
                std::string low = img;
                for (size_t i = 0; i < low.size(); i++) low[i] = (char)tolower((unsigned char)low[i]);
                if (low.compare(0, 6, "https:") == 0 && low.find("\"image\"") == std::string::npos) {
                    url = img;
                    return true;
                }
            }
        }
        p = js.find(tag, p + 1);
    }
    return false;
}

static ULONGLONG g_mbLastAt = 0;
static SRWLOCK g_mbRateLock = SRWLOCK_INIT;

static bool MbReserveRequest(bool waitForTurn) {
    const ULONGLONG started = GetTickCount64();
    while (!g_stop) {
        bool reserved = false;
        AcquireSRWLockExclusive(&g_mbRateLock);
        const ULONGLONG now = GetTickCount64();
        if (!g_mbLastAt || now < g_mbLastAt || now - g_mbLastAt >= 1100) {
            g_mbLastAt = now;
            reserved = true;
        }
        ReleaseSRWLockExclusive(&g_mbRateLock);
        if (reserved) return true;
        if (!waitForTurn || GetTickCount64() - started >= 4000) return false;
        Sleep(100);
    }
    return false;
}

static bool CvPickMbAsin(const std::wstring& artist, const std::wstring& title, std::string& asin) {
    if (g_stop || title.empty() || CvNoArtist(artist)) return false;
    if (!MbReserveRequest(false)) return false;
    std::string js;
    std::wstring q = L"recording:\"" + title + L"\" AND artist:\"" + artist + L"\"";
    if (!HttpGet(L"musicbrainz.org", L"/ws/2/release/?fmt=json&limit=5&query=" + UrlEncode(q), js)) return false;
    std::string a2;
    if (!JsonString(js, 0, "asin", a2) || a2.size() < 8) return false;
    asin = a2;
    return true;
}

static int CvMbCover(const std::wstring& artist, const std::wstring& title, std::vector<BYTE>& out) {
    if (g_stop || title.empty() || CvNoArtist(artist)) return -1;

    if (!MbReserveRequest(false)) return -1;
    std::string js, mbid, url;
    std::wstring q = L"release:\"" + title + L"\" AND artist:\"" + artist + L"\"";
    std::wstring path = L"/ws/2/release/?fmt=json&limit=5&query=" + UrlEncode(q);
    if (!HttpGet(L"musicbrainz.org", path, js)) return -1;
    if (!CvPickMbRelease(js, mbid)) return 0;
    js.clear();
    std::wstring p2 = L"/release/" + FromUtf8(mbid) + L"/front";
    if (!HttpGet(L"coverartarchive.org", p2, js)) return 0;
    if (!CvMbFrontOk(js, url)) return 0;
    if (CvDownload(url, out)) {
        Wh_Log(L"Empotrar: portada de MusicBrainz para '%s'", title.c_str());
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static bool CvMetaContent(const std::string& html, const char* key, std::string& out) {
    std::string k1 = std::string("property=\"") + key + "\"";
    std::string k2 = std::string("name=\"") + key + "\"";
    size_t p = html.find(k1);
    if (p == std::string::npos) p = html.find(k2);
    if (p == std::string::npos) return false;
    size_t c = html.find("content=\"", p);
    if (c == std::string::npos || c - p > 400) return false;
    c += 9;
    size_t e = html.find('"', c);
    if (e == std::string::npos || e - c < 12) return false;
    out = html.substr(c, e - c);

    static const char* ent[3][2] = {{"&amp;", "&"}, {"&#x2F;", "/"}, {"&#47;", "/"}};
    for (int i = 0; i < 3; i++) {
        size_t q = out.find(ent[i][0]);
        while (q != std::string::npos) {
            out.replace(q, strlen(ent[i][0]), ent[i][1]);
            q = out.find(ent[i][0], q + 1);
        }
    }
    return true;
}

static int CvTheAudioDbCover(const std::wstring& artist, const std::wstring& title, std::vector<BYTE>& out) {
    if (g_stop || title.empty()) return -1;
    std::string js, tn, an, url;
    if (!HttpGet(L"theaudiodb.com", L"/api/v1/json/2/searchtrack.php?s=" + UrlEncode(artist) + L"&t=" +
                                     UrlEncode(title), js))
        return -1;
    const std::string tag = "\"strTrack\":";
    size_t pos = js.find(tag);
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        tn.clear(); an.clear(); url.clear();
        if (JsonString(ch, 0, "strTrack", tn)) {
            JsonString(ch, 0, "strArtist", an);
            JsonString(ch, 0, "strTrackThumb", url);
            if (url.empty()) JsonString(ch, 0, "strAlbumThumb", url);
            if (!url.empty() && CvCoverTitleExact(CvJsonUnescape(tn), title) &&
                CvCoverArtistExact(CvJsonUnescape(an), artist) &&
                CvDownload(CvJsonUnescapeUtf8(url), out)) {
                Wh_Log(L"Empotrar: portada de TheAudioDB para '%s'", title.c_str());
                return 1;
            }
        }
        pos = nx;
    }
    return 0;
}

static int CvSpotifyCover(const std::wstring& artist, const std::wstring& title, std::vector<BYTE>& out) {
    if (g_stop || title.empty()) return -1;
    std::string js, tn, an, url;
    std::wstring q = artist.empty() ? title : (artist + L" " + title);
    if (!HttpGet(L"api.spotify.com", L"/v1/search?type=track&limit=10&q=" + UrlEncode(q), js)) {

        std::string html;
        if (!HttpGetUrl(L"https://open.spotify.com/search/" + UrlEncode(q), html)) return -1;
        if (CvMetaContent(html, "og:image", url) && CvDownload(url, out)) {
            Wh_Log(L"Empotrar: portada de Spotify para '%s'", title.c_str());
            return 1;
        }
        return 0;
    }
    const std::string tag = "\"album\":{";
    size_t pos = js.find(tag);
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        tn.clear(); an.clear(); url.clear();
        if (JsonString(ch, 0, "name", tn) && JsonString(ch, 0, "url", url) && url.size() > 12 &&
            CvCoverTitleExact(CvJsonUnescape(tn), title)) {

            JsonString(ch, 0, "artistName", an);
            if (CvDownload(url, out)) return 1;
        }
        pos = nx;
    }
    return 0;
}

static int CvLastFmCover(const std::wstring& artist, const std::wstring& title, std::vector<BYTE>& out) {
    if (g_stop || title.empty() || CvNoArtist(artist)) return -1;
    std::string js, url;
    std::wstring path = L"/2.0/?method=track.getinfo&format=json&autocorrect=0&artist=" + UrlEncode(artist) +
                        L"&track=" + UrlEncode(title);
    if (!HttpGet(L"ws.audioscrobbler.com", path, js)) return -1;
    std::string tn;
    if (!JsonString(js, 0, "name", tn) || !CvCoverTitleExact(CvJsonUnescape(tn), title)) return 0;
    const std::string tag = "\"#text\":\"";
    size_t pos = js.rfind(tag);
    while (pos != std::string::npos) {
        size_t b2 = pos + tag.size();
        size_t e2 = js.find('"', b2);
        if (e2 == std::string::npos) break;
        url = js.substr(b2, e2 - b2);
        if (url.compare(0, 8, "https://") == 0 && url.find("2a96cbd8b46e442fc41c2b86b821562f") == std::string::npos) {
            if (CvDownload(url, out)) {
                Wh_Log(L"Empotrar: portada de Last.fm para '%s'", title.c_str());
                return 1;
            }
        }
        if (pos == 0) break;
        pos = js.rfind(tag, pos - 1);
    }
    return 0;
}

static int CvDiscogsCover(const std::wstring& artist, const std::wstring& title, std::vector<BYTE>& out) {
    if (g_stop || title.empty()) return -1;
    std::string js, url;
    std::wstring q = artist.empty() ? title : (artist + L" " + title);
    std::wstring path = L"/database/search?type=release&per_page=10&q=" + UrlEncode(q);
    if (!HttpGet(L"api.discogs.com", path, js)) return -1;
    const std::string tag = "\"title\":";
    size_t pos = js.find(tag);
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        url.clear();
        std::string tt;
        if (JsonString(ch, 0, "cover_image", url) && JsonString(ch, 0, "title", tt)) {
            std::wstring wt = CvJsonUnescape(tt);

            std::wstring nT = CvNormSp(CvCleanTitleExact(title));
            std::wstring nA = CvNormSp(CvPrimaryArtist(artist));
            std::wstring nAll = CvNormSp(wt);
            if (!nT.empty() && nAll.find(nT) != std::wstring::npos &&
                (nA.empty() || nAll.find(nA) != std::wstring::npos) && CvDownload(url, out)) {
                Wh_Log(L"Empotrar: portada de Discogs para '%s'", title.c_str());
                return 1;
            }
        }
        pos = nx;
    }
    return 0;
}

static int CvAmazonCover(const std::string& asin, std::vector<BYTE>& out) {
    if (g_stop || asin.size() < 8) return -1;
    std::string url = "https://images-na.ssl-images-amazon.com/images/P/" + asin + ".01.LZZZZZZZ.jpg";
    if (CvDownload(url, out)) {
        Wh_Log(L"Empotrar: portada de Amazon para el ASIN %S", asin.c_str());
        return 1;
    }
    return 0;
}

static int CvGeniusCover(const std::wstring& artist, const std::wstring& title, std::vector<BYTE>& out) {
    if (g_stop || title.empty()) return -1;
    std::string js, path8;
    std::wstring q = artist.empty() ? title : (artist + L" " + title);
    if (!HttpGet(L"genius.com", L"/api/search/multi?per_page=5&q=" + UrlEncode(q), js)) return -1;
    std::string url;
    if (JsonString(js, 0, "song_art_image_thumbnail_url", url) && !url.empty()) {
        if (CvDownload(CvJsonUnescapeUtf8(url), out)) {
            Wh_Log(L"Empotrar: portada de Genius para '%s'", title.c_str());
            return 1;
        }
    }
    if (JsonString(js, 0, "song_art_image_url", url) && !url.empty()) {
        if (CvDownload(CvJsonUnescapeUtf8(url), out)) {
            Wh_Log(L"Empotrar: portada de Genius para '%s'", title.c_str());
            return 1;
        }
    }
    return 0;
}

static SRWLOCK g_napsterKeyLock = SRWLOCK_INIT;
static std::wstring g_napsterApiKey;

static bool JsonTopString(const std::string& obj, const char* key, std::string& out);
static void JsonArrayObjects(const std::string& js, const char* key, std::vector<std::string>& objs);

// Look up artwork using a user-supplied key for the legacy music catalog.
static int CvNapsterCover(const std::wstring& apiKey, const std::wstring& artist,
                          const std::wstring& title, std::vector<BYTE>& out) {
    if (g_stop || apiKey.empty() || title.empty()) return -1;

    const std::wstring query = artist.empty() ? title : artist + L" " + title;
    const std::wstring path = L"/v2.2/search?type=track&per_type_limit=10&query=" +
                              UrlEncode(query) + L"&apikey=" + UrlEncode(apiKey);
    std::string response;
    if (!HttpGetEx(L"api.napster.com", INTERNET_DEFAULT_HTTPS_PORT, true, path, response, 4u << 20, false))
        return -1;

    std::vector<std::string> tracks;
    JsonArrayObjects(response, "tracks", tracks);
    for (const auto& track : tracks) {
        if (g_stop) return -1;
        std::string trackName, artistName, albumId;
        if (!JsonTopString(track, "name", trackName) ||
            !JsonTopString(track, "artistName", artistName) ||
            !CvCoverTitleExact(CvJsonUnescape(trackName), title) ||
            !CvCoverArtistExact(CvJsonUnescape(artistName), artist))
            continue;

        if (JsonTopString(track, "albumId", albumId) && albumId.compare(0, 4, "alb.") == 0 &&
            albumId.size() > 4 && albumId.find_first_not_of("0123456789", 4) == std::string::npos &&
            CvDownload("https://direct.rhapsody.com/imageserver/v2/albums/" + albumId + "/images/500x500.jpg", out))
            return 1;
    }
    return 0;
}

static int CvSearchNet(const std::wstring& artist, const std::wstring& title,
                       const std::wstring& napsterKey, std::vector<BYTE>& out) {
    bool reach = false;
    std::string js, url;

    std::wstring art = artist;
    if (CvNoArtist(art) && !title.empty()) {
        std::vector<BYTE> solo;
        int sr0 = CvSoloTituloCover(title, solo);
        if (sr0 == 1) return 1;
        if (sr0 == 0 && InterlockedCompareExchange(&g_soloArtista, 0, 0)) {
            std::wstring tmp = g_soloNombre;
            if (!CvNoArtist(tmp)) art = tmp;
        }
        if (g_stop) return -1;
    }
    std::wstring term = art.empty() ? title : (art + L" " + title);

    if (HttpGet(L"itunes.apple.com", L"/search?term=" + UrlEncode(term) + L"&media=music&entity=song&limit=10", js)) {
        reach = true;
        if (CvPickItunes(js, art, title, url) && CvDownload(url, out)) return 1;
    }
    if (g_stop) return -1;

    js.clear();
    url.clear();
    std::wstring q = art.empty() ? (L"track:\"" + title + L"\"")
                                 : (L"artist:\"" + art + L"\" track:\"" + title + L"\"");
    if (HttpGet(L"api.deezer.com", L"/search?q=" + UrlEncode(q) + L"&limit=10", js)) {
        reach = true;
        if (CvPickDeezer(js, art, title, url) && CvDownload(url, out)) return 1;
    }
    if (g_stop) return -1;

    int mr = CvMbCover(art, title, out);
    if (mr == 1) return 1;
    if (mr == 0) reach = true;
    if (g_stop) return -1;

    int ar = CvTheAudioDbCover(art, title, out);
    if (ar == 1) return 1;
    if (ar == 0) reach = true;
    if (g_stop) return -1;

    int sr = CvSpotifyCover(art, title, out);
    if (sr == 1) return 1;
    if (sr == 0) reach = true;
    if (g_stop) return -1;

    int lr = CvLastFmCover(art, title, out);
    if (lr == 1) return 1;
    if (lr == 0) reach = true;
    if (g_stop) return -1;

    int dr = CvDiscogsCover(art, title, out);
    if (dr == 1) return 1;
    if (dr == 0) reach = true;
    if (g_stop) return -1;

    bool napsterUnavailable = false;
    if (!napsterKey.empty()) {
        const int nr = CvNapsterCover(napsterKey, art, title, out);
        if (nr == 1) return 1;
        if (nr == 0) reach = true;
        napsterUnavailable = nr < 0;
    }
    if (g_stop) return -1;

    int gr = CvGeniusCover(art, title, out);
    if (gr == 1) return 1;
    if (gr == 0) reach = true;
    if (g_stop) return -1;

    std::string asin;
    if (CvPickMbAsin(art, title, asin)) {
        reach = true;
        int mr2 = CvAmazonCover(asin, out);
        if (mr2 == 1) return 1;
    }
    return reach && !napsterUnavailable ? 0 : -1;
}

// Return -1 when no provider could be reached, so the lookup can be retried.
static int CvResolveOrder(const std::wstring& a, const std::wstring& b) {
    bool nA = false, nB = false, reach = false;
    struct Eq {
        static bool T(const std::wstring& x, const std::wstring& y) {
            return CvCoverTitleExact(x, y) || (!CvCoreTitle(x).empty() &&
                   CvNormSp(CvCoreTitle(x)) == CvNormSp(CvCoreTitle(y)));
        }
    };
    std::string js;
    const std::wstring term = a + L" " + b;
    for (int src = 0; src < 2 && !g_stop; src++) {
        js.clear();
        bool ok = (src == 0)
            ? HttpGet(L"itunes.apple.com", L"/search?term=" + UrlEncode(term) + L"&media=music&entity=song&limit=15", js)
            : HttpGet(L"api.deezer.com", L"/search?q=" + UrlEncode(term) + L"&limit=15", js);
        if (!ok) continue;
        reach = true;
        const std::string tag = (src == 0) ? "{\"wrapperType\"" : "\"readable\":";
        size_t pos = js.find(tag);
        while (pos != std::string::npos) {
            size_t nx = js.find(tag, pos + 1);
            std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
            std::string tn, an;
            bool got = (src == 0) ? (JsonString(ch, 0, "trackName", tn) && JsonString(ch, 0, "artistName", an))
                                  : (JsonString(ch, 0, "title", tn) && JsonString(ch, 0, "name", an));
            if (got) {
                std::wstring wt = CvJsonUnescape(tn), wa = CvJsonUnescape(an);
                if (Eq::T(wt, b) && CvCoverArtistExact(wa, a)) nA = true;
                if (Eq::T(wt, a) && CvCoverArtistExact(wa, b)) nB = true;
            }
            pos = nx;
        }
        if (nA != nB) break;
    }
    if (nA && !nB) return 0;
    if (nB && !nA) return 1;
    return reach ? 2 : -1;
}

struct CvOrderJob { std::wstring a, b; };
// Infer the filename's title and artist order from catalog evidence.
static DWORD WINAPI CvOrderThread(LPVOID param) {
    CvOrderJob* j = static_cast<CvOrderJob*>(param);
    int r = CvResolveOrder(j->a, j->b);
    if (r >= 0 && !g_stop) {
        CvOrderSet(j->a, j->b, r);
        Wh_Log(L"Orden del nombre: '%s' / '%s' -> %s", j->a.c_str(), j->b.c_str(),
               r == 0 ? L"Interprete - Titulo" : (r == 1 ? L"Titulo - Interprete" : L"sin evidencia, se mantiene el orden habitual"));
    }
    delete j;
    return 0;
}

static void CvOrderKick(const std::wstring& a, const std::wstring& b) {
    if (!g.onlineCovers || g_stop || a.empty() || b.empty()) return;
    if (CvOrderGet(a, b) != -1) return;
    if (g_orderThread) {
        if (WaitForSingleObject(g_orderThread, 0) != WAIT_OBJECT_0) return;
        CloseHandle(g_orderThread);
        g_orderThread = nullptr;
    }
    ULONGLONG now = GetTickCount64();
    if (g_orderLastTry && now - g_orderLastTry < 60000ULL) return;
    g_orderLastTry = now;
    CvOrderJob* j = new CvOrderJob();
    j->a = a;
    j->b = b;
    g_orderThread = CreateThread(nullptr, 0, CvOrderThread, j, 0, nullptr);
    if (!g_orderThread) delete j;
}

static bool CvYearOk(const std::string& y) {
    if (y.size() < 4) return false;
    for (int i = 0; i < 4; i++) if (y[i] < '0' || y[i] > '9') return false;
    int v = atoi(y.substr(0, 4).c_str());
    return v >= 1900 && v <= 2100;
}

static void CvPrune(const std::wstring& dir) {
    std::vector<std::pair<unsigned long long, std::wstring>> files;
    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileW((dir + L"\\*").c_str(), &fd);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;
        unsigned long long t = ((unsigned long long)fd.ftLastWriteTime.dwHighDateTime << 32) | fd.ftLastWriteTime.dwLowDateTime;
        files.push_back(std::make_pair(t, std::wstring(fd.cFileName)));
    } while (FindNextFileW(h, &fd));
    FindClose(h);
    if (files.size() <= 1500) return;
    std::sort(files.begin(), files.end());
    for (size_t i = 0; i < 500 && i < files.size(); i++) DeleteFileW((dir + L"\\" + files[i].second).c_str());
}

static bool CvGetCover(const std::wstring& key, const std::wstring& artist, const std::wstring& title, bool net,
                       std::vector<BYTE>& out) {
    std::wstring dir = CvCacheDir();
    if (dir.empty()) return false;

    std::wstring qA, qT;
    CvSplitQuery(artist, title, qA, qT);
    if (qT.empty()) qT = CvCleanTitle(title);
    std::wstring safeKey = key.empty() ? CvKeyName(qA, qT) : key;
    std::wstring base = dir + L"\\" + safeKey;
    Wh_Log(L"Empotrar: se busca la imagen con clave %s (tema '%s')", safeKey.c_str(), qT.c_str());
    if (CvReadFile(base + L".img", out, 4u << 20) && CvImageType(out) != 0) return true;
    if (!net || g_stop) return false;
    std::wstring napsterKey;
    {
        SrwGuard guard(&g_napsterKeyLock);
        napsterKey = g_napsterApiKey;
    }
    // A miss from before the user enabled Napster must not suppress its first lookup.
    const std::wstring missPath = base + (napsterKey.empty() ? L".none" : L".napster.none");
    int age = CvFileAgeHours(missPath);
    if (age >= 0 && age < 24 * 7) return false;
    int r = CvSearchNet(artist, title, napsterKey, out);
    if (r == 1) {
        CvWriteFile(base + L".img", out.data(), out.size());
        CvPrune(dir);
        return true;
    }
    if (r == 0) CvTouch(missPath);
    return false;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

enum CvEmbedRes { EMB_OK, EMB_ALREADY, EMB_SKIP, EMB_LOCKED, EMB_ERROR };

// Parse the ID3 header before reading frames. Reject unsupported or oversized input.
static bool CvReadTag(HANDLE h, Id3Info& info, std::vector<BYTE>& tag) {
    BYTE hdr[10];
    DWORD rd = 0;
    LARGE_INTEGER z;
    z.QuadPart = 0;
    if (!SetFilePointerEx(h, z, nullptr, FILE_BEGIN)) return false;
    if (!ReadFile(h, hdr, 10, &rd, nullptr)) return false;
    Id3ReadHeader(hdr, rd, info);
    if (info.hasTag && !info.unsupported) {
        tag.assign(info.tagSize, 0);
        if (info.tagSize) {
            if (!ReadFile(h, tag.data(), (DWORD)info.tagSize, &rd, nullptr) || rd != info.tagSize) return false;
        }
        Id3ParseFrames(tag.data(), tag.size(), info);
    }
    return true;
}

static bool CvVerifyEmbeddedFile(const std::wstring& path, const std::wstring& wantTitle,
                                 const std::wstring& wantArtist, uint64_t wantImageHash,
                                 bool checkCover = true, const std::wstring& wantAlbum = std::wstring(),
                                 const std::wstring& wantYear = std::wstring(),
                                 const std::wstring& wantComment = std::wstring()) {
    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ,
                           FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                           nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    Id3Info check;
    std::vector<BYTE> checkTag;
    bool ok = CvReadTag(h, check, checkTag);
    CloseHandle(h);
    if (!ok || check.unsupported || !check.hasTag) return false;
    if (checkCover && (!check.hasApic || check.apicCount != 1 || check.apicHash != wantImageHash)) return false;
    if (!wantTitle.empty() && CvNorm(check.title) != CvNorm(wantTitle)) return false;
    if (!wantArtist.empty() && CvNorm(check.artist) != CvNorm(wantArtist)) return false;
    if (!wantAlbum.empty() && CvNorm(check.album) != CvNorm(wantAlbum)) return false;
    if (!wantYear.empty() && CvNorm(check.year.substr(0, 4)) != CvNorm(wantYear.substr(0, 4))) return false;
    if (!wantComment.empty() && Trim(check.gcid) != wantComment) return false;
    return true;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// Reject missing, generic, numeric, and URL-only tag values.
static bool MetaTextBad(const std::wstring& s0) {
    std::wstring s = LowerWs(Trim(s0));
    if (s.empty()) return true;
    if (s.find(L"http") != std::wstring::npos || s.find(L"www.") != std::wstring::npos) return true;
    static const wchar_t* bad[] = {L"unknown", L"unknown artist", L"<unknown>", L"desconocido",
                                   L"artista desconocido", L"untitled", L"sin titulo", L"sin t\u00EDtulo",
                                   L"track", L"pista", L"audiotrack"};
    for (size_t i = 0; i < sizeof(bad) / sizeof(bad[0]); i++)
        if (s == bad[i]) return true;
    if (s.size() <= 10 && (s.compare(0, 5, L"track") == 0 || s.compare(0, 5, L"pista") == 0) &&
        s.find_first_of(L"0123456789") != std::wstring::npos)
        return true;
    bool onlyDigits = true;
    for (size_t i = 0; i < s.size(); i++)
        if (!iswdigit(s[i]) && s[i] != L' ') {
            onlyDigits = false;
            break;
        }
    return onlyDigits;
}

// Accept a four-digit year within the supported calendar range.
static bool MetaYearOk(const std::wstring& y) {
    if (y.size() < 4) return false;
    for (int i = 0; i < 4; i++)
        if (!iswdigit(y[i])) return false;
    int v = _wtoi(y.substr(0, 4).c_str());
    SYSTEMTIME st;
    GetLocalTime(&st);
    return v >= 1900 && v <= (int)st.wYear + 1;
}

static bool SameMediaAlbum(const std::wstring& a, const std::wstring& b) {
    return !a.empty() && !b.empty() && CvNormSp(a) == CvNormSp(b);
}

static bool CvIsMp3(const std::wstring& path) {
    return path.size() >= 5 && _wcsicmp(path.c_str() + path.size() - 4, L".mp3") == 0;
}

enum class LocalAudioTags { Unsupported, Flac, M4a };

static LocalAudioTags LocalTagFormat(const std::wstring& path) {
    if (path.size() >= 5 && _wcsicmp(path.c_str() + path.size() - 5, L".flac") == 0)
        return LocalAudioTags::Flac;
    if (path.size() >= 4 && (_wcsicmp(path.c_str() + path.size() - 4, L".m4a") == 0 ||
                             _wcsicmp(path.c_str() + path.size() - 4, L".m4b") == 0))
        return LocalAudioTags::M4a;
    return LocalAudioTags::Unsupported;
}

static constexpr size_t kLocalAudioCoverCap = 4u << 20;
static constexpr size_t kLocalAudioTextCap = 128u << 10;

static void AssignLocalTag(std::wstring& dst, const std::wstring& text) {
    if (!dst.empty()) return;
    std::wstring clean = Trim(text);
    if (!clean.empty() && clean.find(L'\0') == std::wstring::npos) dst = std::move(clean);
}

static bool LocalReadLengthString(const BYTE*& at, const BYTE* end, bool little, std::string& value) {
    if (end - at < 4) return false;
    const uint32_t length = little ?
        uint32_t(at[0]) | uint32_t(at[1]) << 8 | uint32_t(at[2]) << 16 | uint32_t(at[3]) << 24 :
        CvBE32(at);
    at += 4;
    if (length > (size_t)(end - at) || length > kLocalAudioTextCap) return false;
    value.assign(reinterpret_cast<const char*>(at), length);
    at += length;
    return true;
}

static void ReadFlacComments(const std::vector<BYTE>& block, FileMeta& fm) {
    if (block.size() < 8) return;
    const BYTE* at = block.data();
    const BYTE* end = at + block.size();
    std::string line;
    if (!LocalReadLengthString(at, end, true, line) || end - at < 4) return;
    const uint32_t count = uint32_t(at[0]) | uint32_t(at[1]) << 8 | uint32_t(at[2]) << 16 | uint32_t(at[3]) << 24;
    at += 4;
    std::wstring albumArtist;
    for (uint32_t i = 0; i < count && i < 4096; ++i) {
        if (!LocalReadLengthString(at, end, true, line)) return;
        const auto eq = line.find('=');
        if (eq == std::string::npos || eq > 24) continue;
        const auto key = LowerWs(FromUtf8(line.substr(0, eq)));
        const auto text = FromUtf8(line.substr(eq + 1));
        if (key == L"title") AssignLocalTag(fm.title, text);
        else if (key == L"artist") AssignLocalTag(fm.artist, text);
        else if (key == L"albumartist") AssignLocalTag(albumArtist, text);
        else if (key == L"album") AssignLocalTag(fm.album, text);
        else if ((key == L"date" || key == L"year") && MetaYearOk(Trim(text)))
            AssignLocalTag(fm.year, text);
    }
    AssignLocalTag(fm.artist, albumArtist);
}

static bool ReadFlacPicture(const std::vector<BYTE>& block, FileMeta& fm, bool& front) {
    if (block.size() < 32) return false;
    const uint32_t type = CvBE32(block.data());
    if ((type != 0 && type != 3) || front || (type != 3 && fm.coverOk)) return false;
    const BYTE* at = block.data() + 4;
    const BYTE* end = block.data() + block.size();
    std::string mime, desc;
    if (!LocalReadLengthString(at, end, false, mime) || mime == "-->" ||
        !LocalReadLengthString(at, end, false, desc) || end - at < 20) return false;
    const uint32_t length = CvBE32(at + 16);
    at += 20;
    if (!length || length > kLocalAudioCoverCap || length != (size_t)(end - at)) return false;
    std::vector<BYTE> cover(at, end);
    if (!CvImageType(cover)) return false;
    fm.cover = std::move(cover);
    fm.coverOk = true;
    front = type == 3;
    return true;
}

template<class Read>
static bool ReadFlacTags(Read& read, uint64_t size, FileMeta& fm, bool cover) {
    BYTE header[4];
    if (size < 42 || !read(0, header, sizeof(header)) || memcmp(header, "fLaC", 4) != 0) return false;
    uint64_t at = 4;
    bool front = false;
    for (int i = 0; i < 128 && size - at >= 4; ++i) {
        if (!read(at, header, sizeof(header))) return false;
        at += 4;
        const uint32_t length = uint32_t(header[1]) << 16 | uint32_t(header[2]) << 8 | header[3];
        const unsigned type = header[0] & 127;
        if (length > size - at || (i == 0 && (type != 0 || length != 34))) return false;
        if ((type == 4 && length <= 2u * 1024u * 1024u) ||
            (type == 6 && cover && !front && length <= kLocalAudioCoverCap + kLocalAudioTextCap * 2 + 32)) {
            std::vector<BYTE> block(length);
            if (length && !read(at, block.data(), block.size())) return false;
            if (type == 4) ReadFlacComments(block, fm);
            else ReadFlacPicture(block, fm, front);
        }
        at += length;
        if (header[0] & 128) return true;
    }
    return false;
}

constexpr uint32_t AudioAtom(unsigned a, unsigned b, unsigned c, unsigned d) {
    return a << 24 | b << 16 | c << 8 | d;
}

struct LocalAudioBox { uint32_t type; uint64_t payload, end; };

template<class Read>
static bool ReadAudioBox(Read& read, uint64_t at, uint64_t end, LocalAudioBox& box) {
    BYTE header[16];
    if (end - at < 8 || !read(at, header, 8)) return false;
    uint64_t length = CvBE32(header);
    uint64_t headerLength = 8;
    if (length == 1) {
        if (end - at < 16 || !read(at + 8, header + 8, 8)) return false;
        length = uint64_t(CvBE32(header + 8)) << 32 | CvBE32(header + 12);
        headerLength = 16;
    } else if (!length) {
        length = end - at;
    }
    if (length < headerLength || length > end - at) return false;
    box = {CvBE32(header + 4), at + headerLength, at + length};
    return true;
}

template<class Read>
static void ReadM4aItem(Read& read, const LocalAudioBox& item, std::wstring* field,
                        FileMeta& fm, bool cover, unsigned& budget) {
    for (uint64_t at = item.payload; at < item.end && budget;) {
        --budget;
        LocalAudioBox data{};
        if (!ReadAudioBox(read, at, item.end, data)) return;
        at = data.end;
        if (data.type != AudioAtom('d','a','t','a') || data.end - data.payload <= 8) continue;
        BYTE header[8];
        if (!read(data.payload, header, sizeof(header))) return;
        const uint32_t type = CvBE32(header);
        const uint64_t n = data.end - data.payload - 8;
        if ((field && (type == 1 || type == 2) && n <= kLocalAudioTextCap) ||
            (cover && (type == 13 || type == 14) && n <= kLocalAudioCoverCap)) {
            std::vector<BYTE> bytes((size_t)n);
            if (!read(data.payload + 8, bytes.data(), bytes.size())) return;
            if (cover) {
                if (!CvImageType(bytes)) continue;
                fm.cover = std::move(bytes);
                fm.coverOk = true;
            } else if (type == 1) {
                AssignLocalTag(*field, FromUtf8(std::string(bytes.begin(), bytes.end())));
            } else if (bytes.size() % 2 == 0) {
                std::wstring text;
                for (size_t i = 0; i < bytes.size(); i += 2)
                    text += (wchar_t)(unsigned(bytes[i]) << 8 | bytes[i + 1]);
                if (!text.empty() && text.front() == L'\uFEFF') text.erase(text.begin());
                AssignLocalTag(*field, text);
            }
            return;
        }
    }
}

template<class Read>
static bool ReadM4aTagsIn(Read& read, uint64_t at, uint64_t end, int depth,
                         FileMeta& fm, bool cover, unsigned& budget) {
    if (depth > 4) return false;
    bool found = false;
    while (at < end && budget) {
        --budget;
        LocalAudioBox box{};
        if (!ReadAudioBox(read, at, end, box)) return found;
        at = box.end;
        switch (box.type) {
            case AudioAtom('m','o','o','v'):
            case AudioAtom('u','d','t','a'):
                found = ReadM4aTagsIn(read, box.payload, box.end, depth + 1, fm, cover, budget) || found;
                break;
            case AudioAtom('m','e','t','a'):
                if (box.end - box.payload >= 4)
                    found = ReadM4aTagsIn(read, box.payload + 4, box.end, depth + 1, fm, cover, budget) || found;
                break;
            case AudioAtom('i','l','s','t'): {
                std::wstring albumArtist;
                for (uint64_t itemAt = box.payload; itemAt < box.end && budget;) {
                    --budget;
                    LocalAudioBox item{};
                    if (!ReadAudioBox(read, itemAt, box.end, item)) break;
                    itemAt = item.end;
                    std::wstring* field = nullptr;
                    switch (item.type) {
                        case AudioAtom(0xa9,'n','a','m'): field = &fm.title; break;
                        case AudioAtom(0xa9,'A','R','T'): field = &fm.artist; break;
                        case AudioAtom('a','A','R','T'): field = &albumArtist; break;
                        case AudioAtom(0xa9,'a','l','b'): field = &fm.album; break;
                        case AudioAtom(0xa9,'d','a','y'): field = &fm.year; break;
                    }
                    const bool picture = cover && !fm.coverOk && item.type == AudioAtom('c','o','v','r');
                    if (field || picture) ReadM4aItem(read, item, field, fm, picture, budget);
                }
                AssignLocalTag(fm.artist, albumArtist);
                found = true;
                break;
            }
        }
    }
    return found;
}

static bool ReadLocalAudioTags(HANDLE h, LocalAudioTags format, FileMeta& fm, bool cover) {
    LARGE_INTEGER length{};
    if (!GetFileSizeEx(h, &length) || length.QuadPart <= 0) return false;
    const uint64_t size = (uint64_t)length.QuadPart;
    size_t remaining = 12u << 20;
    auto read = [h, size, &remaining](uint64_t at, BYTE* bytes, size_t count) {
        if (at > size || count > size - at || count > remaining) return false;
        remaining -= count;
        LARGE_INTEGER pos{};
        pos.QuadPart = (LONGLONG)at;
        DWORD got = 0;
        return SetFilePointerEx(h, pos, nullptr, FILE_BEGIN) &&
               ReadFile(h, bytes, (DWORD)count, &got, nullptr) && got == count;
    };
    unsigned budget = 4096;
    const bool ok = format == LocalAudioTags::Flac ? ReadFlacTags(read, size, fm, cover) :
        format == LocalAudioTags::M4a && ReadM4aTagsIn(read, 0, size, 0, fm, cover, budget);
    if (!ok) { fm = {}; return false; }
    fm.year = fm.year.substr(0, 4);
    fm.titleOk = !fm.title.empty();
    fm.artistOk = !fm.artist.empty();
    fm.albumOk = !fm.album.empty();
    fm.yearOk = MetaYearOk(fm.year);
    fm.ok = true;
    return true;
}

static bool ReadFileMeta(const std::wstring& path, FileMeta& fm, bool wantCover) {
    fm = FileMeta();
    const bool mp3 = CvIsMp3(path);
    const auto format = LocalTagFormat(path);
    if (!mp3 && format == LocalAudioTags::Unsupported) return false;
    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                           nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    if (!mp3) {
        const bool ok = ReadLocalAudioTags(h, format, fm, wantCover);
        CloseHandle(h);
        if (ok) fm.path = path;
        return ok;
    }
    Id3Info info;
    std::vector<BYTE> tag;
    bool ok = CvReadTag(h, info, tag);
    if (ok && info.hasTag && !info.unsupported) {
        fm.title = Trim(info.title);
        fm.artist = Trim(info.artist);
        fm.album = Trim(info.album);
        fm.year = info.year.size() >= 4 ? info.year.substr(0, 4) : Trim(info.year);
        fm.titleOk = !MetaTextBad(fm.title);
        fm.artistOk = !MetaTextBad(fm.artist);
        fm.albumOk = !MetaTextBad(fm.album);
        fm.yearOk = MetaYearOk(fm.year);
        if (info.hasApic && !info.hasApicBroken && info.apicCount == 1 && info.apicBytes >= 3000) {
            if (wantCover) {
                std::vector<BYTE> img;
                if (CvReadApic(h, info, img) && CvImageType(img) != 0) {
                    fm.cover.swap(img);
                    fm.coverOk = true;
                }
            } else {
                fm.coverOk = true;
            }
        }
        std::wstring id = CvFileIdStr(path);
        fm.mine = !id.empty() && Trim(info.gcid) == L"GCID:" + id;
    }
    CloseHandle(h);
    fm.ok = ok && !info.unsupported;
    fm.path = path;
    return fm.ok;
}

static std::wstring CvPathKey(const std::wstring& path) {
    std::wstring low = LowerWs(path);
    uint64_t h = 1469598103934665603ULL;
    for (size_t i = 0; i < low.size(); i++) {
        h ^= (uint64_t)low[i];
        h *= 1099511628211ULL;
    }
    wchar_t b[32];
    wsprintfW(b, L"%08X%08X", (unsigned)(h >> 32), (unsigned)(h & 0xFFFFFFFFu));
    return b;
}

static const int kUndoLevels = 5;

static SRWLOCK g_cvFileMutationLock = SRWLOCK_INIT;

static std::wstring CvUndoPathN(const std::wstring& path, int n) {
    std::wstring dir = CvCacheDir();
    if (dir.empty()) return std::wstring();
    std::wstring f = dir + L"\\" + CvPathKey(path) + L".undo";
    if (n > 0) f += std::to_wstring(n);
    return f;
}
static std::wstring CvUndoPath(const std::wstring& path) { return CvUndoPathN(path, 0); }
static std::wstring CvUndoPendingPath(const std::wstring& path) {
    std::wstring f = CvUndoPath(path);
    return f.empty() ? std::wstring() : f + L".pending";
}

// Recover interrupted backup rotation while retaining recoverable files on failure.
static void CvUndoRecoverArtifacts(const std::wstring& path) {
    if (path.empty()) return;
    std::wstring base = CvUndoPath(path);
    if (base.empty()) return;

    if (!TryAcquireSRWLockExclusive(&g_cvFileMutationLock)) return;
    auto restorePattern = [&](const std::wstring& pattern, const std::wstring& target) {
        if (CvFileExists(target)) return;
        WIN32_FIND_DATAW fd;
        HANDLE find = FindFirstFileW(pattern.c_str(), &fd);
        if (find == INVALID_HANDLE_VALUE) return;
        do {
            if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;
            std::wstring candidate = pattern.substr(0, pattern.find_last_of(L'\\') + 1) + fd.cFileName;
            if (CvFileExists(target)) break;

            if (MoveFileExW(candidate.c_str(), target.c_str(), MOVEFILE_WRITE_THROUGH)) {
                Wh_Log(L"Deshacer: artefacto recuperado '%s' -> '%s'", candidate.c_str(), target.c_str());
            }
        } while (FindNextFileW(find, &fd));
        FindClose(find);
    };

    restorePattern(base + L".consumed.*", base);

    for (int i = 0; i < kUndoLevels; ++i) {
        std::wstring slot = CvUndoPathN(path, i);
        restorePattern(slot + L".hold.*", slot);
        restorePattern(slot + L".rollback.*", slot);
    }
    ReleaseSRWLockExclusive(&g_cvFileMutationLock);
}

static int CvUndoCount(const std::wstring& path) {
    if (!CvIsMp3(path)) return 0;
    CvUndoRecoverArtifacts(path);
    int c = 0;
    std::wstring pending = CvUndoPendingPath(path);
    if (!pending.empty() && CvFileExists(pending)) c++;
    for (int i = 0; i < kUndoLevels && c < kUndoLevels; i++) {
        std::wstring f = CvUndoPathN(path, i);
        if (f.empty() || !CvFileExists(f)) break;
        c++;
    }
    return c;
}

static bool CvUndoExists(const std::wstring& path) {
    if (!CvIsMp3(path)) return false;
    CvUndoRecoverArtifacts(path);
    std::wstring u = CvUndoPath(path);
    std::wstring pending = CvUndoPendingPath(path);
    return (!u.empty() && CvFileExists(u)) || (!pending.empty() && CvFileExists(pending));
}

static volatile LONG g_mp3MediaSessionUnsafe = 1;
static volatile LONG64 g_mp3MediaLastChecked = 0;
static volatile LONG64 g_mp3MediaNoSessionSince = 0;
// Track the last playback report for the write gate.
static void Mp3MediaSessionReport(bool sessionExists) {
    const LONG64 now = (LONG64)GetTickCount64();
    if (sessionExists) {
        InterlockedExchange(&g_mp3MediaSessionUnsafe, 1);
        InterlockedExchange64(&g_mp3MediaNoSessionSince, 0);
    } else {
        if (InterlockedExchange(&g_mp3MediaSessionUnsafe, 0) != 0)
            InterlockedExchange64(&g_mp3MediaNoSessionSince, now);
    }
    InterlockedExchange64(&g_mp3MediaLastChecked, now);
}

// Treat active or unknown playback as unsafe for replacing an MP3.
static bool Mp3MediaSafeForMutation() {
    if (g_stop || InterlockedCompareExchange(&g_mp3MediaSessionUnsafe, 0, 0) != 0)
        return false;
    const LONG64 now = (LONG64)GetTickCount64();
    const LONG64 seen = InterlockedCompareExchange64(&g_mp3MediaLastChecked, 0, 0);
    const LONG64 idle = InterlockedCompareExchange64(&g_mp3MediaNoSessionSince, 0, 0);
    return seen > 0 && idle > 0 && now >= seen && now - seen <= 2500 &&
           now >= idle && now - idle >= 4000;
}

static bool CvFileExclusivelyAvailable(const std::wstring& path) {
    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ, 0, nullptr,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) {
        Wh_Log(L"Seguridad MP3: acceso exclusivo denegado a '%s' (error %u); no se sustituye",
               path.c_str(), GetLastError());
        return false;
    }
    CloseHandle(h);
    return true;
}

static bool CvMutationIdentityFromHandle(HANDLE h, CvFileId& out) {
    out = CvFileId();
    FILE_ID_INFO fi;
    memset(&fi, 0, sizeof(fi));
    if (!GetFileInformationByHandleEx(h, FileIdInfo, &fi, sizeof(fi))) return false;
    out.vol = fi.VolumeSerialNumber;
    memcpy(out.id, fi.FileId.Identifier, 16);
    out.ok = true;
    return true;
}

static bool CvMutationIdentityOfPath(const std::wstring& path, CvFileId& out) {
    out = CvFileId();

    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    bool ok = CvMutationIdentityFromHandle(h, out);
    CloseHandle(h);
    return ok;
}

static bool CvMutationIdentityStillMatches(const std::wstring& path, const CvFileId& expected) {
    CvFileId current;
    return expected.ok && CvMutationIdentityOfPath(path, current) && expected.Same(current);
}

// Read a consistent copy of the old header and capture its source file identity.
static bool CvUndoSnapshot(const std::wstring& path, std::vector<BYTE>& head, CvFileId& sourceIdentity) {
    head.clear();
    sourceIdentity = CvFileId();

    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ,
                           nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    bool identityOk = CvMutationIdentityFromHandle(h, sourceIdentity);
    BYTE hdr[10];
    DWORD rd = 0;
    bool ok = ReadFile(h, hdr, 10, &rd, nullptr) != 0;
    if (ok && rd == 10 && hdr[0] == 'I' && hdr[1] == 'D' && hdr[2] == '3') {
        if ((hdr[6] | hdr[7] | hdr[8] | hdr[9]) & 0x80) {
            ok = false;
        } else {
            size_t sz = 10 + (size_t)CvSynchsafe(hdr + 6);
            if (sz > (16u << 20)) {
                ok = false;
            } else {
                head.assign(sz, 0);
                LARGE_INTEGER z;
                z.QuadPart = 0;
                DWORD r2 = 0;
                ok = SetFilePointerEx(h, z, nullptr, FILE_BEGIN) &&
                     ReadFile(h, head.data(), (DWORD)sz, &r2, nullptr) && r2 == sz;
            }
        }
    }
    CloseHandle(h);
    if (!ok || !identityOk) {
        head.clear();
        sourceIdentity = CvFileId();
        return false;
    }
    return true;
}

// Fingerprint the audio payload independently of its ID3 header for undo validation.
static bool CvUndoAudioFingerprint(const std::wstring& path, unsigned long long& audioBytes,
                                   unsigned long long& fingerprint, CvFileId* fileIdentity = nullptr) {
    audioBytes = 0;
    fingerprint = 14695981039346656037ULL;

    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ,
                           nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    bool identityOk = !fileIdentity || CvMutationIdentityFromHandle(h, *fileIdentity);
    LARGE_INTEGER size;
    bool ok = identityOk && GetFileSizeEx(h, &size) && size.QuadPart > 0;
    unsigned long long offset = 0;
    BYTE hdr[10] = {};
    DWORD rd = 0;
    if (ok && ReadFile(h, hdr, sizeof(hdr), &rd, nullptr) && rd == sizeof(hdr) &&
        hdr[0] == 'I' && hdr[1] == 'D' && hdr[2] == '3') {

        if ((hdr[6] | hdr[7] | hdr[8] | hdr[9]) & 0x80) ok = false;
        else offset = 10ULL + ((unsigned long long)hdr[6] << 21) +
                      ((unsigned long long)hdr[7] << 14) + ((unsigned long long)hdr[8] << 7) + hdr[9];
    } else if (rd != sizeof(hdr)) {
        ok = false;
    }
    if (ok && (offset >= (unsigned long long)size.QuadPart)) ok = false;
    if (ok) {
        LARGE_INTEGER pos; pos.QuadPart = (LONGLONG)offset;
        ok = SetFilePointerEx(h, pos, nullptr, FILE_BEGIN) != 0;
    }
    BYTE chunk[1u << 16];
    while (ok) {
        DWORD got = 0;
        if (!ReadFile(h, chunk, sizeof(chunk), &got, nullptr)) { ok = false; break; }
        if (!got) break;
        for (DWORD i = 0; i < got; ++i) {
            fingerprint ^= chunk[i];
            fingerprint *= 1099511628211ULL;
        }
        audioBytes += got;
    }
    CloseHandle(h);
    return ok && audioBytes > 0;
}

static uint32_t CvUndoCrc32(const BYTE* data, size_t size) {
    uint32_t crc = 0xFFFFFFFFu;
    for (size_t i = 0; i < size; ++i) {
        crc ^= data[i];
        for (int bit = 0; bit < 8; ++bit)
            crc = (crc >> 1) ^ (0xEDB88320u & (uint32_t)-(int)(crc & 1u));
    }
    return ~crc;
}

struct CvUndoRecord {
    std::wstring savedPath;
    std::vector<BYTE> head;
    unsigned long long audioBytes = 0;
    unsigned long long audioHash = 0;
    bool checksummed = false;
};

// Validate a backup before allowing it to restore a header.
static bool CvUndoParseRecord(const std::vector<BYTE>& buf, const std::wstring& expectedPath,
                              CvUndoRecord& out, const wchar_t** reason = nullptr) {
    auto reject = [&](const wchar_t* why) -> bool { if (reason) *reason = why; return false; };
    if (reason) *reason = L"correcto";
    out = CvUndoRecord();
    if (buf.size() < 8 + 4 + 4 + 16) return reject(L"tamano minimo");
    static const char magic2[8] = {'G','C','U','N','D','O','2',0};
    static const char magic3[8] = {'G','C','U','N','D','O','3',0};
    bool v2 = memcmp(buf.data(), magic2, 8) == 0;
    bool v3 = memcmp(buf.data(), magic3, 8) == 0;
    if (!v2 && !v3) return reject(L"firma/formato GCUNDO incompatible");
    size_t limit = buf.size();
    if (v3) {
        if (limit < 4) return reject(L"CRC ausente");
        limit -= 4;
        uint32_t stored = (uint32_t)buf[limit] | ((uint32_t)buf[limit+1] << 8) |
                          ((uint32_t)buf[limit+2] << 16) | ((uint32_t)buf[limit+3] << 24);
        if (CvUndoCrc32(buf.data(), limit) != stored) return reject(L"CRC incorrecto");
        out.checksummed = true;
    }
    size_t o = 8;
    auto get32 = [&](uint32_t& v) -> bool {
        if (o > limit || limit - o < 4) return reject(L"campo de longitud truncado");
        v = (uint32_t)buf[o] | ((uint32_t)buf[o+1] << 8) |
            ((uint32_t)buf[o+2] << 16) | ((uint32_t)buf[o+3] << 24);
        o += 4; return true;
    };
    uint32_t pathChars = 0, headBytes = 0;
    if (!get32(pathChars) || pathChars == 0 || pathChars > 32767) return reject(L"longitud de ruta invalida");
    if ((size_t)pathChars > (limit - o) / sizeof(wchar_t)) return reject(L"ruta truncada");
    out.savedPath.assign(pathChars, L'\0');
    memcpy(&out.savedPath[0], buf.data() + o, (size_t)pathChars * sizeof(wchar_t));
    o += (size_t)pathChars * sizeof(wchar_t);
    if (out.savedPath.find(L'\0') != std::wstring::npos || _wcsicmp(out.savedPath.c_str(), expectedPath.c_str()) != 0)
        return reject(L"ruta distinta o mal terminada");
    if (!get32(headBytes) || headBytes > (16u << 20) || (size_t)headBytes > limit - o) return reject(L"cabecera ID3 truncada o demasiado grande");
    out.head.assign(buf.begin() + o, buf.begin() + o + headBytes);
    o += headBytes;
    if (!out.head.empty()) {
        if (out.head.size() < 10 || out.head[0] != 'I' || out.head[1] != 'D' || out.head[2] != '3') return reject(L"cabecera ID3 invalida");
        const BYTE* h = out.head.data();
        if ((h[6] | h[7] | h[8] | h[9]) & 0x80) return reject(L"tamano ID3 no synchsafe");
        size_t tagSize = ((size_t)h[6] << 21) | ((size_t)h[7] << 14) | ((size_t)h[8] << 7) | h[9];
        if (tagSize != out.head.size() - 10) return reject(L"tamano de etiqueta ID3 no coincide");
    }
    if (limit - o != 16) return reject(L"tamano final de identidad de audio incorrecto");
    for (int i = 0; i < 8; ++i) out.audioBytes |= (unsigned long long)buf[o++] << (8 * i);
    for (int i = 0; i < 8; ++i) out.audioHash |= (unsigned long long)buf[o++] << (8 * i);
    return out.audioBytes > 0 ? true : reject(L"identidad de audio vacia");
}

// Persist the previous header before any operation can replace the MP3.
static bool CvUndoPrepare(const std::wstring& path, const std::vector<BYTE>& head,
                          const CvFileId& expectedIdentity) {
    std::wstring file = CvUndoPath(path);
    std::wstring pending = CvUndoPendingPath(path);
    if (file.empty() || pending.empty() || head.size() > (16u << 20) || path.size() > 32767)
        return false;
    std::vector<BYTE> buf;
    auto put32 = [&](uint32_t v) {
        for (int i = 0; i < 4; i++) buf.push_back((BYTE)(v >> (8 * i)));
    };
    static const char magic[8] = {'G', 'C', 'U', 'N', 'D', 'O', '3', 0};
    unsigned long long audioBytes = 0, audioHash = 0;
    CvFileId audioIdentity;
    if (!CvUndoAudioFingerprint(path, audioBytes, audioHash, &audioIdentity) ||
        !expectedIdentity.Same(audioIdentity)) return false;
    buf.insert(buf.end(), magic, magic + 8);
    put32((uint32_t)path.size());
    const BYTE* pp = reinterpret_cast<const BYTE*>(path.c_str());
    buf.insert(buf.end(), pp, pp + path.size() * sizeof(wchar_t));
    put32((uint32_t)head.size());
    buf.insert(buf.end(), head.begin(), head.end());
    for (int i = 0; i < 8; ++i) buf.push_back((BYTE)(audioBytes >> (8 * i)));
    for (int i = 0; i < 8; ++i) buf.push_back((BYTE)(audioHash >> (8 * i)));

    uint32_t crc = CvUndoCrc32(buf.data(), buf.size());
    put32(crc);

    return CvWriteFile(pending, buf.data(), buf.size());
}

// Promote the pending backup only after a successful replacement.
static bool CvUndoCommit(const std::wstring& path) {
    std::wstring file = CvUndoPath(path);
    std::wstring pending = CvUndoPendingPath(path);
    if (file.empty() || pending.empty() || !CvFileExists(pending)) return false;

    std::wstring oldest = CvUndoPathN(path, kUndoLevels - 1);
    std::wstring hold = oldest + L".hold." + std::to_wstring(GetCurrentProcessId()) +
                        L"." + std::to_wstring(GetTickCount64());
    bool heldOldest = false;
    if (CvFileExists(oldest)) {
        if (!MoveFileExW(oldest.c_str(), hold.c_str(), MOVEFILE_WRITE_THROUGH)) {
            return false;
        }
        heldOldest = true;
    }
    bool shifted[kUndoLevels] = {};
    bool rotationOk = true;
    for (int i = kUndoLevels - 1; i >= 2; --i) {
        std::wstring from = CvUndoPathN(path, i - 1), to = CvUndoPathN(path, i);
        if (CvFileExists(from)) {
            if (!MoveFileExW(from.c_str(), to.c_str(), MOVEFILE_WRITE_THROUGH)) {
                rotationOk = false;
                break;
            }
            shifted[i] = true;
        }
    }

    bool installed = false;
    if (rotationOk) {
        std::wstring previous = CvUndoPathN(path, 1);
        if (CvFileExists(file)) {
            installed = ReplaceFileW(file.c_str(), pending.c_str(), previous.c_str(),
                                     REPLACEFILE_IGNORE_MERGE_ERRORS, nullptr, nullptr) != 0;
        } else {
            installed = MoveFileExW(pending.c_str(), file.c_str(), MOVEFILE_WRITE_THROUGH) != 0;
        }
    }
    if (installed) {
        if (heldOldest) DeleteFileW(hold.c_str());
        return true;
    }

    std::wstring rollbackHold[kUndoLevels];
    bool evacuated[kUndoLevels] = {};
    bool restored[kUndoLevels] = {};
    bool rollbackOk = true;
    for (int i = kUndoLevels - 1; i >= 2; --i) {
        if (!shifted[i]) continue;
        rollbackHold[i] = CvUndoPathN(path, i) + L".rollback." +
                          std::to_wstring(GetCurrentProcessId()) + L"." +
                          std::to_wstring(GetTickCount64()) + L"." + std::to_wstring(i);
        if (!MoveFileExW(CvUndoPathN(path, i).c_str(), rollbackHold[i].c_str(), MOVEFILE_WRITE_THROUGH)) {
            rollbackOk = false;
            break;
        }
        evacuated[i] = true;
    }
    for (int i = 2; i < kUndoLevels; ++i) {
        if (!evacuated[i]) continue;
        std::wstring originalSlot = CvUndoPathN(path, i - 1);
        if (CvFileExists(originalSlot) ||
            !MoveFileExW(rollbackHold[i].c_str(), originalSlot.c_str(), MOVEFILE_WRITE_THROUGH)) {
            rollbackOk = false;
            continue;
        }
        restored[i] = true;
    }
    if (heldOldest) {
        if (CvFileExists(oldest) || !MoveFileExW(hold.c_str(), oldest.c_str(), MOVEFILE_WRITE_THROUGH))
            rollbackOk = false;
    }
    if (!rollbackOk) {
        Wh_Log(L"Deshacer: rollback incompleto; se conservan los holds para recuperacion: '%s'", hold.c_str());
        for (int i = 2; i < kUndoLevels; ++i)
            if (evacuated[i] && !restored[i]) Wh_Log(L"Deshacer: hold de recuperacion '%s'", rollbackHold[i].c_str());
    }

    return false;
}

// Check the backup before obtaining exclusive access to the destination.
static bool CvUndoPreflight(const std::wstring& path) {
    const std::wstring pending = CvUndoPendingPath(path);
    const std::wstring slot = (!pending.empty() && CvFileExists(pending)) ? pending : CvUndoPath(path);
    if (slot.empty() || !CvFileExists(slot)) {
        Wh_Log(L"Deshacer: prevalidacion: no existe el respaldo");
        return false;
    }
    std::vector<BYTE> bytes;
    if (!CvReadFile(slot, bytes, 20u << 20)) {
        Wh_Log(L"Deshacer: prevalidacion: respaldo ilegible o demasiado grande");
        return false;
    }
    CvUndoRecord record;
    const wchar_t* reason = L"indeterminado";
    if (!CvUndoParseRecord(bytes, path, record, &reason)) {
        Wh_Log(L"Deshacer: prevalidacion FALLIDA; razon=%s; bytes=%u; pendiente=%d; MP3 intacto",
               reason, (unsigned)bytes.size(), slot == pending ? 1 : 0);
        return false;
    }
    Wh_Log(L"Deshacer: prevalidacion OK; formato=%s; cabecera=%u bytes; pendiente=%d; MP3 intacto",
           record.checksummed ? L"GCUNDO3" : L"GCUNDO2", (unsigned)record.head.size(), slot == pending ? 1 : 0);
    return true;
}

// Validate the backing audio before restoring a header. Keep recovery files if rotation fails.
static bool CvUndoApply(const std::wstring& path, bool allowPlayerOpen, bool* busyOut = nullptr) {
    (void)allowPlayerOpen;
    if (busyOut) *busyOut = false;
    if (!Mp3MediaSafeForMutation() || !CvFileExclusivelyAvailable(path)) {
        if (busyOut) *busyOut = true;
        Wh_Log(L"Deshacer: archivo abierto; cierra el reproductor antes de reintentar");
        return false;
    }
    CvUndoRecoverArtifacts(path);
    SrwGuard mutationGuard(&g_cvFileMutationLock);
    std::wstring pendingUndo = CvUndoPendingPath(path);
    bool usingPendingUndo = !pendingUndo.empty() && CvFileExists(pendingUndo);
    std::wstring ufile = usingPendingUndo ? pendingUndo : CvUndoPath(path);
    if (ufile.empty() || path.empty()) return false;
    std::vector<BYTE> buf;
    if (!CvReadFile(ufile, buf, 20u << 20)) return false;

    CvUndoRecord record;
    const wchar_t* parseReason = L"indeterminado";
    if (!CvUndoParseRecord(buf, path, record, &parseReason)) {
        Wh_Log(L"Deshacer: respaldo rechazado; motivo=%s; no se aplica", parseReason);
        return false;
    }
    const BYTE* head = record.head.empty() ? nullptr : record.head.data();
    uint32_t hl = (uint32_t)record.head.size();
    unsigned long long savedAudioBytes = record.audioBytes;
    unsigned long long savedAudioHash = record.audioHash;
    unsigned long long currentAudioBytes = 0, currentAudioHash = 0;
    if (!CvUndoAudioFingerprint(path, currentAudioBytes, currentAudioHash) ||
        currentAudioBytes != savedAudioBytes || currentAudioHash != savedAudioHash) {
        Wh_Log(L"Deshacer: el audio de '%s' ya no coincide con el archivo respaldado; se cancela", path.c_str());
        if (usingPendingUndo) {

            DeleteFileW(ufile.c_str());
            Wh_Log(L"Deshacer: se descarta el pendiente obsoleto; puede repetirse la accion para el historial anterior");
        }
        return false;
    }

    HANDLE src = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ,
                             nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (src == INVALID_HANDLE_VALUE) return false;
    CvFileId undoSourceIdentity;
    if (!CvMutationIdentityFromHandle(src, undoSourceIdentity)) {
        CloseHandle(src);
        return false;
    }
    LARGE_INTEGER fsz;
    if (!GetFileSizeEx(src, &fsz)) {
        CloseHandle(src);
        return false;
    }
    BYTE hdr[10];
    DWORD rd = 0;
    unsigned long long curOff = 0;
    if (ReadFile(src, hdr, 10, &rd, nullptr) && rd == 10 && hdr[0] == 'I' && hdr[1] == 'D' && hdr[2] == '3') {
        if ((hdr[6] | hdr[7] | hdr[8] | hdr[9]) & 0x80) {
            CloseHandle(src);
            return false;
        }
        curOff = 10ULL + (unsigned long long)CvSynchsafe(hdr + 6);
    }
    if (curOff >= (unsigned long long)fsz.QuadPart) {
        CloseHandle(src);
        return false;
    }
    std::wstring tmp;
    HANDLE dst = CvCreateUniqueTempFile(path, L"gcundo", tmp);
    if (dst == INVALID_HANDLE_VALUE) {
        CloseHandle(src);
        return false;
    }
    bool ok = true;
    DWORD wr = 0;
    if (hl > 0) ok = WriteFile(dst, head, hl, &wr, nullptr) && wr == hl;
    if (ok) {
        LARGE_INTEGER pos;
        pos.QuadPart = (LONGLONG)curOff;
        ok = SetFilePointerEx(src, pos, nullptr, FILE_BEGIN) != 0;
    }
    std::vector<BYTE> chunk(1u << 20);
    unsigned long long left = (unsigned long long)fsz.QuadPart - curOff;
    while (ok && left > 0 && !g_stop) {
        DWORD want = (DWORD)std::min<unsigned long long>(left, chunk.size());
        DWORD r2 = 0;
        if (!ReadFile(src, chunk.data(), want, &r2, nullptr) || r2 == 0) {
            ok = false;
            break;
        }
        if (!WriteFile(dst, chunk.data(), r2, &wr, nullptr) || wr != r2) {
            ok = false;
            break;
        }
        left -= r2;
    }
    if (g_stop) ok = false;
    if (ok) ok = FlushFileBuffers(dst) != 0;
    if (!CloseHandle(dst)) ok = false;
    CloseHandle(src);
    if (!ok) {
        DeleteFileW(tmp.c_str());
        return false;
    }

    unsigned long long tempAudioBytes = 0, tempAudioHash = 0;
    if (!CvUndoAudioFingerprint(tmp, tempAudioBytes, tempAudioHash) ||
        tempAudioBytes != savedAudioBytes || tempAudioHash != savedAudioHash) {
        Wh_Log(L"Deshacer: el audio copiado de '%s' no coincide con el respaldo; se cancela", path.c_str());
        DeleteFileW(tmp.c_str());
        return false;
    }

    if (!CvMutationIdentityStillMatches(path, undoSourceIdentity)) {
        Wh_Log(L"Deshacer: '%s' fue sustituido durante la operacion; se cancela", path.c_str());
        DeleteFileW(tmp.c_str());
        return false;
    }

    if (!Mp3MediaSafeForMutation() || !CvFileExclusivelyAvailable(path)) {
        DeleteFileW(tmp.c_str());
        Wh_Log(L"MP3PEND: Deshacer sigue pendiente: sesion o acceso al MP3 ocupado antes de ReplaceFileW");
        if (busyOut) *busyOut = true;
        return false;
    }
    Wh_Log(L"MP3PEND: Deshacer listo para sustitucion; sin sesion GSMTC y MP3 libre");
    const bool done = ReplaceFileW(path.c_str(), tmp.c_str(), nullptr, 0, nullptr, nullptr) != 0;
    const DWORD replaceError = done ? ERROR_SUCCESS : GetLastError();
    if (!done) {

        Wh_Log(L"Deshacer: no se pudo restaurar '%s' (error %u; se conserva '%s')",
               path.c_str(), replaceError, tmp.c_str());
        if (busyOut && (replaceError == ERROR_SHARING_VIOLATION || replaceError == ERROR_ACCESS_DENIED ||
                        replaceError == ERROR_LOCK_VIOLATION || replaceError == ERROR_UNABLE_TO_REMOVE_REPLACED))
            *busyOut = true;
        return false;
    }
    if (usingPendingUndo) {

        std::wstring consumedPending = ufile + L".consumed." + std::to_wstring(GetCurrentProcessId()) +
                                       L"." + std::to_wstring(GetTickCount64());
        if (MoveFileExW(ufile.c_str(), consumedPending.c_str(), MOVEFILE_WRITE_THROUGH))
            DeleteFileW(consumedPending.c_str());
        else
            Wh_Log(L"Deshacer: audio restaurado; el respaldo pendiente sigue presente '%s'", ufile.c_str());
        Wh_Log(L"Deshacer: '%s' vuelve al estado previo a la incrustacion", path.c_str());
        return true;
    }

    std::wstring consumedHold = ufile + L".consumed." + std::to_wstring(GetCurrentProcessId()) +
                                L"." + std::to_wstring(GetTickCount64());
    if (!MoveFileExW(ufile.c_str(), consumedHold.c_str(), MOVEFILE_WRITE_THROUGH)) {
        Wh_Log(L"Deshacer: audio restaurado, pero no se pudo apartar el respaldo consumido '%s'",
               ufile.c_str());
        return true;
    }
    bool promoted[kUndoLevels] = {};
    bool promotionOk = true;
    for (int i = 1; i < kUndoLevels; ++i) {
        std::wstring from = CvUndoPathN(path, i), to = CvUndoPathN(path, i - 1);
        if (CvFileExists(from)) {
            if (!MoveFileExW(from.c_str(), to.c_str(), MOVEFILE_WRITE_THROUGH)) {
                promotionOk = false;
                break;
            }
            promoted[i] = true;
        }
    }
    if (promotionOk) {
        DeleteFileW(consumedHold.c_str());
    } else {

        std::wstring rollbackHold[kUndoLevels];
        bool evacuated[kUndoLevels] = {};
        bool restored[kUndoLevels] = {};
        bool rollbackOk = true;
        for (int i = 1; i < kUndoLevels; ++i) {
            if (!promoted[i]) continue;
            rollbackHold[i] = CvUndoPathN(path, i - 1) + L".rollback." +
                              std::to_wstring(GetCurrentProcessId()) + L"." +
                              std::to_wstring(GetTickCount64()) + L"." + std::to_wstring(i);
            if (!MoveFileExW(CvUndoPathN(path, i - 1).c_str(), rollbackHold[i].c_str(), MOVEFILE_WRITE_THROUGH)) {
                rollbackOk = false;
                break;
            }
            evacuated[i] = true;
        }
        for (int i = 1; i < kUndoLevels; ++i) {
            if (!evacuated[i]) continue;
            std::wstring originalSlot = CvUndoPathN(path, i);
            if (CvFileExists(originalSlot) ||
                !MoveFileExW(rollbackHold[i].c_str(), originalSlot.c_str(), MOVEFILE_WRITE_THROUGH)) {
                rollbackOk = false;
                continue;
            }
            restored[i] = true;
        }
        if (CvFileExists(ufile) || !MoveFileExW(consumedHold.c_str(), ufile.c_str(), MOVEFILE_WRITE_THROUGH))
            rollbackOk = false;
        if (!rollbackOk) {
            Wh_Log(L"Deshacer: rollback incompleto; se conservan los holds para recuperacion: '%s'", consumedHold.c_str());
            for (int i = 1; i < kUndoLevels; ++i)
                if (evacuated[i] && !restored[i]) Wh_Log(L"Deshacer: hold de recuperacion '%s'", rollbackHold[i].c_str());
        } else {
            Wh_Log(L"Deshacer: restauracion completada; historial conservado sin promocion por un error de archivo");
        }
    }

    Wh_Log(L"Deshacer: '%s' vuelve a su estado anterior", path.c_str());
    return true;
}

static unsigned long long g_embedWantSize = 0, g_embedWantTime = 0;
static bool CvFileStamp(const std::wstring& path, unsigned long long& size, unsigned long long& ft);

// Copy the audio bytes into a temporary file and verify the new tags before replacing the original.
static CvEmbedRes CvEmbedCore(const std::wstring& path, const std::vector<BYTE>& img,
                              const std::wstring& wantTitle, const std::wstring& wantArtist,
                              const std::wstring& yearOverride, const std::wstring& albumOverride,
                              const CvFileId& expectedSourceIdentity, bool allowPlayerOpen) {
    (void)allowPlayerOpen;
    if (!Mp3MediaSafeForMutation() || !CvFileExclusivelyAvailable(path)) return EMB_LOCKED;
    int type = CvImageType(img);
    if (!img.empty() && !type) {
        Wh_Log(L"Empotrar: la imagen no es JPEG/PNG valida; no se toca '%s'", path.c_str());
        return EMB_ERROR;
    }
    DWORD attrs = GetFileAttributesW(path.c_str());
    if (attrs == INVALID_FILE_ATTRIBUTES) return EMB_ERROR;
    if (attrs & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_REPARSE_POINT)) {
        Wh_Log(L"Empotrar: '%s' es de solo lectura, carpeta o acceso directo; se omite", path.c_str());
        return EMB_SKIP;
    }

    HANDLE src = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (src == INVALID_HANDLE_VALUE) {
        DWORD e = GetLastError();
        Wh_Log(L"Empotrar: no se pudo abrir '%s' (error %u)%s", path.c_str(), e,
               e == ERROR_SHARING_VIOLATION ? L": lo tiene abierto el reproductor" : L"");
        return e == ERROR_SHARING_VIOLATION ? EMB_LOCKED : EMB_ERROR;
    }
    CvFileId embedSourceIdentity;
    if (!CvMutationIdentityFromHandle(src, embedSourceIdentity) ||
        !expectedSourceIdentity.Same(embedSourceIdentity)) {
        CloseHandle(src);
        Wh_Log(L"Empotrar: '%s' cambio entre el snapshot y la apertura; no se escribe", path.c_str());
        return EMB_ERROR;
    }
    LARGE_INTEGER fsz;
    if (!GetFileSizeEx(src, &fsz) || fsz.QuadPart < 4096 || fsz.QuadPart > 400LL * 1024 * 1024) {
        Wh_Log(L"Empotrar: tamano no valido en '%s'", path.c_str());
        CloseHandle(src);
        return EMB_SKIP;
    }
    FILETIME ct, at, wt;
    bool haveTimes = GetFileTime(src, &ct, &at, &wt) != 0;

    Id3Info info;
    std::vector<BYTE> tag;
    if (!CvReadTag(src, info, tag)) {
        Wh_Log(L"Empotrar: no se pudo leer la etiqueta de '%s'", path.c_str());
        CloseHandle(src);
        return EMB_ERROR;
    }
    if (info.unsupported) {
        Wh_Log(L"Empotrar: etiqueta no soportada en '%s' (ID3v2.%d); se omite", path.c_str(), info.ver);
        CloseHandle(src);
        return EMB_SKIP;
    }

    const std::wstring haveTitleStrict = CvNormSp(CvCleanTitleExact(info.title));
    const std::wstring wantTitleStrict = CvNormSp(CvCleanTitleExact(wantTitle));
    bool needTitle = !wantTitle.empty() &&
                     (info.title.empty() || haveTitleStrict != wantTitleStrict);
    bool needArtist = !wantArtist.empty() &&
                      (info.artist.empty() || !CvArtistOk(info.artist, wantArtist) ||
                       CvNorm(info.artist) != CvNorm(wantArtist));
    bool needAlbum = !albumOverride.empty() && CvNorm(info.album) != CvNorm(albumOverride);
    Wh_Log(L"Empotrar ID3: ver=%d tag=%d bytes=%u APIC=%d/%u hash=%016llX TIT2='%s' TPE1='%s' needTitle=%d needArtist=%d",
           info.ver, info.hasTag ? 1 : 0, (unsigned)info.tagSize, info.hasApic ? 1 : 0,
           info.apicCount, (unsigned long long)info.apicHash,
           info.title.c_str(), info.artist.c_str(), needTitle ? 1 : 0, needArtist ? 1 : 0);

    const uint64_t wantedImageHash = CvHashBytes(img.data(), img.size());
    bool mismaImagen = info.hasApic && !info.hasApicBroken && info.apicCount == 1 &&
                       info.apicType == type && info.apicBytes == img.size() &&
                       info.apicHash == wantedImageHash;

    bool needCover = (type != 0) && !mismaImagen;
    if (needCover && info.hasApicBroken) {
        Wh_Log(L"Empotrar: el APIC de '%s' no lleva imagen; se sustituye", path.c_str());
    } else if (needCover && info.hasApic) {
        Wh_Log(L"Empotrar: la portada de '%s' es distinta (tipo %d/%d, %u/%u bytes); se sustituye",
               path.c_str(), info.apicType, type, (unsigned)info.apicBytes, (unsigned)img.size());
    }

    std::wstring wantYear;
    bool needYear = false;
    if (!yearOverride.empty()) {
        wantYear = yearOverride.substr(0, 4);
        needYear = MetaYearOk(wantYear) && Trim(info.year).substr(0, 4) != wantYear;
    }

    std::wstring wantId = CvFileIdStr(path);
    std::wstring wantComment = wantId.empty() ? std::wstring() : (L"GCID:" + wantId);
    bool needComment = !wantComment.empty() && Trim(info.gcid) != wantComment;
    if (needComment)
        Wh_Log(L"Empotrar: se escribe el DNI en el comentario de '%s' (%s)", path.c_str(),
               wantComment.c_str());
    Wh_Log(L"MP3DIAG: cambios_ID3 portada=%d titulo=%d artista=%d album=%d anio=%d GCID=%d",
           needCover ? 1 : 0, needTitle ? 1 : 0, needArtist ? 1 : 0,
           needAlbum ? 1 : 0, needYear ? 1 : 0, needComment ? 1 : 0);
    if (!needCover && !needTitle && !needArtist && !needAlbum && !needYear) {
        CloseHandle(src);
        return EMB_ALREADY;
    }

    Id3Info build = info;
    if (needTitle) build.title = wantTitle;
    if (needArtist) build.artist = wantArtist;
    build.yearNew = needYear ? wantYear : L"";
    build.albumNew = needAlbum ? albumOverride : L"";
    std::vector<BYTE> head = Id3BuildWithCover(build, tag.data(), img.data(), img.size(), type,
                                               needCover, wantComment);
    unsigned long long audioOff = info.hasTag ? 10ULL + info.tagSize : 0ULL;
    if (head.empty() || audioOff >= (unsigned long long)fsz.QuadPart) {
        Wh_Log(L"Empotrar: no se pudo construir la etiqueta nueva de '%s' (head=%u, audioOff=%llu, tam=%llu)",
               path.c_str(), (unsigned)head.size(), audioOff, (unsigned long long)fsz.QuadPart);
        CloseHandle(src);
        return EMB_SKIP;
    }

    std::wstring tmp;
    HANDLE dst = CvCreateUniqueTempFile(path, L"gcover", tmp);
    if (dst == INVALID_HANDLE_VALUE) {
        Wh_Log(L"Empotrar: no se pudo crear un temporal exclusivo para '%s' (error %u)", path.c_str(), GetLastError());
        CloseHandle(src);
        return EMB_ERROR;
    }
    bool ok = true;
    DWORD wr = 0;
    if (!WriteFile(dst, head.data(), (DWORD)head.size(), &wr, nullptr) || wr != head.size()) ok = false;
    if (ok) {
        LARGE_INTEGER pos;
        pos.QuadPart = (LONGLONG)audioOff;
        ok = SetFilePointerEx(src, pos, nullptr, FILE_BEGIN) != 0;
    }
    std::vector<BYTE> buf(1u << 20);
    unsigned long long left = (unsigned long long)fsz.QuadPart - audioOff;
    while (ok && left > 0 && !g_stop) {
        DWORD want = (DWORD)std::min<unsigned long long>(left, buf.size());
        DWORD rd = 0;
        if (!ReadFile(src, buf.data(), want, &rd, nullptr) || rd == 0) {
            ok = false;
            break;
        }
        if (!WriteFile(dst, buf.data(), rd, &wr, nullptr) || wr != rd) {
            ok = false;
            break;
        }
        left -= rd;
    }
    if (g_stop) ok = false;
    if (ok && haveTimes) SetFileTime(dst, &ct, &at, &wt);
    if (ok) ok = FlushFileBuffers(dst) != 0;
    LARGE_INTEGER dsz;
    if (ok) ok = GetFileSizeEx(dst, &dsz) && (unsigned long long)dsz.QuadPart == head.size() + ((unsigned long long)fsz.QuadPart - audioOff);
    if (!CloseHandle(dst)) ok = false;

    CloseHandle(src);
    src = INVALID_HANDLE_VALUE;
    if (!ok) {
        Wh_Log(L"Empotrar: fallo copiando el audio de '%s'", path.c_str());
        DeleteFileW(tmp.c_str());
        return EMB_ERROR;
    }
    if (!CvVerifyEmbeddedFile(tmp, build.title, build.artist, wantedImageHash, needCover,
                              needAlbum ? albumOverride : std::wstring(),
                              needYear ? wantYear : std::wstring(), wantComment)) {
        Wh_Log(L"Empotrar: verificacion ID3 fallida en el temporal; se conserva el MP3 original (%s)", path.c_str());
        DeleteFileW(tmp.c_str());
        return EMB_ERROR;
    }

    if (g_embedWantSize != 0) {
        unsigned long long sz2 = 0, ft2 = 0;
        if (!CvFileStamp(path, sz2, ft2) || sz2 != g_embedWantSize || ft2 != g_embedWantTime) {
            Wh_Log(L"Empotrar: '%s' ha cambiado desde que se localizo; NO se escribe", path.c_str());
            DeleteFileW(tmp.c_str());
            return EMB_ERROR;
        }
    }

    if (!CvMutationIdentityStillMatches(path, embedSourceIdentity)) {
        Wh_Log(L"Empotrar: '%s' fue sustituido durante la preparacion; NO se escribe", path.c_str());
        DeleteFileW(tmp.c_str());
        return EMB_ERROR;
    }

    if (!Mp3MediaSafeForMutation() || !CvFileExclusivelyAvailable(path)) {
        DeleteFileW(tmp.c_str());
        Wh_Log(L"MP3PEND: Incrustar sigue pendiente: sesion o archivo ocupado antes de ReplaceFileW");
        return EMB_LOCKED;
    }
    Wh_Log(L"MP3DIAG: REPLACEFILE inicio tick=%llu; archivo temporal validado, sesiones inactivas",
           (unsigned long long)GetTickCount64());

    const bool moved = ReplaceFileW(path.c_str(), tmp.c_str(), nullptr, 0, nullptr, nullptr) != 0;
    const DWORD lastErr = moved ? ERROR_SUCCESS : GetLastError();
    if (moved) Wh_Log(L"MP3DIAG: REPLACEFILE exito tick=%llu",
                      (unsigned long long)GetTickCount64());
    if (!moved) {
        Wh_Log(L"Empotrar: no se pudo sustituir atomicamente '%s' (error %u); requiere nueva confirmacion",
               path.c_str(), lastErr);
        DeleteFileW(tmp.c_str());
        return (lastErr == ERROR_SHARING_VIOLATION || lastErr == ERROR_ACCESS_DENIED ||
                lastErr == ERROR_LOCK_VIOLATION || lastErr == ERROR_UNABLE_TO_REMOVE_REPLACED)
                   ? EMB_LOCKED : EMB_ERROR;
    }
    Wh_Log(L"Empotrar: ESCRITO '%s' (portada=%d titulo=%d interprete=%d)", path.c_str(), needCover ? 1 : 0,
           needTitle ? 1 : 0, needArtist ? 1 : 0);
    return EMB_OK;
}

// Estimate MP3 duration from the Xing frame count or the payload size and frame bitrate.

static bool CvFileIdOf(const std::wstring& path, CvFileId& out) {
    out = CvFileId();
    HANDLE h = CreateFileW(path.c_str(), 0,
                           FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                           OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    FILE_ID_INFO fi;
    memset(&fi, 0, sizeof(fi));
    bool ok = GetFileInformationByHandleEx(h, FileIdInfo, &fi, sizeof(fi)) != 0;
    CloseHandle(h);
    if (!ok) return false;
    out.vol = fi.VolumeSerialNumber;
    memcpy(out.id, fi.FileId.Identifier, 16);
    out.ok = true;
    return true;
}

static std::wstring CvIdTagOf(const std::wstring& path) {
    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ,
                           FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return std::wstring();
    Id3Info info;
    std::vector<BYTE> tag;
    bool ok = CvReadTag(h, info, tag);
    CloseHandle(h);
    if (!ok) return std::wstring();
    const std::wstring pre = L"GCID:";
    if (info.gcid.size() <= pre.size()) return std::wstring();
    if (info.gcid.compare(0, pre.size(), pre) != 0) return std::wstring();
    std::wstring id = Trim(info.gcid.substr(pre.size()));
    for (size_t i = 0; i < id.size(); i++)
        if (!iswxdigit((wint_t)id[i])) return std::wstring();
    return id;
}

static std::wstring CvFileIdStr(const std::wstring& path) {
    std::wstring t = CvIdTagOf(path);
    if (!t.empty()) return t;
    CvFileId fid;
    if (!CvFileIdOf(path, fid)) return std::wstring();
    static const wchar_t* hex = L"0123456789ABCDEF";
    std::wstring o;
    for (int sh = 60; sh >= 0; sh -= 4) o += hex[(fid.vol >> sh) & 0xF];
    for (int i = 0; i < 16; i++) {
        o += hex[(fid.id[i] >> 4) & 0xF];
        o += hex[fid.id[i] & 0xF];
    }
    return o;
}

static bool CvFileStamp(const std::wstring& path, unsigned long long& size, unsigned long long& ft) {
    WIN32_FILE_ATTRIBUTE_DATA d;
    if (!GetFileAttributesExW(path.c_str(), GetFileExInfoStandard, &d)) return false;
    size = ((unsigned long long)d.nFileSizeHigh << 32) | d.nFileSizeLow;
    ft = ((unsigned long long)d.ftLastWriteTime.dwHighDateTime << 32) | d.ftLastWriteTime.dwLowDateTime;
    return true;
}

// Read duration from Xing or estimate it from a frame bitrate and the audio size.
static int CvMp3Duration(const std::wstring& path) {
    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ,
                           FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return 0;
    LARGE_INTEGER sz;
    if (!GetFileSizeEx(h, &sz)) { CloseHandle(h); return 0; }
    BYTE hdr[10];
    DWORD rd = 0;
    unsigned long long off = 0;
    if (ReadFile(h, hdr, 10, &rd, nullptr) && rd == 10 && memcmp(hdr, "ID3", 3) == 0)
        off = 10ULL + CvSynchsafe(hdr + 6);
    std::vector<BYTE> b(16384);
    LARGE_INTEGER p;
    p.QuadPart = (LONGLONG)off;
    SetFilePointerEx(h, p, nullptr, FILE_BEGIN);
    if (!ReadFile(h, b.data(), (DWORD)b.size(), &rd, nullptr) || rd < 16) { CloseHandle(h); return 0; }
    int res = 0;
    static const int br1[16] = {0,32,40,48,56,64,80,96,112,128,160,192,224,256,320,0};
    static const int br2[16] = {0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,0};
    static const int sr1[4] = {44100,48000,32000,0};
    for (DWORD i = 0; i + 16 <= rd; i++) {
        if (b[i] != 0xFF || (b[i + 1] & 0xE0) != 0xE0) continue;
        int ver = (b[i + 1] >> 3) & 3;
        int layer = (b[i + 1] >> 1) & 3;
        if (ver == 1 || layer != 1) continue;
        int brIdx = (b[i + 2] >> 4) & 0xF;
        int srIdx = (b[i + 2] >> 2) & 3;
        if (brIdx == 0 || brIdx == 15 || srIdx == 3) continue;
        int sr = sr1[srIdx] >> (ver == 3 ? 0 : (ver == 2 ? 1 : 2));
        int br = (ver == 3 ? br1[brIdx] : br2[brIdx]) * 1000;
        if (!sr || !br) continue;
        int spf = (ver == 3) ? 1152 : 576;
        int side = (ver == 3) ? (((b[i + 3] >> 6) == 3) ? 17 : 32) : (((b[i + 3] >> 6) == 3) ? 9 : 17);
        DWORD xi = i + 4 + (DWORD)side;
        if (xi + 12 <= rd && (!memcmp(b.data() + xi, "Xing", 4) || !memcmp(b.data() + xi, "Info", 4))) {
            unsigned flags = CvBE32(b.data() + xi + 4);
            if (flags & 1) {
                unsigned frames = CvBE32(b.data() + xi + 8);
                if (frames > 0) { res = (int)((unsigned long long)frames * (unsigned)spf / (unsigned)sr); break; }
            }
        }
        unsigned long long audio = (unsigned long long)sz.QuadPart - off;
        res = (int)(audio * 8ULL / (unsigned)br);
        break;
    }
    CloseHandle(h);
    return res;
}

static std::wstring MediaCurrentPath();

static void MxRefreshTagsOk(const std::wstring& artist, const std::wstring& title) {
    std::wstring key = CvKeyFor(MediaCurrentPath(), artist, title);
    bool ok = false;
    if (!key.empty()) {
        std::wstring img = CvCacheDir() + L"\\" + key + L".img";

        if (CvFileExists(CvCacheDir() + L"\\" + key + L".emb2")) ok = true;
        (void)img;
    }
    g.media.tagsOk = ok;
}

// Validate a candidate with sanitized tags and filename evidence.
static bool CvVerifyMp3(const std::wstring& path, const std::wstring& nameNorm, const std::wstring& dirNorm,
                        const std::wstring& title, const std::wstring& artist) {
    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    Id3Info info;
    std::vector<BYTE> tag;
    bool ok = CvReadTag(h, info, tag);
    CloseHandle(h);
    if (!ok) return false;

    if (!info.title.empty() && !CvTitleOk(info.title, title) &&
        !CvLoose(nameNorm, CvNorm(CvCoreTitle(title)))) return false;

    if (info.title.empty() && !CvLoose(nameNorm, CvNorm(CvCoreTitle(title)))) return false;
    if (CvNoArtist(artist)) return true;

    std::wstring nA = CvNorm(CvPrimaryArtist(artist));

    if (!info.artist.empty() && CvArtistOk(info.artist, artist)) return true;
    return nA.size() >= 2 && (nameNorm.find(nA) != std::wstring::npos || dirNorm.find(nA) != std::wstring::npos);
}

struct CvCand { std::wstring path; float nameScore; int dur; long long durDiff; };

static std::wstring g_mediaIdWant;

// Collect MP3 candidates within configured search roots.
static void CvCollectMp3(const std::wstring& root, const std::wstring& nTitle,
                         const std::wstring& title, const std::wstring& artist,
                         int depth, int& budget, ULONGLONG deadline,
                         std::vector<CvCand>& out) {
    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileExW((root + L"\\*").c_str(), FindExInfoBasic, &fd,
                                FindExSearchNameMatch, nullptr, FIND_FIRST_EX_LARGE_FETCH);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        if (g_stop || budget <= 0 || GetTickCount64() > deadline) break;
        std::wstring name = fd.cFileName;
        if (name == L"." || name == L"..") continue;
        std::wstring full = root + L"\\" + name;
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if ((fd.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) || depth >= 8) continue;
            CvCollectMp3(full, nTitle, title, artist, depth + 1, budget, deadline, out);
            continue;
        }
        size_t dot = name.rfind(L'.');
        if (dot == std::wstring::npos) continue;
        std::wstring ext = name.substr(dot);
        for (size_t i = 0; i < ext.size(); i++) ext[i] = (wchar_t)towlower((wint_t)ext[i]);
        if (ext != L".mp3") continue;
        budget--;
        std::wstring nName = CvNorm(name.substr(0, dot));
        if (!CvLoose(nName, nTitle)) continue;
        if (!CvVerifyMp3(full, nName, CvNorm(root), title, artist)) continue;

        if (!g_mediaIdWant.empty()) {
            std::wstring cid = CvIdTagOf(full);
            if (!cid.empty() && cid != g_mediaIdWant) {
                Wh_Log(L"Empotrar: se descarta '%s' (lleva otro DNI)", full.c_str());
                continue;
            }
        }
        CvCand c;
        c.path = full;

        c.nameScore = (float)nTitle.size() / (float)std::max<size_t>(nName.size(), 1);
        c.dur = 0;
        c.durDiff = -1;
        out.push_back(c);
    } while (FindNextFileW(h, &fd));
    FindClose(h);
}

static void CvListMp3(const std::wstring& root, int depth, std::vector<std::wstring>& out) {
    if (depth > 8 || out.size() > 20000) return;
    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileExW((root + L"\\*").c_str(), FindExInfoBasic, &fd,
                                FindExSearchNameMatch, nullptr, FIND_FIRST_EX_LARGE_FETCH);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        if (wcscmp(fd.cFileName, L".") == 0 || wcscmp(fd.cFileName, L"..") == 0) continue;
        std::wstring full = root + L"\\" + fd.cFileName;
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (fd.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) continue;
            CvListMp3(full, depth + 1, out);
            continue;
        }
        std::wstring name = fd.cFileName;
        size_t dot = name.rfind(L'.');
        if (dot == std::wstring::npos) continue;
        std::wstring ext = name.substr(dot);
        for (size_t i = 0; i < ext.size(); i++) ext[i] = (wchar_t)towlower((wint_t)ext[i]);
        if (ext == L".mp3") out.push_back(full);
    } while (FindNextFileW(h, &fd));
    FindClose(h);
}

static std::wstring CvReadCacheText(const std::wstring& p) {
    std::vector<BYTE> b;
    if (!CvReadFile(p, b, 8192) || b.size() < 4) return std::wstring();
    std::wstring w(reinterpret_cast<const wchar_t*>(b.data()), b.size() / sizeof(wchar_t));
    while (!w.empty() && w.back() == L'\0') w.pop_back();
    return w;
}

static bool CvUndoPendingMatchesCurrentAudio(const std::wstring& path, bool& matches) {
    matches = false;
    std::wstring pending = CvUndoPendingPath(path);
    std::vector<BYTE> buf;
    if (pending.empty() || !CvReadFile(pending, buf, 20u << 20)) return false;
    CvUndoRecord record;
    if (!CvUndoParseRecord(buf, path, record)) return false;
    unsigned long long savedBytes = record.audioBytes, savedHash = record.audioHash;
    unsigned long long currentBytes = 0, currentHash = 0;
    if (!CvUndoAudioFingerprint(path, currentBytes, currentHash)) return false;
    matches = currentBytes == savedBytes && currentHash == savedHash;
    return true;
}

// Prepare undo before changing any tags and retain the backup until the write can be reconciled.
static CvEmbedRes CvEmbed(const std::wstring& path, const std::vector<BYTE>& img,
                          const std::wstring& wantTitle, const std::wstring& wantArtist,
                          const std::wstring& yearOverride, const std::wstring& albumOverride,
                          const CvFileId& approvedSource) {

    if (!Mp3MediaSafeForMutation() || !CvFileExclusivelyAvailable(path)) return EMB_LOCKED;
    CvUndoRecoverArtifacts(path);
    SrwGuard mutationGuard(&g_cvFileMutationLock);

    std::wstring oldPending = CvUndoPendingPath(path);
    if (!oldPending.empty() && CvFileExists(oldPending)) {
        bool pendingMatches = false;
        if (!CvUndoPendingMatchesCurrentAudio(path, pendingMatches)) {
            Wh_Log(L"Empotrar: no se pudo validar el respaldo pendiente; se conserva y no se modifica '%s'",
                   path.c_str());
            return EMB_ERROR;
        }
        if (!pendingMatches) {
            DeleteFileW(oldPending.c_str());
            Wh_Log(L"Empotrar: se descarta un respaldo pendiente obsoleto de '%s'", path.c_str());
        } else if (!CvUndoCommit(path)) {
            Wh_Log(L"Empotrar: existe un respaldo pendiente que no se pudo consolidar; no se modifica '%s'",
                   path.c_str());
            return EMB_ERROR;
        }
    }
    std::vector<BYTE> origHead;
    CvFileId snapshotIdentity;
    const bool haveSnap = CvUndoSnapshot(path, origHead, snapshotIdentity);
    if (!haveSnap || !approvedSource.Same(snapshotIdentity)) {
        Wh_Log(L"Empotrar: no se pudo capturar una copia ID3 consistente de '%s'; no se modifica", path.c_str());
        return EMB_ERROR;
    }
    if (!CvUndoPrepare(path, origHead, snapshotIdentity)) {
        Wh_Log(L"Empotrar: no se pudo persistir el respaldo previo de '%s'; no se modifica", path.c_str());
        return EMB_ERROR;
    }
    CvEmbedRes r = CvEmbedCore(path, img, wantTitle, wantArtist, yearOverride, albumOverride,
                               snapshotIdentity, false);
    if (r == EMB_OK) {
        InterlockedExchange(&g_embedLocked, 0);
        if (CvUndoCommit(path)) Wh_Log(L"Deshacer: respaldo previo consolidado para '%s'", path.c_str());
        else Wh_Log(L"Deshacer: respaldo previo conservado como pendiente para '%s'", path.c_str());
    } else {

        std::wstring pending = CvUndoPendingPath(path);
        if (!pending.empty()) DeleteFileW(pending.c_str());
    }
    return r;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

struct FpResult {
    bool ok = false;
    int scorePct = 0;
    std::wstring mbid, title, artist, year, album;
    std::vector<std::wstring> releases;
};
static SRWLOCK g_fpLock = SRWLOCK_INIT;
static SRWLOCK g_fpMemoLock = SRWLOCK_INIT;
static std::vector<std::pair<std::wstring, ULONGLONG> > g_fpFailed;

static bool JsonTopString(const std::string& obj, const char* key, std::string& out) {
    int depth = 0;
    bool inStr = false;
    const std::string pat = std::string("\"") + key + "\"";
    for (size_t i = 0; i < obj.size(); i++) {
        char c = obj[i];
        if (inStr) {
            if (c == '\\') i++;
            else if (c == '"') inStr = false;
            continue;
        }
        if (c == '"') {
            if (depth == 1 && obj.compare(i, pat.size(), pat) == 0) {
                size_t j = i + pat.size();
                while (j < obj.size() && (obj[j] == ' ' || obj[j] == ':')) j++;
                if (j < obj.size() && obj[j] == '"') {
                    j++;
                    out.clear();
                    while (j < obj.size() && obj[j] != '"') {
                        if (obj[j] == '\\' && j + 1 < obj.size()) j++;
                        out += obj[j];
                        j++;
                    }
                    return true;
                }
            }
            inStr = true;
            continue;
        }
        if (c == '{' || c == '[') depth++;
        else if (c == '}' || c == ']') depth--;
    }
    return false;
}

static void JsonArrayObjects(const std::string& js, const char* key, std::vector<std::string>& objs) {
    objs.clear();
    size_t p = js.find(std::string("\"") + key + "\"");
    if (p == std::string::npos) return;
    p = js.find('[', p);
    if (p == std::string::npos) return;
    int depth = 0;
    bool inStr = false;
    size_t start = std::string::npos;
    for (size_t i = p + 1; i < js.size(); i++) {
        char c = js[i];
        if (inStr) {
            if (c == '\\') i++;
            else if (c == '"') inStr = false;
            continue;
        }
        if (c == '"') {
            inStr = true;
        } else if (c == '{') {
            if (depth == 0) start = i;
            depth++;
        } else if (c == '[') {
            depth++;
        } else if (c == '}') {
            depth--;
            if (depth == 0 && start != std::string::npos) {
                objs.push_back(js.substr(start, i - start + 1));
                start = std::string::npos;
            }
        } else if (c == ']') {
            if (depth == 0) break;
            depth--;
        }
    }
}

static bool JsonTopNumber(const std::string& obj, const char* key, double& out) {
    int depth = 0;
    bool inStr = false;
    const std::string pat = std::string("\"") + key + "\"";
    for (size_t i = 0; i < obj.size(); ++i) {
        const char c = obj[i];
        if (inStr) {
            if (c == '\\') ++i;
            else if (c == '"') inStr = false;
            continue;
        }
        if (c == '"') {
            if (depth == 1 && obj.compare(i, pat.size(), pat) == 0) {
                size_t j = i + pat.size();
                while (j < obj.size() && (obj[j] == ' ' || obj[j] == '\t' ||
                    obj[j] == '\n' || obj[j] == '\r')) ++j;
                if (j >= obj.size() || obj[j] != ':') return false;
                ++j;
                while (j < obj.size() && (obj[j] == ' ' || obj[j] == '\t' ||
                    obj[j] == '\n' || obj[j] == '\r')) ++j;
                if (j >= obj.size()) return false;
                const char* begin = obj.c_str() + j;
                char* end = nullptr;
                const double v = strtod(begin, &end);
                if (end == begin || !(v == v) || v > 1.0e15 || v < -1.0e15) return false;

                if (end < obj.c_str() + obj.size() &&
                    *end != ',' && *end != '}' && *end != ' ' &&
                    *end != '\n' && *end != '\r' && *end != '\t') return false;
                out = v;
                return true;
            }
            inStr = true;
        } else if (c == '{' || c == '[') ++depth;
        else if (c == '}' || c == ']') --depth;
    }
    return false;
}

static bool FpValidRecordingId(const std::string& id) {
    if (id.size() != 36) return false;
    for (size_t i = 0; i < id.size(); ++i) {
        const bool hyphen = i == 8 || i == 13 || i == 18 || i == 23;
        if (hyphen) { if (id[i] != '-') return false; }
        else if (!((id[i] >= '0' && id[i] <= '9') ||
                   (id[i] >= 'a' && id[i] <= 'f') ||
                   (id[i] >= 'A' && id[i] <= 'F'))) return false;
    }
    return true;
}

#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <mferror.h>
#include <propidl.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <algorithm>

namespace gc83 {

class MfComPtrBase {
public:
    template<class T> static void Release(T*& p) { if (p) { p->Release(); p = nullptr; } }
};

template<class T>
class MfComPtr {
    T* p_ = nullptr;
public:
    MfComPtr() = default;
    ~MfComPtr() { reset(); }
    MfComPtr(const MfComPtr&) = delete;
    MfComPtr& operator=(const MfComPtr&) = delete;
    T** put() { reset(); return &p_; }
    T* get() const { return p_; }
    T* operator->() const { return p_; }
    explicit operator bool() const { return p_ != nullptr; }
    void reset() { MfComPtrBase::Release(p_); }
};

static double FpSelectFullDuration(double declaredSeconds, uint64_t decodedFrames,
                                   unsigned sampleRate, bool reachedEndOfStream) {
    const bool declaredValid = std::isfinite(declaredSeconds) &&
                               declaredSeconds >= 1.0 && declaredSeconds <= 21600.0;
    if (reachedEndOfStream && sampleRate != 0u && decodedFrames != 0u) {
        const double observed = (double)decodedFrames / (double)sampleRate;
        if (std::isfinite(observed) && observed >= 1.0 && observed <= 21600.0 &&
            (!declaredValid || std::fabs(declaredSeconds - observed) > 0.5))
            return observed;
    }
    return declaredValid ? declaredSeconds : 0.0;
}

// Use Media Foundation to decode local audio for the fingerprint pipeline.
static bool DecodeMp3ToMonoPcm16(const std::wstring& path,
                                 std::vector<short>& pcm,
                                 unsigned& sampleRate,
                                 double& durationSeconds,
                                 unsigned maxSeconds = 120) {
    pcm.clear();
    sampleRate = 0;
    durationSeconds = 0.0;
    if (path.empty() || maxSeconds == 0) return false;

    HRESULT hrCo = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    const bool uninitCom = SUCCEEDED(hrCo);
    if (FAILED(hrCo) && hrCo != RPC_E_CHANGED_MODE) return false;

    HRESULT hr = MFStartup(MF_VERSION, MFSTARTUP_FULL);
    if (FAILED(hr)) {
        if (uninitCom) CoUninitialize();
        return false;
    }

    bool ok = false;
    try {
    do {
        MfComPtr<IMFSourceReader> reader;
        hr = MFCreateSourceReaderFromURL(path.c_str(), nullptr, reader.put());
        if (FAILED(hr) || !reader) break;

        PROPVARIANT duration;
        PropVariantInit(&duration);
        if (SUCCEEDED(reader->GetPresentationAttribute(MF_SOURCE_READER_MEDIASOURCE,
                                                       MF_PD_DURATION, &duration)) &&
            duration.vt == VT_UI8) {
            durationSeconds = static_cast<double>(duration.uhVal.QuadPart) / 10000000.0;
        }
        PropVariantClear(&duration);

        MfComPtr<IMFMediaType> nativeType;
        hr = reader->GetNativeMediaType(MF_SOURCE_READER_FIRST_AUDIO_STREAM, 0, nativeType.put());
        if (FAILED(hr) || !nativeType) break;
        UINT32 nativeChannels = 0, nativeRate = 0;
        if (FAILED(nativeType->GetUINT32(MF_MT_AUDIO_NUM_CHANNELS, &nativeChannels)) ||
            nativeChannels < 1 || nativeChannels > 2 ||
            FAILED(nativeType->GetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, &nativeRate)) ||
            nativeRate < 8000 || nativeRate > 96000) break;

        MfComPtr<IMFMediaType> type;
        hr = MFCreateMediaType(type.put());
        if (FAILED(hr) || !type) break;
        hr = type->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Audio);
        if (SUCCEEDED(hr)) hr = type->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_PCM);
        if (SUCCEEDED(hr)) hr = type->SetUINT32(MF_MT_AUDIO_NUM_CHANNELS, nativeChannels);
        if (SUCCEEDED(hr)) hr = type->SetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, nativeRate);
        if (SUCCEEDED(hr)) hr = type->SetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE, 16);
        const UINT32 nativeBlockAlign = nativeChannels * sizeof(short);
        if (SUCCEEDED(hr)) hr = type->SetUINT32(MF_MT_AUDIO_BLOCK_ALIGNMENT, nativeBlockAlign);
        if (SUCCEEDED(hr)) hr = type->SetUINT32(MF_MT_AUDIO_AVG_BYTES_PER_SECOND,
                                                 nativeRate * nativeBlockAlign);
        UINT32 channelMask = 0;
        if (SUCCEEDED(nativeType->GetUINT32(MF_MT_AUDIO_CHANNEL_MASK, &channelMask)))
            type->SetUINT32(MF_MT_AUDIO_CHANNEL_MASK, channelMask);
        if (SUCCEEDED(hr)) hr = reader->SetCurrentMediaType(MF_SOURCE_READER_FIRST_AUDIO_STREAM, nullptr, type.get());
        if (FAILED(hr)) break;

        MfComPtr<IMFMediaType> actual;
        hr = reader->GetCurrentMediaType(MF_SOURCE_READER_FIRST_AUDIO_STREAM, actual.put());
        if (FAILED(hr) || !actual) break;
        GUID subtype{};
        UINT32 channels = 0, rate = 0, bits = 0;
        if (FAILED(actual->GetGUID(MF_MT_SUBTYPE, &subtype)) || subtype != MFAudioFormat_PCM ||
            FAILED(actual->GetUINT32(MF_MT_AUDIO_NUM_CHANNELS, &channels)) || channels != nativeChannels ||
            FAILED(actual->GetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, &rate)) || rate != nativeRate ||
            FAILED(actual->GetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE, &bits)) || bits != 16) break;
        sampleRate = rate;
        const size_t frameBytes = (size_t)channels * sizeof(short);
        const size_t maxSamples = static_cast<size_t>(maxSeconds) * rate;
        pcm.reserve(std::min<size_t>(maxSamples, (size_t)rate * 30u));
        bool reachedEndOfStream = false;
        uint64_t decodedFrames = 0;
        unsigned consecutiveEmptyReads = 0;
        for (;;) {
            DWORD streamIndex = 0, flags = 0;
            LONGLONG timestamp = 0;
            MfComPtr<IMFSample> sample;
            hr = reader->ReadSample(MF_SOURCE_READER_FIRST_AUDIO_STREAM, 0,
                                    &streamIndex, &flags, &timestamp, sample.put());
            if (FAILED(hr)) { pcm.clear(); break; }

            if (flags & (MF_SOURCE_READERF_ERROR |
                         MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED |
                         MF_SOURCE_READERF_NATIVEMEDIATYPECHANGED)) {
                pcm.clear();
                break;
            }
            bool sampleHadFrames = false;
            if (sample) {
                MfComPtr<IMFMediaBuffer> buffer;
                hr = sample->ConvertToContiguousBuffer(buffer.put());
                if (FAILED(hr) || !buffer) { pcm.clear(); break; }
                BYTE* data = nullptr;
                DWORD maxLength = 0, currentLength = 0;
                hr = buffer->Lock(&data, &maxLength, &currentLength);
                if (FAILED(hr)) { pcm.clear(); break; }
                const bool validBuffer = data != nullptr && currentLength <= maxLength &&
                                         frameBytes != 0 && (currentLength % frameBytes) == 0;
                if (!validBuffer) {
                    buffer->Unlock();
                    pcm.clear();
                    break;
                }
                const size_t frames = currentLength / frameBytes;
                sampleHadFrames = (frames > 0u);
                if (sampleHadFrames) consecutiveEmptyReads = 0;

                decodedFrames += (uint64_t)frames;
                if (decodedFrames > (uint64_t)rate * 21600u) {
                    buffer->Unlock();
                    pcm.clear();
                    break;
                }
                const size_t take = std::min(frames, maxSamples - pcm.size());
                if (take) {
                    const short* samples = reinterpret_cast<const short*>(data);
                    if (channels == 1) {
                        pcm.insert(pcm.end(), samples, samples + take);
                    } else {
                        for (size_t i = 0; i < take; ++i) {
                            const int32_t mixed = (int32_t)samples[i * 2] + (int32_t)samples[i * 2 + 1];
                            pcm.push_back((short)(mixed / 2));
                        }
                    }
                }
                const HRESULT unlockHr = buffer->Unlock();
                if (FAILED(unlockHr)) { pcm.clear(); break; }
            }
            if (flags & MF_SOURCE_READERF_ENDOFSTREAM) {
                reachedEndOfStream = true;
                break;
            }

            if (!sampleHadFrames && ++consecutiveEmptyReads > 128u) {
                pcm.clear();
                break;
            }
        }

        durationSeconds = FpSelectFullDuration(durationSeconds, decodedFrames,
                                                sampleRate, reachedEndOfStream);
        ok = reachedEndOfStream && sampleRate != 0 &&
             pcm.size() >= (size_t)sampleRate * 8u &&
             durationSeconds >= 1.0 && durationSeconds <= 21600.0;
    } while (false);
    } catch (...) {
        pcm.clear();
        ok = false;
    }

    MFShutdown();
    if (uninitCom) CoUninitialize();
    if (!ok) pcm.clear();
    return ok;
}

} // namespace gc83

/*
# Third-party notices

Desktop Glass Cards bundles portions of [Chromaprint 1.6.2](https://github.com/acoustid/chromaprint/tree/v1.6.2) and its bundled [Kiss FFT](https://github.com/acoustid/chromaprint/tree/v1.6.2/src/3rdparty/kissfft). The original source and per-file notices are retained in the C++ file. The mod uses Kiss FFT and supplies its own resampled PCM. The optional internal FFmpeg resampler is disabled.

These notices apply to the listed third-party components.

## Chromaprint — MIT

Copyright (c) 2010-2016 Lukas Lalinsky

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

## Kiss FFT — BSD 3-Clause

Copyright (c) 2003-2010 Mark Borgerding. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

// Chromaprint 1.6.2 amalgamation generated for Windhawk single-translation-unit integration.
// MIT license: retain upstream LICENSE.md in distributed source package.
// Internal FFmpeg avresample is disabled; input is normalized by the mod to mono PCM16 at 11025 Hz.
#ifndef HAVE_CONFIG_H
#define HAVE_CONFIG_H 1
#endif
#ifndef CHROMAPRINT_NODLL
#define CHROMAPRINT_NODLL 1
#endif
#ifndef USE_KISSFFT
#define USE_KISSFFT 1
#endif
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>
#include <limits>

// Generated Chromaprint config.h (USE_INTERNAL_AVRESAMPLE intentionally disabled).
#define HAVE_ROUND 1
#define HAVE_LRINTF 1
/* #undef HAVE_AV_PACKET_UNREF */
/* #undef HAVE_AV_FRAME_ALLOC */
/* #undef HAVE_AV_FRAME_FREE */

#define TESTS_DIR ""

/* #undef USE_SWRESAMPLE */
/* #undef USE_AVRESAMPLE */
/* #undef USE_INTERNAL_AVRESAMPLE */

/* #undef USE_AVTX */
/* #undef USE_AVFFT */
/* #undef USE_FFTW3 */
/* #undef USE_FFTW3F */
/* #undef USE_VDSP */
#define USE_KISSFFT 1

#line 1 "src/audio_processor.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <assert.h>
#include <algorithm>
#include <stdio.h>
#ifdef HAVE_CONFIG_H

// [omitido por inclusión previa: config.h]
#endif

#if USE_INTERNAL_AVRESAMPLE
extern "C" {
// Internal FFmpeg avresample disabled: LGPL header intentionally excluded.
}
#endif


#line 1 "src/debug.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_DEBUG_H_
#define CHROMAPRINT_DEBUG_H_

#ifdef NDEBUG
#include <ostream>
#else
#include <iostream>
#endif

namespace chromaprint {

#ifdef DEBUG
#undef DEBUG
#endif

#ifdef NDEBUG
#define DEBUG(x)
#else
#define DEBUG(x) std::cerr << x << std::endl
#endif

}; // namespace chromaprint

#endif

#line 1 "src/debug.h [fin]"

#line 1 "src/audio_processor.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_AUDIO_PROCESSOR_H_
#define CHROMAPRINT_AUDIO_PROCESSOR_H_


#line 1 "src/utils.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_UTILS_H_
#define CHROMAPRINT_UTILS_H_

#if defined(HAVE_CONFIG_H)

// [omitido por inclusión previa: config.h]
#endif

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <algorithm>
#include <limits>
#include <iterator>

// [omitido por inclusión previa: src/debug.h]

#define CHROMAPRINT_DISABLE_COPY(ClassName) \
	ClassName(const ClassName &);			\
	void operator=(const ClassName &);

namespace chromaprint {

#ifndef HAVE_ROUND
static inline double round(double x)
{
   if (x >= 0.0)
      return floor(x + 0.5);
   else
      return ceil(x - 0.5);
}
#endif

template<class RandomAccessIterator>
void PrepareHammingWindow(RandomAccessIterator first, RandomAccessIterator last, double scale = 1.0)
{
	int i = 0;
	const auto size = std::distance(first, last);
	while (first != last) {
		*first++ = scale * (0.54 - 0.46 * cos(i++ * 2.0 * M_PI / (size - 1)));
	}
}

template <typename InputIt, typename WindowIt, typename OutputIt>
void ApplyWindow(InputIt first, InputIt last, WindowIt &window, OutputIt &output)
{
	auto input = first;
	while (input != last) {
		*output = *input * *window;
		++input;
		++window;
		++output;
	}
}

template<class Iterator>
typename std::iterator_traits<Iterator>::value_type Sum(Iterator first, Iterator last)
{
	typename std::iterator_traits<Iterator>::value_type sum = 0;
	while (first != last) {
		sum += *first;
		++first;
	}
	return sum;
}

template<class Iterator>
typename std::iterator_traits<Iterator>::value_type EuclideanNorm(Iterator first, Iterator last)
{
	typename std::iterator_traits<Iterator>::value_type squares = 0;
	while (first != last) {
		squares += *first * *first;
		++first;
	}
	return (squares > 0) ? sqrt(squares) : 0;
}

template<class Iterator, class Func>
void NormalizeVector(Iterator first, Iterator last, Func func, double threshold = 0.01)
{
	double norm = func(first, last);
	if (norm < threshold) {
		std::fill(first, last, 0.0);
	}
	else {
		while (first != last) {
			*first /= norm;
			++first;
		}
	}
}

inline int GrayCode(int i)
{
	static const unsigned char CODES[] = { 0, 1, 3, 2 };
	return CODES[i];
}

inline double IndexToFreq(int i, int frame_size, int sample_rate)
{
	return double(i) * sample_rate / frame_size;
}

inline int FreqToIndex(double freq, int frame_size, int sample_rate)
{
	return (int)round(frame_size * freq / sample_rate);
}

template<class T>
inline bool IsNaN(T value)
{
	return value != value;
}

inline double FreqToBark(double f)
{
	double z = (26.81 * f) / (1960.0 + f) - 0.53;

	if (z < 2.0) {
		z = z + 0.15 * (2.0 - z);
	} else if (z > 20.1) {
		z = z + 0.22 * (z - 20.1);
	}

	return z;
}

// https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel
#define CHROMAPRINT_POPCNT_IMPL(T) \
	v = v - ((v >> 1) & (T)~(T)0/3);                           \
	v = (v & (T)~(T)0/15*3) + ((v >> 2) & (T)~(T)0/15*3);      \
	v = (v + (v >> 4)) & (T)~(T)0/255*15;                      \
	c = (T)(v * ((T)~(T)0/255)) >> (sizeof(T) - 1) * CHAR_BIT; \

#ifdef __GNUC__
#define CHROMAPRINT_POPCNT_IMPL_32 c = __builtin_popcount(v);
#define CHROMAPRINT_POPCNT_IMPL_64 c = __builtin_popcountll(v);
#else
#define CHROMAPRINT_POPCNT_IMPL_32 CHROMAPRINT_POPCNT_IMPL(uint32_t)
#define CHROMAPRINT_POPCNT_IMPL_64 CHROMAPRINT_POPCNT_IMPL(uint64_t)
#endif

template<typename T, int Size, bool IsSigned>
struct _CountSetBits_Impl {
	static unsigned int Do(T v) {
		return T::not_implemented;
	}
};

template<typename T>
inline unsigned int CountSetBits(T v) {
	return _CountSetBits_Impl<T, sizeof(T), std::numeric_limits<T>::is_signed>::Do(v);
}

template<typename T, int Size>
struct _CountSetBits_Impl<T, Size, true> {
	static unsigned int Do(T v) {
		return CountSetBits(SignedToUnsigned(v));
	}
};

template<typename T>
struct _CountSetBits_Impl<T, 4, false> {
	static unsigned int Do(T v) {
		unsigned int c;
		CHROMAPRINT_POPCNT_IMPL_32;
		return c;
	}
};

template<typename T>
struct _CountSetBits_Impl<T, 8, false> {
	static unsigned int Do(T v) {
		unsigned int c;
		CHROMAPRINT_POPCNT_IMPL_64;
		return c;
	}
};

#undef CHROMAPRINT_POPCNT_IMPL
#undef CHROMAPRINT_POPCNT_IMPL_32
#undef CHROMAPRINT_POPCNT_IMPL_64

template<typename T>
inline unsigned int HammingDistance(T a, T b) {
	return CountSetBits(a ^ b);
}

}; // namespace chromaprint

#endif

#line 1 "src/utils.h [fin]"

#line 1 "src/audio_consumer.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_AUDIO_CONSUMER_H_
#define CHROMAPRINT_AUDIO_CONSUMER_H_

namespace chromaprint {

class AudioConsumer {
public:
	virtual ~AudioConsumer() {}
	virtual void Consume(const int16_t *input, int length) = 0;
};

}; // namespace chromaprint

#endif

#line 1 "src/audio_consumer.h [fin]"
#include <vector>

struct AVResampleContext;

namespace chromaprint
{

	class AudioProcessor : public AudioConsumer
	{
	public:
		AudioProcessor(int sample_rate, AudioConsumer *consumer);
		virtual ~AudioProcessor();

		int target_sample_rate() const
		{
			return m_target_sample_rate;
		}

		void set_target_sample_rate(int sample_rate)
		{
			m_target_sample_rate = sample_rate;
		}

		AudioConsumer *consumer() const
		{
			return m_consumer;
		}

		void set_consumer(AudioConsumer *consumer)
		{
			m_consumer = consumer;
		}

		//! Prepare for a new audio stream
		bool Reset(int sample_rate, int num_channels);

		//! Process a chunk of data from the audio stream
		void Consume(const int16_t *input, int length);

		//! Process any buffered input that was not processed before and clear buffers
		void Flush();

	private:
		CHROMAPRINT_DISABLE_COPY(AudioProcessor);

        void ConsumeAligned(const int16_t *input, int length);
		int Load(const int16_t *input, int length);
		void LoadMono(const int16_t *input, int length);
		void LoadStereo(const int16_t *input, int length);
		void LoadMultiChannel(const int16_t *input, int length);
		void Resample();

		std::vector<int16_t> m_buffer;
		size_t m_buffer_offset;
		std::vector<int16_t> m_resample_buffer;
		int m_target_sample_rate;
		int m_num_channels;
        // Trailing partial frame carried over between Consume() calls when a
        // caller splits its audio on non-frame boundaries.
        std::vector<int16_t> m_leftover;
		AudioConsumer *m_consumer;
		struct AVResampleContext *m_resample_ctx;
	};

};

#endif


#line 1 "src/audio_processor.h [fin]"

namespace chromaprint {

static const int kMinSampleRate = 1000;
static const int kMaxBufferSize = 1024 * 32;

#if USE_INTERNAL_AVRESAMPLE
// Resampler configuration
static const int kResampleFilterLength = 16;
static const int kResamplePhaseShift = 8;
static const int kResampleLinear = 0;
static const double kResampleCutoff = 0.8;
#endif

AudioProcessor::AudioProcessor(int sample_rate, AudioConsumer *consumer)
	: m_buffer(kMaxBufferSize),
	  m_buffer_offset(0),
	  m_resample_buffer(kMaxBufferSize),
	  m_target_sample_rate(sample_rate),
	  m_consumer(consumer),
	  m_resample_ctx(0)
{
}

AudioProcessor::~AudioProcessor()
{
#if USE_INTERNAL_AVRESAMPLE
	if (m_resample_ctx) {
		av_resample_close(m_resample_ctx);
	}
#endif
}

void AudioProcessor::LoadMono(const int16_t *input, int length)
{
	int16_t *output = m_buffer.data() + m_buffer_offset;
	while (length--) {
		*output++ = input[0];
		input++;
	}
}

void AudioProcessor::LoadStereo(const int16_t *input, int length)
{
	int16_t *output = m_buffer.data() + m_buffer_offset;
	while (length--) {
		*output++ = (input[0] + input[1]) / 2;
		input += 2;
	}
}

void AudioProcessor::LoadMultiChannel(const int16_t *input, int length)
{
	int16_t *output = m_buffer.data() + m_buffer_offset;
	while (length--) {
		int32_t sum = 0;
		for (int i = 0; i < m_num_channels; i++) {
			sum += *input++;
		}
		*output++ = (int16_t)(sum / m_num_channels);
	}
}

int AudioProcessor::Load(const int16_t *input, int length)
{
	assert(length >= 0);
	assert(m_buffer_offset <= m_buffer.size());
	length = std::min(length, static_cast<int>(m_buffer.size() - m_buffer_offset));
	switch (m_num_channels) {
	case 1:
		LoadMono(input, length);
		break;
	case 2:
		LoadStereo(input, length);
		break;
	default:
		LoadMultiChannel(input, length);
		break;
	}
	m_buffer_offset += length;
	return length;
}

void AudioProcessor::Resample()
{
#if USE_INTERNAL_AVRESAMPLE
	if (m_resample_ctx) {
		int consumed = 0;
  	int length = av_resample(m_resample_ctx, m_resample_buffer.data(), m_buffer.data(), &consumed, int(m_buffer_offset), kMaxBufferSize, 1);
		if (length > kMaxBufferSize) {
			DEBUG("chromaprint::AudioProcessor::Resample() -- Resampling overwrote output buffer.");
			length = kMaxBufferSize;
		}
		m_consumer->Consume(m_resample_buffer.data(), length);
  	int remaining = int(m_buffer_offset - consumed);
		if (remaining > 0) {
			std::copy(m_buffer.begin() + consumed, m_buffer.begin() + m_buffer_offset, m_buffer.begin());
		}
		else if (remaining < 0) {
			DEBUG("chromaprint::AudioProcessor::Resample() -- Resampling overread input buffer.");
			remaining = 0;
		}
		m_buffer_offset = remaining;
	} else
#endif
	{
		m_consumer->Consume(m_buffer.data(), int(m_buffer_offset));
		m_buffer_offset = 0;
	}
}


bool AudioProcessor::Reset(int sample_rate, int num_channels)
{
	if (num_channels <= 0) {
		DEBUG("chromaprint::AudioProcessor::Reset() -- No audio channels.");
		return false;
	}
	if (sample_rate <= kMinSampleRate) {
		DEBUG("chromaprint::AudioProcessor::Reset() -- Sample rate less than "
              << kMinSampleRate << " (" << sample_rate << ").");
		return false;
	}
	m_buffer_offset = 0;
    m_leftover.clear();

#if USE_INTERNAL_AVRESAMPLE
	if (m_resample_ctx) {
		av_resample_close(m_resample_ctx);
		m_resample_ctx = 0;
	}
	if (sample_rate != m_target_sample_rate) {
		m_resample_ctx = av_resample_init(
			m_target_sample_rate, sample_rate,
			kResampleFilterLength,
			kResamplePhaseShift,
			kResampleLinear,
			kResampleCutoff);
	}
#else
	if (sample_rate != m_target_sample_rate) {
		DEBUG("chromaprint::AudioProcessor::Reset() -- Cannot resample from " << sample_rate
		           << " to " << m_target_sample_rate << " without internal avresample.");
		return false;
	}
#endif
	m_num_channels = num_channels;
	return true;
}

void AudioProcessor::Consume(const int16_t *input, int length)
{
	assert(length >= 0);
	if (!m_leftover.empty()) {
		while (length > 0 && static_cast<int>(m_leftover.size()) < m_num_channels) {
			m_leftover.push_back(*input++);
			length--;
		}
		if (static_cast<int>(m_leftover.size()) < m_num_channels) {
			return;
		}
		ConsumeAligned(&m_leftover[0], m_num_channels);
		m_leftover.clear();
	}
	const int remainder = length % m_num_channels;
	ConsumeAligned(input, length - remainder);
	if (remainder > 0) {
		m_leftover.assign(input + length - remainder, input + length);
	}
}

void AudioProcessor::ConsumeAligned(const int16_t *input, int length)
{
	assert(length >= 0);
	assert(length % m_num_channels == 0);
	length /= m_num_channels;
	while (length > 0) {
		int consumed = Load(input, length);
		input += consumed * m_num_channels;
		length -= consumed;
		if (m_buffer.size() == m_buffer_offset) {
			Resample();
			if (m_buffer.size() == m_buffer_offset) {
				DEBUG("chromaprint::AudioProcessor::ConsumeAligned() -- Resampling failed?");
				return;
			}
		}
	}
}

void AudioProcessor::Flush()
{
	if (m_buffer_offset) {
		Resample();
	}
}

}; // namespace chromaprint

#line 1 "src/audio_processor.cpp [fin]"

#line 1 "src/chroma.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <limits>
#include <cmath>

#line 1 "src/fft_frame.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_FRAME_H_
#define CHROMAPRINT_FFT_FRAME_H_

#include <vector>

namespace chromaprint {

typedef std::vector<double> FFTFrame;

}; // namespace chromaprint

#endif


#line 1 "src/fft_frame.h [fin]"

// [omitido por inclusión previa: src/utils.h]

#line 1 "src/chroma.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_CHROMA_H_
#define CHROMAPRINT_CHROMA_H_

#include <math.h>
#include <vector>

// [omitido por inclusión previa: src/utils.h]

#line 1 "src/fft_frame_consumer.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_FRAME_CONSUMER_H_
#define CHROMAPRINT_FFT_FRAME_CONSUMER_H_


// [omitido por inclusión previa: src/fft_frame.h]

namespace chromaprint {

class FFTFrameConsumer
{
public:
	virtual ~FFTFrameConsumer() {}
	virtual void Consume(const FFTFrame &frame) = 0;
};

}; // namespace chromaprint

#endif

#line 1 "src/fft_frame_consumer.h [fin]"

#line 1 "src/feature_vector_consumer.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FEATURE_VECTOR_CONSUMER_H_
#define CHROMAPRINT_FEATURE_VECTOR_CONSUMER_H_

#include <vector>

namespace chromaprint {

class FeatureVectorConsumer {
public:
	virtual ~FeatureVectorConsumer() {}
	virtual void Consume(std::vector<double> &features) = 0;
};

}; // namespace chromaprint

#endif

#line 1 "src/feature_vector_consumer.h [fin]"

namespace chromaprint {

class Chroma : public FFTFrameConsumer {
public:
	Chroma(int min_freq, int max_freq, int frame_size, int sample_rate, FeatureVectorConsumer *consumer);
	~Chroma();

	bool interpolate() const {
		return m_interpolate;
	}

	void set_interpolate(bool interpolate) {
		m_interpolate = interpolate;
	}

	void Reset();
	void Consume(const FFTFrame &frame);

private:
	CHROMAPRINT_DISABLE_COPY(Chroma);

	void PrepareNotes(int min_freq, int max_freq, int frame_size, int sample_rate);

	bool m_interpolate;
	std::vector<char> m_notes;
	std::vector<double> m_notes_frac;
	int m_min_index;
	int m_max_index;
	std::vector<double> m_features;
	FeatureVectorConsumer *m_consumer;
};

}; // namespace chromaprint

#endif

#line 1 "src/chroma.h [fin]"

// [omitido por inclusión previa: src/debug.h]

namespace chromaprint {

static const int NUM_BANDS = 12;

inline double FreqToOctave(double freq, double base = 440.0 / 16.0)
{
	return log(freq / base) / log(2.0);
}

Chroma::Chroma(int min_freq, int max_freq, int frame_size, int sample_rate, FeatureVectorConsumer *consumer)
	: m_interpolate(false),
	  m_notes(frame_size),
	  m_notes_frac(frame_size),
	  m_features(NUM_BANDS),
	  m_consumer(consumer)
{
	PrepareNotes(min_freq, max_freq, frame_size, sample_rate);
}

Chroma::~Chroma()
{
}

void Chroma::PrepareNotes(int min_freq, int max_freq, int frame_size, int sample_rate)
{
	m_min_index = std::max(1, FreqToIndex(min_freq, frame_size, sample_rate));
	m_max_index = std::min(frame_size / 2, FreqToIndex(max_freq, frame_size, sample_rate));
	for (int i = m_min_index; i < m_max_index; i++) {
		double freq = IndexToFreq(i, frame_size, sample_rate);
		double octave = FreqToOctave(freq);
		double note = NUM_BANDS * (octave - floor(octave)); 
		m_notes[i] = (char)note;
		m_notes_frac[i] = note - m_notes[i];
	}
}

void Chroma::Reset()
{
}

void Chroma::Consume(const FFTFrame &frame)
{
	fill(m_features.begin(), m_features.end(), 0.0);
	for (int i = m_min_index; i < m_max_index; i++) {
		int note = m_notes[i];
		double energy = frame[i];
		if (m_interpolate) {
			int note2 = note;
			double a = 1.0;
			if (m_notes_frac[i] < 0.5) {
				note2 = (note + NUM_BANDS - 1) % NUM_BANDS;
				a = 0.5 + m_notes_frac[i];
			}
			if (m_notes_frac[i] > 0.5) {
				note2 = (note + 1) % NUM_BANDS;
				a = 1.5 - m_notes_frac[i];
			}
			m_features[note] += energy * a; 
			m_features[note2] += energy * (1.0 - a); 
		}
		else {
			m_features[note] += energy; 
		}
	}
	m_consumer->Consume(m_features);
}

}; // namespace chromaprint

#line 1 "src/chroma.cpp [fin]"

#line 1 "src/chroma_resampler.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <limits>
#include <cassert>
#include <cmath>

#line 1 "src/chroma_resampler.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_CHROMA_RESAMPLER_H_
#define CHROMAPRINT_CHROMA_RESAMPLER_H_

#include <vector>

#line 1 "src/image.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_IMAGE_H_
#define CHROMAPRINT_IMAGE_H_

#include <vector>
#include <algorithm>
#include <cassert>

#ifdef NDEBUG
#define CHROMAPRINT_IMAGE_ROW_TYPE double *
#define CHROMAPRINT_IMAGE_ROW_TYPE_CAST(x, c) x
#else
#define CHROMAPRINT_IMAGE_ROW_TYPE ImageRow
#define CHROMAPRINT_IMAGE_ROW_TYPE_CAST(x, c) ImageRow(x, c)
#endif

namespace chromaprint {

class ImageRow
{
public:
	explicit ImageRow(double *data, int columns) : m_data(data), m_columns(columns)
	{
	}

	int NumColumns() const { return m_columns; }

	double &Column(int i)
	{
		assert(0 <= i && i < NumColumns());
		return m_data[i];
	}

	double &operator[](int i)
	{
		return Column(i);
	}

private:
	double *m_data;
	int m_columns;
};

class Image
{
public:
	explicit Image(int columns) : m_columns(columns)
	{
	}

	Image(int columns, int rows) : m_columns(columns), m_data(columns * rows)
	{
	}

	template<class Iterator>
	Image(int columns, Iterator first, Iterator last) : m_columns(columns), m_data(first, last)
	{
	}

	int NumColumns() const { return m_columns; }
	int NumRows() const { return int(m_data.size() / m_columns); }

	void AddRow(const std::vector<double> &row)
	{
		m_data.resize(m_data.size() + m_columns);
		std::copy(row.begin(), row.end(), m_data.end() - m_columns);
	}

	CHROMAPRINT_IMAGE_ROW_TYPE Row(int i)
	{
		assert(0 <= i && i < NumRows());
		return CHROMAPRINT_IMAGE_ROW_TYPE_CAST(&m_data[m_columns * i], m_columns);
	}

	CHROMAPRINT_IMAGE_ROW_TYPE operator[](int i)
	{
		return Row(i);
	}

private:
	int m_columns;
	std::vector<double> m_data;
};

}; // namespace chromaprint

#endif

#line 1 "src/image.h [fin]"

// [omitido por inclusión previa: src/feature_vector_consumer.h]

namespace chromaprint {
	
class ChromaResampler : public FeatureVectorConsumer {
public:
	ChromaResampler(int factor, FeatureVectorConsumer *consumer);
	~ChromaResampler();

	void Reset();
	void Consume(std::vector<double> &features);

	FeatureVectorConsumer *consumer() { return m_consumer; }
	void set_consumer(FeatureVectorConsumer *consumer) { m_consumer = consumer; }

private:
	std::vector<double> m_result;
	int m_iteration;
	int m_factor;
	FeatureVectorConsumer *m_consumer;
};

}; // namespace chromaprint

#endif

#line 1 "src/chroma_resampler.h [fin]"

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

ChromaResampler::ChromaResampler(int factor, FeatureVectorConsumer *consumer)
	: m_result(12, 0.0),
	  m_iteration(0),
	  m_factor(factor),
	  m_consumer(consumer)
{
}

ChromaResampler::~ChromaResampler()
{
}

void ChromaResampler::Reset()
{
	m_iteration = 0;
	fill(m_result.begin(), m_result.end(), 0.0);
}

void ChromaResampler::Consume(std::vector<double> &features)
{
	for (int i = 0; i < 12; i++) {
		m_result[i] += features[i];
	}
	m_iteration += 1;
	if (m_iteration == m_factor) {
		for (int i = 0; i < 12; i++) {
			m_result[i] /= m_factor;
		}
		m_consumer->Consume(m_result);
		Reset();
	}
}

}; // namespace chromaprint

#line 1 "src/chroma_resampler.cpp [fin]"

#line 1 "src/chroma_filter.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <limits>
#include <assert.h>
#include <math.h>

#line 1 "src/chroma_filter.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_CHROMA_FILTER_H_
#define CHROMAPRINT_CHROMA_FILTER_H_

#include <vector>

// [omitido por inclusión previa: src/feature_vector_consumer.h]

namespace chromaprint {
	
class ChromaFilter : public FeatureVectorConsumer {
public:
	ChromaFilter(const double *coefficients, int length, FeatureVectorConsumer *consumer);
	~ChromaFilter();

	void Reset();
	void Consume(std::vector<double> &features);

	FeatureVectorConsumer *consumer() { return m_consumer; }
	void set_consumer(FeatureVectorConsumer *consumer) { m_consumer = consumer; }

private:
	const double *m_coefficients;
	int m_length;
	std::vector< std::vector<double> > m_buffer;
	std::vector<double> m_result;
	int m_buffer_offset;
	int m_buffer_size;
	FeatureVectorConsumer *m_consumer;
};

}; // namespace chromaprint

#endif

#line 1 "src/chroma_filter.h [fin]"

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

ChromaFilter::ChromaFilter(const double *coefficients, int length, FeatureVectorConsumer *consumer)
	: m_coefficients(coefficients),
	  m_length(length),
	  m_buffer(8),
	  m_result(12),
	  m_buffer_offset(0),
	  m_buffer_size(1),
	  m_consumer(consumer)
{
}

ChromaFilter::~ChromaFilter()
{
}

void ChromaFilter::Reset()
{
	m_buffer_size = 1;
	m_buffer_offset = 0;
}

void ChromaFilter::Consume(std::vector<double> &features)
{
	m_buffer[m_buffer_offset] = features;
	m_buffer_offset = (m_buffer_offset + 1) % 8;
	if (m_buffer_size >= m_length) {
		int offset = (m_buffer_offset + 8 - m_length) % 8;
		fill(m_result.begin(), m_result.end(), 0.0);
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < m_length; j++) {
				m_result[i] += m_buffer[(offset + j) % 8][i] * m_coefficients[j];
			}
		}
		m_consumer->Consume(m_result);
	}
	else {
		m_buffer_size++;
	}
}

}; // namespace chromaprint

#line 1 "src/chroma_filter.cpp [fin]"

#line 1 "src/spectrum.cpp"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <limits>
#include <math.h>

// [omitido por inclusión previa: src/fft_frame.h]

// [omitido por inclusión previa: src/utils.h]

#line 1 "src/spectrum.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_SPECTRUM_H_
#define CHROMAPRINT_SPECTRUM_H_

#include <math.h>
#include <vector>

// [omitido por inclusión previa: src/utils.h]

// [omitido por inclusión previa: src/fft_frame_consumer.h]

// [omitido por inclusión previa: src/feature_vector_consumer.h]

namespace chromaprint {

class Spectrum : public FFTFrameConsumer
{
public:
	Spectrum(int num_bands, int min_freq, int max_freq, int frame_size, int sample_rate, FeatureVectorConsumer *consumer);
	~Spectrum();

	void Reset();
	void Consume(const FFTFrame &frame);

protected:
	int NumBands() const { return int(m_bands.size() - 1); }
	int FirstIndex(int band) const { return m_bands[band]; }
	int LastIndex(int band) const { return m_bands[band + 1]; }

private:
	CHROMAPRINT_DISABLE_COPY(Spectrum);
	
	void PrepareBands(int num_bands, int min_freq, int max_freq, int frame_size, int sample_rate);

	std::vector<int> m_bands;
	std::vector<double> m_features;
	FeatureVectorConsumer *m_consumer;
};

}; // namespace chromaprint

#endif

#line 1 "src/spectrum.h [fin]"

namespace chromaprint {

Spectrum::Spectrum(int num_bands, int min_freq, int max_freq, int frame_size, int sample_rate, FeatureVectorConsumer *consumer)
	: m_bands(num_bands + 1),
	  m_features(num_bands),
	  m_consumer(consumer)
{
	PrepareBands(num_bands, min_freq, max_freq, frame_size, sample_rate);
}

Spectrum::~Spectrum()
{
}

void Spectrum::PrepareBands(int num_bands, int min_freq, int max_freq, int frame_size, int sample_rate)
{
    double min_bark = FreqToBark(min_freq);
    double max_bark = FreqToBark(max_freq);
    double band_size = (max_bark - min_bark) / num_bands;

    int min_index = FreqToIndex(min_freq, frame_size, sample_rate);
    //int max_index = FreqToIndex(max_freq, frame_size, sample_rate);

    m_bands[0] = min_index;
    double prev_bark = min_bark;

    for (int i = min_index, b = 0; i < frame_size / 2; i++) {
        double freq = IndexToFreq(i, frame_size, sample_rate);
        double bark = FreqToBark(freq);
        if (bark - prev_bark > band_size) {
            b += 1;
            prev_bark = bark;
            m_bands[b] = i;
            if (b >= num_bands) {
                break;
            }
        }
    }
}

void Spectrum::Reset()
{
}

void Spectrum::Consume(const FFTFrame &frame)
{
	for (int i = 0; i < NumBands(); i++) {
		int first = FirstIndex(i);
		int last = LastIndex(i);
		double denominator = 0.0;
		for (int j = first; j < last; j++) {
			double s = frame[j];
			denominator += s;
		}
		m_features[i] = denominator / (last - first);
	}
	m_consumer->Consume(m_features);
}

}; // namespace chromaprint

#line 1 "src/spectrum.cpp [fin]"

#line 1 "src/fft.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.


#line 1 "src/audio/audio_slicer.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_AUDIO_AUDIO_SLICER_H_
#define CHROMAPRINT_AUDIO_AUDIO_SLICER_H_

#include <cstddef>
#include <cstdint>
#include <cassert>
#include <vector>

// [omitido por inclusión previa: src/debug.h]

namespace chromaprint {

template <typename T>
class AudioSlicer {
public:
	AudioSlicer(size_t size, size_t increment)
		: m_size(size), m_increment(increment), m_buffer(size * 2) {
		assert(size >= increment);
		Reset();
	}

	size_t size() const {
		return m_size;
	}

	size_t increment() const {
		return m_increment;
	}

	void Reset() {
		m_buffer_begin = m_buffer_end = m_buffer.begin();
	}

	template <typename InputIt, typename ConsumerFunc>
	void Process(InputIt begin, InputIt end, ConsumerFunc consumer) {
		size_t size = std::distance(begin, end);
		size_t buffer_size = std::distance(m_buffer_begin, m_buffer_end);

		while (buffer_size > 0 && buffer_size + size >= m_size) {
			consumer(&(*m_buffer_begin), &(*m_buffer_end), begin, std::next(begin, m_size - buffer_size));
			if (buffer_size >= m_increment) {
				std::advance(m_buffer_begin, m_increment);
				buffer_size -= m_increment;
				const size_t available_buffer_size = std::distance(m_buffer_end, m_buffer.end());
				if (buffer_size + available_buffer_size < m_size) {
					const auto new_buffer_begin = m_buffer.begin();
					m_buffer_end = std::copy(m_buffer_begin, m_buffer_end, new_buffer_begin);
					m_buffer_begin = new_buffer_begin;
				}
			} else {
				m_buffer_begin = m_buffer_end = m_buffer.begin();
				std::advance(begin, m_increment - buffer_size);
				size -= m_increment - buffer_size;
				buffer_size = 0;
			}
		}

		if (buffer_size == 0) {
			while (size >= m_size) {
				consumer(begin, std::next(begin, m_size), end, end);
				std::advance(begin, m_increment);
				size -= m_increment;
			}
		}

		assert(buffer_size + size < m_size);
		m_buffer_end = std::copy(begin, end, m_buffer_end);
	}

private:
	size_t m_size;
	size_t m_increment;
	std::vector<T> m_buffer;
	typename std::vector<T>::iterator m_buffer_begin;
	typename std::vector<T>::iterator m_buffer_end;
};

}; // namespace chromaprint

#endif // CHROMAPRINT_AUDIO_AUDIO_SLICER_H_

#line 1 "src/audio/audio_slicer.h [fin]"

// [omitido por inclusión previa: src/utils.h]

#line 1 "src/fft_lib.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_LIB_H_
#define CHROMAPRINT_FFT_LIB_H_

#ifdef HAVE_CONFIG_H

// [omitido por inclusión previa: config.h]
#endif

#ifdef USE_AVTX

#line 1 "src/fft_lib_avtx.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_LIB_AVTX_H_
#define CHROMAPRINT_FFT_LIB_AVTX_H_

extern "C" {
#include <libavutil/tx.h>
#include <libavutil/mem.h>
}


// [omitido por inclusión previa: src/fft_frame.h]

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

class FFTLib {
public:
	FFTLib(size_t frame_size);
	~FFTLib();

	void Load(const int16_t *begin1, const int16_t *end1, const int16_t *begin2, const int16_t *end2);
	void Compute(FFTFrame &frame);

private:
	CHROMAPRINT_DISABLE_COPY(FFTLib);

	size_t m_frame_size;
	float *m_window;
	float *m_input;
	AVComplexFloat *m_output;
	AVTXContext *m_tx_ctx;
	av_tx_fn m_tx_fn;
};

}; // namespace chromaprint

#endif // CHROMAPRINT_FFT_LIB_AVTX_H_
#line 1 "src/fft_lib_avtx.h [fin]"
#endif

#ifdef USE_AVFFT

#line 1 "src/fft_lib_avfft.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_LIB_AVFFT_H_
#define CHROMAPRINT_FFT_LIB_AVFFT_H_

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavcodec/avfft.h>
#include <libavutil/mem.h>
}


// [omitido por inclusión previa: src/fft_frame.h]

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

class FFTLib {
public:
	FFTLib(size_t frame_size);
	~FFTLib();

	void Load(const int16_t *begin1, const int16_t *end1, const int16_t *begin2, const int16_t *end2);
	void Compute(FFTFrame &frame);

private:
	CHROMAPRINT_DISABLE_COPY(FFTLib);

	size_t m_frame_size;
	FFTSample *m_window;
	FFTSample *m_input;
	RDFTContext *m_rdft_ctx;
};

}; // namespace chromaprint

#endif // CHROMAPRINT_FFT_LIB_AVFFT_H_

#line 1 "src/fft_lib_avfft.h [fin]"
#endif

#ifdef USE_FFTW3

#line 1 "src/fft_lib_fftw3.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_LIB_FFTW3_H_
#define CHROMAPRINT_FFT_LIB_FFTW3_H_

#include <fftw3.h>


// [omitido por inclusión previa: src/fft_frame.h]

// [omitido por inclusión previa: src/utils.h]

#ifdef USE_FFTW3F
#define FFTW_SCALAR float
#define fftw_plan fftwf_plan
#define fftw_plan_r2r_1d fftwf_plan_r2r_1d
#define fftw_execute fftwf_execute
#define fftw_destroy_plan fftwf_destroy_plan
#define fftw_malloc fftwf_malloc
#define fftw_free fftwf_free
#else
#define FFTW_SCALAR double
#endif

namespace chromaprint {

class FFTLib {
public:
	FFTLib(size_t frame_size);
	~FFTLib();

	void Load(const int16_t *begin1, const int16_t *end1, const int16_t *begin2, const int16_t *end2);
	void Compute(FFTFrame &frame);

private:
	CHROMAPRINT_DISABLE_COPY(FFTLib);

	size_t m_frame_size;
	FFTW_SCALAR *m_window;
	FFTW_SCALAR *m_input;
	FFTW_SCALAR *m_output;
	fftw_plan m_plan;
};

}; // namespace chromaprint

#endif // CHROMAPRINT_FFT_LIB_FFTW3_H_

#line 1 "src/fft_lib_fftw3.h [fin]"
#endif

#ifdef USE_FFTW3F

// [omitido por inclusión previa: src/fft_lib_fftw3.h]
#endif

#ifdef USE_VDSP

#line 1 "src/fft_lib_vdsp.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_LIB_VDSP_H_
#define CHROMAPRINT_FFT_LIB_VDSP_H_

#include <Accelerate/Accelerate.h>


// [omitido por inclusión previa: src/fft_frame.h]

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

class FFTLib {
public:
	FFTLib(size_t frame_size);
	~FFTLib();

	void Load(const int16_t *begin1, const int16_t *end1, const int16_t *begin2, const int16_t *end2);
	void Compute(FFTFrame &frame);

private:
	CHROMAPRINT_DISABLE_COPY(FFTLib);

	size_t m_frame_size;
	float *m_window;
	float *m_input;
	int m_log2n;
	FFTSetup m_setup;
	DSPSplitComplex m_a;
};

}; // namespace chromaprint

#endif // CHROMAPRINT_FFT_LIB_VDSP_H_

#line 1 "src/fft_lib_vdsp.h [fin]"
#endif

#ifdef USE_KISSFFT

#line 1 "src/fft_lib_kissfft.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_LIB_KISSFFT_H_
#define CHROMAPRINT_FFT_LIB_KISSFFT_H_


#line 1 "src/3rdparty/kissfft/kiss_fftr.h"
/*
 *  Copyright (c) 2003-2004, Mark Borgerding. All rights reserved.
 *  This file is part of KISS FFT - https://github.com/mborgerding/kissfft
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *  See COPYING file for more information.
 */

#ifndef KISS_FTR_H
#define KISS_FTR_H


#line 1 "src/3rdparty/kissfft/kiss_fft.h"
/*
 *  Copyright (c) 2003-2010, Mark Borgerding. All rights reserved.
 *  This file is part of KISS FFT - https://github.com/mborgerding/kissfft
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *  See COPYING file for more information.
 */

#ifndef KISS_FFT_H
#define KISS_FFT_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Define KISS_FFT_SHARED macro to properly export symbols
#ifdef KISS_FFT_SHARED
# ifdef _WIN32
#  ifdef KISS_FFT_BUILD
#   define KISS_FFT_API __declspec(dllexport)
#  else
#   define KISS_FFT_API __declspec(dllimport)
#  endif
# else
#  define KISS_FFT_API __attribute__ ((visibility ("default")))
# endif
#else
# define KISS_FFT_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 ATTENTION!
 If you would like a :
 -- a utility that will handle the caching of fft objects
 -- real-only (no imaginary time component ) FFT
 -- a multi-dimensional FFT
 -- a command-line utility to perform ffts
 -- a command-line utility to perform fast-convolution filtering

 Then see kfc.h kiss_fftr.h kiss_fftnd.h fftutil.c kiss_fastfir.c
  in the tools/ directory.
*/

/* User may override KISS_FFT_MALLOC and/or KISS_FFT_FREE. */
#ifdef USE_SIMD
# include <xmmintrin.h>
# define kiss_fft_scalar __m128
# ifndef KISS_FFT_MALLOC
#  define KISS_FFT_MALLOC(nbytes) _mm_malloc(nbytes,16)
#  define KISS_FFT_ALIGN_CHECK(ptr) 
#  define KISS_FFT_ALIGN_SIZE_UP(size) ((size + 15UL) & ~0xFUL)
# endif
# ifndef KISS_FFT_FREE
#  define KISS_FFT_FREE _mm_free
# endif
#else
# define KISS_FFT_ALIGN_CHECK(ptr)
# define KISS_FFT_ALIGN_SIZE_UP(size) (size)
# ifndef KISS_FFT_MALLOC
#  define KISS_FFT_MALLOC malloc
# endif
# ifndef KISS_FFT_FREE
#  define KISS_FFT_FREE free
# endif
#endif


#ifdef FIXED_POINT
#include <stdint.h>
# if (FIXED_POINT == 32)
#  define kiss_fft_scalar int32_t
# else	
#  define kiss_fft_scalar int16_t
# endif
#else
# ifndef kiss_fft_scalar
/*  default is float */
#   define kiss_fft_scalar float
# endif
#endif

typedef struct {
    kiss_fft_scalar r;
    kiss_fft_scalar i;
}kiss_fft_cpx;

typedef struct kiss_fft_state* kiss_fft_cfg;

/* 
 *  kiss_fft_alloc
 *  
 *  Initialize a FFT (or IFFT) algorithm's cfg/state buffer.
 *
 *  typical usage:      kiss_fft_cfg mycfg=kiss_fft_alloc(1024,0,NULL,NULL);
 *
 *  The return value from fft_alloc is a cfg buffer used internally
 *  by the fft routine or NULL.
 *
 *  If lenmem is NULL, then kiss_fft_alloc will allocate a cfg buffer using malloc.
 *  The returned value should be free()d when done to avoid memory leaks.
 *  
 *  The state can be placed in a user supplied buffer 'mem':
 *  If lenmem is not NULL and mem is not NULL and *lenmem is large enough,
 *      then the function places the cfg in mem and the size used in *lenmem
 *      and returns mem.
 *  
 *  If lenmem is not NULL and ( mem is NULL or *lenmem is not large enough),
 *      then the function returns NULL and places the minimum cfg 
 *      buffer size in *lenmem.
 * */

kiss_fft_cfg KISS_FFT_API kiss_fft_alloc(int nfft,int inverse_fft,void * mem,size_t * lenmem);

/*
 * kiss_fft(cfg,in_out_buf)
 *
 * Perform an FFT on a complex input buffer.
 * for a forward FFT,
 * fin should be  f[0] , f[1] , ... ,f[nfft-1]
 * fout will be   F[0] , F[1] , ... ,F[nfft-1]
 * Note that each element is complex and can be accessed like
    f[k].r and f[k].i
 * */
void KISS_FFT_API kiss_fft(kiss_fft_cfg cfg,const kiss_fft_cpx *fin,kiss_fft_cpx *fout);

/*
 A more generic version of the above function. It reads its input from every Nth sample.
 * */
void KISS_FFT_API kiss_fft_stride(kiss_fft_cfg cfg,const kiss_fft_cpx *fin,kiss_fft_cpx *fout,int fin_stride);

/* If kiss_fft_alloc allocated a buffer, it is one contiguous 
   buffer and can be simply free()d when no longer needed*/
#define kiss_fft_free KISS_FFT_FREE

/*
 Cleans up some memory that gets managed internally. Not necessary to call, but it might clean up 
 your compiler output to call this before you exit.
*/
void KISS_FFT_API kiss_fft_cleanup(void);
	

/*
 * Returns the smallest integer k, such that k>=n and k has only "fast" factors (2,3,5)
 */
int KISS_FFT_API kiss_fft_next_fast_size(int n);

/* for real ffts, we need an even size */
#define kiss_fftr_next_fast_size_real(n) \
        (kiss_fft_next_fast_size( ((n)+1)>>1)<<1)

#ifdef __cplusplus
} 
#endif

#endif

#line 1 "src/3rdparty/kissfft/kiss_fft.h [fin]"
#ifdef __cplusplus
extern "C" {
#endif

    
/* 
 
 Real optimized version can save about 45% cpu time vs. complex fft of a real seq.

 
 
 */

typedef struct kiss_fftr_state *kiss_fftr_cfg;


kiss_fftr_cfg KISS_FFT_API kiss_fftr_alloc(int nfft,int inverse_fft,void * mem, size_t * lenmem);
/*
 nfft must be even

 If you don't care to allocate space, use mem = lenmem = NULL 
*/


void KISS_FFT_API kiss_fftr(kiss_fftr_cfg cfg,const kiss_fft_scalar *timedata,kiss_fft_cpx *freqdata);
/*
 input timedata has nfft scalar points
 output freqdata has nfft/2+1 complex points
*/

void KISS_FFT_API kiss_fftri(kiss_fftr_cfg cfg,const kiss_fft_cpx *freqdata,kiss_fft_scalar *timedata);
/*
 input freqdata has  nfft/2+1 complex points
 output timedata has nfft scalar points
*/

#define kiss_fftr_free KISS_FFT_FREE

#ifdef __cplusplus
}
#endif
#endif

#line 1 "src/3rdparty/kissfft/kiss_fftr.h [fin]"


// [omitido por inclusión previa: src/fft_frame.h]

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

class FFTLib {
public:
	FFTLib(size_t frame_size);
	~FFTLib();

	void Load(const int16_t *begin1, const int16_t *end1, const int16_t *begin2, const int16_t *end2);
	void Compute(FFTFrame &frame);

private:
	CHROMAPRINT_DISABLE_COPY(FFTLib);

	size_t m_frame_size;
	kiss_fft_scalar *m_window;
	kiss_fft_scalar *m_input;
	kiss_fft_cpx *m_output;
	kiss_fftr_cfg m_cfg;
};

}; // namespace chromaprint

#endif // CHROMAPRINT_FFT_LIB_KISSFFT_H_

#line 1 "src/fft_lib_kissfft.h [fin]"
#endif

#endif

#line 1 "src/fft_lib.h [fin]"

#line 1 "src/fft.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FFT_H_
#define CHROMAPRINT_FFT_H_

#include <cmath>
#include <memory>

// [omitido por inclusión previa: src/utils.h]

// [omitido por inclusión previa: src/fft_frame.h]

// [omitido por inclusión previa: src/fft_frame_consumer.h]

// [omitido por inclusión previa: src/audio_consumer.h]

// [omitido por inclusión previa: src/audio/audio_slicer.h]

namespace chromaprint {

class FFTLib;

class FFT : public AudioConsumer
{
public:
	FFT(size_t frame_size, size_t overlap, FFTFrameConsumer *consumer);
	~FFT();

	size_t frame_size() const {
		return m_slicer.size();
	}

	size_t increment() const {
		return m_slicer.increment();
	}

	size_t overlap() const {
		return m_slicer.size() - m_slicer.increment();
	}

	void Reset();
	void Consume(const int16_t *input, int length) override;

private:
	CHROMAPRINT_DISABLE_COPY(FFT);

	FFTFrame m_frame;
	AudioSlicer<int16_t> m_slicer;
	std::unique_ptr<FFTLib> m_lib;
	FFTFrameConsumer *m_consumer;
};

}; // namespace chromaprint

#endif

#line 1 "src/fft.h [fin]"

// [omitido por inclusión previa: src/debug.h]

namespace chromaprint {

FFT::FFT(size_t frame_size, size_t overlap, FFTFrameConsumer *consumer)
	: m_frame(1 + frame_size / 2), m_slicer(frame_size, frame_size - overlap), m_lib(new FFTLib(frame_size)), m_consumer(consumer) {}

FFT::~FFT() {}

void FFT::Reset() {
	m_slicer.Reset();
}

void FFT::Consume(const int16_t *input, int length) {
	m_slicer.Process(input, input + length, [&](const int16_t *b1, const int16_t *e1, const int16_t *b2, const int16_t *e2) {
		m_lib->Load(b1, e1, b2, e2);
		m_lib->Compute(m_frame);
		m_consumer->Consume(m_frame);
	});
}

}; // namespace chromaprint

#line 1 "src/fft.cpp [fin]"

#line 1 "src/fingerprinter.cpp"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <string.h>

#line 1 "src/fingerprinter.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FINGERPRINTER_H_
#define CHROMAPRINT_FINGERPRINTER_H_

#include <stdint.h>
#include <vector>

// [omitido por inclusión previa: src/audio_consumer.h]

namespace chromaprint {

class FFT;
class Chroma;
class ChromaNormalizer;
class ChromaFilter;
class AudioProcessor;
class FingerprintCalculator;
class FingerprinterConfiguration;
class SilenceRemover;

class Fingerprinter : public AudioConsumer
{
public:
	Fingerprinter(FingerprinterConfiguration *config = 0);
	~Fingerprinter();

	/**
	 * Initialize the fingerprinting process.
	 */
	bool Start(int sample_rate, int num_channels);

	/**
	 * Process a block of raw audio data. Call this method as many times
	 * as you need. 
	 */
	void Consume(const int16_t *input, int length);

	/**
	 * Calculate the fingerprint based on the provided audio data.
	 */
	void Finish();

	//! Get the fingerprint generate from data up to this point.
	const std::vector<uint32_t> &GetFingerprint() const;

	//! Clear the generated fingerprint, but allow more audio to be processed.
	void ClearFingerprint();

	bool SetOption(const char *name, int value);

	const FingerprinterConfiguration *config() { return m_config; }

private:
	Chroma *m_chroma;
	ChromaNormalizer *m_chroma_normalizer;
	ChromaFilter *m_chroma_filter;
	FFT *m_fft;
	AudioProcessor *m_audio_processor;
	FingerprintCalculator *m_fingerprint_calculator;
	FingerprinterConfiguration *m_config;
	SilenceRemover *m_silence_remover;
};

}; // namespace chromaprint

#endif

#line 1 "src/fingerprinter.h [fin]"

// [omitido por inclusión previa: src/chroma.h]

#line 1 "src/chroma_normalizer.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_CHROMA_NORMALIZER_H_
#define CHROMAPRINT_CHROMA_NORMALIZER_H_

#include <vector>
#include <algorithm>

// [omitido por inclusión previa: src/feature_vector_consumer.h]

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

class ChromaNormalizer : public FeatureVectorConsumer {
public:
	ChromaNormalizer(FeatureVectorConsumer *consumer) : m_consumer(consumer) {}
	~ChromaNormalizer() {}
	void Reset() {}

	void Consume(std::vector<double> &features)
	{
		NormalizeVector(features.begin(), features.end(),
						chromaprint::EuclideanNorm<std::vector<double>::iterator>,
						0.01);
		m_consumer->Consume(features);
	}

private:
	CHROMAPRINT_DISABLE_COPY(ChromaNormalizer);

	FeatureVectorConsumer *m_consumer;
};

}; // namespace chromaprint

#endif

#line 1 "src/chroma_normalizer.h [fin]"

// [omitido por inclusión previa: src/chroma_filter.h]

// [omitido por inclusión previa: src/fft.h]

// [omitido por inclusión previa: src/audio_processor.h]

#line 1 "src/image_builder.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_IMAGE_BUILDER_H_
#define CHROMAPRINT_IMAGE_BUILDER_H_

#include <vector>

// [omitido por inclusión previa: src/utils.h]

// [omitido por inclusión previa: src/image.h]

// [omitido por inclusión previa: src/feature_vector_consumer.h]

namespace chromaprint {

class ImageBuilder : public FeatureVectorConsumer {
public:
	ImageBuilder(Image *image = 0);
	~ImageBuilder();

	void Reset(Image *image) 	{
		set_image(image);
	}

	void Consume(std::vector<double> &features);

	Image *image() const {
		return m_image;
	}

	void set_image(Image *image) {
		m_image = image;
	}

private:
	CHROMAPRINT_DISABLE_COPY(ImageBuilder);

	Image *m_image;
};

}; // namespace chromaprint

#endif

#line 1 "src/image_builder.h [fin]"

#line 1 "src/silence_remover.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_SILENCE_REMOVER_H_
#define CHROMAPRINT_SILENCE_REMOVER_H_


// [omitido por inclusión previa: src/utils.h]

// [omitido por inclusión previa: src/audio_consumer.h]

#line 1 "src/moving_average.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_MOVING_AVERAGE_H_
#define CHROMAPRINT_MOVING_AVERAGE_H_

#include <vector>

namespace chromaprint {

template<class T>
class MovingAverage
{
public:
	MovingAverage(int size)
		: m_buffer(size), m_size(size), m_offset(0), m_sum(0), m_count(0) {}

	void AddValue(const T &x)
	{
		m_sum += x;
		m_sum -= m_buffer[m_offset];
		if (m_count < m_size) {
			m_count++;
		}
		m_buffer[m_offset] = x;
		m_offset = (m_offset + 1) % m_size;
	}

	T GetAverage() const
	{
		if (!m_count) {
			return 0;
		}
		return m_sum / m_count;
	}

private:
	std::vector<T> m_buffer;
	int m_size;
	int m_offset;
	int m_sum;
	int m_count;
};

}; // namespace chromaprint

#endif

#line 1 "src/moving_average.h [fin]"

namespace chromaprint {

class SilenceRemover : public AudioConsumer
{
public:
	SilenceRemover(AudioConsumer *consumer, int threshold = 0);

	AudioConsumer *consumer() const
	{
		return m_consumer;
	}

	void set_consumer(AudioConsumer *consumer)
	{
		m_consumer = consumer;
	}

	bool Reset(int sample_rate, int num_channels);
	void Consume(const int16_t *input, int length) override;
	void Flush();

	int threshold()
	{
		return m_threshold;
	}

	void set_threshold(int value)
	{
		m_threshold = value;
	}

private:
	CHROMAPRINT_DISABLE_COPY(SilenceRemover);

	bool m_start;
	int m_threshold;
	MovingAverage<int16_t> m_average;
	AudioConsumer *m_consumer;
};

}; // namespace chromaprint

#endif

#line 1 "src/silence_remover.h [fin]"

#line 1 "src/fingerprint_calculator.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FINGERPRINT_CALCULATOR_H_
#define CHROMAPRINT_FINGERPRINT_CALCULATOR_H_

#include <cstdint>
#include <vector>

// [omitido por inclusión previa: src/feature_vector_consumer.h]

#line 1 "src/utils/rolling_integral_image.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_ROLLING_INTEGRAL_IMAGE_H_
#define CHROMAPRINT_ROLLING_INTEGRAL_IMAGE_H_

#include <cstddef>
#include <cassert>
#include <algorithm>
#include <numeric>

// [omitido por inclusión previa: src/debug.h]

namespace chromaprint {

class RollingIntegralImage {
public:

	explicit RollingIntegralImage(size_t max_rows) : m_max_rows(max_rows + 1) {}

	template <typename InputIt>
	RollingIntegralImage(size_t num_columns, InputIt begin, InputIt end) {
		m_max_rows = std::distance(begin, end) / num_columns;
		while (begin != end) {
			AddRow(begin, begin + num_columns);
			std::advance(begin, num_columns);
		}
	}

	size_t num_columns() const { return m_num_columns; }
	size_t num_rows() const { return m_num_rows; }

	void Reset() {
		m_data.clear();
		m_num_rows = 0;
		m_num_columns = 0;
	}

	double Area(size_t r1, size_t c1, size_t r2, size_t c2) const {
		assert(r1 <= m_num_rows);
		assert(r2 <= m_num_rows);

		if (m_num_rows > m_max_rows) {
			assert(r1 > m_num_rows - m_max_rows);
			assert(r2 > m_num_rows - m_max_rows);
		}

		assert(c1 <= m_num_columns);
		assert(c2 <= m_num_columns);

		if (r1 == r2 || c1 == c2) {
			return 0.0;
		}

		assert(r2 > r1);
		assert(c2 > c1);

		if (r1 == 0) {
			auto row = GetRow(r2 - 1);
			if (c1 == 0) {
				return row[c2 - 1];
			} else {
				return row[c2 - 1] - row[c1 - 1];
			}
		} else {
			auto row1 = GetRow(r1 - 1);
			auto row2 = GetRow(r2 - 1);
			if (c1 == 0) {
				return row2[c2 - 1] - row1[c2 - 1];
			} else {
				return row2[c2 - 1] - row1[c2 - 1] - row2[c1 - 1] + row1[c1 - 1];
			}
		}
	}

	template <typename InputIt>
	void AddRow(InputIt begin, InputIt end) {
		const size_t size = std::distance(begin, end);
		if (m_num_columns == 0) {
			m_num_columns = size;
			m_data.resize(m_max_rows * m_num_columns, 0.0);
		}

		assert(m_num_columns == size);

		auto current_row_begin = GetRow(m_num_rows);
		std::partial_sum(begin, end, current_row_begin);

		if (m_num_rows > 0) {
			auto last_row_begin = GetRow(m_num_rows - 1);
			auto last_row_end = last_row_begin + m_num_columns;
			std::transform(last_row_begin, last_row_end, current_row_begin, current_row_begin,
				[](double a, double b) { return a + b; });
		}

		m_num_rows++;
	}

	void AddRow(const std::vector<double> &row) {
		AddRow(row.begin(), row.end());
	}

private:

	std::vector<double>::iterator GetRow(size_t i) {
		i = i % m_max_rows;
		return m_data.begin() + i * m_num_columns;
	}

	std::vector<double>::const_iterator GetRow(size_t i) const {
		i = i % m_max_rows;
		return m_data.begin() + i * m_num_columns;
	}

	size_t m_max_rows;
	size_t m_num_columns = 0;
	size_t m_num_rows = 0;
	std::vector<double> m_data;
};

}; // namespace chromaprint

#endif

#line 1 "src/utils/rolling_integral_image.h [fin]"

namespace chromaprint {

class Classifier;
class Image;
class IntegralImage;

class FingerprintCalculator : public FeatureVectorConsumer {
public:
	FingerprintCalculator(const Classifier *classifiers, size_t num_classifiers);

	virtual void Consume(std::vector<double> &features) override;

	//! Get the fingerprint generate from data up to this point.
	const std::vector<uint32_t> &GetFingerprint() const;

	//! Clear the generated fingerprint, but allow more features to be processed.
	void ClearFingerprint();

	//! Reset all internal state.
	void Reset();

private:
	uint32_t CalculateSubfingerprint(size_t offset);

	const Classifier *m_classifiers;
	size_t m_num_classifiers;
	size_t m_max_filter_width;
	RollingIntegralImage m_image;
	std::vector<uint32_t> m_fingerprint;
};

}; // namespace chromaprint

#endif


#line 1 "src/fingerprint_calculator.h [fin]"

#line 1 "src/fingerprinter_configuration.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FINGERPRINTER_CONFIGURATION_H_
#define CHROMAPRINT_FINGERPRINTER_CONFIGURATION_H_

#include <algorithm>

#line 1 "src/classifier.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_CLASSIFIER_H_
#define CHROMAPRINT_CLASSIFIER_H_

#include <ostream>

#line 1 "src/quantizer.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_QUANTIZER_H_
#define CHROMAPRINT_QUANTIZER_H_

#include <cassert>
#include <ostream>

namespace chromaprint {

class Quantizer {
public:
	Quantizer(double t0 = 0.0, double t1 = 0.0, double t2 = 0.0)
		: m_t0(t0), m_t1(t1), m_t2(t2)
	{
		assert(t0 <= t1 && t1 <= t2);
	}

	int Quantize(double value) const
	{
		if (value < m_t1) {
			if (value < m_t0) {
				return 0;
			}
			return 1;
		}
		else {
			if (value < m_t2) {
				return 2;
			}
			return 3;
		}
	}

	double t0() const { return m_t0; }
	void set_t0(double t) { m_t0 = t; }

	double t1() const { return m_t1; }
	void set_t1(double t) { m_t1 = t; }

	double t2() const { return m_t2; }
	void set_t2(double t) { m_t2 = t; }

private:
	double m_t0, m_t1, m_t2;
};

inline std::ostream &operator<<(std::ostream &stream, const Quantizer &q)
{
	stream << "Quantizer(" << q.t0() << ", " << q.t1() << ", " << q.t2() << ")";
	return stream;
}

}; // namespace chromaprint

#endif

#line 1 "src/quantizer.h [fin]"

#line 1 "src/filter.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FILTER_H_
#define CHROMAPRINT_FILTER_H_

#include <ostream>

#line 1 "src/filter_utils.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FILTER_UTILS_H_
#define CHROMAPRINT_FILTER_UTILS_H_

#include <cmath>
#include <cassert>

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

inline double Subtract(double a, double b) {
	return a - b;
}

inline double SubtractLog(double a, double b) {
	double r = log((1.0 + a) / (1.0 + b));
	assert(!IsNaN(r));
	return r;
}

// oooooooooooooooo
// oooooooooooooooo
// oooooooooooooooo
// oooooooooooooooo
template <typename IntegralImage, typename Comparator>
double Filter0(const IntegralImage &image, size_t x, size_t y, size_t w, size_t h, Comparator cmp) {
	assert(w >= 1);
	assert(h >= 1);

	double a = image.Area(x, y, x + w, y + h);
	double b = 0;

	return cmp(a, b);
}

// ................
// ................
// oooooooooooooooo
// oooooooooooooooo
template <typename IntegralImage, typename Comparator>
double Filter1(const IntegralImage &image, size_t x, size_t y, size_t w, size_t h, Comparator cmp) {
	assert(w >= 1);
	assert(h >= 1);

	const auto h_2 = h / 2;

	double a = image.Area(x, y + h_2, x + w, y + h  );
	double b = image.Area(x, y,       x + w, y + h_2);

	return cmp(a, b);
}

// .......ooooooooo
// .......ooooooooo
// .......ooooooooo
// .......ooooooooo
template <typename IntegralImage, typename Comparator>
double Filter2(const IntegralImage &image, size_t x, size_t y, size_t w, size_t h, Comparator cmp) {
	assert(w >= 1);
	assert(h >= 1);

	const auto w_2 = w / 2;

	double a = image.Area(x + w_2, y, x + w  , y + h);
	double b = image.Area(x,       y, x + w_2, y + h);

	return cmp(a, b);
}

// .......ooooooooo
// .......ooooooooo
// ooooooo.........
// ooooooo.........
template <typename IntegralImage, typename Comparator>
double Filter3(const IntegralImage &image, size_t x, size_t y, size_t w, size_t h, Comparator cmp) {
	assert(x >= 0);
	assert(y >= 0);
	assert(w >= 1);
	assert(h >= 1);

	const auto w_2 = w / 2;
	const auto h_2 = h / 2;

	double a = image.Area(x,       y + h_2, x + w_2, y + h  ) +
			   image.Area(x + w_2, y,       x + w  , y + h_2);
	double b = image.Area(x,       y,       x + w_2, y + h_2) +
			   image.Area(x + w_2, y + h_2, x + w  , y + h  );

	return cmp(a, b);
}

// ................
// oooooooooooooooo
// ................
template <typename IntegralImage, typename Comparator>
double Filter4(const IntegralImage &image, size_t x, size_t y, size_t w, size_t h, Comparator cmp) {
	assert(w >= 1);
	assert(h >= 1);

	const auto h_3 = h / 3;

	double a = image.Area(x, y + h_3,     x + w, y + 2 * h_3);
	double b = image.Area(x, y,           x + w, y + h_3) +
			   image.Area(x, y + 2 * h_3, x + w, y + h);

	return cmp(a, b);
}

// .....oooooo.....
// .....oooooo.....
// .....oooooo.....
// .....oooooo.....
template <typename IntegralImage, typename Comparator>
double Filter5(const IntegralImage &image, size_t x, size_t y, size_t w, size_t h, Comparator cmp) {
	assert(w >= 1);
	assert(h >= 1);

	const auto w_3 = w / 3;

	double a = image.Area(x + w_3,     y, x + 2 * w_3, y + h);
	double b = image.Area(x,           y, x + w_3,     y + h) +
			   image.Area(x + 2 * w_3, y, x + w,       y + h);

	return cmp(a, b);
}

}; // namespace chromaprint

#endif

#line 1 "src/filter_utils.h [fin]"

namespace chromaprint {

class Filter {
public:
	Filter(int type = 0, int y = 0, int height = 0, int width = 0)
		: m_type(type), m_y(y), m_height(height), m_width(width) { }

	template <typename IntegralImage>
	double Apply(const IntegralImage &image, size_t x) const {
		switch (m_type) {
			case 0:
				return Filter0(image, x, m_y, m_width, m_height, SubtractLog);
			case 1:
				return Filter1(image, x, m_y, m_width, m_height, SubtractLog);
			case 2:
				return Filter2(image, x, m_y, m_width, m_height, SubtractLog);
			case 3:
				return Filter3(image, x, m_y, m_width, m_height, SubtractLog);
			case 4:
				return Filter4(image, x, m_y, m_width, m_height, SubtractLog);
			case 5:
				return Filter5(image, x, m_y, m_width, m_height, SubtractLog);
		}
		return 0.0;
	}

	int type() const { return m_type; }
	void set_type(int type) { m_type = type; }

	int y() const { return m_y; }
	void set_y(int y) { m_y = y; }

	int height() const { return m_height; }
	void set_height(int height) { m_height = height; }

	int width() const { return m_width; }
	void set_width(int width) { m_width = width; }

private:
	int m_type;
	int m_y;
	int m_height;
	int m_width;
};

inline std::ostream &operator<<(std::ostream &stream, const Filter &f) {
	stream << "Filter(" << f.type() << ", " << f.y() << ", "
		<< f.height() << ", " << f.width() << ")";
	return stream;
}
	
}; // namespace chromaprint

#endif

#line 1 "src/filter.h [fin]"

namespace chromaprint {

class Classifier
{
public:
	Classifier(const Filter &filter = Filter(), const Quantizer &quantizer = Quantizer())
		: m_filter(filter), m_quantizer(quantizer) { }

	template <typename IntegralImage>
	int Classify(const IntegralImage &image, size_t offset) const {
		double value = m_filter.Apply(image, offset);
		return m_quantizer.Quantize(value);
	}

	const Filter &filter() const { return m_filter; }
	const Quantizer &quantizer() const { return m_quantizer; }

private:
	Filter m_filter;
	Quantizer m_quantizer;
};

inline std::ostream &operator<<(std::ostream &stream, const Classifier &q) {
	stream << "Classifier(" << q.filter() << ", " << q.quantizer() << ")";
	return stream;
}

}; // namespace chromaprint

#endif

#line 1 "src/classifier.h [fin]"

#line 1 "src/chromaprint.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_CHROMAPRINT_H_
#define CHROMAPRINT_CHROMAPRINT_H_

/**
 * @mainpage Chromaprint
 *
 * @section intro Introduction
 *
 * Chromaprint is a library for generating audio fingerprints, mainly to be used with the <a href="https://acoustid.org">AcoustID</a> service.
 *
 * It needs raw audio stream (16-bit signed int) on input. The audio can have any sampling rate and any number of channels. Typically,
 * you would use some native library for decoding compressed audio files and feed the result into Chromaprint.
 *
 * Audio fingerprints returned from the library can be represented either as
 * base64-encoded strings or 32-bit integer arrays. The base64-encoded strings
 * are usually what's used externally when you need to send the fingerprint
 * to a service. You can't directly compare the fingerprints in such form.
 * The 32-bit integer arrays are also called "raw fingerprints" and they
 * represent the internal structure of the fingerprints. If you want to
 * compare two fingerprints yourself, you probably want them in this form.
 *
 * @section generating Generating fingerprints
 *
 * Here is a simple example code that generates a fingerprint from audio samples in memory:
 *
 * @code
 * ChromaprintContext *ctx;
 * char *fp;
 *
 * const int sample_rate = 44100;
 * const int num_channels = 2;
 *
 * ctx = chromaprint_new(CHROMAPRINT_ALGORITHM_DEFAULT);
 *
 * chromaprint_start(ctx, sample_rate, num_channels);
 * while (has_more_data) {
 *     chromaprint_feed(ctx, data, size);
 * }
 * chromaprint_finish(ctx);
 *
 * chromaprint_get_fingerprint(ctx, &fp);
 * printf("%s\n", fp);
 * chromaprint_dealloc(fp);
 *
 * chromaprint_free(ctx);
 * @endcode
 *
 * Note that there is no error handling in the code above. Almost any of the called functions can fail.
 * You should check the return values in an actual code.
 */

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(_WIN32) || defined(_WIN64))
#	ifdef CHROMAPRINT_NODLL
#		define CHROMAPRINT_API
#	else
#		ifdef CHROMAPRINT_API_EXPORTS
#			define CHROMAPRINT_API __declspec(dllexport)
#		else
#			define CHROMAPRINT_API __declspec(dllimport)
#		endif
#	endif
#else
#   if __GNUC__ >= 4
#       define CHROMAPRINT_API __attribute__ ((visibility("default")))
#   else
#       define CHROMAPRINT_API
#   endif
#endif

#include <stdint.h>

struct ChromaprintContextPrivate;
typedef struct ChromaprintContextPrivate ChromaprintContext;

struct ChromaprintMatcherContextPrivate;
typedef struct ChromaprintMatcherContextPrivate ChromaprintMatcherContext;

#define CHROMAPRINT_VERSION_MAJOR 1
#define CHROMAPRINT_VERSION_MINOR 6
#define CHROMAPRINT_VERSION_PATCH 2

enum ChromaprintAlgorithm {
	CHROMAPRINT_ALGORITHM_TEST1 = 0,
	CHROMAPRINT_ALGORITHM_TEST2,
	CHROMAPRINT_ALGORITHM_TEST3,
	CHROMAPRINT_ALGORITHM_TEST4,                   // removes leading silence
	CHROMAPRINT_ALGORITHM_TEST5,
	CHROMAPRINT_ALGORITHM_DEFAULT = CHROMAPRINT_ALGORITHM_TEST2,
};

/**
 * Return the version number of Chromaprint.
 */
CHROMAPRINT_API const char *chromaprint_get_version(void);

/**
 * Allocate and initialize the Chromaprint context.
 *
 * Note that when Chromaprint is compiled with FFTW, this function is
 * not reentrant and you need to call it only from one thread at a time.
 * This is not a problem when using FFmpeg or vDSP.
 *
 * @param algorithm the fingerprint algorithm version you want to use, or
 *		CHROMAPRINT_ALGORITHM_DEFAULT for the default algorithm
 *
 * @return ctx Chromaprint context pointer
 */
CHROMAPRINT_API ChromaprintContext *chromaprint_new(int algorithm);

/**
 * Deallocate the Chromaprint context.
 *
 * Note that when Chromaprint is compiled with FFTW, this function is
 * not reentrant and you need to call it only from one thread at a time.
 * This is not a problem when using FFmpeg or vDSP.
 *
 * @param[in] ctx Chromaprint context pointer
 */
CHROMAPRINT_API void chromaprint_free(ChromaprintContext *ctx);

/**
 * Return the fingerprint algorithm this context is configured to use.
 * @param[in] ctx Chromaprint context pointer
 * @return current algorithm version
 */
CHROMAPRINT_API int chromaprint_get_algorithm(ChromaprintContext *ctx);

/**
 * Set a configuration option for the selected fingerprint algorithm.
 *
 * DO NOT USE THIS FUNCTION IF YOU ARE PLANNING TO USE
 * THE GENERATED FINGERPRINTS WITH THE ACOUSTID SERVICE.
 *
 * Possible options:
 *  - silence_threshold: threshold for detecting silence, 0-32767
 *
 * @param[in] ctx Chromaprint context pointer
 * @param[in] name option name
 * @param[in] value option value
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_set_option(ChromaprintContext *ctx, const char *name, int value);

/**
 * Get the number of channels that is internally used for fingerprinting.
 *
 * @note You normally don't need this. Just set the audio's actual number of channels
 * when calling chromaprint_start() and everything will work. This is only used for
 * certain optimized cases to control the audio source.
 *
 * @param[in] ctx Chromaprint context pointer
 *
 * @return number of channels
 */
CHROMAPRINT_API int chromaprint_get_num_channels(ChromaprintContext *ctx);

/**
 * Get the sampling rate that is internally used for fingerprinting.
 *
 * @note You normally don't need this. Just set the audio's actual number of channels
 * when calling chromaprint_start() and everything will work. This is only used for
 * certain optimized cases to control the audio source.
 *
 * @param[in] ctx Chromaprint context pointer
 *
 * @return sampling rate
 */
CHROMAPRINT_API int chromaprint_get_sample_rate(ChromaprintContext *ctx);

/**
 * Get the duration of one item in the raw fingerprint in samples.
 *
 * @param[in] ctx Chromaprint context pointer
 *
 * @return duration in samples
 */
CHROMAPRINT_API int chromaprint_get_item_duration(ChromaprintContext *ctx);

/**
 * Get the duration of one item in the raw fingerprint in milliseconds.
 *
 * @param[in] ctx Chromaprint context pointer
 *
 * @return duration in milliseconds
 */
CHROMAPRINT_API int chromaprint_get_item_duration_ms(ChromaprintContext *ctx);

/**
 * Get the duration of internal buffers that the fingerprinting algorithm uses.
 *
 * @param[in] ctx Chromaprint context pointer
 *
 * @return duration in samples
 */
CHROMAPRINT_API int chromaprint_get_delay(ChromaprintContext *ctx);

/**
 * Get the duration of internal buffers that the fingerprinting algorithm uses.
 *
 * @param[in] ctx Chromaprint context pointer
 *
 * @return duration in milliseconds
 */
CHROMAPRINT_API int chromaprint_get_delay_ms(ChromaprintContext *ctx);

/**
 * Restart the computation of a fingerprint with a new audio stream.
 *
 * @param[in] ctx Chromaprint context pointer
 * @param[in] sample_rate sample rate of the audio stream (in Hz)
 * @param[in] num_channels numbers of channels in the audio stream (1 or 2)
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_start(ChromaprintContext *ctx, int sample_rate, int num_channels);

/**
 * Send audio data to the fingerprint calculator.
 *
 * @param[in] ctx Chromaprint context pointer
 * @param[in] data raw audio data, should point to an array of 16-bit signed
 *          integers in native byte-order
 * @param[in] size size of the data buffer (in samples)
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_feed(ChromaprintContext *ctx, const int16_t *data, int size);

/**
 * Process any remaining buffered audio data.
 *
 * @param[in] ctx Chromaprint context pointer
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_finish(ChromaprintContext *ctx);

/**
 * Return the calculated fingerprint as a compressed string.
 *
 * The caller is responsible for freeing the returned pointer using
 * chromaprint_dealloc().
 *
 * @param[in] ctx Chromaprint context pointer
 * @param[out] fingerprint pointer to a pointer, where a pointer to the allocated array
 *                 will be stored
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_get_fingerprint(ChromaprintContext *ctx, char **fingerprint);

/**
 * Return the calculated fingerprint as an array of 32-bit integers.
 *
 * The caller is responsible for freeing the returned pointer using
 * chromaprint_dealloc().
 *
 * @param[in] ctx Chromaprint context pointer
 * @param[out] fingerprint pointer to a pointer, where a pointer to the allocated array
 *                 will be stored
 * @param[out] size number of items in the returned raw fingerprint
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_get_raw_fingerprint(ChromaprintContext *ctx, uint32_t **fingerprint, int *size);

/**
 * Return the length of the current raw fingerprint.
 *
 * @param[in] ctx Chromaprint context pointer
 * @param[out] size number of items in the current raw fingerprint
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_get_raw_fingerprint_size(ChromaprintContext *ctx, int *size);

/**
 * Return 32-bit hash of the calculated fingerprint.
 *
 * See chromaprint_hash_fingerprint() for details on how to use the hash.
 *
 * @param[in] ctx Chromaprint context pointer
 * @param[out] hash pointer to a 32-bit integer where the hash will be stored
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_get_fingerprint_hash(ChromaprintContext *ctx, uint32_t *hash);

/**
 * Clear the current fingerprint, but allow more data to be processed.
 *
 * This is useful if you are processing a long stream and want to many
 * smaller fingerprints, instead of waiting for the entire stream to be
 * processed.
 *
 * @param[in] ctx Chromaprint context pointer
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_clear_fingerprint(ChromaprintContext *ctx);

/**
 * Compress and optionally base64-encode a raw fingerprint
 *
 * The caller is responsible for freeing the returned pointer using
 * chromaprint_dealloc().
 *
 * @param[in] fp pointer to an array of 32-bit integers representing the raw
 *        fingerprint to be encoded
 * @param[in] size number of items in the raw fingerprint
 * @param[in] algorithm Chromaprint algorithm version which was used to generate the
 *               raw fingerprint
 * @param[out] encoded_fp pointer to a pointer, where the encoded fingerprint will be
 *                stored
 * @param[out] encoded_size size of the encoded fingerprint in bytes
 * @param[in] base64 Whether to return binary data or base64-encoded ASCII data. The
 *            compressed fingerprint will be encoded using base64 with the
 *            URL-safe scheme if you set this parameter to 1. It will return
 *            binary data if it's 0.
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_encode_fingerprint(const uint32_t *fp, int size, int algorithm, char **encoded_fp, int *encoded_size, int base64);

/**
 * Uncompress and optionally base64-decode an encoded fingerprint
 *
 * The caller is responsible for freeing the returned pointer using
 * chromaprint_dealloc().
 *
 * @param[in] encoded_fp pointer to an encoded fingerprint
 * @param[in] encoded_size size of the encoded fingerprint in bytes
 * @param[out] fp pointer to a pointer, where the decoded raw fingerprint (array
 *        of 32-bit integers) will be stored
 * @param[out] size Number of items in the returned raw fingerprint
 * @param[out] algorithm Chromaprint algorithm version which was used to generate the
 *               raw fingerprint
 * @param[in] base64 Whether the encoded_fp parameter contains binary data or
 *            base64-encoded ASCII data. If 1, it will base64-decode the data
 *            before uncompressing the fingerprint.
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_decode_fingerprint(const char *encoded_fp, int encoded_size, uint32_t **fp, int *size, int *algorithm, int base64);

/**
 * Uncompress and optionally base64-decode an encoded fingerprint
 *
 * The caller is responsible for freeing the returned pointer using
 * chromaprint_dealloc().
 *
 * @param[in] encoded_fp pointer to an encoded fingerprint
 * @param[in] encoded_size size of the encoded fingerprint in bytes
 * @param[out] size Number of items in the returned raw fingerprint
 * @param[out] algorithm Chromaprint algorithm version which was used to generate the
 *               raw fingerprint
 * @param[in] base64 Whether the encoded_fp parameter contains binary data or
 *            base64-encoded ASCII data. If 1, it will base64-decode the data
 *            before uncompressing the fingerprint.
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_decode_fingerprint_header(const char *encoded_fp, int encoded_size, int *size, int *algorithm, int base64);

/**
 * Generate a single 32-bit hash for a raw fingerprint.
 *
 * If two fingerprints are similar, their hashes generated by this function
 * will also be similar. If they are significantly different, their hashes
 * will most likely be significantly different as well, but you can't rely
 * on that.
 *
 * You compare two hashes by counting the bits in which they differ. Normally
 * that would be something like POPCNT(hash1 XOR hash2), which returns a
 * number between 0 and 32. Anthing above 15 means the hashes are
 * completely different.
 *
 * @param[in] fp pointer to an array of 32-bit integers representing the raw
 *        fingerprint to be hashed
 * @param[in] size number of items in the raw fingerprint
 * @param[out] hash pointer to a 32-bit integer where the hash will be stored
 *
 * @return 0 on error, 1 on success
 */
CHROMAPRINT_API int chromaprint_hash_fingerprint(const uint32_t *fp, int size, uint32_t *hash);

/**
 * Free memory allocated by any function from the Chromaprint API.
 *
 * @param ptr pointer to be deallocated
 */
CHROMAPRINT_API void chromaprint_dealloc(void *ptr);

#ifdef __cplusplus
}
#endif

#endif

#line 1 "src/chromaprint.h [fin]"

namespace chromaprint {

static const int DEFAULT_SAMPLE_RATE = 11025;

class FingerprinterConfiguration
{
public:	

	FingerprinterConfiguration()
		: m_num_classifiers(0), m_classifiers(0), m_remove_silence(false), m_silence_threshold(0), m_frame_size(0), m_frame_overlap(0)
	{
	}

	int num_filter_coefficients() const
	{
		return m_num_filter_coefficients;
	}

	const double *filter_coefficients() const
	{
		return m_filter_coefficients;
	}

	void set_filter_coefficients(const double *filter_coefficients, int size)
	{
		m_filter_coefficients = filter_coefficients;
		m_num_filter_coefficients = size;
	}

	int num_classifiers() const
	{
		return m_num_classifiers;
	}

	const Classifier *classifiers() const
	{
		return m_classifiers;
	}

	int max_filter_width() const {
		return m_max_filter_width;
	}

	void set_classifiers(const Classifier *classifiers, int size)
	{
		m_classifiers = classifiers;
		m_num_classifiers = size;
		m_max_filter_width = 0;
		for (int i = 0; i < size; i++) {
			m_max_filter_width = std::max(m_max_filter_width, classifiers[i].filter().width());
		}
	}

	bool interpolate() const 
	{
		return m_interpolate;
	}

	void set_interpolate(bool value)
	{
		m_interpolate = value;
	}

	bool remove_silence() const 
	{
		return m_remove_silence;
	}

	void set_remove_silence(bool value)
	{
		m_remove_silence = value;
	}

	int silence_threshold() const
	{
		return m_silence_threshold;
	}

	void set_silence_threshold(int value)
	{
		m_silence_threshold = value;
	}

	int frame_size() const
	{
		return m_frame_size;
	}

	void set_frame_size(int value)
	{
		m_frame_size = value;
	}

	int frame_overlap() const
	{
		return m_frame_overlap;
	}

	void set_frame_overlap(int value)
	{
		m_frame_overlap = value;
	}

	int sample_rate() const {
		return DEFAULT_SAMPLE_RATE;
	}

	int item_duration() const {
		return m_frame_size - m_frame_overlap;
	}

	double item_duration_in_seconds() const {
		return item_duration() * 1.0 / sample_rate();
	}

	int delay() const {
		return ((m_num_filter_coefficients - 1) + (m_max_filter_width - 1)) * item_duration() + m_frame_overlap;
	}

	double delay_in_seconds() const {
		return delay() * 1.0 / sample_rate();
	}

private:
	int m_num_classifiers;
	int m_max_filter_width;
	const Classifier *m_classifiers;
	int m_num_filter_coefficients;
	const double *m_filter_coefficients;
	bool m_interpolate;
	bool m_remove_silence;
	int m_silence_threshold;
	int m_frame_size;
	int m_frame_overlap;
};

// Used for http://oxygene.sk/lukas/2010/07/introducing-chromaprint/
// Trained on a randomly selected test data
class FingerprinterConfigurationTest1 : public FingerprinterConfiguration
{
public:
	FingerprinterConfigurationTest1();
};

// Trained on 60k pairs based on eMusic samples (mp3)
class FingerprinterConfigurationTest2 : public FingerprinterConfiguration
{
public:
	FingerprinterConfigurationTest2();
};

// Trained on 60k pairs based on eMusic samples with interpolation enabled (mp3)
class FingerprinterConfigurationTest3 : public FingerprinterConfiguration
{
public:
	FingerprinterConfigurationTest3();
};

// Same as v2, but trims leading silence
class FingerprinterConfigurationTest4 : public FingerprinterConfigurationTest2
{
public:
	FingerprinterConfigurationTest4();
};

// Same as v2, but with 2x more precise sampling
class FingerprinterConfigurationTest5 : public FingerprinterConfigurationTest2
{
public:
	FingerprinterConfigurationTest5();
};

inline FingerprinterConfiguration *CreateFingerprinterConfiguration(int algorithm)
{
	switch (algorithm) {
	case CHROMAPRINT_ALGORITHM_TEST1:
		return new FingerprinterConfigurationTest1();
	case CHROMAPRINT_ALGORITHM_TEST2:
		return new FingerprinterConfigurationTest2();
	case CHROMAPRINT_ALGORITHM_TEST3:
		return new FingerprinterConfigurationTest3();
	case CHROMAPRINT_ALGORITHM_TEST4:
		return new FingerprinterConfigurationTest4();
	case CHROMAPRINT_ALGORITHM_TEST5:
		return new FingerprinterConfigurationTest5();
	}
	return 0;
}

}; // namespace chromaprint

#endif

#line 1 "src/fingerprinter_configuration.h [fin]"

// [omitido por inclusión previa: src/classifier.h]

// [omitido por inclusión previa: src/utils.h]

// [omitido por inclusión previa: src/debug.h]

namespace chromaprint {

static const int MIN_FREQ = 28;
static const int MAX_FREQ = 3520;

Fingerprinter::Fingerprinter(FingerprinterConfiguration *config) {
	if (!config) {
		config = new FingerprinterConfigurationTest1();
	}
	m_fingerprint_calculator = new FingerprintCalculator(config->classifiers(), config->num_classifiers());
	m_chroma_normalizer = new ChromaNormalizer(m_fingerprint_calculator);
	m_chroma_filter = new ChromaFilter(config->filter_coefficients(), config->num_filter_coefficients(), m_chroma_normalizer);
	m_chroma = new Chroma(MIN_FREQ, MAX_FREQ, config->frame_size(), config->sample_rate(), m_chroma_filter);
	//m_chroma->set_interpolate(true);
	m_fft = new FFT(config->frame_size(), config->frame_overlap(), m_chroma);
	if (config->remove_silence()) {
		m_silence_remover = new SilenceRemover(m_fft);
		m_silence_remover->set_threshold(config->silence_threshold());
		m_audio_processor = new AudioProcessor(config->sample_rate(), m_silence_remover);
	}
	else {
		m_silence_remover = 0;
		m_audio_processor = new AudioProcessor(config->sample_rate(), m_fft);
	}
	m_config = config;
}

Fingerprinter::~Fingerprinter()
{
	delete m_audio_processor;
	if (m_silence_remover) {
		delete m_silence_remover;
	}
	delete m_fft;
	delete m_chroma;
	delete m_chroma_filter;
	delete m_chroma_normalizer;
	delete m_fingerprint_calculator;
	delete m_config;
}

bool Fingerprinter::SetOption(const char *name, int value)
{
	if (!strcmp(name, "silence_threshold")) {
		if (m_silence_remover) {
			m_silence_remover->set_threshold(value);
			return true;
		}
	}
	return false;
}

bool Fingerprinter::Start(int sample_rate, int num_channels)
{
	if (!m_audio_processor->Reset(sample_rate, num_channels)) {
		// FIXME save error message somewhere
		return false;
	}
	m_fft->Reset();
	m_chroma->Reset();
	m_chroma_filter->Reset();
	m_chroma_normalizer->Reset();
	m_fingerprint_calculator->Reset();
	return true;
}

void Fingerprinter::Consume(const int16_t *samples, int length)
{
	assert(length >= 0);
	m_audio_processor->Consume(samples, length);
}

void Fingerprinter::Finish()
{
	m_audio_processor->Flush();
}

const std::vector<uint32_t> &Fingerprinter::GetFingerprint() const {
	return m_fingerprint_calculator->GetFingerprint();
}

void Fingerprinter::ClearFingerprint() {
	m_fingerprint_calculator->ClearFingerprint();
}

}; // namespace chromaprint

#line 1 "src/fingerprinter.cpp [fin]"

#line 1 "src/image_builder.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <limits>
#include <cassert>
#include <cmath>

// [omitido por inclusión previa: src/image_builder.h]

namespace chromaprint {

ImageBuilder::ImageBuilder(Image *image)
	: m_image(image)
{
}

ImageBuilder::~ImageBuilder()
{
}

void ImageBuilder::Consume(std::vector<double> &features)
{
	assert(features.size() == (size_t)m_image->NumColumns());
	m_image->AddRow(features);
}

}; // namespace chromaprint

#line 1 "src/image_builder.cpp [fin]"

#line 1 "src/simhash.cpp"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.


#line 1 "src/simhash.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_SIMHASH_H_
#define CHROMAPRINT_SIMHASH_H_

#include <vector>

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

uint32_t SimHash(const uint32_t *data, size_t size);

uint32_t SimHash(const std::vector<uint32_t> &data);

}; // namespace chromaprint

#endif

#line 1 "src/simhash.h [fin]"

namespace chromaprint {

uint32_t SimHash(const uint32_t *data, size_t size)
{
	int v[32];

	for (size_t i = 0; i < 32; i++) {
		v[i] = 0;
	}

	for (size_t i = 0; i < size; i++) {
		uint32_t local_hash = data[i];
		for (size_t j = 0; j < 32; j++) {
			v[j] += (local_hash >> j) & 1;
		}
	}

	const size_t threshold = size / 2;
	uint32_t hash = 0;
	for (size_t i = 0; i < 32; i++) {
		const int b = static_cast<size_t>(v[i]) > threshold ? 1 : 0;
		hash |= (b << i);
	}

	return hash;
}

uint32_t SimHash(const std::vector<uint32_t> &data)
{
	if (data.empty()) {
		return 0;
	} else {
		return SimHash(&data[0], data.size());
	}
}

}; // namespace chromaprint

#line 1 "src/simhash.cpp [fin]"

#line 1 "src/silence_remover.cpp"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <cassert>
#include <algorithm>

// [omitido por inclusión previa: src/debug.h]

// [omitido por inclusión previa: src/silence_remover.h]

namespace chromaprint {

const short kSilenceWindow = 55; // 5 ms as 11025 Hz

SilenceRemover::SilenceRemover(AudioConsumer *consumer, int threshold)
    : m_start(true),
	  m_threshold(threshold),
	  m_average(kSilenceWindow),
	  m_consumer(consumer)
{
}

bool SilenceRemover::Reset(int sample_rate, int num_channels)
{
	if (num_channels != 1) {
		DEBUG("chromaprint::SilenceRemover::Reset() -- Expecting mono audio signal.");
		return false;
	}
	m_start = true;
	return true;
}

void SilenceRemover::Consume(const int16_t *input, int length)
{
	if (m_start) {
		while (length) {
			m_average.AddValue(std::abs(*input));
			if (m_average.GetAverage() > m_threshold) {
				m_start = false;
				break;
			}
			input++;
			length--;
		}
	}
	if (length) {
		m_consumer->Consume(input, length);
	}
}

void SilenceRemover::Flush()
{
}

}; // namespace chromaprint

#line 1 "src/silence_remover.cpp [fin]"

#line 1 "src/fingerprint_calculator.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.


// [omitido por inclusión previa: src/fingerprint_calculator.h]

// [omitido por inclusión previa: src/classifier.h]

// [omitido por inclusión previa: src/debug.h]

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

FingerprintCalculator::FingerprintCalculator(const Classifier *classifiers, size_t num_classifiers)
	: m_classifiers(classifiers), m_num_classifiers(num_classifiers), m_image(256)
{
	m_max_filter_width = 0;
	for (size_t i = 0; i < num_classifiers; i++) {
		m_max_filter_width = std::max(m_max_filter_width, (size_t) classifiers[i].filter().width());
	}
	assert(m_max_filter_width > 0);
	assert(m_max_filter_width < 256);
}

uint32_t FingerprintCalculator::CalculateSubfingerprint(size_t offset)
{
	uint32_t bits = 0;
	for (size_t i = 0; i < m_num_classifiers; i++) {
		bits = (bits << 2) | GrayCode(m_classifiers[i].Classify(m_image, offset));
	}
	return bits;
}

void FingerprintCalculator::Reset() {
	m_image.Reset();
	m_fingerprint.clear();
}

void FingerprintCalculator::Consume(std::vector<double> &features) {
	m_image.AddRow(features);
	if (m_image.num_rows() >= m_max_filter_width) {
		m_fingerprint.push_back(CalculateSubfingerprint(m_image.num_rows() - m_max_filter_width));
	}
}

const std::vector<uint32_t> &FingerprintCalculator::GetFingerprint() const {
	return m_fingerprint;
}

void FingerprintCalculator::ClearFingerprint() {
	m_fingerprint.clear();
}

}; // namespace chromaprint

#line 1 "src/fingerprint_calculator.cpp [fin]"

#line 1 "src/fingerprint_compressor.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <algorithm>

#line 1 "src/fingerprint_compressor.h"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FINGERPRINT_COMPRESSOR_H_
#define CHROMAPRINT_FINGERPRINT_COMPRESSOR_H_

#include <cstdint>
#include <vector>
#include <string>

namespace chromaprint {

class FingerprintCompressor
{
public:
	FingerprintCompressor();

	std::string Compress(const std::vector<uint32_t> &fingerprint, int algorithm = 0) {
		std::string tmp;
		Compress(fingerprint, algorithm, tmp);
		return tmp;
	}

	void Compress(const std::vector<uint32_t> &fingerprint, int algorithm, std::string &output);

private:
	void ProcessSubfingerprint(uint32_t);
	std::vector<unsigned char> m_normal_bits;
	std::vector<unsigned char> m_exceptional_bits;
};

inline std::string CompressFingerprint(const std::vector<uint32_t> &data, int algorithm = 0)
{
	FingerprintCompressor compressor;
	return compressor.Compress(data, algorithm);
}

}; // namespace chromaprint

#endif


#line 1 "src/fingerprint_compressor.h [fin]"

// [omitido por inclusión previa: src/utils.h]

#line 1 "src/utils/pack_int3_array.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

// This file was automatically generate using gen_bit_writer.py, do not edit.

#ifndef CHROMAPRINT_UTILS_PACK_INT3_ARRAY_H_
#define CHROMAPRINT_UTILS_PACK_INT3_ARRAY_H_

#include <algorithm>

namespace chromaprint {

inline size_t GetPackedInt3ArraySize(size_t size) {
	return (size * 3 + 7) / 8;
}

template <typename InputIt, typename OutputIt>
inline OutputIt PackInt3Array(const InputIt first, const InputIt last, OutputIt dest) {
	auto size = std::distance(first, last);
	auto src = first;
	while (size >= 8) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		const unsigned char s5 = *src++;
		const unsigned char s6 = *src++;
		const unsigned char s7 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x07)) | ((s1 & 0x07) << 3) | ((s2 & 0x03) << 6);
		*dest++ = (unsigned char) ((s2 & 0x04) >> 2) | ((s3 & 0x07) << 1) | ((s4 & 0x07) << 4) | ((s5 & 0x01) << 7);
		*dest++ = (unsigned char) ((s5 & 0x06) >> 1) | ((s6 & 0x07) << 2) | ((s7 & 0x07) << 5);
		size -= 8;
	}
	if (size == 7) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		const unsigned char s5 = *src++;
		const unsigned char s6 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x07)) | ((s1 & 0x07) << 3) | ((s2 & 0x03) << 6);
		*dest++ = (unsigned char) ((s2 & 0x04) >> 2) | ((s3 & 0x07) << 1) | ((s4 & 0x07) << 4) | ((s5 & 0x01) << 7);
		*dest++ = (unsigned char) ((s5 & 0x06) >> 1) | ((s6 & 0x07) << 2);
	} else if (size == 6) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		const unsigned char s5 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x07)) | ((s1 & 0x07) << 3) | ((s2 & 0x03) << 6);
		*dest++ = (unsigned char) ((s2 & 0x04) >> 2) | ((s3 & 0x07) << 1) | ((s4 & 0x07) << 4) | ((s5 & 0x01) << 7);
		*dest++ = (unsigned char) ((s5 & 0x06) >> 1);
	} else if (size == 5) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x07)) | ((s1 & 0x07) << 3) | ((s2 & 0x03) << 6);
		*dest++ = (unsigned char) ((s2 & 0x04) >> 2) | ((s3 & 0x07) << 1) | ((s4 & 0x07) << 4);
	} else if (size == 4) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x07)) | ((s1 & 0x07) << 3) | ((s2 & 0x03) << 6);
		*dest++ = (unsigned char) ((s2 & 0x04) >> 2) | ((s3 & 0x07) << 1);
	} else if (size == 3) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x07)) | ((s1 & 0x07) << 3) | ((s2 & 0x03) << 6);
		*dest++ = (unsigned char) ((s2 & 0x04) >> 2);
	} else if (size == 2) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x07)) | ((s1 & 0x07) << 3);
	} else if (size == 1) {
		const unsigned char s0 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x07));
	}
	 return dest;
}

}; // namespace chromaprint

#endif

#line 1 "src/utils/pack_int3_array.h [fin]"

#line 1 "src/utils/pack_int5_array.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

// This file was automatically generate using gen_bit_writer.py, do not edit.

#ifndef CHROMAPRINT_UTILS_PACK_INT5_ARRAY_H_
#define CHROMAPRINT_UTILS_PACK_INT5_ARRAY_H_

#include <algorithm>

namespace chromaprint {

inline size_t GetPackedInt5ArraySize(size_t size) {
	return (size * 5 + 7) / 8;
}

template <typename InputIt, typename OutputIt>
inline OutputIt PackInt5Array(const InputIt first, const InputIt last, OutputIt dest) {
	auto size = std::distance(first, last);
	auto src = first;
	while (size >= 8) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		const unsigned char s5 = *src++;
		const unsigned char s6 = *src++;
		const unsigned char s7 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x1f)) | ((s1 & 0x07) << 5);
		*dest++ = (unsigned char) ((s1 & 0x18) >> 3) | ((s2 & 0x1f) << 2) | ((s3 & 0x01) << 7);
		*dest++ = (unsigned char) ((s3 & 0x1e) >> 1) | ((s4 & 0x0f) << 4);
		*dest++ = (unsigned char) ((s4 & 0x10) >> 4) | ((s5 & 0x1f) << 1) | ((s6 & 0x03) << 6);
		*dest++ = (unsigned char) ((s6 & 0x1c) >> 2) | ((s7 & 0x1f) << 3);
		size -= 8;
	}
	if (size == 7) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		const unsigned char s5 = *src++;
		const unsigned char s6 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x1f)) | ((s1 & 0x07) << 5);
		*dest++ = (unsigned char) ((s1 & 0x18) >> 3) | ((s2 & 0x1f) << 2) | ((s3 & 0x01) << 7);
		*dest++ = (unsigned char) ((s3 & 0x1e) >> 1) | ((s4 & 0x0f) << 4);
		*dest++ = (unsigned char) ((s4 & 0x10) >> 4) | ((s5 & 0x1f) << 1) | ((s6 & 0x03) << 6);
		*dest++ = (unsigned char) ((s6 & 0x1c) >> 2);
	} else if (size == 6) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		const unsigned char s5 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x1f)) | ((s1 & 0x07) << 5);
		*dest++ = (unsigned char) ((s1 & 0x18) >> 3) | ((s2 & 0x1f) << 2) | ((s3 & 0x01) << 7);
		*dest++ = (unsigned char) ((s3 & 0x1e) >> 1) | ((s4 & 0x0f) << 4);
		*dest++ = (unsigned char) ((s4 & 0x10) >> 4) | ((s5 & 0x1f) << 1);
	} else if (size == 5) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x1f)) | ((s1 & 0x07) << 5);
		*dest++ = (unsigned char) ((s1 & 0x18) >> 3) | ((s2 & 0x1f) << 2) | ((s3 & 0x01) << 7);
		*dest++ = (unsigned char) ((s3 & 0x1e) >> 1) | ((s4 & 0x0f) << 4);
		*dest++ = (unsigned char) ((s4 & 0x10) >> 4);
	} else if (size == 4) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x1f)) | ((s1 & 0x07) << 5);
		*dest++ = (unsigned char) ((s1 & 0x18) >> 3) | ((s2 & 0x1f) << 2) | ((s3 & 0x01) << 7);
		*dest++ = (unsigned char) ((s3 & 0x1e) >> 1);
	} else if (size == 3) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x1f)) | ((s1 & 0x07) << 5);
		*dest++ = (unsigned char) ((s1 & 0x18) >> 3) | ((s2 & 0x1f) << 2);
	} else if (size == 2) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x1f)) | ((s1 & 0x07) << 5);
		*dest++ = (unsigned char) ((s1 & 0x18) >> 3);
	} else if (size == 1) {
		const unsigned char s0 = *src++;
		*dest++ = (unsigned char) ((s0 & 0x1f));
	}
	 return dest;
}

}; // namespace chromaprint

#endif

#line 1 "src/utils/pack_int5_array.h [fin]"

namespace chromaprint {

static const int kNormalBits = 3;
static const int kMaxNormalValue = (1 << kNormalBits) - 1;

FingerprintCompressor::FingerprintCompressor()
{
}

void FingerprintCompressor::ProcessSubfingerprint(uint32_t x)
{
	int bit = 1, last_bit = 0;
	while (x != 0) {
		if ((x & 1) != 0) {
			const auto value = bit - last_bit;
			if (value >= kMaxNormalValue) {
				m_normal_bits.push_back(kMaxNormalValue);
				m_exceptional_bits.push_back(value - kMaxNormalValue);
			} else {
				m_normal_bits.push_back(value);
			}
			last_bit = bit;
		}
		x >>= 1;
		bit++;
	}
	m_normal_bits.push_back(0);
}

void FingerprintCompressor::Compress(const std::vector<uint32_t> &data, int algorithm, std::string &output)
{
	const auto size = data.size();

	m_normal_bits.clear();
	m_exceptional_bits.clear();

	if (size > 0) {
		m_normal_bits.reserve(size * 8);
		m_exceptional_bits.reserve(size * 2);
		ProcessSubfingerprint(data[0]);
		for (size_t i = 1; i < size; i++) {
			ProcessSubfingerprint(data[i] ^ data[i - 1]);
		}
	}

	output.resize(4 + GetPackedInt3ArraySize(m_normal_bits.size()) + GetPackedInt5ArraySize(m_exceptional_bits.size()));
	output[0] = algorithm & 255;
	output[1] = (size >> 16) & 255;
	output[2] = (size >>  8) & 255;
	output[3] = (size      ) & 255;

	auto ptr = output.begin() + 4;
	ptr = PackInt3Array(m_normal_bits.begin(), m_normal_bits.end(), ptr);
	ptr = PackInt5Array(m_exceptional_bits.begin(), m_exceptional_bits.end(), ptr);
}

}; // namespace chromaprint


#line 1 "src/fingerprint_compressor.cpp [fin]"

#define kMaxNormalValue kMaxNormalValueDecompressor

#line 1 "src/fingerprint_decompressor.cpp"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.


#line 1 "src/fingerprint_decompressor.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FINGERPRINT_DECOMPRESSOR_H_
#define CHROMAPRINT_FINGERPRINT_DECOMPRESSOR_H_

#include <cstdint>
#include <vector>
#include <string>

namespace chromaprint {

class FingerprintDecompressor
{
public:
	FingerprintDecompressor();
	bool DecompressHeader(const std::string &fingerprint);
	bool Decompress(const std::string &fingerprint);

	std::vector<uint32_t> GetOutput() const { return m_output; }
	size_t GetSize() const { return m_size; }
	int GetAlgorithm() const { return m_algorithm; }

private:
	bool UnpackBits();
	std::vector<uint32_t> m_output;
	size_t m_size { 0 };
	int m_algorithm { -1 };
	std::vector<unsigned char> m_bits;
	std::vector<unsigned char> m_exceptional_bits;
};

inline bool DecompressFingerprint(const std::string &input, std::vector<uint32_t> &output, int &algorithm)
{
	FingerprintDecompressor decompressor;
	auto ok = decompressor.Decompress(input);
	if (ok) {
		output = decompressor.GetOutput();
		algorithm = decompressor.GetAlgorithm();
	}
	return ok;
}

inline bool DecompressFingerprintHeader(const std::string &input, size_t &size, int &algorithm)
{
	FingerprintDecompressor decompressor;
	auto ok = decompressor.DecompressHeader(input);
	if (ok) {
		size = decompressor.GetSize();
		algorithm = decompressor.GetAlgorithm();
	}
	return ok;
}

}; // namespace chromaprint

#endif

#line 1 "src/fingerprint_decompressor.h [fin]"

// [omitido por inclusión previa: src/debug.h]

// [omitido por inclusión previa: src/utils/pack_int3_array.h]

// [omitido por inclusión previa: src/utils/pack_int5_array.h]

#line 1 "src/utils/unpack_int3_array.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

// This file was automatically generate using gen_bit_reader.py, do not edit.

#ifndef CHROMAPRINT_UTILS_UNPACK_INT3_ARRAY_H_
#define CHROMAPRINT_UTILS_UNPACK_INT3_ARRAY_H_

#include <algorithm>

namespace chromaprint {

inline size_t GetUnpackedInt3ArraySize(size_t size) {
	return size * 8 / 3;
}

template <typename InputIt, typename OutputIt>
inline OutputIt UnpackInt3Array(const InputIt first, const InputIt last, OutputIt dest) {
	auto size = std::distance(first, last);
	auto src = first;
	while (size >= 3) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		*dest++ = (s0 & 0x07);
		*dest++ = ((s0 & 0x38) >> 3);
		*dest++ = ((s0 & 0xc0) >> 6) | ((s1 & 0x01) << 2);
		*dest++ = ((s1 & 0x0e) >> 1);
		*dest++ = ((s1 & 0x70) >> 4);
		*dest++ = ((s1 & 0x80) >> 7) | ((s2 & 0x03) << 1);
		*dest++ = ((s2 & 0x1c) >> 2);
		*dest++ = ((s2 & 0xe0) >> 5);
		size -= 3;
	}
	if (size == 2) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		*dest++ = (s0 & 0x07);
		*dest++ = ((s0 & 0x38) >> 3);
		*dest++ = ((s0 & 0xc0) >> 6) | ((s1 & 0x01) << 2);
		*dest++ = ((s1 & 0x0e) >> 1);
		*dest++ = ((s1 & 0x70) >> 4);
	} else if (size == 1) {
		const unsigned char s0 = *src++;
		*dest++ = (s0 & 0x07);
		*dest++ = ((s0 & 0x38) >> 3);
	}
	return dest;
}

}; // namespace chromaprint

#endif

#line 1 "src/utils/unpack_int3_array.h [fin]"

#line 1 "src/utils/unpack_int5_array.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

// This file was automatically generate using gen_bit_reader.py, do not edit.

#ifndef CHROMAPRINT_UTILS_UNPACK_INT5_ARRAY_H_
#define CHROMAPRINT_UTILS_UNPACK_INT5_ARRAY_H_

#include <algorithm>

namespace chromaprint {

inline size_t GetUnpackedInt5ArraySize(size_t size) {
	return size * 8 / 5;
}

template <typename InputIt, typename OutputIt>
inline OutputIt UnpackInt5Array(const InputIt first, const InputIt last, OutputIt dest) {
	auto size = std::distance(first, last);
	auto src = first;
	while (size >= 5) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		const unsigned char s4 = *src++;
		*dest++ = (s0 & 0x1f);
		*dest++ = ((s0 & 0xe0) >> 5) | ((s1 & 0x03) << 3);
		*dest++ = ((s1 & 0x7c) >> 2);
		*dest++ = ((s1 & 0x80) >> 7) | ((s2 & 0x0f) << 1);
		*dest++ = ((s2 & 0xf0) >> 4) | ((s3 & 0x01) << 4);
		*dest++ = ((s3 & 0x3e) >> 1);
		*dest++ = ((s3 & 0xc0) >> 6) | ((s4 & 0x07) << 2);
		*dest++ = ((s4 & 0xf8) >> 3);
		size -= 5;
	}
	if (size == 4) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		const unsigned char s3 = *src++;
		*dest++ = (s0 & 0x1f);
		*dest++ = ((s0 & 0xe0) >> 5) | ((s1 & 0x03) << 3);
		*dest++ = ((s1 & 0x7c) >> 2);
		*dest++ = ((s1 & 0x80) >> 7) | ((s2 & 0x0f) << 1);
		*dest++ = ((s2 & 0xf0) >> 4) | ((s3 & 0x01) << 4);
		*dest++ = ((s3 & 0x3e) >> 1);
	} else if (size == 3) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		*dest++ = (s0 & 0x1f);
		*dest++ = ((s0 & 0xe0) >> 5) | ((s1 & 0x03) << 3);
		*dest++ = ((s1 & 0x7c) >> 2);
		*dest++ = ((s1 & 0x80) >> 7) | ((s2 & 0x0f) << 1);
	} else if (size == 2) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		*dest++ = (s0 & 0x1f);
		*dest++ = ((s0 & 0xe0) >> 5) | ((s1 & 0x03) << 3);
		*dest++ = ((s1 & 0x7c) >> 2);
	} else if (size == 1) {
		const unsigned char s0 = *src++;
		*dest++ = (s0 & 0x1f);
	}
	return dest;
}

}; // namespace chromaprint

#endif

#line 1 "src/utils/unpack_int5_array.h [fin]"

// [omitido por inclusión previa: src/utils.h]

namespace chromaprint {

static const int kMaxNormalValue = 7;

FingerprintDecompressor::FingerprintDecompressor()
{
}

bool FingerprintDecompressor::UnpackBits()
{
	int i = 0, last_bit = 0;
    uint32_t value = 0;
	for (size_t j = 0; j < m_bits.size(); j++) {
		const int bit = m_bits[j];
		if (bit == 0) {
			m_output[i] = value;
			last_bit = 0;
			i++;
		} else {
			last_bit += bit;
			if (last_bit > 32) {
				DEBUG("FingerprintDecompressor::Decompress() -- Invalid fingerprint (bit position past 32)");
				return false;
			}
			value ^= uint32_t(1) << (last_bit - 1);
		}
	}
	return true;
}

bool FingerprintDecompressor::DecompressHeader(const std::string &input)
{
	if (input.size() < 4) {
		DEBUG("FingerprintDecompressor::Decompress() -- Invalid fingerprint (shorter than 4 bytes)");
		return false;
	}

	m_algorithm = input[0];

	m_size =
		((size_t)((unsigned char)(input[1])) << 16) |
		((size_t)((unsigned char)(input[2])) <<  8) |
		((size_t)((unsigned char)(input[3]))      );

	return true;
}


bool FingerprintDecompressor::Decompress(const std::string &input)
{
	if (!DecompressHeader(input)) {
		return false;
	}

	if (m_size == 0) {
		// An empty fingerprint has no body, so anything after the header is
		// trailing data, ignored like trailing data after any fingerprint.
		m_output.clear();
		return true;
	}

	size_t offset = 4;
	m_bits.resize(GetUnpackedInt3ArraySize(input.size() - offset));
	UnpackInt3Array(input.begin() + offset, input.end(), m_bits.begin());

	size_t found_values = 0, num_exceptional_bits = 0;
	for (size_t i = 0; i < m_bits.size(); i++) {
		if (m_bits[i] == 0) {
			found_values += 1;
			if (found_values == m_size) {
				m_bits.resize(i + 1);
				break;
			}
		} else if (m_bits[i] == kMaxNormalValue) {
			num_exceptional_bits += 1;
		}
	}

	if (found_values != m_size) {
		DEBUG("FingerprintDecompressor::Decompress() -- Invalid fingerprint (too short, not enough input for normal bits)");
		return false;
	}

	offset += GetPackedInt3ArraySize(m_bits.size());
	if (input.size() < offset + GetPackedInt5ArraySize(num_exceptional_bits)) {
		DEBUG("FingerprintDecompressor::Decompress() -- Invalid fingerprint (too short, not enough input for exceptional bits)");
		return false;
	}

	if (num_exceptional_bits) {
		m_exceptional_bits.resize(GetUnpackedInt5ArraySize(GetPackedInt5ArraySize(num_exceptional_bits)));
		UnpackInt5Array(input.begin() + offset,
						input.begin() + offset + GetPackedInt5ArraySize(num_exceptional_bits),
						m_exceptional_bits.begin());
		for (size_t i = 0, j = 0; i < m_bits.size(); i++) {
			if (m_bits[i] == kMaxNormalValue) {
				m_bits[i] += m_exceptional_bits[j++];
			}
		}
	}

	m_output.assign(m_size, -1);

	return UnpackBits();
}

}; // namespace chromaprint

#line 1 "src/fingerprint_decompressor.cpp [fin]"

#undef kMaxNormalValue

#line 1 "src/fingerprinter_configuration.cpp"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.


// [omitido por inclusión previa: src/fingerprinter_configuration.h]

// [omitido por inclusión previa: src/utils.h]

using namespace chromaprint;

static const int kDefaultFrameSize = 4096;
static const int kDefaultFrameOverlap = kDefaultFrameSize - kDefaultFrameSize / 3;

static const int kChromaFilterSize = 5;
static const double kChromaFilterCoefficients[] = { 0.25, 0.75, 1.0, 0.75, 0.25 };

static const Classifier kClassifiersTest1[16] = {
	Classifier(Filter(0, 0, 3, 15), Quantizer(2.10543, 2.45354, 2.69414)),
	Classifier(Filter(1, 0, 4, 14), Quantizer(-0.345922, 0.0463746, 0.446251)),
	Classifier(Filter(1, 4, 4, 11), Quantizer(-0.392132, 0.0291077, 0.443391)),
	Classifier(Filter(3, 0, 4, 14), Quantizer(-0.192851, 0.00583535, 0.204053)),
	Classifier(Filter(2, 8, 2, 4), Quantizer(-0.0771619, -0.00991999, 0.0575406)),
	Classifier(Filter(5, 6, 2, 15), Quantizer(-0.710437, -0.518954, -0.330402)),
	Classifier(Filter(1, 9, 2, 16), Quantizer(-0.353724, -0.0189719, 0.289768)),
	Classifier(Filter(3, 4, 2, 10), Quantizer(-0.128418, -0.0285697, 0.0591791)),
	Classifier(Filter(3, 9, 2, 16), Quantizer(-0.139052, -0.0228468, 0.0879723)),
	Classifier(Filter(2, 1, 3, 6), Quantizer(-0.133562, 0.00669205, 0.155012)),
	Classifier(Filter(3, 3, 6, 2), Quantizer(-0.0267, 0.00804829, 0.0459773)),
	Classifier(Filter(2, 8, 1, 10), Quantizer(-0.0972417, 0.0152227, 0.129003)),
	Classifier(Filter(3, 4, 4, 14), Quantizer(-0.141434, 0.00374515, 0.149935)),
	Classifier(Filter(5, 4, 2, 15), Quantizer(-0.64035, -0.466999, -0.285493)),
	Classifier(Filter(5, 9, 2, 3), Quantizer(-0.322792, -0.254258, -0.174278)),
	Classifier(Filter(2, 1, 8, 4), Quantizer(-0.0741375, -0.00590933, 0.0600357))
};

FingerprinterConfigurationTest1::FingerprinterConfigurationTest1()
{
	set_classifiers(kClassifiersTest1, 16);
	set_filter_coefficients(kChromaFilterCoefficients, kChromaFilterSize);
	set_interpolate(false);
	set_frame_size(kDefaultFrameSize);
	set_frame_overlap(kDefaultFrameOverlap);
}

static const Classifier kClassifiersTest2[16] = {
	Classifier(Filter(0, 4, 3, 15), Quantizer(1.98215, 2.35817, 2.63523)),
	Classifier(Filter(4, 4, 6, 15), Quantizer(-1.03809, -0.651211, -0.282167)),
	Classifier(Filter(1, 0, 4, 16), Quantizer(-0.298702, 0.119262, 0.558497)),
	Classifier(Filter(3, 8, 2, 12), Quantizer(-0.105439, 0.0153946, 0.135898)),
	Classifier(Filter(3, 4, 4, 8), Quantizer(-0.142891, 0.0258736, 0.200632)),
	Classifier(Filter(4, 0, 3, 5), Quantizer(-0.826319, -0.590612, -0.368214)),
	Classifier(Filter(1, 2, 2, 9), Quantizer(-0.557409, -0.233035, 0.0534525)),
	Classifier(Filter(2, 7, 3, 4), Quantizer(-0.0646826, 0.00620476, 0.0784847)),
	Classifier(Filter(2, 6, 2, 16), Quantizer(-0.192387, -0.029699, 0.215855)),
	Classifier(Filter(2, 1, 3, 2), Quantizer(-0.0397818, -0.00568076, 0.0292026)),
	Classifier(Filter(5, 10, 1, 15), Quantizer(-0.53823, -0.369934, -0.190235)),
	Classifier(Filter(3, 6, 2, 10), Quantizer(-0.124877, 0.0296483, 0.139239)),
	Classifier(Filter(2, 1, 1, 14), Quantizer(-0.101475, 0.0225617, 0.231971)),
	Classifier(Filter(3, 5, 6, 4), Quantizer(-0.0799915, -0.00729616, 0.063262)),
	Classifier(Filter(1, 9, 2, 12), Quantizer(-0.272556, 0.019424, 0.302559)),
	Classifier(Filter(3, 4, 2, 14), Quantizer(-0.164292, -0.0321188, 0.0846339)),
};

FingerprinterConfigurationTest2::FingerprinterConfigurationTest2()
{
	set_classifiers(kClassifiersTest2, 16);
	set_filter_coefficients(kChromaFilterCoefficients, kChromaFilterSize);
	set_interpolate(false);
	set_frame_size(kDefaultFrameSize);
	set_frame_overlap(kDefaultFrameOverlap);
}

static const Classifier kClassifiersTest3[16] = {
	Classifier(Filter(0, 4, 3, 15), Quantizer(1.98215, 2.35817, 2.63523)),
	Classifier(Filter(4, 4, 6, 15), Quantizer(-1.03809, -0.651211, -0.282167)),
	Classifier(Filter(1, 0, 4, 16), Quantizer(-0.298702, 0.119262, 0.558497)),
	Classifier(Filter(3, 8, 2, 12), Quantizer(-0.105439, 0.0153946, 0.135898)),
	Classifier(Filter(3, 4, 4, 8), Quantizer(-0.142891, 0.0258736, 0.200632)),
	Classifier(Filter(4, 0, 3, 5), Quantizer(-0.826319, -0.590612, -0.368214)),
	Classifier(Filter(1, 2, 2, 9), Quantizer(-0.557409, -0.233035, 0.0534525)),
	Classifier(Filter(2, 7, 3, 4), Quantizer(-0.0646826, 0.00620476, 0.0784847)),
	Classifier(Filter(2, 6, 2, 16), Quantizer(-0.192387, -0.029699, 0.215855)),
	Classifier(Filter(2, 1, 3, 2), Quantizer(-0.0397818, -0.00568076, 0.0292026)),
	Classifier(Filter(5, 10, 1, 15), Quantizer(-0.53823, -0.369934, -0.190235)),
	Classifier(Filter(3, 6, 2, 10), Quantizer(-0.124877, 0.0296483, 0.139239)),
	Classifier(Filter(2, 1, 1, 14), Quantizer(-0.101475, 0.0225617, 0.231971)),
	Classifier(Filter(3, 5, 6, 4), Quantizer(-0.0799915, -0.00729616, 0.063262)),
	Classifier(Filter(1, 9, 2, 12), Quantizer(-0.272556, 0.019424, 0.302559)),
	Classifier(Filter(3, 4, 2, 14), Quantizer(-0.164292, -0.0321188, 0.0846339)),
};

FingerprinterConfigurationTest3::FingerprinterConfigurationTest3()
{
	set_classifiers(kClassifiersTest3, 16);
	set_filter_coefficients(kChromaFilterCoefficients, kChromaFilterSize);
	set_interpolate(true);
	set_frame_size(kDefaultFrameSize);
}

FingerprinterConfigurationTest4::FingerprinterConfigurationTest4()
{
	set_remove_silence(true);
	set_silence_threshold(50);
}

FingerprinterConfigurationTest5::FingerprinterConfigurationTest5()
{
	set_frame_size(kDefaultFrameSize / 2);
	set_frame_overlap(kDefaultFrameSize / 2 - kDefaultFrameSize / 4);
}


#line 1 "src/fingerprinter_configuration.cpp [fin]"

#line 1 "src/fingerprint_matcher.cpp"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <algorithm>
#include <numeric>
#include <iostream>

#line 1 "src/fingerprint_matcher.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_FINGERPRINT_MATCHER_H_
#define CHROMAPRINT_FINGERPRINT_MATCHER_H_

#include <vector>
#include <memory>
#include <cstdint>
#include <cassert>

namespace chromaprint {

class FingerprinterConfiguration;

struct Segment
{
	size_t pos1;
	size_t pos2;
	size_t duration;
	double score;
	double left_score;
	double right_score;

	Segment(size_t pos1, size_t pos2, size_t duration, double score)
		: pos1(pos1), pos2(pos2), duration(duration), score(score), left_score(score), right_score(score) {}

	Segment(size_t pos1, size_t pos2, size_t duration, double score, double left_score, double right_score)
		: pos1(pos1), pos2(pos2), duration(duration), score(score), left_score(left_score), right_score(right_score) {}

	int public_score() const {
		//return std::max(0, int(100 - std::round(score * (100.0 / 14.0))));
		//return std::max(0, int(100 - std::round(score * (100.0 / 14.0))));
		return int(score * 100 + 0.5);
	}

	Segment merged(const Segment &other) {
		assert(pos1 + duration == other.pos1);
		assert(pos2 + duration == other.pos2);
		const auto new_duration = duration + other.duration;
		const auto new_score = (score * duration + other.score * other.duration) / new_duration;
		return Segment(pos1, pos2, new_duration, new_score, score, other.score);
	}

};

class FingerprintMatcher
{
public:
	FingerprintMatcher(FingerprinterConfiguration *config);

	// Anything above this is not considered a match.
	void set_match_threshold(double t) { m_match_threshold = t; }
	double match_threshold() const { return m_match_threshold; }
	static constexpr double kDefaultMatchThreshold = 10.0;

	bool Match(const std::vector<uint32_t> &fp1, const std::vector<uint32_t> &fp2);
	bool Match(const uint32_t fp1_data[], size_t fp1_size, const uint32_t fp2_data[], size_t fp2_size);

	double GetHashTime(size_t i) const;
	double GetHashDuration(size_t i) const;

	const std::vector<Segment> &segments() const { return m_segments; };

private:
	std::unique_ptr<FingerprinterConfiguration> m_config;
	std::vector<uint32_t> m_offsets;
	std::vector<uint32_t> m_histogram;
	std::vector<std::pair<uint32_t, uint32_t>> m_best_alignments;
	std::vector<Segment> m_segments;
	double m_match_threshold = kDefaultMatchThreshold;
};

}; // namespace chromaprint

#endif

#line 1 "src/fingerprint_matcher.h [fin]"

// [omitido por inclusión previa: src/fingerprinter_configuration.h]

// [omitido por inclusión previa: src/utils.h]

#line 1 "src/utils/gaussian_filter.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_UTILS_GAUSSIAN_FILTER_H_
#define CHROMAPRINT_UTILS_GAUSSIAN_FILTER_H_

#include <cmath>

// [omitido por inclusión previa: src/debug.h]

namespace chromaprint {

struct ReflectIterator {
	ReflectIterator(size_t size) : size(size) {}

	void MoveForward() {
		if (forward) {
			if (pos + 1 == size) {
				forward = false;
			} else {
				pos++;
			}
		} else {
			if (pos == 0) {
				forward = true;
			} else {
				pos--;
			}
		}
	}

	void MoveBack() {
		if (forward) {
			if (pos == 0) {
				forward = false;
			} else {
				pos--;
			}
		} else {
			if (pos + 1 == size) {
				forward = true;
			} else {
				pos++;
			}
		}
	}

	size_t SafeForwardDistance() {
		if (forward) {
			return size - pos - 1;
		}
		return 0;
	}

	size_t size;
	size_t pos { 0 };
	bool forward { true };
};

template <typename T>
void BoxFilter(T &input, T &output, size_t w) {
	const size_t size = input.size();
	output.resize(size);
	if (w == 0 || size == 0) {
		return;
	}

	const size_t wl = w / 2;
	const size_t wr = w - wl;

	auto out = output.begin();

	ReflectIterator it1(size), it2(size);
	for (size_t i = 0; i < wl; i++) {
		it1.MoveBack();
		it2.MoveBack();
	}

	typename T::value_type sum = 0;
	for (size_t i = 0; i < w; i++) {
		sum += input[it2.pos];
		it2.MoveForward();
	}

	if (size > w) {
		for (size_t i = 0; i < wl; i++) {
			*out++ = sum / w;
			sum += input[it2.pos] - input[it1.pos];
			it1.MoveForward();
			it2.MoveForward();
		}
		for (size_t i = 0; i < size - w - 1; i++) {
			*out++ = sum / w;
			sum += input[it2.pos++] - input[it1.pos++];
		}
		for (size_t i = 0; i < wr + 1; i++) {
			*out++ = sum / w;
			sum += input[it2.pos] - input[it1.pos];
			it1.MoveForward();
			it2.MoveForward();
		}
	} else {
		for (size_t i = 0; i < size; i++) {
			*out++ = sum / w;
			sum += input[it2.pos] - input[it1.pos];
			it1.MoveForward();
			it2.MoveForward();
		}
	}
};

template <typename T>
void GaussianFilter(T &input, T& output, double sigma, int n) {
	const int w = floor(sqrt(12 * sigma * sigma / n + 1));
	const int wl = w - (w % 2 == 0 ? 1 : 0);
	const int wu = wl + 2;

	const int m = round((12 * sigma * sigma - n * wl * wl - 4 * n * wl - 3 * n) / (-4 * wl - 4));

	T* data1 = &input;
	T* data2 = &output;

	int i = 0;
	for (; i < m; i++) {
		BoxFilter(*data1, *data2, wl);
		std::swap(data1, data2);
	}
	for (; i < n; i++) {
		BoxFilter(*data1, *data2, wu);
		std::swap(data1, data2);
	}

	if (data1 != &output) {
		output.assign(input.begin(), input.end());
	}
}

};

#endif

#line 1 "src/utils/gaussian_filter.h [fin]"

#line 1 "src/utils/gradient.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_UTILS_GRADIENT_H_
#define CHROMAPRINT_UTILS_GRADIENT_H_

#include <algorithm>

namespace chromaprint {

template <typename InputIt, typename OutputIt>
void Gradient(InputIt begin, InputIt end, OutputIt output) {
	typedef typename std::iterator_traits<InputIt>::value_type ValueType;
	InputIt ptr = begin;
	if (ptr != end) {
		ValueType f0 = *ptr++;
		if (ptr == end) {
			*output = 0;
			return;
		}
		ValueType f1 = *ptr++;
		*output++ = f1 - f0;
		if (ptr == end) {
			*output = f1 - f0;
			return;
		}
		ValueType f2 = *ptr++;
		while (true) {
			*output++ = (f2 - f0) / 2;
			if (ptr == end) {
				*output = f2 - f1;
				return;
			}
			f0 = f1;
			f1 = f2;
			f2 = *ptr++;
		};
	}
}

};

#endif

#line 1 "src/utils/gradient.h [fin]"

// [omitido por inclusión previa: src/debug.h]

namespace chromaprint {

/* fingerprint matcher settings */
#define ACOUSTID_MAX_BIT_ERROR 2
#define ACOUSTID_MAX_ALIGN_OFFSET 120
#define ACOUSTID_QUERY_START 80
#define ACOUSTID_QUERY_LENGTH 120
#define ACOUSTID_QUERY_BITS 28
#define ACOUSTID_QUERY_MASK (((1<<ACOUSTID_QUERY_BITS)-1)<<(32-ACOUSTID_QUERY_BITS))
#define ACOUSTID_QUERY_STRIP(x) ((x) & ACOUSTID_QUERY_MASK)

#define ALIGN_BITS 12
#define ALIGN_MASK ((1 << ALIGN_BITS) - 1)
#define ALIGN_STRIP(x) ((uint32_t)(x) >> (32 - ALIGN_BITS))

#define UNIQ_BITS 16
#define UNIQ_MASK ((1 << MATCH_BITS) - 1)
#define UNIQ_STRIP(x) ((uint32_t)(x) >> (32 - MATCH_BITS))

FingerprintMatcher::FingerprintMatcher(FingerprinterConfiguration *config)
	: m_config(config)
{
}

double FingerprintMatcher::GetHashTime(size_t i) const {
	return m_config->item_duration_in_seconds() * i;
}

double FingerprintMatcher::GetHashDuration(size_t i) const {
	return GetHashTime(i) + m_config->delay_in_seconds();
}

bool FingerprintMatcher::Match(const std::vector<uint32_t> &fp1, const std::vector<uint32_t> &fp2)
{
	return Match(fp1.data(), fp1.size(), fp2.data(), fp2.size());
}

bool FingerprintMatcher::Match(const uint32_t fp1_data[], size_t fp1_size, const uint32_t fp2_data[], size_t fp2_size)
{
	const uint32_t hash_shift = 32 - ALIGN_BITS;
	const uint32_t hash_mask = ((1u << ALIGN_BITS) - 1) << hash_shift;
	const uint32_t offset_mask = (1u << (32 - ALIGN_BITS - 1)) - 1;
	const uint32_t source_mask = 1u << (32 - ALIGN_BITS - 1);

	if (fp1_size + 1 >= offset_mask) {
		DEBUG("chromaprint::FingerprintMatcher::Match() -- Fingerprint 1 too long.");
		return false;
	}
	if (fp2_size + 1 >= offset_mask) {
		DEBUG("chromaprint::FingerprintMatcher::Match() -- Fingerprint 2 too long.");
		return false;
	}

	m_offsets.clear();
	m_offsets.reserve(fp1_size + fp2_size);
	for (size_t i = 0; i < fp1_size; i++) {
		m_offsets.push_back((ALIGN_STRIP(fp1_data[i]) << hash_shift) | uint32_t(i & offset_mask));
	}
	for (size_t i = 0; i < fp2_size; i++) {
		m_offsets.push_back((ALIGN_STRIP(fp2_data[i]) << hash_shift) | uint32_t(i & offset_mask) | source_mask);
	}
	std::sort(m_offsets.begin(), m_offsets.end());

	m_histogram.assign(fp1_size + fp2_size, 0);
	for (auto it = m_offsets.cbegin(); it != m_offsets.cend(); ++it) {
		const uint32_t hash = (*it) & hash_mask;
		const uint32_t offset1 = (*it) & offset_mask;
		const uint32_t source1 = (*it) & source_mask;
		if (source1 != 0) {
			// if we got hash from fp2, it means there is no hash from fp1,
			// because if there was, it would be first
			continue;
		}
		auto it2 = it;
		while (++it2 != m_offsets.end()) {
			const uint32_t hash2 = (*it2) & hash_mask;
			if (hash != hash2) {
				break;
			}
			const uint32_t offset2 = (*it2) & offset_mask;
			const uint32_t source2 = (*it2) & source_mask;
			if (source2 != 0) {
				const size_t offset_diff = offset1 + fp2_size - offset2;
				m_histogram[offset_diff] += 1;
			}
		}
	}

	m_best_alignments.clear();
	const auto histogram_size = m_histogram.size();
	for (size_t i = 0; i < histogram_size; i++) {
		const uint32_t count = m_histogram[i];
		if (m_histogram[i] > 1) {
			const bool is_peak_left = (i > 0) ? m_histogram[i - 1] <= count : true;
			const bool is_peak_right = (i < histogram_size - 1) ? m_histogram[i + 1] <= count : true;
			if (is_peak_left && is_peak_right) {
				m_best_alignments.push_back(std::make_pair(count, i));
			}
		}
	}
	std::sort(m_best_alignments.rbegin(), m_best_alignments.rend());

	m_segments.clear();

	for (const auto &item : m_best_alignments) {
		const int offset_diff = int(item.second - fp2_size);

		const size_t offset1 = offset_diff > 0 ? offset_diff : 0;
		const size_t offset2 = offset_diff < 0 ? -offset_diff : 0;

		auto it1 = fp1_data + offset1;
		auto it2 = fp2_data + offset2;

		const auto size = std::min(fp1_size - offset1, fp2_size - offset2);
		std::vector<float> bit_counts(size);
		for (size_t i = 0; i < size; i++) {
			bit_counts[i] = HammingDistance(*it1++, *it2++) + (float)rand() * (0.001f / (float)RAND_MAX);
		}

		std::vector<float> orig_bit_counts = bit_counts;
		std::vector<float> smoothed_bit_counts;
		GaussianFilter(bit_counts, smoothed_bit_counts, 8.0, 3);

		std::vector<float> gradient(size);
		Gradient(smoothed_bit_counts.begin(), smoothed_bit_counts.end(), gradient.begin());

		for (size_t i = 0; i < size; i++) {
			gradient[i] = std::abs(gradient[i]);
		}

		std::vector<size_t> gradient_peaks;
		for (size_t i = 0; i < size; i++) {
			const auto gi = gradient[i];
			if (i > 0 && i < size - 1 && gi > 0.15 && gi >= gradient[i - 1] && gi >= gradient[i + 1]) {
				if (gradient_peaks.empty() || gradient_peaks.back() + 1 < i) {
					gradient_peaks.push_back(i);
				}
			}
		}
		gradient_peaks.push_back(size);

		size_t begin = 0;
		for (size_t end : gradient_peaks) {
			const auto duration = end - begin;
			const auto score = std::accumulate(orig_bit_counts.begin() + begin, orig_bit_counts.begin() + end, 0.0) / duration;
			if (score < m_match_threshold) {
				bool added = false;
				if (!m_segments.empty()) {
					auto &s1 = m_segments.back();
					if (std::abs(s1.score - score) < 0.7) {
						s1 = s1.merged(Segment(offset1 + begin, offset2 + begin, duration, score));
						added = true;
					}
				}
				if (!added) {
					m_segments.emplace_back(offset1 + begin, offset2 + begin, duration, score);
				}
			}
			begin = end;
		}

		// TODO try to merge segments from multiple offsets

		break;
	}
	
	return true;
}

}; // namespace chromaprint

#line 1 "src/fingerprint_matcher.cpp [fin]"

#line 1 "src/utils/base64.cpp"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.


#line 1 "src/utils/base64.h"
// Copyright (C) 2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#ifndef CHROMAPRINT_BASE64_H_
#define CHROMAPRINT_BASE64_H_

#include <string>

namespace chromaprint {

static const char kBase64Chars[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
static const char kBase64CharsReversed[256] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 62, 0, 0,
	52,	53, 54, 55, 56, 57, 58, 59,
	60, 61, 0, 0, 0, 0, 0, 0,

	0, 0, 1, 2, 3, 4, 5, 6,
	7, 8, 9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19,	20, 21, 22,
	23, 24, 25, 0, 0, 0, 0, 63,
	0, 26, 27, 28, 29, 30, 31, 32,
	33,	34, 35, 36, 37,	38, 39, 40,
	41,	42, 43, 44, 45, 46, 47, 48,
	49,	50, 51, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
};

inline size_t GetBase64EncodedSize(size_t size)
{
	return (size * 4 + 2) / 3;
}

inline size_t GetBase64DecodedSize(size_t size)
{
	return size * 3 / 4;
}

template <typename InputIt, typename OutputIt>
inline OutputIt Base64Encode(InputIt first, InputIt last, OutputIt dest, bool terminate = false)
{
	auto src = first;
	auto size = std::distance(first, last);
	while (size >= 3) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		const unsigned char s2 = *src++;
		*dest++ = kBase64Chars[(s0 >> 2) & 63];
		*dest++ = kBase64Chars[((s0 << 4) | (s1 >> 4)) & 63];
		*dest++ = kBase64Chars[((s1 << 2) | (s2 >> 6)) & 63];
		*dest++ = kBase64Chars[s2 & 63];
		size -= 3;
	}
	if (size == 2) {
		const unsigned char s0 = *src++;
		const unsigned char s1 = *src++;
		*dest++ = kBase64Chars[(s0 >> 2) & 63];
		*dest++ = kBase64Chars[((s0 << 4) | (s1 >> 4)) & 63];
		*dest++ = kBase64Chars[(s1 << 2) & 63];
	} else if (size == 1) {
		const unsigned char s0 = *src++;
		*dest++ = kBase64Chars[(s0 >> 2) & 63];
		*dest++ = kBase64Chars[(s0 << 4) & 63];
	}
	if (terminate) {
		*dest++ = '\0';
	}
	return dest;
}

template <typename InputIt, typename OutputIt>
inline OutputIt Base64Decode(InputIt first, InputIt last, OutputIt dest)
{
	auto src = first;
	auto size = std::distance(first, last);
	while (size >= 4) {
		const unsigned char b0 = kBase64CharsReversed[*src++ & 255];
		const unsigned char b1 = kBase64CharsReversed[*src++ & 255];
		const unsigned char b2 = kBase64CharsReversed[*src++ & 255];
		const unsigned char b3 = kBase64CharsReversed[*src++ & 255];
		*dest++ = (b0 << 2) | (b1 >> 4);
		*dest++ = ((b1 << 4) & 255) | (b2 >> 2);
		*dest++ = ((b2 << 6) & 255) | b3;
		size -= 4;
	}
	if (size == 3) {
		const unsigned char b0 = kBase64CharsReversed[*src++ & 255];
		const unsigned char b1 = kBase64CharsReversed[*src++ & 255];
		const unsigned char b2 = kBase64CharsReversed[*src++ & 255];
		*dest++ = (b0 << 2) | (b1 >> 4);
		*dest++ = ((b1 << 4) & 255) | (b2 >> 2);
	} else if (size == 2) {
		const unsigned char b0 = kBase64CharsReversed[*src++ & 255];
		const unsigned char b1 = kBase64CharsReversed[*src++ & 255];
		*dest++ = (b0 << 2) | (b1 >> 4);
	}
	return dest;
}

void Base64Encode(const std::string &src, std::string &dest);
std::string Base64Encode(const std::string &src);

void Base64Decode(const std::string &encoded, std::string &dest);
std::string Base64Decode(const std::string &encoded);

}; // namespace chromaprint

#endif


#line 1 "src/utils/base64.h [fin]"
#include <cassert>

namespace chromaprint {

void Base64Encode(const std::string &src, std::string &dest)
{
	dest.resize(GetBase64EncodedSize(src.size()));
	const auto end = Base64Encode(src.cbegin(), src.cend(), dest.begin());
	assert(dest.end() == end);
}

std::string Base64Encode(const std::string &src)
{
	std::string dest;
	Base64Encode(src, dest);
	return dest;
}

void Base64Decode(const std::string &src, std::string &dest)
{
	dest.resize(GetBase64DecodedSize(src.size()));
	const auto end = Base64Decode(src.cbegin(), src.cend(), dest.begin());
	assert(dest.end() == end);
}

std::string Base64Decode(const std::string &src)
{
	std::string dest;
	Base64Decode(src, dest);
	return dest;
}

}; // namespace chromaprint

#line 1 "src/utils/base64.cpp [fin]"

#line 1 "src/chromaprint.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.

#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <cstring>

// [omitido por inclusión previa: src/chromaprint.h]

// [omitido por inclusión previa: src/fingerprinter.h]

// [omitido por inclusión previa: src/fingerprint_compressor.h]

// [omitido por inclusión previa: src/fingerprint_decompressor.h]

// [omitido por inclusión previa: src/fingerprint_matcher.h]

// [omitido por inclusión previa: src/fingerprinter_configuration.h]

// [omitido por inclusión previa: src/utils/base64.h]

// [omitido por inclusión previa: src/simhash.h]

// [omitido por inclusión previa: src/debug.h]

using namespace chromaprint;

struct ChromaprintContextPrivate {
	ChromaprintContextPrivate(int algorithm)
		: algorithm(algorithm),
		  fingerprinter(CreateFingerprinterConfiguration(algorithm)) {}
	int algorithm;
	Fingerprinter fingerprinter;
	FingerprintCompressor compressor;
	std::string tmp_fingerprint;
};

struct ChromaprintMatcherContextPrivate {
	int algorithm = -1;
	std::unique_ptr<FingerprintMatcher> matcher;
	std::vector<uint32_t> fp[2];
	FingerprintDecompressor decompressor;
};

extern "C" {

#define FAIL_IF(x, msg) if (x) { DEBUG(msg); return 0; }

#define STR(x) #x
#define VERSION_STR(major, minor, patch) \
	STR(major) "." STR(minor) "." STR(patch)

static const char *version_str = VERSION_STR(
	CHROMAPRINT_VERSION_MAJOR,
	CHROMAPRINT_VERSION_MINOR,
	CHROMAPRINT_VERSION_PATCH);

const char *chromaprint_get_version(void)
{
	return version_str;
}

ChromaprintContext *chromaprint_new(int algorithm)
{
	return new ChromaprintContextPrivate(algorithm);
}

void chromaprint_free(ChromaprintContext *ctx)
{
	if (ctx) {
		delete ctx;
	}
}

int chromaprint_get_algorithm(ChromaprintContext *ctx)
{
	FAIL_IF(!ctx, "context can't be NULL");
	return ctx->algorithm;
}

int chromaprint_set_option(ChromaprintContext *ctx, const char *name, int value)
{
	FAIL_IF(!ctx, "context can't be NULL");
	return ctx->fingerprinter.SetOption(name, value) ? 1 : 0;
}

int chromaprint_get_num_channels(ChromaprintContext *ctx)
{
	return 1;
}

int chromaprint_get_sample_rate(ChromaprintContext *ctx)
{
	return ctx ? ctx->fingerprinter.config()->sample_rate() : 0;
}

int chromaprint_get_item_duration(ChromaprintContext *ctx)
{
	return ctx ? ctx->fingerprinter.config()->item_duration() : 0;
}

int chromaprint_get_item_duration_ms(ChromaprintContext *ctx)
{
	return ctx ? ctx->fingerprinter.config()->item_duration_in_seconds() * 1000 : 0;
}

int chromaprint_get_delay(ChromaprintContext *ctx)
{
	return ctx ? ctx->fingerprinter.config()->delay() : 0;
}

int chromaprint_get_delay_ms(ChromaprintContext *ctx)
{
	return ctx ? ctx->fingerprinter.config()->delay_in_seconds() * 1000 : 0;
}

int chromaprint_start(ChromaprintContext *ctx, int sample_rate, int num_channels)
{
	FAIL_IF(!ctx, "context can't be NULL");
	return ctx->fingerprinter.Start(sample_rate, num_channels) ? 1 : 0;
}

int chromaprint_feed(ChromaprintContext *ctx, const int16_t *data, int length)
{
	FAIL_IF(!ctx, "context can't be NULL");
	ctx->fingerprinter.Consume(data, length);
	return 1;
}

int chromaprint_finish(ChromaprintContext *ctx)
{
	FAIL_IF(!ctx, "context can't be NULL");
	ctx->fingerprinter.Finish();
	return 1;
}

int chromaprint_get_fingerprint(ChromaprintContext *ctx, char **data)
{
	FAIL_IF(!ctx, "context can't be NULL");
	ctx->compressor.Compress(ctx->fingerprinter.GetFingerprint(), ctx->algorithm, ctx->tmp_fingerprint);
	*data = (char *) malloc(GetBase64EncodedSize(ctx->tmp_fingerprint.size()) + 1);
	FAIL_IF(!*data, "can't allocate memory for the result");
	Base64Encode(ctx->tmp_fingerprint.begin(), ctx->tmp_fingerprint.end(), *data, true);
	return 1;
}

int chromaprint_get_raw_fingerprint(ChromaprintContext *ctx, uint32_t **data, int *size)
{
	FAIL_IF(!ctx, "context can't be NULL");
	const auto fingerprint = ctx->fingerprinter.GetFingerprint();
	*data = (uint32_t *) malloc(sizeof(uint32_t) * fingerprint.size());
	FAIL_IF(!*data, "can't allocate memory for the result");
	*size = int(fingerprint.size());
	std::copy(fingerprint.begin(), fingerprint.end(), *data);
	return 1;
}

int chromaprint_get_raw_fingerprint_size(ChromaprintContext *ctx, int *size)
{
	FAIL_IF(!ctx, "context can't be NULL");
	const auto fingerprint = ctx->fingerprinter.GetFingerprint();
	*size = int(fingerprint.size());
	return 1;
}

int chromaprint_get_fingerprint_hash(ChromaprintContext *ctx, uint32_t *hash)
{
	FAIL_IF(!ctx, "context can't be NULL");
	*hash = SimHash(ctx->fingerprinter.GetFingerprint());
	return 1;
}

int chromaprint_clear_fingerprint(ChromaprintContext *ctx)
{
	FAIL_IF(!ctx, "context can't be NULL");
	ctx->fingerprinter.ClearFingerprint();
	return 1;
}

int chromaprint_encode_fingerprint(const uint32_t *fp, int size, int algorithm, char **encoded_fp, int *encoded_size, int base64)
{
	// The encoded header stores the size in 24 bits.
	if ((fp == NULL && size != 0) || size < 0 || size > 0xFFFFFF || encoded_fp == NULL || encoded_size == NULL) {
		return 0;
	}
	std::vector<uint32_t> uncompressed(fp, fp + size);
	std::string encoded = CompressFingerprint(uncompressed, algorithm);
	if (base64) {
		encoded = Base64Encode(encoded);
	}
	*encoded_fp = (char *) malloc(encoded.size() + 1);
	*encoded_size = int(encoded.size());
	std::copy(encoded.data(), encoded.data() + encoded.size() + 1, *encoded_fp);
	return 1;
}

int chromaprint_decode_fingerprint(const char *encoded_fp, int encoded_size, uint32_t **fp, int *size, int *algorithm, int base64)
{
	if (fp == NULL || size == NULL) {
		return 0;
	}
	std::vector<uint32_t> uncompressed;
	int algo;
	bool ok = false;
	if (encoded_size >= 0 && (encoded_fp != NULL || encoded_size == 0)) {
		std::string encoded(encoded_fp, encoded_size);
		if (base64) {
			encoded = Base64Decode(encoded);
		}
		ok = DecompressFingerprint(encoded, uncompressed, algo);
	}
	if (!ok) {
		*fp = nullptr;
		*size = 0;
		if (algorithm) {
			*algorithm = 0;
		}
		return 0;
	}
	*fp = (uint32_t *) malloc(sizeof(uint32_t) * uncompressed.size());
	*size = int(uncompressed.size());
	if (algorithm) {
		*algorithm = algo;
	}
	std::copy(uncompressed.begin(), uncompressed.end(), *fp);
	return 1;
}

int chromaprint_decode_fingerprint_header(const char *encoded_fp, int encoded_size, int *size, int *algorithm, int base64)
{
	size_t size_out;
	int algorithm_out;
	bool ok = false;
	if (encoded_size >= 0 && (encoded_fp != NULL || encoded_size == 0)) {
		std::string encoded(encoded_fp, std::min(6, encoded_size));
		if (base64) {
			encoded = Base64Decode(encoded);
		}
		ok = DecompressFingerprintHeader(encoded, size_out, algorithm_out);
	}
	if (!ok) {
		if (size) {
			*size = 0;
		}
		if (algorithm) {
			*algorithm = 0;
		}
		return 0;
	}
	if (size) {
		*size = int(size_out);
	}
	if (algorithm) {
		*algorithm = algorithm_out;
	}
	return 1;
}

int chromaprint_hash_fingerprint(const uint32_t *fp, int size, uint32_t *hash)
{
	if (fp == NULL || size < 0 || hash == NULL) {
		return 0;
	}
	*hash = SimHash(fp, size);
	return 1;
}

void chromaprint_dealloc(void *ptr)
{
	free(ptr);
}

}; // extern "C"

#line 1 "src/chromaprint.cpp [fin]"

#undef DEBUG

#line 1 "src/fft_lib_kissfft.cpp"
// Copyright (C) 2010-2016  Lukas Lalinsky
// Distributed under the MIT license, see the LICENSE file for details.


// [omitido por inclusión previa: src/fft_lib_kissfft.h]

namespace chromaprint {

FFTLib::FFTLib(size_t frame_size) : m_frame_size(frame_size) {
	m_window = (kiss_fft_scalar *) KISS_FFT_MALLOC(sizeof(kiss_fft_scalar) * frame_size);
	m_input = (kiss_fft_scalar *) KISS_FFT_MALLOC(sizeof(kiss_fft_scalar) * frame_size);
	m_output = (kiss_fft_cpx *) KISS_FFT_MALLOC(sizeof(kiss_fft_cpx) * frame_size);
	PrepareHammingWindow(m_window, m_window + frame_size, 1.0 / INT16_MAX);
	m_cfg = kiss_fftr_alloc(frame_size, 0, NULL, NULL);
}

FFTLib::~FFTLib() {
	kiss_fftr_free(m_cfg);
	KISS_FFT_FREE(m_output);
	KISS_FFT_FREE(m_input);
	KISS_FFT_FREE(m_window);
}

void FFTLib::Load(const int16_t *b1, const int16_t *e1, const int16_t *b2, const int16_t *e2) {
	auto window = m_window;
	auto output = m_input;
	ApplyWindow(b1, e1, window, output);
	ApplyWindow(b2, e2, window, output);
}

void FFTLib::Compute(FFTFrame &frame) {
	kiss_fftr(m_cfg, m_input, m_output);
	auto input = m_output;
	auto output = frame.data();
	for (size_t i = 0; i <= m_frame_size / 2; ++i, ++input, ++output) {
		*output = input->r * input->r + input->i * input->i;
	}
}

}; // namespace chromaprint

#line 1 "src/fft_lib_kissfft.cpp [fin]"

#undef DEBUG

#line 1 "src/3rdparty/kissfft/kiss_fft.c"
/*
 *  Copyright (c) 2003-2010, Mark Borgerding. All rights reserved.
 *  This file is part of KISS FFT - https://github.com/mborgerding/kissfft
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *  See COPYING file for more information.
 */



#line 1 "src/3rdparty/kissfft/_kiss_fft_guts.h"
/*
 *  Copyright (c) 2003-2010, Mark Borgerding. All rights reserved.
 *  This file is part of KISS FFT - https://github.com/mborgerding/kissfft
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *  See COPYING file for more information.
 */

/* kiss_fft.h
   defines kiss_fft_scalar as either short or a float type
   and defines
   typedef struct { kiss_fft_scalar r; kiss_fft_scalar i; }kiss_fft_cpx; */

#ifndef _kiss_fft_guts_h
#define _kiss_fft_guts_h


// [omitido por inclusión previa: src/3rdparty/kissfft/kiss_fft.h]

#line 1 "src/3rdparty/kissfft/kiss_fft_log.h"
/*
 *  Copyright (c) 2003-2010, Mark Borgerding. All rights reserved.
 *  This file is part of KISS FFT - https://github.com/mborgerding/kissfft
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *  See COPYING file for more information.
 */

#ifndef kiss_fft_log_h
#define kiss_fft_log_h

#define KISSFFT_LOG_ERROR 1
#define KISSFFT_LOG_WARNING 2
#define KISSFFT_LOG_INFO 3
#define KISSFFT_LOG_DEBUG 4

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#if defined(NDEBUG)
# define KISS_FFT_LOG_MSG(severity, ...) ((void)0)
#else
# define KISS_FFT_LOG_MSG(severity, ...) \
    fprintf(stderr, "[" #severity "] " __FILE__ ":" TOSTRING(__LINE__) " "); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n")
#endif

#define KISS_FFT_ERROR(...) KISS_FFT_LOG_MSG(KISSFFT_LOG_ERROR, __VA_ARGS__)
#define KISS_FFT_WARNING(...) KISS_FFT_LOG_MSG(KISSFFT_LOG_WARNING, __VA_ARGS__)
#define KISS_FFT_INFO(...) KISS_FFT_LOG_MSG(KISSFFT_LOG_INFO, __VA_ARGS__)
#define KISS_FFT_DEBUG(...) KISS_FFT_LOG_MSG(KISSFFT_LOG_DEBUG, __VA_ARGS__)



#endif /* kiss_fft_log_h */

#line 1 "src/3rdparty/kissfft/kiss_fft_log.h [fin]"
#include <limits.h>

#define MAXFACTORS 32
/* e.g. an fft of length 128 has 4 factors
 as far as kissfft is concerned
 4*4*4*2
 */

struct kiss_fft_state{
    int nfft;
    int inverse;
    int factors[2*MAXFACTORS];
    kiss_fft_cpx twiddles[1];
};

/*
  Explanation of macros dealing with complex math:

   C_MUL(m,a,b)         : m = a*b
   C_FIXDIV( c , div )  : if a fixed point impl., c /= div. noop otherwise
   C_SUB( res, a,b)     : res = a - b
   C_SUBFROM( res , a)  : res -= a
   C_ADDTO( res , a)    : res += a
 * */
#ifdef FIXED_POINT
#include <stdint.h>
#if (FIXED_POINT==32)
# define FRACBITS 31
# define SAMPPROD int64_t
#define SAMP_MAX INT32_MAX
#define SAMP_MIN INT32_MIN
#else
# define FRACBITS 15
# define SAMPPROD int32_t
#define SAMP_MAX INT16_MAX
#define SAMP_MIN INT16_MIN
#endif

#if defined(CHECK_OVERFLOW)
#  define CHECK_OVERFLOW_OP(a,op,b)  \
    if ( (SAMPPROD)(a) op (SAMPPROD)(b) > SAMP_MAX || (SAMPPROD)(a) op (SAMPPROD)(b) < SAMP_MIN ) { \
        KISS_FFT_WARNING("overflow (%d " #op" %d) = %ld", (a),(b),(SAMPPROD)(a) op (SAMPPROD)(b)); }
#endif


#   define smul(a,b) ( (SAMPPROD)(a)*(b) )
#   define sround( x )  (kiss_fft_scalar)( ( (x) + (1<<(FRACBITS-1)) ) >> FRACBITS )

#   define S_MUL(a,b) sround( smul(a,b) )

#   define C_MUL(m,a,b) \
      do{ (m).r = sround( smul((a).r,(b).r) - smul((a).i,(b).i) ); \
          (m).i = sround( smul((a).r,(b).i) + smul((a).i,(b).r) ); }while(0)

#   define DIVSCALAR(x,k) \
    (x) = sround( smul(  x, SAMP_MAX/k ) )

#   define C_FIXDIV(c,div) \
    do {    DIVSCALAR( (c).r , div);  \
        DIVSCALAR( (c).i  , div); }while (0)

#   define C_MULBYSCALAR( c, s ) \
    do{ (c).r =  sround( smul( (c).r , s ) ) ;\
        (c).i =  sround( smul( (c).i , s ) ) ; }while(0)

#else  /* not FIXED_POINT*/

#   define S_MUL(a,b) ( (a)*(b) )
#define C_MUL(m,a,b) \
    do{ (m).r = (a).r*(b).r - (a).i*(b).i;\
        (m).i = (a).r*(b).i + (a).i*(b).r; }while(0)
#   define C_FIXDIV(c,div) /* NOOP */
#   define C_MULBYSCALAR( c, s ) \
    do{ (c).r *= (s);\
        (c).i *= (s); }while(0)
#endif

#ifndef CHECK_OVERFLOW_OP
#  define CHECK_OVERFLOW_OP(a,op,b) /* noop */
#endif

#define  C_ADD( res, a,b)\
    do { \
        CHECK_OVERFLOW_OP((a).r,+,(b).r)\
        CHECK_OVERFLOW_OP((a).i,+,(b).i)\
        (res).r=(a).r+(b).r;  (res).i=(a).i+(b).i; \
    }while(0)
#define  C_SUB( res, a,b)\
    do { \
        CHECK_OVERFLOW_OP((a).r,-,(b).r)\
        CHECK_OVERFLOW_OP((a).i,-,(b).i)\
        (res).r=(a).r-(b).r;  (res).i=(a).i-(b).i; \
    }while(0)
#define C_ADDTO( res , a)\
    do { \
        CHECK_OVERFLOW_OP((res).r,+,(a).r)\
        CHECK_OVERFLOW_OP((res).i,+,(a).i)\
        (res).r += (a).r;  (res).i += (a).i;\
    }while(0)

#define C_SUBFROM( res , a)\
    do {\
        CHECK_OVERFLOW_OP((res).r,-,(a).r)\
        CHECK_OVERFLOW_OP((res).i,-,(a).i)\
        (res).r -= (a).r;  (res).i -= (a).i; \
    }while(0)


#ifdef FIXED_POINT
#  define KISS_FFT_COS(phase)  floor(.5+SAMP_MAX * cos (phase))
#  define KISS_FFT_SIN(phase)  floor(.5+SAMP_MAX * sin (phase))
#  define HALF_OF(x) ((x)>>1)
#elif defined(USE_SIMD)
#  define KISS_FFT_COS(phase) _mm_set1_ps( cos(phase) )
#  define KISS_FFT_SIN(phase) _mm_set1_ps( sin(phase) )
#  define HALF_OF(x) ((x)*_mm_set1_ps(.5))
#else
#  define KISS_FFT_COS(phase) (kiss_fft_scalar) cos(phase)
#  define KISS_FFT_SIN(phase) (kiss_fft_scalar) sin(phase)
#  define HALF_OF(x) ((x)*((kiss_fft_scalar).5))
#endif

#define  kf_cexp(x,phase) \
    do{ \
        (x)->r = KISS_FFT_COS(phase);\
        (x)->i = KISS_FFT_SIN(phase);\
    }while(0)


/* a debugging function */
#define pcpx(c)\
    KISS_FFT_DEBUG("%g + %gi\n",(double)((c)->r),(double)((c)->i))


#ifdef KISS_FFT_USE_ALLOCA
// define this to allow use of alloca instead of malloc for temporary buffers
// Temporary buffers are used in two case:
// 1. FFT sizes that have "bad" factors. i.e. not 2,3 and 5
// 2. "in-place" FFTs.  Notice the quotes, since kissfft does not really do an in-place transform.
#include <alloca.h>
#define  KISS_FFT_TMP_ALLOC(nbytes) alloca(nbytes)
#define  KISS_FFT_TMP_FREE(ptr)
#else
#define  KISS_FFT_TMP_ALLOC(nbytes) KISS_FFT_MALLOC(nbytes)
#define  KISS_FFT_TMP_FREE(ptr) KISS_FFT_FREE(ptr)
#endif

#endif /* _kiss_fft_guts_h */


#line 1 "src/3rdparty/kissfft/_kiss_fft_guts.h [fin]"
/* The guts header contains all the multiplication and addition macros that are defined for
 fixed or floating point complex numbers.  It also delares the kf_ internal functions.
 */

static void kf_bfly2(
        kiss_fft_cpx * Fout,
        const size_t fstride,
        const kiss_fft_cfg st,
        int m
        )
{
    kiss_fft_cpx * Fout2;
    kiss_fft_cpx * tw1 = st->twiddles;
    kiss_fft_cpx t;
    Fout2 = Fout + m;
    do{
        C_FIXDIV(*Fout,2); C_FIXDIV(*Fout2,2);

        C_MUL (t,  *Fout2 , *tw1);
        tw1 += fstride;
        C_SUB( *Fout2 ,  *Fout , t );
        C_ADDTO( *Fout ,  t );
        ++Fout2;
        ++Fout;
    }while (--m);
}

static void kf_bfly4(
        kiss_fft_cpx * Fout,
        const size_t fstride,
        const kiss_fft_cfg st,
        const size_t m
        )
{
    kiss_fft_cpx *tw1,*tw2,*tw3;
    kiss_fft_cpx scratch[6];
    size_t k=m;
    const size_t m2=2*m;
    const size_t m3=3*m;


    tw3 = tw2 = tw1 = st->twiddles;

    do {
        C_FIXDIV(*Fout,4); C_FIXDIV(Fout[m],4); C_FIXDIV(Fout[m2],4); C_FIXDIV(Fout[m3],4);

        C_MUL(scratch[0],Fout[m] , *tw1 );
        C_MUL(scratch[1],Fout[m2] , *tw2 );
        C_MUL(scratch[2],Fout[m3] , *tw3 );

        C_SUB( scratch[5] , *Fout, scratch[1] );
        C_ADDTO(*Fout, scratch[1]);
        C_ADD( scratch[3] , scratch[0] , scratch[2] );
        C_SUB( scratch[4] , scratch[0] , scratch[2] );
        C_SUB( Fout[m2], *Fout, scratch[3] );
        tw1 += fstride;
        tw2 += fstride*2;
        tw3 += fstride*3;
        C_ADDTO( *Fout , scratch[3] );

        if(st->inverse) {
            Fout[m].r = scratch[5].r - scratch[4].i;
            Fout[m].i = scratch[5].i + scratch[4].r;
            Fout[m3].r = scratch[5].r + scratch[4].i;
            Fout[m3].i = scratch[5].i - scratch[4].r;
        }else{
            Fout[m].r = scratch[5].r + scratch[4].i;
            Fout[m].i = scratch[5].i - scratch[4].r;
            Fout[m3].r = scratch[5].r - scratch[4].i;
            Fout[m3].i = scratch[5].i + scratch[4].r;
        }
        ++Fout;
    }while(--k);
}

static void kf_bfly3(
         kiss_fft_cpx * Fout,
         const size_t fstride,
         const kiss_fft_cfg st,
         size_t m
         )
{
     size_t k=m;
     const size_t m2 = 2*m;
     kiss_fft_cpx *tw1,*tw2;
     kiss_fft_cpx scratch[5];
     kiss_fft_cpx epi3;
     epi3 = st->twiddles[fstride*m];

     tw1=tw2=st->twiddles;

     do{
         C_FIXDIV(*Fout,3); C_FIXDIV(Fout[m],3); C_FIXDIV(Fout[m2],3);

         C_MUL(scratch[1],Fout[m] , *tw1);
         C_MUL(scratch[2],Fout[m2] , *tw2);

         C_ADD(scratch[3],scratch[1],scratch[2]);
         C_SUB(scratch[0],scratch[1],scratch[2]);
         tw1 += fstride;
         tw2 += fstride*2;

         Fout[m].r = Fout->r - HALF_OF(scratch[3].r);
         Fout[m].i = Fout->i - HALF_OF(scratch[3].i);

         C_MULBYSCALAR( scratch[0] , epi3.i );

         C_ADDTO(*Fout,scratch[3]);

         Fout[m2].r = Fout[m].r + scratch[0].i;
         Fout[m2].i = Fout[m].i - scratch[0].r;

         Fout[m].r -= scratch[0].i;
         Fout[m].i += scratch[0].r;

         ++Fout;
     }while(--k);
}

static void kf_bfly5(
        kiss_fft_cpx * Fout,
        const size_t fstride,
        const kiss_fft_cfg st,
        int m
        )
{
    kiss_fft_cpx *Fout0,*Fout1,*Fout2,*Fout3,*Fout4;
    int u;
    kiss_fft_cpx scratch[13];
    kiss_fft_cpx * twiddles = st->twiddles;
    kiss_fft_cpx *tw;
    kiss_fft_cpx ya,yb;
    ya = twiddles[fstride*m];
    yb = twiddles[fstride*2*m];

    Fout0=Fout;
    Fout1=Fout0+m;
    Fout2=Fout0+2*m;
    Fout3=Fout0+3*m;
    Fout4=Fout0+4*m;

    tw=st->twiddles;
    for ( u=0; u<m; ++u ) {
        C_FIXDIV( *Fout0,5); C_FIXDIV( *Fout1,5); C_FIXDIV( *Fout2,5); C_FIXDIV( *Fout3,5); C_FIXDIV( *Fout4,5);
        scratch[0] = *Fout0;

        C_MUL(scratch[1] ,*Fout1, tw[u*fstride]);
        C_MUL(scratch[2] ,*Fout2, tw[2*u*fstride]);
        C_MUL(scratch[3] ,*Fout3, tw[3*u*fstride]);
        C_MUL(scratch[4] ,*Fout4, tw[4*u*fstride]);

        C_ADD( scratch[7],scratch[1],scratch[4]);
        C_SUB( scratch[10],scratch[1],scratch[4]);
        C_ADD( scratch[8],scratch[2],scratch[3]);
        C_SUB( scratch[9],scratch[2],scratch[3]);

        Fout0->r += scratch[7].r + scratch[8].r;
        Fout0->i += scratch[7].i + scratch[8].i;

        scratch[5].r = scratch[0].r + S_MUL(scratch[7].r,ya.r) + S_MUL(scratch[8].r,yb.r);
        scratch[5].i = scratch[0].i + S_MUL(scratch[7].i,ya.r) + S_MUL(scratch[8].i,yb.r);

        scratch[6].r =  S_MUL(scratch[10].i,ya.i) + S_MUL(scratch[9].i,yb.i);
        scratch[6].i = -S_MUL(scratch[10].r,ya.i) - S_MUL(scratch[9].r,yb.i);

        C_SUB(*Fout1,scratch[5],scratch[6]);
        C_ADD(*Fout4,scratch[5],scratch[6]);

        scratch[11].r = scratch[0].r + S_MUL(scratch[7].r,yb.r) + S_MUL(scratch[8].r,ya.r);
        scratch[11].i = scratch[0].i + S_MUL(scratch[7].i,yb.r) + S_MUL(scratch[8].i,ya.r);
        scratch[12].r = - S_MUL(scratch[10].i,yb.i) + S_MUL(scratch[9].i,ya.i);
        scratch[12].i = S_MUL(scratch[10].r,yb.i) - S_MUL(scratch[9].r,ya.i);

        C_ADD(*Fout2,scratch[11],scratch[12]);
        C_SUB(*Fout3,scratch[11],scratch[12]);

        ++Fout0;++Fout1;++Fout2;++Fout3;++Fout4;
    }
}

/* perform the butterfly for one stage of a mixed radix FFT */
static void kf_bfly_generic(
        kiss_fft_cpx * Fout,
        const size_t fstride,
        const kiss_fft_cfg st,
        int m,
        int p
        )
{
    int u,k,q1,q;
    kiss_fft_cpx * twiddles = st->twiddles;
    kiss_fft_cpx t;
    int Norig = st->nfft;

    kiss_fft_cpx * scratch = (kiss_fft_cpx*)KISS_FFT_TMP_ALLOC(sizeof(kiss_fft_cpx)*p);
    if (scratch == NULL){
        KISS_FFT_ERROR("Memory allocation failed.");
        return;
    }

    for ( u=0; u<m; ++u ) {
        k=u;
        for ( q1=0 ; q1<p ; ++q1 ) {
            scratch[q1] = Fout[ k  ];
            C_FIXDIV(scratch[q1],p);
            k += m;
        }

        k=u;
        for ( q1=0 ; q1<p ; ++q1 ) {
            int twidx=0;
            Fout[ k ] = scratch[0];
            for (q=1;q<p;++q ) {
                twidx += fstride * k;
                if (twidx>=Norig) twidx-=Norig;
                C_MUL(t,scratch[q] , twiddles[twidx] );
                C_ADDTO( Fout[ k ] ,t);
            }
            k += m;
        }
    }
    KISS_FFT_TMP_FREE(scratch);
}

static
void kf_work(
        kiss_fft_cpx * Fout,
        const kiss_fft_cpx * f,
        const size_t fstride,
        int in_stride,
        int * factors,
        const kiss_fft_cfg st
        )
{
    kiss_fft_cpx * Fout_beg=Fout;
    const int p=*factors++; /* the radix  */
    const int m=*factors++; /* stage's fft length/p */
    const kiss_fft_cpx * Fout_end = Fout + p*m;

#ifdef _OPENMP
    // use openmp extensions at the
    // top-level (not recursive)
    if (fstride==1 && p<=5 && m!=1)
    {
        int k;

        // execute the p different work units in different threads
#       pragma omp parallel for
        for (k=0;k<p;++k)
            kf_work( Fout +k*m, f+ fstride*in_stride*k,fstride*p,in_stride,factors,st);
        // all threads have joined by this point

        switch (p) {
            case 2: kf_bfly2(Fout,fstride,st,m); break;
            case 3: kf_bfly3(Fout,fstride,st,m); break;
            case 4: kf_bfly4(Fout,fstride,st,m); break;
            case 5: kf_bfly5(Fout,fstride,st,m); break;
            default: kf_bfly_generic(Fout,fstride,st,m,p); break;
        }
        return;
    }
#endif

    if (m==1) {
        do{
            *Fout = *f;
            f += fstride*in_stride;
        }while(++Fout != Fout_end );
    }else{
        do{
            // recursive call:
            // DFT of size m*p performed by doing
            // p instances of smaller DFTs of size m,
            // each one takes a decimated version of the input
            kf_work( Fout , f, fstride*p, in_stride, factors,st);
            f += fstride*in_stride;
        }while( (Fout += m) != Fout_end );
    }

    Fout=Fout_beg;

    // recombine the p smaller DFTs
    switch (p) {
        case 2: kf_bfly2(Fout,fstride,st,m); break;
        case 3: kf_bfly3(Fout,fstride,st,m); break;
        case 4: kf_bfly4(Fout,fstride,st,m); break;
        case 5: kf_bfly5(Fout,fstride,st,m); break;
        default: kf_bfly_generic(Fout,fstride,st,m,p); break;
    }
}

/*  facbuf is populated by p1,m1,p2,m2, ...
    where
    p[i] * m[i] = m[i-1]
    m0 = n                  */
static
void kf_factor(int n,int * facbuf)
{
    int p=4;
    double floor_sqrt;
    floor_sqrt = floor( sqrt((double)n) );

    /*factor out powers of 4, powers of 2, then any remaining primes */
    do {
        while (n % p) {
            switch (p) {
                case 4: p = 2; break;
                case 2: p = 3; break;
                default: p += 2; break;
            }
            if (p > floor_sqrt)
                p = n;          /* no more factors, skip to end */
        }
        n /= p;
        *facbuf++ = p;
        *facbuf++ = n;
    } while (n > 1);
}

/*
 *
 * User-callable function to allocate all necessary storage space for the fft.
 *
 * The return value is a contiguous block of memory, allocated with malloc.  As such,
 * It can be freed with free(), rather than a kiss_fft-specific function.
 * */
kiss_fft_cfg kiss_fft_alloc(int nfft,int inverse_fft,void * mem,size_t * lenmem )
{
    KISS_FFT_ALIGN_CHECK(mem)

    kiss_fft_cfg st=NULL;
    size_t memneeded = KISS_FFT_ALIGN_SIZE_UP(sizeof(struct kiss_fft_state)
        + sizeof(kiss_fft_cpx)*(nfft-1)); /* twiddle factors*/

    if ( lenmem==NULL ) {
        st = ( kiss_fft_cfg)KISS_FFT_MALLOC( memneeded );
    }else{
        if (mem != NULL && *lenmem >= memneeded)
            st = (kiss_fft_cfg)mem;
        *lenmem = memneeded;
    }
    if (st) {
        int i;
        st->nfft=nfft;
        st->inverse = inverse_fft;

        for (i=0;i<nfft;++i) {
            const double pi=3.141592653589793238462643383279502884197169399375105820974944;
            double phase = -2*pi*i / nfft;
            if (st->inverse)
                phase *= -1;
            kf_cexp(st->twiddles+i, phase );
        }

        kf_factor(nfft,st->factors);
    }
    return st;
}


void kiss_fft_stride(kiss_fft_cfg st,const kiss_fft_cpx *fin,kiss_fft_cpx *fout,int in_stride)
{
    if (fin == fout) {
        //NOTE: this is not really an in-place FFT algorithm.
        //It just performs an out-of-place FFT into a temp buffer
        if (fout == NULL){
            KISS_FFT_ERROR("fout buffer NULL.");
        return;
        }

        kiss_fft_cpx * tmpbuf = (kiss_fft_cpx*)KISS_FFT_TMP_ALLOC( sizeof(kiss_fft_cpx)*st->nfft);
        if (tmpbuf == NULL){
            KISS_FFT_ERROR("Memory allocation error.");
        return;
        }



        kf_work(tmpbuf,fin,1,in_stride, st->factors,st);
        memcpy(fout,tmpbuf,sizeof(kiss_fft_cpx)*st->nfft);
        KISS_FFT_TMP_FREE(tmpbuf);
    }else{
        kf_work( fout, fin, 1,in_stride, st->factors,st );
    }
}

void kiss_fft(kiss_fft_cfg cfg,const kiss_fft_cpx *fin,kiss_fft_cpx *fout)
{
    kiss_fft_stride(cfg,fin,fout,1);
}


void kiss_fft_cleanup(void)
{
    // nothing needed any more
}

int kiss_fft_next_fast_size(int n)
{
    while(1) {
        int m=n;
        while ( (m%2) == 0 ) m/=2;
        while ( (m%3) == 0 ) m/=3;
        while ( (m%5) == 0 ) m/=5;
        if (m<=1)
            break; /* n is completely factorable by twos, threes, and fives */
        n++;
    }
    return n;
}

#line 1 "src/3rdparty/kissfft/kiss_fft.c [fin]"

#line 1 "src/3rdparty/kissfft/kiss_fftr.c"
/*
 *  Copyright (c) 2003-2004, Mark Borgerding. All rights reserved.
 *  This file is part of KISS FFT - https://github.com/mborgerding/kissfft
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *  See COPYING file for more information.
 */


// [omitido por inclusión previa: src/3rdparty/kissfft/kiss_fftr.h]

// [omitido por inclusión previa: src/3rdparty/kissfft/_kiss_fft_guts.h]

struct kiss_fftr_state{
    kiss_fft_cfg substate;
    kiss_fft_cpx * tmpbuf;
    kiss_fft_cpx * super_twiddles;
#ifdef USE_SIMD
    void * pad;
#endif
};

kiss_fftr_cfg kiss_fftr_alloc(int nfft,int inverse_fft,void * mem,size_t * lenmem)
{
	KISS_FFT_ALIGN_CHECK(mem)

    int i;
    kiss_fftr_cfg st = NULL;
    size_t subsize = 0, memneeded;

    if (nfft & 1) {
        KISS_FFT_ERROR("Real FFT optimization must be even.");
        return NULL;
    }
    nfft >>= 1;

    kiss_fft_alloc (nfft, inverse_fft, NULL, &subsize);
    memneeded = sizeof(struct kiss_fftr_state) + subsize + sizeof(kiss_fft_cpx) * ( nfft * 3 / 2);

    if (lenmem == NULL) {
        st = (kiss_fftr_cfg) KISS_FFT_MALLOC (memneeded);
    } else {
        if (*lenmem >= memneeded)
            st = (kiss_fftr_cfg) mem;
        *lenmem = memneeded;
    }
    if (!st)
        return NULL;

    st->substate = (kiss_fft_cfg) (st + 1); /*just beyond kiss_fftr_state struct */
    st->tmpbuf = (kiss_fft_cpx *) (((char *) st->substate) + subsize);
    st->super_twiddles = st->tmpbuf + nfft;
    kiss_fft_alloc(nfft, inverse_fft, st->substate, &subsize);

    for (i = 0; i < nfft/2; ++i) {
        double phase =
            -3.14159265358979323846264338327 * ((double) (i+1) / nfft + .5);
        if (inverse_fft)
            phase *= -1;
        kf_cexp (st->super_twiddles+i,phase);
    }
    return st;
}

void kiss_fftr(kiss_fftr_cfg st,const kiss_fft_scalar *timedata,kiss_fft_cpx *freqdata)
{
    /* input buffer timedata is stored row-wise */
    int k,ncfft;
    kiss_fft_cpx fpnk,fpk,f1k,f2k,tw,tdc;

    if ( st->substate->inverse) {
        KISS_FFT_ERROR("kiss fft usage error: improper alloc");
        return;/* The caller did not call the correct function */
    }

    ncfft = st->substate->nfft;

    /*perform the parallel fft of two real signals packed in real,imag*/
    kiss_fft( st->substate , (const kiss_fft_cpx*)timedata, st->tmpbuf );
    /* The real part of the DC element of the frequency spectrum in st->tmpbuf
     * contains the sum of the even-numbered elements of the input time sequence
     * The imag part is the sum of the odd-numbered elements
     *
     * The sum of tdc.r and tdc.i is the sum of the input time sequence.
     *      yielding DC of input time sequence
     * The difference of tdc.r - tdc.i is the sum of the input (dot product) [1,-1,1,-1...
     *      yielding Nyquist bin of input time sequence
     */

    tdc.r = st->tmpbuf[0].r;
    tdc.i = st->tmpbuf[0].i;
    C_FIXDIV(tdc,2);
    CHECK_OVERFLOW_OP(tdc.r ,+, tdc.i);
    CHECK_OVERFLOW_OP(tdc.r ,-, tdc.i);
    freqdata[0].r = tdc.r + tdc.i;
    freqdata[ncfft].r = tdc.r - tdc.i;
#ifdef USE_SIMD
    freqdata[ncfft].i = freqdata[0].i = _mm_set1_ps(0);
#else
    freqdata[ncfft].i = freqdata[0].i = 0;
#endif

    for ( k=1;k <= ncfft/2 ; ++k ) {
        fpk    = st->tmpbuf[k];
        fpnk.r =   st->tmpbuf[ncfft-k].r;
        fpnk.i = - st->tmpbuf[ncfft-k].i;
        C_FIXDIV(fpk,2);
        C_FIXDIV(fpnk,2);

        C_ADD( f1k, fpk , fpnk );
        C_SUB( f2k, fpk , fpnk );
        C_MUL( tw , f2k , st->super_twiddles[k-1]);

        freqdata[k].r = HALF_OF(f1k.r + tw.r);
        freqdata[k].i = HALF_OF(f1k.i + tw.i);
        freqdata[ncfft-k].r = HALF_OF(f1k.r - tw.r);
        freqdata[ncfft-k].i = HALF_OF(tw.i - f1k.i);
    }
}

void kiss_fftri(kiss_fftr_cfg st,const kiss_fft_cpx *freqdata,kiss_fft_scalar *timedata)
{
    /* input buffer timedata is stored row-wise */
    int k, ncfft;

    if (st->substate->inverse == 0) {
        KISS_FFT_ERROR("kiss fft usage error: improper alloc");
        return;/* The caller did not call the correct function */
    }

    ncfft = st->substate->nfft;

    st->tmpbuf[0].r = freqdata[0].r + freqdata[ncfft].r;
    st->tmpbuf[0].i = freqdata[0].r - freqdata[ncfft].r;
    C_FIXDIV(st->tmpbuf[0],2);

    for (k = 1; k <= ncfft / 2; ++k) {
        kiss_fft_cpx fk, fnkc, fek, fok, tmp;
        fk = freqdata[k];
        fnkc.r = freqdata[ncfft - k].r;
        fnkc.i = -freqdata[ncfft - k].i;
        C_FIXDIV( fk , 2 );
        C_FIXDIV( fnkc , 2 );

        C_ADD (fek, fk, fnkc);
        C_SUB (tmp, fk, fnkc);
        C_MUL (fok, tmp, st->super_twiddles[k-1]);
        C_ADD (st->tmpbuf[k],     fek, fok);
        C_SUB (st->tmpbuf[ncfft - k], fek, fok);
#ifdef USE_SIMD
        st->tmpbuf[ncfft - k].i *= _mm_set1_ps(-1.0);
#else
        st->tmpbuf[ncfft - k].i *= -1;
#endif
    }
    kiss_fft (st->substate, st->tmpbuf, (kiss_fft_cpx *) timedata);
}

#line 1 "src/3rdparty/kissfft/kiss_fftr.c [fin]"

#undef DEBUG

static bool FpResampleMono16(const std::vector<short>& input, unsigned inputRate,
                             unsigned outputRate, std::vector<short>& output) {
    output.clear();
    if (inputRate == 0 || outputRate == 0 || input.size() < 2) return false;
    if (inputRate == outputRate) { output = input; return true; }

    const uint64_t countNumerator = (uint64_t)input.size() * outputRate;
    const size_t count = (size_t)((countNumerator + inputRate - 1u) / inputRate);
    if (count < (size_t)outputRate * 8u || count > (size_t)outputRate * 120u) return false;

    try {

    const int taps = 32, half = taps / 2, phases = 1024;
    std::vector<double> coeff((size_t)taps * phases);
    const double pi = 3.14159265358979323846;
    const double ratio = std::min(1.0, (double)outputRate / (double)inputRate);
    const double cutoff = 0.5 * ratio;
    for (int ph = 0; ph < phases; ++ph) {
        const double frac = (double)ph / (double)phases;
        for (int t = 0; t < taps; ++t) {
            const double x = (double)(t - (half - 1)) - frac;
            const double ax = std::fabs(x);
            double window = 0.0;
            if (ax <= (double)half) {
                window = 0.42 + 0.5 * std::cos(pi * x / half) +
                         0.08 * std::cos(2.0 * pi * x / half);
            }
            const double z = 2.0 * cutoff * x;
            const double sinc = std::fabs(z) < 1e-12 ? 1.0 : std::sin(pi * z) / (pi * z);
            coeff[(size_t)ph * taps + t] = (2.0 * cutoff) * sinc * window;
        }
    }

    output.resize(count);
    for (size_t i = 0; i < count; ++i) {
        const uint64_t pos = (uint64_t)i * inputRate;
        const size_t base = (size_t)(pos / outputRate);
        const uint64_t rem = pos % outputRate;
        const int phase = (int)((rem * phases) / outputRate);
        const double* c = coeff.data() + (size_t)phase * taps;
        double sum = 0.0, norm = 0.0;
        for (int t = 0; t < taps; ++t) {
            const int64_t sampleAt = (int64_t)base + t - (half - 1);
            const size_t at = (size_t)std::max<int64_t>(0, std::min<int64_t>(
                (int64_t)input.size() - 1, sampleAt));
            sum += (double)input[at] * c[t];
            norm += c[t];
        }
        const long value = std::lround(norm != 0.0 ? sum / norm : 0.0);
        output[i] = (short)std::max<long>(-32768, std::min<long>(32767, value));
    }
    return true;
    } catch (...) {
        output.clear();
        return false;
    }
}

static bool CpFingerprintPcm16(const std::vector<short>& pcm, int sampleRate,
                               std::string& fingerprint) {
    fingerprint.clear();
    if (sampleRate != 11025 || pcm.size() < (size_t)11025 * 8u ||
        pcm.size() > (size_t)11025 * 120u) return false;

    ChromaprintContext* ctx = chromaprint_new(CHROMAPRINT_ALGORITHM_DEFAULT);
    if (!ctx) return false;
    char* fp = nullptr;
    bool ok = false;
    try {
        ok = chromaprint_start(ctx, sampleRate, 1) != 0;
        for (size_t at = 0; ok && at < pcm.size();) {
            const int count = (int)std::min<size_t>(pcm.size() - at, 32768u);
            ok = chromaprint_feed(ctx, reinterpret_cast<const int16_t*>(pcm.data() + at), count) != 0;
            at += (size_t)count;
        }
        if (ok) ok = chromaprint_finish(ctx) != 0 &&
                     chromaprint_get_fingerprint(ctx, &fp) != 0 && fp != nullptr;
        if (ok && fp) fingerprint.assign(fp);
    } catch (...) {
        ok = false;
        fingerprint.clear();
    }
    if (fp) chromaprint_dealloc(fp);
    chromaprint_free(ctx);
    return ok && fingerprint.size() >= 20;
}

#undef CHROMAPRINT_NODLL
#undef HAVE_CONFIG_H
#undef USE_KISSFFT
#undef CHROMAPRINT_API
#undef DEBUG

static uint64_t FpDiagnosticFingerprintHash(const std::string& fingerprint) {
    uint64_t h = UINT64_C(14695981039346656037);
    for (unsigned char byte : fingerprint) {
        h ^= (uint64_t)byte;
        h *= UINT64_C(1099511628211);
    }
    return h;
}

// Resample decoded audio in-process and calculate the Chromaprint fingerprint.
static bool FpDecodeAndFingerprint(const std::wstring& path, double& duration,
                                   std::string& fingerprint) {
    std::vector<short> nativePcm, pcm11025;
    unsigned nativeRate = 0;
    if (!gc83::DecodeMp3ToMonoPcm16(path, nativePcm, nativeRate, duration, 120) ||
        !FpResampleMono16(nativePcm, nativeRate, 11025, pcm11025)) {
        fingerprint.clear();
        return false;
    }
    return CpFingerprintPcm16(pcm11025, 11025, fingerprint);
}

static bool FpEnabled() {

    return g.fpOn && g_acoustKeyCfg[0] != 0;
}

static bool FpAcoustIdRequestPath(const std::wstring& client, double fullDuration,
                                  const std::string& fingerprint, std::wstring& path) {
    path.clear();
    if (client.empty() || fingerprint.size() < 20 || fingerprint.size() > 30000 ||
        !std::isfinite(fullDuration) || fullDuration < 1.0 || fullDuration > 21600.0)
        return false;

    for (wchar_t c : client) {
        if (!((c >= L'A' && c <= L'Z') || (c >= L'a' && c <= L'z') ||
              (c >= L'0' && c <= L'9') || c == L'_' || c == L'-')) return false;
    }

    for (unsigned char c : fingerprint) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') || c == '+' || c == '/' ||
              c == '=' || c == '-' || c == '_')) return false;
    }

    const uint64_t totalSeconds = static_cast<uint64_t>(std::floor(fullDuration));
    if (totalSeconds < 1u || totalSeconds > 21600u) return false;
    const std::wstring durationText = std::to_wstring(totalSeconds);

    path = L"/v2/lookup?format=json&client=" + UrlEncode(client) +
           L"&duration=" + durationText +
           L"&fingerprint=" + UrlEncode(FromUtf8(fingerprint)) +
           L"&meta=recordingids";
    return true;
}

static bool FpAcoustIdValidatePostBody(const std::string& body,
                                      std::string& durationText) {
    durationText.clear();
    bool client = false, duration = false, fingerprint = false, format = false;
    size_t pos = 0;
    while (pos < body.size()) {
        const size_t end = body.find('&', pos);
        const size_t stop = end == std::string::npos ? body.size() : end;
        const size_t eq = body.find('=', pos);
        if (eq == std::string::npos || eq >= stop || eq == pos || eq + 1 == stop)
            return false;
        const std::string name = body.substr(pos, eq - pos);
        const std::string value = body.substr(eq + 1, stop - eq - 1);
        if (name == "client") {
            if (client) return false;
            client = true;
        } else if (name == "duration") {
            if (duration) return false;
            duration = true;
            if (value.empty() || value.size() > 16) return false;

            for (char c : value) {
                if (c < '0' || c > '9') return false;
            }
            if (value == "0") return false;
            durationText = value;
        } else if (name == "fingerprint") {
            if (fingerprint || value.size() < 20) return false;
            fingerprint = true;
        } else if (name == "format") {
            if (format || value != "json") return false;
            format = true;
        } else if (name != "meta") {

            return false;
        }
        if (end == std::string::npos) break;
        pos = end + 1;
        if (pos == body.size()) return false;
    }
    return client && duration && fingerprint && format;
}

static bool FpAcoustIdPost(const std::wstring& validatedPath, std::string& out) {
    out.clear();
    const std::wstring prefix = L"/v2/lookup?";
    if (g_stop || validatedPath.compare(0, prefix.size(), prefix) != 0) return false;
    const std::wstring wideBody = validatedPath.substr(prefix.size());
    if (wideBody.empty() || wideBody.size() > 65536u) return false;
    std::string body;
    body.reserve(wideBody.size());
    for (wchar_t c : wideBody) {
        if (c < 0x21 || c > 0x7e) return false;
        body.push_back(static_cast<char>(c));
    }
    std::string durationText;
    if (!FpAcoustIdValidatePostBody(body, durationText)) {
        Wh_Log(L"AcoustID: POST cancelado, faltan parametros obligatorios o hay valores invalidos");
        return false;
    }

    Wh_Log(L"AcoustID: POST validado; ruta=/v2/lookup; HTTPS=1; Content-Type=application/x-www-form-urlencoded; Accept=application/json; duration=%s s; body_bytes=%llu; modo=entero",
           FromUtf8(durationText).c_str(), (unsigned long long)body.size());
    HINTERNET ses = WinHttpOpen(GC_HTTP_AGENT_W, WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
                                WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!ses) ses = WinHttpOpen(GC_HTTP_AGENT_W, WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!ses) return false;
    WinHttpSetTimeouts(ses, 4000, 4000, 4000, 10000);
    HINTERNET con = WinHttpConnect(ses, L"api.acoustid.org", INTERNET_DEFAULT_HTTPS_PORT, 0);
    HINTERNET req = con ? WinHttpOpenRequest(con, L"POST", L"/v2/lookup", nullptr,
                        WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE) : nullptr;
    bool ok = false;
    if (req) {
        static const wchar_t headers[] = L"Content-Type: application/x-www-form-urlencoded\r\nAccept: application/json\r\n";
        const DWORD bytes = static_cast<DWORD>(body.size());
        if (WinHttpSendRequest(req, headers, (DWORD)-1, body.data(), bytes, bytes, 0) &&
            WinHttpReceiveResponse(req, nullptr)) {
            DWORD status = 0, length = sizeof(status);
            const bool gotStatus = !!WinHttpQueryHeaders(req, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                                    WINHTTP_HEADER_NAME_BY_INDEX, &status, &length,
                                    WINHTTP_NO_HEADER_INDEX);
            Wh_Log(L"AcoustID: HTTP status %lu; request_duration=%s s",
                   gotStatus ? status : 0, FromUtf8(durationText).c_str());
            if (gotStatus) {

                const size_t cap = status == 200 ? (4u << 20) : 16384u;
                std::string response;
                bool complete = false;
                while (!g_stop) {
                    DWORD avail = 0;
                    if (!WinHttpQueryDataAvailable(req, &avail)) break;
                    if (!avail) { complete = true; break; }
                    if (avail > cap - response.size()) break;
                    std::string chunk(avail, '\0');
                    DWORD read = 0;
                    if (!WinHttpReadData(req, &chunk[0], avail, &read) || !read) break;
                    response.append(chunk.data(), read);
                }
                if (status == 200) {
                    ok = complete && !response.empty() && !g_stop;
                    if (ok) out.swap(response);
                } else {

                    const bool missing = response.find("missing required parameter") != std::string::npos;
                    const wchar_t* field = L"no determinado";
                    if (response.find("duration") != std::string::npos) field = L"duration";
                    else if (response.find("fingerprint") != std::string::npos) field = L"fingerprint";
                    else if (response.find("client") != std::string::npos) field = L"client";
                    else if (response.find("format") != std::string::npos) field = L"format";
                    Wh_Log(L"AcoustID: respuesta HTTP %lu; error=%s; campo=%s; cuerpo_recibido=%d",
                           status, missing ? L"parametro obligatorio ausente" : L"rechazo no clasificado",
                           field, complete ? 1 : 0);

                }
            }
        } else {
            Wh_Log(L"AcoustID: fallo de envio/recepcion HTTP (%lu)", GetLastError());
        }
        WinHttpCloseHandle(req);
    }
    if (con) WinHttpCloseHandle(con);
    WinHttpCloseHandle(ses);
    if (!ok) out.clear();
    return ok;
}

static bool FpAcoustId(double dur, const std::string& fp, std::wstring& mbid, int& pct) {
    mbid.clear();
    pct = 0;
    std::wstring path;
    if (!FpAcoustIdRequestPath(std::wstring(g_acoustKeyCfg), dur, fp, path)) {
        Wh_Log(L"Huella: AcoustID cancelado: clave, huella o duracion total invalidas");
        return false;
    }
    std::string js;
    if (!FpAcoustIdPost(path, js)) {
        Wh_Log(L"Huella: fallo de red/HTTP POST al consultar AcoustID");
        return false;
    }
    std::string st;
    if (!JsonTopString(js, "status", st) || st != "ok") {

        size_t errorAt = js.find("\"error\"");
        std::string errorMessage;
        if (errorAt != std::string::npos)
            JsonString(js, errorAt, "message", errorMessage);
        if (!errorMessage.empty())
            Wh_Log(L"Huella: AcoustID rechazo la peticion: %s",
                   FromUtf8(errorMessage).c_str());
        else
            Wh_Log(L"Huella: AcoustID devolvio status distinto de ok");
        return false;
    }

    std::vector<std::string> candidates;
    JsonArrayObjects(js, "results", candidates);
    double bestScore = -1.0;
    std::string bestId;
    for (const std::string& candidate : candidates) {
        double candidateScore = 0.0;
        if (!JsonTopNumber(candidate, "score", candidateScore) ||
            !std::isfinite(candidateScore) || candidateScore < 0.0 ||
            candidateScore > 1.0 || candidateScore <= bestScore) continue;
        std::vector<std::string> recordings;
        JsonArrayObjects(candidate, "recordings", recordings);
        for (const std::string& recording : recordings) {
            std::string id;
            if (JsonTopString(recording, "id", id) && FpValidRecordingId(id)) {
                bestScore = candidateScore;
                bestId = id;
                break;
            }
        }
    }
    if (bestId.empty()) {
        Wh_Log(L"Huella: AcoustID status ok, sin grabacion MusicBrainz valida (candidatos=%llu)",
               (unsigned long long)candidates.size());
        return false;
    }
    Wh_Log(L"Huella: AcoustID resultado valido; candidatos=%llu; score=%d%%",
           (unsigned long long)candidates.size(), (int)(bestScore * 100.0 + 0.5));
    mbid = FromUtf8(bestId);
    pct = (int)(bestScore * 100.0 + 0.5);
    return true;
}

static bool FpMusicBrainz(const std::wstring& mbid, double fpDur, FpResult& out) {
    if (!MbReserveRequest(true)) return false;
    std::string js;
    if (!HttpGet(L"musicbrainz.org", L"/ws/2/recording/" + mbid + L"?inc=artists+releases&fmt=json", js)) return false;
    std::string t;
    if (!JsonTopString(js, "title", t) || t.empty()) return false;
    double recordingMs = 0.0;
    if (JsonTopNumber(js, "length", recordingMs) && recordingMs > 0.0 &&
        fpDur > 0.0 && fabs(recordingMs / 1000.0 - fpDur) > 12.0) {
        Wh_Log(L"Huella: la duracion no cuadra (archivo %.0f s, MusicBrainz %.0f s); se descarta",
               fpDur, recordingMs / 1000.0);
        return false;
    }
    out.title = FromUtf8(t);
    std::vector<std::string> credits;
    JsonArrayObjects(js, "artist-credit", credits);
    std::wstring artist;
    for (size_t i = 0; i < credits.size(); i++) {
        std::string nm, jp;
        if (JsonTopString(credits[i], "name", nm)) artist += FromUtf8(nm);
        if (JsonTopString(credits[i], "joinphrase", jp)) artist += FromUtf8(jp);
    }
    out.artist = Trim(artist);
    std::string frd;
    JsonTopString(js, "first-release-date", frd);
    struct Rel { std::string id, date, title; bool official; bool suspicious; };
    std::vector<Rel> rels;
    std::vector<std::string> robjs;
    JsonArrayObjects(js, "releases", robjs);
    for (size_t i = 0; i < robjs.size(); i++) {
        Rel r;
        std::string stt;
        JsonTopString(robjs[i], "id", r.id);
        JsonTopString(robjs[i], "date", r.date);
        JsonTopString(robjs[i], "title", r.title);
        JsonTopString(robjs[i], "status", stt);
        r.official = (stt == "Official");
        std::wstring lower = LowerWs(FromUtf8(r.title));

        r.suspicious = lower.find(L"live") != std::wstring::npos ||
                       lower.find(L"tour") != std::wstring::npos ||
                       lower.find(L"remix") != std::wstring::npos ||
                       lower.find(L"karaoke") != std::wstring::npos ||
                       lower.find(L"en vivo") != std::wstring::npos ||
                       lower.find(L"concert") != std::wstring::npos;
        if (FpValidRecordingId(r.id)) rels.push_back(r);
    }

    std::sort(rels.begin(), rels.end(), [](const Rel& a, const Rel& b) {
        if (a.suspicious != b.suspicious) return !a.suspicious;
        if (a.official != b.official) return a.official;
        if (a.date.empty() != b.date.empty()) return !a.date.empty();
        if (a.date != b.date) return a.date < b.date;
        return a.id < b.id;
    });
    for (size_t i = 0; i < rels.size() && i < 6; i++) out.releases.push_back(FromUtf8(rels[i].id));

    if (!rels.empty() && !rels[0].suspicious) out.album = FromUtf8(rels[0].title);
    else if (!rels.empty())
        Wh_Log(L"Huella: ediciones MusicBrainz ambiguas (live/tour/remix); album B sin confirmar");
    if (!rels.empty())
        Wh_Log(L"Huella: MusicBrainz ofrece %llu edicion(es); primer candidato: %s",
               (unsigned long long)rels.size(), FromUtf8(rels[0].title).c_str());
    std::wstring y = FromUtf8(frd);
    if (!MetaYearOk(y) && !rels.empty()) y = FromUtf8(rels[0].date);
    out.year = MetaYearOk(y) ? y.substr(0, 4) : std::wstring();
    out.mbid = mbid;
    return !out.title.empty() && !out.artist.empty();
}

static bool FpFetchCover(const FpResult& fp, std::vector<BYTE>& img) {
    for (size_t i = 0; i < fp.releases.size() && i < 5 && !g_stop; i++) {
        for (int variant = 0; variant < 2 && !g_stop; variant++) {
            const wchar_t* suffix = variant == 0 ? L"/front-500" : L"/front";
            std::string raw;
            if (!HttpGet(L"coverartarchive.org", L"/release/" + fp.releases[i] + suffix, raw)) {
                Wh_Log(L"Huella: Cover Art Archive sin respuesta util (edicion %u, intento %d)",
                       (unsigned)(i + 1), variant + 1);
                continue;
            }
            if (raw.size() < 3000 || raw.size() > (4u << 20)) {
                Wh_Log(L"Huella: portada descartada por tamano (edicion %u, bytes=%llu)",
                       (unsigned)(i + 1), (unsigned long long)raw.size());
                continue;
            }
            std::vector<BYTE> b(raw.begin(), raw.end());
            if (CvImageType(b) == 0) {
                Wh_Log(L"Huella: portada descartada por formato (edicion %u)", (unsigned)(i + 1));
                continue;
            }
            img.swap(b);
            Wh_Log(L"Huella: caratula valida de Cover Art Archive (edicion %u, bytes=%llu)",
                   (unsigned)(i + 1), (unsigned long long)img.size());
            return true;
        }
    }
    Wh_Log(L"Huella: Cover Art Archive sin portada valida entre %u ediciones comprobadas",
           (unsigned)std::min<size_t>(fp.releases.size(), 5));
    return false;
}

static bool FpValidCachedMatch(const std::vector<std::wstring>& ln,
                               unsigned long long bytes, unsigned long long stamp,
                               int& score) {
    score = 0;
    if ((ln.size() != 10 && ln.size() != 11) ||
        (ln.size() == 11 && !ln[10].empty()) || ln[0] != L"FP3" ||
        ln[1] != std::to_wstring(bytes) || ln[2] != std::to_wstring(stamp) ||
        ln[3].size() < 2 || ln[3].size() > 3 ||
        ln[4].size() != 36 || ln[5].empty() || ln[6].empty()) return false;
    int parsedScore = 0;
    for (wchar_t c : ln[3]) {
        if (c < L'0' || c > L'9') return false;
        parsedScore = parsedScore * 10 + (c - L'0');
    }
    if (parsedScore < 85 || parsedScore > 100) return false;
    std::string uuid;
    uuid.reserve(36);
    for (wchar_t c : ln[4]) {
        if (c > 127 || c < 0) return false;
        uuid.push_back(static_cast<char>(c));
    }
    if (!FpValidRecordingId(uuid)) return false;
    for (size_t i = 4; i <= 9; ++i) {
        if (ln[i].size() > 2048 ||
            ln[i].find(L'\r') != std::wstring::npos ||
            ln[i].find(L'\n') != std::wstring::npos ||
            ln[i].find(L'\0') != std::wstring::npos) return false;
    }
    score = parsedScore;
    return true;
}

static bool FpIdentify(const std::wstring& path, FpResult& out) {
    out = FpResult();
    if (g_stop || path.empty() || !FpEnabled()) return false;
    SrwGuard run(&g_fpLock);
    unsigned long long fsz = 0, ftm = 0;
    if (!CvFileStamp(path, fsz, ftm)) return false;
    std::wstring cdir = CvCacheDir();
    std::wstring cfile = cdir.empty() ? std::wstring() : cdir + L"\\" + CvPathKey(path) + L".fp";
    if (!cfile.empty()) {
        std::wstring rawc = CvReadCacheText(cfile);
        if (!rawc.empty()) {
            std::vector<std::wstring> ln;
            std::wstring cur;
            for (size_t i = 0; i <= rawc.size(); i++) {
                if (i == rawc.size() || rawc[i] == L'\n') {
                    ln.push_back(cur);
                    cur.clear();
                } else {
                    cur += rawc[i];
                }
            }
            int cachedScore = 0;
            if (FpValidCachedMatch(ln, fsz, ftm, cachedScore)) {
                out.scorePct = cachedScore;
                out.mbid = ln[4];
                out.title = ln[5];
                out.artist = ln[6];
                out.year = ln[7];
                out.album = ln[8];
                std::wstring rc;
                for (size_t i = 0; i <= ln[9].size(); i++) {
                    if (i == ln[9].size() || ln[9][i] == L',') {
                        if (!rc.empty()) out.releases.push_back(rc);
                        rc.clear();
                    } else {
                        rc += ln[9][i];
                    }
                }
                out.ok = true;
                return true;
            }
        }
    }

    const std::wstring negativeKey = path + L"|" + std::to_wstring(fsz) + L"|" + std::to_wstring(ftm);
    {
        SrwGuard lk(&g_fpMemoLock);
        const ULONGLONG now = GetTickCount64();
        for (size_t i = 0; i < g_fpFailed.size(); i++)
            if (g_fpFailed[i].first == negativeKey &&
                now - g_fpFailed[i].second < 600000) return false;
    }
    auto failDefinitive = [&]() {
        SrwGuard lk(&g_fpMemoLock);
        if (g_fpFailed.size() > 64) g_fpFailed.erase(g_fpFailed.begin());
        g_fpFailed.push_back(std::make_pair(negativeKey, GetTickCount64()));
        return false;
    };
    double dur = 0;
    std::string fpr;
    Wh_Log(L"Huella: calculando la de '%s'", path.c_str());

    if (!FpDecodeAndFingerprint(path, dur, fpr)) return false;

    unsigned long long verifiedSize = 0, verifiedStamp = 0;
    if (!CvFileStamp(path, verifiedSize, verifiedStamp) ||
        verifiedSize != fsz || verifiedStamp != ftm) {
        Wh_Log(L"Huella: MP3 modificado durante la decodificacion; descartando resultado");
        return false;
    }

    Wh_Log(L"Huella: diagnostico fpcalc: duracion=%.3f; fp_chars=%llu; fp_fnv64=%016llx; algoritmo=DEFAULT",
           dur, (unsigned long long)fpr.size(),
           (unsigned long long)FpDiagnosticFingerprintHash(fpr));
    std::wstring mbid;
    int pct = 0;

    if (!FpAcoustId(dur, fpr, mbid, pct)) return false;
    if (pct < 85) {
        Wh_Log(L"Huella: AcoustID no la reconoce con seguridad (%d %%)", pct);
        return failDefinitive();
    }
    FpResult r;
    if (!FpMusicBrainz(mbid, dur, r)) return false;

    if (!CvFileStamp(path, verifiedSize, verifiedStamp) ||
        verifiedSize != fsz || verifiedStamp != ftm) {
        Wh_Log(L"Huella: MP3 modificado durante la consulta; descartando resultado");
        return false;
    }
    r.ok = true;
    r.scorePct = pct;
    out = r;
    Wh_Log(L"Huella: '%s' = '%s' de '%s' (%s), coincidencia %d %%", path.c_str(), out.title.c_str(),
           out.artist.c_str(), out.year.empty() ? L"sin ano" : out.year.c_str(), pct);
    if (!cfile.empty()) {
        std::wstring rc;
        for (size_t i = 0; i < out.releases.size(); i++) {
            if (i) rc += L",";
            rc += out.releases[i];
        }
        std::wstring rec = L"FP3\n" + std::to_wstring(fsz) + L"\n" + std::to_wstring(ftm) + L"\n" +
                           std::to_wstring(pct) + L"\n" + out.mbid + L"\n" + out.title + L"\n" + out.artist + L"\n" +
                           out.year + L"\n" + out.album + L"\n" + rc + L"\n";
        std::vector<std::wstring> fields;
        std::wstring part;
        for (wchar_t c : rec) {
            if (c == L'\n') { fields.push_back(part); part.clear(); }
            else part.push_back(c);
        }
        fields.push_back(part);
        int verifiedScore = 0;
        if (FpValidCachedMatch(fields, fsz, ftm, verifiedScore) && verifiedScore == pct)
            CvWriteFile(cfile, rec.c_str(), (rec.size() + 1) * sizeof(wchar_t));
    }
    return true;
}

// ---------------------------------------------------------------------------

struct ThumbJob {
    winrt::Windows::Storage::Streams::IRandomAccessStreamReference ref{nullptr};
    int gen = 0;
    int size = 0;
    std::wstring artist, title;
    bool online = false;
    std::wstring filePath;
    bool pathSure = false;
};

static bool ThumbDecode(winrt::Windows::Storage::Streams::IRandomAccessStream const& stream, int size,
                        ThumbResult* r) {
    using namespace winrt::Windows::Graphics::Imaging;
    if (size < 16) return false;
    auto decOp = BitmapDecoder::CreateAsync(stream);
    if (decOp.wait_for(std::chrono::seconds(5)) != winrt::Windows::Foundation::AsyncStatus::Completed) {
        decOp.Cancel();
        return false;
    }
    auto dec = decOp.GetResults();
    uint32_t w = dec.PixelWidth(), h = dec.PixelHeight();
    uint32_t S = (uint32_t)size;
    if (w == 0 || h == 0) return false;
    double sc = (double)S / (double)std::min(w, h);
    uint32_t sw = std::max<uint32_t>(S, (uint32_t)((double)w * sc + 0.5));
    uint32_t sh = std::max<uint32_t>(S, (uint32_t)((double)h * sc + 0.5));
    BitmapTransform tr;
    tr.ScaledWidth(sw);
    tr.ScaledHeight(sh);
    tr.InterpolationMode(BitmapInterpolationMode::Fant);
    BitmapBounds b;
    b.X = (sw - S) / 2;
    b.Y = (sh - S) / 2;
    b.Width = S;
    b.Height = S;
    tr.Bounds(b);
    auto pixelOp = dec.GetPixelDataAsync(BitmapPixelFormat::Bgra8, BitmapAlphaMode::Premultiplied, tr,
                                         ExifOrientationMode::IgnoreExifOrientation, ColorManagementMode::DoNotColorManage);
    if (pixelOp.wait_for(std::chrono::seconds(5)) != winrt::Windows::Foundation::AsyncStatus::Completed) {
        pixelOp.Cancel();
        return false;
    }
    auto pd = pixelOp.GetResults();
    auto bytes = pd.DetachPixelData();
    if (bytes.size() < (size_t)S * S * 4) return false;
    r->px.resize((size_t)S * S);
    memcpy(r->px.data(), bytes.data(), (size_t)S * S * 4);
    r->ok = true;
    return true;
}

static bool ThumbEncodePng(ThumbResult& result) {
    using namespace winrt::Windows::Graphics::Imaging;
    using namespace winrt::Windows::Storage::Streams;
    InMemoryRandomAccessStream stream;
    auto create = BitmapEncoder::CreateAsync(BitmapEncoder::PngEncoderId(), stream);
    if (create.wait_for(std::chrono::seconds(5)) != winrt::Windows::Foundation::AsyncStatus::Completed) {
        create.Cancel();
        return false;
    }
    auto encoder = create.GetResults();
    const auto* start = reinterpret_cast<const uint8_t*>(result.px.data());
    encoder.SetPixelData(BitmapPixelFormat::Bgra8, BitmapAlphaMode::Premultiplied,
                         result.size, result.size, 96.0, 96.0,
                         winrt::array_view<const uint8_t>(start, start + result.px.size() * 4));
    auto flush = encoder.FlushAsync();
    if (flush.wait_for(std::chrono::seconds(5)) != winrt::Windows::Foundation::AsyncStatus::Completed) {
        flush.Cancel();
        return false;
    }
    flush.GetResults();
    const uint64_t size = stream.Size();
    if (!size || size > (4u << 20)) return false;
    DataReader reader(stream.GetInputStreamAt(0));
    auto load = reader.LoadAsync(static_cast<uint32_t>(size));
    if (load.wait_for(std::chrono::seconds(5)) != winrt::Windows::Foundation::AsyncStatus::Completed) {
        load.Cancel();
        return false;
    }
    if (load.GetResults() != size) return false;
    result.img.resize(static_cast<size_t>(size));
    reader.ReadBytes(winrt::array_view<uint8_t>(result.img.data(), result.img.data() + result.img.size()));
    return CvImageType(result.img) == 2;
}

static bool NearPoint(float x, float y, float cx, float cy, float r);
static HWND g_metaWin;

static void MetaPanelClose();
static bool MetaPanelCoverFor(const std::wstring& artist, const std::wstring& title,
                              std::vector<BYTE>& out);
static void MetaPanelKick(bool force = false);
static void MetaPanelFill();
static void MetaPanelPaint();
static void MetaPanelPickFile();
static void MetaPanelApply();
static void MetaPanelOpen();

// Load the thumbnail and reject results that belong to a previous track.
static DWORD WINAPI ThumbThread(LPVOID param) {
    ThumbJob* job = static_cast<ThumbJob*>(param);
    ThumbResult* r = new ThumbResult();
    r->gen = job->gen;
    r->size = job->size;
    r->path = job->filePath;
    bool apartmentReady = false;
    try {
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        apartmentReady = true;
    } catch (...) {
    }
    bool done = false;

    std::wstring qa, qt;
    CvSplitQuery(job->artist, job->title, qa, qt);
    if (qt.empty()) qt = CvCleanTitle(job->title);
    if (!qt.empty()) {
        r->key = CvKeyName(qa, qt);
        r->keyHash = CvStrHash(r->key);
        r->artist = qa;
        r->title = qt;
    }

    if (job->pathSure && !job->filePath.empty() && !r->key.empty() && !g_stop) {
        try {
            FileMeta fm;
            if (ReadFileMeta(job->filePath, fm, true) && fm.coverOk && !fm.cover.empty()) {
                using namespace winrt::Windows::Storage::Streams;
                InMemoryRandomAccessStream ms;
                DataWriter dw(ms);
                dw.WriteBytes(winrt::array_view<const uint8_t>(fm.cover.data(), fm.cover.data() + fm.cover.size()));
                auto storeOp = dw.StoreAsync();
                if (storeOp.wait_for(std::chrono::seconds(5)) == winrt::Windows::Foundation::AsyncStatus::Completed) {
                    storeOp.GetResults();
                    dw.DetachStream();
                    ms.Seek(0);
                    if (ThumbDecode(ms, job->size, r)) {
                        r->img = fm.cover;
                        done = true;
                        Wh_Log(L"Miniatura: se usa la caratula del propio archivo '%s'", job->filePath.c_str());
                    }
                } else {
                    storeOp.Cancel();
                }
            }
        } catch (...) {
            done = false;
            r->ok = false;
        }
    }
    if (!done && job->ref) {
        try {
            auto openOp = job->ref.OpenReadAsync();
            if (openOp.wait_for(std::chrono::seconds(5)) != winrt::Windows::Foundation::AsyncStatus::Completed) {
                openOp.Cancel();
                throw winrt::hresult_error(E_ABORT);
            }
            auto st = openOp.GetResults();

            uint64_t encodedSize = st.Size();

            if (encodedSize >= 64 && encodedSize <= (4u << 20)) {
                using namespace winrt::Windows::Storage::Streams;
                DataReader reader(st.GetInputStreamAt(0));
                auto loadOp = reader.LoadAsync((uint32_t)encodedSize);
                uint32_t loaded = 0;
                if (loadOp.wait_for(std::chrono::seconds(5)) == winrt::Windows::Foundation::AsyncStatus::Completed)
                    loaded = loadOp.GetResults();
                else
                    loadOp.Cancel();
                if (loaded == encodedSize) {
                    std::vector<BYTE> encoded(loaded);
                    reader.ReadBytes(winrt::array_view<uint8_t>(encoded.data(), encoded.data() + encoded.size()));
                    if (CvImageType(encoded) != 0 && !r->key.empty()) {

                        uint64_t hash = 14695981039346656037ULL;
                        for (BYTE b : encoded) { hash ^= b; hash *= 1099511628211ULL; }
                        r->sourceHash = hash;
                        LONG64 previous = InterlockedCompareExchange64(&g_lastPlayerThumbHash, 0, 0);
                        LONG64 prevKey  = InterlockedCompareExchange64(&g_lastPlayerThumbKeyHash, 0, 0);
                        if (previous != 0 && (uint64_t)previous == hash &&
                            prevKey != 0 && (uint64_t)prevKey != r->keyHash) {
                            Wh_Log(L"Thumbnail: still associated with the previous track");
                        } else {
                            st.Seek(0);
                            done = ThumbDecode(st, job->size, r);
                            if (done) r->img = std::move(encoded);
                        }
                    }
                }
                reader.Close();
            }
            if (!done && r->sourceHash == 0) {
                st.Seek(0);
                done = ThumbDecode(st, job->size, r) && ThumbEncodePng(*r);
                r->ok = done;
            }
        } catch (...) {
            done = false;
            r->ok = false;
        }
    }

    if (!done && !job->title.empty() && !g_stop) {
        try {
            if (!qt.empty()) {
                std::wstring key = r->key;
                std::vector<BYTE> bytes;

                bool got = MetaPanelCoverFor(qa, qt, bytes);
                if (!got) got = CvGetCover(key, qa, qt, job->online, bytes);
                if (got) {
                    using namespace winrt::Windows::Storage::Streams;
                    InMemoryRandomAccessStream ms;
                    DataWriter dw(ms);
                    dw.WriteBytes(winrt::array_view<const uint8_t>(bytes.data(), bytes.data() + bytes.size()));
                    auto storeOp = dw.StoreAsync();
                    if (storeOp.wait_for(std::chrono::seconds(5)) != winrt::Windows::Foundation::AsyncStatus::Completed) {
                        storeOp.Cancel();
                        throw winrt::hresult_error(E_ABORT);
                    }
                    storeOp.GetResults();
                    dw.DetachStream();
                    ms.Seek(0);
                    if (ThumbDecode(ms, job->size, r)) {
                        r->img = bytes;
                        r->fallback = true;
                        r->key = key;
                        r->artist = qa;
                        r->title = qt;
                    }
                }
            }
        } catch (...) {
            r->ok = false;
            r->fallback = false;
        }
    }
    if (r->ok && (CvImageType(r->img) == 0 || r->img.size() > (16u << 20))) {
        try { r->ok = ThumbEncodePng(*r); }
        catch (...) { r->ok = false; }
    }
    try {
        job->ref = nullptr;
    } catch (...) {
    }
    if (apartmentReady) {
        try { winrt::uninit_apartment(); } catch (...) {}
    }
    delete job;
    if (!PostUi(WM_APP_THUMB, 0, (LPARAM)r)) delete r;
    return 0;
}

static void StartThumbThread() {
    if (!g_thumbRef && g.media.title.empty()) {
        ClearThumb();
        return;
    }
    if (g_thumbBusy) {
        g_thumbRedo = true;
        return;
    }
    CvCacheDir();
    ThumbJob* job = new ThumbJob();
    job->ref = g_thumbRef;
    job->gen = ++g_thumbGen;
    job->size = ClampInt((int)(kThumbU * g.kLast + 0.5f), 32, 256);
    job->artist = g.media.artist;
    job->title = g.media.title;
    job->online = g.onlineCovers && !CvIsBrowserSession();
    job->filePath = MediaCurrentPath();
    job->pathSure = !job->filePath.empty() && (!g.media.path.empty() || g.fileMeta.ok);
    g_thumbFileUsed = job->pathSure ? job->filePath : std::wstring();
    g_thumbThread = CreateThread(nullptr, 0, ThumbThread, job, 0, nullptr);
    if (!g_thumbThread) {
        delete job;
        return;
    }
    g_thumbBusy = true;
}

// Signal the probe and bound the UI wait. The worker's module reference protects its cleanup code.
static void StopMediaProbe();

static void ShutdownMedia() {
    StopMediaProbe();
    ReleaseMediaSession();
#if GH_HAVE_THUMB
    g_thumbRef = nullptr;
#endif
    if (g_winrtOwnApartment) winrt::uninit_apartment();
    g_winrtInit = g_winrtOwnApartment = false;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static std::wstring MxCleanName(const std::wstring& in) {
    std::wstring s = CvStripExt(in);
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == L'_' || s[i] == L'\t') s[i] = L' ';
    }

    {
        std::wstring out;
        for (size_t i = 0; i < s.size();) {
            wchar_t o = s[i];
            if (o == L'(' || o == L'[') {
                wchar_t c = (o == L'(') ? L')' : L']';
                size_t e = s.find(c, i + 1);
                if (e == std::wstring::npos) {
                    out += s[i];
                    ++i;
                    continue;
                }
                std::wstring inner = TrimWs(s.substr(i + 1, e - i - 1));
                std::wstring low = LowerWs(inner);
                bool drop = ContainsNoCase(low, L"official") || ContainsNoCase(low, L"oficial") ||
                            ContainsNoCase(low, L"videoclip") || ContainsNoCase(low, L"music video") ||
                            ContainsNoCase(low, L"lyric") || ContainsNoCase(low, L"letra") ||
                            ContainsNoCase(low, L"audio") || low == L"hq" || low == L"hd" ||
                            ContainsNoCase(low, L"320") || ContainsNoCase(low, L"www.") ||
                            ContainsNoCase(low, L".com") || ContainsNoCase(low, L"remaster") ||
                            ContainsNoCase(low, L"official video");
                if (!drop) out += inner;
                i = e + 1;
                if (i < s.size() && s[i] == L' ') ++i;
                continue;
            }
            out += s[i];
            ++i;
        }
        s = out;
    }

    std::wstring t = TrimWs(s);
    size_t i = 0;
    while (i < t.size() && t[i] >= L'0' && t[i] <= L'9') ++i;
    if (i > 0 && i <= 3) {
        size_t j = i;
        while (j < t.size() && (t[j] == L' ' || t[j] == L'.' || t[j] == L'-' || t[j] == L')')) ++j;
        if (j > i && j < t.size()) t = TrimWs(t.substr(j));
    }

    std::wstring r;
    for (size_t q = 0; q < t.size(); q++) {
        if (t[q] == L' ' && !r.empty() && r.back() == L' ') continue;
        r += t[q];
    }
    return TrimWs(r);
}

static bool MxSplitDash(const std::wstring& in, std::wstring& a, std::wstring& b) {
    size_t p = std::wstring::npos;
    for (size_t i = 0; i < in.size(); i++) {
        if (in[i] != L'-' && in[i] != L'\u2013' && in[i] != L'\u2014') continue;
        bool leftSp = (i > 0 && in[i - 1] == L' ');
        bool rightSp = (i + 1 < in.size() && in[i + 1] == L' ');
        if (leftSp || rightSp) {
            p = i;
            break;
        }
    }
    if (p == std::wstring::npos) return false;
    a = TrimWs(in.substr(0, p));
    b = TrimWs(in.substr(p + 1));
    return !a.empty() && !b.empty();
}

static bool MxLooksArtist(const std::wstring& w) {
    std::wstring low = LowerWs(w);
    static const wchar_t* kBad[] = {L"various", L"va", L"unknown", L"desconocido", L"track", L"audio",
                                    L"music", L"musica", L"album", L"single", L"mix", L"song",
                                    L"cancion", L"the", L"a"};
    for (size_t i = 0; i < sizeof(kBad) / sizeof(kBad[0]); i++) {
        if (low == kBad[i]) return false;
    }
    return low.size() >= 2;
}

static bool MxParseName(const std::wstring& fileName, std::wstring& artist, std::wstring& title) {
    std::wstring cut = MxCleanName(fileName);
    if (cut.empty()) return false;
    artist.clear();
    title.clear();
    std::wstring a, b;
    if (MxSplitDash(cut, a, b)) {
        std::wstring ca = CvCleanTitle(a), cb = CvCleanTitle(b);
        bool aArt = MxLooksArtist(ca), bArt = MxLooksArtist(cb);
        bool aFeat = ContainsNoCase(ca, L"feat") || ContainsNoCase(ca, L"ft.");
        bool bFeat = ContainsNoCase(cb, L"feat") || ContainsNoCase(cb, L"ft.");
        if (bArt && !aArt) {
            artist = cb;
            title = ca;
        } else if (aFeat && !bFeat) {
            artist = ca;
            title = cb;
        } else {
            artist = ca;
            title = cb;
        }
        if (artist.empty() || title.empty()) return false;
        return true;
    }
    std::wstring single = CvCleanTitle(cut);
    if (single.empty()) return false;
    title = single;
    return true;
}

static std::wstring MetaCatalogTitle(const std::wstring& title) {
    std::wstring clean = CvCleanTitleExact(title);
    std::wstring lower = LowerWs(clean);
    for (const std::wstring suffix : {L" (original mix)", L" [original mix]", L" - original mix"}) {
        if (lower.size() > suffix.size() &&
            lower.compare(lower.size() - suffix.size(), suffix.size(), suffix) == 0)
            return Trim(clean.substr(0, clean.size() - suffix.size()));
    }
    return clean;
}

struct MetaCatalogTrack {
    MetaOnlineProposal proposal;
    std::string artwork;
    std::string albumId;
    int seconds = 0;
    int trackCount = 0;
};

static bool MetaReadCatalogTrack(const std::string& row, MetaCatalog catalog, MetaCatalogTrack& track) {
    const bool apple = catalog == MetaCatalog::Apple;
    std::string title, artist, album, date, number;
    if (!JsonString(row, 0, apple ? "trackName" : "title", title) ||
        !JsonString(row, 0, apple ? "artistName" : "name", artist)) return false;
    track = {};
    track.proposal.title = CvJsonUnescape(title);
    track.proposal.artist = CvJsonUnescape(artist);
    track.proposal.catalog = catalog;
    if (JsonNumber(row, 0, apple ? "trackTimeMillis" : "duration", number))
        track.seconds = atoi(number.c_str()) / (apple ? 1000 : 1);
    if (apple) {
        if (JsonString(row, 0, "collectionName", album)) track.proposal.album = CvJsonUnescape(album);
        if (JsonString(row, 0, "releaseDate", date) && CvYearOk(date))
            track.proposal.year = FromUtf8(date.substr(0, 4));
        if (JsonNumber(row, 0, "trackCount", number)) track.trackCount = atoi(number.c_str());
        JsonString(row, 0, "artworkUrl100", track.artwork);
    } else {
        size_t albumPos = 0;
        if (JsonValueStart(row, 0, "album", albumPos) && row[albumPos] == '{') {
            const size_t end = row.find('}', albumPos);
            const std::string object = row.substr(albumPos, end - albumPos);
            if (JsonString(object, 0, "title", album)) track.proposal.album = CvJsonUnescape(album);
            JsonString(object, 0, "cover_big", track.artwork);
            if (!JsonString(object, 0, "id", track.albumId))
                JsonNumber(object, 0, "id", track.albumId);
            if (track.albumId.find_first_not_of("0123456789") != std::string::npos) track.albumId.clear();
        }
    }
    return true;
}

static int MetaCatalogRank(const MetaCatalogTrack& track, const std::wstring& title, int dur) {
    const int distance = dur > 1 && track.seconds > 1 ? abs(track.seconds - dur) : 0;
    const int durationRank = dur > 1 ? (track.seconds <= 1 ? 1 : distance <= std::max(12, dur / 12) ? 2 : 0) : 1;
    return durationRank * 64 + (CvCoverTitleExact(track.proposal.title, title) ? 32 : 0) +
           (!track.artwork.empty() ? 16 : 0) + (!track.proposal.year.empty() ? 8 : 0) +
           (track.trackCount > 0 && track.trackCount <= 4 ? 4 : 0);
}

static MetaCatalogTrack MetaFindCatalogTrack(const std::string& json, MetaCatalog catalog,
                                             const std::wstring& artist, const std::wstring& title, int dur) {
    std::vector<std::string> rows;
    JsonArrayObjects(json, catalog == MetaCatalog::Apple ? "results" : "data", rows);
    MetaCatalogTrack best;
    int bestRank = -1;
    const auto baseTitle = MetaCatalogTitle(title);
    for (const auto& row : rows) {
        MetaCatalogTrack track;
        if (!MetaReadCatalogTrack(row, catalog, track) ||
            !CvCoverArtistExact(track.proposal.artist, artist) ||
            !CvCoverTitleExact(MetaCatalogTitle(track.proposal.title), baseTitle)) continue;
        int rank = MetaCatalogRank(track, title, dur);
        if (rank == bestRank &&
            (track.proposal.year.empty() || (!best.proposal.year.empty() &&
             track.proposal.year >= best.proposal.year))) continue;
        if (rank < bestRank) continue;
        best = std::move(track);
        bestRank = rank;
    }
    return best;
}

static bool MxLookupMeta(const std::wstring& artist, const std::wstring& title, const std::wstring& wantedAlbum,
                         std::wstring& album, std::wstring& year) {
    if (title.empty() || g_stop) return false;
    bool got = false;
    std::string js;
    const std::wstring term = artist.empty() ? title : artist + L" " + title;
    if (HttpGet(L"itunes.apple.com", L"/search?term=" + UrlEncode(term) + L"&media=music&entity=song&limit=20", js)) {
        std::vector<std::string> rows;
        JsonArrayObjects(js, "results", rows);
        for (const auto& row : rows) {
            std::string tn, an, cn, rd;
            if (!JsonString(row, 0, "trackName", tn) || !JsonString(row, 0, "artistName", an) ||
                !CvCoverTitleExact(CvJsonUnescape(tn), title) || !CvCoverArtistExact(CvJsonUnescape(an), artist) ||
                !JsonString(row, 0, "collectionName", cn)) continue;
            const auto release = CvJsonUnescape(cn);
            if (MetaTextBad(release) || (!wantedAlbum.empty() && !SameMediaAlbum(release, wantedAlbum))) continue;
            if (JsonString(row, 0, "releaseDate", rd) && CvYearOk(rd)) {
                album = release;
                year = FromUtf8(rd.substr(0, 4));
                return true;
            }
            if (album.empty()) { album = release; got = true; }
        }
    }

    if (!wantedAlbum.empty() || !album.empty() || g_stop) return got;

    if (year.empty() && !CvNoArtist(artist)) {
        js.clear();
        std::wstring q = L"recording:\"" + title + L"\" AND artist:\"" + artist + L"\"";
        if (HttpGet(L"musicbrainz.org", L"/ws/2/recording?fmt=json&limit=10&query=" + UrlEncode(q), js)) {
            const std::string tag = "\"first-release-date\"";
            size_t pos = js.find(tag);
            std::string best;
            while (pos != std::string::npos) {
                std::string rd;
                if (JsonString(js, pos, "first-release-date", rd) && CvYearOk(rd))
                    if (best.empty() || rd.compare(0, 4, best) < 0) best = rd.substr(0, 4);
                pos = js.find(tag, pos + 1);
                if (pos > 60000) break;
            }
            if (!best.empty()) {
                year = FromUtf8(best);
                got = true;
            }
        }
    }
    if (g_stop) return got;

    if (album.empty()) {
        js.clear();
        if (HttpGet(L"theaudiodb.com", L"/api/v1/json/2/searchtrack.php?s=" + UrlEncode(artist) + L"&t=" +
                                         UrlEncode(title), js)) {
            const std::string tag = "\"strTrack\":";
            size_t pos = js.find(tag);
            while (pos != std::string::npos) {
                size_t nx = js.find(tag, pos + 1);
                std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
                std::string tn, an, al;
                if (JsonString(ch, 0, "strTrack", tn) && JsonString(ch, 0, "strAlbum", al) &&
                    CvCoverTitleExact(CvJsonUnescape(tn), title)) {
                    JsonString(ch, 0, "strArtist", an);
                    if (artist.empty() || CvCoverArtistExact(CvJsonUnescape(an), artist)) {
                        std::wstring wa = CvJsonUnescape(al);
                        if (wa.size() > 1) {
                            album = wa;
                            got = true;
                            break;
                        }
                    }
                }
                pos = nx;
            }
        }
    }
    if (g_stop) return got;

    if (album.empty()) {
        js.clear();
        std::wstring q = artist.empty() ? (L"track:\"" + title + L"\"")
                                        : (L"artist:\"" + artist + L"\" track:\"" + title + L"\"");
        if (HttpGet(L"api.deezer.com", L"/search?q=" + UrlEncode(q) + L"&limit=10", js)) {
            const std::string tag = "\"readable\":";
            size_t pos = js.find(tag);
            while (pos != std::string::npos) {
                size_t nx = js.find(tag, pos + 1);
                std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
                std::string tn, an, al;
                if (JsonString(ch, 0, "title", tn) && JsonString(ch, 0, "album", al) &&
                    CvCoverTitleExact(CvJsonUnescape(tn), title)) {
                    JsonString(ch, 0, "name", an);
                    if (artist.empty() || CvCoverArtistExact(CvJsonUnescape(an), artist)) {
                        std::wstring wa = CvJsonUnescape(al);
                        if (wa.size() > 1) {
                            album = wa;
                            got = true;
                            break;
                        }
                    }
                }
                pos = nx;
            }
        }
    }
    if (got)
        Wh_Log(L"Multimedia: ficha de '%s' sin Wikipedia (%s / %s)", title.c_str(), year.c_str(), album.c_str());
    return got;
}

struct MxEntry {
    std::wstring key, album, year;
};
static std::vector<MxEntry> g_mxCache;
static bool g_mxCacheLoaded = false;

static std::wstring MxCachePath() { return CvCacheDir() + L"\\meta.txt"; }

static void MxCacheLoad() {
    if (g_mxCacheLoaded) return;
    g_mxCacheLoaded = true;
    std::vector<BYTE> b;
    if (!CvReadFile(MxCachePath(), b, 256 * 1024)) return;
    std::string txt(b.begin(), b.end());
    size_t p = 0;
    while (p < txt.size() && g_mxCache.size() < 2000) {
        size_t e = txt.find('\n', p);
        if (e == std::string::npos) break;
        std::string line = txt.substr(p, e - p);
        p = e + 1;
        size_t t1 = line.find('\t');
        if (t1 == std::string::npos) continue;
        size_t t2 = line.find('\t', t1 + 1);
        if (t2 == std::string::npos) continue;
        MxEntry me;
        me.key = FromUtf8(line.substr(0, t1));
        me.album = FromUtf8(line.substr(t1 + 1, t2 - t1 - 1));
        me.year = FromUtf8(line.substr(t2 + 1));
        if (!me.key.empty()) g_mxCache.push_back(me);
    }
}

static void MxCacheSave() {
    std::string out;
    for (size_t i = 0; i < g_mxCache.size(); i++) {
        out += ToUtf8(g_mxCache[i].key);
        out += '\t';
        out += ToUtf8(g_mxCache[i].album);
        out += '\t';
        out += ToUtf8(g_mxCache[i].year);
        out += '\n';
    }
    if (!out.empty()) CvWriteFile(MxCachePath(), out.data(), out.size());
}

static SRWLOCK g_mxLock = SRWLOCK_INIT;

static bool MxCacheGet(const std::wstring& key, std::wstring& album, std::wstring& year) {
    SrwGuard lk(&g_mxLock);
    MxCacheLoad();
    for (size_t i = 0; i < g_mxCache.size(); i++) {
        if (g_mxCache[i].key == key) {
            album = g_mxCache[i].album;
            year = g_mxCache[i].year;
            return true;
        }
    }
    return false;
}

static void MxCachePut(const std::wstring& key, const std::wstring& album, const std::wstring& year) {
    SrwGuard lk(&g_mxLock);
    MxCacheLoad();
    for (size_t i = 0; i < g_mxCache.size(); i++) {
        if (g_mxCache[i].key == key) {
            g_mxCache[i].album = album;
            g_mxCache[i].year = year;
            MxCacheSave();
            return;
        }
    }
    MxEntry me;
    me.key = key;
    me.album = album;
    me.year = year;
    g_mxCache.push_back(me);
    if (g_mxCache.size() > 2000) g_mxCache.erase(g_mxCache.begin());
    MxCacheSave();
}

static std::wstring MediaCatalogueKey(const std::wstring& title, const std::wstring& artist,
                                          const std::wstring& wantedAlbum) {
    return L"edition1\x1" + artist + L"\x1" + title + L"\x1" + wantedAlbum;
}

static void MxLookupCached(const std::wstring& title, const std::wstring& artist, const std::wstring& wantedAlbum,
                           std::wstring& album, std::wstring& year) {
    if (title.empty()) return;
    const auto key = MediaCatalogueKey(title, artist, wantedAlbum);
    if (MxCacheGet(key, album, year)) return;
    std::wstring a2, y2;
    if (MxLookupMeta(artist, title, wantedAlbum, a2, y2)) {
        album = a2;
        year = y2;
        MxCachePut(key, a2, y2);
    }

}

static MetaOnlineProposal MetaSearchMusicBrainz(const std::wstring& artist, const std::wstring& title) {
    if (!MbReserveRequest(true)) return {};
    std::string json;
    const std::wstring query = L"recording:\"" + title + L"\" AND artist:\"" + artist + L"\"";
    if (!HttpGet(L"musicbrainz.org", L"/ws/2/recording?fmt=json&limit=10&query=" + UrlEncode(query), json))
        return {};
    std::vector<std::string> recordings;
    JsonArrayObjects(json, "recordings", recordings);
    for (const auto& row : recordings) {
        std::string name;
        if (!JsonString(row, 0, "title", name) ||
            !CvCoverTitleExact(MetaCatalogTitle(CvJsonUnescape(name)), title)) continue;
        std::vector<std::string> credits;
        JsonArrayObjects(row, "artist-credit", credits);
        std::wstring credited;
        for (const auto& credit : credits) {
            std::string part, join;
            if (JsonString(credit, 0, "name", part)) credited += CvJsonUnescape(part);
            if (JsonString(credit, 0, "joinphrase", join)) credited += CvJsonUnescape(join);
        }
        if (!CvCoverArtistExact(credited, artist)) continue;
        MetaOnlineProposal proposal;
        proposal.catalog = MetaCatalog::MusicBrainz;
        proposal.title = CvJsonUnescape(name);
        proposal.artist = credited;
        std::vector<std::string> releases;
        JsonArrayObjects(row, "releases", releases);
        std::string releaseId, releaseDate, releaseTitle;
        for (const auto& release : releases) {
            std::string id, date, album;
            if (!JsonString(release, 0, "id", id) || id.size() != 36 ||
                id.find_first_not_of("0123456789abcdef-") != std::string::npos ||
                !JsonString(release, 0, "title", album) ||
                !JsonString(release, 0, "date", date) || !CvYearOk(date)) continue;
            if (releaseDate.empty() || date < releaseDate) {
                releaseId = id;
                releaseDate = date;
                releaseTitle = album;
            }
        }
        if (!releaseId.empty()) {
            proposal.year = FromUtf8(releaseDate.substr(0, 4));
            proposal.album = CvJsonUnescape(releaseTitle);
            std::string image;
            if (HttpGet(L"coverartarchive.org", L"/release/" + FromUtf8(releaseId) + L"/front-500", image) &&
                image.size() <= (4u << 20)) {
                proposal.cover.assign(image.begin(), image.end());
                if (!CvImageType(proposal.cover)) proposal.cover.clear();
            }
        } else {
            std::string first;
            if (JsonString(row, 0, "first-release-date", first) && CvYearOk(first))
                proposal.year = FromUtf8(first.substr(0, 4));
        }
        return proposal;
    }
    return {};
}

static MetaOnlineProposal MetaSearchCatalogs(const std::wstring& artist, const std::wstring& title, int dur) {
    const auto baseTitle = MetaCatalogTitle(title);
    if (baseTitle.empty()) return {};
    const std::wstring query = UrlEncode(artist + L" " + baseTitle);
    std::string json;
    MetaCatalogTrack best;
    for (MetaCatalog catalog : {MetaCatalog::Apple, MetaCatalog::Deezer}) {
        if (g_stop) return {};
        const bool apple = catalog == MetaCatalog::Apple;
        if (!HttpGet(apple ? L"itunes.apple.com" : L"api.deezer.com",
                     apple ? L"/search?term=" + query + L"&media=music&entity=song&limit=20" :
                             L"/search?q=" + query + L"&limit=20", json)) continue;
        auto track = MetaFindCatalogTrack(json, catalog, artist, title, dur);
        if (track.proposal.title.empty()) continue;
        if (!track.albumId.empty()) {
            std::string details, date;
            if (HttpGet(L"api.deezer.com", L"/album/" + FromUtf8(track.albumId), details) &&
                JsonString(details, 0, "release_date", date) && CvYearOk(date))
                track.proposal.year = FromUtf8(date.substr(0, 4));
        }
        std::string artwork = CvJsonUnescapeUtf8(track.artwork);
        if (!artwork.empty()) {
            const auto size = artwork.find("100x100bb");
            std::string large = artwork;
            if (apple && size != std::string::npos) large.replace(size, 9, "600x600bb");
            if (!CvDownload(large, track.proposal.cover) && large != artwork)
                CvDownload(artwork, track.proposal.cover);
        }
        if (best.proposal.title.empty() ||
            MetaCatalogRank(track, title, dur) + (track.proposal.cover.empty() ? 0 : 16) >
            MetaCatalogRank(best, title, dur) + (best.proposal.cover.empty() ? 0 : 16))
            best = std::move(track);
        if (!best.proposal.cover.empty() && !best.proposal.year.empty() &&
            (dur <= 1 || (best.seconds > 1 && abs(best.seconds - dur) <= std::max(12, dur / 12))))
            return std::move(best.proposal);
    }
    if (best.proposal.title.empty() && !g_stop)
        return MetaSearchMusicBrainz(artist, baseTitle);
    return std::move(best.proposal);
}

static constexpr size_t kCatalogCoverLimit = 4u << 20;
static constexpr size_t kCatalogHeaderLimit = 16384;

static bool DecodeCatalogCache(const std::vector<BYTE>& bytes, MetaOnlineProposal& proposal) {
    std::string fields[6];
    size_t pos = 0;
    const auto limit = std::min(bytes.size(), kCatalogHeaderLimit);
    for (auto& field : fields) {
        if (pos >= limit) return false;
        const auto first = bytes.begin() + pos;
        const auto end = std::find(first, bytes.begin() + limit, '\n');
        if (end == bytes.begin() + limit) return false;
        field.assign(first, end);
        pos = (size_t)(end - bytes.begin()) + 1;
    }
    if (fields[0] != "GCATALOG1" || fields[1].size() != 1 || fields[1][0] < '1' ||
        fields[1][0] > '3' || fields[2].empty() || fields[3].empty()) return false;
    MetaOnlineProposal decoded;
    decoded.catalog = static_cast<MetaCatalog>(fields[1][0] - '0');
    decoded.title = FromUtf8(fields[2]);
    decoded.artist = FromUtf8(fields[3]);
    decoded.album = FromUtf8(fields[4]);
    decoded.year = FromUtf8(fields[5]);
    if (!fields[5].empty() && (fields[5].size() != 4 || !CvYearOk(fields[5]))) return false;
    if (pos < bytes.size()) {
        if (bytes.size() - pos > kCatalogCoverLimit) return false;
        decoded.cover.assign(bytes.begin() + pos, bytes.end());
        if (!CvImageType(decoded.cover)) return false;
    }
    if (decoded.title.empty() || decoded.artist.empty()) return false;
    proposal = std::move(decoded);
    return true;
}

static std::vector<BYTE> EncodeCatalogCache(const MetaOnlineProposal& proposal) {
    auto line = [](const std::wstring& text) {
        auto value = ToUtf8(text);
        for (char& c : value) if (c == '\r' || c == '\n') c = ' ';
        return value;
    };
    const auto header = "GCATALOG1\n" + std::to_string((int)proposal.catalog) + "\n" +
        line(proposal.title) + "\n" + line(proposal.artist) + "\n" +
        line(proposal.album) + "\n" + line(proposal.year) + "\n";
    if (header.size() > kCatalogHeaderLimit || proposal.cover.size() > kCatalogCoverLimit) return {};
    std::vector<BYTE> bytes(header.begin(), header.end());
    bytes.insert(bytes.end(), proposal.cover.begin(), proposal.cover.end());
    return bytes;
}

static MetaOnlineProposal MetaLookupCatalogs(const std::wstring& artist, const std::wstring& title,
                                               int dur, const std::wstring& fileKey) {
    const auto dir = CvCacheDir();
    const auto key = CvStrHash(fileKey + L"\x1" + LowerWs(artist) + L"\x1" + LowerWs(title) +
                               L"\x1" + std::to_wstring(dur));
    const auto path = dir.empty() ? std::wstring() : dir + L"\\catalog-" + std::to_wstring(key) + L".meta";
    MetaOnlineProposal proposal;
    if (!path.empty()) {
        const int age = CvFileAgeHours(path);
        std::vector<BYTE> bytes;
        if (age >= 0 && age < 24 * 30 && CvReadFile(path, bytes, kCatalogHeaderLimit + kCatalogCoverLimit) &&
            DecodeCatalogCache(bytes, proposal)) return proposal;
    }
    proposal = MetaSearchCatalogs(artist, title, dur);
    if (!path.empty() && !proposal.title.empty() && !proposal.artist.empty() && !g_stop) {
        const auto bytes = EncodeCatalogCache(proposal);
        if (!bytes.empty()) CvWriteFile(path, bytes.data(), bytes.size());
    }
    return proposal;
}

struct MetaJob {
    std::wstring title, artist, album;
    unsigned long long track;
};

static DWORD WINAPI MetaThreadProc(LPVOID pv) {
    MetaJob* j = (MetaJob*)pv;
    MxMetaResult* r = new MxMetaResult();
    r->title = j->title;
    r->artist = j->artist;
    r->track = j->track;
    const auto wantedAlbum = std::move(j->album);
    delete j;
    if (!g_stop) MxLookupCached(r->title, r->artist, wantedAlbum, r->album, r->year);

    if (g_stop || (r->album.empty() && r->year.empty()) || !PostUi(WM_APP_MXMETA, 0, (LPARAM)r)) delete r;
    return 0;
}

static void ApplyMediaCatalogue(const std::wstring& album, const std::wstring& year) {
    const auto& known = g.fileMeta.albumOk ? g.fileMeta.album : g.media.album;
    const bool sameEdition = known.empty() || SameMediaAlbum(known, album);
    if (g.media.album.empty() && !g.fileMeta.albumOk && !album.empty()) g.media.album = album;
    if (sameEdition && !g.fileMeta.yearOk && g.media.year.empty() && !year.empty()) g.media.year = year;
    g.cards[CARD_MEDIA].dirty = true;
}

static void OnMxMeta(MxMetaResult* r) {
    if (r->track == g_thumbTrack && g.media.title == r->title && g.media.artist == r->artist)
        ApplyMediaCatalogue(r->album, r->year);
    delete r;
}

// Synchronized lyrics from LRCLIB
struct LyrJob { std::wstring title, artist, album; int dur; };
struct LyrResult { std::wstring key; std::vector<LyricLine> lines; };

static std::wstring LyrUnescape(const std::wstring& in) {
    std::wstring o;
    for (size_t i = 0; i < in.size(); ++i) {
        if (in[i] == L'\\' && i + 5 < in.size() && in[i + 1] == L'u') {
            const std::wstring h = in.substr(i + 2, 4);
            wchar_t* end = nullptr;
            const unsigned long v = wcstoul(h.c_str(), &end, 16);
            if (end && *end == 0) { o += (wchar_t)v; i += 5; continue; }
        }
        o += in[i];
    }
    return o;
}

static void LyrParse(const std::string& lrc, std::vector<LyricLine>& out) {
    size_t p = 0;
    while (p < lrc.size()) {
        size_t e = lrc.find('\n', p);
        if (e == std::string::npos) e = lrc.size();
        std::string ln = lrc.substr(p, e - p);
        p = e + 1;
        if (!ln.empty() && ln.back() == '\r') ln.pop_back();
        std::vector<double> ts;
        size_t q = 0;
        while (q < ln.size() && ln[q] == '[') {
            const size_t r = ln.find(']', q);
            if (r == std::string::npos) break;
            int mm = 0; double ss = 0;
            if (sscanf(ln.c_str() + q + 1, "%d:%lf", &mm, &ss) == 2 &&
                mm >= 0 && mm < 1440 && ss >= 0.0 && ss < 60.0) ts.push_back(mm * 60.0 + ss);
            q = r + 1;
        }
        if (ts.empty()) continue;
        const std::wstring text = Trim(LyrUnescape(FromUtf8(ln.substr(q))));
        for (double tv : ts) out.push_back({tv, text});
    }
    std::stable_sort(out.begin(), out.end(), [](const LyricLine& a, const LyricLine& b) { return a.t < b.t; });
}

static std::wstring LyricsKey(const std::wstring& title, const std::wstring& artist,
                              const std::wstring& album, int duration) {
    return artist + L"\x1" + title + L"\x1" + album + L"\x1" + std::to_wstring(duration);
}

static DWORD WINAPI LyricsThreadProc(LPVOID pv) {
    LyrJob* j = static_cast<LyrJob*>(pv);
    LyrResult* r = new LyrResult();
    r->key = LyricsKey(j->title, j->artist, j->album, j->dur);
    const std::wstring q = L"artist_name=" + UrlEncode(j->artist) + L"&track_name=" + UrlEncode(j->title);
    std::wstring path = L"/api/get?" + q;
    if (!j->album.empty()) path += L"&album_name=" + UrlEncode(j->album);
    path += L"&duration=" + std::to_wstring(j->dur);
    std::string js, lrc;
    bool got = !g_stop && HttpGet(L"lrclib.net", path, js) && JsonString(js, 0, "syncedLyrics", lrc) && !lrc.empty();

    if (got) LyrParse(lrc, r->lines);
    delete j;
    if (g_stop || r->lines.empty() || !PostUi(WM_APP_LYRICS, 0, (LPARAM)r)) delete r;
    return 0;
}

// Fetch lyrics independently so lookup latency does not delay playback UI.
static void StartLyricsThread(const std::wstring& title, const std::wstring& artist,
                              const std::wstring& album, int dur) {
    if (!g.mediaLyrics || title.empty() || artist.empty() || dur <= 1 || CvIsBrowserSession()) return;
    const std::wstring key = LyricsKey(title, artist, album, dur);
    if (key == g_lyrAsked) return;
    g_lyrAsked = key;
    LyrJob* j = new LyrJob{title, artist, album, dur};
    if (!StartBgThread(LyricsThreadProc, j)) { delete j; g_lyrAsked.clear(); }
}

static void OnLyrics(LyrResult* r) {
    if (r->key == g_lyrAsked) {
        g_lyrics = std::move(r->lines);
        g_lyrKey = r->key;
        g.cards[CARD_MEDIA].dirty = true;
    }
    delete r;
}

// Resolve catalog details independently of the player and tag editor.
static void StartMetaThread(const std::wstring& title, const std::wstring& artist) {
    if (title.empty()) return;
    const std::wstring known = g.fileMeta.albumOk ? g.fileMeta.album : g_lastPropAlbum;
    const auto key = MediaCatalogueKey(title, artist, known);
    const auto trackKey = std::to_wstring(g_thumbTrack) + L"\x1" + key;
    if (g_mxLastQuery == trackKey) return;
    std::wstring album, year;
    if (MxCacheGet(key, album, year)) {
        ApplyMediaCatalogue(album, year);
        g_mxLastQuery = trackKey;
        return;
    }
    auto* job = new MetaJob{title, artist, known, g_thumbTrack};
    if (StartBgThread(MetaThreadProc, job)) g_mxLastQuery = trackKey;
    else delete job;
}

static std::wstring FriendlyPlayer(const std::wstring& sid) {
    std::wstring a = sid;
    size_t bang = a.find(L'!');
    if (bang != std::wstring::npos) a = a.substr(0, bang);
    size_t us = a.find(L'_');
    if (us != std::wstring::npos) a = a.substr(0, us);
    size_t dot = a.rfind(L'.');
    if (dot != std::wstring::npos) {
        std::wstring ext = LowerWs(a.substr(dot + 1));
        if (ext == L"exe") a = a.substr(0, dot);
        else a = a.substr(dot + 1);
    }
    std::wstring k = LowerWs(a);
    struct P { const wchar_t* k; const wchar_t* v; };
    static const P map[] = {
        {L"spotify", L"Spotify"}, {L"chrome", L"Chrome"}, {L"msedge", L"Edge"}, {L"firefox", L"Firefox"},
        {L"brave", L"Brave"}, {L"opera", L"Opera"}, {L"vlc", L"VLC"}, {L"foobar2000", L"foobar2000"},
        {L"aimp", L"AIMP"}, {L"musicbee", L"MusicBee"},
        {L"zunemusic", L"Media Player"}, {L"mediaplayer", L"Media Player"}, {L"applemusic", L"Apple Music"},
        {L"applemusicwin", L"Apple Music"}, {L"itunes", L"iTunes"}, {L"tidal", L"TIDAL"}, {L"deezer", L"Deezer"},
        {L"winamp", L"Winamp"}, {L"mpc-hc64", L"MPC-HC"}, {L"mpc-hc", L"MPC-HC"}, {L"potplayermini64", L"PotPlayer"},
    };
    for (size_t i = 0; i < sizeof(map) / sizeof(map[0]); i++)
        if (k == map[i].k) return map[i].v;
    if (!a.empty() && iswlower(a[0])) a[0] = (wchar_t)towupper(a[0]);
    return a;
}

static void ShowNotice(const std::wstring& title, const std::wstring& text);

static void MediaActionRejected() {
    ShowNotice(TR(L"Multimedia", L"Media", L"Multimèdia"),
               TR(L"El reproductor no confirmó la orden.", L"The player did not confirm the command.",
                  L"El reproductor no ha confirmat l’ordre."));
}

using MediaPlayback = GlobalSystemMediaTransportControlsSessionPlaybackStatus;

struct MediaProbeResult {
    GlobalSystemMediaTransportControlsSession session{nullptr};
    std::wstring app;
    ULONGLONG sampled = 0;
    bool appUnique = false;
    bool sessionExists = true, reliable = false;
    MediaPlayback playback = MediaPlayback::Closed;
    bool previous = false, next = false, toggle = false, play = false, pause = false, seek = false;
    int64_t position = 0, start = 0, end = 0, minSeek = 0, maxSeek = 0;
    int64_t updated = 0;
    double rate = 1.0;
    std::vector<GlobalSystemMediaTransportControlsSession> choices;
    bool shuffle = false, canShuffle = false, canRepeat = false;
    int repeat = 0;
};

static bool MediaProbeIsActive(const MediaProbeResult& probe) {
    return probe.session && probe.playback != MediaPlayback::Closed &&
           (g_mediaKeepStopped || probe.playback != MediaPlayback::Stopped);
}

static SRWLOCK g_mediaProbeLock = SRWLOCK_INIT;
static MediaProbeResult g_mediaProbe;
static GlobalSystemMediaTransportControlsSession g_preferredMediaSession{nullptr};
static int g_mediaProbeMode = 0;
static unsigned g_mediaProbeEpoch = 0;
static HANDLE g_mediaProbeThread = nullptr, g_mediaProbeWake = nullptr, g_mediaProbeStop = nullptr;
static bool g_mediaProbeCanDetach = false;

static void WakeMediaProbe() {
    AcquireSRWLockShared(&g_mediaProbeLock);
    if (g_mediaProbeWake && g_mediaProbeMode > 0 && !g_stop) SetEvent(g_mediaProbeWake);
    ReleaseSRWLockShared(&g_mediaProbeLock);
}

struct MediaProbeRun {
    HMODULE module = nullptr;
    HANDLE stop = nullptr, wake = nullptr;
};

// Rank sessions and collect a coherent snapshot for playback controls and timeline.
static MediaProbeResult ReadMediaProbe(const GlobalSystemMediaTransportControlsSessionManager& manager,
                                       const GlobalSystemMediaTransportControlsSession& previous, bool sessionsOnly,
                                       const GlobalSystemMediaTransportControlsSession& preferred) {
    MediaProbeResult result;
    result.sampled = GetTickCount64();
    auto all = manager.GetSessions();
    result.sessionExists = !all;
    result.reliable = !!all;
    auto current = sessionsOnly ? GlobalSystemMediaTransportControlsSession{nullptr} : manager.GetCurrentSession();
    GlobalSystemMediaTransportControlsSession playing{nullptr}, chosen{nullptr};
    if (all) {
        for (const auto& session : all) {
            try {
                const auto info = session.GetPlaybackInfo();
                if (!info) { result.sessionExists = true; result.reliable = false; continue; }
                const auto status = info.PlaybackStatus();
                if (status != MediaPlayback::Closed && status != MediaPlayback::Stopped)
                    result.sessionExists = true;
                if (!sessionsOnly && status != MediaPlayback::Closed &&
                    (status != MediaPlayback::Stopped || g_mediaKeepStopped)) {
                    result.choices.push_back(session);
                    if (session == preferred) chosen = session;
                }
                if (!sessionsOnly && status == MediaPlayback::Playing &&
                    (!playing || session == current || session == previous) && (!previous || playing != previous))
                    playing = session;
            } catch (...) { result.sessionExists = true; result.reliable = false; }
        }
    }
    if (sessionsOnly) return result;
    result.session = chosen ? chosen : (playing ? playing : current);
    if (!result.session) return result;

    const auto& session = result.session;
    GlobalSystemMediaTransportControlsSessionPlaybackInfo info{nullptr};
    try {
        info = session.GetPlaybackInfo();
        if (info) result.playback = info.PlaybackStatus();
    } catch (...) { info = nullptr; }
    if (!info) {
        result.sessionExists = true;
        result.reliable = false;
        result.session = nullptr;
        return result;
    }
    if (result.playback != MediaPlayback::Closed && result.playback != MediaPlayback::Stopped)
        result.sessionExists = true;
    try { result.app = session.SourceAppUserModelId().c_str(); } catch (...) {}
    int matching = 0;
    if (all && !result.app.empty()) {
        for (const auto& entry : all) {
            try { if (_wcsicmp(entry.SourceAppUserModelId().c_str(), result.app.c_str()) == 0) ++matching; }
            catch (...) { matching = -1; break; }
        }
    }
    result.appUnique = matching == 1;
    try { if (const auto controls = info.Controls()) {
        result.previous = controls.IsPreviousEnabled();
        result.next = controls.IsNextEnabled();
        result.toggle = controls.IsPlayPauseToggleEnabled();
        result.play = controls.IsPlayEnabled();
        result.pause = controls.IsPauseEnabled();
        result.seek = controls.IsPlaybackPositionEnabled();
        result.canShuffle = controls.IsShuffleEnabled();
        result.canRepeat = controls.IsRepeatEnabled();
    } } catch (...) {}
    try { if (const auto timeline = session.GetTimelineProperties()) {
        result.position = timeline.Position().count();
        result.start = timeline.StartTime().count();
        result.end = timeline.EndTime().count();
        result.minSeek = timeline.MinSeekTime().count();
        result.maxSeek = timeline.MaxSeekTime().count();
        result.updated = timeline.LastUpdatedTime().time_since_epoch().count();
    } } catch (...) { result.seek = false; }
    try { if (const auto sh = info.IsShuffleActive()) result.shuffle = sh.Value(); } catch (...) {}
    try {
        if (const auto rp = info.AutoRepeatMode()) {
            const auto v = rp.Value();
            result.repeat = v == winrt::Windows::Media::MediaPlaybackAutoRepeatMode::Track ? 1 :
                            v == winrt::Windows::Media::MediaPlaybackAutoRepeatMode::List ? 2 : 0;
        }
    } catch (...) {}
    try {
        if (const auto r = info.PlaybackRate()) {
            const double v = r.Value();
            if (v > 0.05 && v < 8.0) result.rate = v;
        }
    } catch (...) {}
    return result;
}

// Own the WinRT manager and event subscriptions on the worker thread.
static DWORD RunMediaProbe(const MediaProbeRun& run) {
    try { winrt::init_apartment(winrt::apartment_type::multi_threaded); }
    catch (...) { return 0; }
    using Manager = GlobalSystemMediaTransportControlsSessionManager;
    using Status = winrt::Windows::Foundation::AsyncStatus;
    Manager manager{nullptr};
    winrt::Windows::Foundation::IAsyncOperation<Manager> request{nullptr};
    GlobalSystemMediaTransportControlsSession previous{nullptr};
    Manager::SessionsChanged_revoker sessionsEvent;
    Manager::CurrentSessionChanged_revoker currentEvent;
    using Session = GlobalSystemMediaTransportControlsSession;
    Session observed{nullptr};
    Session::PlaybackInfoChanged_revoker playbackEvent;
    Session::TimelinePropertiesChanged_revoker timelineEvent;
    auto resetObserver = [&]() {
        playbackEvent.revoke();
        timelineEvent.revoke();
        observed = nullptr;
    };
    auto resetManager = [&]() {
        resetObserver();
        sessionsEvent.revoke();
        currentEvent.revoke();
        manager = nullptr;
    };
    HANDLE events[] = {run.stop, run.wake};
    ULONGLONG started = 0, retry = 0;
    for (;;) {
        AcquireSRWLockShared(&g_mediaProbeLock);
        const int mode = g_mediaProbeMode;
        const unsigned epoch = g_mediaProbeEpoch;
        const auto preferred = g_preferredMediaSession;
        ReleaseSRWLockShared(&g_mediaProbeLock);
        if (mode < 0 || g_stop || WaitForSingleObject(run.stop, 0) == WAIT_OBJECT_0) break;
        if (!mode) {
            previous = nullptr;
            CancelMediaOperation(request);
            resetManager();
            retry = 0;
            if (WaitForMultipleObjects(2, events, FALSE, INFINITE) == WAIT_OBJECT_0) break;
            continue;
        }

        MediaProbeResult result;
        try {
            const ULONGLONG now = GetTickCount64();
            if (!manager && now >= retry) {
                if (!request) {
                    request = Manager::RequestAsync();
                    started = now;
                }
                const auto status = request.Status();
                if (status == Status::Completed) {
                    manager = request.GetResults();
                    request = nullptr;
                    if (manager) {
                        try { sessionsEvent = manager.SessionsChanged(winrt::auto_revoke,
                                [](auto&&, auto&&) { WakeMediaProbe(); }); } catch (...) {}
                        try { currentEvent = manager.CurrentSessionChanged(winrt::auto_revoke,
                                [](auto&&, auto&&) { WakeMediaProbe(); }); } catch (...) {}
                    }
                } else if (status != Status::Started || now - started >= 3000) {
                    CancelMediaOperation(request);
                    retry = now + 5000;
                }
            }
            if (manager) result = ReadMediaProbe(manager, previous, mode == 1, preferred);
            if (result.session != observed && (result.session || result.reliable)) {
                resetObserver();
                observed = result.session;
                if (observed) {
                    try { playbackEvent = observed.PlaybackInfoChanged(winrt::auto_revoke,
                            [](auto&&, auto&&) { WakeMediaProbe(); }); } catch (...) {}
                    try { timelineEvent = observed.TimelinePropertiesChanged(winrt::auto_revoke,
                            [](auto&&, auto&&) { WakeMediaProbe(); }); } catch (...) {}
                }
            }
        } catch (...) {
            CancelMediaOperation(request);
            resetManager();
            retry = GetTickCount64() + 1000;
        }
        if (result.sampled && GetTickCount64() - result.sampled > 1500) result = {};
        if (result.session || result.reliable) previous = result.session;
        const DWORD interval = !result.reliable || result.playback == MediaPlayback::Playing ? 350 : 1400;
        {
            SrwGuard guard(&g_mediaProbeLock);
            if (epoch == g_mediaProbeEpoch && !g_stop && WaitForSingleObject(run.stop, 0) != WAIT_OBJECT_0) {
                const bool closed = result.reliable && MediaProbeIsActive(g_mediaProbe) && !MediaProbeIsActive(result);
                Mp3MediaSessionReport(result.sessionExists);
                if (mode == 2 && result.reliable && preferred && result.session != preferred)
                    g_preferredMediaSession = nullptr;
                g_mediaProbe = std::move(result);
                if (closed) PostUi(WM_APP_MEDIA_CLOSED, 0, 0);
            }
        }
        if (WaitForMultipleObjects(2, events, FALSE, interval) == WAIT_OBJECT_0) break;
    }
    CancelMediaOperation(request);
    previous = nullptr;
    resetManager();
    winrt::uninit_apartment();
    return 0;
}

static DWORD WINAPI MediaProbeThread(LPVOID context) {
    auto* run = static_cast<MediaProbeRun*>(context);
    const DWORD code = RunMediaProbe(*run);
    CloseHandle(run->stop);
    CloseHandle(run->wake);
    const HMODULE module = run->module;
    delete run;
    if (module) FreeLibraryAndExitThread(module, code);
    return code;
}

static HANDLE StartMediaProbeThread() {
    auto* run = new (std::nothrow) MediaProbeRun();
    if (!run) return nullptr;
    const HANDLE process = GetCurrentProcess();
    HANDLE thread = nullptr;
    GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
                       reinterpret_cast<LPCWSTR>(&g_mediaProbeLock), &run->module);
    g_mediaProbeCanDetach = run->module != nullptr;
    if (DuplicateHandle(process, g_mediaProbeStop, process, &run->stop, 0, FALSE, DUPLICATE_SAME_ACCESS) &&
        DuplicateHandle(process, g_mediaProbeWake, process, &run->wake, 0, FALSE, DUPLICATE_SAME_ACCESS)) {
        thread = CreateThread(nullptr, 0, MediaProbeThread, run, 0, nullptr);
    }
    if (!thread) {
        if (run->stop) CloseHandle(run->stop);
        if (run->wake) CloseHandle(run->wake);
        if (run->module) FreeLibrary(run->module);
        delete run;
    }
    return thread;
}

static void SetMediaProbeMode(int mode) {
    if (g_mediaProbeThread && WaitForSingleObject(g_mediaProbeThread, 0) == WAIT_OBJECT_0) {
        CloseHandle(g_mediaProbeThread);
        g_mediaProbeThread = nullptr;
    }
    {
        SrwGuard guard(&g_mediaProbeLock);
        if (mode > 0 && !g_mediaProbeWake) g_mediaProbeWake = CreateEventW(nullptr, FALSE, FALSE, nullptr);
        if (mode > 0 && !g_mediaProbeStop) g_mediaProbeStop = CreateEventW(nullptr, TRUE, FALSE, nullptr);
        if (g_mediaProbeMode != mode) {
            g_mediaProbeMode = mode;
            ++g_mediaProbeEpoch;
            g_mediaProbe = {};
            if (mode < 0) g_preferredMediaSession = nullptr;
            Mp3MediaSessionReport(true);
            if (g_mediaProbeWake) SetEvent(g_mediaProbeWake);
        }
    }
    if (mode > 0 && g_mediaProbeWake && g_mediaProbeStop && !g_mediaProbeThread)
        g_mediaProbeThread = StartMediaProbeThread();
}

static void StopMediaProbe() {
    SetMediaProbeMode(-1);
    if (g_mediaProbeStop) SetEvent(g_mediaProbeStop);
    if (g_mediaProbeThread) {
        if (WaitForSingleObject(g_mediaProbeThread, g_mediaProbeCanDetach ? 3000 : INFINITE) == WAIT_TIMEOUT)
            Wh_Log(L"Media: the probe will finish in the background and holds a module reference");
        CloseHandle(g_mediaProbeThread);
        g_mediaProbeThread = nullptr;
    }
    SrwGuard guard(&g_mediaProbeLock);
    if (g_mediaProbeWake) CloseHandle(g_mediaProbeWake);
    if (g_mediaProbeStop) CloseHandle(g_mediaProbeStop);
    g_mediaProbeWake = g_mediaProbeStop = nullptr;
}

static double MediaEstimatedPosition(int64_t position, int64_t start, int64_t updated,
                                     int64_t utc, double rate, bool playing) {
    const double lag = playing && updated > 0 ?
        std::clamp(((double)utc - (double)updated) / 10000000.0, 0.0, 3600.0) : 0.0;
    return std::max(0.0, ((double)position - (double)start) / 10000000.0 + lag * rate);
}

static void SampleMedia(bool sessionsOnly = false) {
    SetMediaProbeMode(sessionsOnly ? 1 : 2);
    if (sessionsOnly) return;
    try {
        if (!g_winrtInit) {
            try {
                winrt::init_apartment(winrt::apartment_type::multi_threaded);
                g_winrtOwnApartment = true;
            } catch (const winrt::hresult_error& e) {
                if (e.code() != RPC_E_CHANGED_MODE) throw;
            }
            g_winrtInit = true;
        }
        MediaProbeResult probe;
        {
            SrwGuard guard(&g_mediaProbeLock);
            probe = g_mediaProbe;
        }
        const ULONGLONG nowPoll = GetTickCount64();
        if (probe.sampled && nowPoll - probe.sampled > 2400) probe = {};
        auto s = probe.session;
        using Status = winrt::Windows::Foundation::AsyncStatus;
        static ULONGLONG s_propsRetry = 0;
        if (s) g_mediaLostSince = 0;
        if (!s && g.media.valid && !probe.reliable) {

            if (!g_mediaLostSince) g_mediaLostSince = nowPoll;
            if (nowPoll - g_mediaLostSince < 2500) return;
        }
        if (!s) {
            g_mediaLostSince = 0;

            ReleaseMediaSession();
#if GH_HAVE_THUMB
            g_thumbRef = nullptr;
#endif
            if (g.media.valid || g.thumbOk) ClearThumb();
            g.media = {};
            g.fileMeta = {};
            InterlockedExchange(&g_mediaDurSec, 0);
            return;
        }
        const std::wstring& sid = probe.app;
        if (!g_sess || s != g_sess) {
            ReleaseMediaSession();
            g_sess = s;
            g_sessId = sid;
            s_propsRetry = 0;
            ++g_metaGen;
            ClearThumb();
            g.media = {};
            g.fileMeta = {};
            if (g_metaWin) MetaPanelClose();
            g_mediaIdWant.clear();
            InterlockedExchange(&g_mediaDurSec, 0);
            g.media.player = FriendlyPlayer(sid);
            try {
                g_propTok = s.MediaPropertiesChanged([](auto&&, auto&&) {
                    InterlockedExchange64(&g_propsEventAt, (LONG64)GetTickCount64());
                    InterlockedExchange(&g_propsFromTimer, 0);
                    InterlockedExchange(&g_propsDirty, 1);
                });
            } catch (...) {}
            InterlockedExchange(&g_propsDirty, 1);
        }
        AudioSetTarget(probe.appUnique ? sid : std::wstring());
        {

            ULONGLONG nowP = GetTickCount64();
            if (nowP - g_propsAtGlobal > 15000) {
                g_propsAtGlobal = nowP;
                if (InterlockedCompareExchange(&g_propsDirty, 1, 0) == 0) InterlockedExchange(&g_propsFromTimer, 1);
            }
        }
        const auto propsAt = (ULONGLONG)InterlockedCompareExchange64(&g_propsEventAt, 0, 0);
        const bool propsDue = nowPoll >= propsAt + 180 || nowPoll >= g_mediaPropsStarted + 400;
        if (!g_mediaProperties && propsDue && nowPoll >= s_propsRetry && InterlockedExchange(&g_propsDirty, 0)) {
            g_mediaPropsFromTimer = InterlockedExchange(&g_propsFromTimer, 0) != 0;
            g_mediaPropsStarted = nowPoll;
            g_mediaProperties = s.TryGetMediaPropertiesAsync();
        }
        bool trackChanged = false;
        if (g_mediaProperties && (g_mediaProperties.Status() != Status::Started ||
                                  nowPoll - g_mediaPropsStarted >= 2500)) {
            auto opProps = g_mediaProperties;
            g_mediaProperties = nullptr;
            const bool fromTimer = g_mediaPropsFromTimer;
            try {
                if (opProps.Status() != Status::Completed) {
                    CancelMediaOperation(opProps);
                    s_propsRetry = nowPoll + 5000;
                    throw winrt::hresult_error(E_PENDING);
                }
                auto props = opProps.GetResults();
                std::wstring nt = std::wstring(props.Title().c_str());
                std::wstring na = std::wstring(props.Artist().c_str());

                if (nt.find(L" - ") != std::wstring::npos) {
                    CvParsed pn = CvParseName(nt);
                    if (pn.two && CvNoArtist(na) && !CvIsBrowserSession()) CvOrderKick(pn.first, pn.second);
                    if (!pn.artist.empty() && !pn.title.empty()) {

                        if (CvNoArtist(na) || CvSim(na, pn.artist) >= 0.80f) {
                            na = pn.artist;
                            nt = pn.title;
                        }
                    }
                } else if (CvNoArtist(na)) {
                    CvParsed pn = CvParseName(nt);
                    if (!pn.artist.empty() && !pn.title.empty()) {
                        na = pn.artist;
                        nt = pn.title;
                    }
                }

                const std::wstring rawTitle = props.Title().c_str();
                const bool drivePath = rawTitle.size() > 3 && rawTitle[1] == L':' &&
                                       rawTitle[2] == L'\\';
                const bool networkPath = rawTitle.rfind(L"\\\\", 0) == 0;
                const std::wstring reportedPath = (drivePath || networkPath) && HasAudioExt(LowerWs(rawTitle)) ? rawTitle : std::wstring();
                std::wstring file = rawTitle;
                const size_t slash = file.find_last_of(L"\\/");
                if (slash != std::wstring::npos) file = file.substr(slash + 1);
                const std::wstring lowFile = LowerWs(file);
                if (!HasAudioExt(lowFile)) file.clear();
                std::wstring parsedArtist, parsedTitle;
                const bool parsed = !file.empty() && MxParseName(file, parsedArtist, parsedTitle) &&
                                    !parsedTitle.empty() && !parsedArtist.empty();
                if (parsed) {
                    na = std::move(parsedArtist);
                    nt = std::move(parsedTitle);
                }
                const std::wstring propAlbum = props.AlbumTitle().c_str();
                const uint32_t propTrack = (uint32_t)props.TrackNumber();
                const bool albumChanged = !g.media.title.empty() &&
                    (propAlbum != g_lastPropAlbum || propTrack != g_lastPropTrack);
                g_lastPropAlbum = propAlbum;
                g_lastPropTrack = propTrack;
                const bool changed = albumChanged || nt != g.media.title || na != g.media.artist ||
                    _wcsicmp(reportedPath.c_str(), g_reportedMediaPath.c_str()) != 0;
                g_reportedMediaPath = reportedPath;
                if (changed) {
                    g_mediaFileDuration = 0;
                    g.media.dur = g.media.pos = 0;
                    g.media.album = propAlbum;
                    g.media.year.clear();
                    g_mediaLast = 0;
                    g_mediaSeekUntil = 0;
                    ++g_metaGen;
                    g_lyrKey.clear();
                    g_lyrAsked.clear();
                    g_lyrics.clear();
                    g.media.path = reportedPath;
                    g.media.file = file;
                    g.media.id = CvFileId();
                    if (!reportedPath.empty()) CvFileIdOf(reportedPath, g.media.id);
                    g_mediaIdWant = reportedPath.empty() ? std::wstring() : CvFileIdStr(reportedPath);
                }
                g.media.nameParsed = parsed;
                g.media.title = nt;
                g.media.artist = na;
#if GH_HAVE_THUMB
                if (changed) {
                    g.fileMeta = FileMeta();
                    InterlockedExchange(&g_embedLocked, 0);
                    g_thumbFileUsed.clear();
                    g_thumbRetry = 0;

                    ClearThumb();
                }

                if (!fromTimer || changed || (!g.thumbOk && g_thumbRetry < 4)) {
                    if (fromTimer && !changed) g_thumbRetry++;
                    g_thumbRef = props.Thumbnail();
                    StartThumbThread();
                }

                if (changed || g.media.album.empty() || g.media.year.empty()) StartMetaThread(nt, na);

                trackChanged = changed;
                if (trackChanged && g_metaWin) MetaPanelClose();
#else
                (void)changed;
                (void)fromTimer;
#endif
            } catch (...) {
                InterlockedExchange(&g_propsDirty, 1);
            }
        }
        MxRefreshTagsOk(g.media.artist, g.media.title);
        const auto pbs = probe.playback;
        g.media.playing = pbs == MediaPlayback::Playing;
        g.media.paused = pbs == MediaPlayback::Paused;
        g.media.loading = pbs == MediaPlayback::Opened || pbs == MediaPlayback::Changing;
        g.media.canPrevious = probe.previous;
        g.media.canNext = probe.next;
        g.media.canToggle = probe.toggle;
        g.media.canPlay = probe.play;
        g.media.canPause = probe.pause;
        g.media.shuffle = probe.shuffle;
        g.media.repeat = probe.repeat;
        g.media.canShuffle = probe.canShuffle;
        g.media.canRepeat = probe.canRepeat;
        if (g_mediaAction && (g_mediaAction.Status() != Status::Started || nowPoll - g_mediaActionStarted >= 3000)) {
            auto action = g_mediaAction;
            g_mediaAction = nullptr;
            try {
                if (action.Status() != Status::Completed) {
                    CancelMediaOperation(action);
                    MediaActionRejected();
                } else if (!action.GetResults()) {
                    const bool reached = g_mediaActionCmd == 1 && g_expectedPlaying >= 0 &&
                                         g.media.playing == (g_expectedPlaying != 0);
                    if (!reached) {
                        g_mediaSeekUntil = 0;
                        MediaActionRejected();
                    }
                }
            } catch (...) { g_mediaSeekUntil = 0; MediaActionRejected(); }
            g_expectedPlaying = -1;
            g_mediaActionCmd = -1;
        }
        const double dur = (double)(probe.end - probe.start) / 10000000.0;
        g_mediaSeekStart = probe.start;
        g_mediaSeekEnd = probe.end;
        g_mediaSeekMin = std::max(probe.start, probe.minSeek);
        g_mediaSeekMax = std::min(probe.end, probe.maxSeek);
        ULONGLONG now = GetTickCount64();
        FILETIME ft{};
        GetSystemTimeAsFileTime(&ft);
        const int64_t utc = (int64_t)((uint64_t)ft.dwHighDateTime << 32 | ft.dwLowDateTime);
        const double est = MediaEstimatedPosition(probe.position, probe.start, probe.updated,
                                                   utc, probe.rate, g.media.playing);
        const double elapsed = g_mediaLast ? (double)(now - g_mediaLast) / 1000.0 : 0.0;
        const double predicted = g.media.pos + (g.media.playing ? elapsed * probe.rate : 0.0);
        if (now < g_mediaSeekUntil && std::fabs(est - g_mediaSeekTarget) > 1.5) {
            g.media.pos = predicted;
        } else {
            g_mediaSeekUntil = 0;
            const double error = est - predicted;
            g.media.pos = !g_mediaLast || !g.media.playing || probe.rate != g_mediaLastRate ||
                          std::fabs(error) > 1.5 ? est : predicted + error * 0.18;
        }
        g.media.pos = std::max(0.0, g.media.pos);
        g_mediaLastRate = probe.rate;
        g_mediaLast = now;
        g.media.dur = dur > 1.0 ? dur : (double)g_mediaFileDuration;
        g.media.canSeek = probe.seek && dur > 1.0 && !g.media.loading && g_mediaSeekMax > g_mediaSeekMin;
        InterlockedExchange(&g_mediaDurSec, (LONG)(g.media.dur + 0.5));
        if (g.media.dur > 0.0 && g.media.pos > g.media.dur) g.media.pos = g.media.dur;
        g.media.valid = MediaProbeIsActive(probe);
        if (g.media.valid) StartLyricsThread(g.media.title, g.media.artist, g_lastPropAlbum, (int)(g.media.dur + 0.5));
        if (g.media.valid && trackChanged) MetaPanelKick();
    } catch (...) {
        InterlockedExchange(&g_propsDirty, 1);
    }
}
#endif  // GH_HAVE_WINRT

#else
static void SampleMedia(bool = false) {
    Mp3MediaSessionReport(true);
    g.media = {};
}
static void ShutdownMedia() {}
static void SetMediaProbeMode(int) { Mp3MediaSessionReport(true); }
static void StartThumbThread() {}
static void StartMetaThread(const std::wstring&, const std::wstring&) {}
#endif

static bool SetClipboardText(const std::wstring& txt) {
    if (!OpenClipboard(g.msgWin)) return false;
    bool ok = false;
    EmptyClipboard();
    size_t bytes = (txt.size() + 1) * sizeof(wchar_t);
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, bytes);
    if (hg) {
        void* mp = GlobalLock(hg);
        if (mp) {
            memcpy(mp, txt.c_str(), bytes);
            GlobalUnlock(hg);
            ok = SetClipboardData(CF_UNICODETEXT, hg) != nullptr;
        }
        if (!ok) GlobalFree(hg);
    }
    CloseClipboard();
    return ok;
}

static void CopyMediaText() {
    if (g.media.title.empty()) return;
    const std::wstring& title = g.fileMeta.ok && g.fileMeta.titleOk ? g.fileMeta.title : g.media.title;
    const std::wstring& artist = g.fileMeta.ok && g.fileMeta.artistOk ? g.fileMeta.artist : g.media.artist;
    std::wstring txt = artist.empty() ? title : artist + L" - " + title;
    if (SetClipboardText(txt)) {
        g.copiedUntil = GetTickCount64() + 1500;
        g.cards[CARD_MEDIA].dirty = true;
    }
}

// Use the displayed session's reported controls to enable transport operations.
static bool MediaCanCommand(const MediaInfo& media, int cmd) {
    if (!media.valid) return false;
    if (cmd == 0) return media.canPrevious;
    if (cmd == 2) return media.canNext;
    return media.canToggle || (media.playing ? media.canPause : media.canPlay);
}

#if GH_HAVE_WINRT
static int64_t MediaSeekPosition(float frac) {
    const double fraction = std::clamp(static_cast<double>(frac), 0.0, 1.0);
    const auto position = g_mediaSeekStart + static_cast<int64_t>((g_mediaSeekEnd - g_mediaSeekStart) * fraction);
    return std::clamp(position, g_mediaSeekMin, g_mediaSeekMax);
}
#endif

static double MediaPreviewSeconds(float frac) {
#if GH_HAVE_WINRT
    return (double)(MediaSeekPosition(frac) - g_mediaSeekStart) / 10000000.0;
#else
    (void)frac;
    return 0.0;
#endif
}

static void MediaSeek(float frac) {
#if GH_HAVE_WINRT
    if (!g_sess || !g.media.valid || !g.media.canSeek) return;
    try {
        CancelMediaOperation(g_mediaAction);
        const int64_t target = MediaSeekPosition(frac);
        g_mediaAction = g_sess.TryChangePlaybackPositionAsync(target);
        g_mediaActionCmd = 3;
        g_mediaActionStarted = GetTickCount64();
        g_mediaSeekTarget = (double)(target - g_mediaSeekStart) / 10000000.0;
        g.media.pos = g_mediaSeekTarget;
        g_mediaSeekUntil = g_mediaActionStarted + 2000;
        g_mediaLast = g_mediaActionStarted;
    } catch (...) { MediaActionRejected(); }
#else
    (void)frac;
#endif
}

static void MediaCommand(int cmd) {
#if GH_HAVE_WINRT
    if (!g_sess || !MediaCanCommand(g.media, cmd)) return;
    try {
        CancelMediaOperation(g_mediaAction);
        g_mediaActionCmd = (cmd == 0 || cmd == 2) ? cmd : 1;
        g_expectedPlaying = cmd == 1 ? (g.media.playing ? 0 : 1) : -1;
        if (cmd == 0) g_mediaAction = g_sess.TrySkipPreviousAsync();
        else if (cmd == 2) g_mediaAction = g_sess.TrySkipNextAsync();
        else if (g.media.canToggle) g_mediaAction = g_sess.TryTogglePlayPauseAsync();
        else if (g.media.playing) g_mediaAction = g_sess.TryPauseAsync();
        else g_mediaAction = g_sess.TryPlayAsync();
        g_mediaActionStarted = GetTickCount64();
        g_mediaPressed = cmd;
        g_mediaPressedUntil = g_mediaActionStarted + 500;
    } catch (...) { MediaActionRejected(); }
#else
    (void)cmd;
#endif
}

static int MediaSessionCount() {
#if GH_HAVE_WINRT
    SrwGuard guard(&g_mediaProbeLock);
    return (int)g_mediaProbe.choices.size();
#else
    return 0;
#endif
}

static void MediaCycleSession(int direction = 1) {
#if GH_HAVE_WINRT
    {
        SrwGuard guard(&g_mediaProbeLock);
        const auto& choices = g_mediaProbe.choices;
        const size_t count = choices.size();
        if (count < 2) return;
        const auto current = std::find(choices.begin(), choices.end(), g_mediaProbe.session);
        const size_t index = (size_t)(current - choices.begin());
        const size_t next = index == count ? 0 : (index + (direction > 0 ? 1 : count - 1)) % count;
        g_preferredMediaSession = choices[next];
        ++g_mediaProbeEpoch;
    }
    WakeMediaProbe();
#else
    (void)direction;
#endif
}

static void MediaToggleShuffle() {
#if GH_HAVE_WINRT
    if (!g_sess || !g.media.valid || !g.media.canShuffle) return;
    try {
        CancelMediaOperation(g_mediaAction);
        g_mediaAction = g_sess.TryChangeShuffleActiveAsync(!g.media.shuffle);
        g_mediaActionCmd = 4;
        g_mediaActionStarted = GetTickCount64();
    } catch (...) { MediaActionRejected(); }
#endif
}

static void MediaCycleRepeat() {
#if GH_HAVE_WINRT
    if (!g_sess || !g.media.valid || !g.media.canRepeat) return;
    using Mode = winrt::Windows::Media::MediaPlaybackAutoRepeatMode;
    const Mode next = g.media.repeat == 0 ? Mode::List : g.media.repeat == 2 ? Mode::Track : Mode::None;
    try {
        CancelMediaOperation(g_mediaAction);
        g_mediaAction = g_sess.TryChangeAutoRepeatModeAsync(next);
        g_mediaActionCmd = 4;
        g_mediaActionStarted = GetTickCount64();
    } catch (...) { MediaActionRejected(); }
#endif
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static bool ReadDwordHKCU(const wchar_t* sub, const wchar_t* name, DWORD& v) {
    DWORD sz = sizeof(v);
    return RegGetValueW(HKEY_CURRENT_USER, sub, name, RRF_RT_REG_DWORD, nullptr, &v, &sz) == ERROR_SUCCESS;
}

static bool UpdatePalette() {
    bool light = false;
    if (g.theme == 2) {
        light = true;
    } else if (g.theme == 0) {
        DWORD v = 0;
        if (ReadDwordHKCU(L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
                          L"SystemUsesLightTheme", v))
            light = (v != 0);
    }

    bool haveAcc = false;
    DWORD raw = 0;
    if (g.useWinAccent) {
        DWORD v = 0;
        if (ReadDwordHKCU(L"Software\\Microsoft\\Windows\\DWM", L"AccentColor", v)) {
            haveAcc = true;
            raw = v;
        }
    }

    bool changed = (light != g.pal.light) || (haveAcc != g.haveAccent) || (haveAcc && raw != g.accentRaw);

    g.pal.light = light;
    g.haveAccent = haveAcc;
    g.accentRaw = raw;
    if (haveAcc) g.accentCol = C((float)(raw & 0xFF), (float)((raw >> 8) & 0xFF), (float)((raw >> 16) & 0xFF));

    if (light) {
        g.pal.white = C(22, 27, 40, 0.96f);
        g.pal.soft = C(46, 54, 74, 0.88f);
        g.pal.dimc = C(84, 94, 118, 0.84f);
        g.pal.hl = C(20, 26, 44, 1.0f);
        g.pal.topC = C(247, 249, 253);
        g.pal.botC = C(224, 230, 241);
        g.pal.shadow = 0.0f;
    } else {
        g.pal.white = C(255, 255, 255, 0.97f);
        g.pal.soft = C(226, 232, 244, 0.86f);
        g.pal.dimc = C(204, 212, 228, 0.66f);
        g.pal.hl = C(255, 255, 255, 1.0f);
        g.pal.topC = C(36, 42, 60);
        g.pal.botC = C(14, 17, 28);
        g.pal.shadow = 0.45f;
    }
    return changed;
}

typedef HRESULT(WINAPI* QueryUnsFn)(int*);

static bool FullscreenBusy() {
    static QueryUnsFn fn = nullptr;
    static bool tried = false;
    if (!tried) {
        tried = true;
        HMODULE m = GetModuleHandleW(L"shell32.dll");
        if (m) fn = (QueryUnsFn)GetProcAddress(m, "SHQueryUserNotificationState");
    }
    if (!fn) return false;
    int s = 0;
    if (FAILED(fn(&s))) return false;
    return s == 2 || s == 3 || s == 4;
}

static BOOL CALLBACK MonEnum(HMONITOR m, HDC, LPRECT, LPARAM lp) {
    reinterpret_cast<std::vector<HMONITOR>*>(lp)->push_back(m);
    return TRUE;
}

static RECT WorkAreaForSetting() {
    RECT wa;
    SystemParametersInfoW(SPI_GETWORKAREA, 0, &wa, 0);
    if (g.monitor > 0) {
        std::vector<HMONITOR> ms;
        EnumDisplayMonitors(nullptr, nullptr, MonEnum, reinterpret_cast<LPARAM>(&ms));
        if ((int)ms.size() >= g.monitor) {
            MONITORINFO mi;
            memset(&mi, 0, sizeof(mi));
            mi.cbSize = sizeof(mi);
            if (GetMonitorInfoW(ms[(size_t)g.monitor - 1], &mi)) wa = mi.rcWork;
        }
    }
    return wa;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static void ShowNotice(const std::wstring& title, const std::wstring& text) {
    if (!g.msgWin) return;
    NOTIFYICONDATAW nid;
    memset(&nid, 0, sizeof(nid));
    nid.cbSize = sizeof(nid);
    nid.hWnd = g.msgWin;
    nid.uID = 0x4743;
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_INFO;
    nid.hIcon = LoadIconW(nullptr, IDI_INFORMATION);
    lstrcpynW(nid.szTip, L"Glass Cards", 127);
    lstrcpynW(nid.szInfoTitle, title.c_str(), 63);
    lstrcpynW(nid.szInfo, text.c_str(), 255);
    nid.dwInfoFlags = NIIF_INFO;
    if (g.noticeActive) {
        Shell_NotifyIconW(NIM_MODIFY, &nid);
    } else if (Shell_NotifyIconW(NIM_ADD, &nid)) {
        g.noticeActive = true;
    }
    SetTimer(g.msgWin, 2, 12000, nullptr);
}

static void RemoveNotice() {
    if (!g.noticeActive || !g.msgWin) return;
    NOTIFYICONDATAW nid;
    memset(&nid, 0, sizeof(nid));
    nid.cbSize = sizeof(nid);
    nid.hWnd = g.msgWin;
    nid.uID = 0x4743;
    Shell_NotifyIconW(NIM_DELETE, &nid);
    g.noticeActive = false;
}

static void PomodoroTick() {
    if (!g.pomoRun || g.pomoFocus <= 0) return;
    const ULONGLONG now = GetTickCount64();
    if (now < g.pomoEnd) {
        g.pomoLeft = (int)((g.pomoEnd - now + 999) / 1000);
        return;
    }
    if (g.pomoMode == 0) {
        g.pomoDone++;
        g.pomoMode = 1;
        g.pomoLeft = g.pomoBreak * 60;
        ShowNotice(L"Pomodoro", TR(L"Trabajo terminado. Toca descansar.", L"Work done. Time for a break.",
                                   L"Treball acabat. Toca descansar."));
    } else {
        g.pomoMode = 0;
        g.pomoLeft = g.pomoFocus * 60;
        ShowNotice(L"Pomodoro", TR(L"Descanso terminado. A por otra tanda.", L"Break over. Back to work.",
                                   L"Descans acabat. A per una altra tanda."));
    }
    g.pomoEnd = now + (ULONGLONG)g.pomoLeft * 1000;
    g.cards[CARD_CLOCK].dirty = true;
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

struct Canvas {
    int w = 0;
    int h = 0;
    std::vector<DWORD> px;
};

static const RGBA kNone = {0, 0, 0, 0};

static inline float Clamp01(float v) { return v < 0.0f ? 0.0f : (v > 1.0f ? 1.0f : v); }
static inline float Lerp(float a, float b, float t) { return a + (b - a) * t; }
static inline float Coverage(float d) { return Clamp01(0.5f - d); }

static inline RGBA LerpC(const RGBA& a, const RGBA& b, float t) {
    RGBA c = {Lerp(a.r, b.r, t), Lerp(a.g, b.g, t), Lerp(a.b, b.b, t), Lerp(a.a, b.a, t)};
    return c;
}

static inline void Blend(Canvas& cv, int x, int y, const RGBA& c) {
    float a = Clamp01(c.a);
    if (a <= 0.0f) return;
    DWORD& d = cv.px[(size_t)y * (size_t)cv.w + (size_t)x];
    float inv = 1.0f - a;
    float dr = (float)((d >> 16) & 0xFF) / 255.0f;
    float dg = (float)((d >> 8) & 0xFF) / 255.0f;
    float db = (float)(d & 0xFF) / 255.0f;
    float da = (float)((d >> 24) & 0xFF) / 255.0f;
    float rr = Clamp01(c.r * a + dr * inv);
    float rg = Clamp01(c.g * a + dg * inv);
    float rb = Clamp01(c.b * a + db * inv);
    float ra = Clamp01(a + da * inv);
    d = ((DWORD)(ra * 255.0f + 0.5f) << 24) | ((DWORD)(rr * 255.0f + 0.5f) << 16) |
        ((DWORD)(rg * 255.0f + 0.5f) << 8) | (DWORD)(rb * 255.0f + 0.5f);
}

template <class F>
static void Paint(Canvas& cv, float x0, float y0, float x1, float y1, F shade) {
    int ix0 = std::max(0, (int)floorf(x0));
    int iy0 = std::max(0, (int)floorf(y0));
    int ix1 = std::min(cv.w, (int)ceilf(x1));
    int iy1 = std::min(cv.h, (int)ceilf(y1));
    for (int y = iy0; y < iy1; y++) {
        for (int x = ix0; x < ix1; x++) {
            RGBA c = shade((float)x + 0.5f, (float)y + 0.5f);
            Blend(cv, x, y, c);
        }
    }
}

static inline float Len2(float x, float y) { return sqrtf(x * x + y * y); }

static inline float SdCircle(float px, float py, float cx, float cy, float r) {
    return Len2(px - cx, py - cy) - r;
}

static inline float SdRoundRect(float px, float py, float cx, float cy, float hw, float hh, float r) {
    float qx = fabsf(px - cx) - hw + r;
    float qy = fabsf(py - cy) - hh + r;
    float ox = std::max(qx, 0.0f);
    float oy = std::max(qy, 0.0f);
    return Len2(ox, oy) + std::min(std::max(qx, qy), 0.0f) - r;
}

static inline float SdCapsule(float px, float py, float ax, float ay, float bx, float by, float r) {
    float pax = px - ax, pay = py - ay;
    float bax = bx - ax, bay = by - ay;
    float den = bax * bax + bay * bay;
    float h = den > 0.0f ? Clamp01((pax * bax + pay * bay) / den) : 0.0f;
    return Len2(pax - bax * h, pay - bay * h) - r;
}

static float SdPolygon(float px, float py, const float* v, int n) {
    float d = (px - v[0]) * (px - v[0]) + (py - v[1]) * (py - v[1]);
    float s = 1.0f;
    for (int i = 0, j = n - 1; i < n; j = i, i++) {
        float ex = v[2 * j] - v[2 * i];
        float ey = v[2 * j + 1] - v[2 * i + 1];
        float wx = px - v[2 * i];
        float wy = py - v[2 * i + 1];
        float t = Clamp01((wx * ex + wy * ey) / std::max(ex * ex + ey * ey, 1e-12f));
        float bx = wx - ex * t;
        float by = wy - ey * t;
        d = std::min(d, bx * bx + by * by);
        bool c1 = py >= v[2 * i + 1];
        bool c2 = py < v[2 * j + 1];
        bool c3 = ex * wy > ey * wx;
        if ((c1 && c2 && c3) || (!c1 && !c2 && !c3)) s = -s;
    }
    return s * sqrtf(d);
}

template <class SD, class CF>
static void FillSdf(Canvas& cv, float x0, float y0, float x1, float y1, SD sdf, CF color) {
    Paint(cv, x0, y0, x1, y1, [&](float x, float y) -> RGBA {
        float c = Coverage(sdf(x, y));
        if (c <= 0.0f) return kNone;
        RGBA k = color(x, y);
        k.a *= c;
        return k;
    });
}

template <class CF>
static void FillCircle(Canvas& cv, float cx, float cy, float r, CF col) {
    FillSdf(cv, cx - r - 1, cy - r - 1, cx + r + 1, cy + r + 1,
            [=](float x, float y) { return SdCircle(x, y, cx, cy, r); }, col);
}

template <class CF>
static void FillCapsule(Canvas& cv, float ax, float ay, float bx, float by, float r, CF col) {
    FillSdf(cv, std::min(ax, bx) - r - 1, std::min(ay, by) - r - 1, std::max(ax, bx) + r + 1,
            std::max(ay, by) + r + 1,
            [=](float x, float y) { return SdCapsule(x, y, ax, ay, bx, by, r); }, col);
}

template <class CF>
static void FillRRect(Canvas& cv, float cx, float cy, float hw, float hh, float r, CF col) {
    FillSdf(cv, cx - hw - 1, cy - hh - 1, cx + hw + 1, cy + hh + 1,
            [=](float x, float y) { return SdRoundRect(x, y, cx, cy, hw, hh, r); }, col);
}

template <class CF>
static void FillPoly(Canvas& cv, const std::vector<float>& pts, CF col) {
    int n = (int)(pts.size() / 2);
    float x0 = pts[0], x1 = pts[0], y0 = pts[1], y1 = pts[1];
    for (int i = 1; i < n; i++) {
        x0 = std::min(x0, pts[2 * i]);
        x1 = std::max(x1, pts[2 * i]);
        y0 = std::min(y0, pts[2 * i + 1]);
        y1 = std::max(y1, pts[2 * i + 1]);
    }
    FillSdf(cv, x0 - 2, y0 - 2, x1 + 2, y1 + 2,
            [&](float x, float y) { return SdPolygon(x, y, pts.data(), n); }, col);
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static void DrawCloud(Canvas& cv, float cx, float cy, float w, RGBA top, RGBA bot) {
    float h = w * 0.55f;
    auto grad = [&](float, float y) -> RGBA {
        float t = Clamp01((y - (cy - h * 0.55f)) / (h * 1.1f));
        return LerpC(top, bot, t);
    };
    FillRRect(cv, cx, cy + h * 0.14f, w * 0.5f, h * 0.28f, h * 0.28f, grad);
    FillCircle(cv, cx - w * 0.18f, cy - h * 0.02f, h * 0.30f, grad);
    FillCircle(cv, cx + w * 0.06f, cy - h * 0.14f, h * 0.40f, grad);
    FillCircle(cv, cx + w * 0.30f, cy + h * 0.02f, h * 0.26f, grad);
}

static void DrawSun(Canvas& cv, float cx, float cy, float r) {
    Paint(cv, cx - r * 2.6f, cy - r * 2.6f, cx + r * 2.6f, cy + r * 2.6f,
          [&](float x, float y) -> RGBA {
              float d = Len2(x - cx, y - cy) - r;
              if (d < 0.0f) return kNone;
              return C(255, 205, 90, 0.30f * expf(-d / (0.75f * r)));
          });
    for (int i = 0; i < 8; i++) {
        float ang = (float)i * 0.78539816f;
        float ca = cosf(ang), sa = sinf(ang);
        FillCapsule(cv, cx + ca * r * 1.38f, cy + sa * r * 1.38f, cx + ca * r * 1.78f,
                    cy + sa * r * 1.78f, r * 0.09f,
                    [](float, float) -> RGBA { return C(255, 214, 102, 0.95f); });
    }
    FillCircle(cv, cx, cy, r, [&](float x, float y) -> RGBA {
        float t = Clamp01(((x - cx) + (y - cy)) / (2.0f * r) * 0.5f + 0.5f);
        return LerpC(C(255, 232, 130), C(255, 160, 45), t);
    });
}

static void DrawMoon(Canvas& cv, float cx, float cy, float r) {
    Paint(cv, cx - r * 2.4f, cy - r * 2.4f, cx + r * 2.4f, cy + r * 2.4f,
          [&](float x, float y) -> RGBA {
              float d = Len2(x - cx, y - cy) - r;
              if (d < 0.0f) return kNone;
              return C(170, 185, 255, 0.22f * expf(-d / (0.8f * r)));
          });
    float ox = cx + r * 0.50f, oy = cy - r * 0.28f, or2 = r * 0.86f;
    FillSdf(cv, cx - r - 1, cy - r - 1, cx + r + 1, cy + r + 1,
            [=](float x, float y) {
                return std::max(SdCircle(x, y, cx, cy, r), -SdCircle(x, y, ox, oy, or2));
            },
            [&](float x, float y) -> RGBA {
                float t = Clamp01(((y - cy) / r) * 0.5f + 0.5f);
                return LerpC(C(246, 248, 255), C(206, 214, 238), t);
            });
    FillCircle(cv, cx + r * 1.15f, cy - r * 0.95f, r * 0.07f,
               [](float, float) -> RGBA { return C(255, 255, 255, 0.9f); });
    FillCircle(cv, cx + r * 0.75f, cy + r * 1.1f, r * 0.05f,
               [](float, float) -> RGBA { return C(255, 255, 255, 0.7f); });
}

static void DrawIcon(Canvas& cv, Kind kind, bool isDay, float cx, float cy, float size) {
    float dim = isDay ? 1.0f : 0.80f;
    RGBA cTop = C(250 * dim, 252 * dim, 255 * dim);
    RGBA cBot = C(186 * dim, 198 * dim, 216 * dim);
    RGBA rTop = C(214 * dim, 222 * dim, 236 * dim);
    RGBA rBot = C(140 * dim, 156 * dim, 184 * dim);

    switch (kind) {
        case K_CLEAR:
            if (isDay) DrawSun(cv, cx, cy, size * 0.25f);
            else DrawMoon(cv, cx, cy, size * 0.30f);
            break;

        case K_PARTLY:
            if (isDay) DrawSun(cv, cx - size * 0.14f, cy - size * 0.13f, size * 0.17f);
            else DrawMoon(cv, cx - size * 0.14f, cy - size * 0.13f, size * 0.20f);
            DrawCloud(cv, cx + size * 0.06f, cy + size * 0.10f, size * 0.74f, cTop, cBot);
            break;

        case K_CLOUD:
            DrawCloud(cv, cx, cy, size * 0.90f, cTop, cBot);
            break;

        case K_FOG: {
            DrawCloud(cv, cx, cy - size * 0.12f, size * 0.78f, cTop, cBot);
            float ys[3] = {0.20f, 0.31f, 0.42f};
            float xs[3] = {0.30f, 0.36f, 0.24f};
            for (int i = 0; i < 3; i++) {
                FillCapsule(cv, cx - size * xs[i], cy + size * ys[i], cx + size * xs[i],
                            cy + size * ys[i], size * 0.022f,
                            [](float, float) -> RGBA { return C(205, 214, 226, 0.85f); });
            }
            break;
        }

        case K_DRIZZLE:
        case K_RAIN: {
            DrawCloud(cv, cx, cy - size * 0.12f, size * 0.82f, rTop, rBot);
            int n = (kind == K_RAIN) ? 3 : 2;
            float len = (kind == K_RAIN) ? 0.17f : 0.11f;
            for (int i = 0; i < n; i++) {
                float x = cx + size * (-0.18f + 0.18f * (float)i + (n == 2 ? 0.09f : 0.0f));
                float y = cy + size * 0.20f + ((i % 2) ? size * 0.03f : 0.0f);
                FillCapsule(cv, x, y, x - size * 0.05f, y + size * len, size * 0.026f,
                            [](float, float) -> RGBA { return C(96, 176, 255, 0.95f); });
            }
            break;
        }

        case K_SNOW: {
            DrawCloud(cv, cx, cy - size * 0.12f, size * 0.82f, cTop, cBot);
            for (int i = 0; i < 3; i++) {
                float x = cx + size * (-0.19f + 0.19f * (float)i);
                float y = cy + size * (0.24f + ((i % 2) ? 0.07f : 0.0f));
                FillCircle(cv, x, y, size * 0.035f,
                           [](float, float) -> RGBA { return C(255, 255, 255, 0.98f); });
            }
            break;
        }

        case K_THUNDER: {
            DrawCloud(cv, cx, cy - size * 0.14f, size * 0.84f, C(172 * dim, 180 * dim, 202 * dim),
                      C(98 * dim, 108 * dim, 138 * dim));
            float bx = cx, by = cy + size * 0.06f;
            std::vector<float> pts = {
                bx + size * 0.06f, by + size * 0.00f, bx - size * 0.08f, by + size * 0.20f,
                bx + size * 0.00f, by + size * 0.20f, bx - size * 0.06f, by + size * 0.40f,
                bx + size * 0.11f, by + size * 0.14f, bx + size * 0.02f, by + size * 0.14f,
                bx + size * 0.10f, by + size * 0.00f};
            FillPoly(cv, pts, [&](float, float y) -> RGBA {
                float t = Clamp01((y - by) / (size * 0.40f));
                return LerpC(C(255, 232, 110), C(255, 182, 40), t);
            });
            break;
        }
    }
}

static RGBA AccentFor(Kind kind, bool isDay) {
    switch (kind) {
        case K_CLEAR: return isDay ? C(255, 186, 70) : C(120, 130, 255);
        case K_PARTLY: return isDay ? C(255, 200, 110) : C(130, 140, 240);
        case K_CLOUD: return C(140, 170, 215);
        case K_FOG: return C(175, 185, 195);
        case K_DRIZZLE:
        case K_RAIN: return C(70, 150, 255);
        case K_SNOW: return C(170, 225, 255);
        case K_THUNDER: return C(175, 110, 255);
    }
    return C(140, 170, 215);
}

static RGBA UrgencyColor(int days) {
    if (days < 0) return C(255, 96, 96);
    if (days <= 3) return C(255, 118, 84);
    if (days <= 7) return C(255, 166, 72);
    if (days <= 30) return C(255, 212, 92);
    return C(112, 222, 164);
}

static RGBA LoadColor(float pct) {
    if (pct >= 90.0f) return C(255, 100, 100);
    if (pct >= 70.0f) return C(255, 190, 80);
    return C(90, 175, 255);
}

static RGBA UvColor(int uv) {
    if (uv < 3) return C(112, 222, 164, 0.95f);
    if (uv < 6) return C(255, 212, 92, 0.95f);
    if (uv < 8) return C(255, 166, 72, 0.95f);
    if (uv < 11) return C(255, 100, 100, 0.95f);
    return C(200, 120, 255, 0.95f);
}

static RGBA AqiColor(int a) {
    if (a < 20) return C(112, 222, 164, 1.0f);
    if (a < 40) return C(160, 224, 120, 1.0f);
    if (a < 60) return C(255, 212, 92, 1.0f);
    if (a < 80) return C(255, 166, 72, 1.0f);
    return C(255, 100, 100, 1.0f);
}

static RGBA PollenColor(int p) {
    if (p < 20) return C(112, 222, 164, 1.0f);
    if (p < 100) return C(255, 212, 92, 1.0f);
    return C(255, 130, 90, 1.0f);
}

static RGBA CardAccent(const RGBA& def) {
    return g.haveAccent ? g.accentCol : def;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

struct TextCtx {
    HDC dc;
    DWORD* bits;
    int W;
    int H;
    Canvas* cv;
    float k = 1.0f;

    float clipL = -1.0f;
    float clipR = -1.0f;
};

static int CALLBACK FontProbeProc(const LOGFONTW*, const TEXTMETRICW*, DWORD, LPARAM lp) {
    *reinterpret_cast<bool*>(lp) = true;
    return 0;
}

static bool FontInstalled(const wchar_t* face) {
    HDC dc = GetDC(nullptr);
    if (!dc) return false;
    LOGFONTW lf;
    memset(&lf, 0, sizeof(lf));
    lf.lfCharSet = DEFAULT_CHARSET;
    wcsncpy(lf.lfFaceName, face, LF_FACESIZE - 1);
    bool found = false;
    EnumFontFamiliesExW(dc, &lf, FontProbeProc, reinterpret_cast<LPARAM>(&found), 0);
    ReleaseDC(nullptr, dc);
    return found;
}

static HFONT MakeFont(int px, int weight) {
    const wchar_t* face = L"Segoe UI";
    int w = weight;
    if (g.modernFont) {
        const bool big = px >= 20;
        const wchar_t* cand;
        if (weight <= FW_LIGHT) cand = L"Segoe UI Variable Display Light";
        else if (weight == FW_SEMIBOLD) cand = big ? L"Segoe UI Variable Display Semibold" : L"Segoe UI Variable Text Semibold";
        else cand = big ? L"Segoe UI Variable Display" : L"Segoe UI Variable Text";
        if (FontInstalled(cand)) {
            face = cand;

            w = (weight >= FW_BOLD) ? FW_BOLD : FW_NORMAL;
        }
    }
    return CreateFontW(-px, 0, 0, 0, w, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                       OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
                       DEFAULT_PITCH | FF_DONTCARE, face);
}

static HFONT MakeFontFace(int px, int weight, const wchar_t* face) {
    return CreateFontW(-px, 0, 0, 0, weight, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                       OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
                       DEFAULT_PITCH | FF_DONTCARE, face);
}

static Fonts MakeFonts(float k) {
    Fonts f;
    f.title = MakeFont((int)(12.0f * k), FW_SEMIBOLD);
    f.small = MakeFont((int)(12.0f * k), FW_NORMAL);
    f.big = MakeFont((int)(36.0f * k), FW_SEMIBOLD);
    f.name = MakeFont((int)(14.0f * k), FW_NORMAL);
    f.pill = MakeFont((int)(14.0f * k), FW_SEMIBOLD);
    f.temp = MakeFont((int)(44.0f * k), FW_NORMAL);
    f.unit = MakeFont((int)(20.0f * k), FW_NORMAL);
    f.desc = MakeFont((int)(15.0f * k), FW_NORMAL);
    f.time = MakeFont((int)(22.0f * k), FW_SEMIBOLD);
    f.city = MakeFont((int)(13.0f * k), FW_SEMIBOLD);
    f.day = MakeFont((int)(12.0f * k), FW_SEMIBOLD);
    f.note = MakeFontFace((int)(15.0f * k), FW_NORMAL, L"Segoe Print");
    f.head = MakeFont((int)(14.0f * k), FW_BOLD);
    return f;
}

static void FreeFonts(Fonts& f) {
    DeleteObject(f.title);
    DeleteObject(f.small);
    DeleteObject(f.big);
    DeleteObject(f.name);
    DeleteObject(f.pill);
    DeleteObject(f.temp);
    DeleteObject(f.unit);
    DeleteObject(f.desc);
    DeleteObject(f.time);
    DeleteObject(f.city);
    DeleteObject(f.day);
    DeleteObject(f.note);
    DeleteObject(f.head);
}

static Fonts& EnsureFonts(float k) {
    int key = (int)(k * 1000.0f) + (g.modernFont ? 1000000 : 0);
    if (!g.fontsOk || g.fontsKey != key) {
        if (g.fontsOk) FreeFonts(g.fonts);
        g.fonts = MakeFonts(k);
        {
            HDC dc = CreateCompatibleDC(nullptr);
            HGDIOBJ o = SelectObject(dc, g.fonts.note);
            TEXTMETRICW tm;
            memset(&tm, 0, sizeof(tm));
            GetTextMetricsW(dc, &tm);
            SelectObject(dc, o);
            DeleteDC(dc);
            g.notePitch = std::max(12, (int)(tm.tmHeight + tm.tmExternalLeading));
        }
        g.fontsKey = key;
        g.fontsOk = true;
    }
    return g.fonts;
}

static int MeasureWidth(TextCtx& t, HFONT font, const std::wstring& s) {
    if (s.empty()) return 0;
    SIZE sz = {0, 0};
    HGDIOBJ old = SelectObject(t.dc, font);
    GetTextExtentPoint32W(t.dc, s.c_str(), (int)s.size(), &sz);
    SelectObject(t.dc, old);
    return sz.cx;
}

static std::wstring Ellipsize(TextCtx& t, HFONT font, std::wstring s, int maxW) {
    if (maxW < 8) return L"";
    if (MeasureWidth(t, font, s) <= maxW) return s;
    while (s.size() > 1) {
        s.pop_back();
        std::wstring c = s + L"\u2026";
        if (MeasureWidth(t, font, c) <= maxW) return c;
    }
    return s;
}

static int DrawLabel(TextCtx& t, HFONT font, const std::wstring& s, float x, float y, int align,
                     RGBA color) {
    if (s.empty()) return 0;

    SIZE sz = {0, 0};
    HGDIOBJ old = SelectObject(t.dc, font);
    GetTextExtentPoint32W(t.dc, s.c_str(), (int)s.size(), &sz);

    int w = sz.cx;
    int h = sz.cy;
    int px = (int)x;
    if (align == 1) px -= w / 2;
    else if (align == 2) px -= w;
    int py = (int)y;

    int rx0 = std::max(0, px - 3);
    int ry0 = std::max(0, py - 3);
    int rx1 = std::min(t.W, px + w + 5);
    int ry1 = std::min(t.H, py + h + 5);
    if (t.clipR > t.clipL) {
        rx0 = std::max(rx0, (int)ceilf(t.clipL));
        rx1 = std::min(rx1, (int)floorf(t.clipR));
    }
    if (rx1 <= rx0 || ry1 <= ry0) {
        SelectObject(t.dc, old);
        return w;
    }

    for (int yy = ry0; yy < ry1; yy++) {
        memset(&t.bits[(size_t)yy * (size_t)t.W + (size_t)rx0], 0, (size_t)(rx1 - rx0) * 4);
    }

    TextOutW(t.dc, px, py, s.c_str(), (int)s.size());
    GdiFlush();
    SelectObject(t.dc, old);

    if (g.pal.shadow > 0.0f) {
        for (int yy = ry0; yy < ry1; yy++) {
            for (int xx = rx0; xx < rx1; xx++) {
                int sx = xx - 1;
                int sy = yy - 1;
                if (sx < rx0 || sy < ry0) continue;
                DWORD m = t.bits[(size_t)sy * (size_t)t.W + (size_t)sx] & 0xFF;
                if (!m) continue;
                RGBA sh = {0.0f, 0.0f, 0.0f, g.pal.shadow * (float)m / 255.0f * color.a};
                Blend(*t.cv, xx, yy, sh);
            }
        }
    }

    for (int yy = ry0; yy < ry1; yy++) {
        for (int xx = rx0; xx < rx1; xx++) {
            DWORD m = t.bits[(size_t)yy * (size_t)t.W + (size_t)xx] & 0xFF;
            if (!m) continue;
            RGBA c = color;
            c.a = color.a * (float)m / 255.0f;
            Blend(*t.cv, xx, yy, c);
        }
    }
    return w;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static std::vector<Deadline> AllDeadlines() {
    long long today = TodayNumber();
    std::vector<Deadline> v;
    for (int pass = 0; pass < 2; pass++) {
        const std::vector<Deadline>& src = pass == 0 ? g.deadlines : g.ics;
        for (size_t i = 0; i < src.size(); i++) {
            Deadline d = src[i];
            if (!ApplyRepeat(d, today)) continue;
            d.days = (int)(d.dayNum - today);

            if (d.days >= 0) v.push_back(d);
        }
    }
    std::sort(v.begin(), v.end(), [](const Deadline& a, const Deadline& b) {
        if (a.days != b.days) return a.days < b.days;
        int ka = a.hh < 0 ? 1440 : a.hh * 60 + a.mm;
        int kb = b.hh < 0 ? 1440 : b.hh * 60 + b.mm;
        return ka < kb;
    });

    std::vector<Deadline> uniq;
    uniq.reserve(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        bool dup = false;

        auto norm = [](std::wstring t) {
            while (!t.empty() && (t.back() == L'.' || t.back() == L' ')) t.pop_back();
            while (!t.empty() && t.front() == L' ') t.erase(t.begin());
            for (size_t c = 0; c < t.size(); c++) t[c] = (wchar_t)towlower(t[c]);
            return t;
        };
        for (size_t j = 0; j < uniq.size(); j++) {
            if (uniq[j].dayNum == v[i].dayNum && uniq[j].hh == v[i].hh &&
                uniq[j].mm == v[i].mm && norm(uniq[j].name) == norm(v[i].name)) {
                dup = true;

                if (uniq[j].place.empty() && !v[i].place.empty()) uniq[j].place = v[i].place;
                break;
            }
        }
        if (!dup) uniq.push_back(v[i]);
    }
    return uniq;
}

static int AgendaGroupOf(int days) {
    if (days == 0) return 1;
    if (days == 1) return 2;
    if (days <= 7) return 3;
    return 4;
}

static std::vector<Deadline> VisibleDeadlines() {
    std::vector<Deadline> v = AllDeadlines();
    if ((int)v.size() > g.maxDeadlines) v.resize((size_t)g.maxDeadlines);
    return v;
}

// Seen calendar events

static void DeadlineDoneKey(wchar_t* buf, const Deadline& d) {
    unsigned int h = TextHash(d.name + L"|" + std::to_wstring(d.dayNum) + L"|" +
                             std::to_wstring(d.hh * 60 + d.mm));
    wsprintfW(buf, L"dlDone_%08X", h);
}

static bool DeadlineDone(const Deadline& d) {
    wchar_t key[32];
    DeadlineDoneKey(key, d);
    return Wh_GetIntValue(key, 0) != 0;
}

static void ToggleDeadlineDone(const Deadline& d) {
    wchar_t key[32];
    DeadlineDoneKey(key, d);
    int now = Wh_GetIntValue(key, 0) ? 0 : 1;
    Wh_SetIntValue(key, now);

    if (now) {
        unsigned int h = TextHash(d.name + L"|" + std::to_wstring(d.dayNum) + L"|" +
                                 std::to_wstring(d.hh * 60 + d.mm));
        if (std::find(g.notified.begin(), g.notified.end(), h) == g.notified.end())
            g.notified.push_back(h);
    }
}

static float DeadlineRowH(const Deadline& d) { return d.fromIcs ? 60.0f : 48.0f; }

static int DeadlineRowAt(float uy) {
    std::vector<Deadline> v = VisibleDeadlines();
    float top = 38.0f;
    int prevG = -99;
    for (size_t i = 0; i < v.size(); i++) {
        int gv = AgendaGroupOf(v[i].days);
        if (gv != prevG) { prevG = gv; top += 20.0f; }
        float h = DeadlineRowH(v[i]);
        if (uy >= top && uy < top + h) return (int)i;
        top += h;
    }
    return -1;
}

static float DeadlineRowTop(int row, const std::vector<Deadline>& v) {
    float top = 38.0f;
    int prevG = -99;
    for (int i = 0; i < (int)v.size(); i++) {
        int gv = AgendaGroupOf(v[i].days);
        if (gv != prevG) { prevG = gv; top += 20.0f; }
        if (i == row) return top;
        top += DeadlineRowH(v[i]);
    }
    return top;
}

static RGBA AlertColor(int c) {
    switch (c) {
        case 1: return C(80, 200, 120, 0.95f);
        case 2: return C(240, 205, 70, 0.97f);
        case 3: return C(245, 150, 60, 0.97f);
        default: return C(235, 80, 80, 0.97f);
    }
}

static const wchar_t* AlertName(int c) {
    switch (c) {
        case 1: return TR(L"Verde", L"Green", L"Verd");
        case 2: return TR(L"Amarilla", L"Yellow", L"Groga");
        case 3: return TR(L"Naranja", L"Orange", L"Taronja");
        default: return TR(L"Roja", L"Red", L"Vermella");
    }
}

struct WLayout {
    float panelY = -1, panelH = 0;
    float detailsY = -1, sunY = -1, rainY = -1, hourlyY = -1, hourlyH = 0, divY = 0, cardH = 0;
    float alertY = -1;
    bool anyPop = true;
};

static WLayout WeatherLayout(const Weather& wt) {
    WLayout L;

    float y = 138.0f;
    bool haveDetails = g.showDetails && wt.valid;
    bool haveSun = g.showSunAir && wt.valid && (wt.sunrise >= 0 || wt.aqi >= 0 || wt.pollen >= 0);
    if (haveDetails || haveSun) {
        int rows = (haveDetails ? 1 : 0) + (haveSun ? 1 : 0);
        L.panelY = y;
        L.panelH = 8.0f + 36.0f * (float)rows;
        float ry = y + 4.0f;
        if (haveDetails) {
            L.detailsY = ry;
            ry += 36.0f;
        }
        if (haveSun) L.sunY = ry;
        y += L.panelH + 4.0f;
    }
    if (wt.valid && wt.rainMin >= 0) {
        L.rainY = y;
        y += 18.0f;
    }
    if (g.showHourly && wt.valid && wt.hourlyN >= 6) {
        L.hourlyY = y + 4.0f;
        L.hourlyH = 88.0f;
        y += 4.0f + 88.0f;
    }

    if (wt.valid && wt.alertColor > 0) {
        L.alertY = y + 16.0f;
        y += 30.0f;
    }
    L.divY = y + 4.0f;

    for (int i = 1; i <= 6 && i < wt.days; i++) {
        if (wt.dpop[i] >= 0) L.anyPop = true;
    }
    L.cardH = g.showForecast ? (L.divY + (L.anyPop ? 100.0f : 84.0f)) : (y + 14.0f);
    return L;
}

static void DrawHourly(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu, float hy) {
    const Weather& wt = g.weather;
    int n = wt.hourlyN;
    if (n < 2) return;

    const RGBA barCol = C(112, 190, 255, 0.95f);
    const RGBA barFill = C(112, 190, 255, 0.22f);

    float x0 = M + 24.0f * k, x1 = M + (cardWu - 24.0f) * k;
    float step = (x1 - x0) / (float)(n - 1);
    float yTop = M + (hy + 36.0f) * k, yBot = M + (hy + 56.0f) * k;
    float baseY = M + (hy + 68.0f) * k;

    double sMin = wt.htemp[0], sMax = wt.htemp[0];
    for (int i = 1; i < n; i++) {
        sMin = std::min(sMin, wt.htemp[i]);
        sMax = std::max(sMax, wt.htemp[i]);
    }
    double dayMax = wt.days > 0 ? wt.dmax[0] : sMax;
    double dayMin = wt.days > 0 ? wt.dmin[0] : sMin;
    double tmin = std::min(sMin, dayMin), tmax = std::max(sMax, dayMax);
    double range = std::max(tmax - tmin, 1.0);

    auto yOf = [=](double v) -> float {
        return yBot - (float)((v - tmin) / range) * (yBot - yTop);
    };

    std::wstring caption = TR(L"Próximas 24 h", L"Next 24 h", L"Properes 24 h");
    if (g.hourlyHover >= 0 && g.hourlyHover < n) {
        const int hour = g.hourlyHover;
        wchar_t hourText[16];
        wsprintfW(hourText, L"%02d:00", wt.hhour[hour]);
        caption = std::wstring(hourText) + L" · " + std::to_wstring((int)lround(wt.htemp[hour])) +
                  (g.fahrenheit ? L" °F · " : L" °C · ") + std::to_wstring(wt.hpop[hour]) +
                  TR(L" % lluvia", L" % rain", L" % pluja");
    }
    DrawLabel(t, f.small, caption, x1, M + (hy - 2.0f) * k, 2, g.pal.white);

    std::vector<float> px((size_t)n), py((size_t)n);
    for (int i = 0; i < n; i++) {
        px[(size_t)i] = x0 + step * (float)i;
        py[(size_t)i] = yOf(wt.htemp[i]);
    }

    for (int i = 0; i < n; i++) {
        if (wt.hpop[i] < 10) continue;
        float h = std::max(2.0f * k, (float)wt.hpop[i] / 100.0f * 9.0f * k);
        FillRRect(cv, px[(size_t)i], baseY - h / 2.0f, step * 0.30f, h / 2.0f, 1.0f * k,
                  [](float, float) -> RGBA { return C(96, 176, 255, 0.60f); });
    }

    float bottom = yBot + 4.0f * k;
    Paint(cv, x0, yTop - 4.0f * k, x1, bottom, [&](float x, float y) -> RGBA {
        int j = (int)((x - x0) / step);
        if (j < 0) j = 0;
        if (j > n - 2) j = n - 2;
        float tt = Clamp01((x - px[(size_t)j]) / (px[(size_t)j + 1] - px[(size_t)j]));
        float yc = Lerp(py[(size_t)j], py[(size_t)j + 1], tt);
        if (y < yc) return kNone;
        float depth = Clamp01(1.0f - (y - yc) / (bottom - yTop));
        RGBA c = barFill;
        c.a *= depth;
        return c;
    });

    for (int i = 0; i + 1 < n; i++) {
        FillCapsule(cv, px[(size_t)i], py[(size_t)i], px[(size_t)i + 1], py[(size_t)i + 1],
                    1.3f * k, [barCol](float, float) -> RGBA { return barCol; });
    }

    for (int i = 0; i < n; i += 3) {
        std::wstring tempS = std::to_wstring((int)floor(wt.htemp[i] + 0.5)) + L"\u00B0";
        DrawLabel(t, f.small, tempS, px[(size_t)i], M + (hy + 17.0f) * k, 1, g.pal.soft);

        std::wstring lab;
        if (i == 0) {
            lab = TR(L"Ahora", L"Now", L"Ara");
        } else {
            wchar_t b[8];
            wsprintfW(b, L"%02dh", wt.hhour[i]);
            lab = b;
        }
        DrawLabel(t, f.small, lab, px[(size_t)i], M + (hy + 71.0f) * k, 1, g.pal.dimc);
    }
    if (g.hourlyHover >= 0 && g.hourlyHover < n) {
        const int hour = g.hourlyHover;
        FillCircle(cv, px[hour], py[hour], 3.5f * k,
                   [](float, float) -> RGBA { return C(166, 219, 255); });
    }

}

static void DrawStat(TextCtx& t, Fonts& f, float cx, float topY, const std::wstring& label,
                     const std::wstring& value, RGBA valCol, int maxW) {
    DrawLabel(t, f.small, label, cx, topY, 1, g.pal.soft);
    DrawLabel(t, f.pill, Ellipsize(t, f.pill, value, maxW), cx, topY + 14.0f * g.kLast, 1, valCol);
}

static RGBA MediaAccent() {
    RGBA def = CardAccent(C(255, 120, 160));
    const int S = g.thumbS;
    if (!g.coverAccent || g.haveAccent || !g.thumbOk || S <= 0 || (int)g.thumbPx.size() < S * S) return def;
    static int s_serial = -1, s_size = 0;
    static RGBA s_col = {0, 0, 0, 1};
    if (s_serial == g.thumbSerial && s_size == S) return s_col;
    double R = 0, G = 0, B = 0, Wt = 0;
    for (int y = 0; y < S; y += 2) {
        for (int x = 0; x < S; x += 2) {
            DWORD p = g.thumbPx[(size_t)y * (size_t)S + (size_t)x];
            float r = (float)((p >> 16) & 0xFF) / 255.0f;
            float gg = (float)((p >> 8) & 0xFF) / 255.0f;
            float b = (float)(p & 0xFF) / 255.0f;
            float mx = std::max(r, std::max(gg, b)), mn = std::min(r, std::min(gg, b));
            float sat = mx > 0.0f ? (mx - mn) / mx : 0.0f;
            float w = sat * sat * mx;
            R += r * w; G += gg * w; B += b * w; Wt += w;
        }
    }
    RGBA col;
    if (Wt < 1.0) {
        col = C(170, 185, 210);
    } else {
        float r = (float)(R / Wt), gg = (float)(G / Wt), b = (float)(B / Wt);
        float mx = std::max(r, std::max(gg, b));
        float sc = mx > 0.001f ? 0.92f / mx : 1.0f;
        col.r = Clamp01(r * sc);
        col.g = Clamp01(gg * sc);
        col.b = Clamp01(b * sc);
        col.a = 1.0f;
    }
    s_serial = g.thumbSerial;
    s_size = S;
    s_col = col;
    return col;
}

static RGBA CardBadgeColor(int id) {
    switch (id) {
        case CARD_SYSTEM: return CardAccent(C(70, 150, 255));
        case CARD_CLOCK: return CardAccent(C(255, 150, 70));
        case CARD_MEDIA: return MediaAccent();
        case CARD_DEADLINES: return CardAccent(C(255, 178, 56));
        default: return CardAccent(C(176, 140, 255));
    }
}

static void DrawCardIcon(Canvas& cv, int id, float cx, float cy, float k) {
    auto wcol = [](float, float) -> RGBA { return C(255, 255, 255, 0.97f); };
    switch (id) {
        case CARD_SYSTEM:
            FillRRect(cv, cx - 4.6f * k, cy + 3.2f * k, 1.5f * k, 2.4f * k, 0.7f * k, wcol);
            FillRRect(cv, cx, cy + 1.6f * k, 1.5f * k, 4.0f * k, 0.7f * k, wcol);
            FillRRect(cv, cx + 4.6f * k, cy, 1.5f * k, 5.6f * k, 0.7f * k, wcol);
            break;
        case CARD_CLOCK: {
            float r = 6.3f * k, th = 1.1f * k;
            FillSdf(cv, cx - r - 2, cy - r - 2, cx + r + 2, cy + r + 2,
                    [=](float x, float y) { return fabsf(SdCircle(x, y, cx, cy, r) + th) - th; }, wcol);
            FillCapsule(cv, cx, cy, cx, cy - 3.9f * k, 0.7f * k, wcol);
            FillCapsule(cv, cx, cy, cx + 2.8f * k, cy + 1.6f * k, 0.7f * k, wcol);
            break;
        }
        case CARD_WEATHER: {

            float sr = 3.6f * k;
            FillCircle(cv, cx + 2.6f * k, cy - 2.6f * k, sr, wcol);
            for (int a = 0; a < 8; a++) {
                float ang = (float)a * 0.7853982f;
                float x0 = cx + 2.6f * k + cosf(ang) * (sr + 1.6f * k);
                float y0 = cy - 2.6f * k + sinf(ang) * (sr + 1.6f * k);
                float x1 = cx + 2.6f * k + cosf(ang) * (sr + 3.4f * k);
                float y1 = cy - 2.6f * k + sinf(ang) * (sr + 3.4f * k);
                FillCapsule(cv, x0, y0, x1, y1, 0.75f * k, wcol);
            }
            FillCircle(cv, cx - 3.4f * k, cy + 3.0f * k, 2.9f * k, wcol);
            FillCircle(cv, cx + 0.2f * k, cy + 2.2f * k, 3.6f * k, wcol);
            FillCircle(cv, cx + 3.6f * k, cy + 3.4f * k, 2.6f * k, wcol);
            FillRRect(cv, cx, cy + 4.6f * k, 5.4f * k, 1.6f * k, 1.6f * k, wcol);
            break;
        }
        case CARD_MEDIA:
            FillCircle(cv, cx - 2.2f * k, cy + 3.6f * k, 2.3f * k, wcol);
            FillCapsule(cv, cx - 0.2f * k, cy + 3.2f * k, cx - 0.2f * k, cy - 5.0f * k, 0.9f * k, wcol);
            FillCapsule(cv, cx - 0.2f * k, cy - 5.0f * k, cx + 4.0f * k, cy - 2.8f * k, 0.9f * k, wcol);
            break;
        case CARD_DEADLINES: {
            FillRRect(cv, cx, cy + 0.8f * k, 6.0f * k, 5.2f * k, 1.4f * k, wcol);
            RGBA band = CardBadgeColor(id);
            band.a = 0.55f;
            FillRRect(cv, cx, cy - 2.4f * k, 6.0f * k, 1.7f * k, 1.2f * k,
                      [band](float, float) -> RGBA { return band; });
            FillCapsule(cv, cx - 2.8f * k, cy - 6.2f * k, cx - 2.8f * k, cy - 3.6f * k, 0.8f * k, wcol);
            FillCapsule(cv, cx + 2.8f * k, cy - 6.2f * k, cx + 2.8f * k, cy - 3.6f * k, 0.8f * k, wcol);
            break;
        }
        default: break;
    }
}

static const wchar_t* CardTitle(int id) {
    if (id == CARD_SYSTEM) return TR(L"SISTEMA", L"SYSTEM", L"SISTEMA");
    if (id == CARD_DEADLINES) return TR(L"AGENDA", L"CALENDAR", L"AGENDA");
    if (id == CARD_NOTES) return TR(L"NOTAS", L"NOTES", L"NOTES");
    if (id == CARD_MEDIA) return TR(L"MULTIMEDIA", L"MEDIA", L"MULTIM\u00C8DIA");
    if (id == CARD_CLOCK) return TR(L"RELOJ", L"CLOCK", L"RELLOTGE");
    return TR(L"TIEMPO", L"WEATHER", L"TEMPS");
}

static unsigned int AlertHash() {
    const Weather& wt = g.weather;
    return TextHash(wt.alertText) * 31u + (unsigned int)wt.alertColor;
}

static bool AlertIsNew() {
    const Weather& wt = g.weather;
    if (!g.alertDot || !wt.valid || wt.alertColor < 2) return false;
    return AlertHash() != g.alertSeen;
}

static void AlertMarkSeen() {
    if (!g.weather.valid || g.weather.alertColor < 2) return;
    unsigned int h = AlertHash();
    if (h != g.alertSeen) {
        g.alertSeen = h;
        Wh_SetIntValue(L"alertSeen", (int)h);
    }
}

static void DrawCardHeader(Canvas& cv, TextCtx& t, Fonts& f, int id, float M, float k, const wchar_t* title) {
    float cx = M + 30.0f * k, cy = M + 20.0f * k, r = 11.0f * k;
    RGBA bc = CardBadgeColor(id);
    FillCircle(cv, cx, cy, r + 3.0f * k, [bc](float, float) -> RGBA {
        RGBA c = bc;
        c.a = 0.18f;
        return c;
    });
    FillCircle(cv, cx, cy, r, [=](float, float y) -> RGBA {
        float tt = Clamp01((y - (cy - r)) / (2.0f * r));
        RGBA c = LerpC(LerpC(bc, C(255, 255, 255), 0.25f), bc, tt);
        c.a = 1.0f;
        return c;
    });
    DrawCardIcon(cv, id, cx, cy, k);
    DrawLabel(t, f.head, title, M + 48.0f * k, M + 11.0f * k, 0, g.pal.white);
    if (id == CARD_WEATHER && AlertIsNew()) {

        RGBA dc = AlertColor(g.weather.alertColor);
        float dx = M + 48.0f * k + (float)MeasureWidth(t, f.head, std::wstring(title)) + 11.0f * k;
        float dy = M + 20.0f * k;
        FillCircle(cv, dx, dy, 6.5f * k, [dc](float, float) -> RGBA {
            RGBA c = dc;
            c.a = 0.28f;
            return c;
        });
        FillCircle(cv, dx, dy, 3.6f * k, [dc](float, float) -> RGBA { return dc; });
    }
}

static const int kAlertIcoW = 112, kAlertIcoH = 100;
static const char kAlertIcoB64[] =
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAAAAAAAAAAAAAAEAEnIAqEs+fMBDP"
    "nzAQw6UtEUBAQAwAAAAAAAAAAAAAAAD/qgADAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/wAAAf+AAAIAAAAAAAAkB72cNDbfszNo670ysvnHMtL7yTHP/ckx"
    "z/3JMdHzwzDF5rkwhNerMEBMMzMKAAAAAAAAAAD//wABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/wAAAQAAAAAAAAAAvpY0J8ajNKbdszT488M1///TNP//0zP//88z///PM///"
    "0jH//9Mw///UMP/9yS769sQtv96yLFYAAEkHAAAAAP+AAAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAgAAAACIdzMPsZI1jLuaNt7UrDf/4bY1//XFM/7+yzH9/8sw/f/ML/3/zC/9/8sv"
    "/f/LL/3/yi79/8st///SLv/+zCz/7LwspIp1NRgAAAAA//8AAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAQAAAACAbSQOooY1p7aXOf+4mDf/06w2/O2/NP78yjL//8sx///LMP//yzD//8sv///LLv//"
    "yy///8ou///KLf7+yiv9/8ss/v/QKv/vvynSnYIxOQAAAAD//wABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//8AAf//AAGVgCsMpYg1p6SJOP+nizf7zKY1/ei7NP/5xzP//ssx///LMP//yy///8sw///LL///yi7//8ou"
    "///KLv//yi3//8os///KKv7+yCn8/9Ur//C9Kc6SeTEV//8AAf//AAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAP+AAAIAAAAAmYE1c6OIOP+bgjf8w581/+a6NP/1xTP//ssy//7LMP//yzD//8sv///LL///yy///8ou///KLv//"
    "yi3//8os///KLP//yiv//8kp///JKfv/0Sj/6boqjAAAAAD//wACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAqpIxKpZ+NeqTezf+t5Y2/eC1NP/ywjP/+8oy///LMf//yzD//8sw///LL///yy///8ou///KLv//yi7//8ot"
    "///KLP//yiz//8or///JKf//ySj+/80o/v3IJuvNpS0zAAAAAP+AAAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH//wABSW0kB52ENZ+YgDj/mYA2/dGqNf/wwTT/98Yz//7LMv//yzD//8sw///LMP//yy///8sv///KLv//yi7//8ot///KLf//"
    "yiz//8os///KK///ySr//8kp//7IJv3/0Sj/8b8ntklJSQf//wAB/wAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAJB5MzeXfzb1mYE2/sCeNf7htjX/+Mcz///LMv/+yzH//8sw///LL///yy///8ou///KLv//yi3//8ot///KLf//yiz//8os"
    "///KLP//yiv//8kq///JKP/+yCf//skm/v7KJvrdsihMAAAAAP//AAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB//8AASRJJAecgjexmYE4/6yPNv3WrjX/7b80//3KMv//yzH//8sw///LMP//yy///8sv///KLv//yi7//8ot///KLf//yi3//8os///KK///"
    "yiz//8or///JKv//ySj//8kn///IJv3/zyb/9sIkyJeALhb//wAB//8AAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/4AAAgAAAACYgTVNkns3+5+FNv7IozX+5rk0//bFM///yzH//8sx///LMP//yy///8sv///KLv//yi7//8ot///KLf//yi3//8ot///KLP//yiv//8os"
    "///KK///ySr//8kp///JKP//yCb//sgl/f/PJf/ltyd1AAAAAP//AAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAA//8AAf//AAGWhy0Rm4E2wpZ+OP+3lzb93rQ1//PCM//7yTP//8sx///LMP//yzD//8sv///KLv//yi7//8ou///KLf//yi3//8ot///KLP//yiz//8os///KK///"
    "yiv//8kq///JKf//ySj//8gm///IJf7/zCX+/MUl5sGXLzH//wAB//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAP//AAEAAAAAm4E1gpF6OP+pjDb90as1/+q9NP/6yDP//ssy///LMP//yzD//8sv///LL///yi7//8ou///KLv//yi3//8ot///KLP//yiz//8os///KLP//yiv//8or"
    "///JKv//ySn//8ko///JJ///yCX//sgk/f/SJf/tuyWeAAAAAP//AAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAP+AAAIAAAAAgG00NpF7N/GagTf+wZ41/uS4Nf/1xDP//coy///LMf//yzD//8sv///LL///yi7//8ou///KLv//yi3//8ot///KLf//yiz//8os///KLP//yiv//8or///KK///"
    "ySr//8kp///JKP//ySf//8gm///IJP7/zCT9/skk8NOrKEAAAAAA/4AAAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAACAgAACAAAAAZqANp2ghjj/rpA2/dGqNf/wwTT//coy///LMf//yzD//8sv///LL///yy///8ou///KLf//yi3//8ot///KLf//yiz//8os///KK///yiv//8or///JKv//ySr//8kq"
    "///JKf//ySn//8kn///IJv//yCX//sgj/f/QI//0wCXCiXY7Df//AAH//wABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAACAgAACAAAAAJN7NjSYfzbvpIk2/sumNf7pvDT/+cgz///LMf//yzD//8sv///LL///yi///8ou///KLf//yi3//8ot///KLf//yiz//8os///KLP//yiv//8or///KK///ySr//8kq///JKv//"
    "ySr//8kp///JJ///yCb//8gl///II//+yCP+/8oi/OCyJVMAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD/AA"
    "AB//8AAUlJJAeVfjWolH04/7KTNv3ZsDX/88Mz//7LMv//yzD//8sv///LL///yi7//8ot///KLf//yi3//8ot///KLf//yi3//8os///KLP//yiz//8or///KK///yiv//8kq///JKv//ySr//8kq"
    "///JKf//ySf//8gm///IJf//yCP//sgi/f/NI//7xCKsoosuC/+AAAL//wABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAg"
    "AAAACHczNkln43/qKHNv7IpDb+5Lg0//rIM///yzL//8sv///LL///yy///8ou///KLf//yi3//8ot///KLf//yi3//8os///KLP//yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKf//"
    "ySn//8ko///JJ///yCb//8gk///II///yCL9/8wj/+q5JXwAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAv//AAFkVS"
    "4hk3024ZmBN/+4mDb+3rQ1//bFM//+yzL//8sw///LL///yi7//8ou///KLf//yi3//8ot///KLf//yi3//8os///KLP//yiz//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySn//8kp"
    "///JKP//ySj//8gm///IJf//yCP//8gi/f/LIv/9xyHixp8mKAAAAACAgAACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAi3Y1gp"
    "iAOP+jiDb9yaU1/+q9NP/9yjL//8sx///LL///yi7//8ot///KLf//yi3//8os///KLP//yiz//8os///KLP//yiz//8or///KK///yiv//8kq///JKv//ySr//8kq///JKf//ySn//8kp///JKP//"
    "ySj//8ko///IJv//yCX//8gk///II///xyH8/88i//C8I6gAAFUD//8AAQAAAAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAi3QxOZN8N+mfhT"
    "f+vJs2/tivNf/wwTT//ssy///LMP//yy///8ou///KLf//yi3//8ot///KLP//yiz//8os///KLP//yiz//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySn//8kp///JKf//ySj//8ko"
    "///JKP//yCb//8gl///IJP//yCP//8ci/v7IIf78xyH12q0pPgAAAAD//wACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD//wAB//8AAZJ8NquTfDj/sZM2/d"
    "GqNf/nujT/+sgz///LMP//yy///8ou///KLv//yi3//8ot///KLf//yiz//8os///KLP//yiz//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kp///JKf//ySn//8ko///JKP//"
    "ySj//8kn///IJf//yCX//8gj///HIv//xyH9/8wh//XAIruPgDAQ//8AAf8AAAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAHxqNUiPeDb0nYM2/sOgNf7etD"
    "X/9sUz///LMf//yy///8sv///KLv//yi3//8os///KLP//yiz//8os//7KLP/+ySz//skr//7JK//+ySv//skr//7JK//+yCv//sgq//7IKv/+yCr//skq///JKf//ySn//8ko///JKP//ySj//8ko"
    "///JJ///ySb//8gl///IJP//yCP//8ci///IIf3/zCL/5rQjZgAAAAD//wACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB//8AATMzMwWNdzbBnIM4/6+SNv3SqzX/6700//"
    "3LMv//yzD//8sv///KLv//yi7//8ot///KLP//yiz//8os//3ILP//yyz//84s///OLP//ziv//84r///OKv//zir//84q///OKv//zin//84p///KKP/9xyn//8kp///JKP//ySj//8ko///JKP//"
    "ySf//8km///IJf//yCT//8gj///HIv/+xyH+/8sh/vXAIN3DmigmAAAAAP+AAAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAgAAAACOdzZakXo39qKINv3HozX+5bg0//vIM///yz"
    "D//8sw///KLv//yi7//8ou///KLf//yiz//8os//7KLP//0Cv/+cYs/+K1Lv/gtC3/4bQt/+G0Lf/htC3/4bQt/+G0Lf/hsyz/4bMs/+CzLP/6xiz//9Ao///JKf//ySj//8ko///JKP//ySj//8kn"
    "///JJv//yCX//8gk///II///xyL//8ch//3GH/3/ziH/7LohkQAAAAD//wACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//8AAf8AAAF8ZjMjkHg22pZ+N/+xkjb91Kw1/+6/NP/+yzL//8sw//"
    "/LL///yi7//8ou///KLf//yi3//8ot//7KLf//zSz/uJcy/1tSNP89OzT/Ozk0/zw6M/87OTP/Ozkz/zs5M/87OTP/Ozkz/zs5M/87OTP/W1Ez/6mLMP//yyn//skp//7JKf//ySj//8ko///JJ///"
    "ySf//8gm///IJf//yCT//8gj///HIv/+xyD+/8kg/frEIPTQqShHAAAAAP//AAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAlX43kJV+OP+mijb9xqM1/9+0Nf/2xjP//ssx///LMP//yy"
    "///8ou///KLv//yi3//8ot//7JLf//zyv/sJEy/y8wNP8qLDL/MTEz/zEyM/8xMTP/MDEy/zAwMv8wMDL/MDAy/zAwMv8wMDL/MDAx/ykrMf8vMTT/q40y///OKP/+yCj//8ko///JKP//ySf//8kn"
    "///IJv//yCX//8gk///II///xyL//sYh//zFH/3/zyD/8b0itm1JSQf//wAB/wAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAi3QyLop2NuiXfjf+vZs2/tmwNf/xwjP//csy///LMP//yy///8sv//"
    "/KLv//yi7//8ot//7JLf//zCz/778u/05INP8tLjL/NzYz/zQ0M/8zMzL/MzMy/zMzMv8zMzL/MzMy/zMzMv8zMzL/MzMy/zIxMf81NDL/MTEx/1lQNP/vvy3//8sn//7IKP//ySj//8kn///JJ///"
    "yCb//8gm///IJf//yCT//8gj///HIv/9xSH+/MYf/v7IIPngsSJLAAAAAP//AAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH//wABQEAgCI54NrKOeTj/pYk2/cynNv/mujT/+8ky///LMf//yzD//8sv///KLv//yi"
    "7//8ot///KLP/+ySz//84r/+O2MP8+OzT/MTIz/zQ0M/8zMzP/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8xMTH/MDAx/0ZAMf9vYTb/37Mw///LJv/+yCj//8kn///JJ///ySf//8gm"
    "///IJv//yCb//8gk///II///xyL//sch//zFH/3/yiD/878gx66UNhP//wAB//8AAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAIx1M22Vfjf9moE2/bqZNv/XrjX/8ME0//7LMv//yzD//8sv///LL///yi7//8ot//"
    "/KLf//yiz//sks///OK//muC7/QD0z/zAxM/80NDP/MzMz/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zQzMf9cUTP/ln85/+2+Mf/+yCf//8ko///JJ///ySf//8kn///IJv//"
    "yCb//8gm///IJP//yCP//8ci///HIf/+xyD//MUf/f/JIP/otyKHAAD/Af//AAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD//wABAAAAAGhdLhaRejbYlH03/6eLNv3MpzX/4rc0//rIM///yzH//8sv///KLv//yi7//8ou///KLf//yi"
    "3//8os//7JLP//ziv/5bcs/z88M/8wMTP/NDQz/zMzM/8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zAxMf8+OzH/cWI0/7KVO//ywCz//sgm///JKP//ySf//8kn///JJ///yCb//8gm"
    "///IJv//yCX//8gk///II///xyL//8gh//rDIP79xx/+98Eh8cigKDMAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//8AAQAAAAKCbzWBkXs4/5mANv25mTb/1681//DBM//+yzL//8sw///LL///yi7//8ou///KLf//yi3//8ot//"
    "/KLP/+yiv//8wr//XCLP9YTzT/LS4z/zU0M/8zMzP/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zExMf8xMTH/RD8y/2tdNP+3mDn/+cUp//7IJ///ySj//8kn///JJ///ySf//8gm///IJv//"
    "yCb//8gl///IJP//yCP//8ci///HIf/9xiD/+8Qf/f/LH//yvCCdAACAAv//AAIAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAgAAAACAaDAgmIA25495N/+ukDb9zKc1/+a6NP/7yTP//8sx///LMP//yy///8ou///KLv//yi3//8ot///KLP//yi"
    "z//8or//7JK///ziv/cmIz/ygrM/81NTP/MzMz/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8xMTH/MjIx/0VAMf94ZzX/sZM3//jEKf//ySf//8ko///JJ///ySf//8kn///IJv//yCb//8gm"
    "///IJf//yCT//8gj///HIv//xyH//8cg//3FH/79xh/9+8Yf+dWnJFQAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAABj3k1lI13N/6fhTb+xKE2/96zNP/0xDP//8sx///LMP//yy///8sv///KLv//yi7//8ot///KLf//yiv//8or//"
    "/KK//9ySv//9Ar/4NuMv8pKzT/NTUz/zMzM/8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zMzMf9EPzH/fWw2/6SINP/3wyb//8on///JJ///ySf//8kn///JJ///yCb//8gm///IJv//"
    "yCX//8gl///IJP//yCP//8ci///HIf/+xiD/+8Qf/f/MIP/wvCDBYGBACP//AAH/AAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAjHg3M5B5NvGSezf/tJU2/s+oNf/pvDT//coy///LMf//yzD//8sv///KLv//yi7//8ot///KLf//yiz//8os///KK///yi"
    "v//cgr///RKv+tjjH/Ky00/zU0M/8zMzP/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zExMf81NDH/VUwy/5Z/OP/LpjX/+8Um///JJ///ySj//8kn///JJ///ySf//8kn///IJv//yCb//8gl"
    "///IJf//yCX//8gj///HIv//xyH//8ch//zFH//6xB/+/scf/N+vJGkAAAAA//8AAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH//wABZkwzCpV+NqaWfzj/o4g2/caiNv/asTX/9MQz///MMv//yzD//8sv///KLv//yi7//8ot///KLf//yi3//8os///KLP//yiv//8or//"
    "3IK///0in/u5kw/ywtNP80NDP/MzMz/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8xMTH/NDMx/2VZNP+hhzn/1q0y//7JJv//ySj//8ko///JJ///ySf//8kn///JJ///yCb//8gm///IJf//"
    "yCX//8gl///IJP//yCP//8ci///HIf/9xiD//cYe/fzGH//zvR/htZQxHwAAAACAgAACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAI94NkKPeTf7kns2/rGTNv7VrjX/57o0//zJMv//yzH//8sw///LL///yi7//8ou///KLf//yi3//8ot///KLP//yiv//8or///KK//9yC"
    "v//88p/86mL/83NjT/MjIz/zQzM/8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zY1Mf9qXTT/nYQ6/9CnLf//yib//sko///JKP//ySf//8kn///JJ///ySf//8gm///IJv//yCX//8gl"
    "///IJf//yCT//8gj///HIv//xyH//sch//3GH//5wh79/8gf/+e2IoEAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB//8AAV1dLguPeTa4j3k3/6OINv2+nDb/2rE1//XEM///yzH//8sw///LL///yy///8ou///KLf//yi3//8ot///KLP//yiz//8or///KK///yiv//skr//"
    "/MKv/vviz/SUM0/y8vM/80NDP/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zAwMf9CPjL/WU8z/6WKOv/0wi3//sgl///JJ///ySj//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJf//"
    "yCX//8gk///II///yCP//8ci///HIf/9xiD/+8Qf/v7HH/76wx/tyqMsOgAAAAD//wACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAA//8AAQAAAACJdjZ3k303/5iANv27mjb+0ak1/+u9NP/9yzL//8sw///LMP//yy///8ou///KLv//yi3//8ot///KLP//yiz//8or///KK///yiv//8or//7JK///yy"
    "r/9cIr/1NLM/8tLjP/NDQz/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8vMDH/Qz8y/2hbNP+6mjn/88Eq///JJ///ySj//8ko///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCX//8gl"
    "///IJP//yCT//8gj///HIv//xyH//8ch//3FH//6xB/9/80g/++8IatVVSsG/4AAAgAAAAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAgIAAAv//AAFsXTYhi3U24pB6N/+qjjb9zac1/+O4NP/6yDP//8wx///LMP//yy///8sv///KLv//yi7//8ot///KLf//yiz//8os///KK///yiv//8or///KK///ySv//skp//"
    "/MK/94ZzL/KSsz/zY1M/8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/Ly8x/0VBMv92ZjX/vpw4/+68J///yij//8ko///JKP//ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gl///IJf//"
    "yCT//8gk///II///xyP//8ch///HIf/9xiD/+sMf//vFH/38xR/81awnYgAAAAD//wACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAICAAAIAAAAAiHM1gZJ8OP+cgjb9vZs2/9evNf/xwjT//8wy///LMP//yy///8sv///LL///yi7//8ot///KLf//yiz//8os///KK///yiv//8or///KK///yiv//8kq//3HKv//0S"
    "n/h3Ew/ycqNP82NTP/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/y8vMf9JRDL/cGE1/8KfNv/8xyf//8ko///JJ///ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJf//yCX//8gk"
    "///IJP//yCT//8gj///HIv//xyH//scg//vEH//5wx79/8gf//W/IMyAgDcO//8AAf//AAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAICAAAIAAAAAcmM0MY13N+Wagjf+rpE2/sqlNf/jtzT/+cgy///LMf//yzD//8sv///LL///yi7//8ou///KLf//yi3//8os///KLP//yiv//8or///KK///yiv//8or///JKv/9xyr//9Ep/5"
    "yBMP8pLDT/NTQy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8uLzH/UEky/4l0OP+ykjH//ccm///JKf//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCX//8gl///IJf//"
    "yCT//8gk///II///xyL//8ci///HIf/9xSD/+8Qf//nCH/79yB/+57YidwAAAAD//wABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAGAgAACOzsnDZF7NrWVfzj/nII2/bybNv/WrjX/7sA0//7LMv//yzD//8sw///LL///yi7//8ou///KLv//yi3//8ot///KLP//yiz//8or///KK///yiv//8or///KK///ySr//ccq///QKf/GoS"
    "//LzE0/zMzMv8zMzL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjH/Ly8x/1NLMv+OeTj/3rQz//vFJf//ySn//8ko///JKP//ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gl///IJf//yCX//8gk"
    "///IJP//yCT//8gi///HIv//xyH//8cg//vEIP/8xR79/8kf//bAHtq5lyMWAAAAAP//AAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAAC"
    "AAAAAIBrM2SXfzf/mIA2/a2PNv/Iozb/47c0//nIM//+yzH//8sw///LL///yy///8ou///KLv//yi3//8ot///KLf//yiz//8os///KK///yiv//8or///KK///ySr//8kq//3HKv//0Cn/zKQt/z"
    "AxM/8zMzP/MzMz/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zAxMf9XTjP/kXs4/+C0Lv/9xyf//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCb//8gk///IJP//"
    "yCT//8gk///II///yCP//8ch///HIf/9xiD/+8Qf//vEH/3+yB/+67kfiwAAAAD//wABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAAC//8AAWxd"
    "LiGMdzXXlX03/p6DNv3Anjb/3LI1//TEM//+yzL//ssw///LMP//yy///8sv///KLv//yi7//8ot///KLf//yi3//8os///KLP//yiv//8or///KK///yiv//8kq///JKv/+yCr//8wp/+e5Lf9JQz"
    "T/LzAz/zQ0M/8yMjL/MjIy/zIyMv8yMjL/MjIy/zExMf8yMTH/XVIz/6iNOv/ouSv//8kn///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJf//yCX//8gk"
    "///IJP//yCP//8gj///HIv//xyH//8ch//3FH//7xB/+/cYe/vnDH/TQpSRHAAAAAP//AAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgICAAgAAAACEcjV0"
    "jnk4/495Nv20lTb/1aw1/+2/NP/+yzL//8sx///LMP//yy///8sv///KLv//yi7//8ou///KLf//yi3//8ot///KLP//yiz//8or///KK///yiv//8or///JKv//ySr//skq///KKv/8yCv/WU8z/y"
    "stM/81NDP/MjIy/zIyMv8yMjL/MjIy/zIyMv8xMTH/MjIx/2JWM/+skDn/88Eq//3HJv//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJv//yCX//8gl///IJf//"
    "yCT//8gj///II///xyL//8ch///HIf/+xiD/+8Qf//rDH/3/zCD/8bwhtABAQAT//wABAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAgAAAACCbDMtinU15Yx2"
    "N/6kiTb+w6A2/+C1NP/4xzP//8sx///LMP//yy///8sv///LL///yi7//8ou///KLf//yi3//8os///KLP//yiz//8or///KK///yiv//8or///KK///ySr//8kq///JKv//ySr//cgq/2NXM/8rLT"
    "P/NTQz/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zEyMf9lWTT/n4Q1//K/KP//ySf//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gl///IJf//yCX//8gk"
    "///IJP//yCT//8gj///HIv//xyH//8ch//3GH//7xB/+/MUe/fvGH/ndsCVaAAAAAP+AAAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAf//AAFVVSsGj3g2sJB6OP+ZgDb9"
    "vJo2/9WtNf/rvTT//coy///LMP//yzD//8sv///LL///yy///8ou///KLf//yi3//8ot///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//ccq///RKv+ReTH/Jyoz/z"
    "Y1M/8yMjL/MjIy/zIyMv8yMjL/MjIy/zExMf8zMjH/b2E1/8qlN//5xCf//8kp///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJf//yCX//8gl///IJP//"
    "yCT//8gk///II///xyP//8ci///HIf/+xyD//MQf//jCH/39yB//9cAf1qaAJhQAAAAAgIAAAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAiHM0SY55NvmPeTb9sZI2/sul"
    "Nv/kuDT/98Yz///LMf//yzD//8sw///LL///yi7//8ou///KLv//yi3//8ot///KLf//yiz//8os///KLP//yiv//8or///KK///yiv//8or///JKv//ySr//8kq//zHKv//0in/oYUv/ygrNP81NT"
    "P/MjIy/zIyMv8yMjL/MjIy/zIyMv8xMTH/MzIw/3poNv/dtDb/+sUn///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gk"
    "///IJP//yCP//8gj///II///xyH//scg//7GH//7xB//98Ef/f7IH//lsyCHAAD/Af//AAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAP8AAAH//wABeFotEZN9NsCVfTj/pIk2/b+dNv/WrjX/"
    "8sI0///MMv//yzD//8sw///LL///yi7//8ou///KLv//yi3//8ot///KLf//yi3//8ot///KLP//yiv//8or///KK///yiv//8or///JKv//ySr//8kq///JKv/9yCr//9Ao/8OeMP8yMjT/MzMy/z"
    "MyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zMyMP+Abjf/4rUy//jDJv//yij//8ko///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gl///IJf//yCX//8gk///IJP//"
    "yCT//8gj///II///yCP//8ci///HIf/+xiD//cUf//rDHv78xh//9L8g8MKZKTL//wAB//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD//wABAAAAAIl0NoCVfjj/l382/biXNv/TrDX/7L00//3K"
    "Mv//yzH//8sw///LL///yy///8ou///KLv//yi7//8ot///KLf//yi3//8ot///KLf//yiz//8or///KK///yiv//8or///KK///ySr//8kq///JKv//ySr//cgq///OKf/ary7/NzY0/zIyM/8zMz"
    "L/MjIy/zIyMv8yMjL/MjIy/zAwMf84NjH/kns5/+q7MP/6xSb//8kp///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJf//yCX//8gl///IJP//yCT//8gk"
    "///IJP//yCP//8gj///HIv//xyH//8cg//3FIP/7xB//+MIe/f/KH//uuyCZAAAAAP//AAIAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAHVmMzKJdTbwkns3/qWKNv7IozX/4rc0//nHM///yzH/"
    "/8sw///LL///yy///8sv///KLv//yi7//8ou///KLf//yi3//8ot///KLf//yi3//8os///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq//3IKv//zSn/4LMs/z07NP8wMTP/MzMy/z"
    "IyMv8yMjL/MjIy/zIyMv8wMTH/ODYx/5yDOf/tvSv//MYm///JKf//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCX//8gl///IJf//yCT//8gk///IJP//"
    "yCT//8gj///II///yCP//8ch///HIP/+xiD/+8Qf//rDHv76wx7++sQf7tqtJT4AAAAA/4AAAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAgAAAAKFcjWbmYE4/6KHNv28mjb/2K81/+/ANP/9yzL//8sx///L"
    "MP//yy///8ou///KLv//yi7//8ou///KLf//yi3//8ot///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv/+yCr//8oo//fEK/9cUjT/Kywy/zQzMv8yMj"
    "L/MjIy/zIyMv8yMjH/LzAx/zw5Mf+jiDj/8sAp//zHJ///ySj//8ko///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCT//8gk"
    "///II///yCP//8gj///HIv//xyH//8ch//3FH//6wx//+MIe/f/KH//yvCC/YEBACP//AAH/AAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/4CAAgAAAACDbjVIjng39ZV9Nv22ljb+z6k1/+y+NP/8yTL//ssx///LMP//yy//"
    "/8sv///KLv//yi7//8ou///KLv//yi3//8ot///KLf//yiz//8os///KLP//yiv//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq//7JKf//zCr/aFoy/ykrM/80NDL/MjIy/z"
    "IyMv8yMjL/MjIx/y8wMf9QSTP/lX02/+28KP/+ySj//8ko///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gk///IJP//"
    "yCP//8gj///II///xyL//8ci///HIf/+xyD//MUg//nDH//6wx79/cYe++SzImgAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYCAAAI5ORwJjHY2qZN9OP+UfTb9v502/9uyNf/3xjP//8sx///LMP//yy///8ou///K"
    "Lv//yi7//8ot///KLf//yi3//8ot///KLf//yi3//8os///KLP//yiz//8or///KK///yiv//8or///KK///ySr//8kq///JKv//ySr//8kq///JKv/9yCn//84o/4ZxMv8oKzP/NDQy/zIyMv8yMj"
    "L/MjIx/zExMf80MzH/Vk40/6WJNP/wvib//sko///JKP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJv//yCX//8gl///IJf//yCT//8gk"
    "///IJP//yCP//8gj///HIv//xyH//8cg//7GIP/7xSD/+sMe/f7HH//0vh/gwZUsHQAAAAD/gAACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAfmk2VY14N/2agTb9s5M2/symNf/ouzT//coy///LMf//yzD//8sv///KLv//yi7/"
    "/8ou///KLf//yi3//8ot///KLf//yi3//8os///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySr//Mcp///SKP+tjjH/KCsz/zQ0Mv8yMjL/MjIy/z"
    "ExMf8yMTH/MzIx/2VZNf/asTX/9cEm//7JKf//ySj//8ko///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJv//yCb//8gl///IJf//yCX//8gk///IJP//"
    "yCT//8gj///II///xyL//8ci///HIf/+xyD//cUg//vEH//3wR79/8ke/+e1IZUAAFUD//8AAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAP8AAAH//wABWE4xGo13NsyVfTf/q442/c+pNf/jtzT/+ccz///MMP//yzD//8sv///KLv//yi7//8ou///K"
    "Lv//yi3//8ot///KLf//yi3//8os///KLP//yiz//8or///KK///yiv//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq//zHKf//0in/rI0u/ygrM/80NDL/MjEx/zExMf8yMj"
    "H/QT0y/0VAMf+Bbzf/4bYz//fCJf//ySj//8ko///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCT//8gk"
    "///II///yCP//8gj///HIv//xyH//8ch//7GIP/7xB//+cMf/v3HHv75wh/1xJ8mPQAAAAD//wACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAINuNH+Wfjj/m4I2/b2bNv/etDT/9MQz//7LMf//yzD//8sv///LL///yi7//8ou///KLf//yi3/"
    "/8ot///KLf//yi3//8os///KLP//yiz//8or///KK///yiv//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq///JKf/9yCr//88p/8+mLf82NTT/MzIy/zMyMv8wMTH/PDkx/1"
    "ZNM/9uYDT/qIw6/+G0L//7xib//8kp///JKP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gk///IJP//"
    "yCP//8gj///II///xyL//8ci///HIf//xyD//cUf//vDH//4wh79/8of/+26IKYAAAAA//8AAQAAAAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAHRmMzeVfTfpln03/rKUNv7RqjX/7L40//7LMv/+yzH//8sv///LL///yi///8ou///KLv//yi3//8ot///K"
    "Lf//yi3//8ot///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8or///KK///ySr//8kq///JKv//ySr//8kq///JKv//ySn//8kp//7JKv/7yiv/Z1o0/yYpMv82NTL/Qj4y/2FVM/+AbT"
    "X/jng3/8OhOv/wvir//cco///JKf//ySj//8ko///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCb//8gl///IJf//yCX//8gl///IJP//yCT//8gk"
    "///II///yCP//8gj///HIv//xyH//8ch///HIP/7xB//+cMe/vrEHv75wx702q0iSwAAAAD/gAACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABgIAAAgAAAAOTfDWomYA5/5uCNv3NpzX/5Lg0//rJMv//yzH//8sw///KLv//yi7//8ou///KLf//yi3//8ot///KLf//yi3/"
    "/8ot///KLP//yiz//8os///KLP//yiv//8or///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySr//8kp///JKf/9yCr//80p/9OqLf9HQjT/Jykx/1VMM/+Gcjf/sJI6/8"
    "WiPP/svTD/+sUn//7IKf//ySj//8kp///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCT//8gk///IJP//"
    "yCP//8gj///II///xyL//8ci///HIf//xyD//MYg//nDH//3wR79/8og//S+H8t2YicN//8AAf//AAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAgAAAACGczRdknw3+ZZ+Nv21lTX/3LI0//DBNP/+yzL//8sw///LL///yi7//8ot///KLf//yi3//8ot///KLf//yi3//8os///K"
    "LP//yiz//8os///KLP//yiz//8or///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKf//ySn//8kp//7IKf//zij/4LMs/5B4M/+HcjX/s5U3/+C2N//8yC"
    "///8kn///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gj"
    "///II///yCP//8ci///HIv//xyL//8ch//7GIP/8xB//+cMe//nCHv39xx/+4bEjdgAAAAD//wACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//8AAf//AAGAaC4Wjnc1zZJ7OP+rjjb91a01/+2+NP/6yTL//ssx///LL///yy///8ou///KLf//yi3//8ot///KLf//yi3//8ot///KLP//yiz/"
    "/8os///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySn//8kp///JKf//ySn//sgp///NKf//0Cn/+MUq//nGK///ySj//8ko//"
    "/JKf//ySn//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gk///IJP//"
    "yCP//8gj///II///xyL//8ci///HIf//xyH//cYg//zEH//5wx79+sMf//W/H+i1jSgmAAAAAP+AAAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAjHc2eo95OP+ehDf8xKE2/+i7NP/7yTP//8sx///LL///yy7//8ou///KLf//yi3//8ot///KLf//yi3//8ot///KLP//yiz//8os///K"
    "LP//yiz//8os///KLP//yiv//8or///KK///yiv//8or///KK///ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kp///JKf//ySn//8kp///JKP/+yCr//cgp///KKf//yij//8kp///JKf//yS"
    "n//8kp///JKf//ySn//8ko///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk"
    "///II///yCP//8gj///HIv//xyH//8ch///HIf/9xR//+sQf//jCHv3/yB7/67khozMzZgX//wABAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAP//AAH/AAABgHA0Iop1N9aRejf/tpY2/dauNf/xwTP//ssx///LMP//yy///8ou///KLf//yi3//8ot///KLf//yi3//8os///KLP//yiz//8os///KLP//yiz/"
    "/8or///KK///yiv//8or///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySn//8kp///JKf//ySn//8kp///JKf//ySn//8kp///JKf/+yCn//sgp//7JKf//ySn//8kp//"
    "/JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gk///II///"
    "yCP//8gj///II///xyL//8ci///HIf//xyD//scf//vEH//7xB/++MIf/vfCH/rNoydIAAAAAP//AAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAI54NYyWfzn/o4g1/c2nNf/puzT/+8ky///LMP//yy///8ou///KLv//yi3//8ot///KLf//yi3//8ot///KLP//yiz//8os///KLP//yiz//8os///K"
    "K///yiv//8or///KK///yiv//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kp///JKf//ySn//8kp///JKf//ySn//8kp//3IKf/9xyn//8kp///KKf//ySn//ccp//3IKf//yS"
    "j//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gk///IJP//yCT//8gj"
    "///II///yCP//8gi///HIv//xyH//8ch///HIP/9xh//+sMf//jCH/3/yh//77sesWZmZgX//wABAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAACAgAACAAAAAIBuNCyXfjbmnIM3/sKfNf7kuDT/+ccz///LMf//yy///8ou///KLv//yi7//8ot///KLP//yiz//8os///KLP//yiz//8os///KLP//yiz//8os///KLP//yiv/"
    "/8or///KK///yiv//8or///JKv//yiv//8or///KK///ySr//8kq///JKv//ySr//8kq///JKf//ySn//8kp///JKf//ySn//sgp///JKf//zyj//9Ep//7JKf/7xyn//8kp///RKP//zij//sgo//"
    "7IKP//ySj//8ko///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gk///IJP//"
    "yCP//8gj///II///xyL//8ci///HIf//xyD//sYg//vEH//5wx/++cIf/vrDH/jmtCBHAAAAAP//AAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAB//8AAVVVAAOWfzavlH04/66QNf3ZsDX/9cQz//7LMv//yzD//8sv///KLv//yi7//8ot///KLf//yi3//8os///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8or///K"
    "K///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKf//ySn//8kp///JKf//ySn//cgq///NKP//zCr/zKQu/5R7Mf9lWDL/V04x/2ZZMv+XfTD/2K4t///OKP//yy"
    "f//sgp///JKP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJv//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gk///IJP//yCT//8gj"
    "///II///yCP//8ci///HIv//xyL//8cg///HIP/9xiD/+sMf//fBHv39xh7/9b8fxqqOKhL//wAB//8AAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAgIAAAgAAAACbgDRUln02+ZN7Nv7FoTb+6r00//3KMv//yzH//8sv///LLv//yi7//8ot///KLf//yiz//8os///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8or///KK///yiv/"
    "/8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq///JKf//ySn//8kp///JKf//ySn//cgq///QKP/csS7/cmEz/zQ0NP8oKjT/Ky0z/ystM/8rLTP/KCs0/zk3NP+KdDH/8sEr//"
    "/MJ//+yCn//8ko///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///II///"
    "yCP//8gj///II///xyL//8ci///HIf//xyH//sYg//vEIP/4wh//98Ee/f/HH//mtSCGAAAAAP//AAEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgI"
    "AAAv//AAFzZjMolHw25JB6N/+zlDb+1681//nHM///zDH//8sw///KLv//yi7//8ot///KLP//yiz//8os///KK///yiz//8os///KLP//yiv//8or///KK///yiv//8or///KK///ySr//8kq///J"
    "Kv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySn//8kp///JKf//ySn//sgp///OKP/MpS7/RUA0/ycqM/8zMzP/NTUz/zU0M/80NDP/NTQz/zU1M/8xMjP/Jyoz/2RYNP/svS"
    "v//8wn//7IKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gk///IJP//yCP//8gj"
    "///II///yCP//8gj///HIv//xyH//8ch///HIf/9xSD/+sMf//jCH/77xB7+9L4e78WaJTAAAAAA/4AAAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAP+AgA"
    "IAAAAAk3w2cZZ/OP+fhTb9z6g1/+2/NP/+yzL//8sw///KLv//yi3//8ot///KLf//yiz//8or///KK///yiv//8or///KK///yiv//8or///KK///yiv//8or///KK///yiv//8kq///JKv//ySr/"
    "/8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kp///JKf//ySn//sgp///MKP/htSv/SEM1/ystM/83NjP/NDMz/zIyMv8zMzP/MzMz/zIyMv8yMjL/MzMy/zU0Mv8sLjL/fmsz//"
    "zKKf/+ySj//sko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gk///IJP//yCT//8gj///II///"
    "yCP//8gj///II///xyL//8ci///HIf//xyH//8cg//3FH//6wx//9sAd/f/IH//uuyGaAACAAv//AAEAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAAAIAAAAAjn"
    "cvK5uCNuCcgzf+wZ01/ee6NP/7yTL//8sx///LLv//yi7//8ot///KLf//yiz//8os///KK///yiv//8or///KK///yiv//8or///KK///yiv//8kq///KK///yiv//8or///JKv//ySr//8kq///J"
    "Kv//ySr//8kq///JKv//ySr//8kq///JKv//ySn//8kp///JKf//ySn//8kp//7HKf//zyn/g28y/ycqM/83NjP/MzMz/zMzM/8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjH/MzMx/0lENP/FoD"
    "D//80n//7IKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gk///IJP//yCT//8gk///II///yCP//8gj"
    "///II///yCP//8ci///HIv//xyL//8ch///HIP/9xiD/+sQf//fBHv76xB/9+cMf+NqsIlP//wAB//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAACAAAAAJqBNZ"
    "qbgzn/qIw2/dmvNf/6yTP//8sx///KL///yi3//8ot///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr/"
    "/8kq///JKv//ySr//8kq///JKv//ySn//8kp///JKf//ySn//8kp//7IKf//zCj/47Us/0RANP8wMDL/NDQz/zIyMv8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zY1Mf9RSTP/oIY2//"
    "/MKf/+yCf//8ko///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCP//8gj///II///"
    "yCP//8gj///HIv//xyL//8ci///HIf//xyD//sYg//vEH//4wh//9b8f/P/KH//vuR+sAAAAAP//AAEAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD/gAACAAAAAJR+NE+YgDf1mo"
    "E2/caiNf/tvzT//8wy//7LMP//yi7//8ot///KLf//yiz//8or///KK///yiv//8or///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///J"
    "Kv//ySr//8kq///JKv//ySr//8kp///JKf//ySn//8kp///JKf/8xyn//9Eo/7uYLv8rLTT/NTQz/zMzM/8yMjL/MjIy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zAwMf9APDH/aVw0/8mmO///zC"
    "v//sgm///JKP//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gk///IJP//yCT//8gj///II///yCP//8gj"
    "///II///yCP//8ci///HIv//xyH//8ch///HIP/9xiD/+sMf//fBHv/4wh79+sMe8+CuImIAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAgAAC//8AAWhdLhadhDbQmoE4/7GSNv"
    "3bsjT/+sgz///LMP//yi///8ot///KLf//yiz//8or///KK///yiv//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKf//ySn/"
    "/8kp///JKf//ySn//8kp///JKf//ySn//8kp///JKf//ySn//Mcp///SKP+6mDD/Ky00/zU0M/8zMzP/MjIy/zIyMv8yMjL/MjIy/zIyMv8xMTH/MTEx/zExMf86ODH/U0sz/4l0Nv/Oqjz/+ccv//"
    "/JJv//ySf//8kn///JJ///ySf//8kn///JJ///yCb//8kn///IJv//yCb//8gm///IJv//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gk///IJP//yCT//8gk///II///yCP//8gj///II///"
    "yCP//8gj///HIv//xyL//8ci///HIf//xyH//scg//vEIP/5wh//98Ee/f/IH//xvR/gs44vGwAAAAD/gAACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgIAAAgAAAACZgDZkmoE3/5Z9Nv7LpjX/7r"
    "80///LMf//yy///8ou///KLP//yiz//8os///KK///yiv//8or///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySn//8kp///JKf//ySn//8kp///J"
    "Kf//ySn//8kp///JKf//ySn//8kp///JKf//ySj//8ko//zHKP//0ij/upgw/ystNP81NDP/MzMz/zIyMv8yMjL/MjIy/zIyMv8xMTH/MTEx/zAxMf84NjH/UEky/2hbNP+ehDf/zKg8//TEL///yS"
    "b//8ko///JJ///ySf//8kn///JJ///yCb//8gm///JJ///yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCP//8gj///II///yCP//8gj"
    "///II///xyL//8ci///HIv//xyH//8ch///HIf/9xiD/+sMg//jBHv/3wh79/cUf/+W1IZQAAIAC//8AAQAAAAAAAAAAAAAAAAAAAAAAAAAA//8AAf//AAGMczMooYY23qCGN/62ljb94LY1//zKMv"
    "//yzD//8ou///KLf//yiz//8or///KK///yiv//8or///KK///yiv//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kp///JKf//ySn//8kp///JKf//ySn/"
    "/8kp///JKf//ySn//8kp///JKP//ySj//8ko///JKP/8xyn//9En/7mWL/8qLTT/NDMy/zIyMv8yMjL/MjIy/zIyMv8yMjL/MTEx/zExMf8xMDH/S0Uy/25fNP+JdTb/pYo4/9KsO//6xyv//8km//"
    "/JJ///ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gk///IJP//yCT//8gj///II///yCP//8gj///II///"
    "yCP//8ci///HIv//xyL//8ci///HIf//xyH//8cg//3GIP/7xB//98Ee/vnDH/73wR71xp4oOgAAAAD//wACAAAAAAAAAAAAAAAAAAAAAP+AAAIAAAAAoYY2k6GHOP+nizf81K01//bGM///zDH//8"
    "ov///KLf//yiz//8os///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKf//ySn//8kp///JKf//ySn//8kp///JKf//ySn//8kp///J"
    "Kf//ySn//8kp///JKP//ySj//8ko///JKP//ySj//sgp///NJ//bryz/Pjw0/zAxMv8yMzL/MjIy/zIyMv8yMjL/MjIy/zExMf8xMTH/Pzwy/2JXNP+Iczb/kns3/6uOOf+9nDf/+MQn///JJv//yC"
    "f//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gk///IJP//yCT//8gk///II///yCP//8gj///II///yCP//8gj"
    "///HIv//xyL//8ci///HIv//xyL//8ch///HIP/+xiD/+8Qf//jCH//1wB79/scf/+67IKhVVVUG//8AAQAAAAEAAAAAAAAAAP+AAAIAAAAApIc1NZ+ENuabgzb+upk2/uu+NP//zDH//8sw///KLf"
    "//yiz//8os///KK///yiv//8or///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKf//ySn//8kp///JKf//ySn//8kp///JKf//ySn//8kp///JKf//ySn//8kp///JKf//ySj/"
    "/8ko///JKP//ySj//8ko///JKP//ySf//8kn///JJ//9yCj//88n/31qMv8mKTP/NjUy/zIyMv8yMjL/MjIy/zExMf8wMTH/MjIx/0tFMv93ZjX/mYE3/6OIN/+3mDv/5rky//7HJP//yCb//8kn//"
    "/IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCP//8gj///II///yCP//8gj///II///"
    "xyL//8ci///HIv//xyL//8ci///HIf//xyD//scg//zFH//4wR//98Ee/vfBHv35wx783K4jXgAAAAD//wACAAAAAAAAAAH//wABXUYuC6SINrilijj/rpA2/d2zNf/7yTL//8sw///LL///yi3//8"
    "os///KLP//yiv//8kq///JKv//ySr//8kq///JKv//ySr//8kq///JKv//ySr//8kp///JKf//ySn//8kp///JKf//ySn//8kp///JKf//ySn//8ko///JKP//ySj//8ko///JKP//ySj//8ko///J"
    "KP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//cgn///NJv/Zrir/Qj81/y0uM/82NTL/MjIy/zIyMv8wMDH/NDMx/0hCMf9zYzX/j3g2/6qOOP+/njz/2LA5//nFKP//ySb//8kn///JJ///yC"
    "b//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCP//8gj///II///yCP//8gj"
    "///HIv//xyL//8ci///HIf//xyH//8ch///HIf/8xCD/+MIf//nCH//2wR79/cYf//W/IMiqiDMP//8AAf//AAH/gAACAAAAAKmNNEqmijb6lX02/s+pNf7tvjT//8wx///LL///yi7//8os///KLP"
    "//yiv//8kq///JKv//ySr//8kq///JKv//ySr//8kp///JKf//ySn//8kp///JKf//ySn//8kp///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj/"
    "/8ko///JJ///ySf//8kn///JJ///ySf//8kn///JJ//+yCf//88m/8ehLf8+PDX/KCsy/zQzMv8zMzH/NDMx/0xFMv9xYjT/nII3/7CSOf+5mjv/0Ks6/+28Kf/6xSX//8gm///IJ///yCb//8gm//"
    "/IJv//yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCT//8gk///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///HIv//"
    "xyL//8ci///HIv//xyH//8ch///HIf//xyD//scg//zEIP/6wyD/98Af//S/H/77xB7+7bgiYQAAAAD//wACAAAAAJZ4LRGmijbIqIw4/6uONv3dszX/+8ky///LL///yi7//8ot///KK///yiv//8"
    "kq///JKf//ySr//8kq///JKv//ySn//8kp///JKf//ySn//8kp///JKf//ySn//8kp///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySj//8ko///J"
    "KP//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8kn//3HJ///zyb/z6cs/1xSM/8tLzP/LC0y/0tFM/91ZTb/n4U5/7OVO//NqTz/z6k2/+28KP/4wyP//scm//7IJv//yCb//8gm///IJv//yC"
    "b//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCP//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci"
    "///HIv//xyL//8ch///HIf//xyH//8ch///HIP/+xiD/+8Qg//fBH//3wR79/MUf//S+Hsm7mTMPAAAAAAAAAACjiDU6q482+qqNNv/KpDX+78Az///MMf/+yi7//8os///KLP//yiv//8kq///JKv"
    "//ySr//8kp///JKf//ySn//8kp///JKf//ySn//8kp///JKf//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf/"
    "/8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//cgn///NJv/5xSf/u5gt/5R8Mv99azL/nYM1/9mwOP/VrTT/2K0s//S/I//4wyT//scm///IJv//yCX//8gl///IJf//yCX//8gl//"
    "/IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci///HIv//"
    "xyL//8ci///HIf//xyH//8ch///HIP//xyH//scg//3GIP/6xB//+MEe/vbBHv73wR7847YfSQAAAAAAAAAAsJA1bqmNOP61ljb957o0//7LMf//yi///8ot///KK///yir//8kq///JKf//ySn//8"
    "kp///JKf//ySn//8kp///JKf//ySn//8ko///JKP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//8kn///J"
    "J///ySf//8kn///IJv//yCb//8gm///IJv//yCb//8gm///IJv/9xyb//8km///QJf//zib//Mcm//rFJv/6xSX//MUj//7HI///yCT//8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yC"
    "X//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci///HIv//xyL//8ci"
    "///HIf//xyH//8ch///HIf//xyD//8ch///HIP/+xiD/+8Qf//jBH//4wR78/8kf//G9Hn8AAAAAVVUAA7uaNqG3lzj/zqg1/frIMv//zDD//8ou///KLP//ySr//8kq///JKf//ySn//8kp///JKf"
    "//ySn//8kp///JKf//ySj//8ko///JKP//ySj//8ko///JKP//ySf//8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///yCb//8gm///IJv//ySf//8kn///IJv//ySf/"
    "/8kn///JJ///yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl//7IJf/9xyb//ccm///IJf//yCX//scm///IJf//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl//"
    "/IJf//yCX//8gl///IJf//yCT//8gk///IJP//yCT//8gk///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci///HIv//xyL//8ci///HIf//"
    "xyH//8ch///HIf//xyH//8ch///HIf//xyH//scg//vFH//4wh//+MIe/f7HIP/1vx6fqqpVA59wMBDAnTXQ06w3//HCM/3/yzD//8ou///KLP//ySr//8kp///JKf//ySn//8kp///JKf//ySn//8"
    "ko///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///I"
    "Jv//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yC"
    "T//8gk///IJP//yCT//8gk///IJP//yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ch"
    "///HIf//xyH//8ch///HIf//xyD//8cg///HIP/8xR//+cMf//fBHv39xR//9b8f0L+fMBCPgDAQ4bYzzvXGNv/9yzH9/8ou///KLP//yiv//8kp///JKf//ySn//8kp///JKf//ySj//8ko///JKP"
    "//ySj//8ko///JKP//ySj//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb/"
    "/8gm///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk//"
    "/IJP//yCT//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIf//xyH//8ch///HIf//"
    "xyH//8ch///HIf//xyH//8cg///HIP//xyD//MUf//nDH//3wR79/cUf//bBH86/nzAQeGktEfLCMtL/0jP//8wv/f/KLf//yiv//8kq///JKf//ySn//8kp///JKf//ySn//8ko///JKP//ySj//8"
    "ko///JKP//ySj//8ko///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJv//yCX//8gl///I"
    "Jf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yC"
    "T//8gk///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIf//xyH//8ch///HIf//xyH//8ch"
    "///HIf//xyH//8ch///HIP//xyD//8cg//zFH//5wx//+MIe/fzEH//0vx/Qv58wEEBAQAjzwjK5/9Qy//7KLf3/yiv//8kq///JKf//ySn//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JKP"
    "//ySj//8kn///JJ///ySf//8kn///IJv//yCb//8gm///IJv//yCb//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX/"
    "/8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCP//8gj///II///yCP//8gj///II///yCP//8gj//"
    "/II///yCP//8gj///II///yCP//8gj///II///xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIf//xyH//8ch///HIf//xyH//8ch///HIf//"
    "xyH//8ch///HIf//xyH//8cg//7GIP/7xB//+MIf//bBHv3+xx//8r4fnapVVQMAAAAA7b0ucP/SL/7/yyv9/8kp///JKP//ySj//8ko///JKP//ySj//8ko///JKP//ySj//8ko///JJ///ySf//8"
    "kn///JJ///yCb//8gm///IJv//yCb//8gm///IJv//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJP//yCT//8gk///IJP//yCT//8gk///I"
    "JP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yC"
    "P//8gj///II///xyL//8gj///II///yCP//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch"
    "///HIf//xyH//8cg///HIP/9xR//+sMf//nCH//zvh78/8sf/+q4IYUAAAAAAAAAAOCzLTn+ySz6/8sq///JKP7/ySf//8ko///JJ///ySj//8ko///JKP//ySj//8ko///JKP//ySb//8km///JJ/"
    "//yCb//8gm///IJv//yCb//8gm///IJv//yCX//8gk///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCP//8gj///II///yCT//8gk///IJP//yCT//8gk///IJP//yCT/"
    "/8gk///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci//"
    "/II///xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//"
    "xyH//8ch///HIP//xyD//MUf//rDH//3wR7/9L4e/vfCH/7SpyVgAAAAAAAAAAClhy0R+cUqyf/RKv7/ySb9/8gm///JJ///ySf//8kn///JJ///ySf//8kn///JJ///ySf//8gm///IJv//yCb//8"
    "gm///IJf//yCX//8gl///IJf//yCX//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gk///IJP//yCT//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///I"
    "I///yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xy"
    "L//8ci///HIv//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8cg"
    "///HIP//xyD//cYf//vEH//4wh//9sEf/f3GH//xvR7JpIA3DgAAAAD//wACAAAAAOq9K2D/zij//8kl/f/IJf//yCX//8gm///IJv//yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf"
    "//yCX//8gk///IJP//yCT//8gk///IJP//yCP//8gj///II///yCP//8gj///II///yCP//8gj///II///yCP//8gj///HIv//xyL//8ci///II///yCP//8gj///HIv//xyL//8ci///HIv//xyL/"
    "/8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch//"
    "/HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyD//8cg///HIP//xyD//8cg///HIP//xyD//8cg///HIP//"
    "xyD//cUf//rDH//4wR//9sAf//XAH/36wx795LIgYAAAAAD//wAC//8AAf//AAGxiTsN98InuP/QJv//xyT8/8gk///IJf//yCb//8gm///IJv//yCb//8gm///IJf//yCX//8gl///IJf//yCT//8"
    "gk///II///yCP//8gj///II///yCP//8gj///II///xyL//8ci///HIv//xyL//8cj///HI///xyL//8ci///HIv//xyL//8ci///HIv//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///H"
    "If//xyH//8ch///HIv//xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ci///HIf//xyH//8ch///HIf//xyH//8ch///HIP//xyD//8cg///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xy"
    "H//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8cg///HIP//xyD//8cg///HIP//xyD//8cg///HIP//xyD//8cg//7HIP/+xyD//scg//7GH//9xh///MUg"
    "//vEH//4wh//98Ee//O9Hvz/yB//7LkgyYhmMw///wAB//8AAQAAAAD/gAACAAAAAL6bLTP4xSXo/80l//7HJPz/yCT//8gl///IJf//yCX//8gl///IJf//yCX//8gl///IJf//yCT//8gj///II/"
    "//yCP//8gj///II///yCP//8gj///II///xyL//8ci///HIv//xyL//8ci///HIv//xyL//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyH/"
    "/8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIf//xyD//8cg///HIP//xyH//8ch///HIf//xyD//8cg///HIP//xyD//8cg///HIP/+xyD//scg//7HIP/+xyD//scg//7HIP/+xyD//scg//"
    "7HIP/+xiD//sYg//7GIP/+xiD//sYg//7GIP/+xiD//sYg//7GIP/+xiD//sYg//7GIP/+xiD//sYg//7GIP/+xiD//sYg//7GIP/+xiD//sYg//zFH//8xR///MUf//zFH//7xB//+sMf//nDHv/4"
    "wh//9cAf//G8Hvz9xh7/9L4f6L+aKUQAAAAA//8AAQAAAAAAAAAAAAAAAP//AAIAAAAA268oRvzIJej/0iX//scj/P/IJP7/yCT//8gk///IJP//yCT//8gk///IJP//yCP//8gj///HIv//xyL//8"
    "ci///HIv//xyL//8ci///HIv//xyH//8ch///HIf//xyH//8ch///HIf//xyH//8ch///HIP//xyD//8cg///HIP//xyD//8cg///HIP//xyD//8cg///HIP//xyD//8cg//7HIP/+xyD//scg//7H"
    "IP/+xyD//scg//7HIP/+xyD//scg//7HIP/+xyD//scg//7HIP/+xyD//scg//7HIP/+xyD//sYg//7GIP/+xiD//cUf//3FH//9xR///MUg//zFIP/8xSD//MUg//zFIP/8xSD//MUg//zFIP/8xS"
    "D/+8Qg//vEIP/7xCD/+8Qg//vEIP/7xCD/+8Qf//vEH//7xB//+8Qf//vEH//6wx//+sMf//rDH//6wx//+sMf//rDH//6wx//+sMf//rDH//5wh//+cIf//nCH//4wh//+MIf//jBHv/3wB7/9cAe"
    "/vK9Hvz/yh//9cAe6MykKEYAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAA/4AAAgAAAADZqy5D9cMnzf/QJP//zCT//scj/v7HI/3/yCP9/8gi/f/IIv3/yCL9/8gi/f/IIv3/xyH9/8ch/f/IIf"
    "3/xyH9/8gh/f/HIP3/yCH9/8cg/f7HIP3/xyD9/8cg/f/HIP3+xx/9/scf/f7HH/3+xx/9/scf/f7HH/39xh/9/cYf/f3GH/38xh/9/MYf/fzGH/38xh/9/MYf/fzGH/38xh/9/MYf/fzGH/38xh/9"
    "/MYf/fzGH/38xh/9/MYf/fzGH/38xh/9/MYf/fzFH/38xR/9/MUf/fzFH/38xR/9/MUf/fzFH/38xR/9/MUf/frEH/36xB/9+sQf/frEH/36xB/9+sQf/frEH/36xB/9+sQf/frEH/36xB/9+sQf/f"
    "rEH/36xB/9+cMf/fnDH/35wx/9+cMf/fjDHv34wx79+MMe/fjDHv34wx79+MMe/fnDHv35wx79+MIe/fjCHv34wh79+MIe/fjCHv34wh7998Ie/ffBHv33wR79+cIe/fbBHv30vh799b4d/PnDH//9"
    "xh//7rkfzcacJkMAAAAAqqoAAwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD//wACAAAAAJt6LBfpuCeI/MUl4v/KI///0SP//84j///PI///ziL//84j///OIv//ziL//84i///OIv//ziH//8"
    "4i///OIf//zSH//84h///NIf//zCD//80h///NIf//zSH//8sg///LIP//yyD//8wg///MIP//zCD//8of///KH///yh///8of///KH///yh///8of///KH///yh///8of///KH///yh///8of///K"
    "H///yh///8of///KH///yh///8of///KH///yh///8of///KH///yh///8of///KH///yh///8of///KH///yR///8kf///JH///yR///8kf///JH///yR///8kf///JH///yR///8kf///JH///yR"
    "///8kf///IH///xx///8cf///HH///xx///8cf///HH///xx///8cf///HH///xx///8cf///HH///xx///8cf///HH///xx///8cf///HH///xx///8cf//zFH//9xiD//8cf///IIP/yvB7k47Mi"
    "h5B6LBcAAAAA//8AAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAP//AAIAAAAAAAAAAMGbJyHpuiZd88AlpvrEItH9xiLP/sYiz/7GIc/+xiHP/sYhz/7GIc/+xiHP/cYhz/7GIM"
    "/9xSDP/cUgz/3FIM/9xSDP+8Ugz/3GIM/9xiDP/cYgz/rEH8/6xB/P+sQfz/vFH8/7xR/P+8Ufz/rDH8/6wx/P+sMfz/rDH8/6wx/P+sMfz/rDH8/6wx/P+sMfz/rDH8/6wx/P+sMfz/rDH8/6wx/P"
    "+sMfz/rDH8/6wx/P+sMfz/rDH8/6wx/P+cEfz/nBH8/5wR/P+cEfz/nBH8/5wR/P+cEfz/nBH8/5wR/P+MEfz/jBH8/4wR/P+MEfz/jBH8/4wR/P+MEfz/jBH8/4wR/P+MEfz/jBH8/4wR/P+MEfz/"
    "jBH8/4wR/P9cAfz/XAH8/1wB/P9cAfz/XAH8/1wB/P9cAfz/XAH8/1wB/P9cAfz/XAH8/1wB/P9cAfz/XAH8/1wB/P9cAfz/XAH8/1wB/P9cAfz/XAH8/0vx/P9cAf0fG9H6XntCN0sZAnJwAAAAAA"
    "AAAA/4AAAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//8AAf//AAIAAAAAAAAAAAAAAAC0li0Rz58wEL+fMBC/nyAQv58gEL+fMBC/nzAQv58wEM+fMBC/nyAQz5"
    "8gEM+fIBDPnyAQz58gEM+fIBDPnyAQz58gEM+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+f"
    "IBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/ny"
    "AQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQv58gEL+fIBC/nyAQz58gEKWHLREAAAAAAAAAAAAAAAD//wAC//8A"
    "AQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA==";

static const std::vector<unsigned char>& AlertIconData() {
    static std::vector<unsigned char> d;
    if (d.empty()) {
        auto val = [](char c) -> int {
            if (c >= 'A' && c <= 'Z') return c - 'A';
            if (c >= 'a' && c <= 'z') return c - 'a' + 26;
            if (c >= '0' && c <= '9') return c - '0' + 52;
            if (c == '+') return 62;
            if (c == '/') return 63;
            return -1;
        };
        int acc = 0, bits = 0;
        d.reserve((size_t)kAlertIcoW * (size_t)kAlertIcoH * 4);
        for (const char* q = kAlertIcoB64; *q; q++) {
            int v = val(*q);
            if (v < 0) continue;
            acc = (acc << 6) | v;
            bits += 6;
            if (bits >= 8) {
                bits -= 8;
                d.push_back((unsigned char)((acc >> bits) & 0xFF));
            }
        }
    }
    return d;
}

static void DrawAlertIcon(Canvas& cv, float cx, float top, float wPx, RGBA tint = RGBA{0.0f, 0.0f, 0.0f, 0.0f}) {
    const std::vector<unsigned char>& d = AlertIconData();
    const int IW = kAlertIcoW, IH = kAlertIcoH;
    if (d.size() < (size_t)IW * (size_t)IH * 4 || wPx < 2.0f) return;
    float hPx = wPx * (float)IH / (float)IW;
    float left = cx - wPx * 0.5f;
    float sx = (float)IW / wPx, sy = (float)IH / hPx;
    int x0 = (int)floorf(left), x1 = (int)ceilf(left + wPx);
    int y0 = (int)floorf(top), y1 = (int)ceilf(top + hPx);
    auto texel = [&](int ix, int iy, float& r, float& g2, float& b, float& a) {
        if (ix < 0) ix = 0;
        if (iy < 0) iy = 0;
        if (ix >= IW) ix = IW - 1;
        if (iy >= IH) iy = IH - 1;
        const unsigned char* q = &d[((size_t)iy * (size_t)IW + (size_t)ix) * 4];
        a = (float)q[3] / 255.0f;
        r = (float)q[0] / 255.0f * a;
        g2 = (float)q[1] / 255.0f * a;
        b = (float)q[2] / 255.0f * a;
    };
    for (int y = y0; y < y1; y++) {
        if (y < 0 || y >= cv.h) continue;
        for (int x = x0; x < x1; x++) {
            if (x < 0 || x >= cv.w) continue;
            float pr = 0, pg = 0, pb = 0, pa = 0;
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 2; i++) {
                    float u = ((float)x + ((float)i + 0.5f) * 0.5f - left) * sx - 0.5f;
                    float v = ((float)y + ((float)j + 0.5f) * 0.5f - top) * sy - 0.5f;
                    int iu = (int)floorf(u), iv = (int)floorf(v);
                    float fu = u - (float)iu, fv = v - (float)iv;
                    float r[4], g2[4], b[4], a[4];
                    texel(iu, iv, r[0], g2[0], b[0], a[0]);
                    texel(iu + 1, iv, r[1], g2[1], b[1], a[1]);
                    texel(iu, iv + 1, r[2], g2[2], b[2], a[2]);
                    texel(iu + 1, iv + 1, r[3], g2[3], b[3], a[3]);
                    float w0 = (1 - fu) * (1 - fv), w1 = fu * (1 - fv), w2 = (1 - fu) * fv, w3 = fu * fv;
                    pr += r[0] * w0 + r[1] * w1 + r[2] * w2 + r[3] * w3;
                    pg += g2[0] * w0 + g2[1] * w1 + g2[2] * w2 + g2[3] * w3;
                    pb += b[0] * w0 + b[1] * w1 + b[2] * w2 + b[3] * w3;
                    pa += a[0] * w0 + a[1] * w1 + a[2] * w2 + a[3] * w3;
                }
            }
            pr *= 0.25f; pg *= 0.25f; pb *= 0.25f; pa *= 0.25f;
            if (pa <= 0.002f) continue;
            RGBA c = {pr / pa, pg / pa, pb / pa, pa};
            if (tint.a > 0.0f) {

                float lum = 0.299f * c.r + 0.587f * c.g + 0.114f * c.b;
                float tt = Clamp01(lum / 0.80f);
                c.r = tint.r * tt;
                c.g = tint.g * tt;
                c.b = tint.b * tt;
            }
            Blend(cv, x, y, c);
        }
    }
}

static void DrawAlertMarquee(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu,
                              const WLayout& L) {

    const Weather& wt = g.weather;
    if (L.alertY >= 0 && !wt.alertText.empty()) {
        float fL = M + 16.0f * k;
        float fR = M + (cardWu - 16.0f) * k;
        float fCx = (fL + fR) * 0.5f;
        float fHw = (fR - fL) * 0.5f;
        float y0 = M + L.alertY * k;
        RGBA ac3 = AlertColor(wt.alertColor);
        FillRRect(cv, fCx, y0, fHw, 11.0f * k, 3.0f * k,
                  [](float, float) -> RGBA { return HL(0.07f); });
        FillRRect(cv, fL + 2.0f * k, y0, 1.2f * k, 11.0f * k, 0.6f * k,
                  [ac3](float, float) -> RGBA { return ac3; });

        std::wstring msg = wt.alertText + L"      \u2022      ";
        float total = (float)MeasureWidth(t, f.small, msg);
        if (total > 1.0f) {
            const double velocidad = 38.0;

            static ULONGLONG s_prev = 0;
            static double s_clock = 0.0;
            ULONGLONG nowT = GetTickCount64();
            double dtS = s_prev ? (double)(nowT - s_prev) * 0.001 : 0.0;
            s_prev = nowT;
            if (dtS > 0.25) dtS = 0.25;
            if (g.hoverCard != &g.cards[CARD_WEATHER]) s_clock += dtS;
            double fase = fmod(s_clock * velocidad * (double)k, (double)total);

            float x = fR - (float)fase;
            while (x > fL - total) x -= total;
            t.clipL = fL + 7.0f * k;
            t.clipR = fR - 4.0f * k;
            for (; x < fR; x += total)
                DrawLabel(t, f.small, msg, x, y0 - 8.0f * k, 0, g.pal.white);
            t.clipL = -1.0f;
            t.clipR = -1.0f;
        }
    }
}

static bool WeatherNeedsRefresh() {
    return g.fetchFailed || (g.lastOk && GetTickCount64() - g.lastOk >
           (ULONGLONG)g.refreshMinutes * 120000ULL);
}

static std::wstring WeatherRefreshLabel(bool stale) {
    wchar_t time[16];
    wsprintfW(time, L"%02d:%02d", (int)g.lastOkTime.wHour, (int)g.lastOkTime.wMinute);
    return std::wstring(stale ? TR(L"Sin actualizar · ", L"Last known · ", L"Sense actualitzar · ") :
                                TR(L"Act. ", L"Upd. ", L"Act. ")) + time;
}

static void DrawWeather(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu,
                        const WLayout& L) {
    const Weather& wt = g.weather;
    bool valid = wt.valid;

    DrawCardHeader(cv, t, f, CARD_WEATHER, M, k, CardTitle(CARD_WEATHER));
    float cardW = cardWu * k;
    float right = M + (cardWu - 18.0f) * k;
    float pitch = (cardWu - 36.0f) / 6.0f;
    float divY = L.divY;

    Kind kind = valid ? KindFromCode(wt.code) : K_CLOUD;
    bool isDay = valid ? wt.isDay : true;

    RGBA white = g.pal.white, soft = g.pal.soft, dimc = g.pal.dimc;

    if (g.showForecast) {
        FillRRect(cv, M + cardW / 2.0f, M + divY * k, (cardW - 36.0f * k) / 2.0f, 0.6f, 0.6f,
                  [](float, float) -> RGBA { return HL(0.16f); });
    }

    DrawIcon(cv, kind, isDay, M + 54.0f * k, M + 62.0f * k, 56.0f * k);
    if (g.showForecast && valid) {
        for (int i = 1; i <= 6 && i < wt.days; i++) {
            float colX = M + (18.0f + pitch / 2.0f + pitch * (float)(i - 1)) * k;
            DrawIcon(cv, KindFromCode(wt.dcode[i]), true, colX, M + (divY + 40.0f) * k, 36.0f * k);
        }
    }

    bool hayAlerta = valid && wt.alertColor > 0;
    float tempX = hayAlerta ? (M + 160.0f * k) : (M + 100.0f * k);
    if (hayAlerta) {
        RGBA ac2 = AlertColor(wt.alertColor);

        float ax = M + 125.0f * k;
        DrawAlertIcon(cv, ax, M + 37.0f * k, 50.0f * k, ac2);

        DrawLabel(t, f.city, AlertName(wt.alertColor), ax, M + 86.0f * k, 1, ac2);
    }

    std::wstring unit = g.fahrenheit ? L"F" : L"C";
    std::wstring bigTemp = valid ? std::to_wstring((int)floor(wt.temp + 0.5)) + L"\u00B0"
                                 : std::wstring(L"--\u00B0");
    int wBig = DrawLabel(t, f.temp, bigTemp, tempX, M + 34.0f * k, 0, white);
    DrawLabel(t, f.unit, unit, tempX + (float)wBig + 2.0f * k, M + 50.0f * k, 0, dimc);

    std::wstring desc;
    if (valid) desc = DescribeText(wt.code);
    else if (g.fetchFailed) desc = TR(L"Sin conexi\u00F3n", L"Offline", L"Sense connexi\u00F3");
    else desc = TR(L"Cargando...", L"Loading...", L"Carregant...");

    DrawLabel(t, f.desc, Ellipsize(t, f.desc, desc, (int)((cardWu - (hayAlerta ? 178.0f : 118.0f)) * k)),
              tempX, M + 86.0f * k, 0, soft);

    SYSTEMTIME st;
    GetLocalTime(&st);
    wchar_t timeBuf[16];
    wsprintfW(timeBuf, L"%02d:%02d", (int)st.wHour, (int)st.wMinute);
    std::wstring dateStr = std::wstring(DowName((int)st.wDayOfWeek)) + L" " +
                           std::to_wstring((int)st.wDay) + L" " + MonthShort((int)st.wMonth);
    DrawLabel(t, f.time, timeBuf, right, M + 30.0f * k, 2, white);
    DrawLabel(t, f.small, dateStr, right, M + 62.0f * k, 2, dimc);

    {
        std::wstring city = (valid && !wt.place.empty()) ? wt.place : g.city;
        std::wstring upd;
        bool updStale = false;
        if (valid && g.lastOk) {
            updStale = WeatherNeedsRefresh();
            upd = WeatherRefreshLabel(updStale);
        }
        const float left0 = M + 18.0f * k;

        if (!city.empty()) {
            int cityMax = (int)std::max(20.0f * k, (M + 178.0f * k) - left0);
            DrawLabel(t, f.city, Ellipsize(t, f.city, city, cityMax), left0, M + 86.0f * k, 0, white);
        }

        if (!upd.empty()) {
            DrawLabel(t, f.small, upd, right, M + 76.0f * k, 2,
                      updStale ? C(255, 170, 80, 0.95f) : dimc);
        }

        if (valid && wt.days > 0) {
            const float metaY = M + 107.0f * k;
            std::wstring hi = L"\u2191 " + std::to_wstring((int)floor(wt.dmax[0] + 0.5)) + L"\u00B0";
            std::wstring lo = L"\u2193 " + std::to_wstring((int)floor(wt.dmin[0] + 0.5)) + L"\u00B0";
            int wHi = DrawLabel(t, f.small, hi, left0, metaY, 0, soft);
            DrawLabel(t, f.small, lo, left0 + (float)wHi + 10.0f * k, metaY, 0, dimc);
            if (wt.uv >= 0) {
                DrawLabel(t, f.small, L"UV " + std::to_wstring(wt.uv), right, metaY, 2, UvColor(wt.uv));
            }
        }
    }

    if (L.panelY >= 0) {
        float px0 = M + 18.0f * k, px1 = right;
        float pcx = (px0 + px1) / 2.0f;
        float pcy = M + (L.panelY + L.panelH / 2.0f) * k;
        float phw = (px1 - px0) / 2.0f, phh = L.panelH * k / 2.0f, pr = 10.0f * k;
        FillRRect(cv, pcx, pcy, phw, phh, pr, [](float, float) -> RGBA { return HL(0.07f); });
        FillSdf(cv, pcx - phw - 2, pcy - phh - 2, pcx + phw + 2, pcy + phh + 2,
                [=](float x, float yy) {
                    return fabsf(SdRoundRect(x, yy, pcx, pcy, phw, phh, pr) + 0.6f) - 0.6f;
                },
                [](float, float) -> RGBA { return HL(0.12f); });

        float colW = (px1 - px0) / 3.0f;
        int maxW = (int)(colW - 10.0f * k);
        float cxs[3] = {px0 + colW * 0.5f, px0 + colW * 1.5f, px0 + colW * 2.5f};

        float rowsY[2];
        int nRows = 0;
        if (L.detailsY >= 0) rowsY[nRows++] = L.detailsY;
        if (L.sunY >= 0) rowsY[nRows++] = L.sunY;

        for (int r = 0; r < nRows; r++) {
            float ry = rowsY[r];
            float cyRow = M + (ry + 16.0f) * k;
            for (int c2 = 1; c2 <= 2; c2++) {
                FillRRect(cv, px0 + colW * (float)c2, cyRow, 0.5f * k, 13.0f * k, 0.5f * k,
                          [](float, float) -> RGBA { return HL(0.12f); });
            }
            if (r + 1 < nRows) {
                FillRRect(cv, pcx, M + (ry + 36.0f) * k, phw - 14.0f * k, 0.5f * k, 0.5f * k,
                          [](float, float) -> RGBA { return HL(0.10f); });
            }
        }

        for (int r = 0; r < nRows; r++) {
            float top = M + (rowsY[r] + 2.0f) * k;
            RGBA white2 = g.pal.white;
            if (rowsY[r] == L.detailsY) {
                std::wstring windUnit = g.fahrenheit ? L"mph" : L"km/h";
                DrawStat(t, f, cxs[0], top, TR(L"Sensaci\u00F3n", L"Feels like", L"Sensaci\u00F3"),
                         std::to_wstring((int)floor(wt.feels + 0.5)) + L"\u00B0", white2, maxW);
                DrawStat(t, f, cxs[1], top, TR(L"Humedad", L"Humidity", L"Humitat"),
                         std::to_wstring(wt.humidity) + L"%", white2, maxW);
                DrawStat(t, f, cxs[2], top, TR(L"Viento", L"Wind", L"Vent"),
                         std::to_wstring((int)floor(wt.wind + 0.5)) + L" " + windUnit, white2, maxW);
            } else {
                std::wstring sun = (wt.sunrise >= 0 && wt.sunset >= 0)
                                       ? HM(wt.sunrise) + L" \u2013 " + HM(wt.sunset)
                                       : std::wstring(L"\u2013");
                std::wstring air = wt.aqi >= 0 ? std::to_wstring(wt.aqi) + L" \u00B7 " + AqiText(wt.aqi)
                                               : std::wstring(L"\u2013");
                std::wstring pol = wt.pollen >= 0 ? std::wstring(PollenText(wt.pollen)) : std::wstring(L"\u2013");
                DrawStat(t, f, cxs[0], top, TR(L"Sol", L"Sun", L"Sol"), sun, white2, maxW);
                DrawStat(t, f, cxs[1], top, TR(L"Aire", L"Air", L"Aire"), air,
                         wt.aqi >= 0 ? AqiColor(wt.aqi) : white2, maxW);
                DrawStat(t, f, cxs[2], top, TR(L"Polen", L"Pollen", L"P\u00F2l\u00B7len"), pol,
                         wt.pollen >= 0 ? PollenColor(wt.pollen) : white2, maxW);
            }
        }
    }

    if (L.rainY >= 0) {
        std::wstring rain;
        if (wt.rainMin <= 5) rain = TR(L"Lluvia ahora mismo", L"Rain right now", L"Pluja ara mateix");
        else rain = std::wstring(TR(L"Lluvia en ~", L"Rain in ~", L"Pluja en ~")) +
                    std::to_wstring(wt.rainMin) + L" min";
        if (wt.rainMm > 0.2) rain += L"  \u00B7  " + FormatNum(wt.rainMm, 1) + L" mm/h";
        DrawLabel(t, f.small, rain, M + 18.0f * k, M + L.rainY * k, 0, C(120, 185, 255, 0.95f));
    }

    if (L.hourlyY >= 0) DrawHourly(cv, t, f, M, k, cardWu, L.hourlyY);

    if (g.showForecast && valid) {
        for (int i = 1; i <= 6 && i < wt.days; i++) {
            float colX = M + (18.0f + pitch / 2.0f + pitch * (float)(i - 1)) * k;
            DrawLabel(t, f.day, DowName(wt.ddow[i]), colX, M + (divY + 10.0f) * k, 1, white);

            std::wstring hi = std::to_wstring((int)floor(wt.dmax[i] + 0.5)) + L"\u00B0";
            std::wstring lo = std::to_wstring((int)floor(wt.dmin[i] + 0.5)) + L"\u00B0";
            int wHi = MeasureWidth(t, f.small, hi);
            int wLo = MeasureWidth(t, f.small, lo);
            float gap = 6.0f * k;
            float x0 = colX - ((float)(wHi + wLo) + gap) / 2.0f;
            DrawLabel(t, f.small, hi, x0, M + (divY + 60.0f) * k, 0, white);
            DrawLabel(t, f.small, lo, x0 + (float)wHi + gap, M + (divY + 60.0f) * k, 0, dimc);

            {
                bool baja = wt.dpop[i] < 20;
                RGBA pc = baja ? C(150, 160, 178, 0.80f) : C(120, 185, 255, 0.95f);
                DrawLabel(t, f.small, std::to_wstring(wt.dpop[i]) + L"%", colX,
                          M + (divY + 78.0f) * k, 1, pc);
            }
        }
    }
}

// System card

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// Draw flags directly to avoid depending on flag emoji support.

enum FlagId {
    FL_NONE = 0, FL_ES, FL_CAT, FL_GB, FL_US, FL_FR, FL_DE, FL_IT, FL_PT, FL_NL, FL_BE, FL_IE,
    FL_JP, FL_CN, FL_MX, FL_AR, FL_BR, FL_CA, FL_AU, FL_IN, FL_RU, FL_CH, FL_SE, FL_EU, FL_UNKNOWN
};

static int FlagFromCode(std::wstring s) {
    s = Trim(s);
    for (size_t i = 0; i < s.size(); i++) s[i] = (wchar_t)towupper(s[i]);
    if (s.empty() || s == L"NONE" || s == L"-") return FL_NONE;
    static const struct {
        const wchar_t* code;
        int id;
    } tbl[] = {{L"ES", FL_ES}, {L"CAT", FL_CAT}, {L"CT", FL_CAT}, {L"GB", FL_GB}, {L"UK", FL_GB},
               {L"US", FL_US}, {L"USA", FL_US}, {L"FR", FL_FR}, {L"DE", FL_DE}, {L"IT", FL_IT},
               {L"PT", FL_PT}, {L"NL", FL_NL}, {L"BE", FL_BE}, {L"IE", FL_IE}, {L"JP", FL_JP},
               {L"CN", FL_CN}, {L"MX", FL_MX}, {L"AR", FL_AR}, {L"BR", FL_BR}, {L"CA", FL_CA},
               {L"AU", FL_AU}, {L"IN", FL_IN}, {L"RU", FL_RU}, {L"CH", FL_CH}, {L"SE", FL_SE},
               {L"EU", FL_EU}};
    for (size_t i = 0; i < sizeof(tbl) / sizeof(tbl[0]); i++) {
        if (s == tbl[i].code) return tbl[i].id;
    }
    return FL_UNKNOWN;
}

static bool HasWord(const std::wstring& s, const wchar_t* k) { return s.find(k) != std::wstring::npos; }

static int GuessFlag(std::wstring label, std::wstring tz) {
    if (!label.empty()) CharLowerBuffW(&label[0], (DWORD)label.size());
    if (!tz.empty()) CharLowerBuffW(&tz[0], (DWORD)tz.size());

    struct Kw {
        const wchar_t* k;
        int id;
    };
    static const Kw byLabel[] = {
        {L"londres", FL_GB}, {L"london", FL_GB}, {L"nueva york", FL_US}, {L"new york", FL_US},
        {L"nova york", FL_US}, {L"los \u00E1ngeles", FL_US}, {L"los angeles", FL_US}, {L"chicago", FL_US},
        {L"miami", FL_US}, {L"san francisco", FL_US}, {L"washington", FL_US}, {L"dallas", FL_US},
        {L"tokio", FL_JP}, {L"tokyo", FL_JP}, {L"pek", FL_CN}, {L"beijing", FL_CN}, {L"shangh", FL_CN},
        {L"par\u00EDs", FL_FR}, {L"paris", FL_FR}, {L"berl", FL_DE}, {L"roma", FL_IT}, {L"rome", FL_IT},
        {L"lisboa", FL_PT}, {L"lisbon", FL_PT}, {L"m\u00E9xico", FL_MX}, {L"mexico", FL_MX},
        {L"buenos aires", FL_AR}, {L"s\u00E3o paulo", FL_BR}, {L"sao paulo", FL_BR}, {L"s\u00EDdney", FL_AU},
        {L"sydney", FL_AU}, {L"melbourne", FL_AU}, {L"madrid", FL_ES}, {L"barcelona", FL_ES},
        {L"valencia", FL_ES}, {L"sevilla", FL_ES}, {L"mosc", FL_RU}, {L"delhi", FL_IN}, {L"mumbai", FL_IN},
        {L"bombay", FL_IN}, {L"toronto", FL_CA}, {L"vancouver", FL_CA}, {L"bruselas", FL_BE},
        {L"brussels", FL_BE}, {L"bruxelles", FL_BE}, {L"\u00E1msterdam", FL_NL}, {L"amsterdam", FL_NL},
        {L"dubl\u00EDn", FL_IE}, {L"dublin", FL_IE}, {L"z\u00FArich", FL_CH}, {L"zurich", FL_CH},
        {L"ginebra", FL_CH}, {L"geneva", FL_CH}, {L"estocolmo", FL_SE}, {L"stockholm", FL_SE}};
    static const Kw byZone[] = {
        {L"gmt standard", FL_GB}, {L"eastern standard", FL_US}, {L"central standard", FL_US},
        {L"mountain standard", FL_US}, {L"pacific standard", FL_US}, {L"tokyo standard", FL_JP},
        {L"china standard", FL_CN}, {L"india standard", FL_IN}, {L"aus eastern", FL_AU},
        {L"e. australia", FL_AU}, {L"e. south america", FL_BR}, {L"argentina standard", FL_AR},
        {L"russian standard", FL_RU}};

    for (size_t i = 0; i < sizeof(byLabel) / sizeof(byLabel[0]); i++)
        if (HasWord(label, byLabel[i].k)) return byLabel[i].id;
    for (size_t i = 0; i < sizeof(byZone) / sizeof(byZone[0]); i++)
        if (HasWord(tz, byZone[i].k)) return byZone[i].id;
    return FL_NONE;
}

static RGBA UnionJack(float x, float y) {
    float inv = 1.0f / sqrtf(13.0f);
    float d1 = fabsf(2.0f * x - 3.0f * y) * inv;
    float d2 = fabsf(2.0f * x + 3.0f * y - 6.0f) * inv;
    float dv = fabsf(x - 1.5f), dh = fabsf(y - 1.0f);
    if (dv < 0.2f || dh < 0.2f) return C(200, 16, 46);
    if (dv < 0.33f || dh < 0.33f) return C(255, 255, 255);
    if (d1 < 0.09f || d2 < 0.09f) return C(200, 16, 46);
    if (d1 < 0.22f || d2 < 0.22f) return C(255, 255, 255);
    return C(1, 33, 105);
}

static RGBA FlagColor(int f, float x, float y) {
    RGBA white = C(255, 255, 255);
    switch (f) {
        case FL_ES: return (y < 0.5f || y > 1.5f) ? C(198, 11, 30) : C(255, 196, 0);
        case FL_CAT: return (((int)(y / 2.0f * 9.0f)) % 2 == 0) ? C(252, 221, 9) : C(218, 18, 26);
        case FL_GB: return UnionJack(x, y);
        case FL_US: {
            if (x < 1.2f && y < 1.077f) {
                float fx = fmodf(x, 0.3f) - 0.15f, fy = fmodf(y, 0.27f) - 0.135f;
                return Len2(fx, fy) < 0.055f ? white : C(60, 59, 110);
            }
            return (((int)(y / 2.0f * 13.0f)) % 2 == 0) ? C(178, 34, 52) : white;
        }
        case FL_FR: return x < 1.0f ? C(0, 35, 149) : (x < 2.0f ? white : C(237, 41, 57));
        case FL_DE: return y < 0.667f ? C(0, 0, 0) : (y < 1.333f ? C(221, 0, 0) : C(255, 206, 0));
        case FL_IT: return x < 1.0f ? C(0, 146, 70) : (x < 2.0f ? white : C(206, 43, 55));
        case FL_PT: {
            if (Len2(x - 1.2f, y - 1.0f) < 0.33f) return C(255, 204, 0);
            return x < 1.2f ? C(0, 102, 0) : C(255, 0, 0);
        }
        case FL_NL: return y < 0.667f ? C(174, 28, 40) : (y < 1.333f ? white : C(33, 70, 139));
        case FL_BE: return x < 1.0f ? C(0, 0, 0) : (x < 2.0f ? C(253, 218, 36) : C(239, 51, 64));
        case FL_IE: return x < 1.0f ? C(22, 155, 98) : (x < 2.0f ? white : C(255, 136, 62));
        case FL_JP: return Len2(x - 1.5f, y - 1.0f) < 0.6f ? C(188, 0, 45) : white;
        case FL_CN: {
            RGBA star = C(255, 222, 0);
            if (Len2(x - 0.55f, y - 0.6f) < 0.28f) return star;
            if (Len2(x - 1.15f, y - 0.25f) < 0.09f || Len2(x - 1.35f, y - 0.5f) < 0.09f ||
                Len2(x - 1.35f, y - 0.85f) < 0.09f || Len2(x - 1.15f, y - 1.1f) < 0.09f)
                return star;
            return C(222, 41, 16);
        }
        case FL_MX: {
            if (x >= 1.0f && x < 2.0f && Len2(x - 1.5f, y - 1.0f) < 0.25f) return C(130, 90, 40);
            return x < 1.0f ? C(0, 104, 71) : (x < 2.0f ? white : C(206, 17, 38));
        }
        case FL_AR: {
            if (Len2(x - 1.5f, y - 1.0f) < 0.22f) return C(246, 180, 14);
            return (y < 0.667f || y > 1.333f) ? C(116, 172, 223) : white;
        }
        case FL_BR: {
            if (Len2(x - 1.5f, y - 1.0f) < 0.5f) return C(0, 39, 118);
            if (fabsf(x - 1.5f) / 1.35f + fabsf(y - 1.0f) / 0.9f < 1.0f) return C(255, 223, 0);
            return C(0, 156, 59);
        }
        case FL_CA: {
            if (fabsf(x - 1.5f) / 0.45f + fabsf(y - 1.0f) / 0.6f < 1.0f) return C(255, 0, 0);
            return (x < 0.75f || x > 2.25f) ? C(255, 0, 0) : white;
        }
        case FL_AU: {
            if (x < 1.5f && y < 1.0f) return UnionJack(x * 2.0f, y * 2.0f);
            if (Len2(x - 0.75f, y - 1.5f) < 0.17f || Len2(x - 2.2f, y - 0.35f) < 0.1f ||
                Len2(x - 2.65f, y - 0.8f) < 0.1f || Len2(x - 2.2f, y - 1.45f) < 0.1f ||
                Len2(x - 1.85f, y - 0.9f) < 0.1f)
                return white;
            return C(0, 0, 139);
        }
        case FL_IN: {
            if (fabsf(Len2(x - 1.5f, y - 1.0f) - 0.22f) < 0.035f) return C(0, 0, 128);
            return y < 0.667f ? C(255, 153, 51) : (y < 1.333f ? white : C(19, 136, 8));
        }
        case FL_RU: return y < 0.667f ? white : (y < 1.333f ? C(0, 57, 166) : C(213, 43, 30));
        case FL_CH: {
            bool cross = (fabsf(x - 1.5f) < 0.17f && fabsf(y - 1.0f) < 0.55f) ||
                         (fabsf(y - 1.0f) < 0.17f && fabsf(x - 1.5f) < 0.55f);
            return cross ? white : C(218, 41, 28);
        }
        case FL_SE: return (fabsf(x - 1.0f) < 0.2f || fabsf(y - 1.0f) < 0.2f) ? C(254, 204, 0) : C(0, 106, 167);
        case FL_EU: {
            for (int i = 0; i < 12; i++) {
                float a = (float)i * 0.5235988f;
                if (Len2(x - (1.5f + 0.7f * cosf(a)), y - (1.0f + 0.7f * sinf(a))) < 0.09f)
                    return C(255, 204, 0);
            }
            return C(0, 51, 153);
        }
        default: return C(120, 130, 150);
    }
}

static void DrawFlag(Canvas& cv, int flag, float cx, float cy, float k) {
    if (flag == FL_NONE) return;
    float w = 24.0f * k, h = 16.0f * k;
    float x0 = cx - w / 2.0f, y0 = cy - h / 2.0f;
    float rad = 2.5f * k;
    Paint(cv, x0 - 1, y0 - 1, x0 + w + 1, y0 + h + 1, [=](float px, float py) -> RGBA {
        float cov = Coverage(SdRoundRect(px, py, cx, cy, w / 2.0f, h / 2.0f, rad));
        if (cov <= 0.0f) return kNone;
        float rr = 0.0f, gg = 0.0f, bb = 0.0f;
        for (int sy = 0; sy < 2; sy++) {
            for (int sx = 0; sx < 2; sx++) {
                float u = Clamp01((px - 0.25f + 0.5f * (float)sx - x0) / w);
                float v = Clamp01((py - 0.25f + 0.5f * (float)sy - y0) / h);
                RGBA c = FlagColor(flag, u * 3.0f, v * 2.0f);
                rr += c.r;
                gg += c.g;
                bb += c.b;
            }
        }
        RGBA o = {rr / 4.0f, gg / 4.0f, bb / 4.0f, cov};
        return o;
    });
    Paint(cv, x0 - 2, y0 - 2, x0 + w + 2, y0 + h + 2, [=](float px, float py) -> RGBA {
        float d = SdRoundRect(px, py, cx, cy, w / 2.0f, h / 2.0f, rad);
        float cov = Coverage(fabsf(d + 0.5f) - 0.5f);
        if (cov <= 0.0f) return kNone;
        return C(255, 255, 255, 0.35f * cov);
    });
}

// Text wrapping

static std::vector<std::wstring> WrapLines(TextCtx& t, HFONT font, const std::wstring& text, int maxW) {
    std::vector<std::wstring> out;
    size_t pos = 0;
    while (true) {
        size_t e = text.find(L'\n', pos);
        if (e == std::wstring::npos) e = text.size();
        std::wstring para = text.substr(pos, e - pos);
        while (!para.empty() && para.back() == L'\r') para.pop_back();

        if (para.empty()) {
            out.push_back(L"");
        } else {
            std::wstring line;
            size_t i = 0;
            while (i < para.size()) {
                size_t j = i;
                while (j < para.size() && para[j] != L' ') j++;
                size_t te = j;
                while (j < para.size() && para[j] == L' ') j++;
                std::wstring word = para.substr(i, j - i);
                std::wstring trimmed = para.substr(i, te - i);
                if (line.empty() || MeasureWidth(t, font, line + trimmed) <= maxW) {
                    if (line.empty() && MeasureWidth(t, font, trimmed) > maxW) {
                        std::wstring chunk;
                        for (size_t q = 0; q < word.size(); q++) {
                            if (!chunk.empty() && MeasureWidth(t, font, chunk + word[q]) > maxW) {
                                out.push_back(chunk);
                                chunk.clear();
                            }
                            chunk += word[q];
                        }
                        line = chunk;
                    } else {
                        line += word;
                    }
                    i = j;
                } else {
                    out.push_back(line);
                    line.clear();
                }
            }
            out.push_back(line);
        }
        if (e >= text.size()) break;
        pos = e + 1;
    }
    return out;
}

static std::vector<SysRow> BuildSysRows() {

    std::vector<SysRow> rows;

    for (size_t i = 0; i < g.disks.size(); i++) {
        SysRow r;
        r.kind = 0;
        r.label = std::wstring(1, g.disks[i].letter) + L":";
        double used = g.disks[i].totalGB - g.disks[i].freeGB;
        r.pct = r.colorPct = (float)(used * 100.0 / g.disks[i].totalGB);
        r.value = FormatSize(g.disks[i].freeGB) + TR(L" libres", L" free", L" lliures");
        rows.push_back(r);
    }

    if (g.showBattery && g.batPct >= 0) {
        SysRow r;
        r.kind = 0;
        r.label = L"Bat";
        r.pct = (float)g.batPct;
        r.colorPct = 100.0f - (float)g.batPct;
        r.value = std::to_wstring(g.batPct) + L" %";
        if (g.batAC) r.value += TR(L"  \u00B7  cargando", L"  \u00B7  charging", L"  \u00B7  carregant");
        rows.push_back(r);
    }

    if (g.showWifi && !g.wifiSsid.empty()) {
        SysRow r;
        r.kind = 1;
        r.label = L"Wi-Fi";
        r.value = g.wifiSsid;
        if (g.wifiQ >= 0) r.value += L"  \u00B7  " + std::to_wstring(g.wifiQ) + L" %";
        rows.push_back(r);
    }

    return rows;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static void DrawBar(Canvas& cv, float x0, float cy, float w, float h, float pct, RGBA ac, RGBA track) {
    if (w <= 1.0f) return;
    float hh = h / 2.0f;
    FillRRect(cv, x0 + w / 2.0f, cy, w / 2.0f, hh, hh, [track](float, float) -> RGBA { return track; });
    float f = Clamp01(pct / 100.0f);
    float fw = w * f;
    if (fw < 1.0f) return;
    float hw = std::max(fw / 2.0f, hh);
    FillRRect(cv, x0 + hw, cy, hw, hh, hh, [ac](float, float) -> RGBA {
        RGBA c = ac;
        c.a = 0.95f;
        return c;
    });
}

static RGBA HslToRgb(float deg, float s, float l) {
    float c = (1.0f - fabsf(2.0f * l - 1.0f)) * s;
    float hp = deg / 60.0f;
    float x = c * (1.0f - fabsf(fmodf(hp, 2.0f) - 1.0f));
    float r = 0, gg = 0, b = 0;
    if (hp < 1) { r = c; gg = x; }
    else if (hp < 2) { r = x; gg = c; }
    else if (hp < 3) { gg = c; b = x; }
    else if (hp < 4) { gg = x; b = c; }
    else if (hp < 5) { r = x; b = c; }
    else { r = c; b = x; }
    float m = l - c / 2.0f;
    return C((r + m) * 255.0f, (gg + m) * 255.0f, (b + m) * 255.0f);
}

static RGBA CalTone(const std::wstring& s) {
    unsigned int h = 2166136261u;
    for (size_t i = 0; i < s.size(); i++) {
        h ^= (unsigned int)(unsigned short)towlower(s[i]);
        h *= 16777619u;
    }
    return HslToRgb((float)(h % 360u), 0.55f, 0.62f);
}

static HFONT CalTagFont(float k) {
    static int cachedPx = 0;
    static HFONT cachedFont = nullptr;
    int px = (int)(10.0f * k);
    if (px < 9) px = 9;
    if (cachedFont && cachedPx == px) return cachedFont;
    if (cachedFont) DeleteObject(cachedFont);
    cachedPx = px;
    cachedFont = MakeFont(px, FW_SEMIBOLD);
    return cachedFont;
}

static void CalFrame(Canvas& cv, TextCtx& t, float k, float x0, float x1, float y0, float y1,
                     const std::wstring& label, RGBA tone) {
    float cx = (x0 + x1) / 2.0f, cy = (y0 + y1) / 2.0f;
    float hw = (x1 - x0) / 2.0f, hh = (y1 - y0) / 2.0f;
    float rad = 9.0f * k;
    if (hh < 3.0f) return;

    HFONT hf = CalTagFont(k);
    float tagW = 0.0f, tagH = 0.0f, tx = cx;
    if (!label.empty()) {
        HGDIOBJ old = SelectObject(t.dc, hf);
        SIZE sz = {0, 0};
        GetTextExtentPoint32W(t.dc, label.c_str(), (int)label.size(), &sz);
        SelectObject(t.dc, old);
        tagW = (float)sz.cx / 2.0f + 5.0f * k;
        tagH = (float)sz.cy;
        float maxHalf = hw - rad;
        if (tagW > maxHalf) tagW = maxHalf;
    }
    bool hasTag = tagW > 0.0f;

    FillRRect(cv, cx, cy, hw, hh, rad, [tone](float, float) -> RGBA { RGBA c = tone; c.a = 0.13f; return c; });
    FillSdf(cv, x0 - 2.0f, y0 - 2.0f, x1 + 2.0f, y1 + 2.0f,
            [=](float x, float y) { return fabsf(SdRoundRect(x, y, cx, cy, hw, hh, rad) + 0.6f) - 0.6f; },
            [=](float x, float y) -> RGBA {
                if (hasTag && fabsf(x - tx) < tagW && y < y0 + 3.0f * k) return kNone;
                RGBA c = tone;
                c.a = 0.55f;
                return c;
            });
    if (hasTag) {
        RGBA tagCol = tone;
        tagCol.a = 1.0f;
        DrawLabel(t, hf, label, tx, y0 - tagH / 2.0f, 1, tagCol);
    }
}

static void TileBox(Canvas& cv, float cx, float cy, float hw, float hh, float rad, float fillA) {
    FillRRect(cv, cx, cy, hw, hh, rad, [fillA](float, float) -> RGBA { return HL(fillA); });

    FillSdf(cv, cx - hw - 2, cy - hh - 2, cx + hw + 2, cy + hh + 2,
            [=](float x, float y) { return fabsf(SdRoundRect(x, y, cx, cy, hw, hh, rad) + 0.6f) - 0.6f; },
            [](float, float) -> RGBA { return HL(0.10f); });
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
static constexpr float kSysGaugeTop = 40.0f;
static constexpr float kSysGaugeH = 88.0f;
static constexpr float kSysGaugeCy = 37.0f;
static constexpr float kSysGaugeR = 29.0f;
static constexpr float kSysGaugeStroke = 3.6f;
static constexpr float kSysArcStart = 145.0f;
static constexpr float kSysArcSweep = 250.0f;
static constexpr float kSysGraphTop = 136.0f;
static constexpr float kSysGraphBottom = 194.0f;
static constexpr float kSysPlotTopOff = 24.0f;
static constexpr float kSysPlotBottomOff = 7.0f;
static constexpr float kSysNetTop = 202.0f;
static constexpr float kSysNetH = 30.0f;
static constexpr float kSysNetLabelW = 67.0f;
static constexpr float kSystemDetailsTop = 240.0f;
static constexpr float kSystemDetailRow = 19.0f;
static constexpr float kSystemDetailPad = 4.0f;
static constexpr float kSystemSectionHeader = 18.0f;
static constexpr float kSystemProcessHeight = 38.0f;

static int SystemGaugeCount() { return 2 + (g.showGpu ? 1 : 0) + (g.showDisk ? 1 : 0); }

static float SystemDetailsH(size_t rows) {
    return rows ? (float)rows * kSystemDetailRow + 2.0f * kSystemDetailPad : 0.0f;
}

static float SystemProcessTop(size_t rows) {
    return kSystemDetailsTop + (rows ? SystemDetailsH(rows) + 10.0f : 0.0f) + kSystemSectionHeader;
}

static void FillArc(Canvas& cv, float cx, float cy, float R, float hw, float a0, float sweep, RGBA col) {
    if (sweep <= 0.0f) return;
    const float rad = 0.0174532925f;
    const float ax = cx + cosf(a0 * rad) * R, ay = cy + sinf(a0 * rad) * R;
    const float bx = cx + cosf((a0 + sweep) * rad) * R, by = cy + sinf((a0 + sweep) * rad) * R;
    const float ext = R + hw + 2.0f;
    FillSdf(cv, cx - ext, cy - ext, cx + ext, cy + ext,
            [=](float x, float y) -> float {
                const float dx = x - cx, dy = y - cy;
                const float radial = fabsf(Len2(dx, dy) - R) - hw;

                if (radial > 1.5f) return radial;
                float ang = atan2f(dy, dx) / rad - a0;
                while (ang < 0.0f) ang += 360.0f;
                while (ang >= 360.0f) ang -= 360.0f;
                if (ang <= sweep) return radial;
                return std::min(Len2(x - ax, y - ay), Len2(x - bx, y - by)) - hw;
            },
            [col](float, float) -> RGBA { return col; });
}

static RGBA SysTone(RGBA base, float pct) {
    if (pct >= 90.0f) return g.pal.light ? C(200, 40, 40) : C(255, 100, 100);
    if (pct >= 70.0f) return g.pal.light ? C(185, 105, 0) : C(255, 190, 80);
    return base;
}

static void DrawSystemStatic(Canvas& cv, float M, float k, float cardWu) {
    const float left = M + 18.0f * k;
    const float right = M + (cardWu - 18.0f) * k;
    const float innerW = cardWu - 36.0f;
    const float mid = (left + right) * 0.5f;

    const int n = SystemGaugeCount();
    const float gap = 8.0f * k;
    const float tw = (right - left - gap * (float)(n - 1)) / (float)n;
    const float gy = M + kSysGaugeTop * k;
    for (int i = 0; i < n; ++i) {
        const float cx = left + (float)i * (tw + gap) + tw * 0.5f;
        TileBox(cv, cx, gy + kSysGaugeH * 0.5f * k, tw * 0.5f, kSysGaugeH * 0.5f * k, 14.0f * k, 0.07f);
        FillArc(cv, cx, gy + kSysGaugeCy * k, kSysGaugeR * k, kSysGaugeStroke * k,
                kSysArcStart, kSysArcSweep, HL(0.13f));
    }

    const float boxTop = M + kSysGraphTop * k, boxBot = M + kSysGraphBottom * k;
    TileBox(cv, mid, (boxTop + boxBot) * 0.5f, innerW * 0.5f * k, (boxBot - boxTop) * 0.5f, 12.0f * k, 0.065f);
    const float plotL = left + 39.0f * k, plotR = right - 12.0f * k;
    const float plotT = boxTop + kSysPlotTopOff * k, plotB = boxBot - kSysPlotBottomOff * k;
    for (int i = 0; i < 3; ++i) {
        const float y = Lerp(plotB, plotT, i * 0.5f);
        FillCapsule(cv, plotL, y, plotR, y, 0.4f * k, [i](float, float) -> RGBA { return HL(i == 0 ? 0.18f : 0.10f); });
    }

    const float ncy = M + (kSysNetTop + kSysNetH * 0.5f) * k;
    TileBox(cv, mid, ncy, (right - left) * 0.5f, kSysNetH * 0.5f * k, 11.0f * k, 0.065f);
    const float labelEdge = left + kSysNetLabelW * k;
    for (const float x : {labelEdge, (labelEdge + right) * 0.5f})
        FillCapsule(cv, x, ncy - 8.0f * k, x, ncy + 8.0f * k, 0.45f * k,
                    [](float, float) -> RGBA { return HL(0.14f); });

    const size_t rows = BuildSysRows().size();
    if (rows) {
        const float tileH = SystemDetailsH(rows);
        const float tileTop = M + kSystemDetailsTop * k;
        TileBox(cv, mid, tileTop + tileH * 0.5f * k, (right - left) * 0.5f, tileH * 0.5f * k, 12.0f * k, 0.065f);
    }
}

static void DrawGauge(Canvas& cv, TextCtx& t, Fonts& f, float cx, float y0, float tw, float k,
                      const wchar_t* label, float arcPct, float readingPct, bool hasValue, RGBA base,
                      const std::wstring& detail) {
    const RGBA white = g.pal.white, soft = g.pal.soft;
    const float cy = y0 + kSysGaugeCy * k, R = kSysGaugeR * k, hw = kSysGaugeStroke * k;
    const RGBA ink = hasValue ? SysTone(base, arcPct) : soft;

    if (hasValue && arcPct > 0.0f) {
        const float p = std::clamp(arcPct, 0.0f, 100.0f);
        const float sweep = std::max(kSysArcSweep * p / 100.0f, 0.6f);
        RGBA glow = ink;
        glow.a = 0.20f;
        FillArc(cv, cx, cy, R, hw + 2.2f * k, kSysArcStart, sweep, glow);
        RGBA c = ink;
        c.a = 1.0f;
        FillArc(cv, cx, cy, R, hw, kSysArcStart, sweep, c);
    }

    const std::wstring num = hasValue ? std::to_wstring((int)lroundf(std::clamp(readingPct, 0.0f, 100.0f))) : std::wstring(L"\u2013");
    const float nw = (float)MeasureWidth(t, f.time, num);
    const float pw = hasValue ? (float)MeasureWidth(t, f.small, L"%") + 1.0f * k : 0.0f;
    const float tx = cx - (nw + pw) * 0.5f;
    DrawLabel(t, f.time, num, tx, cy - 16.0f * k, 0, white);
    if (hasValue) DrawLabel(t, f.small, L"%", tx + nw + 1.0f * k, cy - 8.0f * k, 0, soft);

    DrawLabel(t, f.pill, label, cx, cy + 16.0f * k, 1, ink);
    DrawLabel(t, f.small, Ellipsize(t, f.small, detail, (int)(tw - 8.0f * k)), cx, y0 + 69.0f * k, 1, soft);
}

static float NetworkMeterLevel(double bytesPerSecond) {
    if (!std::isfinite(bytesPerSecond) || bytesPerSecond <= 0.0) return 0.0f;
    return (float)std::min(1.0, std::log1p(bytesPerSecond / 1024.0) /
                               std::log1p(1000000000.0 / 1024.0));
}

static void DrawSystem(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu) {
    const float left = M + 18.0f * k;
    const float right = M + (cardWu - 18.0f) * k;
    const float innerW = cardWu - 36.0f;
    const RGBA white = g.pal.white, soft = g.pal.soft, dimc = g.pal.dimc;
    const bool lt = g.pal.light;
    DrawCardHeader(cv, t, f, CARD_SYSTEM, M, k, TR(L"SISTEMA", L"SYSTEM", L"SISTEMA"));

    ULONGLONG up = GetTickCount64() / 1000ULL;
    unsigned long days = (unsigned long)(up / 86400ULL);
    unsigned long hours = (unsigned long)((up % 86400ULL) / 3600ULL);
    unsigned long mins = (unsigned long)((up % 3600ULL) / 60ULL);
    std::wstring upText = TR(L"Activo ", L"Up ", L"Actiu ");
    if (days > 0)
        upText += std::to_wstring(days) + L" d " + std::to_wstring(hours) + L" h";
    else if (hours > 0)
        upText += std::to_wstring(hours) + L" h " + std::to_wstring(mins) + L" min";
    else
        upText += std::to_wstring(mins) + L" min";
    DrawLabel(t, f.small, upText, right, M + 12.0f * k, 2, dimc);

    const RGBA cpuBase = lt ? C(14, 100, 185) : C(96, 175, 255);
    const RGBA ramBase = lt ? C(112, 72, 205) : C(176, 150, 255);
    const RGBA gpuBase = lt ? C(10, 135, 120) : C(64, 214, 190);
    const RGBA dskBase = lt ? C(170, 40, 130) : C(240, 130, 200);
    const RGBA dlInk = lt ? C(20, 130, 70) : C(110, 222, 150);
    const RGBA ulInk = lt ? C(190, 95, 10) : C(255, 172, 92);

    // CPU, memory, optional GPU, and disk activity gauges.
    const bool hasCpu = !g.hist.empty();
    double peak = 0.0;
    for (const auto& s : g.hist) peak = std::max(peak, s.second);
    const int n = SystemGaugeCount();
    const bool compact = n >= 4;
    const float gap = 8.0f * k;
    const float tw = (right - left - gap * (float)(n - 1)) / (float)n;
    const float gy = M + kSysGaugeTop * k;
    int slot = 0;
    auto gx = [&]() { return left + (float)(slot++) * (tw + gap) + tw * 0.5f; };
    const std::wstring noData = TR(L"Sin datos", L"No data", L"Sense dades");

    DrawGauge(cv, t, f, gx(), gy, tw, k, L"CPU", (float)g.cpuMeter, (float)g.cpu, hasCpu, cpuBase,
              hasCpu ? TR(L"pico ", L"peak ", L"pic ") + FormatNum(peak, 0) + L" %" : noData);
    DrawGauge(cv, t, f, gx(), gy, tw, k, L"RAM", (float)g.ramPct, (float)g.ramPct, g.ramTotalGB > 0.0, ramBase,
              compact ? FormatNum(g.ramUsedGB, 1) + L" GB"
                      : FormatNum(g.ramUsedGB, 1) + L" / " + FormatNum(g.ramTotalGB, 1) + L" GB");
    if (g.showGpu)
        DrawGauge(cv, t, f, gx(), gy, tw, k, L"GPU", (float)g_gpu, (float)g_gpu, g_gpu >= 0.0, gpuBase,
                  g_gpu < 0.0 ? noData
                  : compact   ? std::wstring(TR(L"gr\u00E1fica", L"graphics", L"gr\u00E0fica"))
                              : std::wstring(TR(L"carga gr\u00E1fica", L"graphics load", L"c\u00E0rrega gr\u00E0fica")));
    if (g.showDisk)
        DrawGauge(cv, t, f, gx(), gy, tw, k, TR(L"DISCO", L"DISK", L"DISC"), (float)g_dsk, (float)g_dsk, g_dsk >= 0.0, dskBase,
                  g_dsk < 0.0 ? noData : std::wstring(TR(L"actividad", L"activity", L"activitat")));

    // 60-second CPU history.
    const float boxTop = M + kSysGraphTop * k, boxBot = M + kSysGraphBottom * k;
    DrawLabel(t, f.small, TR(L"CPU \u00B7 \u00FAltimos 60 s", L"CPU \u00B7 last 60 s", L"CPU \u00B7 \u00FAltims 60 s"),
              left + 12.0f * k, boxTop + 4.0f * k, 0, soft);

    const float plotL = left + 39.0f * k, plotR = right - 12.0f * k;
    const float plotT = boxTop + kSysPlotTopOff * k, plotB = boxBot - kSysPlotBottomOff * k;
    const wchar_t* axisLabels[] = {L"0", L"50", L"100 %"};
    for (int i = 0; i < 3; ++i) {
        const float y = Lerp(plotB, plotT, i * 0.5f);
        DrawLabel(t, f.small, axisLabels[i], plotL - 5.0f * k, y - 7.0f * k, 2, dimc);
    }
    if (!hasCpu) {
        DrawLabel(t, f.small, TR(L"Recogiendo muestras\u2026", L"Collecting samples\u2026", L"Recollint mostres\u2026"),
                  (plotL + plotR) * 0.5f, (plotT + plotB) * 0.5f - 8.0f * k, 1, soft);
    } else {
        const RGBA line = SysTone(cpuBase, (float)g.cpuMeter);
        const ULONGLONG latest = g.hist.back().first;
        const int base = (int)floorf(plotL);
        std::vector<float> colY((size_t)((int)ceilf(plotR) - base + 2), -1.0f);
        float prevX = 0.0f, prevY = 0.0f;
        ULONGLONG previous = 0;
        for (const auto& s : g.hist) {
            const float x = Lerp(plotR, plotL, (float)(latest - s.first) / 60000.0f);
            const float y = Lerp(plotB, plotT, Clamp01((float)s.second / 100.0f));
            if (previous && s.first - previous <= 2500) {
                FillCapsule(cv, prevX, prevY, x, y, 1.25f * k, [line](float, float) -> RGBA { return line; });
                for (int xi = (int)ceilf(prevX); xi <= (int)floorf(x); ++xi) {
                    const int idx = xi - base;
                    if (idx < 0 || idx >= (int)colY.size()) continue;
                    const float tt = x > prevX ? ((float)xi - prevX) / (x - prevX) : 1.0f;
                    colY[(size_t)idx] = Lerp(prevY, y, tt);
                }
            }
            previous = s.first;
            prevX = x;
            prevY = y;
        }
        Paint(cv, plotL, plotT - 2.0f, plotR + 1.0f, plotB + 1.0f, [&](float px, float py) -> RGBA {
            const int idx = (int)floorf(px) - base;
            if (idx < 0 || idx >= (int)colY.size() || colY[(size_t)idx] < 0.0f || py < colY[(size_t)idx] || py > plotB)
                return kNone;
            const float tt = Clamp01((py - colY[(size_t)idx]) / std::max(plotB - colY[(size_t)idx], 1.0f));
            RGBA c = line;
            c.a = 0.34f * (1.0f - tt) * (1.0f - tt);
            return c;
        });
        FillCircle(cv, plotR, prevY, 5.0f * k, [line](float, float) -> RGBA { RGBA c = line; c.a = 0.22f; return c; });
        FillCircle(cv, plotR, prevY, 2.7f * k, [line](float, float) -> RGBA { return line; });
        if (g.cpuGraphHover >= 0) {
            const std::pair<ULONGLONG, double>* nearest = nullptr;
            ULONGLONG error = 1251;
            for (const auto& sample : g.hist) {
                const ULONGLONG age = latest - sample.first;
                const ULONGLONG wanted = (ULONGLONG)g.cpuGraphHover;
                const ULONGLONG distance = age > wanted ? age - wanted : wanted - age;
                if (distance < error) { error = distance; nearest = &sample; }
            }
            if (nearest) {
                const float age = (float)(latest - nearest->first) / 1000.0f;
                const float x = Lerp(plotR, plotL, age / 60.0f);
                const float y = Lerp(plotB, plotT, Clamp01((float)nearest->second / 100.0f));
                const auto label = FormatNum(age, 1) + L" s · " + FormatNum(nearest->second, 1) + L" %";
                DrawLabel(t, f.pill, label, right - 12.0f * k, boxTop + 2.0f * k, 2, white);
                FillCircle(cv, x, y, 3.3f * k, [white](float, float) -> RGBA { return white; });
            } else {
                DrawLabel(t, f.small, TR(L"Sin muestra", L"No sample", L"Sense mostra"),
                          right - 12.0f * k, boxTop + 4.0f * k, 2, soft);
            }
        }
    }

    // Download and upload rates and meters.
    {
        const float cy = M + (kSysNetTop + kSysNetH * 0.5f) * k;
        const float labelEdge = left + kSysNetLabelW * k;
        const float half = (right - labelEdge) * 0.5f;
        const RGBA netInk = lt ? C(30, 104, 54) : C(176, 229, 111);
        DrawLabel(t, f.pill, TR(L"RED", L"NET", L"XARXA"),
                  (left + labelEdge) * 0.5f, cy - 10.0f * k, 1, netInk);
        const std::wstring arrows[2] = {L"\u2193", L"\u2191"};
        const double speeds[2] = {g.dlSpeed, g.ulSpeed};
        const RGBA inks[2] = {dlInk, ulInk};
        constexpr int segments = 7;
        const float pitch = 3.6f * k;
        const float meterWidth = segments * pitch;
        for (int i = 0; i < 2; ++i) {
            const float x0 = labelEdge + i * half;
            const float textX = x0 + 22.0f * k;
            const float meterX = x0 + half - 8.0f * k - meterWidth;
            const auto rate = FormatRate(speeds[i]);
            const int textWidth = (int)(meterX - textX - 5.0f * k);
            const HFONT font = MeasureWidth(t, f.pill, rate) <= textWidth ? f.pill : f.small;
            DrawLabel(t, f.pill, arrows[i], x0 + 8.0f * k, cy - 10.0f * k, 0, inks[i]);
            DrawLabel(t, font, Ellipsize(t, font, rate, textWidth), textX, cy - 10.0f * k, 0, white);
            const float level = NetworkMeterLevel(speeds[i]) * segments;
            for (int j = 0; j < segments; ++j) {
                const float x = meterX + (j + 0.5f) * pitch;
                FillRRect(cv, x, cy, 1.05f * k, 6.0f * k, k,
                          [](float, float) -> RGBA { return HL(0.16f); });
                const float lit = Clamp01(level - j);
                if (lit <= 0.0f) continue;
                RGBA ink = inks[i];
                ink.a *= lit;
                FillRRect(cv, x, cy, 1.05f * k, 6.0f * k, k,
                          [ink](float, float) -> RGBA { return ink; });
            }
        }
    }

    // Drive usage, battery, and Wi-Fi.
    const auto rows = BuildSysRows();
    if (!rows.empty()) {
        const float tileTop = M + kSystemDetailsTop * k;
        float valW = 0.0f;
        for (const auto& row : rows)
            if (row.kind == 0) valW = std::max(valW, (float)MeasureWidth(t, f.small, row.value));
        const float xl = left + 12.0f * k, xr = right - 12.0f * k;
        for (size_t i = 0; i < rows.size(); ++i) {
            const auto& row = rows[i];
            const float cy = tileTop + (kSystemDetailPad + ((float)i + 0.5f) * kSystemDetailRow) * k;
            DrawLabel(t, f.pill, row.label, xl, cy - 10.0f * k, 0, white);
            if (row.kind == 0) {
                const float bx = xl + 38.0f * k;
                DrawBar(cv, bx, cy, xr - valW - 12.0f * k - bx, 6.0f * k, row.pct, LoadColor(row.colorPct), HL(0.13f));
                DrawLabel(t, f.small, row.value, xr, cy - 8.0f * k, 2, soft);
            } else {
                DrawLabel(t, f.small, Ellipsize(t, f.small, row.value, (int)(xr - xl - 50.0f * k)), xr,
                          cy - 8.0f * k, 2, soft);
            }
        }
    }

    // Busiest processes and relative activity.
    if (g.procs.empty()) return;
    const float processTop = SystemProcessTop(rows.size());
    DrawLabel(t, f.small, TR(L"PROCESOS", L"PROCESSES", L"PROCESSOS"), left, M + (processTop - kSystemSectionHeader) * k, 0, soft);
    std::wstring detail = g.procByRam ?
        TR(L"Memoria privada comprometida", L"Private committed memory", L"Memòria privada compromesa") : L"CPU";
    double top = 0.0;
    for (const auto& p : g.procs) top = std::max(top, g.procByRam ? p.ramMB : p.cpu);
    const RGBA procInk = g.procByRam ? ramBase : cpuBase;
    const float colWidth = (right - left) / (float)g.procs.size();
    for (size_t i = 0; i < g.procs.size(); ++i) {
        const ProcInfo& process = g.procs[i];
        const float x = left + ((float)i + 0.5f) * colWidth;
        const float y = M + processTop * k;
        const double raw = g.procByRam ? process.ramMB : process.cpu;
        const std::wstring value = g.procByRam ?
            (process.ramMB >= 1024.0 ? FormatNum(process.ramMB / 1024.0, 1) + L" GB" :
             FormatNum(process.ramMB, 0) + L" MB") : FormatNum(process.cpu, 1) + L" %";
        if (g.processHover == (int)i) {
            detail = process.name + L" \u00B7 " + value;
            FillRRect(cv, x, y + 19.0f * k, colWidth * 0.5f - 2.0f * k, 19.5f * k, 7.0f * k,
                      [](float, float) -> RGBA { return HL(0.13f); });
        }
        const int width = (int)(colWidth - 8.0f * k);
        DrawLabel(t, f.small, Ellipsize(t, f.small, process.name, width), x, y, 1, soft);
        DrawLabel(t, f.pill, Ellipsize(t, f.pill, value, width), x, y + 13.0f * k, 1, white);
        DrawBar(cv, x - (colWidth - 18.0f * k) * 0.5f, y + 35.0f * k, colWidth - 18.0f * k, 3.0f * k,
                top > 0.0 ? (float)(raw * 100.0 / top) : 0.0f, procInk, HL(0.12f));
    }
    DrawLabel(t, f.small, Ellipsize(t, f.small, detail, (int)((innerW - 86.0f) * k)), right,
              M + (processTop - kSystemSectionHeader) * k, 2, soft);
}

static float SystemCardH() {
    const size_t rows = BuildSysRows().size();
    if (g.procs.empty())
        return (rows ? kSystemDetailsTop + SystemDetailsH(rows) : kSysNetTop + kSysNetH) + 10.0f;
    return SystemProcessTop(rows) + kSystemProcessHeight + 10.0f;
}

// Calendar card

static std::wstring DeadlineGroupText(int group) {
    switch (group) {
        case 1: return TR(L"HOY", L"TODAY", L"AVUI");
        case 2: return TR(L"MA\u00D1ANA", L"TOMORROW", L"DEM\u00C0");
        case 3: return TR(L"ESTA SEMANA", L"THIS WEEK", L"AQUESTA SETMANA");
        default: return TR(L"M\u00C1S ADELANTE", L"LATER", L"M\u00C9S ENDAVANT");
    }
}

static std::wstring DeadlineCountdown(const Deadline& d) {
    if (d.days <= 0) return TR(L"Hoy", L"Today", L"Avui");
    if (d.days == 1) return TR(L"Ma\u00F1ana", L"Tomorrow", L"Dem\u00E0");
    return std::to_wstring(d.days) + L" d";
}

static std::wstring DeadlineTimeText(const Deadline& d) {
    if (d.hh < 0) return TR(L"todo el d\u00EDa", L"all day", L"tot el dia");
    wchar_t b[16];
    wsprintfW(b, L"%02d:%02d", d.hh, d.mm);
    return b;
}

static void DrawDeadlines(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu) {
    float right = M + (cardWu - 18.0f) * k;
    float left = M + 18.0f * k;
    RGBA white = g.pal.white, soft = g.pal.soft, dimc = g.pal.dimc;

    DrawCardHeader(cv, t, f, CARD_DEADLINES, M, k, TR(L"AGENDA", L"CALENDAR", L"AGENDA"));

    SYSTEMTIME st;
    GetLocalTime(&st);
    std::wstring today = std::wstring(DowName((int)st.wDayOfWeek)) + L" " +
                         std::to_wstring((int)st.wDay) + L" " + MonthShort((int)st.wMonth);
    if (g.icsMissingSources > 0)
        today = std::to_wstring(g.icsMissingSources) +
            TR(L" sin sincronizar", L" not synced", L" sense sincronitzar");
    DrawLabel(t, f.small, today, right, M + 13.0f * k, 2,
              g.icsMissingSources ? CardAccent(C(255, 176, 65)) : dimc);

    std::vector<Deadline> vis = VisibleDeadlines();
    if (vis.empty()) {
        DrawLabel(t, f.name, TR(L"Sin citas pr\u00F3ximas", L"No upcoming events", L"Sense cites properes"),
                  left, M + 52.0f * k, 0, soft);
        return;
    }

    float y = 38.0f;
    int prevG = -99;
    for (size_t i = 0; i < vis.size(); i++) {
        const Deadline& d = vis[i];
        int gv = AgendaGroupOf(d.days);
        if (gv != prevG) {
            prevG = gv;
            DrawLabel(t, f.small, DeadlineGroupText(gv), left, M + (y + 6.0f) * k, 0, dimc);
            FillRRect(cv, (left + 90.0f * k + right) / 2.0f, M + (y + 12.0f) * k,
                      (right - left - 90.0f * k) / 2.0f, 0.5f * k, 0.5f * k,
                      [](float, float) -> RGBA { return HL(0.10f); });
            y += 20.0f;
        }

        bool framed = d.fromIcs;
        float yy = y + (framed ? 8.0f : 0.0f);
        if (framed) {
            std::wstring clave = d.tag.empty() ? std::wstring(L"calendario") : d.tag;
            CalFrame(cv, t, k, left - 7.0f * k, right + 7.0f * k, M + (y + 4.0f) * k,
                     M + (y + DeadlineRowH(d) - 4.0f) * k, d.tag, CalTone(clave));
        }
        bool done = DeadlineDone(d);
        RGBA urg = UrgencyColor(d.days);
        if (done) urg = C(140, 150, 165);

        DrawLabel(t, f.pill, DeadlineCountdown(d), left, M + (yy + 6.0f) * k, 0, urg);
        DrawLabel(t, f.small, DeadlineTimeText(d), left, M + (yy + 24.0f) * k, 0, dimc);

        float tx = left + 72.0f * k;
        float maxW = right - tx;
        std::wstring title = d.name.empty() ? TR(L"Cita", L"Event", L"Cita") : d.name;
        DrawLabel(t, f.name, Ellipsize(t, f.name, title, (int)maxW), tx, M + (yy + 4.0f) * k, 0,
                  done ? dimc : white);
        std::wstring sub = d.place;
        if (!d.badge.empty() && !framed) {
            if (!sub.empty()) sub += L"  \u00B7  ";
            sub += d.badge;
        }
        if (!sub.empty())
            DrawLabel(t, f.small, Ellipsize(t, f.small, sub, (int)maxW), tx, M + (yy + 24.0f) * k, 0, soft);

        float prog = d.days <= 0 ? 100.0f : (d.days >= 7 ? 6.0f : 100.0f - (float)d.days * 13.0f);
        DrawBar(cv, tx, M + (yy + 42.0f) * k, std::min(maxW, 200.0f * k), 2.4f * k, prog, urg,
                C(255, 255, 255, 0.10f));

        y += DeadlineRowH(d);
    }
}

// Sticky note card

static float StickyCardHu(float k) {
    Fonts& fonts = EnsureFonts(k);
    const HFONT font = g.stickyText.size() > 100 ? fonts.name : fonts.note;
    int lines = g.stickyLines;
    if (g.stickyCompact && !g.stickyEditing) {
        static std::wstring lastText;
        static float lastScale = 0.0f;
        static int wrapped = 1;
        if (lastText != g.stickyText || lastScale != k) {
            HDC dc = CreateCompatibleDC(nullptr);
            if (dc) {
                TextCtx measure = {dc, nullptr, 0, 0, nullptr};
                wrapped = g.stickyText.empty() ? 1 :
                    (int)WrapLines(measure, font, g.stickyText, (int)(336.0f * k)).size();
                lastText = g.stickyText;
                lastScale = k;
                DeleteDC(dc);
            }
        }
        lines = ClampInt(wrapped, std::min(2, g.stickyLines), g.stickyLines);
    }
    return kStickyTextTop + (float)lines * ((float)g.notePitch / k) + kStickyPad;
}

static void DrawStickyHeader(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu, bool folded,
                             bool editing = false) {
    (void)cardWu;
    RGBA ink = C(58, 44, 18, 0.95f);

    float pcx = M + 30.0f * k, pcy = M + 20.0f * k;
    FillCircle(cv, pcx, pcy + 1.5f * k, 9.0f * k, [](float, float) -> RGBA { return C(0, 0, 0, 0.18f); });
    FillCircle(cv, pcx, pcy, 8.5f * k, [=](float, float y) -> RGBA {
        float tt = Clamp01((y - (pcy - 8.5f * k)) / (17.0f * k));
        return LerpC(C(255, 120, 108), C(186, 28, 40), tt);
    });
    FillCircle(cv, pcx - 2.6f * k, pcy - 3.0f * k, 2.3f * k,
               [](float, float) -> RGBA { return C(255, 255, 255, 0.55f); });

    float saved = g.pal.shadow;
    g.pal.shadow = 0.0f;
    DrawLabel(t, f.head, TR(L"NOTAS", L"NOTES", L"NOTES"), M + 48.0f * k, M + 11.0f * k, 0, ink);

    float ix = M + kStickyClearX * k, iy = M + 20.0f * k;
    if (folded) {
        DrawLabel(t, f.small, L"\u25B8", ix + 8.0f * k, M + 12.0f * k, 2, ink);
    } else {
        FillCircle(cv, ix, iy, 11.0f * k, [](float, float) -> RGBA { return C(58, 44, 18, 0.10f); });
        auto icol = [](float, float) -> RGBA { return C(58, 44, 18, 0.80f); };
        if (g.stickyCanUndo) {
            std::vector<float> tri = {ix - 5.5f * k, iy, ix + 0.5f * k, iy - 4.5f * k, ix + 0.5f * k,
                                      iy + 4.5f * k};
            FillPoly(cv, tri, icol);
            FillCapsule(cv, ix, iy, ix + 5.0f * k, iy, 1.0f * k, icol);
        } else {
            FillCapsule(cv, ix - 4.0f * k, iy - 4.0f * k, ix + 4.0f * k, iy + 4.0f * k, 1.0f * k, icol);
            FillCapsule(cv, ix - 4.0f * k, iy + 4.0f * k, ix + 4.0f * k, iy - 4.0f * k, 1.0f * k, icol);
        }
    }
    g.pal.shadow = saved;
}

static void DrawSticky(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu, bool editing = false) {
    DrawStickyHeader(cv, t, f, M, k, cardWu, false);

    RGBA ink = C(58, 44, 18, 0.95f), dim = C(110, 88, 30, 0.70f);
    float saved = g.pal.shadow;
    g.pal.shadow = 0.0f;

    int maxW = (int)((cardWu - 36.0f) * k);
    float pitch = (float)g.notePitch;
    float y0 = M + kStickyTextTop * k;
    const HFONT font = g.stickyText.size() > 100 ? f.name : f.note;
    const float textHeight = (StickyCardHu(k) - kStickyTextTop - kStickyPad) * k;

    if (g.stickyText.empty()) {
        DrawLabel(t, f.note,
                  TR(L"Haz clic y escribe...", L"Click and start typing...", L"Fes clic i escriu..."),
                  M + 18.0f * k, y0, 0, dim);
    } else {
        std::vector<std::wstring> lines = WrapLines(t, font, g.stickyText, maxW);
        const int maxL = (int)lroundf(textHeight / pitch);
        for (int i = 0; i < (int)lines.size() && i < maxL; i++) {
            std::wstring ln = lines[(size_t)i];
            if (i == maxL - 1 && (int)lines.size() > maxL) ln = Ellipsize(t, font, ln + L"\u2026", maxW);
            DrawLabel(t, font, ln, M + 18.0f * k, y0 + pitch * (float)i, 0, ink);
        }
    }

    {
        const float py = y0 + textHeight + 2.0f * k;
        FillRRect(cv, (M + 18.0f * k + M + (cardWu - 18.0f) * k) / 2.0f, py,
                  ((cardWu - 36.0f) * k) / 2.0f, 0.5f * k, 0.5f * k,
                  [](float, float) -> RGBA { return C(120, 96, 40, 0.22f); });
        const auto foot = editing ? TR(L"Guardado automático", L"Autosave", L"Desament automàtic") :
            (g.stickyText.empty() ? L"" : TR(L"Nota", L"Note", L"Nota"));
        DrawLabel(t, f.small, foot, M + 18.0f * k, py + 5.0f * k, 0, C(81, 63, 19, 0.92f));
        if (editing) DrawLabel(t, f.small, TR(L"Esc para cerrar", L"Esc to close", L"Esc per tancar"),
                  M + (cardWu - 18.0f) * k, py + 5.0f * k, 2, C(81, 63, 19, 0.92f));
    }
    g.pal.shadow = saved;
}

// Media card

static RGBA EqColor(const EqPal& p, float t) {
    t = Clamp01(t);
    for (int i = 1; i < p.n; i++) {
        if (t <= p.stop[i]) {
            float d = p.stop[i] - p.stop[i - 1];
            return LerpC(p.col[i - 1], p.col[i], d > 0.0f ? (t - p.stop[i - 1]) / d : 1.0f);
        }
    }
    return p.col[p.n - 1];
}

static void EqPalSet(EqPal& p, int n, const RGBA* cols) {
    p.n = n;
    for (int i = 0; i < n; i++) {
        p.col[i] = cols[i];
        p.stop[i] = n > 1 ? (float)i / (float)(n - 1) : 0.0f;
    }
}

static void EqPalPreset(const std::wstring& name, EqPal& p) {
    if (name == L"bluepurple") {
        const RGBA c[5] = {C(40, 120, 255), C(70, 170, 255), C(130, 130, 255), C(170, 100, 255), C(225, 110, 255)};
        EqPalSet(p, 5, c);
    } else if (name == L"sunset") {
        const RGBA c[5] = {C(120, 90, 255), C(200, 90, 230), C(255, 100, 160), C(255, 150, 90), C(255, 210, 100)};
        EqPalSet(p, 5, c);
    } else if (name == L"fire") {
        const RGBA c[5] = {C(255, 225, 90), C(255, 175, 60), C(255, 115, 50), C(235, 55, 60), C(200, 30, 90)};
        EqPalSet(p, 5, c);
    } else if (name == L"green") {
        const RGBA c[5] = {C(30, 190, 160), C(60, 220, 130), C(130, 235, 90), C(200, 245, 100), C(245, 255, 160)};
        EqPalSet(p, 5, c);
    } else if (name == L"ice") {
        const RGBA c[5] = {C(70, 150, 255), C(110, 200, 255), C(160, 230, 255), C(210, 245, 255), C(255, 255, 255)};
        EqPalSet(p, 5, c);
    } else {
        const RGBA c[5] = {C(60, 200, 255), C(70, 230, 150), C(250, 228, 90), C(255, 150, 70), C(255, 70, 140)};
        EqPalSet(p, 5, c);
        const float st[5] = {0.0f, 0.30f, 0.55f, 0.78f, 1.0f};
        for (int i = 0; i < 5; i++) p.stop[i] = st[i];
    }
}

static bool EqParseHex(const std::wstring& in, RGBA& out) {
    std::wstring h;
    bool hash = false;
    for (size_t i = 0; i < in.size(); i++) {
        wchar_t c = in[i];
        if (c == L' ' || c == L'\t') continue;
        if (c == L'#' && h.empty() && !hash) {
            hash = true;
            continue;
        }
        h += c;
    }
    if (h.size() != 6) return false;
    unsigned v[6];
    for (int i = 0; i < 6; i++) {
        wchar_t c = h[i];
        if (c >= L'0' && c <= L'9') v[i] = (unsigned)(c - L'0');
        else if (c >= L'a' && c <= L'f') v[i] = (unsigned)(c - L'a' + 10);
        else if (c >= L'A' && c <= L'F') v[i] = (unsigned)(c - L'A' + 10);
        else return false;
    }
    out = C((float)(v[0] * 16 + v[1]), (float)(v[2] * 16 + v[3]), (float)(v[4] * 16 + v[5]));
    return true;
}

static EqPal EqPalAccent(const RGBA& ac) {
    EqPal p;
    const RGBA c[4] = {LerpC(ac, C(10, 20, 60), 0.45f), ac, LerpC(ac, C(255, 255, 255), 0.35f),
                       LerpC(ac, C(255, 255, 255), 0.70f)};
    EqPalSet(p, 4, c);
    return p;
}

static void ApplyEqPalette(const std::wstring& name, const std::wstring& lo, const std::wstring& mid,
                           const std::wstring& hi) {
    g.eqAccent = (name == L"accent");
    if (name == L"custom") {
        RGBA c[3] = {C(60, 120, 255), C(160, 100, 255), C(255, 100, 200)};
        EqParseHex(lo, c[0]);
        EqParseHex(mid, c[1]);
        EqParseHex(hi, c[2]);
        EqPalSet(g.eqPal, 3, c);
    } else {
        EqPalPreset(name, g.eqPal);
    }
}

static void DrawThumb(Canvas& cv, TextCtx& t, Fonts& f, float x0, float y0, float sz, float k, RGBA ac) {
    float cx = x0 + sz / 2.0f, cy = y0 + sz / 2.0f, hw = sz / 2.0f, rad = 11.0f * k;
    auto sd = [=](float x, float y) { return SdRoundRect(x, y, cx, cy, hw, hw, rad); };
    if (g.thumbOk && g.thumbS > 0 && (int)g.thumbPx.size() >= g.thumbS * g.thumbS) {
        const DWORD* px = g.thumbPx.data();
        const int S = g.thumbS;
        const auto now = GetTickCount64();
        const float fade = now < g_mediaCoverFadeUntil ?
            Clamp01(1.0f - (float)(g_mediaCoverFadeUntil - now) / 180.0f) : 1.0f;
        const RGBA tint = LerpC(ac, C(20, 24, 40), 0.65f);
        FillSdf(cv, x0 - 1, y0 - 1, x0 + sz + 1, y0 + sz + 1, sd, [=](float x, float y) -> RGBA {
            float u = (x - x0) / sz * (float)S - 0.5f;
            float v = (y - y0) / sz * (float)S - 0.5f;
            int ix = (int)floorf(u), iy = (int)floorf(v);
            float fx = u - (float)ix, fy = v - (float)iy;
            int xa = ClampInt(ix, 0, S - 1), xb = ClampInt(ix + 1, 0, S - 1);
            int ya = ClampInt(iy, 0, S - 1), yb = ClampInt(iy + 1, 0, S - 1);
            DWORD p00 = px[(size_t)ya * S + xa], p10 = px[(size_t)ya * S + xb];
            DWORD p01 = px[(size_t)yb * S + xa], p11 = px[(size_t)yb * S + xb];
            auto ch = [&](int sh) {
                float a = (float)((p00 >> sh) & 0xFF), b2 = (float)((p10 >> sh) & 0xFF);
                float c2 = (float)((p01 >> sh) & 0xFF), d = (float)((p11 >> sh) & 0xFF);
                return Lerp(Lerp(a, b2, fx), Lerp(c2, d, fx), fy) / 255.0f;
            };
            return LerpC(tint, RGBA{ch(16), ch(8), ch(0), 1.0f}, fade);
        });
    } else {
        FillSdf(cv, x0 - 1, y0 - 1, x0 + sz + 1, y0 + sz + 1, sd, [=](float, float y) -> RGBA {
            float tt = Clamp01((y - y0) / sz);
            RGBA c = LerpC(ac, LerpC(ac, C(20, 24, 40), 0.65f), tt);
            c.a = 0.55f;
            return c;
        });
        DrawLabel(t, f.big, L"\u266A", cx, cy - 24.0f * k, 1, g.pal.white);
    }

    FillSdf(cv, x0 - 2, y0 - 2, x0 + sz + 2, y0 + sz + 2,
            [=](float x, float y) { return fabsf(sd(x, y) + 0.5f) - 0.5f; },
            [](float, float) -> RGBA { return HL(0.22f); });
}

struct MetaPanel {
    MetaOnlineProposal online;
    CvFileId fileId;
    bool live = false;
    bool ready = false;
    bool loading = false;
    std::wstring path;
    std::wstring file;

    std::wstring fileTitle, fileArtist, fileYear, fileAlbum;
    std::vector<BYTE> fileImg, cardImg;
    std::wstring cardTitle, cardArtist;
    std::vector<DWORD> cardPixels;
    int cardSide = 0;
    unsigned long long coverTrack = 0;

    std::wstring newTitle, newArtist, newYear, newAlbum;
    std::vector<BYTE> newImg;
    int fpPct = 0;
    int dur = 0;
    unsigned long long size = 0, time = 0;
    std::wstring forArtist, forTitle;
};
static MetaPanel g_meta;
static SRWLOCK g_metaLock = SRWLOCK_INIT;

static bool MetaPanelCoverFor(const std::wstring& artist, const std::wstring& title,
                              std::vector<BYTE>& out) {
    AcquireSRWLockShared(&g_metaLock);
    bool ok = g_meta.ready && !g_meta.newImg.empty() && CvNorm(g_meta.forArtist) == CvNorm(artist) &&
              CvNorm(g_meta.forTitle) == CvNorm(title);
    if (ok) out = g_meta.newImg;
    ReleaseSRWLockShared(&g_metaLock);
    return ok;
}

static std::wstring MediaClock(double sec) {
    if (sec < 0.0) sec = 0.0;
    int total = (int)(sec + 0.5);
    int h = total / 3600, m = (total % 3600) / 60, ss = total % 60;
    wchar_t b[32];
    if (h > 0) wsprintfW(b, L"%d:%02d:%02d", h, m, ss);
    else wsprintfW(b, L"%d:%02d", m, ss);
    return b;
}

enum class Mp3CardStatus { None, Pending, Review, Saved, Complete, Incomplete, Locked };
static Mp3CardStatus MediaMp3Status();

static Mp3CardStatus MediaIndicatorStatus() {
    const Mp3CardStatus operation = MediaMp3Status();
    if (operation != Mp3CardStatus::None || !g.fileMeta.ok || !CvIsMp3(g.fileMeta.path)) return operation;
    if (g_embedLocked) return Mp3CardStatus::Locked;
    const auto& tags = g.fileMeta;
    return tags.coverOk && tags.titleOk && tags.artistOk && tags.yearOk ?
        Mp3CardStatus::Complete : Mp3CardStatus::Incomplete;
}

static const wchar_t* MediaMp3Label(Mp3CardStatus state) {
    switch (state) {
        case Mp3CardStatus::Pending: return TR(L"MP3 pendiente", L"MP3 queued", L"MP3 pendent");
        case Mp3CardStatus::Review: return TR(L"Revisar MP3", L"Review MP3", L"Revisa l’MP3");
        case Mp3CardStatus::Saved: return TR(L"MP3 guardado", L"MP3 saved", L"MP3 desat");
        case Mp3CardStatus::Complete: return TR(L"Etiquetas completas", L"Tags complete", L"Etiquetes completes");
        case Mp3CardStatus::Incomplete: return TR(L"Faltan etiquetas", L"Tags missing", L"Falten etiquetes");
        case Mp3CardStatus::Locked: return TR(L"MP3 en uso", L"MP3 in use", L"MP3 en ús");
        default: return TR(L"Metadatos del MP3", L"MP3 metadata", L"Metadades de l’MP3");
    }
}

static const wchar_t* MediaTransportHint(int control) {
    if (control == 0) return TR(L"Pista anterior", L"Previous track", L"Pista anterior");
    if (control == 2) return TR(L"Pista siguiente", L"Next track", L"Pista següent");
    return g.media.playing ? TR(L"Pausar", L"Pause", L"Pausa") :
        TR(L"Reproducir", L"Play", L"Reprodueix");
}

static MediaInfo MediaCardInfo() {
    MediaInfo mi = g.media;

    if (g.fileMeta.ok) {
        if (g.fileMeta.titleOk) mi.title = g.fileMeta.title;
        if (g.fileMeta.artistOk) mi.artist = g.fileMeta.artist;
        if (g.fileMeta.albumOk) {
            if (!mi.album.empty() && !SameMediaAlbum(mi.album, g.fileMeta.album) && !g.fileMeta.yearOk)
                mi.year.clear();
            mi.album = g.fileMeta.album;
        }
        if (g.fileMeta.yearOk) mi.year = g.fileMeta.year;
    }
    return mi;
}

static RECT g_mediaEqRect = {};
static Canvas g_mediaEqUnderlay, g_mediaEqPatch;
static bool g_mediaEqCached = false;

static void SaveMediaEqUnderlay(const Canvas& cv, float x0, float x1, float y0, float y1, float pad) {
    g_mediaEqRect = {std::max(0L, (LONG)floorf(x0 - pad)), std::max(0L, (LONG)floorf(y0 - pad)),
                    std::min((LONG)cv.w, (LONG)ceilf(x1 + pad)), std::min((LONG)cv.h, (LONG)ceilf(y1 + pad))};
    const RECT& r = g_mediaEqRect;
    g_mediaEqUnderlay.w = r.right - r.left;
    g_mediaEqUnderlay.h = r.bottom - r.top;
    const size_t width = (size_t)g_mediaEqUnderlay.w;
    g_mediaEqUnderlay.px.resize(width * g_mediaEqUnderlay.h);
    for (int y = 0; y < g_mediaEqUnderlay.h; ++y)
        memcpy(g_mediaEqUnderlay.px.data() + y * width, cv.px.data() + (r.top + y) * (size_t)cv.w + r.left,
               width * sizeof(DWORD));
    g_mediaEqCached = true;
}

static void DrawMediaEqualizer(Canvas& cv, float ex0, float ex1, float eTop, float eBase, float k, RGBA ac) {
    float eH = eBase - eTop;
    float bw = (ex1 - ex0) / (float)kEqBars;
    float bhw = std::max(0.8f * k, bw * 0.26f);
    const bool live = g.media.valid && g.media.playing;
    const EqPal pal = g.eqAccent ? EqPalAccent(ac) : g.eqPal;
    for (int i = 0; i < kEqBars; i++) {
        float v = live ? g_eqBars[i] : 0.0f;
        float barH = eH * Clamp01(v);
        float bcx2 = ex0 + bw * ((float)i + 0.5f);

        FillRRect(cv, bcx2, eBase - 0.9f * k, bhw, 0.9f * k, 0.9f * k,
                  [live, pal](float, float) -> RGBA { RGBA c = EqColor(pal, 0.0f); c.a = live ? 0.20f : 0.09f; return c; });
        float pk = live ? Clamp01(g_eqPeak[i]) : 0.0f;
        if (pk > 0.05f) {
            RGBA pc = LerpC(EqColor(pal, pk), C(255, 255, 255), 0.45f);
            pc.a = 0.95f;
            FillRRect(cv, bcx2, eBase - eH * pk - 1.6f * k, bhw, 0.8f * k, 0.8f * k,
                      [pc](float, float) -> RGBA { return pc; });
        }
        if (barH < 2.0f * k) continue;
        float bhh = barH / 2.0f;

        FillRRect(cv, bcx2, eBase - bhh, bhw, bhh, std::min(bhw, 2.4f * k),
                  [eBase, eH, pal](float, float y) -> RGBA {
                      RGBA c = EqColor(pal, (eBase - y) / eH);
                      c.a = 0.92f;
                      return c;
                  });
    }
}

static std::wstring MediaVolumeLabel() {
    if (GetTickCount64() >= g_mediaVolumeUntil) return {};
    if (g_mediaVolumeText < 0) return TR(L"Sin control de volumen", L"Volume unavailable", L"Volum no disponible");
    return std::wstring(TR(L"Volumen ", L"Volume ", L"Volum ")) + std::to_wstring(g_mediaVolumeText) + L" %";
}

static void DrawMediaHint(Canvas& cv, TextCtx& t, Fonts& f, float M, float k,
                          float x, float y, const std::wstring& hint) {
    const float left = M + kMediaInset * k, right = M + kMediaRight * k;
    const auto label = Ellipsize(t, f.small, hint, (int)(right - left - 18.0f * k));
    const float halfWidth = MeasureWidth(t, f.small, label) / 2.0f + 9.0f * k;
    const float cx = std::clamp(x, left + halfWidth, right - halfWidth);
    FillRRect(cv, cx, y, halfWidth, 10.0f * k, 5.0f * k, [](float, float) -> RGBA {
        return g.pal.light ? C(239, 243, 252) : C(23, 29, 44);
    });
    DrawLabel(t, f.small, label, cx, y - 7.5f * k, 1, g.pal.white);
}

static void DrawMediaMode(Canvas& cv, float x, float y, float k, bool repeat, bool active, bool hot) {
    const RGBA col = active ? MediaAccent() : g.pal.white;
    if (active || hot)
        FillCircle(cv, x, y, kMediaModeRadius * k, [](float, float) -> RGBA { return HL(0.18f); });
    auto ink = [col](float, float) -> RGBA { return col; };
    auto line = [&](float a, float b, float c, float d) {
        FillCapsule(cv, x + a*k, y + b*k, x + c*k, y + d*k, 0.8f*k, ink);
    };
    auto arrow = [&](float cx, float cy, float direction) {
        FillPoly(cv, {x + (cx + 2.3f*direction)*k, y + cy*k, x + (cx - 1.1f*direction)*k, y + (cy-2.3f)*k,
                      x + (cx - 1.1f*direction)*k, y + (cy+2.3f)*k}, ink);
    };
    if (repeat) {
        line(-5,-3,4,-3); line(-5,-3,-5,-1); arrow(4,-3,1);
        line(5,3,-4,3); line(5,3,5,1); arrow(-4,3,-1);
        if (g.media.repeat == 1) line(0,-1,0,1);
    } else {
        line(-6,-3,-3,-3); line(-3,-3,3,3); line(3,3,5,3); arrow(5,3,1);
        line(-6,3,-3,3); line(-3,3,-1,1); line(1,-1,3,-3); line(3,-3,5,-3); arrow(5,-3,1);
    }
}

// Reserve the lyrics row only while the selected track has usable synchronized lines.
static bool MediaHasLyrics() {
    return g.mediaLyrics && g.media.valid && !g_lyrics.empty() && g_lyrKey == g_lyrAsked;
}

static float MediaProgressY(bool lyrics) {
    return kMediaProgressY + (lyrics ? kMediaLyricExtraH : 0.0f);
}

static RGBA MediaLyricSurface(bool light) {
    return light ? C(247, 249, 254, 0.92f) : C(20, 26, 39, 0.90f);
}

static float MediaLyricLuminance(RGBA color) {
    auto linear = [](float channel) {
        return channel <= 0.04045f ? channel / 12.92f : powf((channel + 0.055f) / 1.055f, 2.4f);
    };
    return 0.2126f * linear(color.r) + 0.7152f * linear(color.g) + 0.0722f * linear(color.b);
}

static RGBA MediaLyricInk(RGBA accent, bool light) {
    const RGBA surface = MediaLyricSurface(light);
    const RGBA neutral = light ? C(0, 0, 0) : C(255, 255, 255);

    const float background = MediaLyricLuminance(LerpC(neutral, surface, surface.a));
    auto readable = [light, background](RGBA color) {
        const float text = MediaLyricLuminance(color);
        return (light ? (background + 0.05f) / (text + 0.05f) :
                        (text + 0.05f) / (background + 0.05f)) >= 5.0f;
    };
    accent.a = 1.0f;
    if (readable(accent)) return accent;
    float lo = 0.0f, hi = 1.0f;
    for (int i = 0; i < 9; ++i) {
        const float mid = (lo + hi) * 0.5f;
        if (readable(LerpC(accent, neutral, mid))) hi = mid;
        else lo = mid;
    }
    return LerpC(accent, neutral, hi);
}

// Render the active line in its own accent-tinted row.
static void DrawMediaLyric(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, RGBA accent, double position) {
    auto line = std::upper_bound(g_lyrics.begin(), g_lyrics.end(), position + 0.3,
        [](double time, const LyricLine& entry) { return time < entry.t; });
    if (line == g_lyrics.begin()) return;
    --line;
    if (line->s.empty()) return;

    const float left = M + kMediaInset * k, right = M + kMediaRight * k;
    const float center = M + kMediaLyricCenterY * k;
    const RGBA surface = MediaLyricSurface(g.pal.light);
    FillRRect(cv, (left + right) * 0.5f, center, (right - left) * 0.5f, kMediaLyricHalfH * k, 6.0f * k,
              [surface](float, float) -> RGBA { return surface; });
    const float pad = 8.0f * k;
    const auto text = Ellipsize(t, f.head, line->s, (int)(right - left - 2.0f * pad));
    DrawLabel(t, f.head, text, (left + right) * 0.5f, center - 8.0f * k, 1, MediaLyricInk(accent, g.pal.light));
}

// Render metadata, transport, progress, lyrics, and spectrum in shared card coordinates.
static void DrawMedia(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, bool cacheEq) {
    const MediaInfo mi = MediaCardInfo();
    float right = M + kMediaRight * k;
    RGBA white = g.pal.white, soft = g.pal.soft;
    RGBA ac = MediaAccent();
    const bool paused = mi.valid && mi.paused && !mi.title.empty();
    const Mp3CardStatus mp3Status = MediaIndicatorStatus();

    DrawCardHeader(cv, t, f, CARD_MEDIA, M, k, TR(L"MULTIMEDIA", L"MEDIA", L"MULTIM\u00C8DIA"));

    {
        const float cy = M + kMediaTransportY * k;
        const float pvx = M + kMediaTransportX[0] * k, plx = M + kMediaTransportX[1] * k,
                    nxx = M + kMediaTransportX[2] * k;
        const float q = 0.80f * k;

        const float buttonCenters[] = {pvx, plx, nxx};
        for (int i = 0; i < 3; ++i) {
            const bool active = MediaCanCommand(mi, i);
            const bool hot = active && g_mediaHover == i;
            const bool pressed = active && g_mediaPressed == i && GetTickCount64() < g_mediaPressedUntil;
            if (hot || pressed || i == 1)
                FillCircle(cv, buttonCenters[i], cy, kMediaTransportRadius[i] * k,
                           [hot, pressed, active](float, float) -> RGBA {
                               return HL(pressed ? 0.33f : hot ? 0.24f : active ? 0.16f : 0.06f);
                           });
        }
        auto transportInk = [&](int cmd) {
            RGBA ink = white;
            if (!MediaCanCommand(mi, cmd)) ink.a *= 0.28f;
            return ink;
        };
        const RGBA previousInk = transportInk(0), playInk = transportInk(1), nextInk = transportInk(2);

        FillRRect(cv, pvx - 5.5f * q, cy, 1.2f * q, 5.5f * q, 0.8f * q, [previousInk](float, float) -> RGBA { return previousInk; });
        std::vector<float> tp = {pvx + 6.0f * q, cy - 6.0f * q, pvx + 6.0f * q, cy + 6.0f * q, pvx - 3.5f * q, cy};
        FillPoly(cv, tp, [previousInk](float, float) -> RGBA { return previousInk; });

        FillRRect(cv, nxx + 5.5f * q, cy, 1.2f * q, 5.5f * q, 0.8f * q, [nextInk](float, float) -> RGBA { return nextInk; });
        std::vector<float> tn = {nxx - 6.0f * q, cy - 6.0f * q, nxx - 6.0f * q, cy + 6.0f * q, nxx + 3.5f * q, cy};
        FillPoly(cv, tn, [nextInk](float, float) -> RGBA { return nextInk; });

        if (mi.playing) {
            FillRRect(cv, plx - 3.6f * q, cy, 1.8f * q, 6.0f * q, 0.8f * q, [playInk](float, float) -> RGBA { return playInk; });
            FillRRect(cv, plx + 3.6f * q, cy, 1.8f * q, 6.0f * q, 0.8f * q, [playInk](float, float) -> RGBA { return playInk; });
        } else {
            std::vector<float> tpl = {plx - 3.0f * q, cy - 7.0f * q, plx - 3.0f * q, cy + 7.0f * q, plx + 7.0f * q, cy};
            FillPoly(cv, tpl, [playInk](float, float) -> RGBA { return playInk; });
        }

    }

    if (mi.canShuffle) DrawMediaMode(cv, M + kMediaShuffleX*k, M + kMediaHeaderY*k, k, false,
                                    mi.shuffle, g_mediaHover == kMediaShuffleHover);
    if (mi.canRepeat) DrawMediaMode(cv, M + kMediaRepeatX*k, M + kMediaHeaderY*k, k, true,
                                   mi.repeat != 0, g_mediaHover == kMediaRepeatHover);

    {
        const float x = M + kMediaInfoX * k, y = M + kMediaHeaderY * k;
        const bool complete = mp3Status == Mp3CardStatus::Saved || mp3Status == Mp3CardStatus::Complete;
        const bool waiting = mp3Status == Mp3CardStatus::Pending || mp3Status == Mp3CardStatus::Locked;
        const bool review = mp3Status == Mp3CardStatus::Review || mp3Status == Mp3CardStatus::Incomplete;
        const RGBA color = complete ? C(95, 228, 157) : waiting ? C(255, 202, 89) :
                           review ? C(255, 142, 191) : C(232, 64, 72);
        const bool hot = g_mediaHover == kMediaMetadataHover;
        FillCircle(cv, x, y, (hot ? 10.5f : 9.0f) * k, [color, hot](float, float) -> RGBA {
            RGBA glow = color;
            glow.a = hot ? 0.42f : 0.24f;
            return glow;
        });
        FillCircle(cv, x, y, 6.8f * k, [color](float, float) -> RGBA { return color; });
        auto ink = [mp3Status](float, float) -> RGBA {
            return mp3Status == Mp3CardStatus::None ? C(255, 255, 255) : C(33, 22, 37);
        };
        if (complete) {
            FillCapsule(cv, x - 2.9f*k, y, x - 0.6f*k, y + 2.2f*k, 0.8f*k, ink);
            FillCapsule(cv, x - 0.6f*k, y + 2.2f*k, x + 3.2f*k, y - 2.4f*k, 0.8f*k, ink);
        } else if (waiting) {
            FillCapsule(cv, x, y, x, y - 3.2f*k, 0.75f*k, ink);
            FillCapsule(cv, x, y, x + 2.6f*k, y, 0.75f*k, ink);
        } else if (review) {
            FillCapsule(cv, x, y - 3.0f*k, x, y, 0.85f*k, ink);
            FillCircle(cv, x, y + 2.6f*k, 0.9f*k, ink);
        } else {
            for (int i = -1; i <= 1; ++i) FillCircle(cv, x + i * 2.6f*k, y, 0.85f*k, ink);
        }
    }

    {
        const bool copied = GetTickCount64() < g.copiedUntil;
        std::wstring tag = copied ? std::wstring(TR(L"Copiado", L"Copied", L"Copiat")) : mi.player;
        if (!copied && mi.loading)
            tag = TR(L"Cargando…", L"Loading…", L"Carregant…");
        {
            const auto volume = MediaVolumeLabel();
            if (!volume.empty() && !copied) tag = volume;
            const float tagRight = mi.canShuffle ? kMediaShuffleX - kMediaModeRadius - 4.0f :
                mi.canRepeat ? kMediaRepeatX - kMediaModeRadius - 4.0f : kMediaInfoX - kMediaInfoRadius - 5.0f;
            int tagW = (int)((tagRight - 150.0f) * k);
            if (!tag.empty()) DrawLabel(t, f.small, Ellipsize(t, f.small, tag, tagW), M + tagRight * k, M + 13.0f * k, 2,
                      copied ? ac : g.pal.dimc);
        }
    }

    DrawThumb(cv, t, f, M + kMediaInset * k, M + kMediaCoverTop * k, kThumbU * k, k, ac);
    if (paused) {

        float tcx = M + (kMediaInset + kThumbU * 0.5f) * k, tcy = M + (kMediaCoverTop + kThumbU * 0.5f) * k;
        FillRRect(cv, tcx, tcy, kThumbU * k * 0.5f, kThumbU * k * 0.5f, 11.0f * k,
                  [](float, float) -> RGBA { return C(0, 0, 0, 0.42f); });
        FillRRect(cv, tcx - 5.0f * k, tcy, 2.6f * k, 8.5f * k, 1.0f * k,
                  [](float, float) -> RGBA { return C(255, 255, 255, 0.90f); });
        FillRRect(cv, tcx + 5.0f * k, tcy, 2.6f * k, 8.5f * k, 1.0f * k,
                  [](float, float) -> RGBA { return C(255, 255, 255, 0.90f); });
    }
    const float tx = M + kMediaTitleX * k;
    std::wstring title = mi.title.empty()
                             ? std::wstring(TR(L"Sin reproducci\u00F3n", L"Nothing playing", L"Sense reproducci\u00F3"))
                             : mi.title;
    const int maxW = (int)(right - tx);
    g_mediaMarqueeActive = g_mediaHoverTitle && !mi.title.empty() && MeasureWidth(t, f.name, title) > maxW;
    if (g_mediaMarqueeActive) {
        constexpr double hold = 0.65, speed = 36.0;
        const double distance = MeasureWidth(t, f.name, title) - maxW + 4.0 * k;
        const double travel = distance / (speed * k);
        const double time = (GetTickCount64() - g_mediaTitleHoverSince) * 0.001;
        const double phase = fmod(time, travel + hold * 2);
        const float offset = (float)(distance * std::clamp((phase - hold) / travel, 0.0, 1.0));
        t.clipL = tx;
        t.clipR = right;
        DrawLabel(t, f.name, title, tx - offset, M + (kMediaTitleTop + 2.0f) * k, 0, paused ? soft : white);
        t.clipL = t.clipR = -1.0f;
    } else {
        DrawLabel(t, f.name, Ellipsize(t, f.name, title, maxW), tx, M + (kMediaTitleTop + 2.0f) * k, 0, paused ? soft : white);
    }
    if (!mi.artist.empty())
        DrawLabel(t, f.small, Ellipsize(t, f.small, mi.artist, maxW), tx, M + 60.0f * k, 0, soft);

    {
        std::wstring extra = mi.year;
        if (!mi.album.empty()) {
            if (!extra.empty()) extra += L"  \u00B7  ";
            extra += mi.album;
        }
        if (!extra.empty())
            DrawLabel(t, f.small, Ellipsize(t, f.small, extra, maxW), tx, M + 78.0f * k, 0, g.pal.dimc);
    }

    if (GetTickCount64() < g_mediaVolumeUntil && g_mediaVolumeText >= 0) {
        const float vy = M + 91.0f * k, vh = 1.6f * k;
        FillRRect(cv, (tx + right) / 2.0f, vy, (right - tx) / 2.0f, vh, vh,
                  [](float, float) -> RGBA { return HL(0.14f); });
        const float vw = (right - tx) * Clamp01((float)g_mediaVolumeText / 100.0f);
        if (vw > vh) {
            const float hw = vw / 2.0f;
            FillRRect(cv, tx + hw, vy, hw, vh, vh, [ac](float, float) -> RGBA { return ac; });
        }
    }

    const bool lyrics = MediaHasLyrics();
    const float progressY = MediaProgressY(lyrics);
    const float px0 = M + kMediaInset * k, px1 = right, py = M + progressY * k;
    const bool preview = mi.valid && mi.canSeek && g_mediaHoverSeek >= 0.0f;
    if (mi.dur > 1.0) {
        const float halfHeight = (preview ? 2.6f : 1.8f) * k;
        FillRRect(cv, (px0 + px1) / 2.0f, py, (px1 - px0) / 2.0f, halfHeight, halfHeight,
                  [](float, float) -> RGBA { return HL(0.14f); });
        float w = (px1 - px0) * Clamp01((float)(mi.pos / mi.dur));
        if (w > halfHeight) {
            const float hw = std::max(w / 2.0f, halfHeight);
            const float fa = paused ? 0.55f : 0.95f;
            FillRRect(cv, px0 + hw, py, hw, halfHeight, halfHeight, [ac, fa](float, float) -> RGBA {
                RGBA c = ac;
                c.a = fa;
                return c;
            });
        }
        if (preview)
            FillCircle(cv, Lerp(px0, px1, g_mediaHoverSeek), py, 4.0f * k,
                       [ac](float, float) -> RGBA { return ac; });
    }
    if (g.mediaTime && (mi.dur > 1.0 || mi.pos >= 1.0)) {
        DrawLabel(t, f.small, MediaClock(mi.pos),
                  px0, M + (progressY + 7.0f) * k, 0, g.pal.white);
        if (mi.dur > 1.0) DrawLabel(t, f.small, MediaClock(mi.dur), px1, M + (progressY + 7.0f) * k, 2, g.pal.dimc);
    }
    if (lyrics) DrawMediaLyric(cv, t, f, M, k, ac, mi.pos);
    const float eqTop = M + kMediaEqTop * k, eqBase = M + kMediaEqBase * k;
    if (cacheEq) {
        const float pad = ceilf(4.0f * k) + 2.0f;
        SaveMediaEqUnderlay(cv, tx, right, eqTop, eqBase, pad);
    }
    DrawMediaEqualizer(cv, tx, right, eqTop, eqBase, k, ac);

    if (preview) {
        DrawMediaHint(cv, t, f, M, k, Lerp(px0, px1, g_mediaHoverSeek),
                      py - (18.0f + (lyrics ? kMediaLyricExtraH : 0.0f)) * k, MediaClock(MediaPreviewSeconds(g_mediaHoverSeek)));
    } else if (g_mediaHover == kMediaMetadataHover) {
        const bool readOnly = g.media.valid && HasAudioExt(LowerWs(g.media.path.empty() ? g.media.file : g.media.path)) &&
                              !CvIsMp3(g.media.path.empty() ? g.media.file : g.media.path);
        const auto label = readOnly ? TR(L"Metadatos de solo lectura", L"Read-only metadata", L"Metadades de només lectura") :
                                      MediaMp3Label(mp3Status);
        DrawMediaHint(cv, t, f, M, k, M + kMediaInfoX * k, M + 42.0f * k, label);
    } else if (g_mediaHover == kMediaShuffleHover || g_mediaHover == kMediaRepeatHover) {
        const bool repeat = g_mediaHover == kMediaRepeatHover;
        const wchar_t* hint = !repeat ? TR(L"Aleatorio", L"Shuffle", L"Aleatori") :
            mi.repeat == 1 ? TR(L"Repetir pista", L"Repeat track", L"Repeteix la pista") :
            mi.repeat == 2 ? TR(L"Repetir lista", L"Repeat list", L"Repeteix la llista") :
                             TR(L"Repetición desactivada", L"Repeat off", L"Repetició desactivada");
        DrawMediaHint(cv, t, f, M, k, M + (repeat ? kMediaRepeatX : kMediaShuffleX)*k, M + 42.0f*k, hint);
    } else if (g_mediaHover >= 0 && g_mediaHover < kMediaMetadataHover) {
        std::wstring hint = MediaTransportHint(g_mediaHover);
        if (!MediaCanCommand(mi, g_mediaHover))
            hint += TR(L" · No disponible", L" · Unavailable", L" · No disponible");
        DrawMediaHint(cv, t, f, M, k, M + kMediaTransportX[g_mediaHover] * k,
                      M + (kMediaTransportY - 24.0f) * k, hint);
    }
}

// Clock and Pomodoro timer

static bool PomoOn() { return g.pomoFocus > 0; }

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
static float AnalogFaceSize(float cardWu) {

    float s = cardWu - 200.0f;
    if (s > 100.0f) s = 100.0f;
    if (s < 68.0f) s = 68.0f;
    return s;
}

template <class CF>
static void DrawClockHand(Canvas& cv, float cx, float cy, float ang, float len, float w, CF col) {
    float nxp = -sinf(ang), nyp = cosf(ang);
    float ex = cx + sinf(ang) * len, ey = cy - cosf(ang) * len;
    float hw = w * 0.5f;
    std::vector<float> pts = {cx + nxp * hw, cy + nyp * hw, cx - nxp * hw, cy - nyp * hw,
                              ex - nxp * hw, ey - nyp * hw, ex + nxp * hw, ey + nyp * hw};
    FillPoly(cv, pts, col);
}

static void DrawAnalogFace(Canvas& cv, TextCtx& t, Fonts& f, float cx, float cy, float size, float k,
                           const SYSTEMTIME& st) {
    RGBA white = g.pal.white, soft = g.pal.soft;
    RGBA ac = CardAccent(C(255, 170, 90));
    RGBA rim = HL(0.16f);
    RGBA face = g.pal.light ? C(244, 246, 250, 0.95f) : C(29, 36, 52, 0.90f);

    float r = size * 0.5f;
    FillCircle(cv, cx, cy, r, [face](float, float) -> RGBA { return face; });

    for (float rr = r; rr > r - 1.6f * k; rr -= 0.4f * k) {
        float cur = rr;
        FillCircle(cv, cx, cy, cur, [rim](float, float) -> RGBA { return rim; });
    }
    FillCircle(cv, cx, cy, r - 1.8f * k, [face](float, float) -> RGBA { return face; });

    for (int i = 0; i < 12; i++) {
        float ang = (float)i * 3.14159265f / 6.0f;
        bool hour = (i % 3) == 0;
        float len = hour ? r * 0.16f : r * 0.10f;
        float w = hour ? 2.6f * k : 1.5f * k;
        float i0 = r - 4.0f * k, i1 = i0 - len;
        float nxp = -sinf(ang), nyp = cosf(ang);
        std::vector<float> pts = {cx + sinf(ang) * i0 + nxp * w * 0.5f,
                                  cy - cosf(ang) * i0 + nyp * w * 0.5f,
                                  cx + sinf(ang) * i0 - nxp * w * 0.5f,
                                  cy - cosf(ang) * i0 - nyp * w * 0.5f,
                                  cx + sinf(ang) * i1 - nxp * w * 0.5f,
                                  cy - cosf(ang) * i1 - nyp * w * 0.5f,
                                  cx + sinf(ang) * i1 + nxp * w * 0.5f,
                                  cy - cosf(ang) * i1 + nyp * w * 0.5f};
        RGBA mc = hour ? white : soft;
        FillPoly(cv, pts, [mc](float, float) -> RGBA { return mc; });
        if (hour && r > 48.0f) {
            wchar_t nb[4];
            wsprintfW(nb, L"%d", (i == 0) ? 12 : i);
            float na = ang;
            DrawLabel(t, f.small, nb, cx + sinf(na) * (r - 15.0f * k),
                      cy - cosf(na) * (r - 15.0f * k) - 7.0f * k, 1, soft);
        }
    }

    float hh = (float)(st.wHour % 12), mm = (float)st.wMinute, ss = (float)st.wSecond;
    float ah = (hh + mm / 60.0f) * 3.14159265f / 6.0f;
    float am = (mm + ss / 60.0f) * 3.14159265f / 30.0f;
    float as = ss * 3.14159265f / 30.0f;
    DrawClockHand(cv, cx, cy, ah, r * 0.50f, 4.4f * k, [white](float, float) -> RGBA { return white; });
    DrawClockHand(cv, cx, cy, am, r * 0.72f, 3.2f * k, [white](float, float) -> RGBA { return white; });
    DrawClockHand(cv, cx, cy, as, r * 0.84f, 1.2f * k, [ac](float, float) -> RGBA { return ac; });
    FillCircle(cv, cx, cy, 3.2f * k, [ac](float, float) -> RGBA { return ac; });
    FillCircle(cv, cx, cy, 1.4f * k, [face](float, float) -> RGBA { return face; });
}

static float ClockRowsStart() { return g.clockStyle ? 38.0f + AnalogFaceSize(kClockCardWu) + 14.0f : 38.0f; }
static float ClockRowsEndEx() { return ClockRowsStart() + 24.0f * (float)(1 + g.zones.size()); }
static float ClockPomoY() { return ClockRowsEndEx() + 12.0f; }
static float ClockCardH() {
    if (PomoOn()) return ClockPomoY() + 62.0f;
    return ClockRowsEndEx() + 10.0f;
}
static void DrawClock(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu) {
    float right = M + (cardWu - 18.0f) * k;
    RGBA white = g.pal.white, soft = g.pal.soft, dimc = g.pal.dimc;
    RGBA ac = CardAccent(C(255, 170, 90));

    DrawCardHeader(cv, t, f, CARD_CLOCK, M, k, TR(L"RELOJ", L"CLOCK", L"RELLOTGE"));

    SYSTEMTIME loc;
    GetLocalTime(&loc);
    long long locDay = DayNumber((int)loc.wYear, (int)loc.wMonth, (int)loc.wDay);

    if (g.clockStyle) {
        float fs = AnalogFaceSize(kClockCardWu);

        float faceCx = M + (kClockCardWu * 0.5f) * k;
        DrawAnalogFace(cv, t, f, faceCx, M + (38.0f + fs * 0.5f) * k, fs * k, k, loc);
    }

    float rowTop = g.clockStyle ? (38.0f + AnalogFaceSize(kClockCardWu) + 14.0f) : 38.0f;
    for (size_t i = 0; i < 1 + g.zones.size(); i++) {
        float ry = M + (rowTop + 24.0f * (float)i) * k;
        SYSTEMTIME zt = loc;

        std::wstring label;
        if (i == 0) {
            label = (g.weather.valid && !g.weather.place.empty()) ? g.weather.place : g.city;
            if (label.empty()) label = TR(L"Local", L"Local", L"Local");
        }
        int flag = g.localFlag;
        int diff = 0;
        if (i > 0) {
            const ZoneInfo& z = g.zones[i - 1];
            label = z.label;
            flag = z.flag;
            SYSTEMTIME utc;
            GetSystemTime(&utc);
            TIME_ZONE_INFORMATION tz = z.tzi;
            if (!z.ok || !SystemTimeToTzSpecificLocalTime(&tz, &utc, &zt)) continue;
            diff = (int)(DayNumber((int)zt.wYear, (int)zt.wMonth, (int)zt.wDay) - locDay);
        }
        wchar_t tb[16];
        wsprintfW(tb, L"%02d:%02d:%02d", (int)zt.wHour, (int)zt.wMinute, (int)zt.wSecond);

        int tw = DrawLabel(t, f.pill, tb, right, ry, 2, white);
        if (diff != 0) {
            std::wstring dd = (diff > 0 ? L"+" : L"") + std::to_wstring(diff) + L" d";
            DrawLabel(t, f.small, dd, right - (float)tw - 8.0f * k, ry + 2.0f * k, 2, dimc);
        }

        float lx = M + 18.0f * k;
        if (flag != FL_NONE) {
            DrawFlag(cv, flag, M + 30.0f * k, ry + 10.0f * k, k);
            lx = M + 48.0f * k;
        }
        if (!label.empty())
            DrawLabel(t, f.name, Ellipsize(t, f.name, label, (int)(right - (float)tw - (diff != 0 ? 44.0f : 14.0f) * k - lx)), lx, ry,
                      0, i == 0 ? soft : white);
    }

    if (!PomoOn()) return;

    float y0 = ClockPomoY();
    FillRRect(cv, (M + 18.0f * k + right) / 2.0f, M + (y0 - 3.0f) * k, (right - (M + 18.0f * k)) / 2.0f,
              0.5f * k, 0.5f * k, [](float, float) -> RGBA { return HL(0.10f); });

    std::wstring mode = g.pomoMode == 0
                            ? std::wstring(TR(L"POMODORO  \u00B7  TRABAJO", L"POMODORO  \u00B7  WORK",
                                              L"POMODORO  \u00B7  TREBALL"))
                            : std::wstring(TR(L"POMODORO  \u00B7  DESCANSO", L"POMODORO  \u00B7  BREAK",
                                              L"POMODORO  \u00B7  DESCANS"));
    if (g.pomoDone > 0) mode += L"  \u00B7  " + std::to_wstring(g.pomoDone) + L" \u2713";
    DrawLabel(t, f.small, mode, M + 18.0f * k, M + (y0 + 2.0f) * k, 0, dimc);

    wchar_t tb[16];
    wsprintfW(tb, L"%02d:%02d", g.pomoLeft / 60, g.pomoLeft % 60);
    DrawLabel(t, f.big, tb, M + 18.0f * k, M + (y0 + 16.0f) * k, 0, g.pomoRun ? white : soft);

    float cy = M + (y0 + 38.0f) * k;
    float plx = M + kPomoPlayX * k, rsx = M + kPomoResetX * k;
    FillCircle(cv, plx, cy, 16.0f * k, [](float, float) -> RGBA { return HL(0.16f); });
    FillCircle(cv, rsx, cy, 11.0f * k, [](float, float) -> RGBA { return HL(0.10f); });
    if (g.pomoRun) {
        FillRRect(cv, plx - 3.6f * k, cy, 1.8f * k, 6.0f * k, 0.8f * k,
                  [white](float, float) -> RGBA { return white; });
        FillRRect(cv, plx + 3.6f * k, cy, 1.8f * k, 6.0f * k, 0.8f * k,
                  [white](float, float) -> RGBA { return white; });
    } else {
        std::vector<float> tp = {plx - 3.0f * k, cy - 7.0f * k, plx - 3.0f * k, cy + 7.0f * k,
                                 plx + 7.0f * k, cy};
        FillPoly(cv, tp, [ac](float, float) -> RGBA { return ac; });
    }
    FillRRect(cv, rsx, cy, 3.6f * k, 3.6f * k, 1.0f * k, [white](float, float) -> RGBA { return white; });
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static void BuildBackground(Canvas& cv, float M, float cardW, float cardH, float k, RGBA ac, bool hover,
                            RGBA topC, RGBA botC, float minOpacity = 0.03f) {
    float cx = M + cardW / 2.0f;
    float cy = M + cardH / 2.0f;
    float hw = cardW / 2.0f;
    float hh = cardH / 2.0f;
    float rad = std::min((float)g.cornerRadius * k, std::min(hw, hh));
    float shA = g.pal.light ? 0.20f : 0.30f;

    Paint(cv, 0, 0, (float)cv.w, (float)cv.h, [&](float x, float y) -> RGBA {
        float dCard = SdRoundRect(x, y, cx, cy, hw, hh, rad);
        if (dCard < 0.0f) return kNone;
        float dSh = SdRoundRect(x, y, cx, cy + 5.0f * k, hw, hh, rad);
        float e = std::max(dSh, 0.0f) / (6.0f * k);
        if (e > 9.0f) return kNone;
        return C(0, 0, 0, shA * expf(-e));
    });

    float baseA = std::max(minOpacity, Clamp01((float)g.glassOpacity / 100.0f) * 0.72f + (hover ? 0.06f : 0.0f));
    Paint(cv, M - 1, M - 1, M + cardW + 1, M + cardH + 1, [&](float x, float y) -> RGBA {
        float cov = Coverage(SdRoundRect(x, y, cx, cy, hw, hh, rad));
        if (cov <= 0.0f) return kNone;
        float tt = Clamp01((y - M) / cardH);
        RGBA c = LerpC(topC, botC, tt);
        c.a = baseA * cov;
        return c;
    });

    float gx = M + 56.0f * k;
    float gy = M + 50.0f * k;
    float sig = 78.0f * k;
    float gi = ((float)g.accent / 255.0f) * 0.40f;
    Paint(cv, M - 1, M - 1, M + cardW + 1, M + cardH + 1, [&](float x, float y) -> RGBA {
        float cov = Coverage(SdRoundRect(x, y, cx, cy, hw, hh, rad));
        if (cov <= 0.0f) return kNone;
        float dx = x - gx, dy = y - gy;
        RGBA c = ac;
        c.a = gi * expf(-(dx * dx + dy * dy) / (2.0f * sig * sig)) * cov;
        return c;
    });

    Paint(cv, M - 1, M - 1, M + cardW + 1, M + cardH * 0.5f, [&](float x, float y) -> RGBA {
        float cov = Coverage(SdRoundRect(x, y, cx, cy, hw, hh, rad));
        float tt = (y - M) / cardH;
        if (cov <= 0.0f || tt > 0.5f) return kNone;
        return C(255, 255, 255, 0.09f * (1.0f - tt / 0.5f) * cov);
    });

    Paint(cv, M - 1, M + cardH * 0.6f, M + cardW + 1, M + cardH + 1, [&](float x, float y) -> RGBA {
        float cov = Coverage(SdRoundRect(x, y, cx, cy, hw, hh, rad));
        float tt = (y - M) / cardH;
        if (cov <= 0.0f || tt < 0.6f) return kNone;
        RGBA c = ac;
        c.a = gi * 0.22f * ((tt - 0.6f) / 0.4f) * cov;
        return c;
    });

    Paint(cv, M - 2, M - 2, M + cardW + 2, M + cardH + 2, [&](float x, float y) -> RGBA {
        float d = SdRoundRect(x, y, cx, cy, hw, hh, rad);
        float cov = Coverage(fabsf(d + 0.7f) - 0.7f);
        if (cov <= 0.0f) return kNone;
        float tt = Clamp01((y - M) / cardH);
        return C(255, 255, 255, (0.42f * (1.0f - tt) + 0.10f) * (hover ? 1.6f : 1.0f) * cov);
    });
}

static void WeatherTint(const Weather& wt, RGBA& top, RGBA& bot) {
    top = g.pal.topC;
    bot = g.pal.botC;
    if (!wt.valid) return;
    Kind kd = KindFromCode(wt.code);
    bool clear = (kd == K_CLEAR || kd == K_PARTLY);
    bool wet = (kd == K_RAIN || kd == K_DRIZZLE || kd == K_THUNDER);
    if (!g.pal.light) {
        if (!wt.isDay) {
            top = C(26, 30, 64);
            bot = C(8, 10, 26);
        } else if (clear) {
            top = C(38, 54, 92);
            bot = C(14, 20, 40);
        } else if (wet) {
            top = C(32, 40, 58);
            bot = C(12, 16, 26);
        }
    } else {
        if (!wt.isDay) {
            top = C(206, 212, 234);
            bot = C(182, 190, 216);
        } else if (clear) {
            top = C(226, 238, 255);
            bot = C(204, 222, 248);
        }
    }
}

static unsigned long long HashMix(unsigned long long h, long long v) {
    return (h * 1099511628211ULL) ^ (unsigned long long)v;
}

static void BuildStickyBackground(Canvas& cv, float M, float cardW, float cardH, float k) {
    float cx = M + cardW / 2.0f, cy = M + cardH / 2.0f;
    float hw = cardW / 2.0f, hh = cardH / 2.0f, rad = 3.0f * k;
    float x1 = M + cardW, y1 = M + cardH;
    float fold = 18.0f * k;

    Paint(cv, 0, 0, (float)cv.w, (float)cv.h, [&](float x, float y) -> RGBA {
        float dCard = SdRoundRect(x, y, cx, cy, hw, hh, rad);
        if (dCard < 0.0f) return kNone;
        float dSh = SdRoundRect(x, y, cx + 1.5f * k, cy + 6.0f * k, hw, hh, rad);
        float e = std::max(dSh, 0.0f) / (7.0f * k);
        if (e > 9.0f) return kNone;
        return C(0, 0, 0, 0.36f * expf(-e));
    });

    Paint(cv, M - 1, M - 1, x1 + 1, y1 + 1, [&](float x, float y) -> RGBA {
        float cov = Coverage(SdRoundRect(x, y, cx, cy, hw, hh, rad));
        if (cov <= 0.0f) return kNone;
        RGBA c = C(255, 236, 121);
        float band = Clamp01(1.0f - (y - M) / (40.0f * k));
        c = LerpC(c, C(246, 214, 80), band * 0.55f);
        float u = x - (x1 - fold), v = y - (y1 - fold);
        if (u > 0.0f && v > 0.0f) {
            float d = (u + v - fold) / 1.41421f;
            if (d > 0.0f) {
                cov *= Clamp01(0.5f - d);
            } else {
                float tf = Clamp01(-d / (fold * 0.7f));
                c = LerpC(C(222, 190, 60), C(252, 226, 108), tf);
            }
        }
        c.a = cov;
        return c;
    });
}

struct RenderDib {
    HDC dc = nullptr;
    HBITMAP bmp = nullptr;
    HGDIOBJ old = nullptr;
    DWORD* bits = nullptr;
    int w = 0;
    int h = 0;
};
static RenderDib g_dibText, g_dibOut, g_dibMedia;
static Canvas g_cvScratch;

static std::vector<DWORD> g_wxCache;
static int g_wxW = 0, g_wxH = 0;
static bool g_wxHov = false, g_wxOk = false;

static void FreeDib(RenderDib& d) {
    if (d.dc) {
        if (d.old) SelectObject(d.dc, d.old);
        DeleteDC(d.dc);
    }
    if (d.bmp) DeleteObject(d.bmp);
    d = RenderDib();
}

static void FreeRenderBuffers() {
    FreeDib(g_dibText);
    FreeDib(g_dibOut);
    FreeDib(g_dibMedia);
    g_mediaEqCached = false;
    g_mediaEqUnderlay = {};
    g_mediaEqPatch = {};
    g_cvScratch = Canvas();
    g_wxCache = std::vector<DWORD>();
    g_wxOk = false;
}

static bool EnsureDib(RenderDib& d, int W, int H, bool textMode) {
    if (d.bmp && d.w == W && d.h >= H) return true;
    int newH = std::max(H, d.h);
    FreeDib(d);
    BITMAPINFO bi;
    memset(&bi, 0, sizeof(bi));
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = W;
    bi.bmiHeader.biHeight = -newH;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    d.dc = CreateCompatibleDC(nullptr);
    if (d.dc) d.bmp = CreateDIBSection(d.dc, &bi, DIB_RGB_COLORS, (void**)&d.bits, nullptr, 0);
    if (!d.dc || !d.bmp || !d.bits) {
        FreeDib(d);
        return false;
    }
    d.old = SelectObject(d.dc, d.bmp);
    d.w = W;
    d.h = newH;
    if (textMode) {
        SetBkMode(d.dc, TRANSPARENT);
        SetTextColor(d.dc, RGB(255, 255, 255));
    }
    return true;
}

static std::wstring FoldedSummary(int id) {
    switch (id) {
        case CARD_WEATHER:
            if (WeatherNeedsRefresh() && g.lastOk) return WeatherRefreshLabel(true);
            if (g.weather.valid)
                return std::to_wstring((int)lround(g.weather.temp)) + (g.fahrenheit ? L" °F · " : L" °C · ") +
                       DescribeText(g.weather.code);
            break;
        case CARD_CLOCK: {
            if (g.pomoStarted && PomoOn())
                return L"Pomodoro · " + MediaClock(g.pomoLeft);
            SYSTEMTIME now = {};
            GetLocalTime(&now);
            wchar_t time[16];
            wsprintfW(time, L"%02d:%02d", (int)now.wHour, (int)now.wMinute);
            return time;
        }
        case CARD_SYSTEM: {
            std::wstring summary;
            if (g.systemFoldSummary.empty() || g.systemFoldSummary == L"cpuRam" || g.systemFoldSummary == L"cpu") {
                summary = g.hist.empty() ? TR(L"CPU sin datos", L"CPU unavailable", L"CPU sense dades") :
                    g.cpu >= 70.0 ? TR(L"CPU alta", L"CPU high", L"CPU alta") :
                    g.cpu >= 35.0 ? TR(L"CPU media", L"CPU moderate", L"CPU mitjana") :
                                    TR(L"CPU baja", L"CPU low", L"CPU baixa");
            }
            if (g.systemFoldSummary.empty() || g.systemFoldSummary == L"cpuRam" || g.systemFoldSummary == L"ram") {
                if (!summary.empty()) summary += L" · ";
                summary += L"RAM " + FormatNum(g.ramUsedGB, 1) + L" GB";
            }
            return summary;
        }
        case CARD_DEADLINES: {
            auto events = VisibleDeadlines();
            if (!events.empty()) {
                const Deadline& next = events.front();
                const auto countdown = DeadlineCountdown(next);
                if (!g.agendaFoldPrivate) return countdown + L" · " + next.name;
                return std::to_wstring(next.d) + L" " + MonthShort(next.m) + L" · " + countdown;
            }
            break;
        }
        case CARD_MEDIA:
            if (g.media.valid) {
                const auto volume = MediaVolumeLabel();
                if (!volume.empty()) return volume;
                if (g_mediaHover == 1) return MediaTransportHint(1);
                std::wstring summary = g.media.loading ? TR(L"Cargando", L"Loading", L"Carregant") :
                    g.media.paused ? TR(L"En pausa", L"Paused", L"En pausa") : L"";
                for (const auto* text : {&g.media.title, &g.media.artist}) {
                    if (text->empty()) continue;
                    if (!summary.empty()) summary += L" · ";
                    summary += *text;
                }
                return summary;
            }
            if (MediaMp3Status() == Mp3CardStatus::Pending) return TR(L"MP3 pendiente", L"MP3 queued", L"MP3 pendent");
            if (MediaMp3Status() == Mp3CardStatus::Review) return TR(L"Revisar MP3", L"Review MP3", L"Revisa l’MP3");
            break;
    }
    return {};
}

static bool RenderCard(Card& c, bool fastWeather = false) {
    if (!c.win || g.dragCard) return false;

    UINT dpiU = GetDpiForWindow(c.win);
    float dpi = dpiU ? (float)dpiU / 96.0f : 1.0f;
    float k = ((float)g.scale / 100.0f) * dpi;
    g.dpi = dpi;
    g.kLast = k;
    Fonts& fonts = EnsureFonts(k);

    std::vector<Deadline> vis;
    WLayout L;
    const float cardWu = kCardW;
    float cardHu = 0.0f;
    RGBA ac = C(90, 175, 255);
    RGBA topC = g.pal.topC, botC = g.pal.botC;
    if (c.id == CARD_WEATHER && g.hoverCard == &c) AlertMarkSeen();
    bool folded = (g.collapsed[c.id] || c.autoFold) && !c.animating;
    bool animRun = false;

    if (c.id == CARD_WEATHER) {
        const Weather& wt = g.weather;
        L = WeatherLayout(wt);
        cardHu = L.cardH;
        ac = wt.valid ? AccentFor(KindFromCode(wt.code), wt.isDay) : AccentFor(K_CLOUD, true);
        WeatherTint(wt, topC, botC);
    } else if (c.id == CARD_SYSTEM) {
        cardHu = SystemCardH();
        ac = CardAccent(C(90, 175, 255));
    } else if (c.id == CARD_DEADLINES) {
        vis = VisibleDeadlines();
        int gPrev = -99;
        for (size_t gi = 0; gi < vis.size(); gi++) {
            int gv = AgendaGroupOf(vis[gi].days);
            if (gv != gPrev) { gPrev = gv; }
        }
        float rowsH = vis.empty() ? 40.0f : 0.0f;
        int prevG = -99;
        for (size_t gi = 0; gi < vis.size(); gi++) {
            int gv = AgendaGroupOf(vis[gi].days);
            if (gv != prevG) { prevG = gv; rowsH += 20.0f; }
            rowsH += DeadlineRowH(vis[gi]);
        }
        cardHu = 38.0f + rowsH + 10.0f;
        ac = vis.empty() ? CardAccent(C(140, 170, 215)) : UrgencyColor(vis[0].days);
    } else if (c.id == CARD_NOTES) {
        cardHu = StickyCardHu(k);
        ac = C(255, 225, 90);
    } else if (c.id == CARD_MEDIA) {
        cardHu = g.mediaTime && (g.media.dur > 1.0 || g.media.pos >= 1.0) ? 182.0f : 166.0f;
        if (MediaHasLyrics()) cardHu += kMediaLyricExtraH;
        ac = MediaAccent();
    } else {
        cardHu = ClockCardH();
        ac = CardAccent(C(255, 170, 90));
    }

    c.fullHu = cardHu;
    if (c.animating) {

        float tt = Clamp01((float)(GetTickCount64() - c.animStart) / 200.0f);
        float e = 1.0f - (1.0f - tt) * (1.0f - tt) * (1.0f - tt);
        float from = c.animOpening ? 40.0f : cardHu;
        float to = c.animOpening ? cardHu : 40.0f;
        if (tt >= 1.0f) {
            c.animating = false;
            folded = (g.collapsed[c.id] || c.autoFold);
        } else {
            cardHu = from + (to - from) * e;
            animRun = true;
        }
    }
    if (folded) cardHu = 40.0f;

    float cardW = cardWu * k;
    float cardH = cardHu * k;
    float M = 20.0f * k;
    int W = (int)ceilf(cardW + 2.0f * M);
    int H = (int)ceilf(cardH + 2.0f * M);

    unsigned long long key = 14695981039346656037ULL;
    key = HashMix(key, W);
    key = HashMix(key, H);
    key = HashMix(key, c.id);
    key = HashMix(key, g.glassOpacity);
    key = HashMix(key, g.cornerRadius);
    key = HashMix(key, g.accent);
    key = HashMix(key, g.pal.light ? 1 : 0);
    key = HashMix(key, (long long)(ac.r * 255.0f));
    key = HashMix(key, (long long)(ac.g * 255.0f));
    key = HashMix(key, (long long)(ac.b * 255.0f));
    key = HashMix(key, (long long)(topC.r * 255.0f));
    key = HashMix(key, (long long)(topC.b * 255.0f));
    if (c.id == CARD_SYSTEM)
        key = HashMix(key, (g.showGpu ? 1 : 0) | (g.showDisk ? 2 : 0) | (g.procs.empty() ? 0 : 4) |
                               ((long long)BuildSysRows().size() << 4));
    auto buildBg = [&](bool hover, std::vector<DWORD>& out) {
        Canvas bgc;
        bgc.w = W;
        bgc.h = H;
        bgc.px.assign((size_t)W * (size_t)H, 0);
        if (c.id == CARD_NOTES) BuildStickyBackground(bgc, M, cardW, cardH, k);
        else BuildBackground(bgc, M, cardW, cardH, k, ac, hover, topC, botC);
        if (c.id == CARD_SYSTEM && !folded) DrawSystemStatic(bgc, M, k, cardWu);
        out.swap(bgc.px);
    };
    if (c.bgW != W || c.bgH != H || c.bgKey != key || c.bg.empty()) {
        buildBg(false, c.bg);
        c.bgHover.clear();
        c.bgW = W;
        c.bgH = H;
        c.bgKey = key;
    }
    const bool hov = (g.hoverCard == &c) && c.id != CARD_NOTES;
    if (hov && c.bgHover.empty()) buildBg(true, c.bgHover);

    Canvas& cv = g_cvScratch;
    cv.w = W;
    cv.h = H;
    const bool wxFast = fastWeather && c.id == CARD_WEATHER && !folded && !animRun && g.weather.valid &&
                        g.weather.alertColor > 0 && g_wxOk && g_wxW == W && g_wxH == H &&
                        g_wxHov == hov && g_wxCache.size() == (size_t)W * (size_t)H;
    if (wxFast) cv.px = g_wxCache;
    else cv.px = hov ? c.bgHover : c.bg;

    RenderDib& output = c.id == CARD_MEDIA ? g_dibMedia : g_dibOut;
    if (c.id == CARD_MEDIA) g_mediaEqCached = false;
    if (!EnsureDib(g_dibText, W, H, true) || !EnsureDib(output, W, H, false)) return false;
    HDC mdc = g_dibText.dc;
    DWORD* sbits = g_dibText.bits;
    memset(sbits, 0, (size_t)W * (size_t)H * 4);

    TextCtx t = {mdc, sbits, W, H, &cv};

    if (folded) {
        if (c.id == CARD_NOTES) {
            DrawStickyHeader(cv, t, fonts, M, k, cardWu, true);
        } else {
            DrawCardHeader(cv, t, fonts, c.id, M, k, CardTitle(c.id));
            const bool play = c.id == CARD_MEDIA && MediaCanCommand(g.media, 1);
            const float right = M + (play ? kMediaFoldedPlayX - 13.0f : cardWu - 34.0f) * k;
            const int width = (int)(right - M - 58.0f * k) - MeasureWidth(t, fonts.head, CardTitle(c.id));
            if (play) {
                const float x = M + kMediaFoldedPlayX * k, y = M + kMediaHeaderY * k;
                const bool pressed = g_mediaPressed == 1 && GetTickCount64() < g_mediaPressedUntil;
                FillCircle(cv, x, y, 9.0f * k, [pressed](float, float) -> RGBA { return HL(pressed ? 0.33f : 0.15f); });
                auto ink = [](float, float) -> RGBA { return g.pal.white; };
                if (g.media.playing) {
                    FillCapsule(cv, x - 2.0f*k, y - 3.0f*k, x - 2.0f*k, y + 3.0f*k, k, ink);
                    FillCapsule(cv, x + 2.0f*k, y - 3.0f*k, x + 2.0f*k, y + 3.0f*k, k, ink);
                } else {
                    FillPoly(cv, {x - 2.5f*k, y - 4.0f*k, x - 2.5f*k, y + 4.0f*k, x + 4.5f*k, y}, ink);
                }
            }
            if (width > 20)
                DrawLabel(t, fonts.small, Ellipsize(t, fonts.small, FoldedSummary(c.id), width),
                          right, M + 12.0f * k, 2, g.pal.white);
            DrawLabel(t, fonts.small, L"\u25B8", M + (cardWu - 18.0f) * k, M + 12.0f * k, 2, g.pal.white);
        }
    } else if (c.id == CARD_WEATHER) {
        if (wxFast) {
            DrawAlertMarquee(cv, t, fonts, M, k, cardWu, L);
        } else {
            DrawWeather(cv, t, fonts, M, k, cardWu, L);
            if (g.weather.valid && g.weather.alertColor > 0) {
                g_wxCache = cv.px;
                g_wxW = W;
                g_wxH = H;
                g_wxHov = hov;
                g_wxOk = true;
                DrawAlertMarquee(cv, t, fonts, M, k, cardWu, L);
            } else {
                g_wxOk = false;
            }
        }
    }
    else if (c.id == CARD_SYSTEM) DrawSystem(cv, t, fonts, M, k, cardWu);
    else if (c.id == CARD_DEADLINES) DrawDeadlines(cv, t, fonts, M, k, cardWu);
    else if (c.id == CARD_NOTES) DrawSticky(cv, t, fonts, M, k, cardWu, g.stickyEditing);
    else if (c.id == CARD_MEDIA) DrawMedia(cv, t, fonts, M, k,
                                            !animRun && g_mediaHover < 0 && g_mediaHoverSeek < 0 &&
                                            !g_mediaCoverFadeUntil);
    else DrawClock(cv, t, fonts, M, k, cardWu);

    if (animRun) {

        const std::vector<DWORD>& bgSrc = hov ? c.bgHover : c.bg;
        if (bgSrc.size() == cv.px.size()) {
            int yStart = std::max(0, (int)floorf(M + cardH) - 1);
            for (int yy = yStart; yy < H; yy++)
                memcpy(&cv.px[(size_t)yy * (size_t)W], &bgSrc[(size_t)yy * (size_t)W], (size_t)W * 4);
        }
    }

    memcpy(output.bits, cv.px.data(), (size_t)W * (size_t)H * 4);

    if (!c.placed || W != c.winW || H != c.winH) {
        SetWindowPos(c.win, HWND_BOTTOM, 0, 0, W, H, SWP_NOMOVE | SWP_NOACTIVATE);
        c.winW = W;
        c.winH = H;
        c.placed = true;
        g.needStack = true;
    }
    c.mPx = (int)M;
    c.cardHpx = (int)ceilf(cardH);

    POINT src = {0, 0};
    SIZE sz = {W, H};
    BLENDFUNCTION bf;
    memset(&bf, 0, sizeof(bf));
    bf.BlendOp = AC_SRC_OVER;
    bf.SourceConstantAlpha = 255;
    bf.AlphaFormat = AC_SRC_ALPHA;
    if (!UpdateLayeredWindow(c.win, nullptr, nullptr, &sz, output.dc, &src, 0, &bf, ULW_ALPHA)) {
        Wh_Log(L"UpdateLayeredWindow failed: %lu", GetLastError());
    }
    return true;
}

static bool RenderMediaEqualizer(Card& c) {
    if (!g_mediaEqCached || c.dirty || c.animating || !g_dibMedia.bits ||
        g_dibMedia.w != c.winW || g_dibMedia.h < c.winH) return false;
    const UINT dpi = GetDpiForWindow(c.win);
    const float k = ((float)g.scale / 100.0f) * (dpi ? (float)dpi / 96.0f : 1.0f);
    const float m = 20.0f * k;
    const RECT& r = g_mediaEqRect;
    g_mediaEqPatch = g_mediaEqUnderlay;
    DrawMediaEqualizer(g_mediaEqPatch, m + kMediaTitleX * k - r.left,
                       m + kMediaRight * k - r.left, m + kMediaEqTop * k - r.top,
                       m + kMediaEqBase * k - r.top, k, MediaAccent());
    const size_t width = (size_t)g_mediaEqPatch.w;
    for (int y = 0; y < g_mediaEqPatch.h; ++y)
        memcpy(g_dibMedia.bits + (r.top + y) * (size_t)c.winW + r.left,
               g_mediaEqPatch.px.data() + y * width, width * sizeof(DWORD));

    const POINT src = {};
    const SIZE sz = {c.winW, c.winH};
    const BLENDFUNCTION blend = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
    UPDATELAYEREDWINDOWINFO info = {};
    info.cbSize = sizeof(info);
    info.psize = &sz;
    info.hdcSrc = g_dibMedia.dc;
    info.pptSrc = &src;
    info.pblend = &blend;
    info.dwFlags = ULW_ALPHA;
    info.prcDirty = &r;
    return UpdateLayeredWindowIndirect(c.win, &info) != FALSE;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static Card* FirstPlaced() {
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[g_cardOrder[i]];
        if (c.win && c.placed) return &c;
    }
    return nullptr;
}

static void StartFoldAnim(Card* c, bool opening);

static void ComputeAutoFold() {
    if (g.dragCard) return;
    Card* first = FirstPlaced();
    if (!first) return;
    bool want[CARD_COUNT] = {};
    if (g.autoFoldOn) {
        const float k = g.kLast;
        POINT p = {g.anchorX + (first->winW - 2 * first->mPx) / 2, g.anchorY};
        MONITORINFO mi;
        memset(&mi, 0, sizeof(mi));
        mi.cbSize = sizeof(mi);
        if (!GetMonitorInfoW(MonitorFromPoint(p, MONITOR_DEFAULTTONEAREST), &mi)) return;
        const int avail = (int)(mi.rcWork.bottom - mi.rcWork.top) - (int)((float)g.marginTop * g.dpi) -
                          (int)(8.0f * g.dpi);
        const int gap = (int)((float)g.stackGap * k);
        const int foldedPx = (int)ceilf(40.0f * k);
        int hs[CARD_COUNT] = {};
        int total = 0, n = 0;
        for (int i = 0; i < CARD_COUNT; i++) {
            Card& c = g.cards[i];
            if (!c.win || !c.placed) continue;
            if (c.fullHu <= 0.0f) return;
            hs[i] = g.collapsed[i] ? foldedPx : (int)ceilf(c.fullHu * k);
            total += hs[i];
            n++;
        }
        if (n > 1) total += gap * (n - 1);
        for (size_t j = 0; j < g.autoFoldOrder.size() && total > avail; j++) {
            const int id = g.autoFoldOrder[j];
            Card& c = g.cards[id];
            if (!c.win || !c.placed || g.collapsed[id] || g.autoPin[id]) continue;
            if (id == CARD_NOTES && g.stickyEditing) continue;
            if (hs[id] <= foldedPx) continue;
            total -= hs[id] - foldedPx;
            want[id] = true;
        }
    }
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[i];
        if (want[i] == c.autoFold) continue;
        c.autoFold = want[i];
        c.dirty = true;
        c.bgKey = 0;
        if (i != CARD_NOTES && c.win && !g.collapsed[i]) StartFoldAnim(&c, !c.autoFold);
    }
}

static void Restack() {
    Card* first = FirstPlaced();
    if (!first) return;
    ComputeAutoFold();

    if (!g.anchorValid) {
        int cardWpx = first->winW - 2 * first->mPx;
        int ax, ay;
        if (Wh_GetIntValue(L"posSet", 0)) {
            ax = Wh_GetIntValue(L"posX", 0);
            ay = Wh_GetIntValue(L"posY", 0);
            int vl = GetSystemMetrics(SM_XVIRTUALSCREEN);
            int vt = GetSystemMetrics(SM_YVIRTUALSCREEN);
            int vr = vl + GetSystemMetrics(SM_CXVIRTUALSCREEN);
            int vb = vt + GetSystemMetrics(SM_CYVIRTUALSCREEN);
            if (ax < vl - cardWpx + 80) ax = vl - cardWpx + 80;
            if (ax > vr - 80) ax = vr - 80;
            if (ay < vt) ay = vt;
            if (ay > vb - 80) ay = vb - 80;
        } else {
            RECT wa = WorkAreaForSetting();
            ax = wa.right - (int)((float)g.marginRight * g.dpi) - cardWpx;
            ay = wa.top + (int)((float)g.marginTop * g.dpi);
        }
        g.anchorX = ax;
        g.anchorY = ay;
        g.anchorValid = true;
    }

    int gap = (int)((float)g.stackGap * g.kLast);
    int y = g.anchorY;
    int placedN = 0;
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[g_cardOrder[i]];
        if (c.win && c.placed) placedN++;
    }

    HDWP dwp = placedN ? BeginDeferWindowPos(placedN) : nullptr;
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[g_cardOrder[i]];
        if (!c.win || !c.placed) continue;
        const UINT fl = SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW;
        if (dwp) {
            dwp = DeferWindowPos(dwp, c.win, HWND_BOTTOM, g.anchorX - c.mPx, y - c.mPx, 0, 0, fl);
            if (!dwp) SetWindowPos(c.win, HWND_BOTTOM, g.anchorX - c.mPx, y - c.mPx, 0, 0, fl);
        } else {
            SetWindowPos(c.win, HWND_BOTTOM, g.anchorX - c.mPx, y - c.mPx, 0, 0, fl);
        }
        y += c.cardHpx + gap;
    }
    if (dwp) EndDeferWindowPos(dwp);
    g.stackH = std::max(0, y - gap - g.anchorY);
}

static void SnapAnchor() {
    if (!g.snap) return;
    Card* first = FirstPlaced();
    if (!first) return;
    int cardW = first->winW - 2 * first->mPx;
    POINT p = {g.anchorX + cardW / 2, g.anchorY};
    HMONITOR mon = MonitorFromPoint(p, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi;
    memset(&mi, 0, sizeof(mi));
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfoW(mon, &mi)) return;
    RECT wa = mi.rcWork;
    int th = (int)(24.0f * g.dpi);
    if (abs(g.anchorX - wa.left) < th) g.anchorX = wa.left;
    else if (abs(g.anchorX + cardW - wa.right) < th) g.anchorX = wa.right - cardW;
    if (abs(g.anchorY - wa.top) < th) g.anchorY = wa.top;
    else if (abs(g.anchorY + g.stackH - wa.bottom) < th) g.anchorY = wa.bottom - g.stackH;
}

static void SavePosition() {
    Wh_SetIntValue(L"posX", g.anchorX);
    Wh_SetIntValue(L"posY", g.anchorY);
    Wh_SetIntValue(L"posSet", 1);
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static std::wstring GetStr(const wchar_t* name) {
    PCWSTR p = Wh_GetStringSetting(name);
    std::wstring s = p ? p : L"";
    if (p) Wh_FreeStringSetting(p);
    return s;
}

static std::wstring GetStrIdx(const wchar_t* name, int i) {
    PCWSTR p = Wh_GetStringSetting(L"%s[%d]", name, i);
    std::wstring s = p ? p : L"";
    if (p) Wh_FreeStringSetting(p);
    return s;
}

static std::wstring GetStoredStr(const wchar_t* name) {
    std::vector<wchar_t> buf(16384, 0);
    Wh_GetStringValue(name, buf.data(), buf.size());
    return std::wstring(buf.data());
}

static std::vector<std::wstring> SplitLines(const std::wstring& s) {
    std::vector<std::wstring> out;
    std::wstring cur;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == L'\n') {
            out.push_back(cur);
            cur.clear();
        } else if (s[i] != L'\r') {
            cur += s[i];
        }
    }
    out.push_back(cur);
    return out;
}

#pragma pack(push, 1)
struct RegTzi {
    LONG bias;
    LONG stdBias;
    LONG dltBias;
    SYSTEMTIME stdDate;
    SYSTEMTIME dltDate;
};
#pragma pack(pop)

static bool LoadTzi(const std::wstring& name, TIME_ZONE_INFORMATION& tz) {
    std::wstring key = L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones\\" + name;
    RegTzi r;
    DWORD sz = sizeof(r);
    if (RegGetValueW(HKEY_LOCAL_MACHINE, key.c_str(), L"TZI", RRF_RT_REG_BINARY, nullptr, &r, &sz) !=
            ERROR_SUCCESS ||
        sz < sizeof(r))
        return false;
    memset(&tz, 0, sizeof(tz));
    tz.Bias = r.bias;
    tz.StandardBias = r.stdBias;
    tz.DaylightBias = r.dltBias;
    tz.StandardDate = r.stdDate;
    tz.DaylightDate = r.dltDate;
    return true;
}

// Load the saved Calendar and Notes edits or fall back to Settings.
static void LoadLists() {

    g.notified.clear();
    {
        std::wstring stored = GetStoredStr(L"notified");
        std::wstring cur;
        for (size_t i = 0; i <= stored.size(); i++) {
            if (i == stored.size() || stored[i] == L'\n') {
                if (!cur.empty()) g.notified.push_back((unsigned int)wcstoul(cur.c_str(), nullptr, 16));
                cur.clear();
            } else if (stored[i] != L'\r') {
                cur += stored[i];
            }
        }
    }

    // deadlines
    g.dlRaw.clear();
    if (Wh_GetIntValue(L"dlOvr", 0)) {
        g.dlRaw = SplitLines(GetStoredStr(L"dlText"));
    } else {
        for (int i = 0; i < 40; i++) {
            std::wstring line = GetStrIdx(L"deadlines", i);
            if (!Trim(line).empty()) g.dlRaw.push_back(line);
        }
    }
    g.deadlines.clear();
    for (size_t i = 0; i < g.dlRaw.size(); i++) {
        std::wstring line = Trim(g.dlRaw[i]);
        if (line.empty() || line[0] == L'#') continue;
        Deadline d;
        if (ParseDeadline(line, d)) g.deadlines.push_back(d);
        else Wh_Log(L"Could not read deadline line: %s", line.c_str());
    }

    g.stickyUndo = GetStoredStr(L"stickyUndo");
    g.stickyCanUndo = !g.stickyUndo.empty();

    if (Wh_GetIntValue(L"stickyInit", 0)) {
        g.stickyText = GetStoredStr(L"stickyText");
    } else {
        std::wstring seed;
        for (int i = 0; i < 60; i++) {
            Note nt;
            if (!ParseNote(GetStrIdx(L"notes", i), nt)) continue;
            std::wstring line = nt.text;
            if (nt.kind == 1) line = L"- " + line;
            else if (nt.kind == 2) line = L"- " + line + L" (" + std::wstring(TR(L"hecho", L"done", L"fet")) + L")";
            else if (nt.kind == 3) line = L"! " + line;
            if (!seed.empty()) seed += L"\n";
            seed += line;
        }
        g.stickyText = seed;
        Wh_SetStringValue(L"stickyText", seed.c_str());
        Wh_SetIntValue(L"stickyInit", 1);
    }
}

// Global hotkeys
static bool ParseHotkey(const std::wstring& in, UINT& mods, UINT& vk) {
    mods = 0;
    vk = 0;
    std::vector<std::wstring> parts;
    std::wstring tok;
    for (size_t i = 0; i <= in.size(); i++) {
        if (i == in.size() || in[i] == L'+') {
            parts.push_back(LowerWs(Trim(tok)));
            tok.clear();
        } else {
            tok += in[i];
        }
    }
    for (size_t i = 0; i < parts.size(); i++) {
        const std::wstring& q = parts[i];
        if (q.empty()) continue;
        if (q == L"ctrl" || q == L"control" || q == L"ctl") mods |= MOD_CONTROL;
        else if (q == L"alt") mods |= MOD_ALT;
        else if (q == L"shift" || q == L"mayus") mods |= MOD_SHIFT;
        else if (q == L"win" || q == L"windows") mods |= MOD_WIN;
        else if (q.size() == 1 && iswalnum(q[0])) vk = (UINT)towupper(q[0]);
        else if (q.size() >= 2 && q[0] == L'f' && iswdigit(q[1])) {
            int n = _wtoi(q.c_str() + 1);
            if (n >= 1 && n <= 24) vk = (UINT)(VK_F1 + n - 1);
            else return false;
        }
        else if (q == L"space" || q == L"espacio") vk = VK_SPACE;
        else if (q == L"tab") vk = VK_TAB;
        else if (q == L"enter" || q == L"intro") vk = VK_RETURN;
        else if (q == L"esc" || q == L"escape") vk = VK_ESCAPE;
        else if (q == L"home" || q == L"inicio") vk = VK_HOME;
        else if (q == L"end" || q == L"fin") vk = VK_END;
        else if (q == L"insert" || q == L"insertar") vk = VK_INSERT;
        else if (q == L"delete" || q == L"supr") vk = VK_DELETE;
        else if (q == L"pageup" || q == L"repag") vk = VK_PRIOR;
        else if (q == L"pagedown" || q == L"avpag") vk = VK_NEXT;
        else if (q == L"left") vk = VK_LEFT;
        else if (q == L"right") vk = VK_RIGHT;
        else if (q == L"up") vk = VK_UP;
        else if (q == L"down") vk = VK_DOWN;
        else return false;
    }
    return vk != 0 && mods != 0;
}

static bool g_hotkeyOn = false;

static bool g_mediaKeyOn[3] = {false, false, false};

static void ApplyMediaHotkeys() {
    if (!g.msgWin) return;
    for (int i = 0; i < 3; ++i) {
        if (g_mediaKeyOn[i]) { UnregisterHotKey(g.msgWin, 2 + i); g_mediaKeyOn[i] = false; }
        if (g.mediaKeys[i].empty()) continue;
        UINT mods = 0, vk = 0;
        if (!ParseHotkey(g.mediaKeys[i], mods, vk)) {
            Wh_Log(L"Invalid media shortcut: '%s'", g.mediaKeys[i].c_str());
            continue;
        }
        if (RegisterHotKey(g.msgWin, 2 + i, mods | MOD_NOREPEAT, vk)) g_mediaKeyOn[i] = true;
        else Wh_Log(L"Could not register media shortcut '%s' (error %lu)", g.mediaKeys[i].c_str(), GetLastError());
    }
}

static void ApplyHotkey() {
    if (!g.msgWin) return;
    ApplyMediaHotkeys();
    if (g_hotkeyOn) {
        UnregisterHotKey(g.msgWin, 1);
        g_hotkeyOn = false;
    }
    if (g.foldHotkey.empty()) return;
    UINT mods = 0, vk = 0;
    if (!ParseHotkey(g.foldHotkey, mods, vk)) {
        Wh_Log(L"Invalid shortcut: '%s'", g.foldHotkey.c_str());
        return;
    }
    if (RegisterHotKey(g.msgWin, 1, mods | MOD_NOREPEAT, vk)) g_hotkeyOn = true;
    else Wh_Log(L"Could not register shortcut '%s' (error %lu): another application might already be using it",
                g.foldHotkey.c_str(), GetLastError());
}

static void LoadSettings() {
    g.settingsVersion++;
    g.dueDisks = g.dueCpu = g.dueGpu = g.dueBat = g.dueWifi = g.dueProcs = 0;

    std::wstring lang = GetStr(L"language");
    g.lang = (lang == L"es") ? 0 : (lang == L"ca" ? 2 : 1);
    std::wstring theme = GetStr(L"theme");
    g.theme = (theme == L"dark") ? 1 : (theme == L"light" ? 2 : 0);
    g.useWinAccent = Wh_GetIntSetting(L"useWindowsAccent") != 0;
    g.modernFont = Wh_GetIntSetting(L"modernFont") != 0;
    g.autoFoldOn = Wh_GetIntSetting(L"autoFold") != 0;
    g.foldHotkey = Trim(GetStr(L"foldHotkey"));
    g.alertDot = Wh_GetIntSetting(L"alertDot") != 0;
    g.mediaTime = Wh_GetIntSetting(L"mediaTime") != 0;
    g.coverAccent = Wh_GetIntSetting(L"coverAccent") != 0;
    g.fpOn = Wh_GetIntSetting(L"fingerprint") != 0;
    wcsncpy(g_acoustKeyCfg, Trim(GetStr(L"acoustidKey")).c_str(), 95);
    g_acoustKeyCfg[95] = 0;
    {
        auto napsterKey = Trim(GetStr(L"napsterApiKey"));
        SrwGuard guard(&g_napsterKeyLock);
        g_napsterApiKey = std::move(napsterKey);
    }
    g.alertSeen = (unsigned int)Wh_GetIntValue(L"alertSeen", 0);
    {
        g.autoFoldOrder.clear();
        std::wstring list = GetStr(L"autoFoldOrder"), tok;
        for (size_t i = 0; i <= list.size(); i++) {
            if (i < list.size() && list[i] != L',' && list[i] != L';') {
                tok += list[i];
                continue;
            }
            std::wstring q = LowerWs(Trim(tok));
            tok.clear();
            if (q.empty()) continue;
            int id = -1;
            if (q == L"tiempo" || q == L"weather") id = CARD_WEATHER;
            else if (q == L"reloj" || q == L"clock") id = CARD_CLOCK;
            else if (q == L"sistema" || q == L"system") id = CARD_SYSTEM;
            else if (q == L"agenda" || q == L"deadlines") id = CARD_DEADLINES;
            else if (q == L"notas" || q == L"notes") id = CARD_NOTES;
            else if (q == L"multimedia" || q == L"media") id = CARD_MEDIA;
            if (id < 0) {
                Wh_Log(L"Orden del plegado automatico: '%s' no es una tarjeta", q.c_str());
                continue;
            }
            bool dup = false;
            for (size_t j = 0; j < g.autoFoldOrder.size(); j++)
                if (g.autoFoldOrder[j] == id) dup = true;
            if (!dup) g.autoFoldOrder.push_back(id);
        }
    }
    g.scale = ClampInt(Wh_GetIntSetting(L"scale"), 60, 200);
    g.glassOpacity = ClampInt(Wh_GetIntSetting(L"glassOpacity"), 0, 100);
    g.cornerRadius = ClampInt(Wh_GetIntSetting(L"cornerRadius"), 0, 60);
    g.accent = ClampInt(Wh_GetIntSetting(L"accent"), 0, 255);
    g.lockPosition = Wh_GetIntValue(L"lockSet", 0) ? (Wh_GetIntValue(L"lockVal", 0) != 0)
                                                   : (Wh_GetIntSetting(L"lockPosition") != 0);
    g.monitor = ClampInt(Wh_GetIntSetting(L"monitor"), 0, 16);
    g.snap = Wh_GetIntSetting(L"snapToEdges") != 0;
    g.pauseFs = Wh_GetIntSetting(L"pauseFullscreen") != 0;
    g.marginRight = ClampInt(Wh_GetIntSetting(L"marginRight"), 0, 6000);
    g.marginTop = ClampInt(Wh_GetIntSetting(L"marginTop"), 0, 6000);
    g.stackGap = ClampInt(Wh_GetIntSetting(L"stackGap"), 0, 200);
    g.calendarUrl = Trim(GetStr(L"calendarUrl"));
    const auto icsSources = Trim(GetStr(L"icsUrl"));
    if (g.icsUrl != icsSources) {
        g.icsBySource.clear();
        g.ics.clear();
        g.icsMissingSources = 0;
        g.icsFailed = false;
    }
    g.icsUrl = icsSources;
    g.icsLabel = Trim(GetStr(L"icsLabel"));
    g.icsNext = 0;

    g.showWeather = Wh_GetIntSetting(L"showWeather") != 0;
    g.showSystem = Wh_GetIntSetting(L"showSystem") != 0;
    g.showMedia = Wh_GetIntSetting(L"showMedia") != 0;
    g.mediaAutoHide = Wh_GetIntSetting(L"mediaAutoHide") != 0;
    g_mediaKeepStopped = Wh_GetIntSetting(L"mediaKeepStopped") != 0;
    g.mediaLyrics = Wh_GetIntSetting(L"mediaLyrics") != 0;
    g.mediaKeys[0] = Trim(GetStr(L"mediaHotkeyPrev"));
    g.mediaKeys[1] = Trim(GetStr(L"mediaHotkeyPlay"));
    g.mediaKeys[2] = Trim(GetStr(L"mediaHotkeyNext"));
    g.showClock = Wh_GetIntSetting(L"showClock") != 0;
    g.showDeadlines = Wh_GetIntSetting(L"showDeadlines") != 0;
    g.showNotes = Wh_GetIntSetting(L"showNotes") != 0;

    g.city = Trim(GetStr(L"city"));
    g.lat = CleanCoordinate(GetStr(L"latitude"));
    g.lon = CleanCoordinate(GetStr(L"longitude"));
    g.fahrenheit = (GetStr(L"units") == L"fahrenheit");
    g.showDetails = Wh_GetIntSetting(L"showDetails") != 0;
    g.showSunAir = Wh_GetIntSetting(L"showSunAir") != 0;
    g.showHourly = Wh_GetIntSetting(L"showHourly") != 0;
    g.showForecast = Wh_GetIntSetting(L"showForecast") != 0;
    g.refreshMinutes = ClampInt(Wh_GetIntSetting(L"refreshMinutes"), 5, 180);

    g.showGpu = Wh_GetIntSetting(L"showGpu") != 0;
    g.showDisk = Wh_GetIntSetting(L"showDisk") != 0;
    g.showBattery = Wh_GetIntSetting(L"showBattery") != 0;
    g.showWifi = Wh_GetIntSetting(L"showWifi") != 0;
    g.onlineCovers = Wh_GetIntSetting(L"onlineCovers") != 0;
    ApplyEqPalette(GetStr(L"eqPalette"), GetStr(L"eqColorLow"), GetStr(L"eqColorMid"), GetStr(L"eqColorHigh"));
    g.musicDirs.clear();
    for (int i = 0; i < 5; i++) {
        std::wstring p = Trim(GetStrIdx(L"musicFolders", i));
        if (p.empty()) continue;
        wchar_t eb[2 * MAX_PATH];
        DWORD en = ExpandEnvironmentStringsW(p.c_str(), eb, 2 * MAX_PATH);
        if (en > 0 && en <= 2 * MAX_PATH) p = eb;
        while (p.size() > 3 && (p.back() == L'\\' || p.back() == L'/')) p.pop_back();
        g.musicDirs.push_back(p);
    }
    g.maxDisks = ClampInt(Wh_GetIntSetting(L"maxDisks"), 0, 4);
    g.topProcs = ClampInt(Wh_GetIntSetting(L"processCount"), 0, 5);
    g.procByRam = (GetStr(L"topProcsSort") == L"ram");
    g.sysRefresh = ClampInt(Wh_GetIntSetting(L"systemRefreshSec"), 1, 10);

    g.maxDeadlines = ClampInt(Wh_GetIntSetting(L"maxDeadlines"), 1, 8);
    g.notifyMin = ClampInt(Wh_GetIntSetting(L"notifyMinutes"), 0, 1440);
    g.stickyLines = ClampInt(Wh_GetIntSetting(L"stickyLines"), 3, 16);

    LoadLists();

    g.zones.clear();
    for (int i = 0; i < 3; i++) {
        std::wstring line = Trim(GetStrIdx(L"clocks", i));
        size_t bar = line.find(L'|');
        if (line.empty() || bar == std::wstring::npos) continue;
        ZoneInfo z;
        z.label = Trim(line.substr(0, bar));
        std::wstring rest = line.substr(bar + 1);
        std::wstring zn, fl;
        size_t bar2 = rest.find(L'|');
        if (bar2 == std::wstring::npos) {
            zn = Trim(rest);
        } else {
            zn = Trim(rest.substr(0, bar2));
            fl = Trim(rest.substr(bar2 + 1));
        }
        memset(&z.tzi, 0, sizeof(z.tzi));
        z.ok = LoadTzi(zn, z.tzi);
        if (!z.ok) Wh_Log(L"Unknown time zone: %s", zn.c_str());
        z.flag = fl.empty() ? GuessFlag(z.label, zn) : FlagFromCode(fl);
        g.zones.push_back(z);
    }
    g.localFlag = FlagFromCode(GetStr(L"localFlag"));
    g.clockStyle = (GetStr(L"clockStyle") == L"analogico") ? 1 : 0;

    g.stickyCompact = Wh_GetIntSetting(L"stickyCompact") != 0;
    g.agendaFoldPrivate = Wh_GetIntSetting(L"agendaFoldPrivate") != 0;
    g.systemFoldSummary = GetStr(L"systemFoldSummary");
    g.pomoFocus = ClampInt(Wh_GetIntSetting(L"pomoFocus"), 0, 180);
    g.pomoBreak = ClampInt(Wh_GetIntSetting(L"pomoBreak"), 1, 60);
    if (!g.pomoRun && !g.pomoStarted) g.pomoLeft = (g.pomoMode ? g.pomoBreak : g.pomoFocus) * 60;

    for (int i = 0; i < CARD_COUNT; i++) {
        wchar_t key[32];
        wsprintfW(key, L"collapsed%d", i);
        g.collapsed[i] = Wh_GetIntValue(key, 0) != 0;
        g.autoPin[i] = false;
    }

    UpdatePalette();
    ApplyHotkey();

    Wh_Log(L"Settings loaded: %d deadline line(s), %d parsed, note of %d char(s)", (int)g.dlRaw.size(),
           (int)g.deadlines.size(), (int)g.stickyText.size());
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static const wchar_t kMetaClass[] = L"WindhawkDesktopGlassCardsMeta7";

static HBITMAP g_metaBmpCard = nullptr, g_metaBmpNew = nullptr;
static bool g_metaAmbiguous = false;
static bool g_metaPathConfirmed = false;
static bool g_metaUndoOk = false;
static int g_metaUndoN = 0;
static bool g_metaTouched[3] = {false, false, false};
static int g_metaPickV[3] = {0, 0, 0};

typedef int GpStatus;
struct GdiplusStartupInput {
    UINT32 GdiplusVersion;
    void* DebugEventCallback;
    BOOL SuppressBackgroundThread;
    BOOL SuppressExternalCodecs;
};
typedef void* GpImage;
typedef void* GpGraphics;

static HBITMAP MetaBitmap(const std::vector<BYTE>& img) {
    if (img.size() < 64) return nullptr;
    HMODULE gp = LoadLibraryW(L"gdiplus.dll");
    if (!gp) return nullptr;
    typedef GpStatus(WINAPI * StartupFn)(ULONG_PTR*, const GdiplusStartupInput*, void*);
    typedef GpStatus(WINAPI * FromStreamFn)(IStream*, GpImage**);
    typedef GpStatus(WINAPI * GetWHFn)(GpImage*, UINT*);
    typedef GpStatus(WINAPI * FromHdcFn)(HDC, GpGraphics**);
    typedef GpStatus(WINAPI * DrawFn)(GpGraphics*, GpImage*, INT, INT, INT, INT);
    typedef GpStatus(WINAPI * DelGfxFn)(GpGraphics*);
    typedef GpStatus(WINAPI * DisposeFn)(GpImage*);
    typedef void(WINAPI * ShutdownFn)(ULONG_PTR);
    StartupFn startup = (StartupFn)GetProcAddress(gp, "GdiplusStartup");
    ShutdownFn shutdown = (ShutdownFn)GetProcAddress(gp, "GdiplusShutdown");
    FromStreamFn fromStream = (FromStreamFn)GetProcAddress(gp, "GdipLoadImageFromStream");
    GetWHFn getW = (GetWHFn)GetProcAddress(gp, "GdipGetImageWidth");
    GetWHFn getH = (GetWHFn)GetProcAddress(gp, "GdipGetImageHeight");
    FromHdcFn fromHdc = (FromHdcFn)GetProcAddress(gp, "GdipCreateFromHDC");
    DrawFn drawImg = (DrawFn)GetProcAddress(gp, "GdipDrawImageRectI");
    DelGfxFn delGfx = (DelGfxFn)GetProcAddress(gp, "GdipDeleteGraphics");
    DisposeFn dispose = (DisposeFn)GetProcAddress(gp, "GdipDisposeImage");
    if (!startup || !shutdown || !fromStream || !getW || !getH || !fromHdc || !drawImg || !delGfx ||
        !dispose) {
        FreeLibrary(gp);
        return nullptr;
    }
    ULONG_PTR tok = 0;
    GdiplusStartupInput si;
    memset(&si, 0, sizeof(si));
    si.GdiplusVersion = 1;
    if (startup(&tok, &si, nullptr) != 0) {
        FreeLibrary(gp);
        return nullptr;
    }
    HBITMAP out = nullptr;
    HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, img.size());
    if (mem) {
        void* dst = GlobalLock(mem);
        if (dst) {
            memcpy(dst, img.data(), img.size());
            GlobalUnlock(mem);
            IStream* st = nullptr;
            if (SUCCEEDED(CreateStreamOnHGlobal(mem, FALSE, &st)) && st) {
                GpImage* im = nullptr;
                if (fromStream(st, &im) == 0 && im) {
                    UINT iw = 0, ih = 0;
                    getW(im, &iw);
                    getH(im, &ih);
                    if (iw > 0 && ih > 0) {
                        const int side = 132;
                        HDC sdc = CreateCompatibleDC(nullptr);
                        BITMAPINFO bi;
                        memset(&bi, 0, sizeof(bi));
                        bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
                        bi.bmiHeader.biWidth = side;
                        bi.bmiHeader.biHeight = -side;
                        bi.bmiHeader.biPlanes = 1;
                        bi.bmiHeader.biBitCount = 32;
                        bi.bmiHeader.biCompression = BI_RGB;
                        void* bits = nullptr;
                        HBITMAP dib = CreateDIBSection(sdc, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
                        if (dib && bits) {
                            memset(bits, 0, (size_t)side * (size_t)side * 4u);
                            HDC mdc = CreateCompatibleDC(sdc);
                            HGDIOBJ oldb = SelectObject(mdc, dib);
                            GpGraphics* g2 = nullptr;
                            if (fromHdc(mdc, &g2) == 0 && g2) {
                                if (drawImg(g2, im, 0, 0, side, side) == 0) {
                                    DWORD* bp = (DWORD*)bits;
                                    for (int i = 0; i < side * side; i++) bp[i] |= 0xFF000000u;
                                    out = dib;
                                }
                                delGfx(g2);
                            }
                            SelectObject(mdc, oldb);
                            if (!out) DeleteObject(dib);
                            DeleteDC(mdc);
                        }
                        DeleteDC(sdc);
                    }
                    dispose(im);
                }
                st->Release();
            }
        }
        GlobalFree(mem);
    }
    shutdown(tok);
    FreeLibrary(gp);
    return out;
}

static void MetaPanelClose() {
    if (g_metaWin) {
        DestroyWindow(g_metaWin);
        g_metaWin = nullptr;
    }
    if (g_metaBmpCard) { DeleteObject(g_metaBmpCard); g_metaBmpCard = nullptr; }
    if (g_metaBmpNew) { DeleteObject(g_metaBmpNew); g_metaBmpNew = nullptr; }
    g_meta.live = false;

}

static volatile LONG g_metaUseFound = 0;
static bool g_metaPreferCardCover = false;
static bool g_metaHasFilePreview = false;
static bool g_metaCoverNeedsChoice = false;
static std::vector<BYTE> g_metaPreviewA, g_metaPreviewB;

static bool KnownReadOnlyAudio(const std::wstring& name) {
    return HasAudioExt(LowerWs(name)) && !CvIsMp3(name);
}

static bool MetaIsReadOnly() {
    if (g.media.valid) {
        const auto& current = g.media.path.empty() ? g.media.file : g.media.path;
        if (HasAudioExt(LowerWs(current))) return !CvIsMp3(current);
        if (g_meta.coverTrack != g_thumbTrack) return false;
    }
    return KnownReadOnlyAudio(g_meta.path);
}

struct MetaPickJob {
    HWND owner = nullptr;
    std::wstring startDir;
    std::wstring forTitle, forArtist;
    int generation = 0;
};
struct MetaPickResult {
    std::wstring path;
    std::wstring forTitle, forArtist;
    int generation = 0;
};
static volatile LONG g_metaPickBusy = 0;

static std::wstring MetaShowFileDialog(HWND owner, const std::wstring& start) {
    wchar_t file[MAX_PATH * 2] = {};
    OPENFILENAMEW ofn;
    memset(&ofn, 0, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = owner;
    ofn.lpstrFilter = L"Audio (*.mp3)\0*.mp3\0Todos los archivos (*.*)\0*.*\0\0";
    ofn.lpstrFile = file;
    ofn.nMaxFile = MAX_PATH * 2;
    ofn.lpstrInitialDir = start.empty() ? nullptr : start.c_str();
    ofn.lpstrTitle = TR(L"Elige el MP3 de este tema",
                        L"Choose the MP3 for this track",
                        L"Tria l’MP3 d’aquest tema");
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;

    typedef BOOL(WINAPI* CvGetOpenFileNameW_t)(LPOPENFILENAMEW);
    static CvGetOpenFileNameW_t pGetOpen = nullptr;
    static HMODULE cd = nullptr;
    if (!pGetOpen) {
        cd = LoadLibraryW(L"comdlg32.dll");
        if (cd) pGetOpen = (CvGetOpenFileNameW_t)GetProcAddress(cd, "GetOpenFileNameW");
    }
    if (!pGetOpen || !pGetOpen(&ofn)) return std::wstring();
    return std::wstring(file);
}

static void MetaPanelPickFileApply(const std::wstring& chosen,
                                   const std::wstring& forTitle,
                                   const std::wstring& forArtist, int generation) {
    if (chosen.empty() || g_stop || !g_metaWin || !g_meta.live || MetaIsReadOnly()) return;
    if (!CvIsMp3(chosen)) {
        ShowNotice(L"MP3", TR(L"Elige un archivo .mp3.", L"Choose an .mp3 file.", L"Tria un fitxer .mp3."));
        return;
    }

    if (generation != g_metaGen || CvNorm(g.media.title) != CvNorm(forTitle) ||
        (!forArtist.empty() && CvNorm(g.media.artist) != CvNorm(forArtist))) {
        ShowNotice(TR(L"Multimedia", L"Media", L"Multimèdia"),
                   TR(L"La canción ha cambiado. Vuelve a elegir el archivo para el tema actual.",
                      L"The track changed. Choose the file again for the current track.",
                      L"La cançó ha canviat. Torna a triar l’arxiu per al tema actual."));
        return;
    }
    g.media.path = chosen;
    InterlockedExchange(&g_embedLocked, 0);
    CvFileIdOf(chosen, g.media.id);
    g_mediaIdWant = CvFileIdStr(chosen);
    Wh_Log(L"Metadatos: el usuario elige '%s' (DNI %s)", chosen.c_str(),
           g_mediaIdWant.empty() ? L"no" : g_mediaIdWant.c_str());
    MetaPanelKick(true);
    OnEmbedDone(4);
}

static DWORD WINAPI MetaPickThread(LPVOID pv) {
    MetaPickJob* job = static_cast<MetaPickJob*>(pv);
    if (!job) return 0;
    const HWND owner = job->owner;
    const std::wstring start = job->startDir;
    const std::wstring forTitle = job->forTitle;
    const std::wstring forArtist = job->forArtist;
    const int generation = job->generation;
    delete job;
    if (g_stop) return 0;
    const std::wstring chosen = MetaShowFileDialog(owner, start);
    InterlockedExchange(&g_metaPickBusy, 0);
    if (chosen.empty() || g_stop) return 0;
    MetaPickResult* result = new (std::nothrow) MetaPickResult();
    if (!result) return 0;
    result->path = chosen;
    result->forTitle = forTitle;
    result->forArtist = forArtist;
    result->generation = generation;
    if (!PostUi(WM_APP_METAPICK, 0, (LPARAM)result)) delete result;
    return 0;
}

static void MetaPanelPickFileAsync() {
    if (MetaIsReadOnly()) return;
    if (InterlockedCompareExchange(&g_metaPickBusy, 1, 0) != 0) return;
    MetaPickJob* job = new (std::nothrow) MetaPickJob();
    if (!job) { InterlockedExchange(&g_metaPickBusy, 0); MetaPanelPickFile(); return; }
    job->owner = g_metaWin;
    job->forTitle = g.media.title;
    job->forArtist = g.media.artist;
    job->generation = g_metaGen;
    if (!g.musicDirs.empty()) job->startDir = g.musicDirs[0];
    if (job->startDir.empty()) {
        wchar_t up[MAX_PATH];
        DWORD n = GetEnvironmentVariableW(L"USERPROFILE", up, MAX_PATH);
        if (n > 0 && n < MAX_PATH) job->startDir = std::wstring(up) + L"\\Music";
    }
    if (!StartBgThread(MetaPickThread, job)) {
        delete job;
        InterlockedExchange(&g_metaPickBusy, 0);
        MetaPanelPickFile();
    }
}

static void MetaPanelPickFile() {
    if (MetaIsReadOnly()) return;
    std::wstring start;
    if (!g.musicDirs.empty()) start = g.musicDirs[0];
    if (start.empty()) {
        wchar_t up[MAX_PATH];
        DWORD n = GetEnvironmentVariableW(L"USERPROFILE", up, MAX_PATH);
        if (n > 0 && n < MAX_PATH) start = std::wstring(up) + L"\\Music";
    }
    const int generation = g_metaGen;
    const std::wstring title = g.media.title, artist = g.media.artist;
    const auto path = MetaShowFileDialog(g_metaWin, start);
    MetaPanelPickFileApply(path, title, artist, generation);
}

static void OnMetaPickResult(MetaPickResult* result) {
    if (!result) return;
    const std::wstring chosen = result->path;
    const std::wstring forTitle = result->forTitle;
    const std::wstring forArtist = result->forArtist;
    const int generation = result->generation;
    delete result;
    MetaPanelPickFileApply(chosen, forTitle, forArtist, generation);
}

static void ChooseFound(bool found) {
    if (found ? g_metaPreviewB.empty() : g_metaPreviewA.empty()) return;
    g_metaCoverNeedsChoice = false;
    if (!found) g_metaPreferCardCover = g_metaPreviewA == g_meta.cardImg;
    InterlockedExchange(&g_metaUseFound, found ? 1 : 0);
    Wh_Log(L"Metadatos: el usuario selecciona la columna %s; falta confirmar con Incrustar",
           found ? L"B" : L"A");
    MetaPanelPaint();
}

// Each field can be selected independently in the metadata comparison.
static const std::wstring& MetaFieldB(int f) {
    return f == 0 ? g_meta.newTitle : (f == 1 ? g_meta.newArtist : g_meta.newYear);
}
static bool MetaFieldOk(int f, const std::wstring& v) { return f == 2 ? MetaYearOk(v) : !MetaTextBad(v); }
static const std::wstring& MetaFieldA(int f) {
    const std::wstring& file = f == 0 ? g_meta.fileTitle : (f == 1 ? g_meta.fileArtist : g_meta.fileYear);
    if (MetaFieldOk(f, file) || (f < 2 && MetaIsReadOnly() && !file.empty())) return file;
    const auto& proposal = g_meta.online;
    const std::wstring& online = f == 0 ? proposal.title : (f == 1 ? proposal.artist : proposal.year);
    if (MetaFieldOk(f, online)) return online;
    if (f < 2) {
        const auto& card = f == 0 ? g_meta.cardTitle : g_meta.cardArtist;
        if (MetaFieldOk(f, card)) return card;
    }
    static const std::wstring empty;
    return empty;
}
static bool MetaFieldAFromCard(int f) {
    return f < 2 && &MetaFieldA(f) == (f == 0 ? &g_meta.cardTitle : &g_meta.cardArtist);
}

static const std::wstring& MetaAlbumA() {
    if (!MetaTextBad(g_meta.fileAlbum) || (MetaIsReadOnly() && !g_meta.fileAlbum.empty())) return g_meta.fileAlbum;
    if (!MetaTextBad(g_meta.online.album)) return g_meta.online.album;
    static const std::wstring empty;
    return empty;
}
static bool MetaCardAlternative() {
    return g_metaHasFilePreview && !g_meta.cardImg.empty() &&
           g_meta.cardImg != g_meta.fileImg && g_meta.cardImg != g_metaPreviewB;
}

static bool MetaRememberCardCover() {
    if (g_meta.coverTrack != g_thumbTrack || !g.thumbOk || CvImageType(g.thumbImg) == 0) return false;
    const auto& path = g_meta.path.empty() ? g.media.path : g_meta.path;
    const bool matches = g_thumbAcceptedPath.empty() || path.empty() ||
                         _wcsicmp(g_thumbAcceptedPath.c_str(), path.c_str()) == 0;
    if ((matches && g_meta.cardImg == g.thumbImg) || (!matches && g_meta.cardImg.empty())) return false;
    if (g_metaWin && !g_metaUseFound && !g_meta.cardImg.empty() &&
        g_metaPreviewA == g_meta.cardImg) g_metaCoverNeedsChoice = true;
    if (matches) {
        g_meta.cardImg = g.thumbImg;
        g_meta.cardPixels = g.thumbPx;
        g_meta.cardSide = g.thumbS;
    } else {
        g_meta.cardImg.clear();
        g_meta.cardPixels.clear();
        g_meta.cardSide = 0;
    }
    return true;
}

static HBITMAP MetaCardBitmap() {
    const int side = g_meta.cardSide;
    if (side <= 0 || g_meta.cardPixels.size() != (size_t)side * side) return nullptr;
    BITMAPINFO info = {};
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = side;
    info.bmiHeader.biHeight = -side;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    HBITMAP bitmap = CreateDIBSection(nullptr, &info, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (bitmap) memcpy(bits, g_meta.cardPixels.data(), g_meta.cardPixels.size() * sizeof(DWORD));
    return bitmap;
}

static int MetaPick(int f) {
    if (g_metaTouched[f]) return g_metaPickV[f];
    const bool found = MetaFieldOk(f, MetaFieldB(f));
    if (MetaFieldOk(f, MetaFieldA(f)) && (!found || !MetaFieldAFromCard(f))) return 0;
    if (found) return 1;
    return 0;
}

static volatile LONG g_metaMutationBusy = 0;
struct MetaMutationUiScope {
    bool active = false;
    MetaMutationUiScope() : active(InterlockedCompareExchange(&g_metaMutationBusy, 1, 0) == 0) {}
    ~MetaMutationUiScope() { if (active) InterlockedExchange(&g_metaMutationBusy, 0); }
};

struct DeferredMp3Op {
    CvFileId fileId;
    unsigned long long id = 0;
    bool undo = false;
    bool running = false;
    bool failed = false;
    std::wstring path, title, artist, year, album;
    std::vector<BYTE> cover;
    unsigned long long size = 0, time = 0;
    ULONGLONG nextCheck = 0;
};
struct DeferredMp3Result {
    unsigned long long id = 0;
    bool undo = false;
    int result = -1;
    std::wstring path;
};
static SRWLOCK g_deferredLock = SRWLOCK_INIT;
static std::vector<DeferredMp3Op> g_deferred;
static unsigned long long g_deferredNextId = 1;
static volatile LONG g_deferredWorkerActive = 0;
static std::wstring g_savedMp3Path;
static ULONGLONG g_savedMp3Until = 0;

static Mp3CardStatus MediaMp3Status() {
    const bool samePanel = g_meta.ready && g_meta.coverTrack == g_thumbTrack;
    const auto& path = g.media.valid ?
        (g.media.path.empty() && samePanel ? g_meta.path : g.media.path) : g_meta.path;
    if (path.empty()) return Mp3CardStatus::None;

    static std::wstring lastPath;
    static Mp3CardStatus queued = Mp3CardStatus::None;
    if (TryAcquireSRWLockShared(&g_deferredLock)) {
        queued = Mp3CardStatus::None;
        for (const auto& item : g_deferred) {
            if (_wcsicmp(item.path.c_str(), path.c_str()) == 0) {
                queued = item.failed ? Mp3CardStatus::Review : Mp3CardStatus::Pending;
                break;
            }
        }
        ReleaseSRWLockShared(&g_deferredLock);
        lastPath = path;
    }
    if (queued != Mp3CardStatus::None && _wcsicmp(path.c_str(), lastPath.c_str()) == 0) return queued;
    if (GetTickCount64() < g_savedMp3Until && _wcsicmp(path.c_str(), g_savedMp3Path.c_str()) == 0)
        return Mp3CardStatus::Saved;
    return Mp3CardStatus::None;
}

static std::wstring g_deferredPath;
static HANDLE g_deferredStoreLock = INVALID_HANDLE_VALUE;
static constexpr uint32_t kDeferredLimit = 12;
static constexpr uint32_t kDeferredCoverLimit = 16u << 20;
static constexpr size_t kDeferredStoreLimit = kDeferredLimit * (kDeferredCoverLimit + (512u << 10));
static constexpr char kDeferredMagic[] = "GCMP3Q1";

// Serialize the write queue with its confirmation and file identity data.
static bool DeferredEncode(const std::vector<DeferredMp3Op>& queue, std::vector<BYTE>& bytes) {
    if (queue.size() > kDeferredLimit) return false;
    bytes.assign(kDeferredMagic, kDeferredMagic + sizeof(kDeferredMagic));
    auto put = [&](const auto& value) {
        const auto* first = reinterpret_cast<const BYTE*>(&value);
        bytes.insert(bytes.end(), first, first + sizeof(value));
    };
    put(static_cast<uint32_t>(queue.size()));
    for (const auto& op : queue) {
        const uint32_t flags = (op.undo ? 1u : 0u) | (op.failed || op.running ? 2u : 0u);
        put(flags);
        put(op.size);
        put(op.time);
        put(op.fileId.vol);
        put(op.fileId.id);
        for (const auto* field : {&op.path, &op.title, &op.artist, &op.year, &op.album}) {
            if (field->size() > 32767 || field->find(L'\0') != std::wstring::npos) return false;
            put(static_cast<uint32_t>(field->size()));
            const auto* first = reinterpret_cast<const BYTE*>(field->data());
            bytes.insert(bytes.end(), first, first + field->size() * sizeof(wchar_t));
        }
        if (op.cover.size() > kDeferredCoverLimit || !op.fileId.ok || !CvIsMp3(op.path)) return false;
        put(static_cast<uint32_t>(op.cover.size()));
        bytes.insert(bytes.end(), op.cover.begin(), op.cover.end());
    }
    put(CvUndoCrc32(bytes.data(), bytes.size()));
    return bytes.size() <= kDeferredStoreLimit;
}

// Validate lengths and fields before accepting queued operations from disk.
static bool DeferredDecode(const std::vector<BYTE>& bytes, std::vector<DeferredMp3Op>& queue) {
    if (bytes.size() < sizeof(kDeferredMagic) + 2 * sizeof(uint32_t) ||
        bytes.size() > kDeferredStoreLimit ||
        memcmp(bytes.data(), kDeferredMagic, sizeof(kDeferredMagic)) != 0) return false;
    const size_t end = bytes.size() - sizeof(uint32_t);
    uint32_t crc = 0;
    memcpy(&crc, bytes.data() + end, sizeof(crc));
    if (crc != CvUndoCrc32(bytes.data(), end)) return false;
    size_t offset = sizeof(kDeferredMagic);
    auto get = [&](auto& value) {
        if (sizeof(value) > end - offset) return false;
        memcpy(&value, bytes.data() + offset, sizeof(value));
        offset += sizeof(value);
        return true;
    };
    uint32_t count = 0;
    if (!get(count) || count > kDeferredLimit) return false;
    std::vector<DeferredMp3Op> decoded;
    for (uint32_t i = 0; i < count; ++i) {
        DeferredMp3Op op;
        uint32_t flags = 0;
        if (!get(flags) || flags > 3 || !get(op.size) || !get(op.time) ||
            !get(op.fileId.vol) || !get(op.fileId.id)) return false;
        for (auto* field : {&op.path, &op.title, &op.artist, &op.year, &op.album}) {
            uint32_t units = 0;
            if (!get(units) || units > 32767 || units > (end - offset) / sizeof(wchar_t)) return false;
            const size_t size = units * sizeof(wchar_t);
            field->resize(units);
            memcpy(field->data(), bytes.data() + offset, size);
            offset += size;
            if (field->find(L'\0') != std::wstring::npos) return false;
        }
        uint32_t coverSize = 0;
        if (!CvIsMp3(op.path) || !op.size ||
            !get(coverSize) || coverSize > kDeferredCoverLimit || coverSize > end - offset) return false;
        op.cover.assign(bytes.data() + offset, bytes.data() + offset + coverSize);
        offset += coverSize;
        if (coverSize && !CvImageType(op.cover)) return false;
        op.undo = (flags & 1u) != 0;

        op.failed = (flags & 2u) != 0;
        op.fileId.ok = true;
        op.id = i + 1;
        decoded.push_back(std::move(op));
    }
    if (offset != end) return false;
    queue.swap(decoded);
    return true;
}

// Persist the queue before scheduling or removing a confirmed operation.
static bool DeferredSave(const std::vector<DeferredMp3Op>& queue) {
    std::vector<BYTE> bytes;
    return !g_deferredPath.empty() && DeferredEncode(queue, bytes) &&
           CvWriteFile(g_deferredPath, bytes.data(), bytes.size());
}

// Recover pending operations and require review where interruption makes state uncertain.
static void DeferredLoad() {
    wchar_t local[MAX_PATH];
    const DWORD length = GetEnvironmentVariableW(L"LOCALAPPDATA", local, MAX_PATH);
    if (!length || length >= MAX_PATH) return;
    const std::wstring dir = std::wstring(local) + L"\\WindhawkGlassCards";
    CreateDirectoryW(dir.c_str(), nullptr);
    const std::wstring path = dir + L"\\pending-mp3.v1";
    g_deferredStoreLock = CreateFileW((path + L".lock").c_str(), GENERIC_READ | GENERIC_WRITE,
                                    0, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (g_deferredStoreLock == INVALID_HANDLE_VALUE) return;
    g_deferredPath = path;
    const DWORD attrs = GetFileAttributesW(path.c_str());
    if (attrs == INVALID_FILE_ATTRIBUTES && GetLastError() == ERROR_FILE_NOT_FOUND) return;
    std::vector<BYTE> bytes;
    SrwGuard guard(&g_deferredLock);
    if (!CvReadFile(path, bytes, kDeferredStoreLimit) || !DeferredDecode(bytes, g_deferred)) {

        g_deferredPath.clear();
        ShowNotice(L"MP3", TR(L"No se pudo recuperar la cola guardada. El archivo de cola se ha conservado.", L"Could not restore the saved queue. Its file was preserved.", L"No s’ha pogut recuperar la cua desada. Se n’ha conservat el fitxer."));
        return;
    }
    g_deferredNextId = g_deferred.size() + 1;
    Wh_Log(L"MP3PEND: recuperadas %u operaciones guardadas", (unsigned)g_deferred.size());
}

static int DeferredCount() {
    AcquireSRWLockShared(&g_deferredLock);
    int n = (int)g_deferred.size();
    ReleaseSRWLockShared(&g_deferredLock);
    return n;
}
static bool DeferredCancelOne(unsigned long long id) {
    SrwGuard guard(&g_deferredLock);
    auto next = g_deferred;
    const auto item = std::find_if(next.begin(), next.end(), [id](const auto& op) { return op.id == id; });
    if (item == next.end() || item->running) return false;
    next.erase(item);
    if (!DeferredSave(next)) return false;
    g_deferred.swap(next);
    return true;
}

static bool DeferredCancelAll() {
    SrwGuard guard(&g_deferredLock);
    for (const auto& item : g_deferred) {
        if (item.running) return false;
    }
    if (!DeferredSave({})) return false;
    g_deferred.clear();
    return true;
}
static bool DeferredQueue(DeferredMp3Op op) {
    SrwGuard guard(&g_deferredLock);
    auto next = g_deferred;
    auto existing = std::find_if(next.begin(), next.end(), [&](const auto& item) {
        return _wcsicmp(item.path.c_str(), op.path.c_str()) == 0;
    });
    op.id = g_deferredNextId;
    if (existing != next.end()) {
        if (existing->running) return false;
        *existing = std::move(op);
    } else {
        if (next.size() >= kDeferredLimit) return false;
        next.push_back(std::move(op));
    }
    if (!DeferredSave(next)) return false;
    g_deferred.swap(next);
    ++g_deferredNextId;
    return true;
}
enum class DeferredCancelResult { Missing, Cancelled, SaveFailed };
static DeferredCancelResult DeferredCancelPendingEmbedFor(const std::wstring& path) {
    SrwGuard guard(&g_deferredLock);
    auto next = g_deferred;
    auto existing = std::find_if(next.begin(), next.end(), [&](const auto& item) {
        return !item.undo && !item.running && _wcsicmp(item.path.c_str(), path.c_str()) == 0;
    });
    if (existing == next.end()) return DeferredCancelResult::Missing;
    next.erase(existing);
    if (!DeferredSave(next)) return DeferredCancelResult::SaveFailed;
    g_deferred.swap(next);
    return DeferredCancelResult::Cancelled;
}
static void DeferredNoticeQueued(bool undo) {
    ShowNotice(TR(L"Metadatos pendientes", L"Pending MP3 tags", L"Metadades pendents"),
        undo ? TR(L"Deshacer guardado. Se aplicará cuando quede libre el MP3.",
                  L"Undo saved. It will run when the MP3 is free.",
                  L"Desfer desat. S’aplicarà quan l’MP3 estigui lliure.")
             : TR(L"Cambios guardados en la cola. Se aplicarán cuando quede libre el MP3.",
                  L"Changes saved to the queue. They will apply when the MP3 is free.",
                  L"Canvis desats a la cua. S’aplicaran quan l’MP3 estigui lliure."));
}
struct DeferredMp3Work {
    DeferredMp3Op operation;
    DeferredMp3Result* result;
};

// Apply a confirmed tag write or restore the prior ID3 header from a backup.
static DWORD WINAPI DeferredMp3Thread(LPVOID param) {
    auto* work = static_cast<DeferredMp3Work*>(param);
    auto* job = &work->operation;
    auto* res = work->result;
    res->id = job->id; res->undo = job->undo; res->path = job->path;
    try {
        unsigned long long size = 0, time = 0;
        if (g_stop) {
            res->result = 2;
        } else if (!CvFileStamp(job->path, size, time) || size != job->size || time != job->time ||
            !CvMutationIdentityStillMatches(job->path, job->fileId)) {
            Wh_Log(L"MP3PEND: el MP3 cambio desde la confirmacion; no se sobrescribe (%s)", job->path.c_str());
            res->result = 3;
        } else if (!Mp3MediaSafeForMutation() || !CvFileExclusivelyAvailable(job->path)) {
            Wh_Log(L"MP3PEND: espera: reproductor/sesion activa, estado desconocido o archivo ocupado");
            res->result = 2;
        } else if (job->undo) {

            if (!CvUndoPreflight(job->path)) res->result = 3;
            else if (!Mp3MediaSafeForMutation()) res->result = 2;
            else {
                bool temporarilyBusy = false;
                const bool success = CvUndoApply(job->path, false, &temporarilyBusy);
                res->result = success ? 0 : (temporarilyBusy ? 2 : 3);
            }
        } else {

            g_embedWantSize = job->size;
            g_embedWantTime = job->time;
            CvEmbedRes r = CvEmbed(job->path, job->cover, job->title, job->artist,
                                   job->year, job->album, job->fileId);
            res->result = r == EMB_OK ? 0 : (r == EMB_ALREADY ? 1 : (r == EMB_LOCKED ? 2 : 3));
        }
    } catch (...) {
        res->result = 3;
    }
    Wh_Log(L"MP3PEND: %s termina; resultado=%d; ruta='%s'", job->undo ? L"Deshacer" : L"Incrustar",
           res->result, res->path.c_str());
    {
        SrwGuard guard(&g_deferredLock);
        auto next = g_deferred;
        auto item = std::find_if(next.begin(), next.end(), [&](const auto& op) { return op.id == res->id; });
        if (item != next.end()) {
            if (res->result <= 1) next.erase(item);
            else {
                item->running = false;
                item->failed = res->result != 2;
                item->nextCheck = GetTickCount64() + 5000;
            }
            if (DeferredSave(next)) {
                g_deferred.swap(next);
            } else {

                for (auto& op : g_deferred) {
                    if (op.id == res->id) { op.running = false; op.failed = true; }
                }
                res->result = 4;
            }
        }
    }
    delete work;
    if (g_stop || !PostUi(WM_APP_DEFERRED, 0, (LPARAM)res)) {
        delete res;
        InterlockedExchange(&g_deferredWorkerActive, 0);
        InterlockedExchange(&g_metaMutationBusy, 0);
    }
    return 0;
}
// Wait for playback and file access to settle, then revalidate the confirmed target.
static void DeferredTryStart() {
    if (g_stop) return;
    if (!Mp3MediaSafeForMutation() || g.media.valid || g.media.playing) return;
    ULONGLONG now = GetTickCount64();
    if (InterlockedCompareExchange(&g_deferredWorkerActive, 0, 0) ||
        InterlockedCompareExchange(&g_metaMutationBusy, 0, 0)) return;
    DeferredMp3Op op;
    bool found = false;
    {
        SrwGuard guard(&g_deferredLock);
        for (auto& item : g_deferred) {
            if (item.running || item.failed || now < item.nextCheck) continue;
            item.nextCheck = now + 3000;
            op = item; found = true;
            break;
        }
    }
    if (!found) return;
    unsigned long long sz = 0, ft = 0;

    if (!CvFileStamp(op.path, sz, ft)) return;
    if (op.size != sz || op.time != ft || !CvMutationIdentityStillMatches(op.path, op.fileId)) {
        SrwGuard guard(&g_deferredLock);
        for (auto& item : g_deferred) if (item.id == op.id) item.failed = true;
        if (!DeferredSave(g_deferred)) Wh_Log(L"MP3PEND: no se pudo guardar la suspensión");
        Wh_Log(L"MP3PEND: MP3 cambiado mientras esperaba; suspendido sin escribir: '%s'", op.path.c_str());
        ShowNotice(TR(L"MP3 pendiente", L"Pending MP3", L"MP3 pendent"), TR(L"El archivo cambió. Revisa o cancela la operación pendiente.", L"The file changed. Review or cancel the pending operation.", L"El fitxer ha canviat. Revisa o cancel·la l’operació pendent."));
        return;
    }
    if (!Mp3MediaSafeForMutation() || !CvFileExclusivelyAvailable(op.path)) return;
    if (InterlockedCompareExchange(&g_metaMutationBusy, 1, 0) != 0) return;
    if (InterlockedCompareExchange(&g_deferredWorkerActive, 1, 0) != 0) {
        InterlockedExchange(&g_metaMutationBusy, 0); return;
    }
    {
        SrwGuard guard(&g_deferredLock);
        for (auto& item : g_deferred) if (item.id == op.id) item.running = true;
        if (!DeferredSave(g_deferred)) {
            for (auto& item : g_deferred) if (item.id == op.id) item.running = false;
            InterlockedExchange(&g_deferredWorkerActive, 0);
            InterlockedExchange(&g_metaMutationBusy, 0);
            Wh_Log(L"MP3PEND: no se inicia el trabajo porque no se pudo guardar la cola");
            return;
        }
    }
    const unsigned long long scheduledId = op.id;
    auto* result = new (std::nothrow) DeferredMp3Result();
    auto* job = result ? new (std::nothrow) DeferredMp3Work{std::move(op), result} : nullptr;
    if (!job || !StartBgThread(DeferredMp3Thread, job)) {
        delete result;
        delete job;
        InterlockedExchange(&g_metaMutationBusy, 0);
        InterlockedExchange(&g_deferredWorkerActive, 0);
        SrwGuard guard(&g_deferredLock);
        for (auto& item : g_deferred) if (item.running) { item.running = false; item.nextCheck = now + 3000; }
        if (!DeferredSave(g_deferred)) Wh_Log(L"MP3PEND: no se pudo restaurar la cola");
        return;
    }
    Wh_Log(L"MP3PEND: MP3 libre durante 4 s; comienza operacion diferida, id=%llu", scheduledId);
}
// Reconcile the worker result with the persistent queue and independent notices.
static void OnDeferredDone(DeferredMp3Result* res) {
    if (!res) return;
    InterlockedExchange(&g_deferredWorkerActive, 0);
    InterlockedExchange(&g_metaMutationBusy, 0);
    if (res->result <= 1) {
        g_savedMp3Path = res->path;
        g_savedMp3Until = GetTickCount64() + 8000;
        Wh_Log(L"MP3PEND: %s TERMINADO; pendientes=%d", res->undo ? L"Deshacer" : L"Incrustar", DeferredCount());
        if (res->undo) OnEmbedDone(2);
        else {
            if (_wcsicmp(res->path.c_str(), g.media.path.c_str()) == 0) {
                RefreshFileMeta(res->path);
            }
            if (_wcsicmp(res->path.c_str(), g_meta.path.c_str()) == 0) {
                FileMeta saved;
                if (ReadFileMeta(res->path, saved, true)) {
                    SrwGuard guard(&g_metaLock);
                    g_meta.fileTitle = saved.title;
                    g_meta.fileArtist = saved.artist;
                    g_meta.fileAlbum = saved.album;
                    g_meta.fileYear = saved.year;
                    g_meta.fileImg = std::move(saved.cover);
                    CvFileStamp(res->path, g_meta.size, g_meta.time);
                    CvMutationIdentityOfPath(res->path, g_meta.fileId);
                }
                if (g_metaWin) { MetaPanelFill(); MetaPanelPaint(); }
            }
        }
        ShowNotice(TR(L"Metadatos MP3", L"MP3 metadata", L"Metadades MP3"), res->result == 1 ? TR(L"El archivo ya tenía los datos elegidos.", L"The file already had the selected tags.", L"El fitxer ja tenia les etiquetes triades.") :
                   (res->undo ? TR(L"Se restauraron las etiquetas del MP3.", L"The MP3 tags were restored.", L"S’han restaurat les etiquetes de l’MP3.") : TR(L"Se guardaron las etiquetas del MP3.", L"The MP3 tags were saved.", L"S’han desat les etiquetes de l’MP3.")));
    } else if (res->result == 4) {
        ShowNotice(TR(L"MP3 pendiente", L"Pending MP3", L"MP3 pendent"), TR(L"No se pudo actualizar la cola guardada. Revisa el MP3 antes de volver a autorizar la operación.", L"Could not update the saved queue. Review the MP3 before authorizing another change.", L"No s’ha pogut actualitzar la cua. Revisa l’MP3 abans d’autoritzar un altre canvi."));
    } else if (res->result == 3) {
        ShowNotice(TR(L"MP3 pendiente", L"Pending MP3", L"MP3 pendent"), TR(L"La operación queda suspendida. Puedes cancelarla desde el menú de una tarjeta.", L"The operation is suspended. You can cancel it from a card menu.", L"L’operació està suspesa. La pots cancel·lar des del menú d’una targeta."));
    }
    delete res;
}

static void MetaPanelApply() {
    MetaMutationUiScope operation;
    if (!operation.active) { Wh_Log(L"Metadatos: Incrustar omitido; ya hay una operacion pendiente"); return; }
    if (!g_meta.ready || !g_metaPathConfirmed || !CvIsMp3(g_meta.path)) return;
    if (MetaIsReadOnly() || (g.media.valid && g_meta.coverTrack != g_thumbTrack)) return;
    if (g_metaCoverNeedsChoice) {
        ShowNotice(L"MP3", TR(L"La portada cambió. Elige la que quieres guardar.",
                              L"The cover changed. Choose the artwork to save.",
                              L"La portada ha canviat. Tria la que vols desar."));
        return;
    }
    const bool useFound = InterlockedCompareExchange(&g_metaUseFound, 0, 0) != 0;
    const auto& cover = useFound ? g_metaPreviewB : g_metaPreviewA;
    auto pickVal = [&](int f) -> std::wstring {
        const int pk = MetaPick(f);
        std::wstring v = pk ? MetaFieldB(f) : MetaFieldA(f);
        if (!MetaFieldOk(f, v)) {
            const std::wstring& o = pk ? MetaFieldA(f) : MetaFieldB(f);
            if (MetaFieldOk(f, o)) v = o;
        }
        return v;
    };
    std::wstring title = pickVal(0);
    std::wstring artist = pickVal(1);
    std::wstring year = pickVal(2);
    year = MetaYearOk(year) ? year.substr(0, 4) : std::wstring();

    std::wstring album = useFound ? g_meta.newAlbum : MetaAlbumA();
    if (MetaTextBad(album)) album.clear();
    if (title.empty() && artist.empty() && year.empty() && album.empty() && cover.empty()) {
        ShowNotice(L"MP3", TR(L"No hay datos para guardar.", L"No tags to save.", L"No hi ha dades per desar."));
        return;
    }

    unsigned long long actualSize = 0, actualTime = 0;
    if (!CvFileStamp(g_meta.path, actualSize, actualTime) ||
        actualSize != g_meta.size || actualTime != g_meta.time ||
        !CvMutationIdentityStillMatches(g_meta.path, g_meta.fileId)) {
        ShowNotice(L"MP3", TR(L"El archivo cambió desde que se abrió la ficha. Vuelve a seleccionarlo.", L"The file changed after opening the panel. Select it again.", L"El fitxer ha canviat des que has obert la fitxa. Torna’l a triar."));
        Wh_Log(L"MP3PEND: no se encola una ficha cuyo MP3 cambio");
        return;
    }
    DeferredMp3Op op;
    op.path = g_meta.path;
    if (cover != g_meta.fileImg) op.cover = cover;
    op.fileId = g_meta.fileId;
    op.title = title; op.artist = artist; op.year = year; op.album = album;
    op.size = actualSize; op.time = actualTime;
    if (!DeferredQueue(std::move(op))) {
        ShowNotice(L"MP3", TR(L"No se pudo poner el cambio en cola. Comprueba el espacio disponible y las operaciones pendientes.", L"Could not queue the change. Check available storage and pending operations.", L"No s’ha pogut afegir el canvi a la cua. Comprova l’espai disponible i les operacions pendents."));
        return;
    }
    Wh_Log(L"MP3PEND: INCRUSTAR en disco; archivo='%s'; pendientes=%d; NO se ha modificado",
           g_meta.path.c_str(), DeferredCount());
    MetaPanelClose();
    DeferredNoticeQueued(false);
}

static const float kMetaW = 560.0f;
static constexpr float kMetaH = 456.0f;
static constexpr float kMetaCoverTop = 126.0f;
static constexpr float kMetaCoverSize = 104.0f;
static constexpr float kMetaCoverLabelY = kMetaCoverTop + kMetaCoverSize + 5.0f;
static constexpr float kMetaFieldTop = kMetaCoverLabelY + 23.0f;
static constexpr float kMetaFieldStep = 22.0f;
static constexpr float kMetaButtonY = kMetaH - 30.0f;
static constexpr float kMetaButtonHalfWidth = 88.0f;
static constexpr float kMetaButtonHalfHeight = 16.0f;

static float MetaPanelScale(HWND window) {
    const UINT dpi = GetDpiForWindow(window);
    float k = ((float)g.scale / 100.0f) * (dpi ? (float)dpi / 96.0f : 1.0f);
    MONITORINFO monitor = {};
    monitor.cbSize = sizeof(monitor);
    if (GetMonitorInfoW(MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST), &monitor)) {
        const float fitWidth = (monitor.rcWork.right - monitor.rcWork.left - 16.0f) / (kMetaW + 40.0f);
        const float fitHeight = (monitor.rcWork.bottom - monitor.rcWork.top - 16.0f) / (kMetaH + 40.0f);
        k = std::max(0.1f, std::min({k, fitWidth, fitHeight}));
    }
    return k;
}

// Choose the controls for the current metadata dialog state.
struct MetaUi {
    int need;
    bool undo;
    bool canConfirm;
    bool readOnly;
};
static MetaUi MetaUiState() {
    MetaUi u{};
    u.readOnly = MetaIsReadOnly();
    if (u.readOnly || !g_meta.ready) return u;
    if (g.media.valid && g_meta.coverTrack != g_thumbTrack) return u;
    u.undo = g_metaPathConfirmed && g_metaUndoOk;
    if (g_meta.path.empty()) u.need = g_metaAmbiguous ? 2 : 1;
    else if (!g_metaPathConfirmed) u.need = 3;
    u.canConfirm = u.need == 3 && g_meta.fileId.ok;
    return u;
}
static void MetaButtonX(const MetaUi& ui, float& alternateX, float& primaryX) {
    const float center = kMetaW * 0.5f;
    alternateX = primaryX = center;
    if (ui.canConfirm || ui.undo) {
        primaryX = center - 98.0f;
        alternateX = center + 98.0f;
    }
}

static void MetaConfirmCandidate() {
    if (!MetaUiState().canConfirm) return;
    unsigned long long size = 0, time = 0;
    if (!CvFileStamp(g_meta.path, size, time) || size != g_meta.size || time != g_meta.time ||
        !CvMutationIdentityStillMatches(g_meta.path, g_meta.fileId)) {
        ShowNotice(L"MP3", TR(L"El archivo cambió. Vuelve a abrir la ficha.",
                              L"The file changed. Open the metadata panel again.",
                              L"El fitxer ha canviat. Torna a obrir la fitxa."));
        if (g.media.valid) MetaPanelKick(true);
        return;
    }
    g_metaPathConfirmed = true;
    if (g.media.valid && g.media.dur <= 1.0 && g_meta.coverTrack == g_thumbTrack)
        g_mediaFileDuration = g_meta.dur;
    MetaPanelPaint();
}

static void MetaPanelFill() {
    if (!g_metaWin) return;
    g_metaUndoN = g_meta.path.empty() ? 0 : CvUndoCount(g_meta.path);
    g_metaUndoOk = g_metaUndoN > 0;
    if (g_metaBmpCard) { DeleteObject(g_metaBmpCard); g_metaBmpCard = nullptr; }
    if (g_metaBmpNew) { DeleteObject(g_metaBmpNew); g_metaBmpNew = nullptr; }
    g_metaPreviewA.clear();
    g_metaPreviewB.clear();
    g_metaBmpNew = !g_meta.cardImg.empty() && g_meta.newImg == g_meta.cardImg ?
        MetaCardBitmap() : MetaBitmap(g_meta.newImg);
    if (g_metaBmpNew) g_metaPreviewB = g_meta.newImg;
    HBITMAP file = CvImageType(g_meta.fileImg) ? MetaBitmap(g_meta.fileImg) : nullptr;
    g_metaHasFilePreview = file != nullptr;
    if (!g_meta.cardImg.empty() && (g_metaPreferCardCover || !file)) {
        g_metaBmpCard = MetaCardBitmap();
        if (g_metaBmpCard) g_metaPreviewA = g_meta.cardImg;
    }
    if (!g_metaBmpCard && file) {
        g_metaBmpCard = file;
        file = nullptr;
        g_metaPreviewA = g_meta.fileImg;
    }
    if (file) DeleteObject(file);
    if (!g_metaBmpCard && CvImageType(g_meta.online.cover)) {
        g_metaBmpCard = MetaBitmap(g_meta.online.cover);
        if (g_metaBmpCard) g_metaPreviewA = g_meta.online.cover;
    }

    if (g_metaUseFound && !g_metaBmpNew && g_metaBmpCard) {
        InterlockedExchange(&g_metaUseFound, 0);
    } else if (!g_metaUseFound && !g_metaBmpCard && g_metaBmpNew) {
        InterlockedExchange(&g_metaUseFound, 1);
    }
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static void MetaDrawCover(Canvas& cv, HBITMAP bmp, float x0, float y0, float sz, float k, RGBA ac,
                          bool hot) {
    float cx = x0 + sz / 2.0f, cy = y0 + sz / 2.0f, hw = sz / 2.0f, rad = 12.0f * k;
    auto sd = [=](float x, float y) { return SdRoundRect(x, y, cx, cy, hw, hw, rad); };

    if (hot) {
        RGBA hc = ac;
        hc.a = 0.95f;
        FillSdf(cv, x0 - 5.0f * k, y0 - 5.0f * k, x0 + sz + 5.0f * k, y0 + sz + 5.0f * k,
                [=](float x, float y) {
                    float d = SdRoundRect(x, y, cx, cy, hw + 2.6f * k, hw + 2.6f * k, rad + 2.6f * k);
                    return fabsf(d + 2.6f * k) - 2.6f * k;
                },
                [hc](float, float) -> RGBA { return hc; });
    }
    BITMAP bm;
    if (bmp && GetObjectW(bmp, sizeof(bm), &bm) && bm.bmBits && bm.bmWidth > 0 && bm.bmHeight > 0) {
        const DWORD* px = (const DWORD*)bm.bmBits;
        const int S = bm.bmWidth;
        FillSdf(cv, x0 - 1, y0 - 1, x0 + sz + 1, y0 + sz + 1, sd, [=](float x, float y) -> RGBA {
            float u = (x - x0) / sz * (float)S - 0.5f;
            float v = (y - y0) / sz * (float)S - 0.5f;
            int ix = (int)floorf(u), iy = (int)floorf(v);
            float fx = u - (float)ix, fy = v - (float)iy;
            int xa = ClampInt(ix, 0, S - 1), xb = ClampInt(ix + 1, 0, S - 1);
            int ya = ClampInt(iy, 0, S - 1), yb = ClampInt(iy + 1, 0, S - 1);
            DWORD p00 = px[(size_t)ya * S + xa], p10 = px[(size_t)ya * S + xb];
            DWORD p01 = px[(size_t)yb * S + xa], p11 = px[(size_t)yb * S + xb];
            auto ch = [&](int sh) {
                float a = (float)((p00 >> sh) & 0xFF), b2 = (float)((p10 >> sh) & 0xFF);
                float c2 = (float)((p01 >> sh) & 0xFF), d = (float)((p11 >> sh) & 0xFF);
                return Lerp(Lerp(a, b2, fx), Lerp(c2, d, fx), fy) / 255.0f;
            };
            RGBA c = {ch(16), ch(8), ch(0), 1.0f};
            return c;
        });
    } else {
        FillSdf(cv, x0 - 1, y0 - 1, x0 + sz + 1, y0 + sz + 1, sd, [=](float, float y) -> RGBA {
            float tt = Clamp01((y - y0) / sz);
            RGBA c = LerpC(ac, LerpC(ac, C(20, 24, 40), 0.65f), tt);
            c.a = 0.55f;
            return c;
        });
    }
}

static void MetaDrawButton(Canvas& cv, TextCtx& t, Fonts& f, float cx, float cy, float hw, float hh,
                           const std::wstring& label, bool primary, float k) {
    FillRRect(cv, cx, cy, hw, hh, hh, [primary](float, float) -> RGBA {
        return primary ? C(145, 36, 76) : HL(0.19f);
    });
    DrawLabel(t, f.name, label, cx, cy - 9.0f * k, 1, primary ? C(255, 255, 255) : g.pal.white);
}

static void MetaPanelPaint() {
    if (!g_metaWin) return;
    const float k = MetaPanelScale(g_metaWin);
    Fonts& fonts = EnsureFonts(k);
    RGBA ac = CardAccent(C(255, 120, 160));

    float cardW = kMetaW * k, cardH = kMetaH * k;
    float M = 20.0f * k;
    int W = (int)ceilf(cardW + 2.0f * M);
    int H = (int)ceilf(cardH + 2.0f * M);

    Canvas cv;
    cv.w = W;
    cv.h = H;
    cv.px.assign((size_t)W * (size_t)H, 0);
    const RGBA glassAccent = LerpC(g.pal.topC, ac, 0.24f);
    BuildBackground(cv, M, cardW, cardH, k, glassAccent, false, g.pal.topC, g.pal.botC, 0.72f);

    if (!EnsureDib(g_dibText, W, H, true) || !EnsureDib(g_dibOut, W, H, false)) return;
    HDC mdc = g_dibText.dc;
    DWORD* sbits = g_dibText.bits;
    memset(sbits, 0, (size_t)W * (size_t)H * 4);
    TextCtx t = {mdc, sbits, W, H, &cv};
    t.k = k;

    const MetaUi ui = MetaUiState();
    DrawCardHeader(cv, t, fonts, CARD_MEDIA, M, k, ui.readOnly ?
        TR(L"METADATOS DE AUDIO", L"AUDIO METADATA", L"METADADES D’ÀUDIO") :
        TR(L"METADATOS DEL MP3", L"MP3 METADATA", L"METADADES DE L’MP3"));
    {
        float cx = M + (kMetaW - 22.0f) * k, cy = M + 20.0f * k;
        FillCircle(cv, cx, cy, 11.0f * k, [](float, float) -> RGBA { return HL(0.14f); });
        float q = 0.9f * k;
        FillCapsule(cv, cx - 3.4f * q, cy - 3.4f * q, cx + 3.4f * q, cy + 3.4f * q, 0.9f * q,
                    [](float, float) -> RGBA { return g.pal.soft; });
        FillCapsule(cv, cx + 3.4f * q, cy - 3.4f * q, cx - 3.4f * q, cy + 3.4f * q, 0.9f * q,
                    [](float, float) -> RGBA { return g.pal.soft; });
    }

    float y = M + 44.0f * k;
    std::wstring fileLine = g_meta.path.empty() ?
        (ui.readOnly && !g.media.file.empty() ? g.media.file : TR(L"(sin archivo)", L"(no file)", L"(sense arxiu)")) :
        (ui.canConfirm ? g_meta.path : g_meta.file);
    const bool showLink = !ui.readOnly && ui.need == 0 && !g_meta.file.empty();
    DrawLabel(t, fonts.small,
              Ellipsize(t, fonts.small, fileLine, (int)((kMetaW - 36.0f - (showLink ? 140.0f : 0.0f)) * k)),
              M + 18.0f * k, y, 0, g.pal.white);
    if (showLink) {

        DrawLabel(t, fonts.small, TR(L"\u00BFNo es este archivo?", L"Not this file?", L"No \u00E9s aquest arxiu?"),
                  M + (kMetaW - 18.0f) * k, y, 2, CardAccent(C(255, 120, 160)));
    }

    DrawLabel(t, fonts.small,
              ui.readOnly ? TR(L"Solo lectura · Se pueden guardar etiquetas en MP3.",
                               L"Read-only · Tags can be saved to MP3 files.",
                               L"Només lectura · Es poden desar etiquetes en MP3.") :
              g_metaCoverNeedsChoice ?
                 TR(L"La portada cambió. Selecciona la que quieres guardar.",
                    L"The cover changed. Choose the artwork to save.",
                    L"La portada ha canviat. Tria la que vols desar.") :
                 TR(L"Pulsa los datos y la carátula que quieras guardar.",
                    L"Click the tags and cover you want to save.",
                    L"Prem les dades i la portada que vulguis desar."),
              M + kMetaW * 0.5f * k, M + 70.0f * k, 1, g.pal.white);

    float colW = (kMetaW - 36.0f) / 2.0f;
    float x1 = M + 18.0f * k;
    float x2 = M + (18.0f + colW) * k;
    const float coverSz = kMetaCoverSize * k;
    const float yCover = M + kMetaCoverTop * k;
    const float yText = M + kMetaFieldTop * k;

    float cx1 = x1 + colW * 0.5f * k;
    float cx2 = x2 + colW * 0.5f * k;
    int textW = (int)(colW * k) - 12;

    float covOff = (colW * 0.5f - coverSz * 0.5f / k) * k;
    const int selectedCover = g_metaCoverNeedsChoice ? 0 : (g_metaUseFound ? 2 : 1);
    MetaDrawCover(cv, g_metaBmpCard, x1 + covOff, yCover, coverSz, k, ac,
                  g_metaBmpCard && selectedCover == 1);
    MetaDrawCover(cv, g_metaBmpNew, x2 + covOff, yCover, coverSz, k, ac,
                  g_metaBmpNew && selectedCover == 2);

    const bool cardInA = !g_metaPreviewA.empty() && g_metaPreviewA == g_meta.cardImg;
    const wchar_t* coverLabel = nullptr;
    if (!ui.readOnly && MetaCardAlternative() && g_metaBmpCard) {
        coverLabel = cardInA ? TR(L"Usar portada del MP3", L"Use MP3 cover", L"Fes servir la portada de l’MP3") :
                              TR(L"Usar portada de Multimedia", L"Use Media cover", L"Fes servir la portada de Multimèdia");
    } else if (cardInA && g_metaPreviewA != g_meta.fileImg) {
        coverLabel = TR(L"Portada de Multimedia", L"Media card cover", L"Portada de Multimèdia");
    } else if (!g_metaPreviewA.empty() && g_metaPreviewA == g_meta.online.cover &&
               g_metaPreviewA != g_meta.fileImg) {
        coverLabel = TR(L"Portada de Internet", L"Online cover", L"Portada d’Internet");
    }
    if (coverLabel)
        DrawLabel(t, fonts.small, coverLabel, cx1, M + kMetaCoverLabelY * k, 1,
                  MetaCardAlternative() ? (g.pal.light ? C(135, 32, 75) : C(255, 171, 200)) : g.pal.white);
    const wchar_t* noCover = TR(L"Sin carátula", L"No cover", L"Sense portada");
    if (!g_metaBmpCard) DrawLabel(t, fonts.small, noCover, cx1, yCover + 44.0f * k, 1, g.pal.white);
    if (!g_metaBmpNew) DrawLabel(t, fonts.small, noCover, cx2, yCover + 44.0f * k, 1, g.pal.white);

    std::wstring none = TR(L"(sin etiqueta)", L"(no tag)", L"(sense etiqueta)");
    const std::wstring noneNew = g_meta.loading ?
        TR(L"(buscando…)", L"(searching…)", L"(cercant…)") :
        TR(L"(sin coincidencia)", L"(no match)", L"(sense coincidència)");

    auto fieldLine = [&](int f, bool colB, const std::wstring& label, const std::wstring& value,
                         const std::wstring& emptyTxt, float cx, float yy) {
        const bool picked = (MetaPick(f) == (colB ? 1 : 0));
        std::wstring shown = Ellipsize(t, fonts.small, label + (value.empty() ? emptyTxt : value), textW);
        DrawLabel(t, fonts.small, shown, cx, yy, 1, g.pal.white);
        if (picked && !value.empty()) {
            float w2 = (float)MeasureWidth(t, fonts.small, shown);
            FillCapsule(cv, cx - w2 * 0.5f, yy + 17.0f * k, cx + w2 * 0.5f, yy + 17.0f * k, 0.9f * k,
                        [ac](float, float) -> RGBA {
                            RGBA c = ac;
                            c.a = 0.85f;
                            return c;
                        });
        }
    };
    std::wstring cyr = MetaFieldA(2);
    const std::wstring& albumA = MetaAlbumA();
    if (!albumA.empty()) {
        if (!cyr.empty()) cyr += L"  \u00B7  ";
        cyr += albumA;
    }
    std::wstring nyr = g_meta.newYear;
    if (!g_meta.newAlbum.empty()) {
        if (!nyr.empty()) nyr += L"  \u00B7  ";
        nyr += g_meta.newAlbum;
    }
    const std::wstring lT = TR(L"T\u00EDtulo: ", L"Title: ", L"T\u00EDtol: ");
    const std::wstring lA = TR(L"Int\u00E9rprete: ", L"Artist: ", L"Int\u00E8rpret: ");
    const std::wstring lY = TR(L"A\u00F1o: ", L"Year: ", L"Any: ");
    const bool aUsesOnline =
        (!g_meta.online.title.empty() && MetaTextBad(g_meta.fileTitle)) ||
        (!g_meta.online.artist.empty() && MetaTextBad(g_meta.fileArtist)) ||
        (!g_meta.online.year.empty() && !MetaYearOk(g_meta.fileYear)) ||
        (!g_meta.online.album.empty() && MetaTextBad(g_meta.fileAlbum)) ||
        (!g_meta.online.cover.empty() && CvImageType(g_meta.fileImg) == 0);
    const bool aUsesCard = MetaFieldAFromCard(0) || MetaFieldAFromCard(1);
    DrawLabel(t, fonts.name, ui.readOnly ?
        TR(L"A · Datos de la pista", L"A · Track tags", L"A · Dades de la pista") :
        aUsesCard ?
        TR(L"A · MP3 y tarjeta", L"A · MP3 and card", L"A · MP3 i targeta") :
        aUsesOnline ?
        TR(L"A · MP3 + Internet", L"A · MP3 + Online", L"A · MP3 + Internet") :
        TR(L"A · Etiquetas del MP3", L"A · MP3 tags", L"A · Etiquetes de l’MP3"),
              cx1, M + 102.0f*k, 1, g.pal.white);
    const wchar_t* sourceB = !g_meta.ready ? TR(L"B · Buscando…", L"B · Searching…", L"B · Cercant…") :
        g_meta.fpPct > 0 ? TR(L"B · Huella acústica", L"B · Audio fingerprint", L"B · Empremta acústica") :
        g_meta.online.catalog == MetaCatalog::Apple ? L"B · iTunes" :
        g_meta.online.catalog == MetaCatalog::Deezer ? L"B · Deezer" :
        g_meta.online.catalog == MetaCatalog::MusicBrainz ? L"B · MusicBrainz" :
        TR(L"B · Sin coincidencia", L"B · No match", L"B · Cap coincidència");
    DrawLabel(t, fonts.name, sourceB, cx2, M + 102.0f*k, 1, g.pal.white);
    fieldLine(0, false, MetaFieldAFromCard(0) ?
        TR(L"Título (tarjeta): ", L"Title (card): ", L"Títol (targeta): ") : lT,
        MetaFieldA(0), none, cx1, yText);
    fieldLine(1, false, MetaFieldAFromCard(1) ?
        TR(L"Intérprete (tarjeta): ", L"Artist (card): ", L"Intèrpret (targeta): ") : lA,
        MetaFieldA(1), none, cx1, yText + kMetaFieldStep * k);
    fieldLine(2, false, lY, cyr, none, cx1, yText + 2.0f * kMetaFieldStep * k);

    fieldLine(0, true, lT, g_meta.newTitle, noneNew, cx2, yText);
    fieldLine(1, true, lA, g_meta.newArtist, noneNew, cx2, yText + kMetaFieldStep * k);
    fieldLine(2, true, lY, nyr, noneNew, cx2, yText + 2.0f * kMetaFieldStep * k);

    if (g_meta.fpPct > 0) {

        std::wstring fpl = std::wstring(TR(L"Identificado por la huella de audio \u00B7 ",
                                           L"Identified by audio fingerprint \u00B7 ",
                                           L"Identificat per l’empremta d’\u00E0udio \u00B7 ")) +
                           std::to_wstring(g_meta.fpPct) + L" %";
        DrawLabel(t, fonts.small, fpl, M + kMetaW * 0.5f * k, yText + 66.0f * k, 1, g.pal.white);
    }
    const float by = M + kMetaButtonY * k;
    float alternateX = 0, primaryX = 0;
    MetaButtonX(ui, alternateX, primaryX);
    if (ui.need > 0) {
        const wchar_t* message = nullptr;
        if (ui.canConfirm) {
            message = TR(L"El reproductor no indica la ruta. Confirma el archivo encontrado.",
                         L"The player gave no file path. Confirm the file shown above.",
                         L"El reproductor no indica la ruta. Confirma el fitxer trobat.");
        } else if (ui.need == 2) {
            message = TR(L"Hay varios archivos posibles. Elige el MP3 correcto.",
                         L"Several files match. Choose the correct MP3.",
                         L"Hi ha diversos fitxers possibles. Tria l’MP3 correcte.");
        } else {
            message = TR(L"Elige un MP3 para poder guardar los datos.",
                         L"Choose an MP3 file to save the tags.",
                         L"Tria un fitxer MP3 per desar les dades.");
        }
        DrawLabel(t, fonts.name, Ellipsize(t, fonts.name, message, (int)((kMetaW - 48.0f) * k)),
                  M + kMetaW * 0.5f * k, M + 375.0f * k, 1, g.pal.white);
        if (ui.canConfirm) {
            MetaDrawButton(cv, t, fonts, M + primaryX * k, by, kMetaButtonHalfWidth * k, kMetaButtonHalfHeight * k,
                           TR(L"Usar este MP3", L"Use this MP3", L"Fes servir aquest MP3"), true, k);
        }
        MetaDrawButton(cv, t, fonts, M + alternateX * k, by, kMetaButtonHalfWidth * k, kMetaButtonHalfHeight * k,
                       ui.canConfirm ? TR(L"Elegir otro…", L"Choose another…", L"Tria’n un altre…") :
                                       TR(L"Elegir el MP3…", L"Choose MP3…", L"Tria l’MP3…"), !ui.canConfirm, k);
    }
    if (ui.undo) {
        std::wstring label = TR(L"Deshacer último cambio", L"Undo last change", L"Desfés l’últim canvi");
        if (g_metaUndoN > 1) label += L" (" + std::to_wstring(g_metaUndoN) + L")";
        MetaDrawButton(cv, t, fonts, M + alternateX * k, by, kMetaButtonHalfWidth * k, kMetaButtonHalfHeight * k,
                       label, false, k);
    }
    if (!ui.readOnly && ui.need == 0 && g_meta.ready && g_metaPathConfirmed && !g_metaCoverNeedsChoice &&
        (!g.media.valid || g_meta.coverTrack == g_thumbTrack))
        MetaDrawButton(cv, t, fonts, M + primaryX * k, by, kMetaButtonHalfWidth * k, kMetaButtonHalfHeight * k,
                       TR(L"Incrustar", L"Embed", L"Incrustar"), true, k);

    if (ui.readOnly)
        MetaDrawButton(cv, t, fonts, M + kMetaW * 0.5f * k, by, kMetaButtonHalfWidth * k, kMetaButtonHalfHeight * k,
                       TR(L"Cerrar", L"Close", L"Tanca"), false, k);
    memcpy(g_dibOut.bits, cv.px.data(), (size_t)W * (size_t)H * 4);
    POINT src = {0, 0};
    SIZE sz = {W, H};
    BLENDFUNCTION bf;
    memset(&bf, 0, sizeof(bf));
    bf.BlendOp = AC_SRC_OVER;
    bf.SourceConstantAlpha = 255;
    bf.AlphaFormat = AC_SRC_ALPHA;
    UpdateLayeredWindow(g_metaWin, nullptr, nullptr, &sz, g_dibOut.dc, &src, 0, &bf, ULW_ALPHA);
}

static void MetaCoverZones(float& ax, float& bx, float& cy, float& half) {
    float colW = (kMetaW - 36.0f) / 2.0f;
    const float coverSz = kMetaCoverSize;
    float off = colW * 0.5f - coverSz * 0.5f;
    ax = 18.0f + off + coverSz * 0.5f;
    bx = 18.0f + colW + off + coverSz * 0.5f;
    cy = kMetaCoverTop + coverSz * 0.5f;
    half = coverSz * 0.5f;
}

static int MetaCoverUnder(float ux, float uy) {
    float ax, bx, cy, half;
    MetaCoverZones(ax, bx, cy, half);
    if (fabsf(uy - cy) >= half) return 0;
    if (g_metaBmpCard && fabsf(ux - ax) < half) return 1;
    if (g_metaBmpNew && fabsf(ux - bx) < half) return 2;
    return 0;
}

static LRESULT CALLBACK MetaWndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_MOUSEMOVE: {
            const float k = MetaPanelScale(h);
            const float ux = GET_X_LPARAM(l) / k - 20.0f;
            const float uy = GET_Y_LPARAM(l) / k - 20.0f;
            const bool coverLink = !MetaIsReadOnly() && MetaCardAlternative() && g_metaBmpCard && ux >= 18.0f &&
                ux < kMetaW * 0.5f && uy >= kMetaCoverLabelY && uy < kMetaFieldTop - 2.0f;
            SetCursor(LoadCursorW(nullptr, (coverLink || (!MetaIsReadOnly() && MetaCoverUnder(ux, uy))) ? IDC_HAND : IDC_ARROW));
            return 0;
        }

        case WM_LBUTTONDOWN: {
            const float k = MetaPanelScale(h);
            float M = 20.0f * k;
            int x = GET_X_LPARAM(l), y = GET_Y_LPARAM(l);
            float ux = ((float)x - M) / k, uy = ((float)y - M) / k;

            if (NearPoint(ux, uy, kMetaW - 22.0f, 20.0f, 14.0f)) {
                MetaPanelClose();
                return 0;
            }
            const MetaUi ui = MetaUiState();
            if (ui.readOnly) {
                if (fabsf(uy - kMetaButtonY) <= kMetaButtonHalfHeight &&
                    fabsf(ux - kMetaW * 0.5f) <= kMetaButtonHalfWidth) MetaPanelClose();
                return 0;
            }
            float alternateX = 0, primaryX = 0;
            MetaButtonX(ui, alternateX, primaryX);
            if (fabsf(uy - kMetaButtonY) <= kMetaButtonHalfHeight) {
                if (fabsf(ux - primaryX) <= kMetaButtonHalfWidth) {
                    if (ui.canConfirm) { MetaConfirmCandidate(); return 0; }
                    if (ui.need == 0 && g_meta.ready && !g_metaCoverNeedsChoice) { MetaPanelApply(); return 0; }
                }
                if (fabsf(ux - alternateX) <= kMetaButtonHalfWidth) {
                    if (ui.need > 0) { MetaPanelPickFileAsync(); return 0; }
                    if (ui.undo) { UndoLastChange(); return 0; }
                }
            }

            if (ui.need == 0 && !g_meta.file.empty() && uy >= 40.0f && uy <= 64.0f &&
                ux >= kMetaW - 150.0f && ux <= kMetaW - 12.0f) {
                MetaPanelPickFileAsync();
                return 0;
            }
            if (MetaCardAlternative() && g_metaBmpCard && ux >= 18.0f && ux < kMetaW * 0.5f &&
                uy >= kMetaCoverLabelY && uy < kMetaFieldTop - 2.0f) {
                g_metaPreferCardCover = g_metaPreviewA != g_meta.cardImg;
                MetaPanelFill();
                if (g_metaBmpCard) ChooseFound(false);
                else MetaPanelPaint();
                return 0;
            }

            {
                const float colWu = (kMetaW - 36.0f) / 2.0f;
                for (int f = 0; f < 3; f++) {
                    const float top = kMetaFieldTop + kMetaFieldStep * (float)f - 2.0f;
                    if (uy >= top && uy <= top + kMetaFieldStep && ux >= 18.0f && ux <= 18.0f + 2.0f * colWu) {
                        const int col = (ux < 18.0f + colWu) ? 0 : 1;
                        const std::wstring& v = col ? MetaFieldB(f) : MetaFieldA(f);
                        if (g_meta.ready && MetaFieldOk(f, v)) {
                            g_metaTouched[f] = true;
                            g_metaPickV[f] = col;
                            MetaPanelPaint();
                        }
                        return 0;
                    }
                }
            }

            {
                int which = MetaCoverUnder(ux, uy);
                if (which == 1) { ChooseFound(false); return 0; }
                if (which == 2) { ChooseFound(true);  return 0; }
            }

            if (uy < 40.0f) {
                ReleaseCapture();
                SendMessageW(h, WM_NCLBUTTONDOWN, HTCAPTION, 0);
            }
            return 0;
        }
        case WM_CLOSE:
            MetaPanelClose();
            return 0;
    }
    return DefWindowProcW(h, m, w, l);
}

static void MetaPanelOpen() {
    if (g_metaWin && IsWindowVisible(g_metaWin)) {
        SetForegroundWindow(g_metaWin);
        return;
    }
    const bool offline = !g.media.valid;
    if (!offline && g.media.title.empty()) {
        ShowNotice(TR(L"Multimedia", L"Media", L"Multimèdia"),
                   TR(L"El reproductor todavía no ha facilitado el título.",
                      L"The player has not supplied a title yet.",
                      L"El reproductor encara no ha facilitat el títol."));
        return;
    }
    if (offline && (g_meta.path.empty() || !g_meta.ready)) {
        ShowNotice(TR(L"Multimedia", L"Media", L"Multim\u00E8dia"),
                   TR(L"No hay una ficha MP3 pendiente. Abre primero la ficha con el reproductor.",
                      L"No pending MP3 metadata. Open its panel while the player is running first.",
                      L"No hi ha cap fitxa MP3 pendent. Obre-la primer amb el reproductor."));
        return;
    }
    for (int i = 0; i < 3; i++) g_metaTouched[i] = false;
    InterlockedExchange(&g_metaUseFound, 0);
    g_metaPreferCardCover = false;
    g_metaCoverNeedsChoice = false;
    if (!g_metaWin) {
        HWND parent = g.cards[CARD_MEDIA].win ? g.cards[CARD_MEDIA].win : GetShellWindow();
        const float k = MetaPanelScale(parent);
        int W = (int)ceilf(kMetaW * k + 40.0f * k);
        int H = (int)ceilf(kMetaH * k + 40.0f * k);
        MONITORINFO monitor = {};
        monitor.cbSize = sizeof(monitor);
        RECT work = {0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
        if (GetMonitorInfoW(MonitorFromWindow(parent, MONITOR_DEFAULTTONEAREST), &monitor))
            work = monitor.rcWork;
        const int x = std::max((int)work.left + 8, (int)work.right - W - 32);
        const int y = std::max((int)work.top + 8, std::min((int)work.top + 80, (int)work.bottom - H - 8));
        g_metaWin = CreateWindowExW(WS_EX_TOOLWINDOW | WS_EX_LAYERED, kMetaClass, L"",
                                    WS_POPUP, x, y, W, H, nullptr, nullptr, GetModuleHandleW(nullptr),
                                    nullptr);
        if (!g_metaWin) {
            Wh_Log(L"Metadatos: no se pudo crear la ventana (%lu)", GetLastError());
            return;
        }
    }
    g_meta.live = true;
    if (!offline) { MetaPanelKick(); MetaRememberCardCover(); }

    MetaPanelFill();
    MetaPanelPaint();
    ShowWindow(g_metaWin, SW_SHOW);
    SetForegroundWindow(g_metaWin);
    Wh_Log(L"Metadatos: ventana abierta para '%s'%s", offline ? g_meta.forTitle.c_str() : g.media.title.c_str(),
           offline ? L" (reproductor cerrado)" : L"");
}

struct MetaPanelJob {
    bool online = false;
    std::wstring artist, title, path;

    std::wstring idWant;
    CvFileId mediaId;
    std::vector<std::wstring> dirs;
    int gen = 0;
    int dur = 0;
    bool readOnly = false;
};
// Resolve the file and proposals for the two-column editor using a track snapshot.
static DWORD WINAPI MetaPanelThread(LPVOID pv) {
    MetaPanelJob* j = (MetaPanelJob*)pv;
    std::wstring artist = j->artist, title = j->title;
    std::wstring jobPath = j->path, idWant = j->idWant;
    const bool allowOnline = j->online;
    const bool noReportedPath = j->path.empty() && !j->readOnly;
    CvFileId mediaId = j->mediaId;
    std::vector<std::wstring> jobDirs = j->dirs;
    int jobGen = j->gen;
    int dur = j->dur;
    bool ambiguous = false;
    bool pathConfirmed = false;
    delete j;
    if (g_stop) return 0;

    std::wstring path;
    std::vector<BYTE> haveImg;
    std::wstring haveTitle, haveArtist, haveYear, haveAlbum;
    unsigned long long sourceSize = 0, sourceTime = 0;
    CvFileId sourceId;
    bool readable = false;
    {

        path = jobPath;
        if (!path.empty()) pathConfirmed = true;
        if (path.empty() && noReportedPath) {
            std::vector<std::wstring> dirs = jobDirs;
            if (dirs.empty()) {
                wchar_t up[MAX_PATH];
                DWORD n = GetEnvironmentVariableW(L"USERPROFILE", up, MAX_PATH);
                if (n > 0 && n < MAX_PATH) dirs.push_back(std::wstring(up) + L"\\Music");
            }

            if (!idWant.empty()) {
                for (size_t di = 0; di < dirs.size() && path.empty(); di++) {
                    std::vector<std::wstring> files;
                    CvListMp3(dirs[di], 0, files);
                    for (size_t fi = 0; fi < files.size(); fi++) {
                        if (CvIdTagOf(files[fi]) == idWant) {
                            Wh_Log(L"Metadatos: localizado por su DNI: '%s'", files[fi].c_str());
                            path = files[fi];
                            pathConfirmed = true;
                            break;
                        }
                    }
                }
            }
            int budget = 20000;
            ULONGLONG deadline = GetTickCount64() + 5000;
            std::vector<CvCand> cands;
            for (size_t di = 0; path.empty() && di < dirs.size() && budget > 0 && GetTickCount64() < deadline; di++)
                CvCollectMp3(dirs[di], CvNorm(CvCoreTitle(title)), title, artist, 0, budget, deadline,
                             cands);

            if (path.empty() && cands.empty()) {
                std::wstring base = CvCoreTitle(title);
                if (!base.empty() && CvNorm(base) != CvNorm(title)) {
                    Wh_Log(L"Empotrar: sin resultado con el titulo completo; se prueba con '%s'",
                           base.c_str());
                    for (size_t di = 0; path.empty() && di < dirs.size() && budget > 0 && GetTickCount64() < deadline; di++)
                        CvCollectMp3(dirs[di], CvNorm(base), base, artist, 0, budget, deadline, cands);
                }
            }

            if (mediaId.ok) {
                for (size_t ci = 0; ci < cands.size(); ci++) {
                    CvFileId fid;
                    if (CvFileIdOf(cands[ci].path, fid) && fid.Same(mediaId)) {
                        Wh_Log(L"Metadatos: identificado por su DNI: '%s'", cands[ci].path.c_str());
                        path = cands[ci].path;
                        pathConfirmed = true;
                        break;
                    }
                }
            }
            if (path.empty() && cands.size() > 1) ambiguous = true;
            if (path.empty() && cands.size() == 1) path = cands.front().path;
        }
        if (!path.empty()) {
            CvFileStamp(path, sourceSize, sourceTime);
            HANDLE h = CreateFileW(path.c_str(), GENERIC_READ,
                                   FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                                   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
            if (h != INVALID_HANDLE_VALUE) {
                if (CvMutationIdentityFromHandle(h, sourceId)) {
                    if (CvIsMp3(path)) {
                        Id3Info info;
                        std::vector<BYTE> tag;
                        if (CvReadTag(h, info, tag)) {
                            readable = !info.unsupported;
                            haveTitle = info.title;
                            haveArtist = info.artist;
                            haveYear = info.year;
                            haveAlbum = info.album;
                            if (info.hasApic && info.apicBytes > 0) CvReadApic(h, info, haveImg);
                        }
                    } else if (const auto format = LocalTagFormat(path); format != LocalAudioTags::Unsupported) {
                        FileMeta native;
                        readable = ReadLocalAudioTags(h, format, native, true);
                        if (readable) {
                            haveTitle = std::move(native.title);
                            haveArtist = std::move(native.artist);
                            haveYear = std::move(native.year);
                            haveAlbum = std::move(native.album);
                            haveImg = std::move(native.cover);
                        }
                    }
                }
                CloseHandle(h);
            }
        }
    }
    if (g_stop) return 0;

    MetaOnlineProposal online;
    std::vector<BYTE> newImg;
    std::wstring qT = title.empty() ? haveTitle : title;
    std::wstring qA = artist.empty() ? haveArtist : artist;
    if (qA.empty()) {
        std::wstring parsedArtist, parsedTitle;
        CvSplitQuery(qA, qT, parsedArtist, parsedTitle);
        if (!CvNoArtist(parsedArtist) && !parsedTitle.empty()) {
            qA = std::move(parsedArtist);
            qT = std::move(parsedTitle);
        }
    }
    if (CvNoArtist(qA) && pathConfirmed && !path.empty()) {
        const size_t slash = path.find_last_of(L"\\/");
        const auto name = slash == std::wstring::npos ? path : path.substr(slash + 1);
        CvSplitQuery(L"", name, qA, qT);
    }
    const int fileDur = sourceId.ok && CvIsMp3(path) ? CvMp3Duration(path) : 0;
    FpResult acoustic;
    const bool acousticMatch = CvIsMp3(path) && sourceId.ok && FpEnabled() &&
                               FpIdentify(path, acoustic);
    if (allowOnline && !g_stop) {
        const int duration = pathConfirmed && fileDur > 1 ? fileDur : dur;
        std::wstring fileKey;
        if (pathConfirmed && sourceId.ok)
            fileKey = CvKeyFor(path, qA, qT) + L":" + std::to_wstring(sourceSize) + L":" + std::to_wstring(sourceTime);
        if (!qT.empty() && !CvNoArtist(qA)) online = MetaLookupCatalogs(qA, qT, duration, fileKey);
        if (online.title.empty() && pathConfirmed && !haveTitle.empty() && !CvNoArtist(haveArtist) &&
            (!CvCoverTitleExact(haveTitle, qT) || !CvCoverArtistExact(haveArtist, qA)))
            online = MetaLookupCatalogs(haveArtist, haveTitle, duration, fileKey);
    }
    if (acousticMatch && allowOnline) {
        const auto dir = CvCacheDir();
        const auto art = dir.empty() || acoustic.mbid.empty() ? std::wstring() :
            dir + L"\\acoustic-" + std::to_wstring(CvStrHash(acoustic.mbid)) + L".img";
        if (art.empty() || !CvReadFile(art, newImg, 4u << 20) || !CvImageType(newImg)) {
            newImg.clear();
            if (FpFetchCover(acoustic, newImg)) {
                if (!art.empty()) CvWriteFile(art, newImg.data(), newImg.size());
            } else {
                const std::wstring key = CvKeyFor(path, acoustic.artist, acoustic.title) + L"_audio";
                if (!CvGetCover(key, acoustic.artist, acoustic.title, true, newImg)) newImg.clear();
            }
        }
    } else if (!acousticMatch) {
        newImg = online.cover;
    }
    if (CvImageType(newImg) == 0) newImg.clear();
    if (g_stop) return 0;

    unsigned long long size = 0, time = 0;
    if (!path.empty() && (!readable || !sourceId.ok || !CvFileStamp(path, size, time) ||
        size != sourceSize || time != sourceTime || !CvMutationIdentityStillMatches(path, sourceId))) {
        pathConfirmed = false;
        sourceId = {};
        if (!CvIsMp3(path)) {
            haveTitle.clear(); haveArtist.clear(); haveYear.clear(); haveAlbum.clear(); haveImg.clear();
        }
    }

    Wh_Log(L"Metadatos: ficha lista para '%s' (archivo '%s', portada nueva %u bytes)", title.c_str(),
           path.c_str(), (unsigned)newImg.size());
    MetaPanelResult* res = new MetaPanelResult();
    res->gen = jobGen;
    res->dur = dur > 1 ? dur : fileDur;
    res->ambiguous = ambiguous;
    res->fpPct = acousticMatch ? acoustic.scorePct : 0;
    res->size = sourceSize;
    res->time = sourceTime;
    res->fileId = sourceId;
    res->newTitle = acousticMatch ? acoustic.title : online.title;
    res->newArtist = acousticMatch ? acoustic.artist : online.artist;
    res->newYear = acousticMatch ? acoustic.year : online.year;
    res->newAlbum = acousticMatch ? acoustic.album : online.album;
    res->online = std::move(online);
    res->path = path;
    res->fileTitle = haveTitle;
    res->fileArtist = haveArtist;
    res->fileYear = haveYear;
    res->fileAlbum = haveAlbum;
    res->fileImg.swap(haveImg);
    res->pathConfirmed = pathConfirmed;
    res->newImg.swap(newImg);
    if (g_stop || !PostUi(WM_APP_PANEL, 0, (LPARAM)res)) delete res;
    return 0;
}

static void OnMetaPanelResult(MetaPanelResult* r) {
    if (r->gen == g_metaGen) {
        Wh_Log(L"Metadatos: B recibida; gen=%d; titulo=%d artista=%d anio=%d portada=%u score=%d",
               r->gen, !r->newTitle.empty(), !r->newArtist.empty(), !r->newYear.empty(),
               (unsigned)r->newImg.size(), r->fpPct);
        g_metaAmbiguous = r->ambiguous;
        g_metaPathConfirmed = r->pathConfirmed;
        std::wstring fileName;
        if (!r->path.empty()) {
            size_t sl = r->path.find_last_of(L"\\/");
            fileName = (sl == std::wstring::npos) ? r->path : r->path.substr(sl + 1);
        }
        {
            SrwGuard lk(&g_metaLock);
            g_meta.path = r->path;
            g_meta.fileTitle = r->fileTitle;
            g_meta.fileArtist = r->fileArtist;
            g_meta.fileYear = r->fileYear;
            g_meta.fileAlbum = r->fileAlbum;
            g_meta.fileImg.swap(r->fileImg);
            g_meta.size = r->size;
            g_meta.time = r->time;
            g_meta.fileId = r->fileId;
            g_meta.online = std::move(r->online);
            g_meta.file = fileName;
            g_meta.newTitle = r->newTitle;
            g_meta.newArtist = r->newArtist;
            g_meta.newYear = r->newYear;
            g_meta.newAlbum = r->newAlbum;
            g_meta.newImg.swap(r->newImg);
            g_meta.dur = r->dur;
            if (r->pathConfirmed && r->dur > 1 && g.media.valid && g.media.dur <= 1.0 &&
                g_meta.coverTrack == g_thumbTrack)
                g_mediaFileDuration = r->dur;
            g_meta.fpPct = r->fpPct;
            g_meta.loading = false;
            g_meta.ready = true;
        }
        if (r->pathConfirmed && !CvIsMp3(r->path) && g.media.valid &&
            _wcsicmp(r->path.c_str(), g.media.path.c_str()) == 0) {
            auto& file = g.fileMeta;
            file.ok = true;
            file.path = r->path;
            file.title = r->fileTitle;
            file.artist = r->fileArtist;
            file.year = r->fileYear;
            file.album = r->fileAlbum;
            file.coverOk = !g_meta.fileImg.empty();
            file.titleOk = !file.title.empty();
            file.artistOk = !file.artist.empty();
            file.albumOk = !file.album.empty();
            file.yearOk = MetaYearOk(file.year);
            if (file.albumOk) {
                if (!SameMediaAlbum(g.media.album, file.album)) g.media.year.clear();
                g.media.album = file.album;
            }
        }
    } else {
        Wh_Log(L"Metadatos: B descartada por generacion antigua; recibido=%d actual=%d", r->gen, g_metaGen);
    }
    delete r;
    MetaRememberCardCover();
    if (g_metaWin) { MetaPanelFill(); MetaPanelPaint(); }
    g.cards[CARD_MEDIA].dirty = true;
}

static void MetaPanelAutoClose() {
    if (!g_metaWin || !g_meta.live) return;
    std::wstring wa, wt;
    {
        SrwGuard lk(&g_metaLock);
        wa = g_meta.forArtist;
        wt = g_meta.forTitle;
    }
    if (wt.empty()) return;
    if (!g.media.valid || g.media.title.empty()) {

        if (g_meta.path.empty() && !g_meta.loading && !g_meta.ready) MetaPanelClose();
        return;
    }
    bool mismo = CvNorm(g.media.title) == CvNorm(wt) &&
                 (wa.empty() || CvNorm(g.media.artist) == CvNorm(wa));
    if (!mismo) {
        Wh_Log(L"Metadatos: cambio de tema; se cierra la ventana de '%s'", wt.c_str());
        MetaPanelClose();
    }
}

static std::wstring MediaCurrentPath() {

    return g.media.path;
}

// Inspect embedded tags and restore a saved header.
static void RefreshFileMeta(const std::wstring& forcePath) {
    std::wstring p = forcePath.empty() ? MediaCurrentPath() : forcePath;
    FileMeta fm;
    bool have = !p.empty() && ReadFileMeta(p, fm, false);
    if (have && forcePath.empty() && g.media.path.empty()) {

        std::wstring qa, qt;
        CvSplitQuery(g.media.artist, g.media.title, qa, qt);
        if (qt.empty()) qt = CvCleanTitle(g.media.title);
        bool consistent = fm.titleOk && CvSim(fm.title, qt) >= 0.8f &&
                          (qa.empty() || !fm.artistOk || CvSim(fm.artist, qa) >= 0.7f);
        if (!fm.mine && !consistent) have = false;
    }
    FileMeta next = have ? fm : FileMeta();
    const bool changed = g.fileMeta.ok != next.ok || g.fileMeta.path != next.path ||
                         g.fileMeta.title != next.title || g.fileMeta.artist != next.artist ||
                         g.fileMeta.album != next.album || g.fileMeta.year != next.year ||
                         g.fileMeta.titleOk != next.titleOk || g.fileMeta.artistOk != next.artistOk ||
                         g.fileMeta.albumOk != next.albumOk || g.fileMeta.yearOk != next.yearOk ||
                         g.fileMeta.coverOk != next.coverOk || g.fileMeta.mine != next.mine;
    if (changed) {
        g.fileMeta = next;
        if (next.albumOk) {
            if (!SameMediaAlbum(g.media.album, next.album)) g.media.year.clear();
            g.media.album = next.album;
        }
        g.cards[CARD_MEDIA].dirty = true;
    }
}

static void OnEmbedDone(int what) {

    if (what == 3) {
        ShowNotice(TR(L"Multimedia", L"Media", L"Multim\u00E8dia"),
                   TR(L"No se pudo deshacer el cambio.", L"The change could not be undone.",
                      L"No s’ha pogut desfer el canvi."));
        return;
    }
    RefreshFileMeta();
    if (what == 2 || what == 4) {

#if GH_HAVE_THUMB
        g_thumbRef = nullptr;
#endif
        g_thumbFileUsed.clear();
        StartThumbThread();
    } else if (g.fileMeta.ok && g.fileMeta.coverOk && g_thumbFileUsed != g.fileMeta.path && !g.thumbOk) {
        StartThumbThread();
    }
    if (what == 2) {
        if (g_metaWin) MetaPanelClose();
        ShowNotice(TR(L"Multimedia", L"Media", L"Multim\u00E8dia"),
                   TR(L"Cambio deshecho: el MP3 vuelve a su estado anterior.",
                      L"Change undone: the MP3 is back to its previous state.",
                      L"Canvi desfet: l’MP3 torna al seu estat anterior."));
    }
    if (g_metaWin) {
        MetaPanelFill();
        MetaPanelPaint();
    }
}

static void UndoLastChange() {
    MetaMutationUiScope operation;
    if (!operation.active) return;
    const bool useEditor = g_metaWin || !g.media.valid;
    if (useEditor && (!g_meta.ready || !g_metaPathConfirmed)) return;
    std::wstring path = useEditor ? g_meta.path : MediaCurrentPath();
    if (path.empty()) return;

    const auto cancelled = DeferredCancelPendingEmbedFor(path);
    if (cancelled != DeferredCancelResult::Missing) {
        ShowNotice(TR(L"Metadatos MP3", L"MP3 metadata", L"Metadades MP3"), cancelled == DeferredCancelResult::Cancelled ?
            TR(L"Se ha cancelado Incrustar pendiente; el MP3 no se modificó.", L"The queued write was canceled. The MP3 was left intact.", L"S’ha cancel·lat l’escriptura pendent. L’MP3 ha quedat intacte.") :
            TR(L"No se pudo guardar la cancelación; la operación sigue pendiente.", L"Could not save the cancellation. The operation is still pending.", L"No s’ha pogut desar la cancel·lació. L’operació continua pendent."));
        return;
    }
    if (!CvUndoExists(path) || !CvUndoPreflight(path)) {
        ShowNotice(TR(L"Metadatos MP3", L"MP3 metadata", L"Metadades MP3"), TR(L"No hay un respaldo válido para deshacer.", L"There is no valid backup for Undo.", L"No hi ha cap còpia vàlida per a Desfer."));
        return;
    }
    unsigned long long size = 0, time = 0;
    CvFileId fileId;
    if (!CvIsMp3(path) || !CvFileStamp(path, size, time) || !CvMutationIdentityOfPath(path, fileId)) {
        ShowNotice(TR(L"Metadatos MP3", L"MP3 metadata", L"Metadades MP3"), TR(L"No se pudo identificar el MP3 para deshacer el cambio.", L"Could not identify the MP3 for Undo.", L"No s’ha pogut identificar l’MP3 per desfer el canvi."));
        return;
    }
    DeferredMp3Op op;
    op.undo = true; op.fileId = fileId; op.path = path; op.size = size; op.time = time;
    if (!DeferredQueue(std::move(op))) {
        ShowNotice(TR(L"Metadatos MP3", L"MP3 metadata", L"Metadades MP3"), TR(L"No se pudo poner la restauración en cola. Comprueba el espacio y las operaciones pendientes.", L"Could not queue Undo. Check available storage and pending operations.", L"No s’ha pogut afegir Desfer a la cua. Comprova l’espai i les operacions pendents."));
        return;
    }
    Wh_Log(L"MP3PEND: DESHACER guardado en disco; pendientes=%d; MP3 intacto", DeferredCount());
    DeferredNoticeQueued(true);
}

static void MetaPanelKick(bool force) {
    if (g.media.title.empty() || g_stop) return;
    static std::wstring last;
    std::wstring key = g.media.artist + L"\x1" + g.media.title + L"\x1" + MediaCurrentPath() +
                       L"\x1" + std::to_wstring(g_thumbTrack);
    if (!force && key == last && (g_meta.ready || g_meta.loading)) return;
    last = key;
    const MediaInfo card = MediaCardInfo();
    {
        SrwGuard lk(&g_metaLock);
        g_meta.ready = false;
        g_meta.loading = true;
        g_meta.path.clear();
        g_meta.file.clear();
        g_meta.fileTitle.clear(); g_meta.fileArtist.clear(); g_meta.fileYear.clear();
        g_meta.fileAlbum.clear(); g_meta.fileImg.clear();
        g_meta.cardImg.clear();
        g_meta.cardTitle = card.title;
        g_meta.cardArtist = card.artist;
        g_meta.cardPixels.clear();
        g_meta.cardSide = 0;
        g_meta.coverTrack = g_thumbTrack;
        g_meta.newTitle.clear(); g_meta.newArtist.clear(); g_meta.newYear.clear();
        g_meta.newAlbum.clear(); g_meta.newImg.clear();
        g_meta.online = {};
        g_meta.fpPct = 0;
        g_meta.forArtist = g.media.artist;
        g_meta.forTitle = g.media.title;
    }
    g_metaGen++;
    g_metaPathConfirmed = false;
    for (auto& touched : g_metaTouched) touched = false;
    InterlockedExchange(&g_metaUseFound, 0);
    g_metaPreferCardCover = false;
    g_metaCoverNeedsChoice = false;
    MetaRememberCardCover();
    if (g_metaWin) { MetaPanelFill(); MetaPanelPaint(); }
    MetaPanelJob* j = new MetaPanelJob();
    j->artist = g.media.artist;
    j->title = g.media.title;
    j->path = MediaCurrentPath();
    j->readOnly = KnownReadOnlyAudio(j->path.empty() ? g.media.file : j->path);
    j->online = g.onlineCovers && (!CvIsBrowserSession() || !j->path.empty());
    j->idWant = g_mediaIdWant;
    j->mediaId = g.media.id;
    j->dirs = g.musicDirs;
    j->gen = g_metaGen;

    j->dur = (int)(g.media.dur + 0.5);
    if (j->dur <= 0) j->dur = (int)InterlockedCompareExchange(&g_mediaDurSec, 0, 0);
    if (!StartBgThread(MetaPanelThread, j)) {
        delete j;
        g_meta.loading = false;
    }
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static HWND g_editWin = nullptr;
static HFONT g_editFont = nullptr, g_editTitleFont = nullptr;
enum AgendaControl {
    kAgendaSave = 1, kAgendaCancel = 2, kAgendaText = 100,
    kAgendaTitle, kAgendaFormat, kAgendaExample, kAgendaStatus
};

static COLORREF AgendaBackground() { return g.pal.light ? RGB(250, 250, 253) : RGB(18, 23, 37); }
static COLORREF AgendaSurface() { return g.pal.light ? RGB(232, 238, 247) : RGB(34, 42, 61); }
static COLORREF AgendaInk() { return g.pal.light ? RGB(28, 39, 59) : RGB(231, 240, 253); }
static COLORREF AgendaAccent() { return g.pal.light ? RGB(132, 77, 5) : RGB(255, 198, 103); }
static int AgendaPx(HWND h, int size) {
    const UINT dpi = GetDpiForWindow(h);
    return MulDiv(size, dpi ? dpi : 96, 96);
}
static const wchar_t* AgendaShortcutText() {
    return TR(L"Ctrl+Intro guarda · Esc cancela", L"Ctrl+Enter saves · Esc cancels",
              L"Ctrl+Retorn desa · Esc cancel·la");
}

static bool SaveAgendaEditor(HWND h) {
    HWND edit = GetDlgItem(h, kAgendaText);
    const int length = GetWindowTextLengthW(edit);
    std::wstring text((size_t)length + 1, wchar_t{});
    const int copied = GetWindowTextW(edit, text.data(), length + 1);
    if (copied != length) return false;
    text.resize((size_t)copied);
    const auto lines = SplitLines(text);
    for (size_t i = 0; i < lines.size(); ++i) {
        const auto line = Trim(lines[i]);
        if (line.empty() || line.front() == L'#') continue;
        Deadline entry;
        if (ParseDeadline(line, entry)) continue;
        const auto message = std::wstring(TR(L"Revisa la fecha o la hora de la línea ", L"Check the date or time on line ",
                                             L"Revisa la data o l’hora de la línia ")) + std::to_wstring(i + 1);
        SetDlgItemTextW(h, kAgendaStatus, message.c_str());

        size_t offset = 0;
        for (size_t row = 0; row < i; ++row) offset = text.find(L'\n', offset) + 1;
        SendMessageW(edit, EM_SETSEL, offset, offset + lines[i].size());
        SendMessageW(edit, EM_SCROLLCARET, 0, 0);
        SetFocus(edit);
        return false;
    }
    text.erase(std::remove(text.begin(), text.end(), L'\r'), text.end());
    if (!Wh_SetStringValue(L"dlText", text.c_str()) || !Wh_SetIntValue(L"dlOvr", 1)) {
        SetDlgItemTextW(h, kAgendaStatus,
            TR(L"No se pudieron guardar las citas.", L"Could not save the events.", L"No s’han pogut desar les cites."));
        return false;
    }
    LoadLists();
    g.cards[CARD_DEADLINES].dirty = true;
    return true;
}

static void LayoutAgendaEditor(HWND h) {
    RECT rc = {};
    GetClientRect(h, &rc);
    auto px = [h](int n) { return AgendaPx(h, n); };
    const int pad = px(22), width = std::max(1, (int)rc.right - pad * 2);
    MoveWindow(GetDlgItem(h, kAgendaTitle), pad, px(18), width, px(30), TRUE);
    MoveWindow(GetDlgItem(h, kAgendaFormat), pad, px(53), width, px(22), TRUE);
    MoveWindow(GetDlgItem(h, kAgendaExample), pad, px(77), width, px(22), TRUE);
    MoveWindow(GetDlgItem(h, kAgendaText), pad, px(111), width, std::max(px(30), (int)rc.bottom - px(213)), TRUE);
    MoveWindow(GetDlgItem(h, kAgendaStatus), pad, rc.bottom - px(93), width, px(24), TRUE);
    const int button = px(110), y = rc.bottom - px(55);
    MoveWindow(GetDlgItem(h, kAgendaCancel), rc.right - pad - 2 * button - px(8), y, button, px(34), TRUE);
    MoveWindow(GetDlgItem(h, kAgendaSave), rc.right - pad - button, y, button, px(34), TRUE);
}

static LRESULT CALLBACK EditWndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_CREATE: {
            const HINSTANCE instance = GetModuleHandleW(nullptr);
            g_editFont = MakeFont(AgendaPx(h, 15), FW_NORMAL);
            g_editTitleFont = MakeFont(AgendaPx(h, 22), FW_SEMIBOLD);
            auto child = [&](const wchar_t* cls, const wchar_t* text, DWORD style, int id) {
                HWND control = CreateWindowExW(0, cls, text, WS_CHILD | WS_VISIBLE | style,
                    0, 0, 0, 0, h, (HMENU)(INT_PTR)id, instance, nullptr);
                if (control) SendMessageW(control, WM_SETFONT, (WPARAM)(id == kAgendaTitle ? g_editTitleFont : g_editFont), FALSE);
                return control != nullptr;
            };
            if (!child(L"STATIC", TR(L"Citas locales", L"Local events", L"Cites locals"), SS_NOPREFIX, kAgendaTitle) ||
                !child(L"STATIC", TR(L"DD/MM/AAAA [HH:MM] Texto [@repetición] [# Lugar]",
                                     L"DD/MM/YYYY [HH:MM] Text [@repeat] [# Place]",
                                     L"DD/MM/AAAA [HH:MM] Text [@repetició] [# Lloc]"), SS_NOPREFIX | SS_ENDELLIPSIS, kAgendaFormat) ||
                !child(L"STATIC", TR(L"Ejemplo · 16/03/2027 07:00 Renovar DNI @anual # Ayuntamiento",
                                     L"Example · 16/03/2027 07:00 Renew passport @yearly # Town hall",
                                     L"Exemple · 16/03/2027 07:00 Renova el DNI @anual # Ajuntament"),
                       SS_NOPREFIX | SS_ENDELLIPSIS, kAgendaExample) ||
                !child(L"EDIT", L"", WS_TABSTOP | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN, kAgendaText) ||
                !child(L"STATIC", AgendaShortcutText(), SS_NOPREFIX, kAgendaStatus) ||
                !child(L"BUTTON", TR(L"Cancelar", L"Cancel", L"Cancel·la"), BS_OWNERDRAW | WS_TABSTOP, kAgendaCancel) ||
                !child(L"BUTTON", TR(L"Guardar", L"Save", L"Desa"), BS_OWNERDRAW | WS_TABSTOP, kAgendaSave)) return -1;
            const int inset = AgendaPx(h, 10);
            SendDlgItemMessageW(h, kAgendaText, EM_SETMARGINS, EC_LEFTMARGIN | EC_RIGHTMARGIN, MAKELPARAM(inset, inset));
            SendDlgItemMessageW(h, kAgendaText, EM_SETLIMITTEXT, 16382, 0);
            LayoutAgendaEditor(h);
            return 0;
        }
        case WM_GETMINMAXINFO: {
            auto* limits = reinterpret_cast<MINMAXINFO*>(l);
            limits->ptMinTrackSize.x = AgendaPx(h, 464);
            limits->ptMinTrackSize.y = AgendaPx(h, 340);
            return 0;
        }
        case WM_SIZE:
            LayoutAgendaEditor(h);
            return 0;
        case WM_ERASEBKGND:
            return 1;
        case WM_PAINT: {
            PAINTSTRUCT paint;
            HDC dc = BeginPaint(h, &paint);
            RECT rc;
            GetClientRect(h, &rc);
            HBRUSH brush = CreateSolidBrush(AgendaBackground());
            FillRect(dc, &rc, brush);
            DeleteObject(brush);
            rc.bottom = AgendaPx(h, 3);
            brush = CreateSolidBrush(AgendaAccent());
            FillRect(dc, &rc, brush);
            DeleteObject(brush);
            EndPaint(h, &paint);
            return 0;
        }
        case WM_CTLCOLOREDIT: {
            HDC dc = reinterpret_cast<HDC>(w);
            SetTextColor(dc, AgendaInk());
            SetBkColor(dc, AgendaSurface());
            SetDCBrushColor(dc, AgendaSurface());
            return reinterpret_cast<LRESULT>(GetStockObject(DC_BRUSH));
        }
        case WM_CTLCOLORSTATIC: {
            HDC dc = reinterpret_cast<HDC>(w);
            const int id = GetDlgCtrlID(reinterpret_cast<HWND>(l));
            SetBkColor(dc, AgendaBackground());
            SetDCBrushColor(dc, AgendaBackground());
            SetTextColor(dc, id == kAgendaTitle || id == kAgendaStatus ? AgendaAccent() : AgendaInk());
            return reinterpret_cast<LRESULT>(GetStockObject(DC_BRUSH));
        }
        case WM_DRAWITEM: {
            const auto& button = *reinterpret_cast<DRAWITEMSTRUCT*>(l);
            const bool save = button.CtlID == kAgendaSave;
            if (!save && button.CtlID != kAgendaCancel) break;
            HBRUSH brush = CreateSolidBrush(save ? RGB(146, 83, 9) : AgendaSurface());
            HPEN pen = CreatePen(PS_SOLID, 1, (button.itemState & ODS_SELECTED) ? AgendaInk() : AgendaAccent());
            HGDIOBJ oldBrush = SelectObject(button.hDC, brush), oldPen = SelectObject(button.hDC, pen);
            RECT rc = button.rcItem;
            const int corner = AgendaPx(h, 15);
            RoundRect(button.hDC, rc.left, rc.top, rc.right, rc.bottom, corner, corner);
            SelectObject(button.hDC, oldBrush);
            SelectObject(button.hDC, oldPen);
            DeleteObject(brush);
            DeleteObject(pen);
            SetBkMode(button.hDC, TRANSPARENT);
            SetTextColor(button.hDC, save ? RGB(255, 255, 255) : AgendaInk());
            HGDIOBJ oldFont = SelectObject(button.hDC, g_editFont);
            wchar_t label[40] = {};
            GetWindowTextW(button.hwndItem, label, _countof(label));
            DrawTextW(button.hDC, label, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOPREFIX);
            SelectObject(button.hDC, oldFont);
            if (button.itemState & ODS_FOCUS) {
                InflateRect(&rc, -4, -4);
                DrawFocusRect(button.hDC, &rc);
            }
            return TRUE;
        }
        case WM_COMMAND:
            if (LOWORD(w) == kAgendaCancel) DestroyWindow(h);
            else if (LOWORD(w) == kAgendaSave && SaveAgendaEditor(h)) DestroyWindow(h);
            else if (LOWORD(w) == kAgendaText && HIWORD(w) == EN_CHANGE)
                SetDlgItemTextW(h, kAgendaStatus, AgendaShortcutText());
            return 0;
        case WM_NCDESTROY:
            if (g_editFont) DeleteObject(g_editFont);
            if (g_editTitleFont) DeleteObject(g_editTitleFont);
            g_editFont = g_editTitleFont = nullptr;
            g_editWin = nullptr;
            break;
    }
    return DefWindowProcW(h, m, w, l);
}

static void OpenAgendaEditor(HWND anchor) {
    if (g_editWin) {
        if (IsIconic(g_editWin)) ShowWindow(g_editWin, SW_RESTORE);
        SetForegroundWindow(g_editWin);
        return;
    }
    MONITORINFO monitor = {};
    monitor.cbSize = sizeof(monitor);
    RECT work = {0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
    if (GetMonitorInfoW(MonitorFromWindow(anchor, MONITOR_DEFAULTTONEAREST), &monitor)) work = monitor.rcWork;
    const int width = std::min((int)(work.right - work.left), AgendaPx(anchor, 690));
    const int height = std::min((int)(work.bottom - work.top), AgendaPx(anchor, 510));
    g_editWin = CreateWindowExW(WS_EX_CONTROLPARENT, kEditClass, TR(L"Editar agenda", L"Edit calendar", L"Edita l’agenda"),
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN, work.left + (work.right - work.left - width) / 2,
        work.top + (work.bottom - work.top - height) / 2, width, height, nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);
    if (!g_editWin) return;
    std::wstring text;
    for (size_t i = 0; i < g.dlRaw.size(); ++i) {
        if (i) text += L"\r\n";
        text += g.dlRaw[i];
    }
    SetDlgItemTextW(g_editWin, kAgendaText, text.c_str());
    ShowWindow(g_editWin, SW_SHOW);
    SetForegroundWindow(g_editWin);
    SetFocus(GetDlgItem(g_editWin, kAgendaText));
}

static HWND g_cardOrderWin = nullptr;
static HFONT g_cardOrderFont = nullptr;
static int g_cardOrderDraft[CARD_COUNT];
enum CardOrderControl {
    kOrderSave = 1, kOrderCancel = 2, kOrderList = 100, kOrderUp, kOrderDown, kOrderReset, kOrderStatus
};

static const wchar_t* CardOrderTitle() {
    return TR(L"Orden de las tarjetas", L"Card order", L"Ordre de les targetes");
}

static void UpdateCardOrderButtons(HWND h) {
    const LRESULT selected = SendDlgItemMessageW(h, kOrderList, LB_GETCURSEL, 0, 0);
    EnableWindow(GetDlgItem(h, kOrderUp), selected > 0);
    EnableWindow(GetDlgItem(h, kOrderDown), selected != LB_ERR && selected < CARD_COUNT - 1);
}

static bool FillCardOrderList(HWND h, int selected) {
    const HWND list = GetDlgItem(h, kOrderList);
    SendMessageW(list, WM_SETREDRAW, FALSE, 0);
    SendMessageW(list, LB_RESETCONTENT, 0, 0);
    bool ok = true;
    for (int id : g_cardOrderDraft) {
        if (SendMessageW(list, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>(CardTitle(id))) < 0) {
            ok = false;
            break;
        }
    }
    if (ok) SendMessageW(list, LB_SETCURSEL, selected, 0);
    SendMessageW(list, WM_SETREDRAW, TRUE, 0);
    InvalidateRect(list, nullptr, TRUE);
    UpdateCardOrderButtons(h);
    EnableWindow(GetDlgItem(h, kOrderSave), ok);
    return ok;
}

static void LayoutCardOrderEditor(HWND h) {
    auto px = [h](int n) { return AgendaPx(h, n); };
    RECT rc = {};
    GetClientRect(h, &rc);
    const int left = px(16), buttonW = px(110), gap = px(10);
    const int right = rc.right - left, buttons = right - buttonW;
    const int listY = px(48), buttonH = px(29), footer = rc.bottom - left - buttonH;
    MoveWindow(GetDlgItem(h, kOrderStatus), left, px(16), right - left, px(24), TRUE);
    MoveWindow(GetDlgItem(h, kOrderList), left, listY, buttons - gap - left, footer - gap - listY, TRUE);
    MoveWindow(GetDlgItem(h, kOrderUp), buttons, listY, buttonW, buttonH, TRUE);
    MoveWindow(GetDlgItem(h, kOrderDown), buttons, listY + buttonH + gap, buttonW, buttonH, TRUE);
    MoveWindow(GetDlgItem(h, kOrderReset), buttons, listY + 2 * (buttonH + gap), buttonW, buttonH, TRUE);
    MoveWindow(GetDlgItem(h, kOrderCancel), buttons - buttonW - gap, footer, buttonW, buttonH, TRUE);
    MoveWindow(GetDlgItem(h, kOrderSave), buttons, footer, buttonW, buttonH, TRUE);
}

static LRESULT CALLBACK CardOrderWndProc(HWND h, UINT message, WPARAM w, LPARAM l) {
    switch (message) {
        case WM_CREATE: {
            g_cardOrderFont = MakeFont(AgendaPx(h, 15), FW_NORMAL);
            auto child = [&](const wchar_t* cls, const wchar_t* title, DWORD style, int id) {
                const DWORD ex = id == kOrderList ? WS_EX_CLIENTEDGE : 0;
                HWND ctl = CreateWindowExW(ex, cls, title, WS_VISIBLE | WS_CHILD | style, 0, 0, 0, 0,
                                           h, (HMENU)(INT_PTR)id, GetModuleHandleW(nullptr), nullptr);
                if (ctl && g_cardOrderFont) SendMessageW(ctl, WM_SETFONT, (WPARAM)g_cardOrderFont, FALSE);
                return ctl != nullptr;
            };
            if (!child(L"STATIC", TR(L"Orden de arriba abajo", L"Order from top to bottom",
                                     L"Ordre de dalt a baix"), SS_NOPREFIX, kOrderStatus) ||
                !child(L"LISTBOX", L"", WS_TABSTOP | WS_VSCROLL | LBS_NOTIFY | LBS_NOINTEGRALHEIGHT, kOrderList) ||
                !child(L"BUTTON", TR(L"Subir", L"Move up", L"Puja"), WS_TABSTOP, kOrderUp) ||
                !child(L"BUTTON", TR(L"Bajar", L"Move down", L"Baixa"), WS_TABSTOP, kOrderDown) ||
                !child(L"BUTTON", TR(L"Orden original", L"Default order", L"Ordre original"), WS_TABSTOP, kOrderReset) ||
                !child(L"BUTTON", TR(L"Cancelar", L"Cancel", L"Cancel·la"), WS_TABSTOP, kOrderCancel) ||
                !child(L"BUTTON", TR(L"Guardar", L"Save", L"Desa"), WS_TABSTOP | BS_DEFPUSHBUTTON, kOrderSave))
                return -1;
            LayoutCardOrderEditor(h);
            return 0;
        }
        case WM_SIZE:
            LayoutCardOrderEditor(h);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps = {};
            HDC dc = BeginPaint(h, &ps);
            SetDCBrushColor(dc, AgendaBackground());
            FillRect(dc, &ps.rcPaint, (HBRUSH)GetStockObject(DC_BRUSH));
            EndPaint(h, &ps);
            return 0;
        }
        case WM_CTLCOLORLISTBOX:
        case WM_CTLCOLORSTATIC: {
            HDC dc = reinterpret_cast<HDC>(w);
            const COLORREF bg = message == WM_CTLCOLORLISTBOX ? AgendaSurface() : AgendaBackground();
            SetBkColor(dc, bg);
            SetTextColor(dc, AgendaInk());
            SetDCBrushColor(dc, bg);
            return reinterpret_cast<LRESULT>(GetStockObject(DC_BRUSH));
        }
        case WM_COMMAND:
            switch (LOWORD(w)) {
                case kOrderList:
                    if (HIWORD(w) == LBN_SELCHANGE) UpdateCardOrderButtons(h);
                    return 0;
                case kOrderUp:
                case kOrderDown: {
                    const int row = (int)SendDlgItemMessageW(h, kOrderList, LB_GETCURSEL, 0, 0);
                    const int target = MoveCardInOrder(g_cardOrderDraft, row, LOWORD(w) == kOrderUp ? -1 : 1);
                    if (target != row) FillCardOrderList(h, target);
                    if (!IsWindowEnabled(reinterpret_cast<HWND>(l))) SetFocus(GetDlgItem(h, kOrderList));
                    return 0;
                }
                case kOrderReset:
                    std::copy_n(kDefaultCardOrder, CARD_COUNT, g_cardOrderDraft);
                    FillCardOrderList(h, 0);
                    return 0;
                case kOrderCancel:
                    DestroyWindow(h);
                    return 0;
                case kOrderSave:
                    if (!IsWindowEnabled(GetDlgItem(h, kOrderSave))) return 0;
                    if (!Wh_SetStringValue(L"cardDisplayOrder", EncodeCardOrder(g_cardOrderDraft).c_str())) {
                        SetDlgItemTextW(h, kOrderStatus, TR(L"No se pudo guardar el orden.",
                            L"Could not save the card order.", L"No s’ha pogut desar l’ordre."));
                        return 0;
                    }
                    std::copy_n(g_cardOrderDraft, CARD_COUNT, g_cardOrder);
                    Restack();
                    DestroyWindow(h);
                    return 0;
            }
            break;
        case WM_NCDESTROY:
            if (g_cardOrderFont) DeleteObject(g_cardOrderFont);
            g_cardOrderFont = nullptr;
            g_cardOrderWin = nullptr;
            break;
    }
    return DefWindowProcW(h, message, w, l);
}

// Edit a copy of the saved order and commit it only when the user saves.
static void OpenCardOrderEditor(HWND anchor, int cardId) {
    if (g_cardOrderWin) {
        SetForegroundWindow(g_cardOrderWin);
        return;
    }
    MONITORINFO monitor = {};
    monitor.cbSize = sizeof(monitor);
    RECT work = {0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
    if (GetMonitorInfoW(MonitorFromWindow(anchor, MONITOR_DEFAULTTONEAREST), &monitor)) work = monitor.rcWork;
    const int width = std::min((int)(work.right - work.left), AgendaPx(anchor, 420));
    const int height = std::min((int)(work.bottom - work.top), AgendaPx(anchor, 295));
    std::copy_n(g_cardOrder, CARD_COUNT, g_cardOrderDraft);
    g_cardOrderWin = CreateWindowExW(WS_EX_CONTROLPARENT | WS_EX_TOOLWINDOW, kCardOrderClass, CardOrderTitle(),
        WS_CAPTION | WS_SYSMENU | WS_CLIPCHILDREN,
        work.left + (work.right - work.left - width) / 2, work.top + (work.bottom - work.top - height) / 2,
        width, height, nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);
    if (!g_cardOrderWin) return;
    const int selected = (int)(std::find(g_cardOrderDraft, g_cardOrderDraft + CARD_COUNT, cardId) - g_cardOrderDraft);
    FillCardOrderList(g_cardOrderWin, selected < CARD_COUNT ? selected : 0);
    ShowWindow(g_cardOrderWin, SW_SHOW);
    SetForegroundWindow(g_cardOrderWin);
    SetFocus(GetDlgItem(g_cardOrderWin, kOrderList));
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static HWND g_stickyHost = nullptr;
static HWND g_stickyEdit = nullptr;
static WNDPROC g_oldEditProc = nullptr;
static HFONT g_stickyFont = nullptr;
static HBRUSH g_paperBrush = nullptr;
static const UINT WM_STICKY_CLOSE = WM_APP + 10;

static bool StickySave() {
    if (!g_stickyEdit) return true;
    int len = GetWindowTextLengthW(g_stickyEdit);
    std::vector<wchar_t> buf((size_t)len + 2, 0);
    GetWindowTextW(g_stickyEdit, buf.data(), len + 1);
    std::wstring o;
    for (const wchar_t* p = buf.data(); *p; p++) {
        if (*p != L'\r') o += *p;
    }
    if (o == g.stickyText) return true;
    if (!Wh_SetStringValue(L"stickyText", o.c_str())) {
        ShowNotice(TR(L"Notas", L"Notes", L"Notes"),
                   TR(L"No se pudo guardar el post-it.", L"Could not save the note.", L"No s’ha pogut desar la nota."));
        return false;
    }
    g.stickyText = o;
    Wh_SetIntValue(L"stickyInit", 1);
    if (Wh_SetStringValue(L"stickyUndo", L"")) {
        g.stickyUndo.clear();
        g.stickyCanUndo = false;
    }
    return true;
}

static void StickyClose() {
    if (!g_stickyHost) return;
    if (!StickySave()) return;
    HWND h = g_stickyHost;
    g_stickyHost = nullptr;
    g_stickyEdit = nullptr;
    DestroyWindow(h);
    if (g_stickyFont) {
        DeleteObject(g_stickyFont);
        g_stickyFont = nullptr;
    }
    g.stickyEditing = false;
    Card& c = g.cards[CARD_NOTES];
    c.dirty = true;
    if (c.win && RenderCard(c)) c.dirty = false;
}

static LRESULT CALLBACK StickyEditProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_KEYDOWN:
            if (w == VK_ESCAPE) {
                if (g_stickyHost) PostMessageW(g_stickyHost, WM_STICKY_CLOSE, 0, 0);
                return 0;
            }
            if (w == 'A' && (GetKeyState(VK_CONTROL) & 0x8000)) {
                SendMessageW(h, EM_SETSEL, 0, -1);
                return 0;
            }
            break;
        case WM_CHAR:
            if (w == 1) return 0;
            break;
        case WM_KILLFOCUS: {
            LRESULT r = CallWindowProcW(g_oldEditProc, h, m, w, l);
            if (g_stickyHost) PostMessageW(g_stickyHost, WM_STICKY_CLOSE, 0, 0);
            return r;
        }
    }
    return CallWindowProcW(g_oldEditProc, h, m, w, l);
}

static LRESULT CALLBACK StickyHostProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_CTLCOLOREDIT: {
            HDC dc = (HDC)w;
            SetTextColor(dc, kInkRef);
            SetBkColor(dc, kPaperRef);
            return (LRESULT)g_paperBrush;
        }
        case WM_ERASEBKGND: {
            RECT rc;
            GetClientRect(h, &rc);
            FillRect((HDC)w, &rc, g_paperBrush);
            return 1;
        }
        case WM_COMMAND:

            if (HIWORD(w) == EN_CHANGE) {
                SetTimer(h, 1, 500, nullptr);
            }
            return 0;
        case WM_TIMER:
            if (w == 1) {
                KillTimer(h, 1);
                StickySave();
            }
            return 0;
        case WM_SETFOCUS:
            if (g_stickyEdit) SetFocus(g_stickyEdit);
            return 0;
        case WM_STICKY_CLOSE:
            StickyClose();
            return 0;
    }
    return DefWindowProcW(h, m, w, l);
}

static void OpenStickyEditor(Card* card) {
    if (g_stickyHost || g.collapsed[CARD_NOTES] || !card->win) return;
    g.stickyEditing = true;
    if (!RenderCard(*card)) { g.stickyEditing = false; return; }
    Restack();
    RECT rc;
    if (!GetWindowRect(card->win, &rc)) { g.stickyEditing = false; return; }
    float k = g.kLast;
    int x = rc.left + card->mPx + (int)(18.0f * k);
    int y = rc.top + card->mPx + (int)(kStickyTextTop * k);
    int w = (int)((372.0f - 36.0f) * k);
    int h = card->cardHpx - (int)(kStickyTextTop * k) - (int)(kStickyPad * k);
    if (h < 20) { g.stickyEditing = false; return; }

    HINSTANCE hi = GetModuleHandleW(nullptr);
    g_stickyHost = CreateWindowExW(WS_EX_TOOLWINDOW, kStickyClass, L"", WS_POPUP, x, y, w, h, nullptr, nullptr,
                                   hi, nullptr);
    if (!g_stickyHost) { g.stickyEditing = false; return; }
    g.cards[CARD_NOTES].dirty = true;
    g_stickyEdit = CreateWindowExW(0, L"EDIT", L"",
                                   WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN, 0, 0,
                                   w, h, g_stickyHost, (HMENU)(INT_PTR)100, hi, nullptr);
    if (!g_stickyEdit) {
        DestroyWindow(g_stickyHost);
        g_stickyHost = nullptr;
        g.stickyEditing = false;
        return;
    }

    g_stickyFont = g.stickyText.size() > 100 ? MakeFont((int)(14.0f * k), FW_NORMAL) :
                                             MakeFontFace((int)(15.0f * k), FW_NORMAL, L"Segoe Print");
    SendMessageW(g_stickyEdit, WM_SETFONT, (WPARAM)g_stickyFont, TRUE);
    SendMessageW(g_stickyEdit, EM_SETMARGINS, EC_LEFTMARGIN | EC_RIGHTMARGIN, 0);
    SendMessageW(g_stickyEdit, EM_SETLIMITTEXT, 6000, 0);

    std::wstring txt;
    for (size_t i = 0; i < g.stickyText.size(); i++) {
        if (g.stickyText[i] == L'\n') txt += L"\r\n";
        else txt += g.stickyText[i];
    }
    SetWindowTextW(g_stickyEdit, txt.c_str());
    g_oldEditProc = (WNDPROC)SetWindowLongPtrW(g_stickyEdit, GWLP_WNDPROC, (LONG_PTR)StickyEditProc);

    ShowWindow(g_stickyHost, SW_SHOW);
    SetForegroundWindow(g_stickyHost);
    SetFocus(g_stickyEdit);
    int n = GetWindowTextLengthW(g_stickyEdit);
    SendMessageW(g_stickyEdit, EM_SETSEL, n, n);
}

static void StickyClear() {
    if (g.stickyText.empty()) return;
    if (!Wh_SetStringValue(L"stickyUndo", g.stickyText.c_str()) ||
        !Wh_SetStringValue(L"stickyText", L"")) {
        ShowNotice(TR(L"Notas", L"Notes", L"Notes"), TR(L"No se pudo borrar el post-it.", L"Could not clear the note.", L"No s’ha pogut esborrar la nota."));
        return;
    }
    g.stickyUndo = g.stickyText;
    g.stickyCanUndo = true;
    g.stickyText.clear();
    g.cards[CARD_NOTES].dirty = true;
}

static void StickyUndo() {
    if (!g.stickyCanUndo) return;
    if (!Wh_SetStringValue(L"stickyText", g.stickyUndo.c_str())) {
        ShowNotice(TR(L"Notas", L"Notes", L"Notes"), TR(L"No se pudo recuperar el post-it.", L"Could not restore the note.", L"No s’ha pogut recuperar la nota."));
        return;
    }
    g.stickyText = g.stickyUndo;
    g.stickyCanUndo = false;
    g.stickyUndo.clear();
    Wh_SetStringValue(L"stickyUndo", L"");
    g.cards[CARD_NOTES].dirty = true;
}

static UINT_PTR g_tmrAnim = 0;

static void OnAnimTimer() {
    bool any = false;
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[i];
        if (!c.animating) continue;
        if (!c.win || g.paused) {
            c.animating = false;
            c.dirty = true;
            continue;
        }
        if (RenderCard(c)) c.dirty = false;
        if (c.animating) any = true;
    }
    Restack();
    if (!any && g_tmrAnim) {
        KillTimer(nullptr, g_tmrAnim);
        g_tmrAnim = 0;
    }
}

static void StartFoldAnim(Card* c, bool opening) {
    c->animating = true;
    c->animOpening = opening;
    c->animStart = GetTickCount64();
    if (!g_tmrAnim) g_tmrAnim = SetTimer(nullptr, 0, 16, nullptr);
}

static void ToggleFold(Card* card) {
    const int id = card->id;
    const bool wasFolded = g.collapsed[id] || card->autoFold;
    if (card->autoFold && !g.collapsed[id]) {

        card->autoFold = false;
        g.autoPin[id] = true;
    } else {
        g.collapsed[id] = !g.collapsed[id];
        if (g.collapsed[id]) {
            g.autoPin[id] = false;
            card->autoFold = false;
        }
        wchar_t key[32];
        wsprintfW(key, L"collapsed%d", id);
        Wh_SetIntValue(key, g.collapsed[id] ? 1 : 0);
    }
    const bool nowFolded = g.collapsed[id] || card->autoFold;
    card->bgKey = 0;
    if (id != CARD_NOTES && wasFolded != nowFolded) StartFoldAnim(card, !nowFolded);
    if (RenderCard(*card)) card->dirty = false;
    Restack();
}

static bool AnyCardOpen() {
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[i];
        if (c.win && c.placed && !g.collapsed[i]) return true;
    }
    return false;
}

static void ToggleAllFold() {
    const bool anyOpen = AnyCardOpen();
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[i];
        if (!c.win) continue;
        const bool was = g.collapsed[i] || c.autoFold;
        g.collapsed[i] = anyOpen;
        c.autoFold = false;
        if (anyOpen) g.autoPin[i] = false;
        wchar_t key[32];
        wsprintfW(key, L"collapsed%d", i);
        Wh_SetIntValue(key, anyOpen ? 1 : 0);
        c.bgKey = 0;
        c.dirty = true;
        if (i != CARD_NOTES && was != anyOpen) StartFoldAnim(&c, !anyOpen);
    }
    Restack();
}

static void PomoReset() {
    g.pomoRun = false;
    g.pomoEnd = 0;
    g.pomoStarted = false;
    g.pomoMode = 0;
    g.pomoLeft = g.pomoFocus * 60;
    g.cards[CARD_CLOCK].dirty = true;
}

static bool NearPoint(float ux, float uy, float cx, float cy, float r) {
    return Len2(ux - cx, uy - cy) <= r;
}

static void MediaRebuild() {
    if (g.media.title.empty()) {
        ShowNotice(TR(L"Multimedia", L"Media", L"Multimèdia"),
                   TR(L"No hay ninguna canción sonando.", L"Nothing is playing.",
                      L"No hi ha cap cançó sonant."));
        return;
    }

    g_mxLastQuery.clear();
    StartMetaThread(g.media.title, g.media.artist);
    MetaPanelKick(true);
    g.cards[CARD_MEDIA].dirty = true;
    MetaPanelOpen();
    ShowNotice(TR(L"Multimedia", L"Media", L"Multimèdia"),
               TR(L"Ficha actualizada. Revisa los datos de A y B.",
                  L"Metadata refreshed. Review the tags in A and B.",
                  L"Fitxa actualitzada. Revisa les dades d’A i B."));
}

static int MediaTransportAt(float x, float y) {
    for (int i = 0; i < 3; ++i)
        if (NearPoint(x, y, kMediaTransportX[i], kMediaTransportY, kMediaTransportRadius[i])) return i;
    return -1;
}

static bool MediaTitleAt(float x, float y) {
    return x >= kMediaTitleX && x <= kMediaRight && y >= kMediaTitleTop && y <= kMediaTitleBottom;
}

static int MediaModeAt(float x, float y) {
    if (g.media.canShuffle && NearPoint(x, y, kMediaShuffleX, kMediaHeaderY, kMediaModeRadius))
        return kMediaShuffleHover;
    if (g.media.canRepeat && NearPoint(x, y, kMediaRepeatX, kMediaHeaderY, kMediaModeRadius))
        return kMediaRepeatHover;
    return -1;
}

static bool MediaProgressAt(float x, float y) {
    return g.media.valid && g.media.canSeek && fabsf(y - MediaProgressY(MediaHasLyrics())) <= kMediaProgressHit &&
           x >= kMediaInset && x <= kMediaRight;
}

static void HandleClick(Card* card, int x, int y) {
    float k = g.kLast;
    float M = (float)card->mPx;
    float ux = ((float)x - M) / k;
    float uy = ((float)y - M) / k;

    if (uy < 34.0f && ux < 150.0f) {
        ToggleFold(card);
        return;
    }
    if (g.collapsed[card->id] || card->autoFold) {
        if (card->id == CARD_MEDIA && NearPoint(ux, uy, kMediaFoldedPlayX, kMediaHeaderY, kMediaFoldedPlayRadius)) {
            MediaCommand(1);
            if (RenderCard(*card)) card->dirty = false;
        }
        return;
    }

    bool redraw = false;

    if (card->id == CARD_NOTES) {
        if (NearPoint(ux, uy, kStickyClearX, 20.0f, 13.0f)) {
            if (g.stickyCanUndo) StickyUndo();
            else StickyClear();
            redraw = true;
        } else if (uy >= kStickyHeaderH) {
            OpenStickyEditor(card);
            return;
        } else {
            return;
        }
    } else if (card->id == CARD_DEADLINES) {
        int row = DeadlineRowAt(uy);
        std::vector<Deadline> v = VisibleDeadlines();
        if (row < 0 || row >= (int)v.size()) return;
        const Deadline& dl0 = v[(size_t)row];
        float rel = uy - DeadlineRowTop(row, v) - (dl0.fromIcs ? 8.0f : 0.0f);
        const Deadline& dl = v[(size_t)row];
        if (!dl.place.empty() && ux >= 78.0f && rel >= 18.0f && rel <= 36.0f) {

            std::wstring url =
                L"https://www.google.com/maps/search/?api=1&query=" + UrlEncode(dl.place);
            ShellExecuteW(nullptr, L"open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
            return;
        }
        if (ux < 78.0f) {

            ToggleDeadlineDone(dl);
            redraw = true;
        }
        return;
    } else if (card->id == CARD_MEDIA) {

        if (MediaProgressAt(ux, uy)) {
            MediaSeek(Clamp01((ux - kMediaInset) / (kMediaRight - kMediaInset)));
            card->bgKey = 0;
            if (RenderCard(*card)) card->dirty = false;
            Restack();
            return;
        }

        if (!g.media.title.empty() && MediaTitleAt(ux, uy)) {
            CopyMediaText();
            card->bgKey = 0;
            if (RenderCard(*card)) card->dirty = false;
            return;
        }
        if (NearPoint(ux, uy, kMediaInfoX, kMediaHeaderY, kMediaInfoRadius)) {

            MetaPanelOpen();
            return;
        }
        const int mode = MediaModeAt(ux, uy);
        if (mode == kMediaShuffleHover) { MediaToggleShuffle(); return; }
        if (mode == kMediaRepeatHover) { MediaCycleRepeat(); return; }
        const int transport = MediaTransportAt(ux, uy);
        if (transport < 0) return;
        MediaCommand(transport);
        redraw = true;
    } else if (card->id == CARD_CLOCK && PomoOn()) {
        float cy = ClockPomoY() + 38.0f;
        if (NearPoint(ux, uy, kPomoPlayX, cy, 18.0f)) {
            const ULONGLONG now = GetTickCount64();
            if (g.pomoRun) {
                PomodoroTick();
                g.pomoRun = false;
            } else {
                g.pomoEnd = now + (ULONGLONG)g.pomoLeft * 1000;
                g.pomoRun = true;
            }
            g.pomoStarted = true;
        } else if (NearPoint(ux, uy, kPomoResetX, cy, 14.0f)) {
            PomoReset();
        } else {
            return;
        }
        redraw = true;
    }

    if (redraw) {
        card->bgKey = 0;
        if (RenderCard(*card)) card->dirty = false;
        Restack();
    }
}

static void OnWeather(bool ok, Weather* w);
static void OnIcs(bool ok, IcsResult* r);
static void OnThumb(ThumbResult* r);
static void HandleReload();
static bool g_menuOpen = false;
static bool g_reloadPending = false;

static void ShowCardMenu(Card* card, HWND hwnd) {
    HMENU m = CreatePopupMenu();
    if (!m) return;
    int id = card->id;

    AppendMenuW(m, MF_STRING, 1,
                g.collapsed[id] ? TR(L"Desplegar", L"Expand", L"Desplega") : TR(L"Plegar", L"Collapse", L"Plega"));
    if (id == CARD_WEATHER) AppendMenuW(m, MF_STRING, 2, TR(L"Actualizar ahora", L"Refresh now", L"Actualitza ara"));
    if (id == CARD_SYSTEM)
        AppendMenuW(m, MF_STRING, 6, TR(L"Administrador de tareas", L"Task Manager", L"Gestor de tasques"));
    if (id == CARD_DEADLINES) {
        AppendMenuW(m, MF_STRING, 3, TR(L"Editar agenda...", L"Edit calendar...", L"Edita l’agenda..."));
        if (!g.icsUrl.empty())
            AppendMenuW(m, MF_STRING, 11, TR(L"Actualizar calendario", L"Refresh calendar", L"Actualitza el calendari"));
        if (!g.calendarUrl.empty())
            AppendMenuW(m, MF_STRING, 7, TR(L"Abrir calendario", L"Open calendar", L"Obre el calendari"));
        if (Wh_GetIntValue(L"dlOvr", 0))
            AppendMenuW(m, MF_STRING, 10,
                        TR(L"Volver a los ajustes", L"Back to settings", L"Torna als ajustos"));
    }
    if (id == CARD_NOTES) {
        if (g.stickyCanUndo)
            AppendMenuW(m, MF_STRING, 13, TR(L"Deshacer borrado", L"Undo clear", L"Desf\u00E9s l’esborrat"));
        else
            AppendMenuW(m, MF_STRING | (g.stickyText.empty() ? MF_GRAYED : 0), 12,
                        TR(L"Borrar la nota", L"Clear the note", L"Esborra la nota"));
    }
    if (id == CARD_MEDIA) {
        std::wstring cpath = MediaCurrentPath();
        AppendMenuW(m, MF_STRING | ((!cpath.empty() && CvUndoExists(cpath)) ? 0 : MF_GRAYED), 17,
                    TR(L"Deshacer el último cambio en el MP3", L"Undo the last change to the MP3",
                       L"Desfés l’últim canvi a l’MP3"));
    }
    if (id == CARD_MEDIA)
        AppendMenuW(m, MF_STRING | (g.media.title.empty() ? MF_GRAYED : 0), 16,
                    TR(L"Copiar t\u00EDtulo y artista", L"Copy title and artist", L"Copia t\u00EDtol i artista"));
    if (id == CARD_MEDIA)
        AppendMenuW(m, MF_STRING | (g.media.title.empty() ? MF_GRAYED : 0), 14,
                    TR(L"Regenerar metadatos del MP3", L"Rebuild MP3 metadata", L"Regenera les metadades"));
    if (id == CARD_MEDIA) {
        AppendMenuW(m, MF_STRING | (MediaSessionCount() > 1 ? 0 : MF_GRAYED), 23,
                    TR(L"Cambiar de reproductor", L"Switch player", L"Canvia de reproductor"));
        AppendMenuW(m, MF_STRING | (g.media.canShuffle ? 0 : MF_GRAYED) | (g.media.shuffle ? MF_CHECKED : 0), 24,
                    TR(L"Reproducci\u00F3n aleatoria", L"Shuffle", L"Reproducci\u00F3 aleat\u00F2ria"));
        const wchar_t* repLabel = g.media.repeat == 1 ? TR(L"Repetir: una pista", L"Repeat: one track", L"Repeteix: una pista")
                                : g.media.repeat == 2 ? TR(L"Repetir: la lista", L"Repeat: all", L"Repeteix: la llista")
                                                      : TR(L"Repetir: desactivado", L"Repeat: off", L"Repeteix: desactivat");
        AppendMenuW(m, MF_STRING | (g.media.canRepeat ? 0 : MF_GRAYED) | (g.media.repeat ? MF_CHECKED : 0), 25, repLabel);
    }

    if (!g.media.valid && !g_meta.path.empty() && g_meta.ready) {
        AppendMenuW(m, MF_STRING, 18,
                    TR(L"Abrir metadatos del último MP3...", L"Open last MP3 metadata...",
                       L"Obre les metadades de l’ultim MP3..."));
        if (CvUndoExists(g_meta.path))
            AppendMenuW(m, MF_STRING, 19,
                        TR(L"Deshacer último cambio en ese MP3", L"Undo last change to that MP3",
                           L"Desfes l’ultim canvi d’aquest MP3"));
    }
    std::vector<unsigned long long> pendingIds;
    if (HMENU pending = CreatePopupMenu()) {
        {
            SrwGuard guard(&g_deferredLock);
            for (const auto& item : g_deferred) {
                const auto slash = item.path.find_last_of(L"\\/");
                std::wstring file = slash == std::wstring::npos ? item.path : item.path.substr(slash + 1);
                if (file.size() > 64) file = file.substr(0, 60) + L"…";
                for (size_t i = 0; i < file.size(); ++i) if (file[i] == L'&') file.insert(++i, 1, L'&');
                const wchar_t* state = item.running ? TR(L"En curso", L"Running", L"En curs") :
                    item.failed ? TR(L"Requiere revisión", L"Needs review", L"Cal revisar") :
                                  TR(L"En espera", L"Waiting", L"En espera");
                const wchar_t* action = item.undo ? TR(L"Deshacer", L"Undo", L"Desfer") :
                                                   TR(L"Incrustar", L"Embed", L"Incrustar");
                const std::wstring label = std::wstring(state) + L" · " + action + L" · " + file;
                AppendMenuW(pending, MF_STRING | (item.running ? MF_GRAYED : 0),
                            100 + pendingIds.size(), label.c_str());
                pendingIds.push_back(item.id);
            }
        }
        if (pendingIds.empty()) DestroyMenu(pending);
        else {
            InsertMenuW(pending, 0, MF_BYPOSITION | MF_STRING | MF_GRAYED, 0,
                TR(L"En espera hasta que el MP3 esté libre", L"Waiting until the MP3 is free",
                   L"En espera fins que el fitxer estigui lliure"));
            AppendMenuW(pending, MF_SEPARATOR, 0, nullptr);
            AppendMenuW(pending, MF_STRING, 21, TR(L"Cancelar todos", L"Cancel all", L"Cancel·la-ho tot"));
            AppendMenuW(m, MF_POPUP, (UINT_PTR)pending,
                        TR(L"Cambios MP3 pendientes…", L"Pending MP3 changes…", L"Canvis MP3 pendents…"));
        }
    }
    if (id == CARD_CLOCK && PomoOn())
        AppendMenuW(m, MF_STRING, 9, TR(L"Reiniciar temporizador", L"Reset timer", L"Reinicia el temporitzador"));

    AppendMenuW(m, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(m, MF_STRING, 15,
                AnyCardOpen() ? TR(L"Plegar todas", L"Collapse all", L"Plega-les totes")
                              : TR(L"Desplegar todas", L"Expand all", L"Desplega-les totes"));
    AppendMenuW(m, MF_STRING, 22, TR(L"Orden de las tarjetas…", L"Card order…", L"Ordre de les targetes…"));
    AppendMenuW(m, MF_STRING | (g.lockPosition ? MF_CHECKED : 0), 4,
                TR(L"Bloquear posici\u00F3n", L"Lock position", L"Bloqueja la posici\u00F3"));
    AppendMenuW(m, MF_STRING, 5, TR(L"Restablecer posici\u00F3n", L"Reset position", L"Restableix la posici\u00F3"));

    POINT p;
    GetCursorPos(&p);
    SetForegroundWindow(hwnd);
    g_menuOpen = true;
    int cmd = TrackPopupMenu(m, TPM_RETURNCMD | TPM_RIGHTBUTTON | TPM_NONOTIFY, p.x, p.y, 0, hwnd, nullptr);
    g_menuOpen = false;
    PostMessageW(hwnd, WM_NULL, 0, 0);
    DestroyMenu(m);

    switch (cmd) {
        case 1: ToggleFold(card); break;
        case 2:
            g.nextFetch = 0;
            break;
        case 3: OpenAgendaEditor(hwnd); break;
        case 4:
            g.lockPosition = !g.lockPosition;
            Wh_SetIntValue(L"lockSet", 1);
            Wh_SetIntValue(L"lockVal", g.lockPosition ? 1 : 0);
            break;
        case 5:
            Wh_SetIntValue(L"posSet", 0);
            g.anchorValid = false;
            g.needStack = true;
            break;
        case 6: ShellExecuteW(nullptr, L"open", L"taskmgr.exe", nullptr, nullptr, SW_SHOWNORMAL); break;
        case 7: ShellExecuteW(nullptr, L"open", g.calendarUrl.c_str(), nullptr, nullptr, SW_SHOWNORMAL); break;
        case 9: PomoReset(); break;
        case 10:
            Wh_SetIntValue(L"dlOvr", 0);
            LoadLists();
            g.cards[CARD_NOTES].dirty = true;
            g.cards[CARD_DEADLINES].dirty = true;
            break;
        case 11: g.icsNext = 0; break;
        case 12: StickyClear(); break;
        case 13: StickyUndo(); break;
        case 14: MediaRebuild(); break;
        case 15: ToggleAllFold(); break;
        case 16: CopyMediaText(); break;
        case 23: MediaCycleSession(); break;
        case 24: MediaToggleShuffle(); break;
        case 25: MediaCycleRepeat(); break;
        case 17: UndoLastChange(); break;
        case 18: MetaPanelOpen(); break;
        case 19: UndoLastChange(); break;
        case 22: OpenCardOrderEditor(hwnd, id); break;
        case 21:
            if (DeferredCancelAll()) ShowNotice(TR(L"Metadatos MP3", L"MP3 metadata", L"Metadades MP3"), TR(L"Operaciones pendientes canceladas.", L"Pending operations canceled.", L"S’han cancel·lat les operacions pendents."));
            else ShowNotice(TR(L"Metadatos MP3", L"MP3 metadata", L"Metadades MP3"), TR(L"No se pudo cancelar la cola. Comprueba si hay un trabajo en curso.", L"Could not clear the queue. Check for operations in progress.", L"No s’ha pogut buidar la cua. Comprova si hi ha operacions en curs."));
            break;
        default:
            if (cmd >= 100 && (size_t)(cmd - 100) < pendingIds.size()) {
                const auto id = pendingIds[(size_t)(cmd - 100)];
                if (MessageBoxW(hwnd,
                    TR(L"¿Cancelar esta operación pendiente?", L"Cancel this pending operation?", L"Cancel·lar aquesta operació pendent?"),
                    L"MP3", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES) {
                    if (!DeferredCancelOne(id)) ShowNotice(L"MP3",
                        TR(L"La operación sigue activa o ya no está en cola.",
                           L"The operation is active or has already left the queue.",
                           L"L’operació està activa o ja no és a la cua."));
                }
            }
            break;
    }
    if (g_reloadPending) {
        g_reloadPending = false;
        HandleReload();
    }
}

static bool CardDetailHover(Card& card, int x, int y) {
    const float ux = (x - card.mPx) / g.kLast;
    const float uy = (y - card.mPx) / g.kLast;
    int hour = -1, process = -1;
    int cpuGraph = -1;
    int mediaHover = -1;
    float seekHover = -1.0f;
    bool titleHover = false;
    if (!g.collapsed[card.id] && !card.autoFold && !card.animating) {
        if (card.id == CARD_WEATHER && g.weather.hourlyN > 1) {
            const float top = WeatherLayout(g.weather).hourlyY;
            if (top >= 0.0f && ux >= 24.0f && ux <= 348.0f && uy >= top + 14.0f && uy <= top + 89.0f)
                hour = ClampInt((int)lroundf((ux - 24.0f) / 324.0f * (g.weather.hourlyN - 1)),
                                0, g.weather.hourlyN - 1);
        }
        if (card.id == CARD_MEDIA) {
            mediaHover = MediaTransportAt(ux, uy);
            if (mediaHover < 0) mediaHover = MediaModeAt(ux, uy);
            if (NearPoint(ux, uy, kMediaInfoX, kMediaHeaderY, kMediaInfoRadius))
                mediaHover = kMediaMetadataHover;
            titleHover = MediaTitleAt(ux, uy);
            if (MediaProgressAt(ux, uy))
                seekHover = (ux - kMediaInset) / (kMediaRight - kMediaInset);
        }
        if (card.id == CARD_SYSTEM && ux >= 18.0f && ux < 354.0f) {
            if (uy >= kSysGraphTop && uy < kSysGraphBottom && ux >= 57.0f && ux <= 342.0f)
                cpuGraph = (int)lroundf((342.0f - ux) * 60000.0f / 285.0f);
            const float top = SystemProcessTop(BuildSysRows().size());
            if (!g.procs.empty() && uy >= top && uy < top + kSystemProcessHeight)
                process = std::min((int)g.procs.size() - 1, (int)((ux - 18.0f) * g.procs.size() / 336.0f));
        }
    }
    if (card.id == CARD_MEDIA && (g.collapsed[CARD_MEDIA] || card.autoFold) && !card.animating &&
        MediaCanCommand(g.media, 1) && NearPoint(ux, uy, kMediaFoldedPlayX, kMediaHeaderY, kMediaFoldedPlayRadius))
        mediaHover = 1;
    if (titleHover && !g_mediaHoverTitle) g_mediaTitleHoverSince = GetTickCount64();
    if (!titleHover) g_mediaMarqueeActive = false;
    const bool changed = hour != g.hourlyHover || process != g.processHover || cpuGraph != g.cpuGraphHover ||
        mediaHover != g_mediaHover || seekHover != g_mediaHoverSeek || titleHover != g_mediaHoverTitle;
    g_mediaHover = mediaHover;
    g_mediaHoverSeek = seekHover;
    g_mediaHoverTitle = titleHover;
    g.hourlyHover = hour;
    g.processHover = process;
    g.cpuGraphHover = cpuGraph;
    return changed;
}

static void MediaVolumeWheel(int delta);
static void EqSetActive(bool on);
static void OnMediaClosed();

static LRESULT CALLBACK CardWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    Card* card = reinterpret_cast<Card*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));

    if (msg == WM_HOTKEY && wp >= 2 && wp <= 4) {
        if (!g.dragCard && !g_menuOpen) MediaCommand(wp == 2 ? 0 : wp == 3 ? 1 : 2);
        return 0;
    }
    if (msg == WM_HOTKEY && wp == 1) {
        if (!g.dragCard && !g_menuOpen) ToggleAllFold();
        return 0;
    }

    switch (msg) {

        case WM_APP_WEATHER:
            OnWeather(wp != 0, reinterpret_cast<Weather*>(lp));
            return 0;
        case WM_APP_ICS:
            OnIcs(wp != 0, reinterpret_cast<IcsResult*>(lp));
            return 0;
        case WM_APP_THUMB:
            OnThumb(reinterpret_cast<ThumbResult*>(lp));
            return 0;
        case WM_APP_EMBED:
            OnEmbedDone((int)wp);
            return 0;
        case WM_APP_MEDIA_CLOSED:
            OnMediaClosed();
            return 0;
        case WM_APP_DEFERRED:
            OnDeferredDone(reinterpret_cast<DeferredMp3Result*>(lp));
            return 0;
        case WM_APP_PANEL:
            OnMetaPanelResult(reinterpret_cast<MetaPanelResult*>(lp));
            return 0;
        case WM_APP_METAPICK:
            OnMetaPickResult(reinterpret_cast<MetaPickResult*>(lp));
            return 0;
#if GH_HAVE_WINRT
        case WM_APP_MXMETA:
            OnMxMeta(reinterpret_cast<MxMetaResult*>(lp));
            return 0;
#if GH_HAVE_THUMB
        case WM_APP_LYRICS:
            OnLyrics(reinterpret_cast<LyrResult*>(lp));
            return 0;
#endif
#endif
        case WM_APP_RELOAD:

            if (g_menuOpen) g_reloadPending = true;
            else HandleReload();
            return 0;

        case WM_MOUSEACTIVATE:

            return (card && card->id == CARD_NOTES) ? MA_ACTIVATE : MA_NOACTIVATE;

        case WM_TIMER:
            if (wp == 2) {
                KillTimer(hwnd, 2);
                RemoveNotice();
            }
            return 0;

        case WM_WINDOWPOSCHANGING: {
            WINDOWPOS* pos = reinterpret_cast<WINDOWPOS*>(lp);
            if (pos && !(pos->flags & SWP_NOZORDER)) {
                pos->hwndInsertAfter = HWND_BOTTOM;
            }
            break;
        }

        case WM_LBUTTONDOWN:
            if (card && card->id == CARD_MEDIA && !g.collapsed[CARD_MEDIA] && !card->autoFold &&
                !card->animating && MediaProgressAt((GET_X_LPARAM(lp) - card->mPx) / g.kLast,
                                                    (GET_Y_LPARAM(lp) - card->mPx) / g.kLast)) {
                g_mediaScrubWindow = hwnd;
                g_mediaScrubGeneration = g_metaGen;
                g_mediaHoverSeek = Clamp01(((GET_X_LPARAM(lp) - card->mPx) / g.kLast - kMediaInset) /
                                           (kMediaRight - kMediaInset));
                SetCapture(hwnd);
                if (RenderCard(*card)) card->dirty = false;
                return 0;
            }
            if (card && !g.lockPosition && g.anchorValid) {
                GetCursorPos(&g.dragCursor);
                g.dragAnchor.x = g.anchorX;
                g.dragAnchor.y = g.anchorY;
                g.dragMoved = false;
                g.dragCard = card;
                SetCapture(hwnd);
            } else if (card) {
                HandleClick(card, (short)LOWORD(lp), (short)HIWORD(lp));
            }
            return 0;

        case WM_MOUSEMOVE: {
            if (card && g_mediaScrubWindow == hwnd) {
                g_mediaHoverSeek = Clamp01(((GET_X_LPARAM(lp) - card->mPx) / g.kLast - kMediaInset) /
                                           (kMediaRight - kMediaInset));
                if (RenderCard(*card)) card->dirty = false;
                return 0;
            }
            const bool detailChanged = card && !g.dragCard &&
                CardDetailHover(*card, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
            if (card && g.hoverCard != card && !g.dragCard) {
                Card* prev = g.hoverCard;
                g.hoverCard = card;
                TRACKMOUSEEVENT tme;
                memset(&tme, 0, sizeof(tme));
                tme.cbSize = sizeof(tme);
                tme.dwFlags = TME_LEAVE;
                tme.hwndTrack = hwnd;
                TrackMouseEvent(&tme);

                if (prev && prev->win && RenderCard(*prev)) prev->dirty = false;
                if (RenderCard(*card)) card->dirty = false;
            } else if (detailChanged && RenderCard(*card)) card->dirty = false;
            if (card && card->id == CARD_MEDIA && detailChanged && g_mediaMarqueeActive) EqSetActive(g_eqWanted != 0);
            if (card && g.dragCard == card) {
                POINT p;
                GetCursorPos(&p);
                int dx = p.x - g.dragCursor.x;
                int dy = p.y - g.dragCursor.y;
                if (!g.dragMoved && (abs(dx) > 3 || abs(dy) > 3)) g.dragMoved = true;
                if (g.dragMoved) {
                    g.anchorX = g.dragAnchor.x + dx;
                    g.anchorY = g.dragAnchor.y + dy;
                    Restack();
                }
            }
            return 0;
        }

        case WM_LBUTTONUP:
            if (card && g_mediaScrubWindow == hwnd) {
                const float target = Clamp01(((GET_X_LPARAM(lp) - card->mPx) / g.kLast - kMediaInset) /
                                             (kMediaRight - kMediaInset));
                g_mediaScrubWindow = nullptr;
                g_mediaHoverSeek = -1.0f;
                ReleaseCapture();
                if (g_mediaScrubGeneration == g_metaGen) MediaSeek(target);
                if (RenderCard(*card)) card->dirty = false;
                return 0;
            }
            if (card && g.dragCard == card) {
                bool moved = g.dragMoved;
                g.dragCard = nullptr;
                ReleaseCapture();
                if (moved) {
                    SnapAnchor();
                    Restack();
                    SavePosition();
                } else {
                    HandleClick(card, (short)LOWORD(lp), (short)HIWORD(lp));
                }
            }
            return 0;

        case WM_MOUSEWHEEL:
            if (card && card->id == CARD_MEDIA && !g.dragCard) {
                RECT box;
                const POINT mouse = {GET_X_LPARAM(lp), GET_Y_LPARAM(lp)};
                if (GetWindowRect(hwnd, &box) && PtInRect(&box, mouse)) {
                    if (GET_KEYSTATE_WPARAM(wp) & MK_SHIFT) MediaCycleSession(GET_WHEEL_DELTA_WPARAM(wp));
                    else MediaVolumeWheel(GET_WHEEL_DELTA_WPARAM(wp));
                    return 0;
                }
            }
            break;

        case WM_RBUTTONUP:
            if (card) ShowCardMenu(card, hwnd);
            return 0;

        case WM_MOUSELEAVE:
            if (card && g.hoverCard == card) {
                g.hourlyHover = g.processHover = -1;
                g.cpuGraphHover = -1;
                g_mediaHover = -1;
                g_mediaHoverSeek = -1.0f;
                g_mediaHoverTitle = g_mediaMarqueeActive = false;
                g.hoverCard = nullptr;
                if (RenderCard(*card)) card->dirty = false;
            }
            return 0;

        case WM_CAPTURECHANGED:
            if (g_mediaScrubWindow == hwnd) {
                g_mediaScrubWindow = nullptr;
                g_mediaHoverSeek = -1.0f;
                if (card) card->dirty = true;
            }
            if (card && g.dragCard == card) g.dragCard = nullptr;
            return 0;

        case WM_LBUTTONDBLCLK:
            if (card) {

                float uy = ((float)(short)HIWORD(lp) - (float)card->mPx) / g.kLast;
                if (uy < 34.0f) return 0;
                if (card->id == CARD_WEATHER) {
                    g.nextFetch = 0;
                } else if (card->id == CARD_SYSTEM) {
                    ShellExecuteW(nullptr, L"open", L"taskmgr.exe", nullptr, nullptr, SW_SHOWNORMAL);
                } else if (card->id == CARD_DEADLINES && !g.calendarUrl.empty()) {
                    ShellExecuteW(nullptr, L"open", g.calendarUrl.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
                }
            }
            return 0;

        case WM_DISPLAYCHANGE:
        case WM_DPICHANGED:
            g.anchorValid = false;
            g.needStack = true;
            for (int i = 0; i < CARD_COUNT; i++) {
                g.cards[i].dirty = true;
                g.cards[i].bgKey = 0;
            }
            return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

static bool EnsureShellProcess() {
    if (g.decided) return !g.disabled;
    HWND progman = FindWindowW(L"Progman", nullptr);
    if (!progman) return false;
    DWORD pid = 0;
    GetWindowThreadProcessId(progman, &pid);
    g.decided = true;
    g.disabled = (pid != GetCurrentProcessId());
    if (g.disabled) Wh_Log(L"This explorer.exe is not the shell process, the cards stay disabled here");
    return !g.disabled;
}

static bool EnsureWindow(Card& c) {
    if (c.win && !IsWindow(c.win)) {
        c.win = nullptr;
        c.placed = false;
    }
    if (c.win) return true;

    c.win = CreateWindowExW(WS_EX_LAYERED | WS_EX_TOOLWINDOW, kWndClass, L"", WS_POPUP, 0, 0, 10, 10, nullptr,
                            nullptr, GetModuleHandleW(nullptr), nullptr);
    if (!c.win) {
        Wh_Log(L"CreateWindowEx failed: %lu", GetLastError());
        return false;
    }
    SetWindowLongPtrW(c.win, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&c));
    c.placed = false;
    c.dirty = true;
    return true;
}

static void DestroyCard(Card& c) {
    if (c.win) {
        if (c.id == CARD_MEDIA) {
            g_mediaEqCached = false;
            g_mediaMarqueeActive = g_mediaHoverTitle = false;
            if (g_mediaScrubWindow == c.win) {
                g_mediaScrubWindow = nullptr;
                if (GetCapture() == c.win) ReleaseCapture();
            }
            g_mediaHover = -1;
            g_mediaHoverSeek = -1.0f;
        }
        if (g.hoverCard == &c) g.hoverCard = nullptr;
        DestroyWindow(c.win);
        c.win = nullptr;
        c.animating = false;
        g.needStack = true;
    }
    c.placed = false;
}

static void OnMediaClosed() {
    if (g_stop || !g.showMedia || !g.mediaAutoHide || g.paused) return;
    SampleMedia();
    if (g.media.valid) return;
    EqSetActive(false);
    DestroyCard(g.cards[CARD_MEDIA]);
    Restack();
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static void MarkAllDirty() {
    for (int i = 0; i < CARD_COUNT; i++) {
        g.cards[i].dirty = true;
        g.cards[i].bgKey = 0;
    }
}

static void CheckDeadlineNotices() {
    if (g.notifyMin <= 0) return;

    {
        std::vector<Deadline> all = AllDeadlines();
        for (size_t i = 0; i < all.size(); i++) {
            const Deadline& d = all[i];
            if (d.days >= 0 || d.days < -7) continue;
            unsigned int key = TextHash(L"miss|" + d.name + L"|" +
                                        std::to_wstring(d.dayNum) + L"|" +
                                        std::to_wstring(d.hh * 60 + d.mm));
            if (std::find(g.notified.begin(), g.notified.end(), key) != g.notified.end()) continue;
            g.notified.push_back(key);
            if (g.notified.size() > 200) g.notified.erase(g.notified.begin());
            std::wstring body = TR(L"Se pasó  \u00B7  ", L"Missed  \u00B7  ", L"S’ha passat  \u00B7  ") +
                                std::to_wstring(d.d) + L" " + MonthShort(d.m) +
                                L"  \u00B7  " + std::to_wstring(d.hh >= 0 ? d.hh : 0) +
                                L":" + (d.mm >= 0 && d.mm < 10 ? L"0" : L"") +
                                std::to_wstring(d.mm >= 0 ? d.mm : 0);
            if (!d.place.empty()) body += L"  \u00B7  " + d.place;
            ShowNotice(d.name, body);

            std::wstring packed;
            for (size_t k = 0; k < g.notified.size(); k++) {
                wchar_t hx[16];
                wsprintfW(hx, L"%08X", g.notified[k]);
                if (!packed.empty()) packed += L"\n";
                packed += hx;
            }
            Wh_SetStringValue(L"notified", packed.c_str());
        }
    }
    SYSTEMTIME st;
    GetLocalTime(&st);
    int nowMin = (int)st.wHour * 60 + (int)st.wMinute;
    std::vector<Deadline> all = AllDeadlines();
    for (size_t i = 0; i < all.size(); i++) {
        const Deadline& d = all[i];
        if (d.days != 0 || d.hh < 0) continue;
        int left = (d.hh * 60 + d.mm) - nowMin;
        if (left < 0 || left > g.notifyMin) continue;
        if (DeadlineDone(d)) continue;
        unsigned int key = TextHash(d.name + L"|" + std::to_wstring(d.dayNum) + L"|" +
                                    std::to_wstring(d.hh * 60 + d.mm));
        if (std::find(g.notified.begin(), g.notified.end(), key) != g.notified.end()) continue;
        g.notified.push_back(key);
        if (g.notified.size() > 200) g.notified.erase(g.notified.begin());

        {
            std::wstring packed;
            for (size_t k = 0; k < g.notified.size(); k++) {
                wchar_t hx[16];
                wsprintfW(hx, L"%08X", g.notified[k]);
                if (!packed.empty()) packed += L"\n";
                packed += hx;
            }
            Wh_SetStringValue(L"notified", packed.c_str());
        }

        wchar_t head[64];
        if (left <= 1) lstrcpynW(head, TR(L"Ahora", L"Now", L"Ara"), 63);
        else wsprintfW(head, TR(L"En %d min", L"In %d min", L"En %d min"), left);
        std::wstring body = std::wstring(head) + L"  \u00B7  " + HM(d.hh * 60 + d.mm);
        if (!d.place.empty()) body += L"  \u00B7  " + d.place;
        ShowNotice(d.name, body);
    }
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

static UINT_PTR g_tmrEq = 0;
static UINT_PTR g_tmrSystem = 0;
static UINT_PTR g_tmrAlert = 0;

static void EqSetActive(bool on) {
    InterlockedExchange(&g_eqWanted, on ? 1 : 0);
    if (g_eqThread && WaitForSingleObject(g_eqThread, 0) == WAIT_OBJECT_0) {
        CloseHandle(g_eqThread);
        g_eqThread = nullptr;
    }
    AcquireSRWLockShared(&g_audioLock);
    const bool volumePending = g_audioWheelSteps != 0 || g_audioVolumeBusy || g_audioVolumeResult != -2;
    ReleaseSRWLockShared(&g_audioLock);
    if ((on || volumePending) && !g_eqThread && !g_eqQuit) {
        g_eqThread = CreateThread(nullptr, 0, EqCaptureThread, nullptr, 0, nullptr);
    }
    const ULONGLONG now = GetTickCount64();
    const bool animate = on || volumePending || g_mediaMarqueeActive || now < g_mediaCoverFadeUntil || g_mediaVolumeUntil != 0;
    if (animate && !g_tmrEq) g_tmrEq = SetTimer(nullptr, 0, 67, nullptr);
    if (!animate && g_tmrEq) {
        KillTimer(nullptr, g_tmrEq);
        g_tmrEq = 0;
    }
}

static void MediaVolumeWheel(int delta) {
    if (!g.media.valid) return;
    g_mediaWheelRemainder += delta;
    const int steps = g_mediaWheelRemainder / WHEEL_DELTA;
    g_mediaWheelRemainder %= WHEEL_DELTA;
    if (!steps) return;

    AcquireSRWLockExclusive(&g_audioLock);
    if (g_audioApp.empty()) g_audioVolumeResult = -1;
    else g_audioWheelSteps = std::clamp(g_audioWheelSteps + steps, -20, 20);
    ReleaseSRWLockExclusive(&g_audioLock);
    EqSetActive(g_eqWanted != 0);
}

static void EqShutdown() {
    InterlockedExchange(&g_eqQuit, 1);
    if (g_tmrEq) {
        KillTimer(nullptr, g_tmrEq);
        g_tmrEq = 0;
    }
    if (g_eqThread) {
        WaitForSingleObject(g_eqThread, INFINITE);
        CloseHandle(g_eqThread);
        g_eqThread = nullptr;
    }
}

static void OnSystemTimer() {
    Card& card = g.cards[CARD_SYSTEM];
    if (!g.showSystem || g.paused || !card.win || !IsWindowVisible(card.win)) return;
    const ULONGLONG now = GetTickCount64();
    const bool sampleDue = now >= g.dueCpu;
    const ULONGLONG previous = g.hist.empty() ? 0 : g.hist.back().first;
    if (sampleDue) {
        SampleCpu(now);
        g.dueCpu = now + 500;
    }
    const double old = g.cpuMeter;
    g.cpuMeter = EaseCpuMeter(old, g.cpu);
    const bool newSample = !g.hist.empty() && g.hist.back().first != previous;
    if (!g.dragCard && !card.animating && !card.autoFold && !g.collapsed[CARD_SYSTEM] &&
        (newSample || g.cpuMeter != old)) {
        RenderCard(card);
    }
}

static void OnEqTimer() {
    if (g.dragCard || g.paused) return;
    Card& cm = g.cards[CARD_MEDIA];
    if (!cm.win || !g.media.valid) return;
    AcquireSRWLockExclusive(&g_audioLock);
    const int volume = std::exchange(g_audioVolumeResult, -2);
    ReleaseSRWLockExclusive(&g_audioLock);
    const ULONGLONG now = GetTickCount64();
    const bool volumeChanged = volume != -2 || (g_mediaVolumeUntil && now >= g_mediaVolumeUntil);
    if (volumeChanged) {
        g_mediaVolumeText = volume;
        g_mediaVolumeUntil = volume == -2 ? 0 : now + 1500;
        if (RenderCard(cm)) cm.dirty = false;
    }
    if (cm.autoFold || g.collapsed[CARD_MEDIA]) return;
    const bool coverChanged = g_mediaCoverFadeUntil != 0;
    bool changed = coverChanged;
    if (coverChanged && GetTickCount64() >= g_mediaCoverFadeUntil) g_mediaCoverFadeUntil = 0;
    const bool animateBars = g.media.playing && g_eqCapOk;
    for (int i = 0; animateBars && i < kEqBars; i++) {
        float t = Clamp01(g_eqLive[i].load(std::memory_order_relaxed));
        float old = g_eqBars[i];
        float nv = t > old ? t : old + (t - old) * 0.30f;
        if (fabsf(nv - old) > 0.004f) changed = true;
        g_eqBars[i] = nv;
        float pk = g_eqPeak[i];
        float np = nv > pk ? nv : std::max(0.0f, pk - 0.015f);
        if (fabsf(np - pk) > 0.004f) changed = true;
        g_eqPeak[i] = np;
    }
    if (g_mediaMarqueeActive || (changed && (coverChanged || !RenderMediaEqualizer(cm)))) {
        if (RenderCard(cm)) cm.dirty = false;
    }
}

static void OnAlertTimer() {
    if (g.paused || !g.showWeather || !g.weather.valid || g.weather.alertColor <= 0) return;
    Card& cw = g.cards[CARD_WEATHER];
    if (!EnsureWindow(cw)) return;

    if (RenderCard(cw, !cw.dirty)) cw.dirty = false;
}

static void OnTimer() {
    if (!EnsureShellProcess()) return;

    g.tick++;

    SYSTEMTIME st;
    GetLocalTime(&st);
    bool minuteChanged = (int)st.wMinute != g.lastMinute;
    if (minuteChanged) {
        g.lastMinute = (int)st.wMinute;
        if (UpdatePalette()) MarkAllDirty();
        CheckDeadlineNotices();
    }
    PomodoroTick();

    MetaPanelAutoClose();

    g.cards[CARD_CLOCK].dirty = true;

    if (g.pauseFs && FullscreenBusy()) {
        SetMediaProbeMode(0);
        g.paused = true;
        EqSetActive(false);
        return;
    }
    if (g.paused) {
        g.paused = false;
        MarkAllDirty();
    }

    ULONGLONG now = GetTickCount64();

    Card& cw = g.cards[CARD_WEATHER];
    Card& cs = g.cards[CARD_SYSTEM];
    Card& cd = g.cards[CARD_DEADLINES];
    Card& cn = g.cards[CARD_NOTES];
    Card& cm = g.cards[CARD_MEDIA];
    Card& cc = g.cards[CARD_CLOCK];

    if (minuteChanged) {
        cw.dirty = true;
        cd.dirty = true;
        cc.dirty = true;
    }

    // weather
    if (g.showWeather) {

        if (g.weather.valid && g.weather.alertColor > 0) {
            if (!g_tmrAlert) g_tmrAlert = SetTimer(nullptr, 0, 40, nullptr);
        } else if (g_tmrAlert) {
            KillTimer(nullptr, g_tmrAlert);
            g_tmrAlert = 0;
        }
        if (EnsureWindow(cw) && cw.dirty) {
            if (RenderCard(cw)) cw.dirty = false;
        }
        if (!g.fetching && now >= g.nextFetch) StartFetch();
    } else {
        if (g_tmrAlert) { KillTimer(nullptr, g_tmrAlert); g_tmrAlert = 0; }
        DestroyCard(cw);
    }

    if (!g.icsUrl.empty()) {
        if (!g.icsFetching && now >= g.icsNext) StartIcsFetch();
    } else if (!g.ics.empty()) {
        g.ics.clear();
        cd.dirty = true;
    }

    // system
    if (g.showSystem) {
        if (!cs.win || g.tick % g.sysRefresh == 0) {
            if (g.showGpu && !g_gpuQ && !g_gpuTried) {
                g_gpuTried = true;
                InitGpu();
            }
            if (g.showGpu && now >= g.dueGpu) {
                SampleGpu();
                g.dueGpu = now + 2000;
            }
            if (g.showDisk && !g_dskQ && !g_dskTried) {
                g_dskTried = true;
                InitDiskActivity();
            }
            if (g.showDisk && now >= g_dueDsk) {
                SampleDiskActivity();
                g_dueDsk = now + 1000;
            }
            SampleMemory();
            SampleNetwork();
            if (g.disks.empty() || now >= g.dueDisks) { SampleDisks(); g.dueDisks = now + 15000; }
            if (g.showBattery && now >= g.dueBat) { SampleBattery(); g.dueBat = now + 10000; }
            if (g.showWifi && now >= g.dueWifi) { SampleWifi(); g.dueWifi = now + 10000; }
            if (g.topProcs <= 0) g.procs.clear();
            else if (now >= g.dueProcs) { SampleProcs(); g.dueProcs = now + 3000; }
            if (EnsureWindow(cs) && RenderCard(cs)) cs.dirty = false;
        }
    } else {
        DestroyCard(cs);
    }

    // media
    if (g.showMedia) {
        SampleMedia();
        if (g.thumbOk && !g_thumbBusy && g.thumbS > 0 && abs(ClampInt((int)(kThumbU * g.kLast + 0.5f), 32, 256) - g.thumbS) > 8)
            StartThumbThread();
        bool eqPlay = g.media.valid && g.media.playing && !cm.autoFold && !g.collapsed[CARD_MEDIA];

        EqSetActive(eqPlay);
        if (eqPlay && !g_eqCapOk) SampleEqualizer();
        unsigned int sig = TextHash(g.media.title + L"|" + g.media.artist) ^
                           (g.media.playing ? 0x9E3779B1u : 0u) ^ ((unsigned int)g.media.pos << 5) ^
                           (g.media.valid ? 1u : 0u) ^ TextHash(g.media.player) ^
                           (GetTickCount64() < g.copiedUntil ? 0x5A5A5A5Au : 0u) ^
                           (static_cast<unsigned>(MediaIndicatorStatus()) << 25) ^
                           ((unsigned)g.media.dur * 31u) ^
                           (g.media.paused ? 0x071E6523u : 0u) ^ (g.media.loading ? 0x946AD881u : 0u) ^
                           ((unsigned)g.media.canNext << 9) ^ ((unsigned)g.media.canPrevious << 10) ^
                           ((unsigned)MediaCanCommand(g.media, 1) << 11) ^ ((unsigned)g.media.canSeek << 12) ^
                           ((unsigned)g.media.canShuffle << 16) ^ ((unsigned)g.media.canRepeat << 17) ^
                           ((unsigned)g.media.shuffle << 18) ^ ((unsigned)g.media.repeat << 19) ^
                           (now < g_mediaPressedUntil && g_mediaPressed >= 0 ? 0x81A8F90Bu : 0u);
        if (sig != g.mediaSig) {
            g.mediaSig = sig;
            cm.dirty = true;
        }
        const bool want = !g.mediaAutoHide || g.media.valid;
        if (want) {
            if (EnsureWindow(cm) && cm.dirty) {
                if (RenderCard(cm)) cm.dirty = false;
            }
        } else {
            DestroyCard(cm);
        }
    } else {
        DestroyCard(cm);
        EqSetActive(false);
        g.media.valid = g.media.playing = false;
        if (DeferredCount() > 0) SampleMedia(true);
        else SetMediaProbeMode(0);
    }

    DeferredTryStart();

    if (g.showClock) {
        if (EnsureWindow(cc) && (cc.dirty || g.pomoRun)) {
            if (RenderCard(cc)) cc.dirty = false;
        }
    } else {
        DestroyCard(cc);
    }

    // deadlines
    if (g.showDeadlines) {
        if (EnsureWindow(cd) && cd.dirty) {
            if (RenderCard(cd)) cd.dirty = false;
        }
    } else {
        DestroyCard(cd);
    }

    // notes
    if (g.showNotes) {
        if (EnsureWindow(cn) && cn.dirty) {
            if (RenderCard(cn)) cn.dirty = false;
        }
    } else {
        DestroyCard(cn);
    }

    if (g.needStack) {
        g.needStack = false;
        Restack();
    }
}

static void HandleReload() {
    LoadSettings();
    int reset = Wh_GetIntSetting(L"resetPosition");
    if (reset != g.lastReset) {
        g.lastReset = reset;
        Wh_SetIntValue(L"posSet", 0);
        Wh_Log(L"Position reset");
    }
    g.anchorValid = false;
    g.needStack = true;
    g.disks.clear();
    g.nextFetch = 0;
    MarkAllDirty();
    OnTimer();
}

static void OnThumb(ThumbResult* r) {
    if (g_thumbThread) {
        CloseHandle(g_thumbThread);
        g_thumbThread = nullptr;
    }
    g_thumbBusy = false;

    if (r->gen == g_thumbGen && !g_thumbRedo &&
        (r->path.empty() || _wcsicmp(r->path.c_str(), g.media.path.c_str()) == 0)) {
        std::wstring ca, ct;
        CvSplitQuery(g.media.artist, g.media.title, ca, ct);
        if (ct.empty()) ct = CvCleanTitle(g.media.title);
        bool mismaCancion = !ct.empty() &&
                            CvNormSp(r->title) == CvNormSp(ct) &&
                            (ca.empty() || r->artist.empty() ||
                             CvNormSp(r->artist) == CvNormSp(ca));
        if (!mismaCancion) {
            Wh_Log(L"Miniatura descartada: es de '%s' de '%s' y ahora suena '%s' de '%s'",
                   r->title.c_str(), r->artist.c_str(), ct.c_str(), ca.c_str());
            g.thumbOk = false;
            g.thumbPx.clear();
            g.thumbImg.clear();
        g.thumbSerial++;
            g.cards[CARD_MEDIA].dirty = true;
            g_curCoverKey.clear();
            if (InterlockedIncrement(&g_thumbMismatch) <= 3) g_thumbRedo = true;
        } else {
            InterlockedExchange(&g_thumbMismatch, 0);
            if (r->ok) {
                if (r->sourceHash != 0) {
                    InterlockedExchange64(&g_lastPlayerThumbHash, (LONG64)r->sourceHash);
                    InterlockedExchange64(&g_lastPlayerThumbKeyHash, (LONG64)r->keyHash);
                }
                g.thumbPx.swap(r->px);
                g.thumbImg.swap(r->img);
                g_thumbAcceptedPath = r->path;
                g.thumbSerial++;
                g.thumbS = r->size;
                if (!g.thumbOk) {
                    g_mediaCoverFadeUntil = GetTickCount64() + 180;
                    if (!g_tmrEq) g_tmrEq = SetTimer(nullptr, 0, 67, nullptr);
                }
                g.thumbOk = true;
                g_curCoverKey = r->key;
            } else {
                g.thumbOk = false;
                g.thumbPx.clear();
            g.thumbImg.clear();
        g.thumbSerial++;
                g_curCoverKey.clear();
            }
            g.cards[CARD_MEDIA].dirty = true;
        }
        if (MetaRememberCardCover() && g_metaWin) { MetaPanelFill(); MetaPanelPaint(); }
        RefreshFileMeta();

    }
    delete r;
    if (g_thumbRedo) {
        g_thumbRedo = false;
        StartThumbThread();
    }
}
static void OnWeather(bool ok, Weather* w) {
    if (g.fetchThread) {
        CloseHandle(g.fetchThread);
        g.fetchThread = nullptr;
    }
    g.fetching = false;

    if (w->version != g.settingsVersion) {
        g.nextFetch = 0;
    } else if (ok) {
        g.weather = *w;
        g.fetchFailed = false;
        g.lastOk = GetTickCount64();
        GetLocalTime(&g.lastOkTime);
        g.nextFetch = GetTickCount64() + (ULONGLONG)g.refreshMinutes * 60000ULL;
        g.cards[CARD_WEATHER].dirty = true;
        Wh_Log(L"Weather updated: %d, code %d", (int)floor(w->temp + 0.5), w->code);
    } else {
        Wh_Log(L"Weather update failed, retrying in 1 minute");
        g.fetchFailed = true;
        g.nextFetch = GetTickCount64() + 60000ULL;
        g.cards[CARD_WEATHER].dirty = true;
    }
    delete w;
}

static void OnIcs(bool ok, IcsResult* r) {
    if (g.icsThread) {
        CloseHandle(g.icsThread);
        g.icsThread = nullptr;
    }
    g.icsFetching = false;

    if (r->version != g.settingsVersion) {
        g.icsNext = 0;
    } else if (ok || !r->sources.empty()) {
        g.ics.clear();
        g.icsMissingSources = 0;
        std::unordered_map<std::wstring, std::vector<Deadline>> updated;
        for (auto& source : r->sources) {
            if (!source.ok) {
                ++g.icsMissingSources;
                const auto previous = g.icsBySource.find(source.key);
                if (previous != g.icsBySource.end()) source.events = std::move(previous->second);
            }
            auto inserted = updated.emplace(source.key, std::move(source.events));
            if (inserted.second)
                g.ics.insert(g.ics.end(), inserted.first->second.begin(), inserted.first->second.end());
        }
        g.icsBySource.swap(updated);
        g.icsFailed = g.icsMissingSources > 0;
        if (ok) g.icsLastOk = GetTickCount64();
        g.icsFailCount = 0;
        g.icsLastCount = (int)g.ics.size();
        g.icsNext = GetTickCount64() + (g.icsFailed ? 5ULL : 30ULL) * 60000ULL;
        g.cards[CARD_DEADLINES].dirty = true;
        Wh_Log(L"Calendar updated: %d event(s)", (int)g.ics.size());
    } else {

        g.icsFailed = true;
        static const int kBackoffMin[5] = {1, 2, 5, 10, 15};
        int step = g.icsFailCount < 5 ? g.icsFailCount : 4;
        int waitMin = kBackoffMin[step];
        if (g.icsFailCount < 5) g.icsFailCount++;
        Wh_Log(L"Calendar update failed (%d in a row), retrying in %d min",
               g.icsFailCount, waitMin);
        g.icsNext = GetTickCount64() + (ULONGLONG)waitMin * 60000ULL;
        g.cards[CARD_DEADLINES].dirty = true;
    }
    delete r;
}

// Own card windows, timers, input, drawing, and worker result dispatch.
static DWORD WINAPI WorkerThread(LPVOID) {
    MSG msg;
    PeekMessageW(&msg, nullptr, WM_USER, WM_USER, PM_NOREMOVE);
    SetEvent(g_ready);

    for (int i = 0; i < CARD_COUNT; i++) g.cards[i].id = i;
    if (!DecodeCardOrder(GetStoredStr(L"cardDisplayOrder"), g_cardOrder))
        std::copy_n(kDefaultCardOrder, CARD_COUNT, g_cardOrder);

    HINSTANCE hi = GetModuleHandleW(nullptr);

    WNDCLASSEXW wc;
    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = CardWndProc;
    wc.hInstance = hi;
    wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    wc.lpszClassName = kWndClass;
    RegisterClassExW(&wc);

    WNDCLASSEXW ec;
    memset(&ec, 0, sizeof(ec));
    ec.cbSize = sizeof(ec);
    ec.lpfnWndProc = EditWndProc;
    ec.hInstance = hi;
    ec.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    ec.hbrBackground = nullptr;
    ec.lpszClassName = kEditClass;
    RegisterClassExW(&ec);

    WNDCLASSEXW oc = ec;
    oc.lpfnWndProc = CardOrderWndProc;
    oc.lpszClassName = kCardOrderClass;
    RegisterClassExW(&oc);

    WNDCLASSEXW mc;
    memset(&mc, 0, sizeof(mc));
    mc.cbSize = sizeof(mc);
    mc.lpfnWndProc = MetaWndProc;
    mc.hInstance = hi;
    mc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    mc.hbrBackground = nullptr;
    mc.lpszClassName = kMetaClass;
    RegisterClassExW(&mc);

    WNDCLASSEXW sc;
    memset(&sc, 0, sizeof(sc));
    sc.cbSize = sizeof(sc);
    sc.lpfnWndProc = StickyHostProc;
    sc.hInstance = hi;
    sc.hCursor = LoadCursorW(nullptr, IDC_IBEAM);
    sc.lpszClassName = kStickyClass;
    RegisterClassExW(&sc);
    g_paperBrush = CreateSolidBrush(kPaperRef);

    g.msgWin = CreateWindowExW(0, kWndClass, L"", 0, 0, 0, 0, 0, HWND_MESSAGE, nullptr, hi, nullptr);

    LoadSettings();
    g.lastReset = Wh_GetIntSetting(L"resetPosition");
    SetTimer(nullptr, 1, 1000, nullptr);
    g_tmrSystem = SetTimer(nullptr, 0, 125, nullptr);

    DeferredLoad();
    while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
        if (!msg.hwnd) {
            if (msg.message == WM_TIMER) {
                if (g_tmrEq && msg.wParam == g_tmrEq) OnEqTimer();
                else if (g_tmrSystem && msg.wParam == g_tmrSystem) OnSystemTimer();
                else if (g_tmrAlert && msg.wParam == g_tmrAlert) OnAlertTimer();
                else if (g_tmrAnim && msg.wParam == g_tmrAnim) OnAnimTimer();
                else OnTimer();
            } else if (msg.message == WM_APP_RELOAD) {
                HandleReload();
            } else if (msg.message == WM_APP_WEATHER) {
                OnWeather(msg.wParam != 0, reinterpret_cast<Weather*>(msg.lParam));
            } else if (msg.message == WM_APP_ICS) {
                OnIcs(msg.wParam != 0, reinterpret_cast<IcsResult*>(msg.lParam));
            } else if (msg.message == WM_APP_EMBED) {
                OnEmbedDone((int)msg.wParam);
            } else if (msg.message == WM_APP_MEDIA_CLOSED) {
                OnMediaClosed();
            } else if (msg.message == WM_APP_DEFERRED) {
                OnDeferredDone(reinterpret_cast<DeferredMp3Result*>(msg.lParam));
            } else if (msg.message == WM_APP_THUMB) {
                OnThumb(reinterpret_cast<ThumbResult*>(msg.lParam));
            } else if (msg.message == WM_APP_META) {
                if (g_metaWin) MetaPanelFill();
                g.cards[CARD_MEDIA].dirty = true;
            } else if (msg.message == WM_APP_PANEL) {
                OnMetaPanelResult(reinterpret_cast<MetaPanelResult*>(msg.lParam));
            } else if (msg.message == WM_APP_METAPICK) {
                OnMetaPickResult(reinterpret_cast<MetaPickResult*>(msg.lParam));
#if GH_HAVE_WINRT
            } else if (msg.message == WM_APP_MXMETA) {
                OnMxMeta(reinterpret_cast<MxMetaResult*>(msg.lParam));
#if GH_HAVE_THUMB
            } else if (msg.message == WM_APP_LYRICS) {
                OnLyrics(reinterpret_cast<LyrResult*>(msg.lParam));
#endif
#endif
            }
            continue;
        }
        if (g_editWin && msg.message == WM_KEYDOWN &&
            (msg.hwnd == g_editWin || IsChild(g_editWin, msg.hwnd))) {
            if (msg.wParam == VK_ESCAPE ||
                (msg.wParam == VK_RETURN && (GetKeyState(VK_CONTROL) & 0x8000))) {
                SendMessageW(g_editWin, WM_COMMAND, msg.wParam == VK_ESCAPE ? kAgendaCancel : kAgendaSave, 0);
                continue;
            }
            if (msg.wParam == VK_TAB && IsDialogMessageW(g_editWin, &msg)) continue;
        }
        if (g_cardOrderWin && msg.message == WM_KEYDOWN &&
            (msg.hwnd == g_cardOrderWin || IsChild(g_cardOrderWin, msg.hwnd))) {
            if (msg.wParam == VK_ESCAPE ||
                (msg.wParam == VK_RETURN && (GetKeyState(VK_CONTROL) & 0x8000))) {
                SendMessageW(g_cardOrderWin, WM_COMMAND, msg.wParam == VK_ESCAPE ? kOrderCancel : kOrderSave, 0);
                continue;
            }
            if (msg.wParam == VK_TAB && IsDialogMessageW(g_cardOrderWin, &msg)) continue;
        }
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    if (g.fetchThread) {
        WaitForSingleObject(g.fetchThread, INFINITE);
        CloseHandle(g.fetchThread);
        g.fetchThread = nullptr;
    }
    if (g.icsThread) {
        WaitForSingleObject(g.icsThread, INFINITE);
        CloseHandle(g.icsThread);
        g.icsThread = nullptr;
    }
    if (g_orderThread) {
        WaitForSingleObject(g_orderThread, INFINITE);
        CloseHandle(g_orderThread);
        g_orderThread = nullptr;
    }
    if (g_thumbThread) {
        WaitForSingleObject(g_thumbThread, INFINITE);
        CloseHandle(g_thumbThread);
        g_thumbThread = nullptr;
    }
    JoinBgThreads();
    if (g_deferredStoreLock != INVALID_HANDLE_VALUE) {
        CloseHandle(g_deferredStoreLock);
        g_deferredStoreLock = INVALID_HANDLE_VALUE;
    }
    while (PeekMessageW(&msg, nullptr, WM_APP_THUMB, WM_APP_THUMB, PM_REMOVE)) {
        delete reinterpret_cast<ThumbResult*>(msg.lParam);
    }
    while (PeekMessageW(&msg, nullptr, WM_APP_WEATHER, WM_APP_WEATHER, PM_REMOVE)) {
        delete reinterpret_cast<Weather*>(msg.lParam);
    }
    while (PeekMessageW(&msg, nullptr, WM_APP_ICS, WM_APP_ICS, PM_REMOVE)) {
        delete reinterpret_cast<IcsResult*>(msg.lParam);
    }
    while (PeekMessageW(&msg, nullptr, WM_APP_DEFERRED, WM_APP_DEFERRED, PM_REMOVE)) {
        delete reinterpret_cast<DeferredMp3Result*>(msg.lParam);
    }
    while (PeekMessageW(&msg, nullptr, WM_APP_PANEL, WM_APP_PANEL, PM_REMOVE)) {
        delete reinterpret_cast<MetaPanelResult*>(msg.lParam);
    }

    while (PeekMessageW(&msg, nullptr, WM_APP_METAPICK, WM_APP_METAPICK, PM_REMOVE)) {
        delete reinterpret_cast<MetaPickResult*>(msg.lParam);
    }
    while (PeekMessageW(&msg, nullptr, WM_APP_MXMETA, WM_APP_MXMETA, PM_REMOVE)) {
        delete reinterpret_cast<MxMetaResult*>(msg.lParam);
    }
#if GH_HAVE_THUMB
    while (PeekMessageW(&msg, nullptr, WM_APP_LYRICS, WM_APP_LYRICS, PM_REMOVE)) {
        delete reinterpret_cast<LyrResult*>(msg.lParam);
    }
#endif

    if (g_stickyHost) {
        StickySave();
        HWND hs = g_stickyHost;
        g_stickyHost = nullptr;
        g_stickyEdit = nullptr;
        DestroyWindow(hs);
    }
    if (g_stickyFont) {
        DeleteObject(g_stickyFont);
        g_stickyFont = nullptr;
    }
    if (g_editWin) DestroyWindow(g_editWin);
    if (g_cardOrderWin) DestroyWindow(g_cardOrderWin);
    MetaPanelClose();
    for (int i = 0; i < CARD_COUNT; i++) DestroyCard(g.cards[i]);
    RemoveNotice();
    if (g.msgWin) {
        DestroyWindow(g.msgWin);
        g.msgWin = nullptr;
    }
    if (g_hotkeyOn && g.msgWin) {
        UnregisterHotKey(g.msgWin, 1);
        g_hotkeyOn = false;
    }
    CloseWifi();
    if (g_tmrSystem) {
        KillTimer(nullptr, g_tmrSystem);
        g_tmrSystem = 0;
    }
    EqShutdown();
    CloseAudioMeter();
    ShutdownMedia();
    FreeRenderBuffers();
    CloseGpu();
    CloseDiskActivity();
    if (g.fontsOk) {
        FreeFonts(g.fonts);
        g.fontsOk = false;
    }
    UnregisterClassW(kStickyClass, hi);
    if (g_paperBrush) {
        DeleteObject(g_paperBrush);
        g_paperBrush = nullptr;
    }
    UnregisterClassW(kMetaClass, hi);
    UnregisterClassW(kEditClass, hi);
    UnregisterClassW(kCardOrderClass, hi);
    UnregisterClassW(kWndClass, hi);
    return 0;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

BOOL Wh_ModInit() {
    Wh_Log(L"Desktop Glass Cards starting");
    g_stop = 0;
    SetMediaProbeMode(0);
    InterlockedExchange(&g_mp3MediaSessionUnsafe, 1);
    InterlockedExchange64(&g_mp3MediaLastChecked, 0);
    InterlockedExchange64(&g_mp3MediaNoSessionSince, 0);
    g_ready = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    g_thread = CreateThread(nullptr, 0, WorkerThread, nullptr, 0, &g_threadId);
    if (!g_thread) {
        if (g_ready) CloseHandle(g_ready);
        g_ready = nullptr;
        return FALSE;
    }
    WaitForSingleObject(g_ready, 5000);
    return TRUE;
}

void Wh_ModSettingsChanged() {
    if (g_thread) PostUi(WM_APP_RELOAD, 0, 0);
}

void Wh_ModUninit() {
    g_stop = 1;
    if (g_thread) {
        PostThreadMessageW(g_threadId, WM_QUIT, 0, 0);
        WaitForSingleObject(g_thread, INFINITE);
        CloseHandle(g_thread);
        g_thread = nullptr;
    }
    if (g_ready) {
        CloseHandle(g_ready);
        g_ready = nullptr;
    }
}
