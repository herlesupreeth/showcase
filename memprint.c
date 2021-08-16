#define MEM_BUFFER_ADDR  (0x7F800000)
#define MEM_LINE_SIZE    (0x80)
#define MEM_LINE_COUNT   (0x100)

static void   *_pMemBuffer = NULL;
static char   *_lineStr[MEM_LINE_COUNT];
static uint32  _lineIndex = 0;

void memprint(const char *fmt, ...);

void memprint_initBuffer(void)
{
    int i;

    _pMemBuffer = (void *)ioremap(MEM_BUFFER_ADDR, (MEM_LINE_SIZE * MEM_LINE_COUNT));
    if (_pMemBuffer > 0)
    {
        memset(_pMemBuffer, 0x00, (MEM_LINE_SIZE * MEM_LINE_COUNT));

        for (i = 0; i < MEM_LINE_COUNT; i++)
        {
            _lineStr[i] = (char *)(_pMemBuffer + (MEM_LINE_SIZE * i));
        }

        _lineIndex = 0;
    }
}

void memprint_uninitBuffer(void)
{
    iounmap( _pMemBuffer );
    _lineIndex = 0;
}

void memprint(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    vsnprintf(
        _lineStr[_lineIndex++],
        (MEM_LINE_SIZE - 1),
        fmt,
        args
    );

    _lineIndex &= (MEM_LINE_COUNT - 1);

    va_end(args);
}

