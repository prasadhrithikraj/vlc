/*****************************************************************************
 * config.h: limits and configuration
 * Defines all compilation-time configuration constants and size limits
 *****************************************************************************
 * Copyright (C) 1999, 2000, 2001 VideoLAN
 *
 * Authors: Vincent Seguin <seguin@via.ecp.fr>
 *          Samuel Hocevar <sam@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

/* Conventions regarding names of symbols and variables
 * ----------------------------------------------------
 *
 * - Symbols should begin with a prefix indicating in which module they are
 *   used, such as INTF_, VOUT_ or ADEC_.
 *
 * - Regarding environment variables, which are used as initialization
 *  parameters for threads :
 *   + variable names should end with '_VAR'
 *   + environment variable default value should end with '_DEFAULT'
 *   + values having a special meaning with '_VAL'
 *
 */

/*****************************************************************************
 * Debugging options - define or undefine symbols
 *****************************************************************************/
#ifdef TRACE
/* General trace support, which depends of the TRACE define, is determined
 * in the Makefile */

/* Modules specific debugging - this will produce a lot of output, but can be
 * useful to track a bug */
//#define TRACE_INTF
//#define TRACE_INPUT
//#define TRACE_AUDIO
#define TRACE_VOUT
#define TRACE_VPAR

/* Trace log file - if defined, a file can be used to store all messages. If
 * TRACE_LOG_ONLY is defined, debug messages will only be printed to the log and
 * will not appear on the screen */
#define TRACE_LOG                       "vlc-trace.log"
#define TRACE_LOG_ONLY

#endif

/*****************************************************************************
 * General configuration
 *****************************************************************************/

#define CLOCK_FREQ 1000000


/* Automagically spawn audio and video decoder threads */
#define AUTO_SPAWN

/* When creating or destroying threads in blocking mode, delay to poll thread
 * status */
#define THREAD_SLEEP                    ((int)(0.010*CLOCK_FREQ))

/* When a thread waits on a condition in debug mode, delay to wait before
 * outputting an error message (in second) */
#define THREAD_COND_TIMEOUT             5

/* Environment variable containing the memcpy method */
#define MEMCPY_METHOD_VAR               "vlc_memcpy"

/*
 * Paths
 */

#define MAX_PLUGIN_COUNT                32

/*****************************************************************************
 * Interface configuration
 *****************************************************************************/

/* Environment variable containing the display method */
#define INTF_METHOD_VAR                 "vlc_intf"
#define INTF_METHOD_DEFAULT             "gtk"

/* Environment variable used to store startup script name and default value */
#define INTF_INIT_SCRIPT_VAR            "vlcrc"
#define INTF_INIT_SCRIPT_DEFAULT        ".vlcrc"

/* Environment variable used to store channels file and default value */
#define INTF_CHANNELS_VAR               "vlc_channels"
#define INTF_CHANNELS_DEFAULT           "vlc.channels"

/* Base delay in micro second for interface sleeps */
#define INTF_IDLE_SLEEP                 ((int)(0.050*CLOCK_FREQ))

/* Step for changing gamma, and minimum and maximum values */
#define INTF_GAMMA_STEP                 .1
#define INTF_GAMMA_LIMIT                3

/* Maximum number of channels */
#define INTF_MAX_CHANNELS               10

/* Default search path for interface file browser */
#define INTF_PATH_VAR                   "vlc_search_path"
#define INTF_PATH_DEFAULT               ""

/* Environment variable containing the standard output method */
#define INTF_STDOUT_VAR                 "vlc_stdout"
#define INTF_STDOUT_DEFAULT             ""

/*****************************************************************************
 * Input thread configuration
 *****************************************************************************/

/* Environment variable containing the input method */
#define INPUT_METHOD_VAR                "vlc_input"
#define INPUT_METHOD_DEFAULT            "ps"

/* XXX?? */
#define INPUT_IDLE_SLEEP                ((int)(0.100*CLOCK_FREQ))

/*
 * General limitations
 */

/* Maximum number of input threads - this value is used exclusively by
 * interface, and is in fact an interface limitation */
#define INPUT_MAX_THREADS               10

/* Maximum size of a data packet (128 kB) */
#define INPUT_MAX_PACKET_SIZE           131072

/* Maximum length of a pre-parsed chunk (4 MB) */
#define INPUT_PREPARSE_LENGTH           4194304

/* Maximum length of a hostname or source name */
#define INPUT_MAX_SOURCE_LENGTH         100

/* Maximum memory the input is allowed to use (20 MB) */
#define INPUT_MAX_ALLOCATION            20971520

/* Default network protocol */
#define INPUT_NETWORK_PROTOCOL_VAR      "vlc_network_protocol"
#define INPUT_NETWORK_PROTOCOL_DEFAULT  "ts"

/* Default input port */
#define INPUT_PORT_VAR                  "vlc_server_port"
#define INPUT_PORT_DEFAULT              1234

/* FIXME : Delete those ! */
/* Default remote server */
#define INPUT_SERVER_VAR                "vlc_server"
#define INPUT_SERVER_DEFAULT            "138.195.143.220"

/* Broadcast mode */
#define INPUT_BROADCAST_VAR             "vlc_broadcast"
#define INPUT_BROADCAST_DEFAULT         0

/* Default broadcast address */
#define INPUT_BCAST_ADDR_VAR            "vlc_broadcast_addr"
#define INPUT_BCAST_ADDR_DEFAULT        "138.195.143.255"

/* Channels mode */
#define INPUT_NETWORK_CHANNEL_VAR       "vlc_channel"
#define INPUT_NETWORK_CHANNEL_DEFAULT   0

/*
 * Channel method
 */

/* Default network interface and environment variable */
#define INPUT_IFACE_VAR                 "vlc_iface"
#define INPUT_IFACE_DEFAULT             "eth0"

/* Default server and port */
#define INPUT_CHANNEL_SERVER_VAR           "vlc_channel_server"
#define INPUT_CHANNEL_SERVER_DEFAULT       "138.195.143.120"
#define INPUT_CHANNEL_PORT_VAR             "vlc_channel_port"
#define INPUT_CHANNEL_PORT_DEFAULT         6010

/* Delay between channel changes - this is required to avoid flooding the 
 * channel server */
#define INPUT_CHANNEL_CHANGE_DELAY         (mtime_t)(5*CLOCK_FREQ)

/* Duration between the time we receive the data packet, and the time we will
 * mark it to be presented */
#define DEFAULT_PTS_DELAY               (mtime_t)(.2*CLOCK_FREQ)

/* DVD defaults */
#define INPUT_DVD_DEVICE_VAR            "vlc_dvd_device"

#define INPUT_TITLE_VAR                 "vlc_input_title"
#define INPUT_CHAPTER_VAR               "vlc_input_chapter"
#define INPUT_ANGLE_VAR                 "vlc_input_angle"
#define INPUT_AUDIO_VAR                 "vlc_input_audio"
#define INPUT_CHANNEL_VAR               "vlc_input_channel"
#define INPUT_SUBTITLE_VAR              "vlc_input_subtitle"

/* VCD defaults */
#define INPUT_VCD_DEVICE_VAR            "vlc_vcd_device"

/*****************************************************************************
 * Audio configuration
 *****************************************************************************/

/* Maximum number of audio output threads */
#define AOUT_MAX_THREADS                10

/* Environment variable containing the audio output method */
#define AOUT_METHOD_VAR                 "vlc_aout"
#define AOUT_METHOD_DEFAULT             "dsp"

/* Environment variable used to store dsp device name, and default value */
#define AOUT_DSP_VAR                    "vlc_dsp"
#define AOUT_DSP_DEFAULT                "/dev/dsp"

/* Default audio output format (AOUT_FMT_S16_NE = Native Endianess) */
#define AOUT_FORMAT_DEFAULT             AOUT_FMT_S16_NE
/* #define AOUT_FORMAT_DEFAULT          AOUT_FMT_S8 */
/* #define AOUT_FORMAT_DEFAULT          AOUT_FMT_U8 */
/* #define AOUT_FORMAT_DEFAULT          AOUT_FMT_S16_BE */
/* #define AOUT_FORMAT_DEFAULT          AOUT_FMT_S16_LE */
/* #define AOUT_FORMAT_DEFAULT          AOUT_FMT_U16_BE */
/* #define AOUT_FORMAT_DEFAULT          AOUT_FMT_U16_LE */

/* Environment variable for stereo, and default value */
#define AOUT_STEREO_VAR                 "vlc_stereo"
#define AOUT_STEREO_DEFAULT             1

/* Environment variable for spdif mode */
#define AOUT_SPDIF_VAR                  "vlc_spdif"
#define AOUT_SPDIF_DEFAULT              0

/* Environment variable containing the AC3 downmix method */
#define DOWNMIX_METHOD_VAR              "vlc_downmix"

/* Environment variable containing the AC3 IMDCT method */
#define IMDCT_METHOD_VAR                "vlc_imdct"

/* Volume */
#define VOLUME_DEFAULT                  512
#define VOLUME_STEP                     128
#define VOLUME_MAX                      1024

/* Environment variable for volume */
#define AOUT_VOLUME_VAR                 "vlc_volume"

/* Environment variable for output rate, and default value */
#define AOUT_RATE_VAR                   "vlc_audio_rate"
#define AOUT_RATE_DEFAULT               44100

/* Number of audio output frames contained in an audio output fifo.
 * (AOUT_FIFO_SIZE + 1) must be a power of 2, in order to optimise the
 * %(AOUT_FIFO_SIZE + 1) operation with an &AOUT_FIFO_SIZE.
 * With 511 we have at least 511*384/2/48000=2 seconds of sound */
#define AOUT_FIFO_SIZE                  511

/* Maximum number of audio fifos. The value of AOUT_MAX_FIFOS should be a power
 * of two, in order to optimize the '/AOUT_MAX_FIFOS' and '*AOUT_MAX_FIFOS'
 * operations with '>>' and '<<' (gcc changes this at compilation-time) */
#define AOUT_MAX_FIFOS                  2

/* Duration (in microseconds) of an audio output buffer should be :
 * - short, in order to be able to play a new song very quickly (especially a
 *   song from the interface)
 * - long, in order to perform the buffer calculations as few as possible */
#define AOUT_BUFFER_DURATION            100000

/* Environment variable for MPEG audio decoder */
#define ADEC_MPEG_VAR                   "vlc_mpeg_adec"

/*****************************************************************************
 * Video configuration
 *****************************************************************************/

/* Maximum number of video output threads */
#define VOUT_MAX_THREADS                256

/*
 * Default settings for video output threads
 */

/* Environment variable containing the display method */
#define VOUT_METHOD_VAR                 "vlc_vout"
#define VOUT_METHOD_DEFAULT             "x11"

/* Environment variable containing the display method */
#define VOUT_FILTER_VAR                 "vlc_filter"
#define VOUT_FILTER_DEFAULT             "x11"

/* Environment variable containing the motion compensation method */
#define MOTION_METHOD_VAR               "vlc_motion"

/* Environment variable containing the IDCT method */
#define IDCT_METHOD_VAR                 "vlc_idct"

/* Environment variable containing the YUV method */
#define YUV_METHOD_VAR                  "vlc_yuv"

/* Environment variable used in place of DISPLAY if available */
#define VOUT_DISPLAY_VAR                "vlc_display"

/* Default dimensions for display window - these dimensions are enough for the
 * standard width and height broadcasted MPEG-2 streams or DVDs */
#define VOUT_WIDTH_VAR                  "vlc_width"
#define VOUT_WIDTH_DEFAULT              720
#define VOUT_HEIGHT_VAR                 "vlc_height"
#define VOUT_HEIGHT_DEFAULT             576
#define VOUT_DEPTH_VAR                  "vlc_depth"
#define VOUT_DEPTH_DEFAULT              15

/* Multiplier value for aspect ratio calculation (2^7 * 3^3 * 5^3) */
#define VOUT_ASPECT_FACTOR              432000

/* Maximum width of a scaled source picture - this should be relatively high,
 * since higher stream values will result in no display at all. */
#define VOUT_MAX_WIDTH                  4096

/* Number of planes in a picture */
#define VOUT_MAX_PLANES                 5

/* Video heap size - remember that a decompressed picture is big
 * (~1 Mbyte) before using huge values */
#define VOUT_MAX_PICTURES               8

/* Number of simultaneous subpictures */
#define VOUT_MAX_SUBPICTURES            8

/* Maximum number of active areas in a rendering buffer. Active areas are areas
 * of the picture which need to be cleared before re-using the buffer. If a
 * picture, including its many additions such as subtitles, additionnal user
 * informations and interface, has too many active areas, some of them are
 * joined. */
#define VOUT_MAX_AREAS                  5

/* Environment variable for grayscale output mode, and default value */
#define VOUT_GRAYSCALE_VAR              "vlc_grayscale"
#define VOUT_GRAYSCALE_DEFAULT          0

/* Environment variable for fullscreen mode, and default value */
#define VOUT_FULLSCREEN_VAR             "vlc_fullscreen"
#define VOUT_FULLSCREEN_DEFAULT         0

/* Environment variable for overlay mode, and default value */
#define VOUT_NOOVERLAY_VAR              "vlc_nooverlay"
#define VOUT_NOOVERLAY_DEFAULT          0

/* Default gamma */
#define VOUT_GAMMA_VAR                  "vlc_gamma"
#define VOUT_GAMMA_DEFAULT              0.

/* Default fonts */
#define VOUT_DEFAULT_FONT               "default8x9.psf"
#define VOUT_LARGE_FONT                 "default8x16.psf"

/* Statistics are displayed every n loops (=~ pictures) */
#define VOUT_STATS_NB_LOOPS             100

/*
 * Time settings
 */

/* Time during which the thread will sleep if it has nothing to
 * display (in micro-seconds) */
#define VOUT_IDLE_SLEEP                 ((int)(0.020*CLOCK_FREQ))

/* Maximum lap of time allowed between the beginning of rendering and
 * display. If, compared to the current date, the next image is too
 * late, the thread will perform an idle loop. This time should be
 * at least VOUT_IDLE_SLEEP plus the time required to render a few
 * images, to avoid trashing of decoded images */
#define VOUT_DISPLAY_DELAY              ((int)(0.500*CLOCK_FREQ))

/* Delay (in microseconds) before an idle screen is displayed */
#define VOUT_IDLE_DELAY                 (5*CLOCK_FREQ)

/* Number of pictures required to computes the FPS rate */
#define VOUT_FPS_SAMPLES                20

/* Better be in advance when awakening than late... */
#define VOUT_MWAIT_TOLERANCE            ((int)(0.020*CLOCK_FREQ))

/* Time to sleep when waiting for a buffer (from vout or the video fifo).
 * It should be approximately the time needed to perform a complete picture
 * loop. Since it only happens when the video heap is full, it does not need
 * to be too low, even if it blocks the decoder. */
#define VOUT_OUTMEM_SLEEP               ((int)(0.020*CLOCK_FREQ))

/* The default video output window title */
#define VOUT_TITLE                      "VideoLAN Client " VERSION

/* Environment variable for framebuffer device, and default value */
#define VOUT_FB_DEV_VAR                 "vlc_fb_dev"
#define VOUT_FB_DEV_DEFAULT             "/dev/fb0"

/* Environment variable for XVideo adaptor, and default value */
#define VOUT_XVADAPTOR_VAR              "vlc_xv_adaptor"

/*****************************************************************************
 * Video parser configuration
 *****************************************************************************/

#define VPAR_IDLE_SLEEP                 ((int)(0.010*CLOCK_FREQ))

/* Optimization level, from 0 to 2 - 1 is generally a good compromise. Remember
 * that raising this level dramatically lengthens the compilation time. */
#ifdef HAVE_RELEASE
#   define VPAR_OPTIM_LEVEL             2
#else
#   define VPAR_OPTIM_LEVEL             1
#endif

/* Maximum number of macroblocks in a picture. */
#define MAX_MB                          2048

/* The synchro variable name */
#define VPAR_SYNCHRO_VAR                "vlc_synchro"

/*****************************************************************************
 * Video decoder configuration
 *****************************************************************************/

#define VDEC_IDLE_SLEEP                 ((int)(0.100*CLOCK_FREQ))

/* Maximum range of values out of the IDCT + motion compensation. */
#define VDEC_CROPRANGE                  2048

/* Environment variable containing the SMP value. */
#define VDEC_SMP_VAR                   "vlc_smp"

/* No SMP by default, since it slows down things on non-smp machines. */
#define VDEC_SMP_DEFAULT                0

/* Nice increments for decoders -- necessary for x11 scheduling */
#define VDEC_NICE                       3

/*****************************************************************************
 * Messages and console interfaces configuration
 *****************************************************************************/

/* Maximal size of a message to be stored in the mesage queue,
 * it is needed when vasprintf is not avalaible */
#define INTF_MAX_MSG_SIZE              512

/* Maximal size of the message queue - in case of overflow, all messages in the
 * queue are printed by the calling thread */
#define INTF_MSG_QSIZE                  64

/* Interface warnig message level */
#define INTF_WARNING_VAR                "vlc_warning_level"
#define INTF_WARNING_DEFAULT            0

/* Define to enable messages queues - disabling messages queue can be useful
 * when debugging, since it allows messages which would not be printed
 * due to a crash to be printed anyway */
#ifndef DEBUG
#define INTF_MSG_QUEUE
#endif

/* Format of the header for debug messages. The arguments following this header
 * are the file (char *), the function (char *) and the line (int) in which the
 * message function was called */
#define INTF_MSG_DBG_FORMAT             "## %s:%s(),%i: "

/* Max number of arguments on a command line, including the function name */
#define INTF_MAX_ARGS                   20

/* Maximal size of a command line in a script */
#define INTF_MAX_CMD_SIZE               240

/* Number of memorized lines in console window text zone */
#define INTF_CONSOLE_MAX_TEXT           100

/* Maximal number of commands which can be saved in history list */
#define INTF_CONSOLE_MAX_HISTORY        20

/****************************************************************************
 * Playlist defaults
 ****************************************************************************/

/* Launch on start-up */
#define PLAYLIST_STARTUP_VAR            "vlc_playlist_on_start_up"
#define PLAYLIST_STARTUP_DEFAULT        0

/* Enqueue drag'n dropped item */
#define PLAYLIST_ENQUEUE_VAR            "vlc_playlist_enqueue"
#define PLAYLIST_ENQUEUE_DEFAULT        0

/* Loop on playlist end */
#define PLAYLIST_LOOP_VAR               "vlc_playlist_loop"
#define PLAYLIST_LOOP_DEFAULT           0

