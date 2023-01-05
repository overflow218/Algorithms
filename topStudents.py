class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        positive = {p: 3 for p in positive_feedback}
        negative = {n: -1 for n in negative_feedback}
        rank = []
        for repo, st_id in zip(report, student_id):
            score = 0
            parsed = repo.split(' ')
            for word in parsed:
                score += positive.get(word, 0)
                score += negative.get(word, 0)
            rank.append((score, st_id))
        rank.sort(key = lambda x: (-x[0], x[1]))
        ans = [rank[i][1] for i in range(k)]
        return ans