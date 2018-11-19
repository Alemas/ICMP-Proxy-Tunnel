#define ETH_LEN	1518
#define ETHER_TYPE	0x0800

struct eth_hdr {
	uint8_t dst_addr[6];
	uint8_t src_addr[6];
	uint16_t eth_type;
};

struct ip_hdr {
	uint8_t ver;			/* version, header length */
	uint8_t tos;			/* type of service */
	int16_t len;			/* total length */
	uint16_t id;			/* identification */
	int16_t off;			/* fragment offset field */
	uint8_t ttl;			/* time to live */
	uint8_t proto;			/* protocol */
	uint16_t sum;			/* checksum */
	uint8_t src[4];			/* source address */
	uint8_t dst[4];			/* destination address */
};

struct icmp_hdr {
	char ver;				/* Should receive 4 */
	char ihl;				/* Internet Header Length */
	uint8_t tos;			/* Type of Service */
	uint16_t totalLength;	/* Header + Data size in bytes */
	uint16_t id;			
	char flags;
	uint8_t offset;
	uint8_t ttl;			/* Time to live */
	uint8_t icmp_ver;		/* ICMP Protocol Version */
	uint16_t hdr_checksum;	/* Header Checksum */
	uint16_t src[4];		/* Source address */
	uint16_t dst[4];		/* Destionation address */
	uint8_t type;			/* Type */
	uint8_t code;			/* Code identifier */
	uint16_t checksum;		/* Checksum */
	char *payload;			/* Data Payload */
};

union packet_u {
	struct ip_hdr ip;
};

struct eth_frame_s {
	struct eth_hdr ethernet;
	union packet_u payload;
	struct icmp_hdr icmp;
};

union eth_buffer {
	struct eth_frame_s cooked_data;
	uint8_t raw_data[ETH_LEN];
};
