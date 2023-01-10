class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        mail_box = set()
        for email in emails:
            local, domain = email.split('@')
            if('+' in local):
                local = local.split('+')[0]
            local = ''.join(local.split('.'))
            mail_box.add(local + '@' + domain)
        return len(mail_box)
        