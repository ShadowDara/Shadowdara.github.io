import { BlogPosts } from 'app/components/posts'

export default function Page() {
  return (
    <section>
      <h1 className="mb-8 text-2xl font-semibold tracking-tighter">
        Develeper Blog
      </h1>
      <p className="mb-4">
        {
          `Hey,
          I am a develeper and here on my site i am posting some stuff about my recent projects :)`
        }
      </p>
      <div className="my-8">
        <BlogPosts />
      </div>
    </section>
  )
}
