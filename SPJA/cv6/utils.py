import oauth2 as oauth

"""
TODO: paste tokens from e-mail here
"""
CONSUMER_KEY = "itUGozsTZKlbAuicGRD3GFWlt"
CONSUMER_SECRET = "Szl2WNSs9E5HyWdIy6xxNMPCwftKveccNhQFNc0Cnar99JT2J7"
ACCESS_KEY = "1055351409615519744-nOjW95Fav9aWn6zY86qkxcf2dJ86CA"
ACCESS_SECRET = "BPpnx8ufSLTxKuPT7uOpCP8T9nzwpxnbk83Qws4LIRSDx"


def create_client():
    consumer = oauth.Consumer(key=CONSUMER_KEY, secret=CONSUMER_SECRET)
    access_token = oauth.Token(key=ACCESS_KEY, secret=ACCESS_SECRET)
    client = oauth.Client(consumer, access_token)

    return client
