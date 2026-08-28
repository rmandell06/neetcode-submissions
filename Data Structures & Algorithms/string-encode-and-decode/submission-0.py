class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded_str = ""
        for string in strs:
            encoded_str += (string +'/0')

        return encoded_str
    def decode(self, s: str) -> List[str]:
        return s.split('/0')[:-1]