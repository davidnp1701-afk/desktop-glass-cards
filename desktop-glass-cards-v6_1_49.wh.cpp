// ==WindhawkMod==
// @id              desktop-glass-cards
// @name            Tarjetas de cristal para el escritorio
// @description     Tarjetas de cristal en el escritorio: tiempo, reloj con Pomodoro, sistema, multimedia, agenda y un post-it de notas.
// @version         6.1.49
// @author          David Nadal Pérez
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -lwinhttp -luser32 -lgdi32 -liphlpapi -lshell32 -lpdh -ladvapi32 -lpsapi -lole32 -loleaut32 -lruntimeobject -utf-8
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Tarjetas de cristal para el escritorio

Tarjetas de cristal apiladas en el escritorio, en una sola columna:

- **Tiempo** - temperatura, sensación, humedad, viento, sol, aire, polen, lluvia inminente, gráfica de las próximas 24 horas con la máxima y la mínima del día, y previsión de 6 días.
- **Reloj** - hora local, husos horarios con su bandera y temporizador Pomodoro.
- **Sistema** - CPU con histórico, RAM, GPU, discos, batería, red, Wi-Fi y, abajo, barras verticales con los 5 procesos que más consumen.
- **Multimedia** - carátula (si el tema no la trae, se busca en internet y se guarda), título, artista, ecualizador real con la paleta de colores a elegir, progreso y botones anterior / pausa / siguiente.
- **Agenda** - cuenta atrás, con lugar tras `#`, repeticiones y calendario `.ics`.
- **Notas** - un post-it amarillo: haz clic, escribe y se guarda solo.

## Ajustes

Están ordenados por tarjeta, y cada nombre empieza por su etiqueta: **[General]**, **[Posición]**, **[Tiempo]**, **[Reloj]**, **[Sistema]**, **[Multimedia]**, **[Agenda]** y **[Notas]**. Cada ajuste lleva debajo una descripción de para qué sirve.

## Uso

- **Arrastrar** - mueve cualquier tarjeta y se desplazan todas juntas. Se pega a los bordes y se guarda la posición.
- **Clic derecho** - menú con plegar, editar, actualizar, bloquear y restablecer posición.
- **Plegar** - clic en el título de la tarjeta.
- **Post-it** - clic sobre la nota y escribe. Se guarda mientras escribes. Pulsa fuera o Esc para terminar. El botón de arriba a la derecha borra la nota y, justo después, la recupera.
- **Agenda** - clic derecho > Editar agenda. Un clic sobre el lugar de una cita lo abre en Google Maps.

## Agenda

`DD/MM/AAAA [HH:MM] Texto [@repetición] [# Lugar]`

      - '05/11/2026 16:50 Revisión del coche. # Taller del barrio'
      - '16/03/2027 07:00 Renovar el DNI @anual # Oficina de la calle Mayor'

Repeticiones: `@diario`, `@semanal`, `@mensual`, `@anual` (también en inglés y catalán).

## Reloj y banderas

`Etiqueta | Zona horaria de Windows | País`, por ejemplo `Nueva York | Eastern Standard Time | US`. Los nombres de zona se ven con `tzutil /l`. El país es opcional: si falta, se intenta deducir de la etiqueta. Países disponibles: ES, CAT, GB, US, FR, DE, IT, PT, NL, BE, IE, JP, CN, MX, AR, BR, CA, AU, IN, RU, CH, SE y EU.

## Pomodoro

Es una cuenta atrás para trabajar por tandas: unos minutos de trabajo seguidos de un descanso corto. Al terminar cada tanda recibes un aviso. No es un cronómetro.

## Carátulas de los temas

Si el reproductor no ofrece carátula, el mod busca una por **artista y título** en iTunes y, si no aparece, en Deezer. Solo se acepta un resultado cuyo título y artista coincidan; si no hay coincidencia clara, se muestra una nota musical en lugar de arriesgar una carátula equivocada.

- **Privacidad**: lo único que sale de tu PC es el artista y el título del tema. Se desactiva con *Buscar en internet la carátula*. No se busca para navegadores.
- **Caché**: la imagen se guarda en `%LOCALAPPDATA%\WindhawkGlassCards\covers`, así que la próxima vez no hay descarga. Un tema sin resultado se recuerda 7 días. La carpeta se mantiene acotada sola.
- **Incrustar en el MP3** (desactivado por defecto): añade la imagen a la etiqueta ID3 del archivo para que cualquier reproductor la use. Localiza el archivo buscando el título en el nombre dentro de las *Carpetas donde buscar los MP3*. Añade o repara carátula (APIC), título (TIT2) e intérprete (TPE1) en etiquetas ID3v2.3/2.4. Si los tres ya son correctos, no modifica el MP3. Copia el audio sin cambios, conserva las fechas y verifica la etiqueta temporal antes de sustituir el original. Si el reproductor tiene el archivo bloqueado, no se toca y se reintenta al cambiar de tema. **Prueba primero con copias de tu música.**

## Aviso

El mod guarda en el almacenamiento de Windhawk la posición, las tarjetas plegadas, el texto del post-it y las citas editados desde la tarjeta.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- language: es
  $name: "[General] Idioma"
  $description: "Idioma de los textos de todas las tarjetas"
  $options:
    - es: "Español"
    - en: "English"
    - ca: "Català"
- theme: auto
  $name: "[General] Tema"
  $description: "Automático sigue el tema claro u oscuro de Windows"
  $options:
    - auto: "Automático"
    - dark: "Oscuro"
    - light: "Claro"
- useWindowsAccent: false
  $name: "[General] Usar el color de acento de Windows"
  $description: "Todas las tarjetas usan el acento del sistema (brillo, iconos, barras y paleta de acento del ecualizador) en vez de su color propio"
- accent: 255
  $name: "[General] Brillo de color de las tarjetas (0 a 255)"
  $description: "Intensidad del resplandor de color de la esquina superior izquierda de cada tarjeta. 0 = sin brillo, 255 = máximo"
- scale: 100
  $name: "[General] Escala (%)"
  $description: "Tamaño de todas las tarjetas. 100 es el tamaño normal"
- glassOpacity: 72
  $name: "[General] Opacidad del cristal (%)"
  $description: "Cuanto más alto, menos se ve el fondo a través de las tarjetas"
- cornerRadius: 24
  $name: "[General] Radio de las esquinas (px)"
  $description: "Cuanto más alto, más redondeadas son las tarjetas"
- pauseFullscreen: true
  $name: "[General] Pausar con aplicaciones a pantalla completa"
  $description: "Deja de actualizar las tarjetas mientras un juego o un vídeo ocupa toda la pantalla, para no gastar recursos"
- lockPosition: false
  $name: "[Posición] Bloquear la posición"
  $description: "Impide arrastrar las tarjetas. También se cambia con el clic derecho"
- monitor: 0
  $name: "[Posición] Monitor"
  $description: "0 = monitor principal; 1, 2... = número de monitor"
- snapToEdges: true
  $name: "[Posición] Pegar a los bordes al soltar"
  $description: "Al arrastrar, las tarjetas se imantan a los bordes de la pantalla"
- marginRight: 45
  $name: "[Posición] Margen derecho (px)"
  $description: "Distancia entre las tarjetas y el borde derecho de la pantalla"
- marginTop: 32
  $name: "[Posición] Margen superior (px)"
  $description: "Distancia entre la primera tarjeta y el borde superior de la pantalla"
- stackGap: 14
  $name: "[Posición] Separación entre tarjetas (px)"
  $description: "Espacio vertical entre una tarjeta y la siguiente"
- resetPosition: 0
  $name: "[Posición] Restablecer la posición"
  $description: "Ponlo en 1 un momento y vuelve a 0 para devolver las tarjetas a su sitio original"
- showWeather: true
  $name: "[Tiempo] Mostrar la tarjeta"
  $description: "Muestra u oculta la tarjeta del tiempo"
- city: Tu ciudad
  $name: "[Tiempo] Ciudad"
  $description: "Nombre que se ve en la tarjeta. El tiempo se obtiene con la latitud y la longitud de abajo"
- latitude: "41.4667"
  $name: "[Tiempo] Latitud"
  $description: "Coordenada con punto decimal, por ejemplo 41.4667"
- longitude: "2.2833"
  $name: "[Tiempo] Longitud"
  $description: "Coordenada con punto decimal, por ejemplo 2.2833"
- units: celsius
  $name: "[Tiempo] Unidades"
  $description: "Unidad de temperatura"
  $options:
    - celsius: "Celsius"
    - fahrenheit: "Fahrenheit"
- showDetails: true
  $name: "[Tiempo] Mostrar sensación, humedad y viento"
  $description: "Panel con la sensación térmica, la humedad y el viento"
- showSunAir: true
  $name: "[Tiempo] Mostrar sol, calidad del aire y polen"
  $description: "Panel con las horas del sol, la calidad del aire y el nivel de polen"
- showHourly: true
  $name: "[Tiempo] Mostrar la gráfica de 24 horas"
  $description: "Curva de temperatura de las próximas 24 horas"
- showForecast: true
  $name: "[Tiempo] Mostrar la previsión"
  $description: "Previsión de los próximos días"
- refreshMinutes: 15
  $name: "[Tiempo] Actualizar el tiempo cada (min)"
  $description: "Cada cuántos minutos se vuelve a consultar el tiempo"
- showClock: true
  $name: "[Reloj] Mostrar la tarjeta"
  $description: "Muestra u oculta la tarjeta del reloj"
- clocks:
  - 'Londres | GMT Standard Time | GB'
  - 'Nueva York | Eastern Standard Time | US'
  $name: "[Reloj] Husos horarios (máx. 3)"
  $description: "Etiqueta | Zona horaria de Windows | País (opcional). Los nombres de zona se ven con tzutil /l"
- localFlag: ES
  $name: "[Reloj] Bandera de la hora local"
  $description: "Código de país (ES, CAT, GB...). Vacío = sin bandera"
- pomoFocus: 25
  $name: "[Reloj] Pomodoro: minutos de trabajo"
  $description: "Duración de cada tanda de trabajo. 0 = sin temporizador"
- pomoBreak: 5
  $name: "[Reloj] Pomodoro: minutos de descanso"
  $description: "Duración del descanso entre tandas"
- showSystem: true
  $name: "[Sistema] Mostrar la tarjeta"
  $description: "Muestra u oculta la tarjeta del sistema"
- systemRefreshSec: 1
  $name: "[Sistema] Actualizar cada (s)"
  $description: "Cada cuántos segundos se actualizan los datos. Más alto gasta menos"
- showGpu: true
  $name: "[Sistema] Mostrar la GPU"
  $description: "Uso de la tarjeta gráfica"
- showBattery: true
  $name: "[Sistema] Mostrar la batería (si existe)"
  $description: "Nivel de carga en portátiles y tabletas"
- showWifi: true
  $name: "[Sistema] Mostrar el Wi-Fi"
  $description: "Nombre de la red inalámbrica y porcentaje de señal"
- maxDisks: 2
  $name: "[Sistema] Número de discos"
  $description: "Cuántos discos se muestran (0 a 4)"
- processCount: 5
  $name: "[Sistema] Procesos más activos, en barras"
  $description: "0 = ninguno; máximo 5"
- topProcsSort: cpu
  $name: "[Sistema] Ordenar los procesos por"
  $description: "Criterio para elegir los procesos que se muestran"
  $options:
    - cpu: "CPU"
    - ram: "RAM"
- showMedia: true
  $name: "[Multimedia] Mostrar la tarjeta"
  $description: "Muestra u oculta la tarjeta multimedia"
- mediaAutoHide: true
  $name: "[Multimedia] Ocultar si no suena nada"
  $description: "Activada, la tarjeta solo aparece mientras hay algo sonando. Desactivada, se ve siempre"
- eqPalette: rainbow
  $name: "[Multimedia] Ecualizador: paleta de colores"
  $description: "Las barras cambian de color según la altura que alcanzan, de abajo arriba. Con Personalizada se usan los tres colores de abajo"
  $options:
    - rainbow: "Arcoíris (cian, verde, amarillo, naranja, rosa)"
    - bluepurple: "Azules y violetas"
    - sunset: "Atardecer (violeta, rosa, naranja)"
    - fire: "Fuego (amarillo, naranja, rojo)"
    - green: "Verdes"
    - ice: "Hielo (azul claro a blanco)"
    - accent: "Color de acento de la tarjeta"
    - custom: "Personalizada (tres colores)"
- eqColorLow: '#3C78FF'
  $name: "[Multimedia] Ecualizador: color de la base"
  $description: "Solo con la paleta Personalizada. Formato #RRGGBB"
- eqColorMid: '#A064FF'
  $name: "[Multimedia] Ecualizador: color del medio"
  $description: "Solo con la paleta Personalizada. Formato #RRGGBB"
- eqColorHigh: '#FF64C8'
  $name: "[Multimedia] Ecualizador: color de la punta"
  $description: "Solo con la paleta Personalizada. Formato #RRGGBB"
- onlineCovers: true
  $name: "[Multimedia] Buscar la carátula en internet si el tema no la trae"
  $description: "Consulta iTunes y Deezer con el artista y el título; solo esos dos datos salen de tu PC. La imagen se guarda en la carpeta de datos del mod, dentro de LocalAppData, y no se vuelve a descargar"
- embedCovers: false
  $name: "[Multimedia] Incrustar la carátula descargada en el MP3"
  $description: "ATENCIÓN: modifica el archivo, añadiendo o reparando carátula, título e intérprete en su etiqueta ID3, para que cualquier reproductor los use. Prueba antes con copias. Si el reproductor tiene el archivo bloqueado, se reintenta al cambiar de tema"
- musicFolders:
  - '%USERPROFILE%\Music'
  $name: "[Multimedia] Carpetas donde buscar los MP3 (máx. 5)"
  $description: "Solo se usan al incrustar. Se busca también en las subcarpetas, y el archivo debe llevar el título en su nombre"
- showDeadlines: true
  $name: "[Agenda] Mostrar la tarjeta"
  $description: "Muestra u oculta la tarjeta de la agenda"
- maxDeadlines: 4
  $name: "[Agenda] Número de citas visibles"
  $description: "Cuántas citas se ven a la vez en la tarjeta"
- deadlines:
  - '05/11/2026 16:50 Revisión del coche. # Taller del barrio'
  $name: "[Agenda] Citas"
  $description: "DD/MM/AAAA [HH:MM] Texto [@diario|@semanal|@mensual|@anual] [# Lugar]"
- notifyMinutes: 30
  $name: "[Agenda] Avisar de las citas con (min) de antelación"
  $description: "0 = nunca avisar"
- icsUrl: ''
  $name: "[Agenda] Calendario .ics (opcional)"
  $description: "URL de un calendario iCal (Google, Outlook...) cuyas citas se añaden a la agenda"
- icsLabel: ''
  $name: "[Agenda] Nombre corto de la cuenta (opcional)"
  $description: "Lo que se verá en cada cita de ese calendario: una inicial, unas siglas o el correo"
- calendarUrl: ''
  $name: "[Agenda] Enlace del doble clic (opcional)"
  $description: "Página que se abre al hacer doble clic en la agenda"
- showNotes: true
  $name: "[Notas] Mostrar el post-it"
  $description: "Muestra u oculta el post-it de notas"
- stickyLines: 7
  $name: "[Notas] Líneas visibles del post-it"
  $description: "Altura del post-it, en líneas de texto"
- notes:
  - 'Haz clic y escribe lo que quieras'
  $name: "[Notas] Texto inicial del post-it"
  $description: "Solo se usa la primera vez; después manda lo que escribas en la nota"
*/
// ==/WindhawkModSettings==

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <windows.h>
#include <winhttp.h>
#include <shellapi.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <pdh.h>
#include <pdhmsg.h>
#include <math.h>
#include <ctype.h>
#include <wctype.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <mmsystem.h>
#include <mmreg.h>
#include <mmdeviceapi.h>
#include <audioclient.h>

// El soporte de multimedia usa C++/WinRT solo si las cabeceras existen.
#define GH_HAVE_WINRT 0
#define GH_HAVE_THUMB 0
#if defined(__has_include)
#if __has_include(<winrt/Windows.Media.Control.h>)
#undef GetCurrentTime
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
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
// GetIfTable2 / FreeMibTable (resueltos en tiempo de ejecucion)
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
    // Orden real de MIB_IF_ROW2: todos los contadores de entrada y despues los de salida.
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
// Medidor de audio (MMDevice API), resuelto en tiempo de ejecucion
//
// Se pide al sistema el nivel de pico del audio que suena por los altavoces.
// Como el audio es una sola cifra por canal, el ecualizador no puede separar
// graves y agudos de verdad: se reparte esa energia en tres tramos con formas
// distintas, bajando hacia los lados, para que las barras se muevan con la
// musica y den la sensacion de un ecualizador.
// ---------------------------------------------------------------------------

typedef HRESULT(WINAPI* CoCreateInstanceFn)(REFCLSID, LPUNKNOWN, DWORD, REFIID, LPVOID*);

static void*  g_audioMeter = nullptr;   // IAudioMeterInformation
static bool   g_audioTried = false;
#define kEqBars 24                    // numero de barras del ecualizador
static float  g_eqBars[kEqBars] = {0};
static float  g_eqPeak[kEqBars] = {0};   // marcas de pico que caen despacio

// Los dos GUID que identifican el enumerador de dispositivos y el medidor.
static const GUID kClsidMMDeviceEnumerator =
    {0xBCDE0395, 0xE52F, 0x467C, {0x8E, 0x3D, 0xC4, 0x57, 0x92, 0x91, 0x69, 0x2E}};
static const GUID kIidIAudioMeter =
    {0xC02216F6, 0x8C67, 0x4B5B, {0x9D, 0x00, 0xD0, 0x08, 0xE7, 0x3E, 0x00, 0x64}};
static const GUID kIidIMMDeviceEnumerator =
    {0xA95664D2, 0x9614, 0x4F35, {0xA7, 0x46, 0xDE, 0x8D, 0xB6, 0x36, 0x17, 0xE6}};

// Tablas de funciones de las tres interfaces que hacen falta. Solo se
// declaran los metodos que se usan; el resto son huecos para que los indices
// coincidan con los reales.
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
        Wh_Log(L"Medidor de audio: no hay mmdevapi.dll");
        return;
    }
    // Este hilo necesita COM propio; si ya estaba iniciado, no pasa nada.
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    // 1) El enumerador de dispositivos de audio.
    void* enumerator = nullptr;
    HRESULT hr = CoCreateInstance(kClsidMMDeviceEnumerator, nullptr, 1 /*INPROC_SERVER*/,
                                  kIidIMMDeviceEnumerator, &enumerator);
    if (FAILED(hr) || !enumerator) {
        Wh_Log(L"Medidor de audio: sin enumerador, hr=0x%08lX", (unsigned long)hr);
        return;
    }

    // 2) El dispositivo de salida que Windows usa por defecto.
    //    eRender = 0, eMultimedia = 1
    void** evt = reinterpret_cast<void**>(enumerator);
    PFN_GetDefaultAudioEndpoint getEndpoint = reinterpret_cast<PFN_GetDefaultAudioEndpoint>(
        reinterpret_cast<void**>(evt[0])[4]);
    void* device = nullptr;
    hr = getEndpoint ? getEndpoint(enumerator, 0, 1, &device) : E_FAIL;
    if (FAILED(hr) || !device) {
        Wh_Log(L"Medidor de audio: sin dispositivo por defecto, hr=0x%08lX", (unsigned long)hr);
        typedef ULONG(WINAPI* PFN_Release)(void*);
        reinterpret_cast<PFN_Release>(evt[0] ? reinterpret_cast<void**>(evt[0])[2] : nullptr)(enumerator);
        return;
    }

    // 3) De ese dispositivo, el medidor de nivel.
    void** dvt = reinterpret_cast<void**>(device);
    PFN_Activate activate = reinterpret_cast<PFN_Activate>(
        reinterpret_cast<void**>(dvt[0])[3]);
    void* meter = nullptr;
    hr = activate ? activate(device, kIidIAudioMeter, 0 /*CLSCTX_INPROC_SERVER*/, nullptr, &meter)
                  : E_FAIL;
    if (FAILED(hr) || !meter) {
        Wh_Log(L"Medidor de audio: sin medidor, hr=0x%08lX", (unsigned long)hr);
        meter = nullptr;
    }

    // Se sueltan el dispositivo y el enumerador: ya no hacen falta.
    typedef ULONG(WINAPI* PFN_Release)(void*);
    PFN_Release rel = reinterpret_cast<PFN_Release>(dvt[0] ? reinterpret_cast<void**>(dvt[0])[2] : nullptr);
    if (rel) rel(device);
    rel = reinterpret_cast<PFN_Release>(evt[0] ? reinterpret_cast<void**>(evt[0])[2] : nullptr);
    if (rel) rel(enumerator);

    g_audioMeter = meter;
    Wh_Log(L"Medidor de audio: %s", meter ? L"listo" : L"no disponible");
}

// Pide el pico actual (0..1). Devuelve -1 si no se puede leer.
// Tabla de funciones del medidor. Ademas del pico global interesa el de cada
// canal por separado: con el izquierdo y el derecho como dos series distintas,
// cada barra puede seguir una mezcla propia y el conjunto se mueve mucho mas.
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

// Pico de cada canal (hasta 8). Devuelve cuantos canales ha leido, 0 si no hay.
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

// Reparte el pico en ocho barras con forma de campana: las de los extremos
// responden menos, asi el conjunto se mueve como un ecualizador de verdad.
static void SampleEqualizer() {
    // El dispositivo de salida puede cambiar (auriculares, HDMI...): se vuelve a
    // resolver cada 30 s, y a los 5 s si no hay medidor o la lectura falla.
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
        g_audioTried = (nowT < s_reload);  // reintenta cuando toque
        return;
    }
    // Se parten en dos series: la suavizada y la instantanea. La segunda da los
    // golpes y la primera el cuerpo, y de su mezcla sale el nervio.
    static float s_slow = 0.0f;
    static float s_phase = 0.0f;
    float inst = ReadAudioPeak();
    if (inst < 0.0f) {  // medidor invalidado: se suelta y se reintenta pronto
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
        // Forma de campana: las del centro responden mas que las puntas.
        float shape = 0.55f + 0.45f * sinf(t * 3.14159265f);
        // Mezcla: la energia instantanea da el golpe, la suavizada el fondo.
        float base = inst * 0.65f + s_slow * 0.35f;
        // Si hay dos canales, cada mitad de la tira tira de uno distinto.
        if (nch >= 2) {
            float c = (t < 0.5f) ? ch[0] : ch[1];
            base = base * 0.55f + c * 0.45f;
        }
        // Bamboleo raudo, distinto en cada barra.
        float wob = 0.42f + 0.58f * sinf(s_phase + (float)i * 0.70f);
        wob += 0.18f * sinf(s_phase * 2.3f + (float)i * 1.7f);
        float target = base * shape * wob;
        if (target > 1.0f) target = 1.0f;
        // Sube de golpe y baja rapidisimo, como un vumetro nervioso.
        if (target > g_eqBars[i]) g_eqBars[i] = target;
        else g_eqBars[i] += (target - g_eqBars[i]) * 0.82f;
    }
}

// ---------------------------------------------------------------------------
// Ecualizador real: captura "loopback" de WASAPI + FFT
//
// Un hilo propio escucha lo que suena por la salida por defecto, lo pasa por
// una FFT de 2048 puntos y reparte la energia en kEqBars bandas logaritmicas
// (50 Hz a 14 kHz). Solo trabaja mientras la tarjeta multimedia lo pide. Si la
// captura no esta disponible se usa el medidor de pico de antes.
// ---------------------------------------------------------------------------

#define kFftN 2048
static volatile LONG  g_eqWanted = 0;
static volatile LONG  g_eqQuit = 0;
static volatile LONG  g_eqCapOk = 0;
static volatile float g_eqLive[kEqBars];
static HANDLE         g_eqThread = nullptr;

static const GUID kIidIAudioClient =
    {0x1CB9AD4C, 0xDBFA, 0x4C32, {0xB1, 0x78, 0xC2, 0xF5, 0x68, 0xA7, 0x03, 0xB2}};
static const GUID kIidIAudioCaptureClient =
    {0xC8ADBD64, 0xE71E, 0x48A0, {0xA4, 0xDE, 0x18, 0x5C, 0x39, 0x5C, 0xD3, 0x17}};

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
    if (s.dev) s.dev->Release();
    if (s.fmt) CoTaskMemFree(s.fmt);
    s = EqSession();
}

static bool EqOpen(IMMDeviceEnumerator* en, EqSession& s) {
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
        Wh_Log(L"Ecualizador: no se pudo abrir la captura (formato %d bits, float=%d)", s.bits, s.isFloat ? 1 : 0);
        EqClose(s);
        return false;
    }
    return true;
}

static inline float EqReadSample(const BYTE* p, bool isFloat, int bits) {
    if (isFloat) {
        float v;
        memcpy(&v, p, 4);
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

static DWORD WINAPI EqCaptureThread(LPVOID) {
    HRESULT hrCo = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    IMMDeviceEnumerator* en = nullptr;
    if (FAILED(CoCreateInstance(kClsidMMDeviceEnumerator, nullptr, CLSCTX_INPROC_SERVER, kIidIMMDeviceEnumerator,
                                (void**)&en)) ||
        !en) {
        Wh_Log(L"Ecualizador: sin enumerador de audio, se usa el medidor de pico");
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
    float agc = 0.5f;          // referencia de nivel que se adapta al volumen de la musica
    float live[kEqBars] = {0};
    ULONGLONG lastIdCheck = 0, lastData = 0;

    while (!g_eqQuit) {
        if (!g_eqWanted) {
            if (sess.ac) EqClose(sess);
            InterlockedExchange(&g_eqCapOk, 0);
            for (int i = 0; i < kEqBars; i++) {
                live[i] = 0.0f;
                g_eqLive[i] = 0.0f;
            }
            Sleep(150);
            continue;
        }
        ULONGLONG now = GetTickCount64();
        if (!sess.ac) {
            if (!EqOpen(en, sess)) {
                InterlockedExchange(&g_eqCapOk, 0);
                Sleep(1500);
                continue;
            }
            lastIdCheck = lastData = now;
            ringW = sinceLast = 0;
            memset(ring, 0, sizeof(ring));
            InterlockedExchange(&g_eqCapOk, 1);
        }

        // Si cambia la salida por defecto (auriculares, HDMI...), se reabre.
        if (now - lastIdCheck > 1500) {
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

            const float fmin = 50.0f;
            const float fmax = std::min(14000.0f, (float)sess.sr * 0.45f);
            const float ratio = fmax / fmin;
            float frameMax = 0.0f;
            float val[kEqBars];
            for (int b = 0; b < kEqBars; b++) {
                float lo = fmin * powf(ratio, (float)b / (float)kEqBars);
                float hi = fmin * powf(ratio, (float)(b + 1) / (float)kEqBars);
                int kLo = std::max(1, (int)(lo * (float)kFftN / (float)sess.sr));
                int kHi = std::max(kLo + 1, (int)(hi * (float)kFftN / (float)sess.sr));
                kHi = std::min(kHi, kFftN / 2);
                float sum = 0.0f;
                for (int k = kLo; k < kHi; k++) sum += sqrtf(re[k] * re[k] + im[k] * im[k]);
                float mag = sum / (float)std::max(1, kHi - kLo);
                float amp = mag / ((float)kFftN * 0.25f);
                float db = 20.0f * log10f(amp + 1e-7f);
                // Los agudos traen menos energia por banda: se compensa con +2,5 dB por octava.
                db += 2.5f * log2f(sqrtf(lo * hi) / 150.0f);
                float v = (db + 75.0f) / 60.0f;
                v = v < 0.0f ? 0.0f : (v > 1.5f ? 1.5f : v);
                val[b] = v;
                if (v > frameMax) frameMax = v;
            }
            // Ganancia automatica lenta: la musica baja tambien llena el medidor.
            agc = std::max(frameMax, agc * 0.995f);
            float gain = 0.95f / std::max(agc, 0.35f);
            for (int b = 0; b < kEqBars; b++) {
                float v = std::min(1.0f, std::max(0.0f, val[b] * gain));
                v = v * v * (3.0f - 2.0f * v);   // curva suave: menos ruido en reposo, mas contraste
                live[b] = std::max(v, live[b] * 0.86f);
                g_eqLive[b] = live[b];
            }
        } else if (!got && now - lastData > 120) {
            // Silencio: WASAPI no entrega paquetes, asi que las barras caen solas.
            for (int b = 0; b < kEqBars; b++) {
                live[b] *= 0.85f;
                if (live[b] < 0.004f) live[b] = 0.0f;
                g_eqLive[b] = live[b];
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
// Wlan API minima (sin cabeceras, resuelta en tiempo de ejecucion)
// ---------------------------------------------------------------------------

struct UA_WLAN_IFINFO {
    GUID guid;
    WCHAR desc[256];
    ULONG state;
};
struct UA_WLAN_IFLIST {
    DWORD n;
    DWORD idx;
    UA_WLAN_IFINFO info[1];
};
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
// Tipos y globales
// ---------------------------------------------------------------------------

static const wchar_t kWndClass[] = L"WindhawkDesktopGlassCards6";
static const wchar_t kEditClass[] = L"WindhawkDesktopGlassCardsEdit6";
static const wchar_t kStickyClass[] = L"WindhawkDesktopGlassCardsSticky6";
static const UINT WM_APP_RELOAD  = WM_APP + 1;
static const UINT WM_APP_WEATHER = WM_APP + 2;
static const UINT WM_APP_ICS     = WM_APP + 3;
static const UINT WM_APP_THUMB   = WM_APP + 4;

static const int CARD_WEATHER = 0;
static const int CARD_SYSTEM = 1;
static const int CARD_DEADLINES = 2;
static const int CARD_NOTES = 3;
static const int CARD_MEDIA = 4;
static const int CARD_CLOCK = 5;
static const int CARD_COUNT = 6;
static const int kOrder[CARD_COUNT] = {CARD_WEATHER, CARD_CLOCK, CARD_SYSTEM,
                                       CARD_MEDIA,   CARD_DEADLINES, CARD_NOTES};

static HANDLE g_thread = nullptr;
static HANDLE g_ready = nullptr;
static DWORD  g_threadId = 0;
static volatile LONG g_stop = 0;

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
    std::wstring origin;     // nombre del calendario del que viene (X-WR-CALNAME)
    std::wstring badge;      // inicial de la cuenta, para marcar la cita
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

struct IcsResult {
    std::vector<Deadline> ev;
    int version = 0;
};

struct IcsJob {
    std::wstring url;
    std::wstring label;   // copia de icsLabel para el hilo
    std::wstring noName;  // texto de "(sin nombre)" ya traducido
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
    std::vector<DWORD> bg;
    std::vector<DWORD> bgHover;  // variante con el raton encima, se rellena al hacer falta
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
    double cpu = 0;
    double ramMB = 0;
};

struct ProcPrev {
    DWORD pid;
    ULONGLONG t;
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
    bool fallback = false;  // la imagen no venia del reproductor sino de internet o de la cache
    std::wstring key, artist, title;
    uint64_t sourceHash = 0;  // huella de la imagen original entregada por el reproductor
    std::vector<DWORD> px;  // BGRA premultiplicado, size x size
};

struct MediaInfo {
    bool valid = false;
    std::wstring title;
    std::wstring artist;
    bool playing = false;
    double pos = 0;
    double dur = 0;
};

// Paleta del ecualizador: n colores repartidos entre la base (0) y la punta (1).
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

    // dragging and stacking
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
    float dpi = 1.0f;
    float kLast = 1.0f;

    int lastMinute = -1;
    int lastReset = 0;
    int tick = 0;
    ULONGLONG dueDisks = 0, dueGpu = 0, dueBat = 0, dueWifi = 0, dueProcs = 0;

    // general settings
    int lang = 0;  // 0 es, 1 en, 2 ca
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
    std::wstring icsLabel;   // inicial o etiqueta corta de la cuenta del calendario
    bool showWeather = true;
    bool showSystem = true;
    bool showMedia = true;
    bool mediaAutoHide = true;
    bool onlineCovers = true;
    EqPal eqPal;           // paleta elegida en los ajustes
    bool eqAccent = false; // paleta "acento": se calcula al dibujar
    bool embedCovers = false;
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
    bool showBattery = true;
    bool showWifi = true;
    int topProcs = 3;
    bool procByRam = false;
    int sysRefresh = 1;
    double cpu = 0;
    std::vector<float> hist;
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
    std::vector<DWORD> thumbPx;  // caratula del tema actual
    int thumbS = 0;
    bool thumbOk = false;

    // clock and pomodoro
    std::vector<ZoneInfo> zones;
    int pomoFocus = 25;
    int pomoBreak = 5;
    bool pomoRun = false;
    bool pomoStarted = false;
    int pomoMode = 0;  // 0 focus, 1 break
    int pomoLeft = 25 * 60;
    int pomoDone = 0;

    // deadlines
    int maxDeadlines = 4;
    int notifyMin = 30;
    std::vector<Deadline> deadlines;
    std::vector<Deadline> ics;
    std::vector<std::wstring> dlRaw;
    bool icsFetching = false;
    HANDLE icsThread = nullptr;
    ULONGLONG icsNext = 0;
    bool icsFailed = false;      // la ultima descarga del calendario no llego
    int icsFailCount = 0;        // fallos seguidos, para espaciar los reintentos
    int icsLastCount = -1;       // eventos de la ultima descarga correcta (-1 = ninguna)
    ULONGLONG icsLastOk = 0;     // cuando llego bien por ultima vez
    bool icsShowList = false;    // el desplegable de la cabecera esta abierto
    std::vector<unsigned int> notified;

    // notes
    std::vector<Note> notes;
    std::vector<std::wstring> noteRaw;

    // sticky note
    std::wstring stickyText;
    std::wstring stickyUndo;
    bool stickyCanUndo = false;
    int stickyLines = 7;
    int notePitch = 24;
    int localFlag = 0;

    // helper windows
    HWND msgWin = nullptr;
    bool noticeActive = false;

    // fonts
    Fonts fonts = {};
    int fontsKey = 0;
    bool fontsOk = false;
};

static State g;

static const wchar_t* TR(const wchar_t* es, const wchar_t* en, const wchar_t* ca) {
    return g.lang == 1 ? en : (g.lang == 2 ? ca : es);
}

static inline RGBA HL(float a) {
    RGBA c = g.pal.hl;
    c.a = a;
    return c;
}

// ---------------------------------------------------------------------------
// Helpers de texto y numeros
// ---------------------------------------------------------------------------

static std::wstring Trim(std::wstring s) {
    while (!s.empty() && (s.front() == L' ' || s.front() == L'\t' || s.front() == L'"')) s.erase(s.begin());
    while (!s.empty() && (s.back() == L' ' || s.back() == L'\t' || s.back() == L'"')) s.pop_back();
    return s;
}

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
// Fechas, plazos y repeticiones
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

// Moves a repeating deadline to its next occurrence (today or later).
// Returns false when the repetition has already ended.
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

// Optional "HH:MM" (and an optional trailing "h" / "h.") at the start of `rest`.
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

// "31/12/2026 [17:05] Name [@anual] [# Place]"
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
    if (ParseTimePrefix(rest, th, tm)) {
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
// Calendario iCal (.ics)
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

// Etiqueta corta de origen: si el usuario puso un nombre corto para la cuenta
// se usa su primera letra; si no, la primera letra del nombre que trae el .ics.
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

// Color propio de cada calendario, derivado de su etiqueta: asi dos cuentas
// distintas nunca comparten ni inicial ni color.
static RGBA OriginColor(const std::wstring& calName) {
    std::wstring src = g.icsLabel.empty() ? calName : g.icsLabel;
    if (src.empty()) return C(112, 190, 255, 0.95f);
    unsigned int h = 2166136261u;
    for (size_t i = 0; i < src.size(); i++) { h ^= (unsigned int)src[i]; h *= 16777619u; }
    float t = (float)(h % 360u) / 360.0f;
    auto hue = [](float p, float q, float t) {
        if (t < 0.0f) t += 1.0f;
        if (t > 1.0f) t -= 1.0f;
        if (t < 1.0f / 6.0f) return p + (q - p) * 6.0f * t;
        if (t < 1.0f / 2.0f) return q;
        if (t < 2.0f / 3.0f) return p + (q - p) * (2.0f / 3.0f - t) * 6.0f;
        return p;
    };
    float q = 0.62f, p = q * (1.0f - 0.55f);
    float r = hue(p, q, t + 1.0f / 3.0f);
    float gg = hue(p, q, t);
    float b = hue(p, q, t - 1.0f / 3.0f);
    return C(r * 255.0f, gg * 255.0f, b * 255.0f, 0.98f);
}

// Los calendarios llevan dentro una linea X-WR-CALNAME con su nombre
// ("Citas medicas", "Trabajo"...). Se lee para saber de donde viene cada cita.
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
        // Parametros de la propiedad: TZID de la zona del evento y si es de dia entero.
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
            // Un evento de dia entero llega como VALUE=DATE sin hora: se marca
            // sin hora (hh = -1) para que no se confunda con una cita a medianoche.
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
            // Los calendarios pueden traer la misma cita con un minuto de
            // diferencia entre la entrada y su excepcion. Se redondea a
            // multiplos de 5 para que ambas se reconozcan como la misma,
            // sin desvirtuar la hora (2 min de desvio, como mucho).
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
// Minimal JSON helpers
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
    size_t e = js.find('"', p);
    if (e == std::string::npos) return false;
    out = js.substr(p, e - p);
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
// Caratulas por internet: utilidades puras (sin llamadas a Windows)
// ---------------------------------------------------------------------------

static std::wstring CvNorm(const std::wstring& s) {
    std::wstring o;
    for (size_t i = 0; i < s.size(); i++) {
        if (iswalnum((wint_t)s[i])) o += (wchar_t)towlower((wint_t)s[i]);
    }
    return o;
}

// Coincidencia laxa: una contiene a la otra (y ninguna es demasiado corta).
static bool CvLoose(const std::wstring& a, const std::wstring& b) {
    if (a.size() < 2 || b.size() < 2) return false;
    if (a.find(b) != std::wstring::npos || b.find(a) != std::wstring::npos) return true;
    // Por palabras: "summerof" encaja dentro de "102marcphilippesummerof..."
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
    return hits * 3 >= words * 2;   // dos de cada tres palabras bastan
}

// Quita (...) y [...], guiones bajos y el numero de pista inicial ("01 - ", "3. ").
// Limpia un nombre o un titulo para compararlo: fuera el numero de orden y su
// guion ("19 - ", "3. "), fuera lo que va entre parentesis, y guiones a espacios.
// Quita la extension del nombre de archivo, si la lleva.
static std::wstring CvStripExt(std::wstring t) {
    size_t d = t.rfind(L'.');
    if (d == std::wstring::npos) d = t.rfind(L'.');
    if (d == std::wstring::npos || d == 0) return t;
    std::wstring e = t.substr(d);
    for (size_t i = 0; i < e.size(); i++) e[i] = (wchar_t)towlower((wint_t)e[i]);
    const wchar_t* exts[] = {L".mp3", L".m4a", L".aac", L".flac", L".wav", L".ogg", L".wma", L".opus"};
    for (size_t k = 0; k < sizeof(exts) / sizeof(exts[0]); k++) {
        if (e == exts[k]) return t.substr(0, d);
    }
    return t;
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

// Elimina sufijos que describen la edicion, no el titulo principal.
// Ejemplo: "Umbrella Remix" se compara y se etiqueta como "Umbrella".
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

// "Artista feat. Otro", "A & B", "A, B" -> "Artista"
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

// Prepara artista y titulo para buscar. Si no hay artista y el titulo es
// "Artista - Titulo" (nombre de archivo sin etiquetas), se separa.
// "Unknown", "Desconocido" o vacio: no hay interprete de verdad.
static bool CvNoArtist(const std::wstring& a) {
    if (a.empty()) return true;
    std::wstring n = CvNorm(a);
    return n.empty() || n == L"unknown" || n == L"desconocido" || n == L"desconegut" ||
           n == L"varios" || n == L"various" || n == L"variousartists";
}

// Prepara interprete y titulo. El numero de orden ya se ha quitado, y si no hay
// interprete de verdad se parte el nombre por " - ", dando por hecho que el
// primero es el interprete.
static void CvSplitQuery(const std::wstring& artist, const std::wstring& title, std::wstring& outA,
                         std::wstring& outT) {
    std::wstring t = CvCoreTitle(title);
    std::wstring a = CvNoArtist(artist) ? std::wstring() : CvPrimaryArtist(artist);
    if (a.empty()) {
        size_t p = t.find(L" - ");
        if (p != std::wstring::npos && p > 0) {
            a = CvCleanTitle(t.substr(0, p));
            t = CvCoreTitle(t.substr(p + 3));
        }
    }
    outA = a;
    outT = t;
}

static bool CvTitleOk(const std::wstring& cand, const std::wstring& want) {
    return CvLoose(CvNorm(CvCoreTitle(cand)), CvNorm(CvCoreTitle(want)));
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

// Deshace los escapes de JSON (\" \\ \/ \n \uXXXX...) y devuelve UTF-8.
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

// iTunes Search: resultados separados por {"wrapperType". Se acepta el primero
// cuyo titulo y artista encajan; mejor sin caratula que con una equivocada.
static bool CvPickItunes(const std::string& js, const std::wstring& artist, const std::wstring& title,
                         std::string& url) {
    const std::string tag = "{\"wrapperType\"";
    size_t pos = js.find(tag);
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        std::string tn, an, au;
        if (JsonString(ch, 0, "trackName", tn) && JsonString(ch, 0, "artworkUrl100", au)) {
            JsonString(ch, 0, "artistName", an);
            if (CvTitleOk(CvJsonUnescape(tn), title) && CvArtistOk(CvJsonUnescape(an), artist)) {
                url = CvJsonUnescapeUtf8(au);
                size_t p = url.find("100x100bb");
                if (p != std::string::npos) url.replace(p, 9, "600x600bb");
                return true;
            }
        }
        pos = nx;
    }
    return false;
}

// Deezer: cada resultado empieza en "readable":; el primer "title" es el del tema,
// el primer "name" el del artista y cover_big la portada de 500 px.
static bool CvPickDeezer(const std::string& js, const std::wstring& artist, const std::wstring& title,
                         std::string& url) {
    const std::string tag = "\"readable\":";
    size_t pos = js.find(tag);
    while (pos != std::string::npos) {
        size_t nx = js.find(tag, pos + 1);
        std::string ch = js.substr(pos, nx == std::string::npos ? std::string::npos : nx - pos);
        std::string tn, an, cu;
        if (JsonString(ch, 0, "title", tn) && JsonString(ch, 0, "cover_big", cu)) {
            JsonString(ch, 0, "name", an);
            if (CvTitleOk(CvJsonUnescape(tn), title) && CvArtistOk(CvJsonUnescape(an), artist)) {
                url = CvJsonUnescapeUtf8(cu);
                return true;
            }
        }
        pos = nx;
    }
    return false;
}

// ---- ID3v2: leer lo justo y anadir una imagen de portada (APIC) ------------

struct Id3Info {
    bool hasTag = false;
    bool unsupported = false;  // etiqueta que no se debe tocar
    int ver = 3;
    size_t tagSize = 0;        // bytes tras la cabecera de 10
    size_t framesEnd = 0;      // fin de los fotogramas (antes del relleno)
    bool hasApic = false;
    std::wstring title, artist;
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
    if (info.ver != 3 && info.ver != 4) info.unsupported = true;  // v2.2 y otras: no se tocan
    if (flags & 0x80) info.unsupported = true;                    // desincronizacion
    if (flags & 0x40) info.unsupported = true;                    // cabecera extendida
    if (info.ver == 4 && (flags & 0x10)) info.unsupported = true; // pie
    if (info.tagSize > 64u * 1024u * 1024u) info.unsupported = true;
}

// Recorre los fotogramas. Si algo no cuadra, la etiqueta se marca como "no tocar".
static void Id3ParseFrames(const BYTE* tag, size_t n, Id3Info& info) {
    size_t pos = 0;
    while (pos + 10 <= n) {
        if (tag[pos] == 0) break;  // relleno
        unsigned sz = (info.ver == 4) ? CvSynchsafe(tag + pos + 4) : CvBE32(tag + pos + 4);
        if (sz == 0 || (size_t)sz > n - pos - 10) {
            info.unsupported = true;
            return;
        }
        const BYTE* fr = tag + pos;
        // Los flags de formato están en el segundo byte de flags del frame.
        // Si hay agrupación, compresión, cifrado o indicador de longitud,
        // no interpretamos el cuerpo como texto plano.
        bool special = (fr[9] & (info.ver == 4 ? 0x4F : 0xE0)) != 0;
        if (memcmp(fr, "APIC", 4) == 0) {
            info.hasApic = true;
        } else if (!special && memcmp(fr, "TIT2", 4) == 0) {
            info.title = Id3Text(fr + 10, sz);
        } else if (!special && memcmp(fr, "TPE1", 4) == 0) {
            info.artist = Id3Text(fr + 10, sz);
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

// Etiqueta nueva completa (cabecera + fotogramas existentes + APIC), sin relleno.
// Fotograma de texto ID3v2 (TIT2, TPE1...). UTF-8 en v2.4 y UTF-16 en v2.3.
static void Id3AddTextFrame(std::vector<BYTE>& out, int ver, const char* id,
                            const std::wstring& value) {
    if (value.empty()) return;
    std::vector<BYTE> body;
    if (ver == 4) {
        // ID3v2.4 admite UTF-8 (encoding 3).
        std::string u8 = ToUtf8(value);
        body.push_back(3);
        body.insert(body.end(), u8.begin(), u8.end());
        body.push_back(0);
    } else {
        // ID3v2.3 NO admite UTF-8: usa UTF-16 con BOM (encoding 1).
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

// Etiqueta nueva completa: fotogramas que ya tenia el archivo, titulo,
// interprete y la portada al final. El tamano se escribe cuando esta entera.
static std::vector<BYTE> Id3BuildWithCover(const Id3Info& info, const BYTE* tag, const BYTE* img,
                                           size_t imgN, int imgType, bool addCover = true) {
    const char* mime = (imgType == 2) ? "image/png" : "image/jpeg";
    int ver = info.hasTag ? info.ver : 3;
    size_t keep = info.hasTag ? info.framesEnd : 0;

    // Cuerpo APIC solo cuando el MP3 todavía no tiene portada.
    std::vector<BYTE> body;
    if (addCover) {
        body.push_back(0);
        for (const char* m = mime; *m; m++) body.push_back((BYTE)*m);
        body.push_back(0);
        body.push_back(0);
        body.push_back(0);
        body.push_back(3);
        body.push_back(0);
        body.insert(body.end(), img, img + imgN);
    }

    std::vector<BYTE> out;
    out.push_back('I'); out.push_back('D'); out.push_back('3');
    out.push_back((BYTE)ver); out.push_back(0); out.push_back(0);
    out.resize(10, 0);   // la cabecera se rellena al final
    // Copia los fotogramas que ya hubiera, menos TIT2 y TPE1: esos se
    // reescriben abajo con los datos de la cancion, para no dejarlos duplicados.
    if (keep) {
        size_t p = 0;
        while (p + 10 <= keep) {
            if (tag[p] == 0) break;
            unsigned fsz = (ver == 4) ? CvSynchsafe(tag + p + 4) : CvBE32(tag + p + 4);
            size_t full = 10 + (size_t)fsz;
            if (fsz == 0 || p + full > keep) break;
            bool drop = (memcmp(tag + p, "TIT2", 4) == 0) || (memcmp(tag + p, "TPE1", 4) == 0);
            if (!drop) out.insert(out.end(), tag + p, tag + p + full);
            p += full;
        }
    }

    if (!info.title.empty()) Id3AddTextFrame(out, ver, "TIT2", info.title);
    if (!info.artist.empty()) Id3AddTextFrame(out, ver, "TPE1", info.artist);

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

    size_t total = out.size() - 10;   // tamano real de la etiqueta
    if (total >= (1u << 28)) return std::vector<BYTE>();
    CvPutSynchsafe(&out[6], (unsigned)total);
    return out;
}


// "YYYY-MM-DDTHH:MM" -> absolute minutes (city time), -1 if malformed
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
// HTTP, tiempo e ICS (cada descarga corre en su propio hilo)
// ---------------------------------------------------------------------------

static bool HttpGetEx(const std::wstring& host, INTERNET_PORT port, bool secure, const std::wstring& path,
                      std::string& out, size_t cap) {
    out.clear();
    if (g_stop) return false;

    HINTERNET ses = WinHttpOpen(L"WindhawkGlassCards/5.0", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
                                WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!ses) {
        ses = WinHttpOpen(L"WindhawkGlassCards/5.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
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
            if (WinHttpSendRequest(req, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0) &&
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
        L"&forecast_days=7"
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

    // "Now" in the city's own clock, so other time zones work.
    std::string curTime;
    long long nowAbs = JsonString(js, cur, "time", curTime) ? AbsMinutes(curTime) : -1;

    // Rain in the next 90 minutes.
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

    // Next 24 hours.
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

    // Air quality and pollen (optional, never fatal).
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

static DWORD WINAPI FetchThread(LPVOID param) {
    FetchJob* job = static_cast<FetchJob*>(param);
    Weather* w = new Weather();
    bool ok = DoFetch(*job, *w);
    delete job;
    if (!PostThreadMessageW(g_threadId, WM_APP_WEATHER, ok ? 1 : 0, (LPARAM)w)) {
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

static DWORD WINAPI IcsThread(LPVOID param) {
    IcsJob* job = static_cast<IcsJob*>(param);
    IcsResult* res = new IcsResult();
    res->version = job->version;
    std::string body;
    bool ok = HttpGetUrl(job->url, body);
    if (ok) ParseIcs(body, res->ev, job->label, job->noName);
    delete job;
    if (!PostThreadMessageW(g_threadId, WM_APP_ICS, ok ? 1 : 0, (LPARAM)res)) {
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
// Weather text and kinds
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
// System sampling
// ---------------------------------------------------------------------------

static ULONGLONG FileTimeToU64(const FILETIME& f) {
    ULARGE_INTEGER u;
    u.LowPart = f.dwLowDateTime;
    u.HighPart = f.dwHighDateTime;
    return (ULONGLONG)u.QuadPart;
}

static void SampleCpu() {
    static ULONGLONG pIdle = 0, pKernel = 0, pUser = 0;
    static bool have = false;

    FILETIME fi, fk, fu;
    if (!GetSystemTimes(&fi, &fk, &fu)) return;
    ULONGLONG i = FileTimeToU64(fi);
    ULONGLONG k = FileTimeToU64(fk);
    ULONGLONG u = FileTimeToU64(fu);

    if (have) {
        ULONGLONG di = i - pIdle;
        ULONGLONG dk = k - pKernel;
        ULONGLONG du = u - pUser;
        ULONGLONG total = dk + du;
        if (total > 0) {
            double busy = (double)(total - di) * 100.0 / (double)total;
            if (busy < 0.0) busy = 0.0;
            if (busy > 100.0) busy = 100.0;
            g.cpu = busy;
            g.hist.push_back((float)busy);
            while (g.hist.size() > 60) g.hist.erase(g.hist.begin());
        }
    }
    pIdle = i;
    pKernel = k;
    pUser = u;
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

static void SampleGpu() {
    if (!g_gpuQ) return;
    if (PdhCollectQueryData(g_gpuQ) != ERROR_SUCCESS) return;

    DWORD bytes = 0, count = 0;
    PDH_STATUS s = PdhGetFormattedCounterArrayW(g_gpuC, PDH_FMT_DOUBLE, &bytes, &count, nullptr);
    if (s != (PDH_STATUS)PDH_MORE_DATA || bytes == 0) return;

    std::vector<BYTE> buf(bytes);
    PDH_FMT_COUNTERVALUE_ITEM_W* items = reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(buf.data());
    if (PdhGetFormattedCounterArrayW(g_gpuC, PDH_FMT_DOUBLE, &bytes, &count, items) != ERROR_SUCCESS)
        return;

    std::vector<std::pair<std::wstring, double> > per;
    for (DWORD i = 0; i < count; i++) {
        if (items[i].FmtValue.CStatus != PDH_CSTATUS_VALID_DATA &&
            items[i].FmtValue.CStatus != PDH_CSTATUS_NEW_DATA)
            continue;
        std::wstring nm = items[i].szName ? items[i].szName : L"";
        if (nm.find(L"engtype_3D") == std::wstring::npos) continue;

        std::wstring id;
        size_t a = nm.find(L"luid_");
        if (a != std::wstring::npos) {
            size_t b = nm.find(L"_phys", a);
            id = nm.substr(a, b == std::wstring::npos ? std::wstring::npos : b - a);
        }
        bool found = false;
        for (size_t j = 0; j < per.size(); j++) {
            if (per[j].first == id) {
                per[j].second += items[i].FmtValue.doubleValue;
                found = true;
                break;
            }
        }
        if (!found) per.push_back(std::make_pair(id, items[i].FmtValue.doubleValue));
    }

    double best = 0.0;
    for (size_t j = 0; j < per.size(); j++) {
        if (per[j].second > best) best = per[j].second;
    }
    g_gpu = best > 100.0 ? 100.0 : best;
}

static void CloseGpu() {
    if (g_gpuQ) {
        PdhCloseQuery(g_gpuQ);
        g_gpuQ = nullptr;
        g_gpuC = nullptr;
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
            PROCESS_MEMORY_COUNTERS pmc;
            memset(&pmc, 0, sizeof(pmc));
            pmc.cb = sizeof(pmc);
            double ram = 0.0;
            if (GetProcessMemoryInfo(h, &pmc, sizeof(pmc))) ram = (double)pmc.WorkingSetSize / 1048576.0;
            CloseHandle(h);
            if (!okT) continue;

            ProcPrev pp;
            pp.pid = pe.th32ProcessID;
            pp.t = tot;
            cur.push_back(pp);

            double cpu = 0.0;
            if (dtWall > 0.0) {
                for (size_t j = 0; j < g.procPrev.size(); j++) {
                    if (g.procPrev[j].pid == pp.pid && tot >= g.procPrev[j].t) {
                        cpu = (double)(tot - g.procPrev[j].t) * 100.0 / (dtWall * ncpu);
                        break;
                    }
                }
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
    g.procs = all;
}

// ---------------------------------------------------------------------------
// Multimedia (sesiones de Windows; solo teclas multimedia si no hay C++/WinRT)
// ---------------------------------------------------------------------------

static const float kThumbU = 80.0f;   // lado de la caratula, en unidades de la tarjeta
static int    g_thumbGen = 0;
static bool   g_thumbBusy = false;
static bool   g_thumbRedo = false;
static int    g_thumbRetry = 0;
static HANDLE g_thumbThread = nullptr;
// Ultima imagen aceptada del reproductor: permite detectar cuando Windows
// entrega la miniatura de la pista anterior junto con los metadatos nuevos.
static volatile LONG64 g_lastPlayerThumbHash = 0;
static volatile LONG g_propsFromTimer = 0;
static std::wstring g_curCoverKey;          // clave de la caratula descargada del tema actual
static volatile LONG g_embedPending = 1;     // puede haber MP3 pendientes de incrustar
static HANDLE g_embedThread = nullptr;

static void ClearThumb() {
    g_thumbGen++;
    if (g.thumbOk || !g.thumbPx.empty()) {
        g.thumbOk = false;
        g.thumbPx.clear();
        g.cards[CARD_MEDIA].dirty = true;
    }
}

#if GH_HAVE_WINRT
using namespace winrt::Windows::Media::Control;
static bool g_winrtInit = false;
static GlobalSystemMediaTransportControlsSessionManager g_mgr{nullptr};
static ULONGLONG g_mediaLast = 0;
static double g_mediaRaw = -1.0;
// Las propiedades (titulo, artista) solo se piden cuando el reproductor avisa
// de que han cambiado: la llamada .get() puede tardar y bloquea el hilo de la UI.
static GlobalSystemMediaTransportControlsSession g_sess{nullptr};
static winrt::event_token g_propTok{};
static volatile LONG g_propsDirty = 1;
static std::wstring g_sessId;

static void ReleaseMediaSession() {
    try {
        if (g_sess) g_sess.MediaPropertiesChanged(g_propTok);
    } catch (...) {
    }
    g_sess = nullptr;
    g_sessId.clear();
}

#if GH_HAVE_THUMB
static winrt::Windows::Storage::Streams::IRandomAccessStreamReference g_thumbRef{nullptr};

// ---------------------------------------------------------------------------
// Cache de caratulas y busqueda en internet (carpeta propia del mod)
// ---------------------------------------------------------------------------

static std::wstring CvCacheDir() {
    static std::wstring dir;
    static bool tried = false;
    if (tried) return dir;
    tried = true;
    wchar_t buf[MAX_PATH];
    DWORD n = GetEnvironmentVariableW(L"LOCALAPPDATA", buf, MAX_PATH);
    if (!n || n >= MAX_PATH) return dir;
    std::wstring d = buf;
    d += L"\\WindhawkGlassCards";
    CreateDirectoryW(d.c_str(), nullptr);
    d += L"\\covers";
    CreateDirectoryW(d.c_str(), nullptr);
    DWORD at = GetFileAttributesW(d.c_str());
    if (at != INVALID_FILE_ATTRIBUTES && (at & FILE_ATTRIBUTE_DIRECTORY)) dir = d;
    return dir;
}

static std::wstring CvKeyName(const std::wstring& artist, const std::wstring& title) {
    std::wstring k = CvNorm(artist) + L"|" + CvNorm(title);
    unsigned long long h = 1469598103934665603ULL;  // FNV-1a de 64 bits
    for (size_t i = 0; i < k.size(); i++) {
        h ^= (unsigned long long)(unsigned short)k[i];
        h *= 1099511628211ULL;
    }
    static const wchar_t* hex = L"0123456789abcdef";
    std::wstring o;
    for (int sh = 60; sh >= 0; sh -= 4) o += hex[(h >> sh) & 0xF];
    return o;
}

// No se busca en internet para navegadores: casi siempre son videos, no musica.
static bool CvIsBrowserSession() {
    std::wstring id = g_sessId;
    for (size_t i = 0; i < id.size(); i++) id[i] = (wchar_t)towlower((wint_t)id[i]);
    static const wchar_t* names[] = {L"chrome", L"msedge", L"firefox", L"opera", L"brave", L"vivaldi", L"iexplore"};
    for (size_t k = 0; k < sizeof(names) / sizeof(names[0]); k++) {
        if (id.find(names[k]) != std::wstring::npos) return true;
    }
    return false;
}

static bool CvFileExists(const std::wstring& p) {
    DWORD a = GetFileAttributesW(p.c_str());
    return a != INVALID_FILE_ATTRIBUTES && !(a & FILE_ATTRIBUTE_DIRECTORY);
}

// Horas desde la ultima escritura; -1 si no existe.
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

// Escribe en un temporal y lo renombra: nunca queda un archivo a medias.
static bool CvWriteFile(const std::wstring& p, const void* data, size_t n) {
    std::wstring tmp = p + L".tmp";
    HANDLE h = CreateFileW(tmp.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    DWORD wr = 0;
    bool ok = (n == 0) || (WriteFile(h, data, (DWORD)n, &wr, nullptr) && wr == n);
    CloseHandle(h);
    if (ok) ok = MoveFileExW(tmp.c_str(), p.c_str(), MOVEFILE_REPLACE_EXISTING) != 0;
    if (!ok) DeleteFileW(tmp.c_str());
    return ok;
}

static int CvImageType(const std::vector<BYTE>& b) {
    if (b.size() >= 4 && b[0] == 0xFF && b[1] == 0xD8 && b[2] == 0xFF) return 1;  // JPEG
    if (b.size() >= 8 && b[0] == 0x89 && b[1] == 0x50 && b[2] == 0x4E && b[3] == 0x47) return 2;  // PNG
    return 0;
}

static bool CvDownload(const std::string& url8, std::vector<BYTE>& out) {
    std::string body;
    if (url8.compare(0, 8, "https://") != 0) return false;  // solo conexiones seguras
    if (!HttpGetUrl(FromUtf8(url8), body)) return false;
    out.assign(body.begin(), body.end());
    return out.size() >= 2048 && out.size() <= 4u * 1024u * 1024u && CvImageType(out) != 0;
}

// 1 = encontrada, 0 = los servicios respondieron pero no hay coincidencia, -1 = sin conexion.
static int CvSearchNet(const std::wstring& artist, const std::wstring& title, std::vector<BYTE>& out) {
    bool reach = false;
    std::string js, url;
    std::wstring term = artist.empty() ? title : (artist + L" " + title);
    if (HttpGet(L"itunes.apple.com", L"/search?term=" + UrlEncode(term) + L"&media=music&entity=song&limit=10", js)) {
        reach = true;
        if (CvPickItunes(js, artist, title, url) && CvDownload(url, out)) return 1;
    }
    if (g_stop) return -1;
    js.clear();
    url.clear();
    std::wstring q = artist.empty()
                         ? (L"track:\"" + title + L"\"")
                         : (L"artist:\"" + artist + L"\" track:\"" + title + L"\"");
    if (HttpGet(L"api.deezer.com", L"/search?q=" + UrlEncode(q) + L"&limit=10", js)) {
        reach = true;
        if (CvPickDeezer(js, artist, title, url) && CvDownload(url, out)) return 1;
    }
    return reach ? 0 : -1;
}

// Mantiene la carpeta acotada: si pasa de 1500 archivos, borra los 500 mas antiguos.
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

// Cache primero; si no esta y hay permiso, busca en internet y la guarda.
// Un "no hay coincidencia" tambien se recuerda (7 dias) para no repetir la consulta.
static bool CvGetCover(const std::wstring& key, const std::wstring& artist, const std::wstring& title, bool net,
                       std::vector<BYTE>& out) {
    std::wstring dir = CvCacheDir();
    if (dir.empty()) return false;
    // La clave se recalcula aqui, con el titulo y el interprete de ESTA cancion.
    // Antes se arrastraba de fuera y podia ser la de la cancion anterior: asi
    // fue como la caratula de un tema acabo escrita en el MP3 de otro.
    std::wstring qA, qT;
    CvSplitQuery(artist, title, qA, qT);
    if (qT.empty()) qT = CvCleanTitle(title);
    std::wstring safeKey = (artist.empty() && title.empty()) ? key : CvKeyName(qA, qT);
    std::wstring base = dir + L"\\" + safeKey;
    if (CvReadFile(base + L".img", out, 4u << 20) && CvImageType(out) != 0) return true;
    if (!net || g_stop) return false;
    int age = CvFileAgeHours(base + L".none");
    if (age >= 0 && age < 24 * 7) return false;
    int r = CvSearchNet(artist, title, out);
    if (r == 1) {
        CvWriteFile(base + L".img", out.data(), out.size());
        CvPrune(dir);
        return true;
    }
    if (r == 0) CvTouch(base + L".none");
    return false;
}

// ---------------------------------------------------------------------------
// Incrustar la caratula en el MP3 (opcional)
// ---------------------------------------------------------------------------

enum CvEmbedRes { EMB_OK, EMB_ALREADY, EMB_SKIP, EMB_LOCKED, EMB_ERROR };

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

// Reabre el archivo temporal y comprueba la etiqueta desde disco. No basta
// con que WriteFile haya terminado: solo se sustituye el original si el parser
// vuelve a encontrar los tres frames y sus valores exactos.
static bool CvVerifyEmbeddedFile(const std::wstring& path, const std::wstring& wantTitle,
                                 const std::wstring& wantArtist) {
    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ,
                           FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                           nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    Id3Info check;
    std::vector<BYTE> checkTag;
    bool ok = CvReadTag(h, check, checkTag);
    CloseHandle(h);
    if (!ok || check.unsupported || !check.hasTag || !check.hasApic) return false;
    if (!wantTitle.empty() && CvNorm(check.title) != CvNorm(wantTitle)) return false;
    if (!wantArtist.empty() && CvNorm(check.artist) != CvNorm(wantArtist)) return false;
    return true;
}

// Reescribe el MP3 con la imagen anadida a su etiqueta ID3v2. El audio se copia
// tal cual; el original solo se sustituye cuando la copia esta completa y
// comprobada, y conserva sus fechas. Si el archivo esta bloqueado no se toca.
static CvEmbedRes CvEmbed(const std::wstring& path, const std::vector<BYTE>& img,
                           const std::wstring& wantTitle, const std::wstring& wantArtist) {
    int type = CvImageType(img);
    if (!type) return EMB_ERROR;
    DWORD attrs = GetFileAttributesW(path.c_str());
    if (attrs == INVALID_FILE_ATTRIBUTES) return EMB_ERROR;
    if (attrs & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_REPARSE_POINT)) return EMB_SKIP;

    HANDLE src = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (src == INVALID_HANDLE_VALUE) {
        return GetLastError() == ERROR_SHARING_VIOLATION ? EMB_LOCKED : EMB_ERROR;
    }
    LARGE_INTEGER fsz;
    if (!GetFileSizeEx(src, &fsz) || fsz.QuadPart < 4096 || fsz.QuadPart > 400LL * 1024 * 1024) {
        CloseHandle(src);
        return EMB_SKIP;
    }
    FILETIME ct, at, wt;
    bool haveTimes = GetFileTime(src, &ct, &at, &wt) != 0;

    Id3Info info;
    std::vector<BYTE> tag;
    if (!CvReadTag(src, info, tag)) {
        CloseHandle(src);
        return EMB_ERROR;
    }
    if (info.unsupported) {
        CloseHandle(src);
        return EMB_SKIP;
    }
    // Si ya hay portada no la sustituimos, pero sí completamos TIT2/TPE1
    // cuando falten. Así no se da por terminado un MP3 con metadatos incompletos.
    // Solo se considera correcto si el texto ID3 coincide con el dato esperado.
    // CvTitleOk por sí solo también acepta variantes (p. ej. "Umbrella Remix"),
    // pero aquí debemos corregirlas y también sustituir valores incorrectos.
    bool needTitle = !wantTitle.empty() &&
                     (info.title.empty() ||
                      !CvTitleOk(info.title, wantTitle) ||
                      CvNorm(info.title) != CvNorm(wantTitle));
    bool needArtist = !wantArtist.empty() &&
                      (info.artist.empty() || !CvArtistOk(info.artist, wantArtist) ||
                       CvNorm(info.artist) != CvNorm(wantArtist));
    Wh_Log(L"Empotrar ID3: ver=%d tag=%d bytes=%u APIC=%d TIT2='%s' TPE1='%s' needTitle=%d needArtist=%d",
           info.ver, info.hasTag ? 1 : 0, (unsigned)info.tagSize, info.hasApic ? 1 : 0,
           info.title.c_str(), info.artist.c_str(), needTitle ? 1 : 0, needArtist ? 1 : 0);
    if (info.hasApic && !needTitle && !needArtist) {
        CloseHandle(src);
        return EMB_ALREADY;
    }
    // Se escriben el titulo y el interprete de la cancion, no los que trajera
    // el archivo: si no los tenia, ahora los tendra.
    Id3Info build = info;
    if (!wantTitle.empty()) build.title = wantTitle;
    if (!wantArtist.empty()) build.artist = wantArtist;
    std::vector<BYTE> head = Id3BuildWithCover(build, tag.data(), img.data(), img.size(), type, !info.hasApic);
    unsigned long long audioOff = info.hasTag ? 10ULL + info.tagSize : 0ULL;
    if (head.empty() || audioOff >= (unsigned long long)fsz.QuadPart) {
        CloseHandle(src);
        return EMB_SKIP;
    }

    std::wstring tmp = path + L".gcover.tmp";
    HANDLE dst = CreateFileW(tmp.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (dst == INVALID_HANDLE_VALUE) {
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
    CloseHandle(dst);
    CloseHandle(src);
    if (!ok) {
        DeleteFileW(tmp.c_str());
        return EMB_ERROR;
    }
    if (!CvVerifyEmbeddedFile(tmp, wantTitle, wantArtist)) {
        Wh_Log(L"Empotrar: verificacion ID3 fallida en el temporal; se conserva el MP3 original (%s)", path.c_str());
        DeleteFileW(tmp.c_str());
        return EMB_ERROR;
    }
    if (!MoveFileExW(tmp.c_str(), path.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
        DWORD e = GetLastError();
        DeleteFileW(tmp.c_str());
        return (e == ERROR_SHARING_VIOLATION || e == ERROR_ACCESS_DENIED || e == ERROR_LOCK_VIOLATION) ? EMB_LOCKED
                                                                                                   : EMB_ERROR;
    }
    return EMB_OK;
}

// Comprueba (por la etiqueta o, si no hay, por el nombre) que el MP3 es el tema buscado.
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
    // Un TIT2 incorrecto no debe impedir reparar el archivo si su nombre
    // identifica claramente la pista. Si el nombre tampoco coincide, se descarta.
    if (!info.title.empty() && !CvTitleOk(info.title, title) &&
        !CvLoose(nameNorm, CvNorm(CvCoreTitle(title)))) return false;
    // Sin etiqueta TIT2, o con una etiqueta incorrecta, el nombre debe contener
    // el titulo principal; el prefijo numerico y "Remix" no afectan al cotejo.
    if (info.title.empty() && !CvLoose(nameNorm, CvNorm(CvCoreTitle(title)))) return false;
    if (CvNoArtist(artist)) return true;   // sin interprete de verdad, no se exige
    // El nombre puede ser "Artista - Titulo" o "Titulo - Artista": buscamos
    // ambos componentes por separado y no dependemos de su orden.
    std::wstring nA = CvNorm(CvPrimaryArtist(artist));
    // Si el TPE1 existe pero es incorrecto, permitimos reparar solo cuando
    // nombre o carpeta confirman el artista esperado.
    if (!info.artist.empty() && CvArtistOk(info.artist, artist)) return true;
    return nA.size() >= 2 && (nameNorm.find(nA) != std::wstring::npos || dirNorm.find(nA) != std::wstring::npos);
}

static bool CvFindMp3(const std::wstring& root, const std::wstring& nTitle, const std::wstring& title,
                      const std::wstring& artist, int depth, int& budget, ULONGLONG deadline, std::wstring& found) {
    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileExW((root + L"\\*").c_str(), FindExInfoBasic, &fd, FindExSearchNameMatch, nullptr,
                                FIND_FIRST_EX_LARGE_FETCH);
    if (h == INVALID_HANDLE_VALUE) return false;
    bool got = false;
    do {
        if (g_stop || budget <= 0 || GetTickCount64() > deadline) break;
        std::wstring name = fd.cFileName;
        if (name == L"." || name == L"..") continue;
        std::wstring full = root + L"\\" + name;
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if ((fd.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) || depth >= 8) continue;
            if (CvFindMp3(full, nTitle, title, artist, depth + 1, budget, deadline, found)) {
                got = true;
                break;
            }
            continue;
        }
        size_t dot = name.rfind(L'.');
        if (dot == std::wstring::npos) continue;
        std::wstring ext = name.substr(dot);
        for (size_t i = 0; i < ext.size(); i++) ext[i] = (wchar_t)towlower((wint_t)ext[i]);
        if (ext != L".mp3") continue;
        budget--;
        std::wstring nName = CvNorm(name.substr(0, dot));
        if (!CvLoose(nName, nTitle)) {
            Wh_Log(L"Empotrar: descartado '%s' (no encaja con el titulo)", name.c_str());
            continue;
        }
        if (CvVerifyMp3(full, nName, CvNorm(root), title, artist)) {
            found = full;
            got = true;
            break;
        }
    } while (FindNextFileW(h, &fd));
    FindClose(h);
    return got;
}

static std::wstring CvReadPend(const std::wstring& p) {
    std::vector<BYTE> b;
    if (!CvReadFile(p, b, 8192) || b.size() < 4) return std::wstring();
    std::wstring w(reinterpret_cast<const wchar_t*>(b.data()), b.size() / sizeof(wchar_t));
    while (!w.empty() && w.back() == L'\0') w.pop_back();
    return w;
}

struct EmbedJob {
    std::wstring key, artist, title;
    std::vector<std::wstring> dirs;
};

// Una caratula: localiza el MP3 (o usa el ya localizado y pendiente) e intenta incrustarla.
static void CvEmbedOne(const std::wstring& dir, const std::wstring& key, const std::wstring& artist,
                       const std::wstring& title, const std::vector<std::wstring>& dirs) {
    Wh_Log(L"Empotrar: buscando MP3 para '%s' de '%s'", title.c_str(), artist.c_str());
    std::wstring qA, qT;
    CvSplitQuery(artist, title, qA, qT);
    if (qT.empty()) qT = CvCleanTitle(title);
    std::wstring safeKey = (artist.empty() && title.empty()) ? key : CvKeyName(qA, qT);
    std::wstring base = dir + L"\\" + safeKey;
    // El marcador .emb2 ya no basta para omitir el archivo: versiones anteriores
    // podían crearlo aunque faltasen TIT2/TPE1. Se vuelve a leer el ID3 y CvEmbed
    // decide si está completo; si lo está, devuelve EMB_ALREADY sin reescribir.
    if (CvFileExists(base + L".emb2"))
        Wh_Log(L"Empotrar: verificando de nuevo los metadatos del MP3 (%s.emb2)", base.c_str());
    std::vector<BYTE> img;
    if (!CvReadFile(base + L".img", img, 4u << 20)) {
        Wh_Log(L"Empotrar: no hay imagen en cache (%s.img); no se puede incrustar", base.c_str());
        DeleteFileW((base + L".pend").c_str());
        return;
    }
    if (CvImageType(img) == 0) {
        Wh_Log(L"Empotrar: la imagen de cache no es JPEG/PNG valido (%s.img)", base.c_str());
        DeleteFileW((base + L".pend").c_str());
        return;
    }
    std::wstring path;
    bool pending = CvFileExists(base + L".pend");
    if (pending) {
        std::wstring pendRaw = CvReadPend(base + L".pend");
        size_t nl = pendRaw.find(L'\n');
        if (nl != std::wstring::npos) {
            path = pendRaw.substr(0, nl);
            std::wstring resto = pendRaw.substr(nl + 1);
            size_t nl2 = resto.find(L'\n');
            if (nl2 != std::wstring::npos) {
                qT = resto.substr(0, nl2);
                qA = resto.substr(nl2 + 1);
            }
        } else {
            path = pendRaw;
        }
    } else {
        int age = CvFileAgeHours(base + L".noemb");
        if (age >= 0 && age < 24) {
            Wh_Log(L"Empotrar: busqueda omitida; ya se intento hace menos de 24 horas (%s.noemb)", base.c_str());
            return;
        }
        std::wstring nT = CvNorm(qT);
        if (nT.size() < 2) return;
        int budget = 40000;
        ULONGLONG deadline = GetTickCount64() + 15000;
        for (size_t i = 0; i < dirs.size() && path.empty(); i++) {
            CvFindMp3(dirs[i], nT, qT, qA, 0, budget, deadline, path);
        }
        if (path.empty()) {
            Wh_Log(L"Empotrar: no se encontro el MP3 de '%s'", title.c_str());
            if (!g_stop) CvTouch(base + L".noemb");
            return;
        }
    }
    if (path.empty()) {
        DeleteFileW((base + L".pend").c_str());
        return;
    }
    // Se separa el nombre para saber que es interprete y que es titulo.
    // La version ("Remix") se deja en el titulo, entre parentesis.
    if (qT.empty()) qT = CvCleanTitle(title);
    Wh_Log(L"Empotrar: '%s' titulo='%s' interprete='%s'", path.c_str(), qT.c_str(), qA.c_str());
    // Antes de escribir se comprueba que la imagen y los datos son de ESTA
    // cancion. Si no cuadra, no se toca el archivo.
    std::wstring keyEsperada = CvKeyName(qA, qT);
    if (keyEsperada != safeKey) {
        Wh_Log(L"Empotrar: no cuadra la clave de '%s': se omite", path.c_str());
        return;
    }
    CvEmbedRes r = CvEmbed(path, img, qT, qA);
    switch (r) {
        case EMB_OK:
            Wh_Log(L"Empotrar: ESCRITO en '%s'", path.c_str());
            Wh_Log(L"Caratula incrustada en: %s", path.c_str());
            CvTouch(base + L".emb2");
            DeleteFileW((base + L".pend").c_str());
            break;
        case EMB_ALREADY:
            CvTouch(base + L".emb2");  // portada y metadatos ya estaban correctos
            DeleteFileW((base + L".pend").c_str());
            Wh_Log(L"Empotrar: portada, titulo e interprete ya eran correctos en '%s'", path.c_str());
            break;
        case EMB_SKIP:
            // No crear .emb2: un formato no compatible o archivo protegido no
            // significa que sus metadatos estén completos.
            Wh_Log(L"Empotrar: no se pudo modificar el formato/archivo '%s'; se conserva para reintento", path.c_str());
            DeleteFileW((base + L".pend").c_str());
            break;
        case EMB_LOCKED: {
            // El reproductor tiene el archivo abierto: se apunta y se reintenta mas tarde.
            // El pendiente guarda tambien la cancion: ruta, titulo e interprete,
            // para que el reintento sepa a quien pertenece.
            std::wstring pend = path + L"\n" + qT + L"\n" + qA;
            CvWriteFile(base + L".pend", pend.c_str(), (pend.size() + 1) * sizeof(wchar_t));
            InterlockedExchange(&g_embedPending, 1);
            break;
        }
        default:
            CvTouch(base + L".noemb");
            DeleteFileW((base + L".pend").c_str());
            break;
    }
}

static void CvRetryPending(const std::wstring& dir, const std::wstring& skipKey, const std::vector<std::wstring>& dirs) {
    bool left = false;
    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileW((dir + L"\\*.pend").c_str(), &fd);
    if (h == INVALID_HANDLE_VALUE) {
        InterlockedExchange(&g_embedPending, 0);
        return;
    }
    do {
        if (g_stop) break;
        std::wstring name = fd.cFileName;
        if (name.size() < 6) continue;
        std::wstring key = name.substr(0, name.size() - 5);
        if (key == skipKey) {  // es el tema que suena ahora: seguira bloqueado
            left = true;
            continue;
        }
        CvEmbedOne(dir, key, L"", L"", dirs);
        if (CvFileExists(dir + L"\\" + name)) left = true;
    } while (FindNextFileW(h, &fd));
    FindClose(h);
    InterlockedExchange(&g_embedPending, left ? 1 : 0);
}

static DWORD WINAPI EmbedThread(LPVOID param) {
    EmbedJob* j = static_cast<EmbedJob*>(param);
    std::wstring dir = CvCacheDir();
    if (!dir.empty()) {
        if (!j->key.empty()) CvEmbedOne(dir, j->key, j->artist, j->title, j->dirs);
        CvRetryPending(dir, j->key, j->dirs);
    }
    delete j;
    return 0;
}

static void StartEmbedThread(const std::wstring& key, const std::wstring& artist, const std::wstring& title) {
    if (g_embedThread) {
        if (WaitForSingleObject(g_embedThread, 0) != WAIT_OBJECT_0) return;  // ocupado: se reintentara
        CloseHandle(g_embedThread);
        g_embedThread = nullptr;
    }
    if (CvCacheDir().empty()) return;
    EmbedJob* j = new EmbedJob();
    j->key = key;
    j->artist = artist;
    j->title = title;
    j->dirs = g.musicDirs;
    if (j->dirs.empty()) {
        wchar_t up[MAX_PATH];
        DWORD n = GetEnvironmentVariableW(L"USERPROFILE", up, MAX_PATH);
        if (n > 0 && n < MAX_PATH) j->dirs.push_back(std::wstring(up) + L"\\Music");
    }
    g_embedThread = CreateThread(nullptr, 0, EmbedThread, j, 0, nullptr);
    if (!g_embedThread) delete j;
}

// ---------------------------------------------------------------------------
// Miniatura: la del reproductor o, si no hay, la de la cache / internet
// ---------------------------------------------------------------------------

struct ThumbJob {
    winrt::Windows::Storage::Streams::IRandomAccessStreamReference ref{nullptr};
    int gen = 0;
    int size = 0;
    std::wstring artist, title;
    bool online = false;
};

// Decodifica una imagen como un cuadrado size x size recortado por el centro.
static bool ThumbDecode(winrt::Windows::Storage::Streams::IRandomAccessStream const& stream, int size,
                        ThumbResult* r) {
    using namespace winrt::Windows::Graphics::Imaging;
    if (size < 16) return false;
    auto dec = BitmapDecoder::CreateAsync(stream).get();
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
    auto pd = dec.GetPixelDataAsync(BitmapPixelFormat::Bgra8, BitmapAlphaMode::Premultiplied, tr,
                                    ExifOrientationMode::IgnoreExifOrientation, ColorManagementMode::DoNotColorManage)
                  .get();
    auto bytes = pd.DetachPixelData();
    if (bytes.size() < (size_t)S * S * 4) return false;
    r->px.resize((size_t)S * S);
    memcpy(r->px.data(), bytes.data(), (size_t)S * S * 4);
    r->ok = true;
    return true;
}

static DWORD WINAPI ThumbThread(LPVOID param) {
    ThumbJob* job = static_cast<ThumbJob*>(param);
    ThumbResult* r = new ThumbResult();
    r->gen = job->gen;
    r->size = job->size;
    try {
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
    } catch (...) {
    }
    bool done = false;
    // Estos datos deben acompañar también a la miniatura que entrega el propio
    // reproductor (antes solo se rellenaban en la descarga de internet).
    std::wstring qa, qt;
    CvSplitQuery(job->artist, job->title, qa, qt);
    if (qt.empty()) qt = CvCleanTitle(job->title);
    if (!qt.empty()) {
        r->key = CvKeyName(qa, qt);
        r->artist = qa;
        r->title = qt;
    }
    if (job->ref) {
        try {
            auto st = job->ref.OpenReadAsync().get();
            // Conserva el archivo JPEG/PNG original para poder incrustarlo
            // después; los píxeles decodificados por sí solos no sirven para APIC.
            uint64_t encodedSize = st.Size();
            // No imponer un minimo de 2 KB: algunas caratulas JPEG pequeñas son validas.
            if (encodedSize >= 64 && encodedSize <= (4u << 20)) {
                using namespace winrt::Windows::Storage::Streams;
                DataReader reader(st.GetInputStreamAt(0));
                uint32_t loaded = reader.LoadAsync((uint32_t)encodedSize).get();
                if (loaded == encodedSize) {
                    std::vector<BYTE> encoded(loaded);
                    reader.ReadBytes(winrt::array_view<uint8_t>(encoded.data(), encoded.data() + encoded.size()));
                    if (CvImageType(encoded) != 0 && !r->key.empty()) {
                        // FNV-1a sobre los bytes originales. Si coincide con la
                        // portada de la pista anterior, Windows probablemente ha
                        // entregado una miniatura atrasada: no la asociamos a esta pista.
                        uint64_t hash = 1469598103934665603ULL;
                        for (BYTE b : encoded) { hash ^= b; hash *= 1099511628211ULL; }
                        r->sourceHash = hash;
                        LONG64 previous = InterlockedCompareExchange64(&g_lastPlayerThumbHash, 0, 0);
                        if (previous != 0 && (uint64_t)previous == hash) {
                            Wh_Log(L"Miniatura del reproductor repetida para otra pista; se descarta como posiblemente obsoleta");
                            std::wstring cache = CvCacheDir();
                            if (!cache.empty()) {
                                DeleteFileW((cache + L"\\" + r->key + L".img").c_str());
                                // Si la portada incorrecta ya se habia incrustado,
                                // permite repetir la operacion con la imagen correcta.
                                DeleteFileW((cache + L"\\" + r->key + L".emb2").c_str());
                            }
                        } else {
                            std::wstring cache = CvCacheDir();
                            if (!cache.empty()) {
                                bool saved = CvWriteFile(cache + L"\\" + r->key + L".img", encoded.data(), encoded.size());
                                Wh_Log(L"Empotrar: imagen original %s (%llu bytes)", saved ? L"guardada en cache" : L"NO se pudo guardar", (unsigned long long)encoded.size());
                            }
                            st.Seek(0);
                            done = ThumbDecode(st, job->size, r);
                        }
                    }
                }
                reader.Close();
            }
            if (!done && r->sourceHash == 0) {
                st.Seek(0);
                done = ThumbDecode(st, job->size, r);
            }
        } catch (...) {
            done = false;
            r->ok = false;
        }
    }
    // Sin imagen del reproductor: cache local y, si se permite, internet.
    if (!done && !job->title.empty() && !g_stop) {
        try {
            if (!qt.empty()) {
                std::wstring key = r->key;
                std::vector<BYTE> bytes;
                if (CvGetCover(key, qa, qt, job->online, bytes)) {
                    using namespace winrt::Windows::Storage::Streams;
                    InMemoryRandomAccessStream ms;
                    DataWriter dw(ms);
                    dw.WriteBytes(winrt::array_view<const uint8_t>(bytes.data(), bytes.data() + bytes.size()));
                    dw.StoreAsync().get();
                    dw.DetachStream();
                    ms.Seek(0);
                    if (ThumbDecode(ms, job->size, r)) {
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
    try {
        job->ref = nullptr;  // se suelta con el apartamento todavia iniciado
    } catch (...) {
    }
    delete job;
    if (!PostThreadMessageW(g_threadId, WM_APP_THUMB, 0, (LPARAM)r)) delete r;
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
    CvCacheDir();  // se crea aqui, en el hilo de la interfaz, antes de lanzar hilos
    ThumbJob* job = new ThumbJob();
    job->ref = g_thumbRef;
    job->gen = ++g_thumbGen;
    job->size = ClampInt((int)(kThumbU * g.kLast + 0.5f), 32, 256);
    job->artist = g.media.artist;
    job->title = g.media.title;
    job->online = g.onlineCovers && !CvIsBrowserSession();
    g_thumbThread = CreateThread(nullptr, 0, ThumbThread, job, 0, nullptr);
    if (!g_thumbThread) {
        delete job;
        return;
    }
    g_thumbBusy = true;
}
#else
static void StartThumbThread() {}
static void StartEmbedThread(const std::wstring&, const std::wstring&, const std::wstring&) {}
#endif

static void ShutdownMedia() {
    ReleaseMediaSession();
#if GH_HAVE_THUMB
    g_thumbRef = nullptr;
#endif
    g_mgr = nullptr;
}

static void SampleMedia() {
    try {
        if (!g_winrtInit) {
            g_winrtInit = true;
            try {
                winrt::init_apartment(winrt::apartment_type::multi_threaded);
            } catch (...) {
            }
        }
        if (!g_mgr) g_mgr = GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
        auto s = g_mgr.GetCurrentSession();
        if (!s) {
            ReleaseMediaSession();  // la proxima sesion se vuelve a suscribir
#if GH_HAVE_THUMB
            g_thumbRef = nullptr;
#endif
            ClearThumb();
            g.media.valid = false;
            return;
        }
        std::wstring sid = std::wstring(s.SourceAppUserModelId().c_str());
        if (!g_sess || sid != g_sessId) {
            ReleaseMediaSession();
            g_sess = s;
            g_sessId = sid;
            g_propTok = s.MediaPropertiesChanged([](auto&&, auto&&) {
                InterlockedExchange(&g_propsFromTimer, 0);
                InterlockedExchange(&g_propsDirty, 1);
            });
            InterlockedExchange(&g_propsDirty, 1);
        }
        {
            // Red de seguridad: aunque no llegue el aviso, se refresca cada 15 s.
            static ULONGLONG s_propsAt = 0;
            ULONGLONG nowP = GetTickCount64();
            if (nowP - s_propsAt > 15000) {
                s_propsAt = nowP;
                if (InterlockedCompareExchange(&g_propsDirty, 1, 0) == 0) InterlockedExchange(&g_propsFromTimer, 1);
            }
        }
        if (InterlockedExchange(&g_propsDirty, 0)) {
            bool fromTimer = InterlockedExchange(&g_propsFromTimer, 0) != 0;
            try {
                auto props = s.TryGetMediaPropertiesAsync().get();
                std::wstring nt = std::wstring(props.Title().c_str());
                std::wstring na = std::wstring(props.Artist().c_str());
                // Algunos reproductores devuelven el nombre del archivo como
                // Title y dejan Artist vacio cuando faltan etiquetas ID3.
                // Si el nombre sigue el formato "04 - Rihanna - Umbrella Remix",
                // recuperamos artista y titulo para la tarjeta y para incrustarlos.
                if (CvNoArtist(na) && nt.find(L" - ") != std::wstring::npos) {
                    std::wstring parsedArtist, parsedTitle;
                    CvSplitQuery(na, nt, parsedArtist, parsedTitle);
                    if (!parsedArtist.empty() && !parsedTitle.empty()) {
                        na = parsedArtist;
                        nt = parsedTitle;
                    }
                }
                bool changed = (nt != g.media.title || na != g.media.artist);
                g.media.title = nt;
                g.media.artist = na;
#if GH_HAVE_THUMB
                if (changed) {
                    g_thumbRetry = 0;
                    // No mantener visible la caratula del tema anterior mientras se
                    // obtiene la nueva. Tambien invalida cualquier resultado en vuelo.
                    ClearThumb();
                }
                // La caratula se pide en cada aviso del reproductor; el refresco de
                // seguridad solo la reintenta unas pocas veces si todavia no ha llegado.
                if (!fromTimer || changed || (!g.thumbOk && g_thumbRetry < 4)) {
                    if (fromTimer && !changed) g_thumbRetry++;
                    g_thumbRef = props.Thumbnail();  // puede ser nula: entonces se busca fuera
                    StartThumbThread();
                }
#else
                (void)changed;
                (void)fromTimer;
#endif
            } catch (...) {
                InterlockedExchange(&g_propsDirty, 1);  // se reintenta en el siguiente ciclo
            }
        }
        auto info = s.GetPlaybackInfo();
        g.media.playing =
            info.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing;
        auto tl = s.GetTimelineProperties();
        double raw = (double)tl.Position().count() / 10000000.0;
        double dur = (double)(tl.EndTime().count() - tl.StartTime().count()) / 10000000.0;
        ULONGLONG now = GetTickCount64();
        if (g.media.playing && raw == g_mediaRaw && g_mediaLast)
            g.media.pos += (double)(now - g_mediaLast) / 1000.0;
        else
            g.media.pos = raw;
        g_mediaRaw = raw;
        g_mediaLast = now;
        g.media.dur = dur;
        if (dur > 0.0 && g.media.pos > dur) g.media.pos = dur;
        g.media.valid = true;
    } catch (...) {
        g_sess = nullptr;
        g_mgr = nullptr;
        g.media.valid = false;
    }
}
#else
static void SampleMedia() {
    g.media.valid = true;
}
static void ShutdownMedia() {}
static void StartThumbThread() {}
static void StartEmbedThread(const std::wstring&, const std::wstring&, const std::wstring&) {}
#endif

static void MediaKey(WORD vk) {
    keybd_event((BYTE)vk, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event((BYTE)vk, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

static void MediaCommand(int cmd) {  // 0 previous, 1 play/pause, 2 next
#if GH_HAVE_WINRT
    try {
        if (g_mgr) {
            auto s = g_mgr.GetCurrentSession();
            if (s) {
                if (cmd == 0) s.TrySkipPreviousAsync();
                else if (cmd == 1) s.TryTogglePlayPauseAsync();
                else s.TrySkipNextAsync();
                return;
            }
        }
    } catch (...) {
    }
#endif
    MediaKey(cmd == 0 ? VK_MEDIA_PREV_TRACK : (cmd == 1 ? VK_MEDIA_PLAY_PAUSE : VK_MEDIA_NEXT_TRACK));
}

// ---------------------------------------------------------------------------
// Tema, acento, pantalla completa y monitor
// ---------------------------------------------------------------------------

static bool ReadDwordHKCU(const wchar_t* sub, const wchar_t* name, DWORD& v) {
    DWORD sz = sizeof(v);
    return RegGetValueW(HKEY_CURRENT_USER, sub, name, RRF_RT_REG_DWORD, nullptr, &v, &sz) == ERROR_SUCCESS;
}

// Returns true when something visible changed.
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
    return s == 2 || s == 3 || s == 4;  // busy, D3D fullscreen, presentation mode
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
// Avisos (globo del area de notificacion) y Pomodoro
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
    if (--g.pomoLeft > 0) return;
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
    g.cards[CARD_CLOCK].dirty = true;
}
// ---------------------------------------------------------------------------
// Render por software: formas suavizadas con campos de distancia
// ---------------------------------------------------------------------------

struct Canvas {
    int w = 0;
    int h = 0;
    std::vector<DWORD> px;  // premultiplied BGRA
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
        float t = Clamp01((wx * ex + wy * ey) / (ex * ex + ey * ey));
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
// Iconos del tiempo
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
// Fuentes y texto (mascaras GDI compuestas sobre el lienzo)
// ---------------------------------------------------------------------------

struct TextCtx {
    HDC dc;
    DWORD* bits;
    int W;
    int H;
    Canvas* cv;
};

static HFONT MakeFont(int px, int weight) {
    return CreateFontW(-px, 0, 0, 0, weight, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                       OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
                       DEFAULT_PITCH | FF_DONTCARE, L"Segoe UI");
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
    f.big = MakeFont((int)(36.0f * k), FW_LIGHT);
    f.name = MakeFont((int)(14.0f * k), FW_NORMAL);
    f.pill = MakeFont((int)(14.0f * k), FW_SEMIBOLD);
    f.temp = MakeFont((int)(44.0f * k), FW_LIGHT);
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
    int key = (int)(k * 1000.0f);
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

// align: 0 = left, 1 = center, 2 = right. Returns the text width.
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
// Contenido de las tarjetas
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
            // Solo las de hoy en adelante: una cita vencida desaparece al
            // dia siguiente, para no ocupar sitio con lo que ya ha pasado.
            if (d.days >= 0) v.push_back(d);
        }
    }
    std::sort(v.begin(), v.end(), [](const Deadline& a, const Deadline& b) {
        if (a.days != b.days) return a.days < b.days;
        int ka = a.hh < 0 ? 1440 : a.hh * 60 + a.mm;
        int kb = b.hh < 0 ? 1440 : b.hh * 60 + b.mm;
        return ka < kb;
    });

    // Citas repetidas: el .ics de Google puede traer el mismo evento dos veces
    // (el evento y su excepcion), y ademas puede coincidir con una escrita a
    // mano en el mod. Dos citas son la misma si coinciden nombre, dia y hora.
    std::vector<Deadline> uniq;
    uniq.reserve(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        bool dup = false;
        // El nombre se compara en minusculas y sin espacio ni punto al final,
        // porque el mismo evento puede llegar como "Vacuna" y "Vacuna.".
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
                // Si una trae lugar y la otra no, se conserva el lugar.
                if (uniq[j].place.empty() && !v[i].place.empty()) uniq[j].place = v[i].place;
                break;
            }
        }
        if (!dup) uniq.push_back(v[i]);
    }
    return uniq;
}

// Cuantas citas caen hoy y cuantas en los proximos siete dias. Se usa para el
// contador de la cabecera de la agenda.
static void AgendaCounts(int& todayN, int& weekN) {
    todayN = 0;
    weekN = 0;
    std::vector<Deadline> all = AllDeadlines();
    for (size_t i = 0; i < all.size(); i++) {
        if (all[i].days == 0) todayN++;
        if (all[i].days >= 0 && all[i].days <= 7) weekN++;
    }
}

// Rotulo fino que separa los grupos de la agenda.
static std::wstring AgendaGroupLabel(int days, const SYSTEMTIME& st) {
    if (days == 0) return TR(L"HOY", L"TODAY", L"AVUI");
    if (days == 1) return TR(L"MA\u00D1ANA", L"TOMORROW", L"DEM\u00C0");
    if (days <= 7) return TR(L"ESTA SEMANA", L"THIS WEEK", L"AQUESTA SETMANA");
    return TR(L"PR\u00D3XIMO", L"UPCOMING", L"PROPER");
}

static int AgendaGroupOf(int days) {
    if (days == 0) return 1;
    if (days == 1) return 2;
    if (days <= 7) return 3;
    return 4;
}

// 1 = hoy, 2 = manana, 3 = esta semana, 4 = proximo

static std::vector<Deadline> VisibleDeadlines() {
    std::vector<Deadline> v = AllDeadlines();
    if ((int)v.size() > g.maxDeadlines) v.resize((size_t)g.maxDeadlines);
    return v;
}

// ---- citas marcadas como vistas -------------------------------------------
//
// La marca se guarda en el almacenamiento del mod, con una clave por cita (su
// texto, su dia y su hora), igual que el estado de las notas. Asi sobrevive a
// los reinicios y no vuelve a avisar de lo ya visto.

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
    // Una cita marcada cuenta como vista: no debe volver a avisar.
    if (now) {
        unsigned int h = TextHash(d.name + L"|" + std::to_wstring(d.dayNum) + L"|" +
                                 std::to_wstring(d.hh * 60 + d.mm));
        if (std::find(g.notified.begin(), g.notified.end(), h) == g.notified.end())
            g.notified.push_back(h);
    }
}

// Fila del cursor dentro de la agenda, teniendo en cuenta los rotulos de grupo.
static int DeadlineRowAt(float uy) {
    std::vector<Deadline> v = VisibleDeadlines();
    int extra = 0;
    int prevG = -99;
    for (size_t i = 0; i < v.size(); i++) {
        int gv = AgendaGroupOf(v[i].days);
        if (gv != prevG) { prevG = gv; extra++; }
        float top = 38.0f + 40.0f * (float)(i + extra);
        if (uy >= top && uy < top + 40.0f) return (int)i;
    }
    return -1;
}

// Borde superior de la fila i, con los rotulos de grupo ya contados.
static float DeadlineRowTop(int row, const std::vector<Deadline>& v) {
    int extra = 0;
    int prevG = -99;
    for (int i = 0; i <= row && i < (int)v.size(); i++) {
        int gv = AgendaGroupOf(v[i].days);
        if (gv != prevG) { prevG = gv; extra++; }
    }
    return 38.0f + 40.0f * (float)(row + extra);
}





struct WLayout {
    float panelY = -1, panelH = 0;
    float detailsY = -1, sunY = -1, rainY = -1, hourlyY = -1, hourlyH = 0, divY = 0, cardH = 0;
    bool anyPop = false;
};

static WLayout WeatherLayout(const Weather& wt) {
    WLayout L;
    float y = 112.0f;
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
        L.hourlyH = 74.0f;
        y += 4.0f + 74.0f;
    }
    L.divY = y + 4.0f;
    for (int i = 1; i <= 6 && i < wt.days; i++) {
        if (wt.dpop[i] >= 20) L.anyPop = true;
    }
    L.cardH = g.showForecast ? (L.divY + (L.anyPop ? 100.0f : 84.0f)) : (y + 14.0f);
    return L;
}

// Next 24 hours: the day's maximum (reds) and minimum (blues) above the curve,
// dashed reference lines at both values and a label every 3 hours.
static void DrawHourly(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu, float hy) {
    const Weather& wt = g.weather;
    int n = wt.hourlyN;
    if (n < 2) return;

    // Gráfica horaria monocromática: la temperatura se muestra
    // encima de cada hora marcada y la gráfica mantiene un solo color.
    const RGBA barCol = C(112, 190, 255, 0.95f);
    const RGBA barFill = C(112, 190, 255, 0.22f);

    float x0 = M + 18.0f * k, x1 = M + (cardWu - 18.0f) * k;
    float step = (x1 - x0) / (float)(n - 1);
    float yTop = M + (hy + 26.0f) * k, yBot = M + (hy + 46.0f) * k;
    float baseY = M + (hy + 58.0f) * k;

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

    // Sin etiquetas de máxima y mínima junto a la gráfica: se quitaron a peticion
    // del usuario. dayMax y dayMin se siguen usando para el rango de la curva.
    DrawLabel(t, f.small, TR(L"Pr\u00F3ximas 24 h", L"Next 24 h", L"Properes 24 h"), x1,
              M + (hy + 4.0f) * k, 2, g.pal.dimc);

    std::vector<float> px((size_t)n), py((size_t)n);
    for (int i = 0; i < n; i++) {
        px[(size_t)i] = x0 + step * (float)i;
        py[(size_t)i] = yOf(wt.htemp[i]);
    }

    // Barras de probabilidad de lluvia, debajo de la temperatura.
    for (int i = 0; i < n; i++) {
        if (wt.hpop[i] < 10) continue;
        float h = std::max(2.0f * k, (float)wt.hpop[i] / 100.0f * 9.0f * k);
        FillRRect(cv, px[(size_t)i], baseY - h / 2.0f, step * 0.30f, h / 2.0f, 1.0f * k,
                  [](float, float) -> RGBA { return C(96, 176, 255, 0.60f); });
    }

    // Área y línea de temperatura en un único color.
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

    // Cada hora señalada (cada 3 h) lleva la temperatura encima de la gráfica.
    for (int i = 0; i < n; i += 3) {
        std::wstring tempS = std::to_wstring((int)floor(wt.htemp[i] + 0.5)) + L"\u00B0";
        DrawLabel(t, f.small, tempS, px[(size_t)i], M + (hy + 14.0f) * k, 1, g.pal.soft);

        std::wstring lab;
        if (i == 0) {
            lab = TR(L"Ahora", L"Now", L"Ara");
        } else {
            wchar_t b[8];
            wsprintfW(b, L"%02dh", wt.hhour[i]);
            lab = b;
        }
        DrawLabel(t, f.small, lab, px[(size_t)i], M + (hy + 60.0f) * k, 1, g.pal.dimc);
    }
}

// One centered stat: small label on top, bright value below.
static void DrawStat(TextCtx& t, Fonts& f, float cx, float topY, const std::wstring& label,
                     const std::wstring& value, RGBA valCol, int maxW) {
    DrawLabel(t, f.small, label, cx, topY, 1, g.pal.soft);
    DrawLabel(t, f.pill, Ellipsize(t, f.pill, value, maxW), cx, topY + 14.0f * g.kLast, 1, valCol);
}

static void DrawWeather(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu,
                        const WLayout& L) {
    const Weather& wt = g.weather;
    bool valid = wt.valid;
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

    DrawIcon(cv, kind, isDay, M + 52.0f * k, M + 52.0f * k, 76.0f * k);
    if (g.showForecast && valid) {
        for (int i = 1; i <= 6 && i < wt.days; i++) {
            float colX = M + (18.0f + pitch / 2.0f + pitch * (float)(i - 1)) * k;
            DrawIcon(cv, KindFromCode(wt.dcode[i]), true, colX, M + (divY + 40.0f) * k, 36.0f * k);
        }
    }

    std::wstring unit = g.fahrenheit ? L"F" : L"C";
    std::wstring bigTemp = valid ? std::to_wstring((int)floor(wt.temp + 0.5)) + L"\u00B0"
                                 : std::wstring(L"--\u00B0");
    int wBig = DrawLabel(t, f.temp, bigTemp, M + 100.0f * k, M + 4.0f * k, 0, white);
    DrawLabel(t, f.unit, unit, M + 100.0f * k + (float)wBig + 2.0f * k, M + 20.0f * k, 0, dimc);

    std::wstring desc;
    if (valid) desc = DescribeText(wt.code);
    else if (g.fetchFailed) desc = TR(L"Sin conexi\u00F3n", L"Offline", L"Sense connexi\u00F3");
    else desc = TR(L"Cargando...", L"Loading...", L"Carregant...");
    DrawLabel(t, f.desc, desc, M + 100.0f * k, M + 64.0f * k, 0, soft);

    SYSTEMTIME st;
    GetLocalTime(&st);
    wchar_t timeBuf[16];
    wsprintfW(timeBuf, L"%02d:%02d", (int)st.wHour, (int)st.wMinute);
    std::wstring dateStr = std::wstring(DowName((int)st.wDayOfWeek)) + L" " +
                           std::to_wstring((int)st.wDay) + L" " + MonthShort((int)st.wMonth);
    DrawLabel(t, f.time, timeBuf, right, M + 8.0f * k, 2, white);
    DrawLabel(t, f.small, dateStr, right, M + 38.0f * k, 2, dimc);

    if (valid && g.lastOk) {
        bool stale = (GetTickCount64() - g.lastOk) > (ULONGLONG)g.refreshMinutes * 120000ULL;
        if (stale) {
            DrawLabel(t, f.small, TR(L"Sin conexi\u00F3n", L"Offline", L"Sense connexi\u00F3"), right,
                      M + 56.0f * k, 2, C(255, 170, 80, 0.95f));
        } else {
            wchar_t upd[32];
            wsprintfW(upd, TR(L"Act. %02d:%02d", L"Upd. %02d:%02d", L"Act. %02d:%02d"),
                      (int)g.lastOkTime.wHour, (int)g.lastOkTime.wMinute);
            DrawLabel(t, f.small, upd, right, M + 56.0f * k, 2, dimc);
        }
    }

    std::wstring city = (valid && !wt.place.empty()) ? wt.place : g.city;
    DrawLabel(t, f.city, city, M + 18.0f * k, M + 92.0f * k, 0, white);

    if (valid && wt.days > 0) {
        std::wstring hl = L"\u2191 " + std::to_wstring((int)floor(wt.dmax[0] + 0.5)) +
                          L"\u00B0   \u2193 " + std::to_wstring((int)floor(wt.dmin[0] + 0.5)) + L"\u00B0";
        float hlRight = right;
        if (wt.uv >= 0) {
            int uvW = DrawLabel(t, f.small, L"UV " + std::to_wstring(wt.uv), right, M + 94.0f * k, 2,
                                UvColor(wt.uv));
            hlRight = right - (float)uvW - 10.0f * k;
        }
        DrawLabel(t, f.small, hl, hlRight, M + 94.0f * k, 2, soft);
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

            if (wt.dpop[i] >= 20) {
                DrawLabel(t, f.small, std::to_wstring(wt.dpop[i]) + L"%", colX,
                          M + (divY + 78.0f) * k, 1, C(120, 185, 255, 0.95f));
            }
        }
    }
}

// ---- system ---------------------------------------------------------------

// ---------------------------------------------------------------------------
// Cabeceras con icono, banderas, texto con ajuste de linea
// ---------------------------------------------------------------------------

static RGBA CardBadgeColor(int id) {
    switch (id) {
        case CARD_SYSTEM: return CardAccent(C(70, 150, 255));
        case CARD_CLOCK: return CardAccent(C(255, 150, 70));
        case CARD_MEDIA: return CardAccent(C(255, 95, 150));
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

// Colored badge with an icon, followed by a bold title: tells the cards apart at a glance.
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
}

// ---- flags (drawn with shapes: Windows does not render flag emoji) ---------

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

// Deduces a flag from the label of a clock ("Nueva York") or from its Windows zone name.
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

// Union Jack in a 3 x 2 box.
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

// x in 0..3, y in 0..2
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

// ---- text wrapping ----------------------------------------------------------

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

// Level meter colour: green at the bottom, amber in the middle, red at the top.
static RGBA SegColor(float t) {
    if (t < 0.5f) return LerpC(C(86, 214, 150), C(255, 214, 90), t / 0.5f);
    if (t < 0.8f) return LerpC(C(255, 214, 90), C(255, 150, 70), (t - 0.5f) / 0.3f);
    return LerpC(C(255, 150, 70), C(255, 86, 86), (t - 0.8f) / 0.2f);
}

static std::vector<SysRow> BuildSysRows() {
    std::vector<SysRow> rows;

    SysRow ram;
    ram.kind = 0;
    ram.label = L"RAM";
    ram.pct = ram.colorPct = (float)g.ramPct;
    ram.value = FormatNum(g.ramUsedGB, 1) + L" / " + FormatNum(g.ramTotalGB, g.ramTotalGB >= 10.0 ? 0 : 1) + L" GB";
    rows.push_back(ram);

    if (g.showGpu && g_gpu >= 0.0) {
        SysRow r;
        r.kind = 0;
        r.label = L"GPU";
        r.pct = r.colorPct = (float)g_gpu;
        r.value = std::to_wstring((int)(g_gpu + 0.5)) + L" %";
        rows.push_back(r);
    }

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

    SysRow net;
    net.kind = 1;
    net.label = TR(L"Red", L"Net", L"Xarxa");
    net.value = L"\u2193 " + FormatRate(g.dlSpeed) + L"     \u2191 " + FormatRate(g.ulSpeed);
    rows.push_back(net);

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

static void DrawSystem(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu) {
    float right = M + (cardWu - 18.0f) * k;
    RGBA white = g.pal.white, soft = g.pal.soft, dimc = g.pal.dimc;

    float sx0 = M + 120.0f * k, sx1 = right;
    float sy0 = M + 38.0f * k, sy1 = M + 92.0f * k;
    float rcx = (sx0 + sx1) / 2.0f, rcy = (sy0 + sy1) / 2.0f;
    float rhw = (sx1 - sx0) / 2.0f, rhh = (sy1 - sy0) / 2.0f, rr = 6.0f * k;

    FillRRect(cv, rcx, rcy, rhw, rhh, rr, [](float, float) -> RGBA { return HL(0.05f); });

    size_t n = g.hist.size();
    if (n >= 2) {
        float step = (sx1 - sx0) / 59.0f;
        std::vector<float> px(n), py(n);
        for (size_t i = 0; i < n; i++) {
            px[i] = sx1 - (float)(n - 1 - i) * step;
            py[i] = sy1 - 2.0f * k - (g.hist[i] / 100.0f) * (sy1 - sy0 - 6.0f * k);
        }
        RGBA graphCol = LoadColor((float)g.cpu);

        Paint(cv, sx0, sy0, sx1, sy1, [&](float x, float y) -> RGBA {
            if (x < px[0] || x > px[n - 1]) return kNone;
            int j = (int)((x - px[0]) / step);
            if (j < 0) j = 0;
            if (j > (int)n - 2) j = (int)n - 2;
            float tt = Clamp01((x - px[(size_t)j]) / (px[(size_t)j + 1] - px[(size_t)j]));
            float yc = Lerp(py[(size_t)j], py[(size_t)j + 1], tt);
            float cov = Clamp01(y - yc + 0.5f) * Coverage(SdRoundRect(x, y, rcx, rcy, rhw, rhh, rr));
            if (cov <= 0.0f) return kNone;
            float depth = Clamp01(1.0f - (y - yc) / (sy1 - sy0));
            RGBA gc = graphCol;
            gc.a = 0.38f * depth * cov;
            return gc;
        });
        for (size_t i = 0; i + 1 < n; i++) {
            FillCapsule(cv, px[i], py[i], px[i + 1], py[i + 1], 1.1f * k,
                        [graphCol](float, float) -> RGBA {
                            RGBA lc = LerpC(graphCol, C(255, 255, 255), 0.35f);
                            lc.a = 0.95f;
                            return lc;
                        });
        }
    }

    std::vector<SysRow> rows = BuildSysRows();
    float bx0 = M + 62.0f * k;
    float bw = 170.0f * k;

    for (size_t i = 0; i < rows.size(); i++) {
        if (rows[i].kind != 0) continue;
        float ry = M + (104.0f + 26.0f * (float)i) * k;
        float cy = ry + 9.0f * k;
        FillRRect(cv, bx0 + bw / 2.0f, cy, bw / 2.0f, 3.5f * k, 3.5f * k,
                  [](float, float) -> RGBA { return HL(0.12f); });
        float w = Clamp01(rows[i].pct / 100.0f) * bw;
        if (w > 1.0f * k) {
            RGBA col = LoadColor(rows[i].colorPct);
            float hw = std::max(w / 2.0f, 3.5f * k);
            FillRRect(cv, bx0 + hw, cy, hw, 3.5f * k, 3.5f * k, [col](float, float) -> RGBA {
                RGBA c = col;
                c.a = 0.95f;
                return c;
            });
        }
    }

    DrawCardHeader(cv, t, f, CARD_SYSTEM, M, k, TR(L"SISTEMA", L"SYSTEM", L"SISTEMA"));

    ULONGLONG up = GetTickCount64() / 1000ULL;
    unsigned long days = (unsigned long)(up / 86400ULL);
    unsigned long hours = (unsigned long)((up % 86400ULL) / 3600ULL);
    unsigned long mins = (unsigned long)((up % 3600ULL) / 60ULL);
    std::wstring upText = TR(L"Activo ", L"Up ", L"Actiu ");
    if (days > 0) upText += std::to_wstring(days) + L" d " + std::to_wstring(hours) + L" h";
    else upText += std::to_wstring(hours) + L" h " + std::to_wstring(mins) + L" min";
    DrawLabel(t, f.small, upText, right, M + 12.0f * k, 2, dimc);

    DrawLabel(t, f.small, L"CPU", M + 18.0f * k, M + 34.0f * k, 0, dimc);
    DrawLabel(t, f.big, std::to_wstring((int)floor(g.cpu + 0.5)) + L"%", M + 18.0f * k, M + 46.0f * k, 0,
              white);

    for (size_t i = 0; i < rows.size(); i++) {
        float ry = M + (104.0f + 26.0f * (float)i) * k;
        const SysRow& r = rows[i];
        if (r.kind == 0) {
            DrawLabel(t, f.small, r.label, M + 18.0f * k, ry, 0, dimc);
            DrawLabel(t, f.small, r.value, right, ry, 2, soft);
        } else {
            DrawLabel(t, f.small, r.label, M + 18.0f * k, ry, 0, dimc);
            DrawLabel(t, f.small, Ellipsize(t, f.small, r.value, (int)(right - bx0)), bx0, ry, 0, soft);
        }
    }

    // Busiest processes: segmented vertical bars that fill up with the usage,
    // with the process name on the bottom line.
    if (!g.procs.empty()) {
        float secTop = 104.0f + 26.0f * (float)rows.size() + 6.0f;
        FillRRect(cv, (M + 18.0f * k + right) / 2.0f, M + (secTop - 3.0f) * k,
                  (right - (M + 18.0f * k)) / 2.0f, 0.5f * k, 0.5f * k,
                  [](float, float) -> RGBA { return HL(0.10f); });

        int np = (int)g.procs.size();
        float colW = 336.0f / (float)np;
        float barW = std::min(colW * 0.68f, 64.0f);
        float barH = 48.0f;
        const int segs = 10;
        float gap = 1.4f;
        float segH = (barH - gap * (float)(segs - 1)) / (float)segs;

        double top = 0.0;
        for (int i = 0; i < np; i++) {
            double v = g.procByRam ? g.procs[(size_t)i].ramMB : g.procs[(size_t)i].cpu;
            if (v > top) top = v;
        }
        // Full scale of the meter: 50 % CPU or 2 GB of RAM (larger values still fit).
        double ref = std::max(top, g.procByRam ? 2048.0 : 50.0);
        float barTop = secTop + 4.0f;

        for (int i = 0; i < np; i++) {
            const ProcInfo& p = g.procs[(size_t)i];
            double val = g.procByRam ? p.ramMB : p.cpu;
            float frac = Clamp01((float)(val / ref));
            int lit = val < 0.3 ? 0 : std::max(1, (int)floorf(frac * (float)segs + 0.5f));
            float cx = M + (18.0f + colW * ((float)i + 0.5f)) * k;

            for (int s = 0; s < segs; s++) {
                float cyU = barTop + barH - segH / 2.0f - (float)s * (segH + gap);
                RGBA sc = (s < lit) ? SegColor((float)s / (float)(segs - 1)) : HL(0.09f);
                if (s < lit) sc.a = 0.96f;
                FillRRect(cv, cx, M + cyU * k, barW / 2.0f * k, segH / 2.0f * k, 1.2f * k,
                          [sc](float, float) -> RGBA { return sc; });
            }

            float nameY = M + (barTop + barH + 6.0f) * k;
            DrawLabel(t, f.small, Ellipsize(t, f.small, p.name, (int)((colW - 6.0f) * k)), cx, nameY, 1, white);
            std::wstring cpuS = std::to_wstring((int)(p.cpu + 0.5)) + L" %";
            std::wstring ramS = p.ramMB >= 1024.0 ? FormatNum(p.ramMB / 1024.0, 1) + L" GB"
                                                  : std::to_wstring((int)(p.ramMB + 0.5)) + L" MB";
            if (np >= 4) {
                // narrow columns: CPU and RAM on two lines
                DrawLabel(t, f.small, cpuS, cx, nameY + 16.0f * k, 1, g.procByRam ? dimc : soft);
                DrawLabel(t, f.small, ramS, cx, nameY + 30.0f * k, 1, g.procByRam ? soft : dimc);
            } else {
                DrawLabel(t, f.small, Ellipsize(t, f.small, cpuS + L"  \u00B7  " + ramS, (int)((colW - 4.0f) * k)),
                          cx, nameY + 16.0f * k, 1, dimc);
            }
        }
    }
}

// ---- deadlines ------------------------------------------------------------

static void DrawDeadlines(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu,
                          const std::vector<Deadline>& vis) {
    float right = M + (cardWu - 18.0f) * k;
    RGBA white = g.pal.white, soft = g.pal.soft, dimc = g.pal.dimc;

    // Alto que ocupa el desplegable de calendarios cuando esta abierto. Se
    // declara aqui arriba porque lo usan las tres pasadas del dibujo.
    float listDrop = (g.icsShowList && !g.icsUrl.empty()) ? 40.0f : 0.0f;

    SYSTEMTIME st;
    GetLocalTime(&st);

    int shapesExtra = 0;
    int shapesPrevG = -99;
    for (size_t i = 0; i < vis.size(); i++) {
        int gv = AgendaGroupOf(vis[i].days);
        if (gv != shapesPrevG) {
            shapesPrevG = gv;
            shapesExtra++;
        }
        float ry = M + (38.0f + listDrop + 40.0f * (float)(i + shapesExtra)) * k;
        RGBA uc = UrgencyColor(vis[i].days);
        bool two = !vis[i].place.empty();

        // Sin pastilla: la marca de origen es solo la letra, dibujada delante de
        // la pildora de la cuenta atras, sin pisarla.
        float pcx = M + 44.0f * k, pcy = ry + (two ? 20.0f : 18.0f) * k;
        float phw = 26.0f * k, phh = 12.0f * k;

        FillRRect(cv, pcx, pcy, phw, phh, phh, [uc](float, float) -> RGBA {
            RGBA c = uc;
            c.a = 0.20f;
            return c;
        });
        FillSdf(cv, pcx - phw - 2, pcy - phh - 2, pcx + phw + 2, pcy + phh + 2,
                [=](float x, float y) {
                    return fabsf(SdRoundRect(x, y, pcx, pcy, phw, phh, phh) + 0.6f) - 0.6f;
                },
                [uc](float, float) -> RGBA {
                    RGBA c = uc;
                    c.a = 0.65f;
                    return c;
                });

        if (i + 1 < vis.size() && AgendaGroupOf(vis[i + 1].days) == gv) {
            FillRRect(cv, (M + 18.0f * k + right) / 2.0f, ry + 40.0f * k, (right - (M + 18.0f * k)) / 2.0f,
                      0.5f * k, 0.5f * k, [](float, float) -> RGBA { return HL(0.08f); });
        }
    }

    DrawCardHeader(cv, t, f, CARD_DEADLINES, M, k, TR(L"AGENDA", L"AGENDA", L"AGENDA"));

    // Panel desplegable de calendarios: aparece al pulsar "Sincronizando".
    // Va dentro de la tarjeta, empujando las citas hacia abajo mientras esta
    // abierto, para que no haya nada que se salga de la ventana.
    if (g.icsShowList && !g.icsUrl.empty()) {
        std::wstring nome = TR(L"Calendario añadido", L"Added calendar", L"Calendari afegit");
        std::wstring det = g.icsLabel.empty() ? TR(L"(sin nombre corto)",
                                                  L"(no short name)",
                                                  L"(sense nom curt)")
                                              : g.icsLabel;
        float py = M + 34.0f * k;
        float ph = 38.0f * k;
        FillRRect(cv, M + cardWu * k / 2.0f, py + ph / 2.0f, (cardWu - 36.0f) * k / 2.0f,
                  ph / 2.0f, 7.0f * k,
                  [](float, float) -> RGBA { return HL(0.05f); });
        FillSdf(cv, M + 17.0f * k, py - 1.0f, right, py + ph + 1.0f,
                [=](float x, float y) {
                    return fabsf(SdRoundRect(x, y, M + cardWu * k / 2.0f, py + ph / 2.0f,
                                             (cardWu - 36.0f) * k / 2.0f, ph / 2.0f,
                                             7.0f * k) + 0.6f) - 0.6f;
                },
                [](float, float) -> RGBA { return HL(0.14f); });
        bool fresh2 = g.icsLastOk != 0 &&
                      (GetTickCount64() - g.icsLastOk) < 45ULL * 60000ULL;
        RGBA stCol = fresh2 ? C(80, 255, 130, 1.0f) : C(150, 156, 166, 0.6f);
        FillCircle(cv, M + 30.0f * k, py + 19.0f * k, 3.6f * k,
                   [stCol](float, float) -> RGBA { return stCol; });
        int dx = DrawLabel(t, f.small, Ellipsize(t, f.small, nome, (int)(200.0f * k)),
                           M + 40.0f * k, py + 6.0f * k, 0, white);
        (void)dx;
        DrawLabel(t, f.small, Ellipsize(t, f.small, det, (int)(200.0f * k)),
                  M + 40.0f * k, py + 21.0f * k, 0, dimc);
        std::wstring upd = g.icsLastOk
                               ? TR(L"actualizado", L"updated", L"actualitzat")
                               : TR(L"pendiente", L"pending", L"pendent");
        DrawLabel(t, f.small, upd, right, py + 13.0f * k, 2, dimc);
        listDrop = 40.0f;
    }

    if (g.icsFailed && !g.icsUrl.empty()) {
        // El calendario no llego en la ultima descarga: se dice, en vez de
        // dejar la tarjeta como si simplemente no hubiera citas.
        DrawLabel(t, f.small,
                  TR(L"\u26A0 calendario sin actualizar", L"\u26A0 calendar not updated",
                     L"\u26A0 calendari sense actualitzar"),
                  right, M + 12.0f * k, 2, C(255, 190, 90, 0.95f));
    } else if (!g.icsUrl.empty()) {
        // Sincronizando: con luz cuando hay un calendario externo añadido y
        // apagada cuando no lo hay. Un clic muestra los calendarios.
        const wchar_t* label = TR(L"Sincronizando", L"Syncing", L"Sincronitzant");
        int lw = MeasureWidth(t, f.small, label);
        // Verde fosforito si la ultima descarga llego bien; gris apagado si
        // todavia no ha habido ninguna o el calendario lleva tiempo sin venir.
        bool fresh = g.icsLastOk != 0 &&
                     (GetTickCount64() - g.icsLastOk) < 45ULL * 60000ULL;
        RGBA dot = fresh ? C(80, 255, 130, 1.0f) : C(150, 156, 166, 0.6f);
        FillCircle(cv, right - (float)lw - 7.0f * k, M + 17.5f * k, 2.7f * k,
                   [dot](float, float) -> RGBA { return dot; });
        DrawLabel(t, f.small, label, right, M + 12.0f * k, 2, g.pal.white);
    } else {
        int todayN = 0, weekN = 0;
        AgendaCounts(todayN, weekN);
        if (todayN > 0 || weekN > 0) {
            std::wstring cnt = std::to_wstring(todayN) + TR(L" hoy", L" today", L" avui");
            cnt += L"  \u00B7  " + std::to_wstring(weekN) +
                   TR(L" esta semana", L" this week", L" aquesta setmana");
            DrawLabel(t, f.small, cnt, right, M + 12.0f * k, 2, dimc);
        }
    }
    if (vis.empty()) {
        const wchar_t* msg;
        if (g.icsFailed && !g.icsUrl.empty())
            msg = TR(L"El calendario no responde. Se reintentara solo.",
                     L"The calendar is not responding. It will retry on its own.",
                     L"El calendari no respon. Es reintentara sol.");
        else
            msg = TR(L"Clic derecho > Editar agenda", L"Right-click > Edit agenda",
                     L"Clic dret > Edita l'agenda");
        DrawLabel(t, f.small, msg, M + 18.0f * k, M + 50.0f * k, 0, soft);
        return;
    }


    int lastGroup = -99;
    int extraRows = 0;   // filas de rotulo ya pintadas, para empujar las citas
    for (size_t i = 0; i < vis.size(); i++) {
        const Deadline& d = vis[i];
        int grp = AgendaGroupOf(d.days);
        if (grp != lastGroup) {
            lastGroup = grp;
            extraRows++;
            float gy = M + (38.0f + listDrop + 40.0f * (float)(i + extraRows - 1)) * k;
            DrawLabel(t, f.small, AgendaGroupLabel(d.days, st), M + 18.0f * k, gy + 6.0f * k, 0,
                      C(255, 255, 255, 0.42f));
            FillRRect(cv, (M + 90.0f * k + right) / 2.0f, gy + 13.0f * k,
                      (right - (M + 90.0f * k)) / 2.0f, 0.5f * k, 0.5f * k,
                      [](float, float) -> RGBA { return HL(0.07f); });
        }
        float ry = M + (38.0f + listDrop + 40.0f * (float)(i + extraRows)) * k;
        RGBA uc = UrgencyColor(d.days);
        uc.a = 1.0f;
        bool twoRow = !d.place.empty();

        std::wstring daysText;
        if (d.days == 0 && d.hh >= 0) {
            int left = (d.hh * 60 + d.mm) - ((int)st.wHour * 60 + (int)st.wMinute);
            if (left > 60) daysText = std::to_wstring(left / 60) + L" h";
            else if (left > 0) daysText = std::to_wstring(left) + L" min";
            else daysText = TR(L"Ya", L"Now", L"Ara");
        } else if (d.days == 0) {
            daysText = TR(L"Hoy", L"Today", L"Avui");
        } else if (d.days < 0) {
            daysText = TR(L"Venc.", L"Late", L"Venc.");
        } else if (d.days >= 60) {
            daysText = std::to_wstring((d.days + 15) / 30) + TR(L" mes", L" mo", L" mes");
        } else if (d.days >= 14) {
            daysText = std::to_wstring(d.days / 7) + TR(L" sem", L" wk", L" set");
        } else {
            daysText = std::to_wstring(d.days) + L" d";
        }
        bool done = DeadlineDone(d);

        // La inicial de la cuenta, al principio de la fila. Se dibuja aqui, con
        // el resto de la primera pasada de texto, porque `two` se calcula mas
        // abajo y no existe todavia en este punto.
        if (!d.badge.empty()) {
            // A la izquierda de la pildora (centrada en M+44, 26 de ancho, o
            // sea que empieza en M+31): la letra va centrada en M+14 y con la
            // fuente pequena, para que no la toque ni pese demasiado.
            RGBA sc = OriginColor(d.origin);
            DrawLabel(t, f.small, d.badge, M + 10.0f * k,
                      ry + (twoRow ? 13.0f : 11.5f) * k, 1, sc);
        }

        if (done) {
            // Cita ya vista: pildora apagada con un visto bueno.
            DrawLabel(t, f.pill, L"\u2713", M + 44.0f * k, ry + 10.5f * k, 1,
                      C(150, 200, 170, 0.85f));
        } else {
            DrawLabel(t, f.pill, daysText, M + 44.0f * k, ry + 10.5f * k, 1, uc);
        }

        std::wstring date = std::to_wstring(d.d) + L" " + MonthShort(d.m);
        if (d.y != (int)st.wYear) date += L" " + std::to_wstring(d.y);
        if (d.hh >= 0) {
            wchar_t hm[16];
            wsprintfW(hm, L" %02d:%02d", d.hh, d.mm);
            date += hm;
        }
        int dateW = MeasureWidth(t, f.small, date);

        int nameMaxW = (int)(right - (M + 78.0f * k)) - dateW - (int)(10.0f * k);
        bool two = !d.place.empty();
        std::wstring nm = Ellipsize(t, f.name, d.name, nameMaxW);
        DrawLabel(t, f.name, nm, M + 78.0f * k, ry + (two ? 2.0f : 10.5f) * k, 0,
                  done ? C(255, 255, 255, 0.45f) : white);
        if (two) {
            int plW = (int)(right - (M + 78.0f * k));
            DrawLabel(t, f.small, Ellipsize(t, f.small, d.place, plW), M + 78.0f * k, ry + 21.0f * k, 0,
                      dimc);
        }
        DrawLabel(t, f.small, date, right, ry + (two ? 3.0f : 12.5f) * k, 2, dimc);
    }
}

// ---- sticky note ----------------------------------------------------------

static const float kStickyClearX = 342.0f;  // centre of the clear / undo button (card units)
static const float kStickyHeaderH = 40.0f;
static const float kStickyTextTop = 46.0f;
static const float kStickyPad = 16.0f;
static const COLORREF kPaperRef = RGB(255, 236, 121);
static const COLORREF kInkRef = RGB(58, 44, 18);

static float StickyCardHu(float k) {
    return kStickyTextTop + (float)g.stickyLines * ((float)g.notePitch / k) + kStickyPad;
}

static void DrawStickyHeader(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu, bool folded) {
    (void)cardWu;
    RGBA ink = C(58, 44, 18, 0.95f);

    // red push pin
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

static void DrawSticky(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu) {
    DrawStickyHeader(cv, t, f, M, k, cardWu, false);

    RGBA ink = C(58, 44, 18, 0.95f), dim = C(110, 88, 30, 0.70f);
    float saved = g.pal.shadow;
    g.pal.shadow = 0.0f;

    int maxW = (int)((cardWu - 36.0f) * k);
    float pitch = (float)g.notePitch;
    float y0 = M + kStickyTextTop * k;

    if (g.stickyText.empty()) {
        DrawLabel(t, f.note,
                  TR(L"Haz clic y escribe...", L"Click and start typing...", L"Fes clic i escriu..."),
                  M + 18.0f * k, y0, 0, dim);
    } else {
        std::vector<std::wstring> lines = WrapLines(t, f.note, g.stickyText, maxW);
        int maxL = g.stickyLines;
        for (int i = 0; i < (int)lines.size() && i < maxL; i++) {
            std::wstring ln = lines[(size_t)i];
            if (i == maxL - 1 && (int)lines.size() > maxL) ln = Ellipsize(t, f.note, ln + L"\u2026", maxW);
            DrawLabel(t, f.note, ln, M + 18.0f * k, y0 + pitch * (float)i, 0, ink);
        }
    }
    g.pal.shadow = saved;
}

// ---- media ----------------------------------------------------------------

static const float kMediaBtnY = 20.0f;   // en la cabecera, esquina superior derecha
static const float kMediaPrevX = 288.0f, kMediaPlayX = 318.0f, kMediaNextX = 348.0f;

// Color del ecualizador segun la altura (0 = base, 1 = punta).
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

// Reparte n colores a distancias iguales.
static void EqPalSet(EqPal& p, int n, const RGBA* cols) {
    p.n = n;
    for (int i = 0; i < n; i++) {
        p.col[i] = cols[i];
        p.stop[i] = n > 1 ? (float)i / (float)(n - 1) : 0.0f;
    }
}

static void EqPalPreset(const std::wstring& name, EqPal& p) {
    if (name == L"bluepurple") {  // azules y violetas
        const RGBA c[5] = {C(40, 120, 255), C(70, 170, 255), C(130, 130, 255), C(170, 100, 255), C(225, 110, 255)};
        EqPalSet(p, 5, c);
    } else if (name == L"sunset") {  // atardecer
        const RGBA c[5] = {C(120, 90, 255), C(200, 90, 230), C(255, 100, 160), C(255, 150, 90), C(255, 210, 100)};
        EqPalSet(p, 5, c);
    } else if (name == L"fire") {  // fuego
        const RGBA c[5] = {C(255, 225, 90), C(255, 175, 60), C(255, 115, 50), C(235, 55, 60), C(200, 30, 90)};
        EqPalSet(p, 5, c);
    } else if (name == L"green") {  // verdes
        const RGBA c[5] = {C(30, 190, 160), C(60, 220, 130), C(130, 235, 90), C(200, 245, 100), C(245, 255, 160)};
        EqPalSet(p, 5, c);
    } else if (name == L"ice") {  // hielo
        const RGBA c[5] = {C(70, 150, 255), C(110, 200, 255), C(160, 230, 255), C(210, 245, 255), C(255, 255, 255)};
        EqPalSet(p, 5, c);
    } else {  // arcoiris (por defecto)
        const RGBA c[5] = {C(60, 200, 255), C(70, 230, 150), C(250, 228, 90), C(255, 150, 70), C(255, 70, 140)};
        EqPalSet(p, 5, c);
        const float st[5] = {0.0f, 0.30f, 0.55f, 0.78f, 1.0f};
        for (int i = 0; i < 5; i++) p.stop[i] = st[i];
    }
}

// "#RRGGBB" o "RRGGBB". Si no es valido, out no se toca.
static bool EqParseHex(const std::wstring& in, RGBA& out) {
    std::wstring h;
    bool hash = false;  // solo se admite una almohadilla, y al principio
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

// Paleta "acento": del tono oscuro del color de la tarjeta a casi blanco en la punta.
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
        RGBA c[3] = {C(60, 120, 255), C(160, 100, 255), C(255, 100, 200)};  // si un color no es valido, se usa este
        EqParseHex(lo, c[0]);
        EqParseHex(mid, c[1]);
        EqParseHex(hi, c[2]);
        EqPalSet(g.eqPal, 3, c);
    } else {
        EqPalPreset(name, g.eqPal);
    }
}

// Caratula: cuadrado redondeado con la imagen del tema, o una nota musical si no hay.
static void DrawThumb(Canvas& cv, TextCtx& t, Fonts& f, float x0, float y0, float sz, float k, RGBA ac) {
    float cx = x0 + sz / 2.0f, cy = y0 + sz / 2.0f, hw = sz / 2.0f, rad = 11.0f * k;
    auto sd = [=](float x, float y) { return SdRoundRect(x, y, cx, cy, hw, hw, rad); };
    if (g.thumbOk && g.thumbS > 0 && (int)g.thumbPx.size() >= g.thumbS * g.thumbS) {
        const DWORD* px = g.thumbPx.data();
        const int S = g.thumbS;
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
        DrawLabel(t, f.big, L"\u266A", cx, cy - 24.0f * k, 1, g.pal.white);
    }
    // Borde fino de cristal
    FillSdf(cv, x0 - 2, y0 - 2, x0 + sz + 2, y0 + sz + 2,
            [=](float x, float y) { return fabsf(sd(x, y) + 0.5f) - 0.5f; },
            [](float, float) -> RGBA { return HL(0.22f); });
}

static void DrawMedia(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu) {
    const MediaInfo& mi = g.media;
    float right = M + (cardWu - 18.0f) * k;
    RGBA white = g.pal.white, soft = g.pal.soft;
    RGBA ac = CardAccent(C(255, 120, 160));

    DrawCardHeader(cv, t, f, CARD_MEDIA, M, k, TR(L"MULTIMEDIA", L"MEDIA", L"MULTIM\u00C8DIA"));

    // Botones: esquina superior derecha, en la linea del titulo.
    {
        float cy = M + kMediaBtnY * k;
        float pvx = M + kMediaPrevX * k, plx = M + kMediaPlayX * k, nxx = M + kMediaNextX * k;
        float q = 0.80f * k;  // los iconos son algo mas pequenos que antes

        FillCircle(cv, plx, cy, 13.0f * k, [](float, float) -> RGBA { return HL(0.16f); });

        FillRRect(cv, pvx - 5.5f * q, cy, 1.2f * q, 5.5f * q, 0.8f * q, [white](float, float) -> RGBA { return white; });
        std::vector<float> tp = {pvx + 6.0f * q, cy - 6.0f * q, pvx + 6.0f * q, cy + 6.0f * q, pvx - 3.5f * q, cy};
        FillPoly(cv, tp, [white](float, float) -> RGBA { return white; });

        FillRRect(cv, nxx + 5.5f * q, cy, 1.2f * q, 5.5f * q, 0.8f * q, [white](float, float) -> RGBA { return white; });
        std::vector<float> tn = {nxx - 6.0f * q, cy - 6.0f * q, nxx - 6.0f * q, cy + 6.0f * q, nxx + 3.5f * q, cy};
        FillPoly(cv, tn, [white](float, float) -> RGBA { return white; });

        if (mi.playing) {
            FillRRect(cv, plx - 3.6f * q, cy, 1.8f * q, 6.0f * q, 0.8f * q, [white](float, float) -> RGBA { return white; });
            FillRRect(cv, plx + 3.6f * q, cy, 1.8f * q, 6.0f * q, 0.8f * q, [white](float, float) -> RGBA { return white; });
        } else {
            std::vector<float> tpl = {plx - 3.0f * q, cy - 7.0f * q, plx - 3.0f * q, cy + 7.0f * q, plx + 7.0f * q, cy};
            FillPoly(cv, tpl, [white](float, float) -> RGBA { return white; });
        }
    }

    // Caratula a la izquierda; titulo, artista y ecualizador a su derecha.
    DrawThumb(cv, t, f, M + 18.0f * k, M + 42.0f * k, kThumbU * k, k, ac);

    float tx = M + (18.0f + kThumbU + 12.0f) * k;
    std::wstring title = mi.title.empty()
                             ? std::wstring(TR(L"Sin reproducci\u00F3n", L"Nothing playing", L"Sense reproducci\u00F3"))
                             : mi.title;
    int maxW = (int)((cardWu - 18.0f - (18.0f + kThumbU + 12.0f)) * k);
    DrawLabel(t, f.name, Ellipsize(t, f.name, title, maxW), tx, M + 40.0f * k, 0, white);
    if (!mi.artist.empty())
        DrawLabel(t, f.small, Ellipsize(t, f.small, mi.artist, maxW), tx, M + 60.0f * k, 0, soft);

    // Ecualizador: a la derecha de la caratula. El color de cada barra depende de
    // la altura que alcanza, asi que los tonos calidos aparecen al subir.
    {
        float ex0 = tx, ex1 = right;
        float eBase = M + (42.0f + kThumbU) * k;  // alineado con el borde inferior de la caratula
        float eTop = M + 84.0f * k;
        float eH = eBase - eTop;
        float bw = (ex1 - ex0) / (float)kEqBars;
        float bhw = std::max(0.8f * k, bw * 0.26f);
        const bool live = g.media.valid && g.media.playing;
        const EqPal pal = g.eqAccent ? EqPalAccent(ac) : g.eqPal;
        for (int i = 0; i < kEqBars; i++) {
            float v = live ? g_eqBars[i] : 0.0f;
            float barH = eH * Clamp01(v);
            float bcx2 = ex0 + bw * ((float)i + 0.5f);
            // Pista tenue en la base: se ve aunque no suene nada.
            FillRRect(cv, bcx2, eBase - 0.9f * k, bhw, 0.9f * k, 0.9f * k,
                      [](float, float) -> RGBA { return C(90, 175, 255, 0.20f); });
            float pk = live ? Clamp01(g_eqPeak[i]) : 0.0f;
            if (pk > 0.05f) {
                RGBA pc = LerpC(EqColor(pal, pk), C(255, 255, 255), 0.45f);
                pc.a = 0.95f;
                FillRRect(cv, bcx2, eBase - eH * pk - 1.6f * k, bhw, 0.8f * k, 0.8f * k,
                          [pc](float, float) -> RGBA { return pc; });
            }
            if (barH < 2.0f * k) continue;
            float bhh = barH / 2.0f;
            // El color sale de la altura absoluta del pixel dentro del ecualizador.
            FillRRect(cv, bcx2, eBase - bhh, bhw, bhh, std::min(bhw, 2.4f * k),
                      [eBase, eH, pal](float, float y) -> RGBA {
                          RGBA c = EqColor(pal, (eBase - y) / eH);
                          c.a = 0.92f;
                          return c;
                      });
        }
    }

    // Progreso, a todo lo ancho bajo la caratula.
    float px0 = M + 18.0f * k, px1 = right, py = M + 135.0f * k;
    FillRRect(cv, (px0 + px1) / 2.0f, py, (px1 - px0) / 2.0f, 1.8f * k, 1.8f * k,
              [](float, float) -> RGBA { return HL(0.14f); });
    if (mi.dur > 1.0) {
        float frac = Clamp01((float)(mi.pos / mi.dur));
        float w = (px1 - px0) * frac;
        if (w > 1.0f * k) {
            float hw = std::max(w / 2.0f, 1.8f * k);
            FillRRect(cv, px0 + hw, py, hw, 1.8f * k, 1.8f * k, [ac](float, float) -> RGBA {
                RGBA c = ac;
                c.a = 0.95f;
                return c;
            });
        }
    }
}

// ---- clock and pomodoro ---------------------------------------------------

static bool PomoOn() { return g.pomoFocus > 0; }
static float ClockRowsEnd() { return 38.0f + 24.0f * (float)(1 + g.zones.size()); }
static float ClockPomoY() { return ClockRowsEnd() + 6.0f; }
static float ClockCardH() { return PomoOn() ? ClockRowsEnd() + 76.0f : ClockRowsEnd() + 10.0f; }
static const float kPomoPlayX = 292.0f, kPomoResetX = 332.0f;

static void DrawClock(Canvas& cv, TextCtx& t, Fonts& f, float M, float k, float cardWu) {
    float right = M + (cardWu - 18.0f) * k;
    RGBA white = g.pal.white, soft = g.pal.soft, dimc = g.pal.dimc;
    RGBA ac = CardAccent(C(255, 170, 90));

    DrawCardHeader(cv, t, f, CARD_CLOCK, M, k, TR(L"RELOJ", L"CLOCK", L"RELLOTGE"));

    SYSTEMTIME loc;
    GetLocalTime(&loc);
    long long locDay = DayNumber((int)loc.wYear, (int)loc.wMonth, (int)loc.wDay);

    for (size_t i = 0; i < 1 + g.zones.size(); i++) {
        float ry = M + (38.0f + 24.0f * (float)i) * k;
        SYSTEMTIME zt = loc;
        // La hora local no lleva etiqueta: se entiende sola y ahorra una fila.
        std::wstring label;
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
        wsprintfW(tb, L"%02d:%02d", (int)zt.wHour, (int)zt.wMinute);
        int tw = DrawLabel(t, f.pill, tb, right, ry, 2, white);
        if (diff != 0) {
            std::wstring dd = (diff > 0 ? L"+" : L"") + std::to_wstring(diff) + L" d";
            DrawLabel(t, f.small, dd, right - (float)tw - 10.0f * k, ry + 2.0f * k, 2, dimc);
        }

        float lx = M + 18.0f * k;
        if (flag != FL_NONE) {
            DrawFlag(cv, flag, M + 30.0f * k, ry + 10.0f * k, k);
            lx = M + 48.0f * k;
        }
        if (!label.empty())
            DrawLabel(t, f.name, Ellipsize(t, f.name, label, (int)(160.0f * k)), lx, ry, 0,
                      i == 0 ? soft : white);
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
// Fondo de cristal (en cache) y render de cada tarjeta
// ---------------------------------------------------------------------------

static void BuildBackground(Canvas& cv, float M, float cardW, float cardH, float k, RGBA ac, bool hover,
                            RGBA topC, RGBA botC) {
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

    // Never fully transparent, otherwise clicks fall through the card.
    float baseA = std::max(0.03f, Clamp01((float)g.glassOpacity / 100.0f) * 0.72f + (hover ? 0.06f : 0.0f));
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

static const wchar_t* CardTitle(int id) {
    if (id == CARD_SYSTEM) return TR(L"SISTEMA", L"SYSTEM", L"SISTEMA");
    if (id == CARD_DEADLINES) return TR(L"AGENDA", L"AGENDA", L"AGENDA");
    if (id == CARD_NOTES) return TR(L"NOTAS", L"NOTES", L"NOTES");
    if (id == CARD_MEDIA) return TR(L"MULTIMEDIA", L"MEDIA", L"MULTIM\u00C8DIA");
    if (id == CARD_CLOCK) return TR(L"RELOJ", L"CLOCK", L"RELLOTGE");
    return TR(L"TIEMPO", L"WEATHER", L"TEMPS");
}

static unsigned long long HashMix(unsigned long long h, long long v) {
    return (h * 1099511628211ULL) ^ (unsigned long long)v;
}

// Yellow paper: flat colour in the writing area (so the edit overlay matches it exactly),
// darker adhesive band at the top and a folded bottom-right corner.
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

// Returns true when the card was actually drawn.
// DIB reutilizables: crear y destruir dos DIB y dos DC en cada pintado era
// lo mas caro de repintar una tarjeta. Todas tienen el mismo ancho, asi que
// basta con crecer en alto cuando hace falta (el paso de fila es siempre W * 4).
struct RenderDib {
    HDC dc = nullptr;
    HBITMAP bmp = nullptr;
    HGDIOBJ old = nullptr;
    DWORD* bits = nullptr;
    int w = 0;
    int h = 0;
};
static RenderDib g_dibText, g_dibOut;
static Canvas g_cvScratch;

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
    g_cvScratch = Canvas();
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

static bool RenderCard(Card& c) {
    if (!c.win || g.dragCard) return false;

    UINT dpiU = GetDpiForWindow(c.win);
    float dpi = dpiU ? (float)dpiU / 96.0f : 1.0f;
    float k = ((float)g.scale / 100.0f) * dpi;
    g.dpi = dpi;
    g.kLast = k;
    Fonts& fonts = EnsureFonts(k);

    std::vector<Deadline> vis;
    WLayout L;
    const float cardWu = 372.0f;
    float cardHu = 0.0f;
    RGBA ac = C(90, 175, 255);
    RGBA topC = g.pal.topC, botC = g.pal.botC;
    bool folded = g.collapsed[c.id] && c.id != CARD_WEATHER;

    if (c.id == CARD_WEATHER) {
        const Weather& wt = g.weather;
        L = WeatherLayout(wt);
        cardHu = L.cardH;
        ac = wt.valid ? AccentFor(KindFromCode(wt.code), wt.isDay) : AccentFor(K_CLOUD, true);
        WeatherTint(wt, topC, botC);
    } else if (c.id == CARD_SYSTEM) {
        cardHu = 104.0f + (float)BuildSysRows().size() * 26.0f + (g.procs.empty() ? 8.0f : (g.procs.size() >= 4 ? 118.0f : 104.0f));
        ac = CardAccent(C(90, 175, 255));
    } else if (c.id == CARD_DEADLINES) {
        vis = VisibleDeadlines();
        int groups = 0, prevG = -99;
        for (size_t gi = 0; gi < vis.size(); gi++) {
            int gv = AgendaGroupOf(vis[gi].days);
            if (gv != prevG) { prevG = gv; groups++; }
        }
        float listExtra = (g.icsShowList && !g.icsUrl.empty()) ? 40.0f : 0.0f;
        cardHu = 38.0f + (float)(std::max(1, (int)vis.size()) + groups) * 40.0f +
                 listExtra + 10.0f;
        ac = vis.empty() ? CardAccent(C(140, 170, 215)) : UrgencyColor(vis[0].days);
    } else if (c.id == CARD_NOTES) {
        cardHu = StickyCardHu(k);
        ac = C(255, 225, 90);
    } else if (c.id == CARD_MEDIA) {
        cardHu = 146.0f;
        ac = CardAccent(C(255, 120, 160));
    } else {
        cardHu = ClockCardH();
        ac = CardAccent(C(255, 170, 90));
    }

    if (folded) cardHu = 40.0f;

    float cardW = cardWu * k;
    float cardH = cardHu * k;
    float M = 20.0f * k;
    int W = (int)ceilf(cardW + 2.0f * M);
    int H = (int)ceilf(cardH + 2.0f * M);

    unsigned long long key = 1469598103934665603ULL;
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
    auto buildBg = [&](bool hover, std::vector<DWORD>& out) {
        Canvas bgc;
        bgc.w = W;
        bgc.h = H;
        bgc.px.assign((size_t)W * (size_t)H, 0);
        if (c.id == CARD_NOTES) BuildStickyBackground(bgc, M, cardW, cardH, k);
        else BuildBackground(bgc, M, cardW, cardH, k, ac, hover, topC, botC);
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
    cv.px = hov ? c.bgHover : c.bg;

    if (!EnsureDib(g_dibText, W, H, true) || !EnsureDib(g_dibOut, W, H, false)) return false;
    HDC mdc = g_dibText.dc;
    DWORD* sbits = g_dibText.bits;
    memset(sbits, 0, (size_t)W * (size_t)H * 4);

    TextCtx t = {mdc, sbits, W, H, &cv};

    if (folded) {
        if (c.id == CARD_NOTES) {
            DrawStickyHeader(cv, t, fonts, M, k, cardWu, true);
        } else {
            DrawCardHeader(cv, t, fonts, c.id, M, k, CardTitle(c.id));
            DrawLabel(t, fonts.small, L"\u25B8", M + (cardWu - 18.0f) * k, M + 12.0f * k, 2, g.pal.dimc);
        }
    } else if (c.id == CARD_WEATHER) DrawWeather(cv, t, fonts, M, k, cardWu, L);
    else if (c.id == CARD_SYSTEM) DrawSystem(cv, t, fonts, M, k, cardWu);
    else if (c.id == CARD_DEADLINES) DrawDeadlines(cv, t, fonts, M, k, cardWu, vis);
    else if (c.id == CARD_NOTES) DrawSticky(cv, t, fonts, M, k, cardWu);
    else if (c.id == CARD_MEDIA) DrawMedia(cv, t, fonts, M, k, cardWu);
    else DrawClock(cv, t, fonts, M, k, cardWu);

    memcpy(g_dibOut.bits, cv.px.data(), (size_t)W * (size_t)H * 4);

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
    if (!UpdateLayeredWindow(c.win, nullptr, nullptr, &sz, g_dibOut.dc, &src, 0, &bf, ULW_ALPHA)) {
        Wh_Log(L"UpdateLayeredWindow failed: %lu", GetLastError());
    }
    return true;
}

// ---------------------------------------------------------------------------
// Apilado, posicion y ajuste a los bordes
// ---------------------------------------------------------------------------

static Card* FirstPlaced() {
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[kOrder[i]];
        if (c.win && c.placed) return &c;
    }
    return nullptr;
}

static void Restack() {
    Card* first = FirstPlaced();
    if (!first) return;

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
        Card& c = g.cards[kOrder[i]];
        if (c.win && c.placed) placedN++;
    }
    // Un solo reposicionamiento para todas las tarjetas: sin parpadeo ni saltos.
    HDWP dwp = placedN ? BeginDeferWindowPos(placedN) : nullptr;
    for (int i = 0; i < CARD_COUNT; i++) {
        Card& c = g.cards[kOrder[i]];
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
// Ajustes y listas (notas, plazos, husos)
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
    Wh_GetStringValue(name, buf.data(), buf.size() - 1);
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

// Notes and deadlines come from the settings unless they were edited on the card.
static void LoadLists() {
    // Avisos ya mostrados: se guardan en el almacenamiento del mod para que un
    // reinicio del explorador no los repita dentro de la misma ventana de aviso.
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

    // sticky note: the text lives in the mod storage; the notes setting only seeds it once
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

static void LoadSettings() {
    g.settingsVersion++;
    g.dueDisks = g.dueGpu = g.dueBat = g.dueWifi = g.dueProcs = 0;

    std::wstring lang = GetStr(L"language");
    g.lang = (lang == L"en") ? 1 : (lang == L"ca" ? 2 : 0);
    std::wstring theme = GetStr(L"theme");
    g.theme = (theme == L"dark") ? 1 : (theme == L"light" ? 2 : 0);
    g.useWinAccent = Wh_GetIntSetting(L"useWindowsAccent") != 0;
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
    g.icsUrl = Trim(GetStr(L"icsUrl"));
    g.icsLabel = Trim(GetStr(L"icsLabel"));
    g.icsNext = 0;

    g.showWeather = Wh_GetIntSetting(L"showWeather") != 0;
    g.showSystem = Wh_GetIntSetting(L"showSystem") != 0;
    g.showMedia = Wh_GetIntSetting(L"showMedia") != 0;
    g.mediaAutoHide = Wh_GetIntSetting(L"mediaAutoHide") != 0;
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
    g.showBattery = Wh_GetIntSetting(L"showBattery") != 0;
    g.showWifi = Wh_GetIntSetting(L"showWifi") != 0;
    g.onlineCovers = Wh_GetIntSetting(L"onlineCovers") != 0;
    g.embedCovers = Wh_GetIntSetting(L"embedCovers") != 0;
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

    g.pomoFocus = ClampInt(Wh_GetIntSetting(L"pomoFocus"), 0, 180);
    g.pomoBreak = ClampInt(Wh_GetIntSetting(L"pomoBreak"), 1, 60);
    if (!g.pomoRun && !g.pomoStarted) g.pomoLeft = (g.pomoMode ? g.pomoBreak : g.pomoFocus) * 60;

    for (int i = 0; i < CARD_COUNT; i++) {
        wchar_t key[32];
        wsprintfW(key, L"collapsed%d", i);
        g.collapsed[i] = Wh_GetIntValue(key, 0) != 0;
    }

    UpdatePalette();

    Wh_Log(L"Settings loaded: %d deadline line(s), %d parsed, note of %d char(s)", (int)g.dlRaw.size(),
           (int)g.deadlines.size(), (int)g.stickyText.size());
}

// ---------------------------------------------------------------------------
// Editor de notas y plazos
// ---------------------------------------------------------------------------

static HWND g_editWin = nullptr;
static int g_editWhich = 0;  // 0 notes, 1 deadlines
static HFONT g_editFont = nullptr;

static LRESULT CALLBACK EditWndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_CREATE: {
            HINSTANCE hi = GetModuleHandleW(nullptr);
            CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE, 0, 0, 10, 10, h, (HMENU)(INT_PTR)101,
                            hi, nullptr);
            CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
                            WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN,
                            0, 0, 10, 10, h, (HMENU)(INT_PTR)100, hi, nullptr);
            CreateWindowExW(0, L"BUTTON", TR(L"Guardar", L"Save", L"Desa"),
                            WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 0, 0, 10, 10, h, (HMENU)(INT_PTR)1, hi,
                            nullptr);
            CreateWindowExW(0, L"BUTTON", TR(L"Cancelar", L"Cancel", L"Cancel\u00B7la"),
                            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 0, 10, 10, h, (HMENU)(INT_PTR)2, hi,
                            nullptr);
            if (!g_editFont) {
                g_editFont = CreateFontW(-15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                         OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                         DEFAULT_PITCH | FF_DONTCARE, L"Segoe UI");
            }
            int ids[4] = {100, 101, 1, 2};
            for (int i = 0; i < 4; i++)
                SendMessageW(GetDlgItem(h, ids[i]), WM_SETFONT, (WPARAM)g_editFont, TRUE);
            return 0;
        }
        case WM_SIZE: {
            RECT rc;
            GetClientRect(h, &rc);
            int W = rc.right, H = rc.bottom;
            MoveWindow(GetDlgItem(h, 101), 12, 8, W - 24, 38, TRUE);
            MoveWindow(GetDlgItem(h, 100), 12, 50, W - 24, std::max(40, H - 50 - 52), TRUE);
            MoveWindow(GetDlgItem(h, 2), W - 12 - 100, H - 40, 100, 28, TRUE);
            MoveWindow(GetDlgItem(h, 1), W - 12 - 100 - 8 - 100, H - 40, 100, 28, TRUE);
            return 0;
        }
        case WM_COMMAND:
            if (LOWORD(w) == 1) {
                HWND ed = GetDlgItem(h, 100);
                int len = GetWindowTextLengthW(ed);
                std::vector<wchar_t> buf((size_t)len + 2, 0);
                GetWindowTextW(ed, buf.data(), len + 1);
                std::wstring o;
                for (const wchar_t* p = buf.data(); *p; p++) {
                    if (*p != L'\r') o += *p;
                }
                if (g_editWhich == 0) {
                    Wh_SetStringValue(L"notesText", o.c_str());
                    Wh_SetIntValue(L"notesOvr", 1);
                } else {
                    Wh_SetStringValue(L"dlText", o.c_str());
                    Wh_SetIntValue(L"dlOvr", 1);
                }
                LoadLists();
                g.cards[CARD_NOTES].dirty = true;
                g.cards[CARD_DEADLINES].dirty = true;
                DestroyWindow(h);
            } else if (LOWORD(w) == 2) {
                DestroyWindow(h);
            }
            return 0;
        case WM_CLOSE:
            DestroyWindow(h);
            return 0;
        case WM_DESTROY:
            g_editWin = nullptr;
            return 0;
    }
    return DefWindowProcW(h, m, w, l);
}

static void OpenEditor(int which) {
    if (g_editWin) {
        SetForegroundWindow(g_editWin);
        return;
    }
    int W = 540, H = 430;
    int x = (GetSystemMetrics(SM_CXSCREEN) - W) / 2;
    int y = (GetSystemMetrics(SM_CYSCREEN) - H) / 2;
    const wchar_t* title = which == 0 ? TR(L"Editar notas", L"Edit notes", L"Edita les notes")
                                      : TR(L"Editar agenda", L"Edit agenda", L"Edita l'agenda");
    g_editWin = CreateWindowExW(0, kEditClass, title, WS_OVERLAPPEDWINDOW, x, y, W, H, nullptr, nullptr,
                                GetModuleHandleW(nullptr), nullptr);
    if (!g_editWin) return;
    g_editWhich = which;

    const wchar_t* help =
        which == 0
            ? TR(L"Una l\u00EDnea por nota:  [ ] tarea abierta   [x] hecha   ! importante",
                 L"One line per note:  [ ] open task   [x] done   ! important",
                 L"Una l\u00EDnia per nota:  [ ] tasca oberta   [x] feta   ! important")
            : TR(L"DD/MM/AAAA [HH:MM] Texto [@diario|@semanal|@mensual|@anual] [# Lugar]",
                 L"DD/MM/YYYY [HH:MM] Text [@daily|@weekly|@monthly|@yearly] [# Place]",
                 L"DD/MM/AAAA [HH:MM] Text [@diari|@setmanal|@mensual|@anual] [# Lloc]");
    SetWindowTextW(GetDlgItem(g_editWin, 101), help);

    const std::vector<std::wstring>& raw = which == 0 ? g.noteRaw : g.dlRaw;
    std::wstring txt;
    for (size_t i = 0; i < raw.size(); i++) {
        if (i) txt += L"\r\n";
        txt += raw[i];
    }
    SetWindowTextW(GetDlgItem(g_editWin, 100), txt.c_str());

    ShowWindow(g_editWin, SW_SHOW);
    SetForegroundWindow(g_editWin);
    SetFocus(GetDlgItem(g_editWin, 100));
}

// ---------------------------------------------------------------------------
// Clics, menu contextual y ventanas
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// Post-it: se escribe directamente sobre la nota y se guarda solo
// ---------------------------------------------------------------------------

static HWND g_stickyHost = nullptr;
static HWND g_stickyEdit = nullptr;
static WNDPROC g_oldEditProc = nullptr;
static HFONT g_stickyFont = nullptr;
static HBRUSH g_paperBrush = nullptr;
static const UINT WM_STICKY_CLOSE = WM_APP + 10;

static void StickySave() {
    if (!g_stickyEdit) return;
    int len = GetWindowTextLengthW(g_stickyEdit);
    std::vector<wchar_t> buf((size_t)len + 2, 0);
    GetWindowTextW(g_stickyEdit, buf.data(), len + 1);
    std::wstring o;
    for (const wchar_t* p = buf.data(); *p; p++) {
        if (*p != L'\r') o += *p;
    }
    g.stickyText = o;
    Wh_SetStringValue(L"stickyText", o.c_str());
    Wh_SetIntValue(L"stickyInit", 1);
}

static void StickyClose() {
    if (!g_stickyHost) return;
    StickySave();
    HWND h = g_stickyHost;
    g_stickyHost = nullptr;
    g_stickyEdit = nullptr;
    DestroyWindow(h);
    if (g_stickyFont) {
        DeleteObject(g_stickyFont);
        g_stickyFont = nullptr;
    }
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
            if (w == 1) return 0;  // Ctrl+A
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
            // Every change is saved after a short pause: nothing to confirm.
            if (HIWORD(w) == EN_CHANGE) {
                g.stickyCanUndo = false;
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
    RECT rc;
    if (!GetWindowRect(card->win, &rc)) return;
    float k = g.kLast;
    int x = rc.left + card->mPx + (int)(18.0f * k);
    int y = rc.top + card->mPx + (int)(kStickyTextTop * k);
    int w = (int)((372.0f - 36.0f) * k);
    int h = card->cardHpx - (int)(kStickyTextTop * k) - (int)(kStickyPad * k);
    if (h < 20) return;

    HINSTANCE hi = GetModuleHandleW(nullptr);
    g_stickyHost = CreateWindowExW(WS_EX_TOOLWINDOW, kStickyClass, L"", WS_POPUP, x, y, w, h, nullptr, nullptr,
                                   hi, nullptr);
    if (!g_stickyHost) return;
    g_stickyEdit = CreateWindowExW(0, L"EDIT", L"",
                                   WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN, 0, 0,
                                   w, h, g_stickyHost, (HMENU)(INT_PTR)100, hi, nullptr);
    if (!g_stickyEdit) {
        DestroyWindow(g_stickyHost);
        g_stickyHost = nullptr;
        return;
    }

    g_stickyFont = MakeFontFace((int)(15.0f * k), FW_NORMAL, L"Segoe Print");
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
    g.stickyUndo = g.stickyText;
    g.stickyCanUndo = true;
    g.stickyText.clear();
    Wh_SetStringValue(L"stickyText", L"");
    g.cards[CARD_NOTES].dirty = true;
}

static void StickyUndo() {
    if (!g.stickyCanUndo) return;
    g.stickyText = g.stickyUndo;
    g.stickyCanUndo = false;
    Wh_SetStringValue(L"stickyText", g.stickyText.c_str());
    g.cards[CARD_NOTES].dirty = true;
}

static void ToggleFold(Card* card) {
    g.collapsed[card->id] = !g.collapsed[card->id];
    wchar_t key[32];
    wsprintfW(key, L"collapsed%d", card->id);
    Wh_SetIntValue(key, g.collapsed[card->id] ? 1 : 0);
    card->bgKey = 0;
    if (RenderCard(*card)) card->dirty = false;
    Restack();
}

static void PomoReset() {
    g.pomoRun = false;
    g.pomoStarted = false;
    g.pomoMode = 0;
    g.pomoLeft = g.pomoFocus * 60;
    g.cards[CARD_CLOCK].dirty = true;
}

static bool NearPoint(float ux, float uy, float cx, float cy, float r) {
    return Len2(ux - cx, uy - cy) <= r;
}

// A click on the header folds the card; other clicks depend on the card.
static void HandleClick(Card* card, int x, int y) {
    float k = g.kLast;
    float M = (float)card->mPx;
    float ux = ((float)x - M) / k;
    float uy = ((float)y - M) / k;

    // La esquina superior derecha de la agenda abre y cierra la lista de
    // calendarios. Va antes del plegado para que no se lo coma.
    if (card->id == CARD_DEADLINES && uy < 34.0f && ux >= 150.0f && !g.icsUrl.empty()) {
        g.icsShowList = !g.icsShowList;
        card->bgKey = 0;
        if (RenderCard(*card)) card->dirty = false;
        Restack();
        return;
    }

    if (card->id != CARD_WEATHER && uy < 34.0f && ux < 150.0f) {
        ToggleFold(card);
        return;
    }
    if (g.collapsed[card->id] && card->id != CARD_WEATHER) return;

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
        if (g.icsShowList) {
            // Un clic en cualquier otro sitio de la agenda cierra la lista.
            g.icsShowList = false;
            card->bgKey = 0;
            if (RenderCard(*card)) card->dirty = false;
            Restack();
            return;
        }
        int row = DeadlineRowAt(uy);
        std::vector<Deadline> v = VisibleDeadlines();
        if (row < 0 || row >= (int)v.size()) return;
        float rel = uy - DeadlineRowTop(row, v);
        const Deadline& dl = v[(size_t)row];
        if (!dl.place.empty() && ux >= 78.0f && rel >= 18.0f && rel <= 36.0f) {
            // El lugar abre Maps.
            std::wstring url =
                L"https://www.google.com/maps/search/?api=1&query=" + UrlEncode(dl.place);
            ShellExecuteW(nullptr, L"open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
            return;
        }
        if (ux < 78.0f) {
            // Un clic en la cuenta atras marca la cita como vista; otro clic la desmarca.
            ToggleDeadlineDone(dl);
            redraw = true;
        }
        return;
    } else if (card->id == CARD_MEDIA) {
        if (NearPoint(ux, uy, kMediaPlayX, kMediaBtnY, 14.0f)) MediaCommand(1);
        else if (NearPoint(ux, uy, kMediaPrevX, kMediaBtnY, 12.0f)) MediaCommand(0);
        else if (NearPoint(ux, uy, kMediaNextX, kMediaBtnY, 12.0f)) MediaCommand(2);
        else return;
        g.media.playing = (card->id == CARD_MEDIA && NearPoint(ux, uy, kMediaPlayX, kMediaBtnY, 14.0f))
                              ? !g.media.playing
                              : g.media.playing;
        redraw = true;
    } else if (card->id == CARD_CLOCK && PomoOn()) {
        float cy = ClockPomoY() + 38.0f;
        if (NearPoint(ux, uy, kPomoPlayX, cy, 18.0f)) {
            g.pomoRun = !g.pomoRun;
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

static void ShowCardMenu(Card* card, HWND hwnd) {
    HMENU m = CreatePopupMenu();
    if (!m) return;
    int id = card->id;

    if (id != CARD_WEATHER)
        AppendMenuW(m, MF_STRING, 1,
                    g.collapsed[id] ? TR(L"Desplegar", L"Expand", L"Desplega") : TR(L"Plegar", L"Collapse", L"Plega"));
    if (id == CARD_WEATHER) AppendMenuW(m, MF_STRING, 2, TR(L"Actualizar ahora", L"Refresh now", L"Actualitza ara"));
    if (id == CARD_SYSTEM)
        AppendMenuW(m, MF_STRING, 6, TR(L"Administrador de tareas", L"Task Manager", L"Gestor de tasques"));
    if (id == CARD_DEADLINES) {
        AppendMenuW(m, MF_STRING, 3, TR(L"Editar agenda...", L"Edit agenda...", L"Edita l'agenda..."));
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
            AppendMenuW(m, MF_STRING, 13, TR(L"Deshacer borrado", L"Undo clear", L"Desf\u00E9s l'esborrat"));
        else
            AppendMenuW(m, MF_STRING | (g.stickyText.empty() ? MF_GRAYED : 0), 12,
                        TR(L"Borrar la nota", L"Clear the note", L"Esborra la nota"));
    }
    if (id == CARD_CLOCK && PomoOn())
        AppendMenuW(m, MF_STRING, 9, TR(L"Reiniciar temporizador", L"Reset timer", L"Reinicia el temporitzador"));

    AppendMenuW(m, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(m, MF_STRING | (g.lockPosition ? MF_CHECKED : 0), 4,
                TR(L"Bloquear posici\u00F3n", L"Lock position", L"Bloqueja la posici\u00F3"));
    AppendMenuW(m, MF_STRING, 5, TR(L"Restablecer posici\u00F3n", L"Reset position", L"Restableix la posici\u00F3"));

    POINT p;
    GetCursorPos(&p);
    SetForegroundWindow(hwnd);
    int cmd = TrackPopupMenu(m, TPM_RETURNCMD | TPM_RIGHTBUTTON | TPM_NONOTIFY, p.x, p.y, 0, hwnd, nullptr);
    PostMessageW(hwnd, WM_NULL, 0, 0);
    DestroyMenu(m);

    switch (cmd) {
        case 1: ToggleFold(card); break;
        case 2:
            g.nextFetch = 0;
            break;
        case 3: OpenEditor(id == CARD_NOTES ? 0 : 1); break;
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
            Wh_SetIntValue(id == CARD_NOTES ? L"notesOvr" : L"dlOvr", 0);
            LoadLists();
            g.cards[CARD_NOTES].dirty = true;
            g.cards[CARD_DEADLINES].dirty = true;
            break;
        case 11: g.icsNext = 0; break;
        case 12: StickyClear(); break;
        case 13: StickyUndo(); break;
        default: break;
    }
}

static LRESULT CALLBACK CardWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    Card* card = reinterpret_cast<Card*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));

    switch (msg) {
        case WM_MOUSEACTIVATE:
            // The note must be able to take the keyboard focus to be typed on.
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

        case WM_MOUSEMOVE:
            if (card && g.hoverCard != card && !g.dragCard) {
                Card* prev = g.hoverCard;
                g.hoverCard = card;
                TRACKMOUSEEVENT tme;
                memset(&tme, 0, sizeof(tme));
                tme.cbSize = sizeof(tme);
                tme.dwFlags = TME_LEAVE;
                tme.hwndTrack = hwnd;
                TrackMouseEvent(&tme);
                // The previous card may not get its WM_MOUSELEAVE in time; clear it here.
                if (prev && prev->win && RenderCard(*prev)) prev->dirty = false;
                if (RenderCard(*card)) card->dirty = false;
            }
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

        case WM_LBUTTONUP:
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

        case WM_RBUTTONUP:
            if (card) ShowCardMenu(card, hwnd);
            return 0;

        case WM_MOUSELEAVE:
            if (card && g.hoverCard == card) {
                g.hoverCard = nullptr;
                if (RenderCard(*card)) card->dirty = false;
            }
            return 0;

        case WM_CAPTURECHANGED:
            if (card && g.dragCard == card) g.dragCard = nullptr;
            return 0;

        case WM_LBUTTONDBLCLK:
            if (card) {
                // A double click on the header is just two folds: ignore it.
                float uy = ((float)(short)HIWORD(lp) - (float)card->mPx) / g.kLast;
                if (card->id != CARD_WEATHER && uy < 34.0f) return 0;
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

    // Not WS_EX_NOACTIVATE: such layered windows receive no mouse-move or button-up.
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
        if (g.hoverCard == &c) g.hoverCard = nullptr;
        DestroyWindow(c.win);
        c.win = nullptr;
        g.needStack = true;
    }
    c.placed = false;
}

// ---------------------------------------------------------------------------
// Temporizador principal y avisos de plazos
// ---------------------------------------------------------------------------

static void MarkAllDirty() {
    for (int i = 0; i < CARD_COUNT; i++) {
        g.cards[i].dirty = true;
        g.cards[i].bgKey = 0;
    }
}

static void CheckDeadlineNotices() {
    if (g.notifyMin <= 0) return;
    // Aviso de citas que se han pasado: se miran las de los ultimos siete dias,
    // que son las que el filtro de la tarjeta ya no muestra. Cada una avisa una
    // sola vez, con la misma memoria que los avisos de antes.
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
            std::wstring body = TR(L"Se pasó  \u00B7  ", L"Missed  \u00B7  ", L"S'ha passat  \u00B7  ") +
                                std::to_wstring(d.d) + L" " + MonthShort(d.m) +
                                L"  \u00B7  " + std::to_wstring(d.hh >= 0 ? d.hh : 0) +
                                L":" + (d.mm >= 0 && d.mm < 10 ? L"0" : L"") +
                                std::to_wstring(d.mm >= 0 ? d.mm : 0);
            if (!d.place.empty()) body += L"  \u00B7  " + d.place;
            ShowNotice(d.name, body);
            // Persistir, para que no se repita tras reiniciar el explorador.
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
        if (DeadlineDone(d)) continue;   // ya marcada como vista: no avisar
        unsigned int key = TextHash(d.name + L"|" + std::to_wstring(d.dayNum) + L"|" +
                                    std::to_wstring(d.hh * 60 + d.mm));
        if (std::find(g.notified.begin(), g.notified.end(), key) != g.notified.end()) continue;
        g.notified.push_back(key);
        if (g.notified.size() > 200) g.notified.erase(g.notified.begin());
        // Persistir para que el aviso no se repita tras reiniciar el explorador.
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
// Ecualizador: temporizador rapido (solo mientras suena algo)
// ---------------------------------------------------------------------------

static UINT_PTR g_tmrEq = 0;

static void EqSetActive(bool on) {
    InterlockedExchange(&g_eqWanted, on ? 1 : 0);
    if (on && !g_eqThread && !g_eqQuit) {
        g_eqThread = CreateThread(nullptr, 0, EqCaptureThread, nullptr, 0, nullptr);
    }
    if (on && !g_tmrEq) g_tmrEq = SetTimer(nullptr, 0, 50, nullptr);
    if (!on && g_tmrEq) {
        KillTimer(nullptr, g_tmrEq);
        g_tmrEq = 0;
    }
}

static void EqShutdown() {
    InterlockedExchange(&g_eqQuit, 1);
    if (g_tmrEq) {
        KillTimer(nullptr, g_tmrEq);
        g_tmrEq = 0;
    }
    if (g_eqThread) {
        WaitForSingleObject(g_eqThread, 4000);
        CloseHandle(g_eqThread);
        g_eqThread = nullptr;
    }
}

// Cada 50 ms: sube de golpe, baja suave, y solo repinta si algo se ha movido.
static void OnEqTimer() {
    if (g.dragCard || g.paused || !g_eqCapOk) return;
    Card& cm = g.cards[CARD_MEDIA];
    if (!cm.win || !g.media.valid || !g.media.playing) return;
    bool changed = false;
    for (int i = 0; i < kEqBars; i++) {
        float t = Clamp01(g_eqLive[i]);
        float old = g_eqBars[i];
        float nv = t > old ? t : old + (t - old) * 0.30f;
        if (fabsf(nv - old) > 0.004f) changed = true;
        g_eqBars[i] = nv;
        float pk = g_eqPeak[i];
        float np = nv > pk ? nv : std::max(0.0f, pk - 0.015f);
        if (fabsf(np - pk) > 0.004f) changed = true;
        g_eqPeak[i] = np;
    }
    if (changed && RenderCard(cm)) cm.dirty = false;
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

    // Nothing to draw while a fullscreen app or a presentation is in front.
    if (g.pauseFs && FullscreenBusy()) {
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

    // The minute change is remembered in `dirty`, so a skipped redraw is not lost.
    if (minuteChanged) {
        cw.dirty = true;
        cd.dirty = true;
        cc.dirty = true;
    }

    // weather
    if (g.showWeather) {
        if (EnsureWindow(cw) && cw.dirty) {
            if (RenderCard(cw)) cw.dirty = false;
        }
        if (!g.fetching && now >= g.nextFetch) StartFetch();
    } else {
        DestroyCard(cw);
    }

    // calendar
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
            SampleCpu();
            SampleMemory();
            SampleNetwork();
            if (g.disks.empty() || now >= g.dueDisks) { SampleDisks(); g.dueDisks = now + 15000; }
            if (g.showGpu && (now >= g.dueGpu || g_gpu < 0.0)) { SampleGpu(); g.dueGpu = now + 2000; }
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
        bool eqPlay = g.media.valid && g.media.playing;
        EqSetActive(eqPlay);
        if (eqPlay && !g_eqCapOk) SampleEqualizer();  // respaldo si la captura no esta disponible
        unsigned int sig = TextHash(g.media.title + L"|" + g.media.artist) ^
                           (g.media.playing ? 0x9E3779B1u : 0u) ^ ((unsigned int)g.media.pos << 5) ^
                           (g.media.valid ? 1u : 0u);
        if (sig != g.mediaSig) {
            g.mediaSig = sig;
            cm.dirty = true;
        }
        bool want = !g.mediaAutoHide || g.media.valid;
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
    }

    // clock
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

static void OnThumb(ThumbResult* r) {
    if (g_thumbThread) {
        CloseHandle(g_thumbThread);
        g_thumbThread = nullptr;
    }
    g_thumbBusy = false;
    // Si ya hay una peticion mas reciente esperando, este resultado esta obsoleto.
    if (r->gen == g_thumbGen && !g_thumbRedo) {
        if (r->ok) {
            if (r->sourceHash != 0) InterlockedExchange64(&g_lastPlayerThumbHash, (LONG64)r->sourceHash);
            g.thumbPx.swap(r->px);
            g.thumbS = r->size;
            g.thumbOk = true;
        } else {
            g.thumbOk = false;
            g.thumbPx.clear();
        }
        g.cards[CARD_MEDIA].dirty = true;
        g_curCoverKey = r->ok ? r->key : std::wstring();
        if (g.embedCovers && (r->ok || g_embedPending)) {
            StartEmbedThread(g_curCoverKey, r->artist, r->title);
        }
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
    } else if (ok) {
        g.ics = r->ev;
        g.icsFailed = false;
        g.icsFailCount = 0;
        g.icsLastCount = (int)g.ics.size();
        g.icsLastOk = GetTickCount64();
        g.icsNext = GetTickCount64() + 30ULL * 60000ULL;
        g.cards[CARD_DEADLINES].dirty = true;
        Wh_Log(L"Calendar updated: %d event(s)", (int)g.ics.size());
    } else {
        // Reintento con espera creciente: 1, 2, 5, 10 y 15 minutos como tope.
        // Asi una caida de red pasajera se recupera sola sin insistir de mas.
        g.icsFailed = true;
        static const int kBackoffMin[5] = {1, 2, 5, 10, 15};
        int step = g.icsFailCount < 5 ? g.icsFailCount : 4;
        int waitMin = kBackoffMin[step];
        if (g.icsFailCount < 5) g.icsFailCount++;
        Wh_Log(L"Calendar update failed (%d in a row), retrying in %d min",
               g.icsFailCount, waitMin);
        g.icsNext = GetTickCount64() + (ULONGLONG)waitMin * 60000ULL;
        g.cards[CARD_DEADLINES].dirty = true;   // que se vea el aviso en la tarjeta
    }
    delete r;
}

static DWORD WINAPI WorkerThread(LPVOID) {
    MSG msg;
    PeekMessageW(&msg, nullptr, WM_USER, WM_USER, PM_NOREMOVE);
    SetEvent(g_ready);

    for (int i = 0; i < CARD_COUNT; i++) g.cards[i].id = i;

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
    ec.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    ec.lpszClassName = kEditClass;
    RegisterClassExW(&ec);

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

    while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
        if (!msg.hwnd) {
            if (msg.message == WM_TIMER) {
                if (g_tmrEq && msg.wParam == g_tmrEq) OnEqTimer();
                else OnTimer();
            } else if (msg.message == WM_APP_RELOAD) {
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
            } else if (msg.message == WM_APP_WEATHER) {
                OnWeather(msg.wParam != 0, reinterpret_cast<Weather*>(msg.lParam));
            } else if (msg.message == WM_APP_ICS) {
                OnIcs(msg.wParam != 0, reinterpret_cast<IcsResult*>(msg.lParam));
            } else if (msg.message == WM_APP_THUMB) {
                OnThumb(reinterpret_cast<ThumbResult*>(msg.lParam));
            }
            continue;
        }
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    // Shutdown: wait for running downloads (g_stop makes them return quickly).
    if (g.fetchThread) {
        WaitForSingleObject(g.fetchThread, 12000);
        CloseHandle(g.fetchThread);
        g.fetchThread = nullptr;
    }
    if (g.icsThread) {
        WaitForSingleObject(g.icsThread, 12000);
        CloseHandle(g.icsThread);
        g.icsThread = nullptr;
    }
    if (g_embedThread) {
        WaitForSingleObject(g_embedThread, 15000);
        CloseHandle(g_embedThread);
        g_embedThread = nullptr;
    }
    if (g_thumbThread) {
        WaitForSingleObject(g_thumbThread, 12000);
        CloseHandle(g_thumbThread);
        g_thumbThread = nullptr;
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
    for (int i = 0; i < CARD_COUNT; i++) DestroyCard(g.cards[i]);
    RemoveNotice();
    if (g.msgWin) {
        DestroyWindow(g.msgWin);
        g.msgWin = nullptr;
    }
    CloseGpu();
    CloseWifi();
    EqShutdown();
    CloseAudioMeter();
    ShutdownMedia();
    FreeRenderBuffers();
    if (g_editFont) {
        DeleteObject(g_editFont);
        g_editFont = nullptr;
    }
    if (g.fontsOk) {
        FreeFonts(g.fonts);
        g.fontsOk = false;
    }
    UnregisterClassW(kStickyClass, hi);
    if (g_paperBrush) {
        DeleteObject(g_paperBrush);
        g_paperBrush = nullptr;
    }
    UnregisterClassW(kEditClass, hi);
    UnregisterClassW(kWndClass, hi);
    return 0;
}

// ---------------------------------------------------------------------------
// Windhawk entry points
// ---------------------------------------------------------------------------

BOOL Wh_ModInit() {
    Wh_Log(L"Desktop glass cards 6.1 starting");
    g_stop = 0;
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
    if (g_thread) PostThreadMessageW(g_threadId, WM_APP_RELOAD, 0, 0);
}

void Wh_ModUninit() {
    g_stop = 1;
    if (g_thread) {
        PostThreadMessageW(g_threadId, WM_QUIT, 0, 0);
        WaitForSingleObject(g_thread, 15000);
        CloseHandle(g_thread);
        g_thread = nullptr;
    }
    if (g_ready) {
        CloseHandle(g_ready);
        g_ready = nullptr;
    }
}
