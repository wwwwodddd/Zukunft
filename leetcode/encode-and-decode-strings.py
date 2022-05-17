class Codec:
    def encode(self, a: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        return json.dumps(a)

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        return json.loads(s)


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))