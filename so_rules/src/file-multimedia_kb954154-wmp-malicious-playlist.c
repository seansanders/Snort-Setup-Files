/*
!!! XXX DOES NOT USE BUILT-IN DETECTION FUNCTIONS XXX !!!

Note there are three rules in here that all largely share the same structs -- references, most options, metadata, etc.  Also, there are three flowbits in addition to the download flowbit for keeping track of things.  The code has been written to reuse as many structures as possible and all three rules are evaluated using the same detection function that determines which content match succeeded and sets up the rest of the algorithm appropriately.

alert tcp $EXTERNAL_NET 554 -> $HOME_NET any (msg:"MULTIMEDIA Windows Media Player malicious playlist buffer overflow attempt"; flow:to_client,established; flowbits:isset,file.wmp_playlist; content:"kQfct7epzxGO5gDADCBT"; content:"QJ5p+E1bzxGo/QCAX1xE"; fast_pattern; distance:12; within:20; metadata:policy security-ips drop, policy balanced-ips drop; reference:cve,2008-2253; reference:url,technet.microsoft.com/en-us/security/bulletin/MS08-054; classtype:attempted-user; sid:14252; rev:1;)

alert tcp $EXTERNAL_NET 554 -> $HOME_NET any (msg:"MULTIMEDIA Windows Media Player malicious playlist buffer overflow attempt"; flow:to_client,established; flowbits:isset,file.wmp_playlist; content:"B9y3t6nPEY7mAMAMIFNl"; content:"nmn4TVvPEaj9AIBfXEQr"; fast_pattern; distance:12; within:20; metadata:policy security-ips drop, policy balanced-ips drop; reference:cve,2008-2253; reference:url,technet.microsoft.com/en-us/security/bulletin/MS08-054; classtype:attempted-user; sid:14253; rev:1;)

alert tcp $EXTERNAL_NET 554 -> $HOME_NET any (msg:"MULTIMEDIA Windows Media Player malicious playlist buffer overflow attempt"; flow:to_client,established; flowbits:isset,file.wmp_playlist; content:"3Le3qc8RjuYAwAwg"; content:"afhNW88RqP0AgF9c"; fast_pattern; distance:16; within:16; metadata:policy security-ips drop, policy balanced-ips drop; reference:cve,2008-2253; reference:url,technet.microsoft.com/en-us/security/bulletin/MS08-054; classtype:attempted-user; sid:14254; rev:1;)
*/
/*
 * Use at your own risk.
 *
 * Copyright (C) 2005-2008 Sourcefire, Inc.
 * 
 * This file is autogenerated via rules2c, by Brian Caswell <bmc@sourcefire.com>
 */

#include <string.h>

#include "sf_snort_plugin_api.h"
#include "sf_snort_packet.h"

#include "so-util.h"
#include "so-util_base64-decode.h"

//#define DEBUG
#ifdef DEBUG
#define DEBUG_SO(code) code
#else
#define DEBUG_SO(code)
#endif

typedef struct _SampleRate {
    uint32_t samplerate;
    uint16_t bitrate;
} SampleRate;

/* declare detection functions */
static int rule14252eval(void *);
static int rule14253eval(void *);
static int rule14254eval(void *);
static int checkPrereqs(void *);
static int ruleCVE_2008_2253Eval(void *, uint8_t);

/* declare rule data structures */
/* precompile the stuff that needs pre-compiled */
/* flow:established, to_client; */
static FlowFlags ruleCVE_2008_2253flow0 = 
{
    FLOW_ESTABLISHED|FLOW_TO_CLIENT
};

static RuleOption ruleCVE_2008_2253option0 =
{
    OPTION_TYPE_FLOWFLAGS,
    {
        &ruleCVE_2008_2253flow0
    }
};
/* flowbits:isset "file.wmp_playlist"; */
static FlowBitsInfo ruleCVE_2008_2253flowbits1 =
{
    "file.wmp_playlist",
    FLOWBIT_ISSET,
    0,
};

static RuleOption ruleCVE_2008_2253option1 =
{
    OPTION_TYPE_FLOWBIT,
    {
        &ruleCVE_2008_2253flowbits1
    }
};

// content:"kQfct7epzxGO5gDADCBT", depth 0; 
static ContentInfo rule14252content2 = 
{
    (uint8_t *) "kQfct7epzxGO5gDADCBT", /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_BUF_NORMALIZED, /* flags */
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule14252option2 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule14252content2
    }
};
// content:"QJ5p+E1bzxGo/QCAX1xE", offset 12, depth 20, relative, fast_pattern; 
static ContentInfo rule14252content3 = 
{
    (uint8_t *) "QJ5p+E1bzxGo/QCAX1xE", /* pattern (now in snort content format) */
    20, /* depth */
    12, /* offset */
    CONTENT_RELATIVE|CONTENT_FAST_PATTERN|CONTENT_BUF_NORMALIZED, /* flags */
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule14252option3 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule14252content3
    }
};

RuleOption *rule14252options[] =
{
    &ruleCVE_2008_2253option0,
    &ruleCVE_2008_2253option1,
    &rule14252option2,
    &rule14252option3,
    NULL
};

/* references for sid 14252 */
/* reference: cve "2008-2253"; */
static RuleReference ruleCVE_2008_2253ref1 = 
{
    "cve", /* type */
    "2008-2253" /* value */
};

/* reference: url "technet.microsoft.com/en-us/security/bulletin/MS08-054"; */
static RuleReference ruleCVE_2008_2253ref2 = 
{
    "url", /* type */
    "technet.microsoft.com/en-us/security/bulletin/MS08-054" /* value */
};

static RuleReference *ruleCVE_2008_2253refs[] =
{
    &ruleCVE_2008_2253ref1,
    &ruleCVE_2008_2253ref2,
    NULL
};

/* metadata for sid 14252 */
static RuleMetaData rule14252policy1 =
{
   "policy max-detect-ips drop"
};

static RuleMetaData *rule14252metadata[] =
{
   &rule14252policy1,
   NULL
};

/* metadata:policy balanced-ips drop, policy security-ips drop; */

//static RuleMetaData ruleCVE_2008_2253policy1 = 
//{
//    "policy balanced-ips drop"
//};
//
//static RuleMetaData ruleCVE_2008_2253policy2 = 
//{
//    "policy security-ips drop"
//};


static RuleMetaData *ruleCVE_2008_2253metadata[] =
{
//    &ruleCVE_2008_2253policy1,
//    &ruleCVE_2008_2253policy2,
    NULL
};

Rule rule14252 = {
   
   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_TCP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "554", /* SRCPORT   */
       0, /* DIRECTION */
       "$HOME_NET", /* DSTIP     */
       "any", /* DSTPORT   */
   },
   /* metadata */
   { 
       3,  /* genid (HARDCODED!!!) */
       14252, /* sigid */
       16, /* revision */
   
       "attempted-user", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "FILE-MULTIMEDIA Windows Media Player malicious playlist buffer overflow attempt",     /* message */
       ruleCVE_2008_2253refs /* ptr to references */
       ,rule14252metadata
   },
   rule14252options, /* ptr to rule options */
   rule14252eval, /* DO NOT use the built in detection function */
   0 /* am I initialized yet? */
};

// content:"B9y3t6nPEY7mAMAMIFNl", depth 0; 
static ContentInfo rule14253content2 = 
{
    (uint8_t *) "B9y3t6nPEY7mAMAMIFNl", /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_BUF_NORMALIZED, /* flags */
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule14253option2 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule14253content2
    }
};
// content:"nmn4TVvPEaj9AIBfXEQr", offset 12, depth 20, relative, fast_pattern; 
static ContentInfo rule14253content3 = 
{
    (uint8_t *) "nmn4TVvPEaj9AIBfXEQr", /* pattern (now in snort content format) */
    20, /* depth */
    12, /* offset */
    CONTENT_RELATIVE|CONTENT_FAST_PATTERN|CONTENT_BUF_NORMALIZED, /* flags */
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule14253option3 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule14253content3
    }
};

RuleOption *rule14253options[] =
{
    &ruleCVE_2008_2253option0,
    &ruleCVE_2008_2253option1,
    &rule14253option2,
    &rule14253option3,
    NULL
};

Rule rule14253 = {
   
   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_TCP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "554", /* SRCPORT   */
       0, /* DIRECTION */
       "$HOME_NET", /* DSTIP     */
       "any", /* DSTPORT   */
   },
   /* metadata */
   { 
       3,  /* genid (HARDCODED!!!) */
       14253, /* sigid */
       15, /* revision */
   
       "attempted-user", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "FILE-MULTIMEDIA Windows Media Player malicious playlist buffer overflow attempt",     /* message */
       ruleCVE_2008_2253refs /* ptr to references */
       ,ruleCVE_2008_2253metadata
   },
   rule14253options, /* ptr to rule options */
   rule14253eval, /* DO NOT use the built in detection function */
   0 /* am I initialized yet? */
};

// content:"3Le3qc8RjuYAwAwg", depth 0; 
static ContentInfo rule14254content2 = 
{
    (uint8_t *) "3Le3qc8RjuYAwAwg", /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_BUF_NORMALIZED, /* flags */
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule14254option2 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule14254content2
    }
};
// content:"afhNW88RqP0AgF9c", offset 16, depth 16, relative, fast_pattern; 
static ContentInfo rule14254content3 = 
{
    (uint8_t *) "afhNW88RqP0AgF9c", /* pattern (now in snort content format) */
    16, /* depth */
    16, /* offset */
    CONTENT_RELATIVE|CONTENT_FAST_PATTERN|CONTENT_BUF_NORMALIZED, /* flags */
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule14254option3 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule14254content3
    }
};

RuleOption *rule14254options[] =
{
    &ruleCVE_2008_2253option0,
    &ruleCVE_2008_2253option1,
    &rule14254option2,
    &rule14254option3,
    NULL
};

Rule rule14254 = {
   
   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_TCP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "554", /* SRCPORT   */
       0, /* DIRECTION */
       "$HOME_NET", /* DSTIP     */
       "any", /* DSTPORT   */
   },
   /* metadata */
   { 
       3,  /* genid (HARDCODED!!!) */
       14254, /* sigid */
       15, /* revision */
   
       "attempted-user", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "FILE-MULTIMEDIA Windows Media Player malicious playlist buffer overflow attempt",     /* message */
       ruleCVE_2008_2253refs /* ptr to references */
       ,ruleCVE_2008_2253metadata
   },
   rule14254options, /* ptr to rule options */
   rule14254eval, /* DO NOT use the built in detection function */
   0 /* am I initialized yet? */
};

/* detection functions */
static int rule14252eval(void *p)
{
    if (checkPrereqs(p) != 0)
        return RULE_NOMATCH;

    return ruleCVE_2008_2253Eval(p, 1);
}

static int rule14253eval(void *p)
{
    if (checkPrereqs(p) != 0)
        return RULE_NOMATCH;

    return ruleCVE_2008_2253Eval(p, 0);
}

static int rule14254eval(void *p)
{
    if (checkPrereqs(p) != 0)
        return RULE_NOMATCH;

    return ruleCVE_2008_2253Eval(p, 2);
}

static int checkPrereqs(void *p)
{
    SFSnortPacket *sp = (SFSnortPacket *)p;

    if ((sp == NULL) || (sp->payload == NULL) || (sp->stream_session_ptr == NULL))
        return -1;

    // flow:established, to_client;
    if(checkFlow(p, rule14252options[0]->option_u.flowFlags) <= 0 )
        return -1;

    // flowbits:isset "file.wmp_playlist";
    if(processFlowbits(p, rule14252options[1]->option_u.flowBit) <= 0)
        return -1;

    return 0;
}

static int ruleCVE_2008_2253Eval(void *p, uint8_t alignment)
{
   const uint8_t *cursor_normal=0, *end_of_payload;
   SFSnortPacket *sp = (SFSnortPacket *)p;

   // for base64 decoder
   uint8_t  outbuf[16], *p_outbuf;
   uint32_t bytes_written;
   int ret;

   // to store or retrieve sample per second value
   SampleRate      *samplerate2compare;
   RuleInformation *ruleinfo;
       
   // for extracting the sample per second   
   uint32_t samplerate;
   // for extracting the bits per sample   
   uint16_t bitrate;

   DEBUG_SO(printf("ruleCVE_2008_2253eval (malicious WMP playlist) enter\n"));

   if(getBuffer(sp, CONTENT_BUF_NORMALIZED, &cursor_normal, &end_of_payload) <= 0)
      return RULE_NOMATCH;

   switch (alignment)
   {
       case 0:
           if (contentMatch(p, rule14253options[2]->option_u.content, &cursor_normal) <= 0)
               return RULE_NOMATCH;
           if (contentMatch(p, rule14253options[3]->option_u.content, &cursor_normal) <= 0)
               return RULE_NOMATCH;
           ruleinfo = &(rule14253.info);
           break;
       case 1:
           if (contentMatch(p, rule14252options[2]->option_u.content, &cursor_normal) <= 0)
               return RULE_NOMATCH;
           if (contentMatch(p, rule14252options[3]->option_u.content, &cursor_normal) <= 0)
               return RULE_NOMATCH;
           ruleinfo = &(rule14252.info);
           break;
       case 2:
           if (contentMatch(p, rule14254options[2]->option_u.content, &cursor_normal) <= 0)
               return RULE_NOMATCH;
           if (contentMatch(p, rule14254options[3]->option_u.content, &cursor_normal) <= 0)
               return RULE_NOMATCH;
           ruleinfo = &(rule14254.info);
           break;
       default:
           return RULE_NOMATCH;
   }

   if(cursor_normal + 76 > end_of_payload)
      return RULE_NOMATCH;
     
   ret = base64decode(cursor_normal + 56, 20, outbuf, 16, &bytes_written);
   DEBUG_SO(printf("bytes_written = %d\n", bytes_written);)

   if(ret != 0 || bytes_written != 15)  // error
      return RULE_NOMATCH;
   
   p_outbuf = outbuf + alignment;
   samplerate = read_little_32(p_outbuf);
   p_outbuf += 10;
   bitrate    = read_little_16(p_outbuf); 
      
   DEBUG_SO(printf("decoded value: \n");)
   DEBUG_SO(printf("|%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x|", outbuf[0],  outbuf[1],  outbuf[2],  outbuf[3],  outbuf[4], outbuf[5],  outbuf[6],  outbuf[7],  outbuf[8],  outbuf[9], outbuf[10], outbuf[11], outbuf[12], outbuf[13], outbuf[14]);)
   DEBUG_SO(printf("samplerate=0x%08x    bitrate=0x%04x\n", samplerate, bitrate);)                  

   samplerate2compare = (SampleRate *)getRuleData(sp, (uint32_t)ruleinfo->sigID);

   if (samplerate2compare == NULL)
   {
       DEBUG_SO(printf("ruleCVE_2008_2253Eval is allocatin memory\n");)
       samplerate2compare = (SampleRate *)allocRuleData(sizeof(SampleRate));
       if (samplerate2compare == NULL)
           return RULE_NOMATCH;

       samplerate2compare->samplerate = samplerate;
       samplerate2compare->bitrate    = bitrate;           
       if (storeRuleData(sp, samplerate2compare, ruleinfo->sigID, &freeRuleData) < 0)
           freeRuleData(samplerate2compare);

       return RULE_NOMATCH;
   }       

   DEBUG_SO(printf("stored samplerate = 0x%08x\n", samplerate2compare->samplerate);)

   // malicious condition
   if ((samplerate2compare->samplerate < samplerate)  && (samplerate2compare->bitrate == bitrate))
       return RULE_MATCH;

   // in order to check next consecutive audio files
   samplerate2compare->samplerate = samplerate;
   samplerate2compare->bitrate    = bitrate;
   
   if (storeRuleData(sp, samplerate2compare, ruleinfo->sigID, &freeRuleData) < 0)
       freeRuleData(samplerate2compare);
       
   return RULE_NOMATCH;
}

/*
Rule *rules[] = {
    &rule14252,
    &rule14253,
    &rule14254,
    NULL
};
*/
